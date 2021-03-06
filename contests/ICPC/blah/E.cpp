#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string nextstr(string temp, int pos)
{
    string res = "";
    int tempSz = temp.length();
    for (int i = pos; i < tempSz; i++)
    {
        if (temp[i] < 'Z')
        {
            res += char(temp[i] + 1);
            return res;
        }
        else
        {
            res += 'Z';
        }
    } 
    res += 'A';
    return res;
}

string middle(string left, string right)
{
    string sol = "";
    int lsz = left.length();
    int rsz = right.length();
    for (int i = 0; i < lsz; i++)
    {
        int dist = int(right[i] - left[i]);
        if (dist > 1)
        {
            sol += char(left[i] + 1);
            break;
        }
        else if(dist == 0)
        {
            sol += right[i];
            
        }
        else if (dist == 1)
        {
               if (i+1 == rsz)
               {
                    sol +=left[i];
                    
                    if (i + 1 == lsz)
                    {
                        sol += 'A';
                        break;
                    }
                    else
                    {
                        sol += nextstr(left, i + 1);
                        break;
                    }
               }
               else
               {
                    sol += right[i];
                    break;
               }      
        }
     
        
        
        else
        {
            cout<<"You fucked up"<<endl;
        }
    }
    
    return sol;

}

int main()
{
   int n;
   
   while (cin >> n)
   {
        if (n == 0){
            break;
        }
        vector <string> names(n);
        for (int i =0; i < n; i++)
        {
            cin>>names[i];   
        }
        sort(names.begin(), names.end());
        
        string left = names[(n-1)/2];
        string right = names[(n-1)/2 + 1];
        
        //cout<<left<<" "<<right<<endl;
        
        cout<<middle(left, right)<<endl;
        
   }
   
   return 0;
}

