#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> s1, s2;  // two stacks

public:
    // Enqueue: add element to the queue
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue: remove element from front of the queue
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Top of s2 is the front of the queue
        int front = s2.top();
        s2.pop();
        return front;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (s1.empty() && s2.empty());
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 20

    q.enqueue(40);
    cout << "Dequeue: " << q.dequeue() << endl; // 30
    cout << "Dequeue: " << q.dequeue() << endl; // 40

    // Try to dequeue from empty queue
    q.dequeue(); // prints "Queue is empty!"
    return 0;
}
