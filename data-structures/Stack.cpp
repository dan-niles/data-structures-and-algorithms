// Stack is a linear data structure that follows a particular order in which the operations are performed.
// The order may be LIFO(Last In First Out) or FILO(First In Last Out).

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Push item into stack
bool Stack::push(int x)
{
    // Check if stack is full
    if (top >= (MAX - 1))
        return false;
    else
    {
        top++;
        a[top] = x;
        return true;
    }
}

// Pop and return top item in stack
int Stack::pop()
{
    // Check if stack is empty
    if (top < 0)
        return 0;
    else
    {
        top--;
        int x = a[top];
        return x;
    }
}

// Returns topmost element in stack without removing it
int Stack::peek()
{
    // Check if stack is empty
    if (top < 0)
        return 0;
    else
        return a[top];
}

// Checks if stack is empty
bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    // print top element of stack after poping
    cout << "Top element is : " << s.peek() << endl;

    // print all elements in stack :
    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() << " ";
        // remove top element in stack
        s.pop();
    }

    return 0;
}
