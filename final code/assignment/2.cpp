#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;
    int n = str.length();
    
    // Push all characters onto the stack
    for(int i = 0; i < n; i++) {
        s.push(str[i]);
    }

    // Pop characters to form reversed string
    string rev = "";
    while(!s.empty()) {
        rev += s.top();
        s.pop();
    }

    // Compare original and reversed
    return str == rev;
}

int main() {
    int N;
    cout << "Enter number of test cases: ";
    cin >> N;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;

        if(isPalindrome(str)) {
            cout << str << " Yes" << endl;
        } else {
            cout << str << " No" << endl;
        }
    }

    return 0;
}
