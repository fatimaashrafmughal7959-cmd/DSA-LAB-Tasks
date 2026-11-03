#include <iostream>
using namespace std;
#define MAX 5
int top = -1;
int stackArr[MAX];

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack overflow!" << endl;
    }
    else {
        top++;
        stackArr[top] = value;
        cout << value << " pushed" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
    }
    else {
        cout << "Popped: " << stackArr[top] << endl;
        top--;
    }
}

int search(int x) {
    int steps = 1;
    for (int i = top; i >= 0; i--) {
        if (stackArr[i] == x) {
            return steps;
        }
        steps++;
    }
    return -1;
}

int main() {
    int value;
    cout << "Enter five integers:" << endl;
    for (int i = 0; i < MAX; i++) {
        cin >> value;
        push(value);
    }

    cout << "Trying sixth push:" << endl;
    push(90);

    cout << "Searching 30:" << endl;
    cout << "Position from top: " << search(30) << endl;

    cout << "Searching 100:" << endl;
    cout << "Position from top: " << search(100) << endl;

    cout << "Popping all items:" << endl;
    while (top != -1) {
        pop();
    }

    cout << "Trying extra pop:" << endl;
    pop();

    return 0;
}