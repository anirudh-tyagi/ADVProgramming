#include<iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        count = 0;
        cout << "Circular Queue of size: " << capacity << " has been created." << endl;
    }

    void enqueue(int value) {
        if (count == capacity) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Dequeued element: " << arr[front] << endl;
        front = (front + 1) % capacity;
        count--;
        if (count == 0) {
            front = -1;
            rear = -1;
        }
    }

    int front_element() {
        if (count == 0) {
            cout << "Queue underflow" << endl;
            return 0;
        }
        return arr[front];
    }

    void print_queue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
        cout << "Memory destroyed" << endl;
    }
};

int main() {
    CircularQueue q1(6);
    q1.dequeue();
    q1.enqueue(4);
    q1.enqueue(14);
    q1.enqueue(45);
    q1.enqueue(35);
    q1.enqueue(454);
    q1.print_queue();
    cout << "Front element: " << q1.front_element() << endl;
    q1.dequeue();
    q1.print_queue();
    q1.dequeue();
    q1.print_queue();
    q1.dequeue();
    q1.print_queue();
    q1.dequeue();
    q1.print_queue();
    q1.dequeue();
    q1.print_queue();
    return 0;
}