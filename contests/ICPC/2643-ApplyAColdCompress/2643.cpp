#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define HORIZONTAL_SPLIT 10
#define VERTICAL_SPLIT 1
#define BLACK_REGION 0
#define WHITE_REGION 11

typedef struct picture {
    int w;
    int h;
    int command_length;
    char *pixels;
} picture;

string command;

int gcd(int a, int b) {
    while (true) {
        if (a == 0) {
            return b;
        }
        b %= a;
        if (b == 0) {
            return a;
        }
        a %= b;
    }
}

int lcm(int a, int b) {
    int tmp = gcd(a, b);

    return tmp ? (a / tmp * b) : 0;
}

void print_picture(picture *a_picture) {
    // prints the picture
    int i, j;
    for (i = 0 ; i < a_picture->w + 2 ; i++) {
        cout << '-';
    }
    cout << '\n';
    for (j = 0 ; j < a_picture->h ; j++) {
        cout << '|';
        for (i = 0 ; i < a_picture->w ; i++) {
            cout << a_picture->pixels[j * a_picture->w + i];
        }
        cout << '|' << '\n';
    }

    for (i = 0 ; i < a_picture->w + 2 ; i++) {
        cout << '-';
    }
    
    cout << '\n';
}

void enlarge(picture *to_enlarge, int multiplier) {
    if (multiplier == 1) {
        return;
    }

    // used to enlarge a picture by multiplier times
    char *original = to_enlarge->pixels;
    int i,j;

    int new_w = multiplier * to_enlarge->w;
    int new_h = multiplier * to_enlarge->h;

    to_enlarge->w = new_w;
    to_enlarge->h = new_h;
    to_enlarge->pixels = (char *)(malloc(new_w * new_h));

    for (i = 0 ; i <  new_w ; i++) {
        for (j = 0 ; j < new_h ; j++) {
            to_enlarge->pixels[i + j * new_w] = original[i / multiplier + (j / multiplier) * new_w / multiplier];
        }
    }

    free(original);
}

void enlarge_w(picture *to_enlarge, int new_w) {
    enlarge(to_enlarge, new_w / to_enlarge->w);
}

void enlarge_h(picture *to_enlarge, int new_h) {
    enlarge(to_enlarge, new_h / to_enlarge->h);
}


picture *get_output(int index) {
    // returns the output if we treat the command starting at a certain index
    picture *ret_val = (picture *)malloc(sizeof(picture));
    picture *arg1;
    picture *arg2;
    int i, j;
    int new_val;
    char original;

    switch (atoi(command.substr(index, 2).c_str())) {
        case BLACK_REGION:
            ret_val->w = 1;
            ret_val->h = 1;
            ret_val->command_length = 2;
            ret_val->pixels = (char *)malloc(ret_val->w * ret_val->h);
            ret_val->pixels[0] = 'X';
            break;

        case WHITE_REGION:
            ret_val->w = 1;
            ret_val->h = 1;
            ret_val->command_length = 2;
            ret_val->pixels = (char *)malloc(ret_val->w * ret_val->h);
            ret_val->pixels[0] = ' ';
            break;

        case HORIZONTAL_SPLIT:
            arg1 = get_output(index + 2);
            arg2 = get_output(index + 2 + arg1->command_length);

            // if heights are not the same, make them the same, should be lcm of
            // heights
            new_val = lcm(arg1->h, arg2->h);
            enlarge_h(arg1, new_val);
            enlarge_h(arg2, new_val);

            // if heights are the same, just put together
            ret_val->w = arg1->w + arg2->w;
            ret_val->h = arg1->h;
            ret_val->pixels = (char *)malloc(ret_val->w * ret_val->h);
            for (i = 0 ; i < ret_val->h ; i++) {
                for (j = 0 ; j < arg1->w ; j++) {
                    ret_val->pixels[i * ret_val->w + j] = arg1->pixels[i * arg1->w + j];
                }
                for (j = 0 ; j < arg2->w ; j++) {
                    ret_val->pixels[i * ret_val->w + arg1->w + j] = arg2->pixels[i * arg2->w + j];
                }
            }
            ret_val->command_length = 2 + arg1->command_length + arg2->command_length;
            free(arg1);
            free(arg2);
            break;

        case VERTICAL_SPLIT:
            arg1 = get_output(index + 2);
            arg2 = get_output(index + 2 + arg1->command_length);

            // if heights are not the same, make them the same
            new_val = lcm(arg1->w, arg2->w);
            enlarge_w(arg1, new_val);
            enlarge_w(arg2, new_val);

            if (arg1->w < arg2->w) {
                enlarge(arg1, arg2->w / arg1->w);
            }
            else if (arg1->w > arg2->w) {
                enlarge(arg2, arg1->w / arg2->w);
            }

            // if heights are the same, just put together
            ret_val->w = arg1->w;
            ret_val->h = arg1->h + arg2->h;
            ret_val->pixels = (char *)malloc(ret_val->w * ret_val->h);
            for (j = 0 ; j < ret_val->w ; j++) {
                for (i = 0 ; i < arg1->h ; i++) {
                    ret_val->pixels[i * ret_val->w + j] = arg1->pixels[i * arg1->w + j];
                }
                for (i = 0 ; i < arg2->h ; i++) {
                    ret_val->pixels[(i + arg1->h) * ret_val->w + j] = arg2->pixels[i * arg2->w + j];
                }
            }
            ret_val->command_length = 2 + arg1->command_length + arg2->command_length;
            free(arg1);
            free(arg2);
            break;
    }
    
    //print_picture(ret_val);
    return ret_val;
}

int main(int argc, char *argv[]) {
    while (getline(cin, command)) {
        print_picture(get_output(0));
    }
    return 0;
}
