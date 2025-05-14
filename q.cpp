#include<iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        cout << "Queue of size: " << capacity << " has been created." << endl;
    }

    void enqueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        
        if (front == -1) {
            front = 0;
        }
        
        rear++;
        arr[rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return;
        }
        
        // Shift all elements to the left
        for (int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        
        rear--;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int front_element() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return arr[front];
    }

    bool is_empty() {
        return (front == -1 || front > rear);
    }

    ~Queue() {
        delete[] arr;
        cout << "Memory destroyed" << endl;
    }
};

int main() {
    Queue q(6);
    
    q.dequeue(); // Queue underflow
    
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(45);
    q.enqueue(35);
    q.enqueue(454);
    
    q.display();
    
    cout << "Front element: " << q.front_element() << endl;
    
    q.dequeue();
    q.display();
    
    q.dequeue();
    q.display();
    
    q.dequeue();
    q.display();
    
    q.dequeue();
    q.display();
    
    q.dequeue();
    q.display();
    
    q.dequeue(); 
    
    return 0;
}