#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Function to reverse a string using two queues
string reverseStringUsingQueue(string s) {
    queue<char> q1, q2;

    // Push all characters into the first queue
    for (char c : s) {
        q1.push(c);
    }

    // Reverse the string using the second queue
    while (!q1.empty()) {
        char front = q1.front();
        q1.pop();

        // Push this character into q2
        q2.push(front);

        // Rotate q2 so that the newly added element moves to the front
        int size = q2.size();
        for (int i = 0; i < size - 1; ++i) {
            q2.push(q2.front());
            q2.pop();
        }
    }

    // Build the reversed string from q2
    string reversed = "";
    while (!q2.empty()) {
        reversed += q2.front();
        q2.pop();
    }

    return reversed;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        // Call the function and print result
        cout << reverseStringUsingQueue(s) << endl;
    }

    return 0;
}