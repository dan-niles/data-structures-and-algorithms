// A queue is a linear data structure that serves as a container of objects that are inserted
// and removed according to the FIFO (First–In, First–Out) principle.

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 1000 // Default size of queue

class Queue
{
    int *arr;     // Array to store queue elements
    int capacity; // Maximum capacity of the queue
    int front;    // First element in queue
    int rear;     // Last element in queue
    int count;    // No of items in the queue

public:
    Queue(int size = SIZE);

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize a queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Add an item to the queue
void Queue::enqueue(int item)
{
    // Check if queue is already full
    if (isFull())
        return;

    rear = (rear + 1) % capacity; // Set rear element pointer
    arr[rear] = item;
    count++;
}

// Dequeue the front element
int Queue::dequeue()
{
    // Check if queue is empty
    if (isEmpty())
        return -1;

    int x = arr[front];
    front = (front + 1) % capacity; // Shift front element pointer by 1
    count--;

    return x;
}

// Returns the first element of the queue
int Queue::peek()
{
    if (isEmpty())
        return -1;

    return arr[front];
}

// Returns the size of the queue
int Queue::size()
{
    return count;
}

// Check if the queue is empty or not
bool Queue::isEmpty()
{
    return (size() == 0);
}

// Check if the queue is full or not
bool Queue::isFull()
{
    return (size() == capacity);
}

int main()
{
    Queue q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "The queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "The front element is " << q.peek() << endl;

    if (q.isEmpty())
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";

    return 0;
}