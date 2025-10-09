#include <iostream>
#include <queue>
#include <string>
using namespace std;

void reverseString(string str) {
    queue<char> q1, q2;

    // Step 1: Push all characters to q1
    for (int i = 0; i < str.length(); i++) {
        q1.push(str[i]);
    }

    // Step 2: Reverse using q2
    while (!q1.empty()) {
        char ch = q1.front();
        q1.pop();
        

        queue<char> temp;
        temp.push(ch);

        while (!q2.empty()) {
            temp.push(q2.front());
            q2.pop();
        }

        q2 = temp;
    }

    // Step 3: Build reversed string
    string rev = "";
    while (!q2.empty()) {
        rev += q2.front();
        q2.pop();
    }

    cout << "Reversed string: " << rev << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverseString(str);
    return 0;
}
