#include<iostream>
#include<stack>
#include<string>

using namespace std;

int ispalindrome(string str)
{
    int n=str.length();
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        s.push(str[i]);
    }

    string rev;

    while(!s.empty())
    {
        rev=rev+s.top();
        s.pop();
    }

    return str==rev;
}

int main()
{
    while(1)
    {
        cout<<"enter word:";
        string str;
        cin>>str;
        if(ispalindrome(str))
        {
            cout<<"valid"<<endl;
        }
        else
        {
            cout<<"not valid"<<endl;
        }
    }
}