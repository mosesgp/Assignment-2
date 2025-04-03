
// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor to initialize the queue
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) {
            front = 0;  // First element being inserted
        }

        arr[++rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;  // Return -1 if the queue is empty
        }

        int dequeuedValue = arr[front++];
        if (front > rear) {
            front = rear = -1;  // Reset the queue if empty
        }
        return dequeuedValue;
    }

    // Peek the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Display the contents of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);  // Creating a queue of capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;

    q.display();

    q.enqueue(60);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
