#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>



using namespace std;

bool vowel(string c)
{
    if (c == "a" or c == "e" or c=="i" or c == "o" or c == "u" or c == "y")
    {
        return true;
    }
    else
    {
    
        return false;
    }
}

bool breakuprule(string str)
{
    vector <string> checklist = {"qu", "tr", "br", "st", "sl", "bl", "cr", "ph", "ch"};
    
    if (count(checklist.begin(), checklist.end(), str) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
        
string modify(string str)
{
    string sol = "";
    
    vector <bool> cases; //true is upper
    
    string temp = "";
    
    for (char c: str)
    {
        if (isupper(c))
        {
            cases.push_back(true);
        }
        else
        {
            cases.push_back(false);
        }
        temp += tolower(c);

    }
    
    str = temp;
    
    
    
    
    vector <string> breakup; //removed "str" from breakuplist
    string prev = "";
    int slen = str.length();
    for (int i =0; i < slen; i++)
    {
        string threeNext = "";
        string twoNext = "";
        if (i < slen - 2)
            threeNext = string(1, str[i]) + string(1, str[i+1]) + string(1,str[i+2]);
        if (i < slen - 1)
            twoNext = string(1, str[i]) + string(1, str[i+1]);
        if (threeNext == "str")
        {
            breakup.push_back(threeNext);
            i += 2;
        }
        else if(breakuprule(twoNext))
        {
            breakup.push_back(twoNext);
            i++;
        }
        else
        {
            breakup.push_back(string(1, str[i]));
        }
    }    
    
    
    
    int bsize = breakup.size();
    for (int i = 0; i < bsize; i++)
    {
        if (i  < bsize - 3)
        {
        
            if(vowel(breakup[i]) and !vowel(breakup[i+1]) and !vowel(breakup[i+2]) and vowel(breakup[i+3]))
            {
                sol += breakup[i] + breakup[i+1] + "-";
                i ++;
            }
            else if(vowel(breakup[i]) and !vowel(breakup[i+1]) and vowel(breakup[i+2]) and !(breakup[i+2] == "e" and i + 2 == bsize - 1))
            {
                sol += breakup[i] + "-";
                
            }
            else
            {
                sol += breakup[i];
            }
        }
        else if(i < bsize - 2)
        {
            if(vowel(breakup[i]) and !vowel(breakup[i+1]) and vowel(breakup[i+2]) and !(breakup[i+2] == "e" and i + 2 == bsize - 1))
            {
                sol += breakup[i] + "-";
                
                
            }
            else
            {
                sol += breakup[i];
            }
        }
        else
        {
            sol += breakup[i];
        }
        
        //cerr<<"Iteration: "<<sol<<endl;
    }
    
    int counter = 0;
    temp = "";
    
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[i] == '-')
        {
            temp += "-";
            continue;
        }
        
        if (cases[counter])
        {
            temp.push_back(toupper(sol[i]));
        }
        else
        {
            temp.push_back(sol[i]);
        }
        counter++;

    }
    
    return temp;
   
}

int main()
{    
    
    string s;
    vector <string> list;
    while(cin>>s and s!="===")
    {           
        list.push_back(s);        	
    }
    for(string word: list)
    {
        cout<<modify(word)<<'\n';
    }
    cout<<'\n';
    
    

}
