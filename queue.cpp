#include<iostream>
using namespace std;

class queue {
private:
    int* arr;
    int capacity;
    int front;  // index of front element
    int rear;   // index of rear element
    int size;   // current number of elements in queue

public:
    queue(int size) {
        capacity = size;  // max size of queue
        arr = new int[capacity]; // array for queue
        front = -1;
        rear = -1;
        this->size = 0;
        cout << "Queue of size: " << capacity << " has been created" << endl;
    }

    void enqueue(int value) {
        // Check if queue is full
        if (size == capacity) {
            cout << "Queue overflow" << endl;
            return;
        }

        // If queue is initially empty
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        // Check if queue is empty
        if (size == 0) {
            cout << "Queue underflow" << endl;
            return;
        }

        // If last element is being removed
        if (size == 1) {
            front = -1;
            rear = -1;
        } else {
            // Move front to next element circularly
            front = (front + 1) % capacity;
        }
        size--;
    }

    int front_element() {
        // Check if queue is empty
        if (size == 0) {
            cout << "Queue underflow" << endl;
            return 0;
        }
        return arr[front];
    }

    bool is_empty() {
        return size == 0;
    }

    ~queue() {
        delete[] arr;
        cout << "Memory destroyed" << endl;
    }
};

int main() {
    queue q1(6);
    q1.dequeue();  
    q1.enqueue(4);
    q1.enqueue(14);
    q1.enqueue(45);
    q1.enqueue(35);
    q1.enqueue(454);
    q1.enqueue(100);  
    
    cout << "Front element: " << q1.front_element() << endl;
    
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();  
    
    return 0;
}