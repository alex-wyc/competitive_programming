#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int overlap(string s1, string s2)
{
    int s1l = s1.length();
    int s2l = s2.length();
    int count = 0;
    for (int i = 0; i < s1l; i++)
    {
        for (int j = 0; j < s2l; j++)
        {
            if(s1[i] == s2[j])
            {
                count++;
            }
        }
    }
    return count;
}

int calc(vector <string> &rec)
{
    int acc = 0;
    for (int i =0; i < rec.size() - 1; i++)
    {
        acc += overlap(rec[i], rec[i+1]);
    }
    return acc;
}



int main()
{
    
    int N;
    int minSol = 10010010;
    cin>>N;
    vector <string> recitals(N);
    for(int i = 0; i < N; i++)
    {
        cin>>recitals[i];
    }
    sort(recitals.begin(), recitals.end());
    
    while(next_permutation(recitals.begin(), recitals.end())
    {
        minSol = min(minSol, calc(recitals));   
    }
    cout<<minSol<<'\n';

}
