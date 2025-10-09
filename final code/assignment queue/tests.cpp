#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    queue<char> q;
    stack<char> s;

    // Step 1: Push characters into queue and stack
    for (char ch : str) {
        q.push(ch);
        s.push(ch);
    }

    // Step 2: Compare front of queue and top of stack
    while (!q.empty()) {
        if (q.front() != s.top())
            return false;  // Mismatch found
        q.pop();
        s.pop();
    }

    return true; // All matched
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "✅ It is a palindrome!" << endl;
    else
        cout << "❌ Not a palindrome." << endl;

    return 0;
}
