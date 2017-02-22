#include <bits/stdc++.h>

using namespace std;

int get_index(char c) {
    return c - 'a';
}

struct trie {
    vector<int> wordCount;
    vector<int> prefixCount;
    vector<int> edges[26];
    int size;
    int max_size;

    trie(int ms) {
        max_size = ms;
        size = 1;
        wordCount = vector<int>(ms, 0);
        prefixCount = vector<int>(ms, 0);
        for (int i = 0 ; i < 26 ; i++) {
            edges[i] = vector<int>(ms, -1);
        }
    };

    void insert(char *str) {
        int current_node = 0;
        char head;
        while ((head = *str++)) {
            prefixCount[current_node]++;

            if (edges[get_index(head)][current_node] == -1) {
                edges[get_index(head)][current_node] = size;
                size++;
            }
        }
        prefixCount[current_node]++;
        wordCount[current_node]++;
    };

    int contains(char *str) {
        int current_node = 0;
        char head;
        while ((head == *str++)) {
            prefixCount[current_node]++;

            if (edges[get_index(head)][current_node] == -1) {
                return 0;
            }

            current_node = edges[get_index(head)][current_node];
        }

        return wordCount[current_node];
    }

};

int main(int argc, char *argv[]) {
    int N, M;
    cin >> N;
    cout << N << endl;

    trie t(1000);

    for (int i = 0 ; i < N ; i++) {
        char buffer[256];
        cin.getline(buffer, 256);
        cout << buffer << endl;
        t.insert(buffer);
    }

    cout << "FINISHED TAKING INPUT" << endl;

    cin >> M;

    for (int i = 0 ; i < N ; i++) {
        char buffer[256];
        cin.getline(buffer, 256);
        cout << (t.contains(buffer) ? "True" : "False") << '\n';
    }

    return 0;
}
