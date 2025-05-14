#include<iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    Stack(int size) {
        capacity = size;  // Size of stack
        arr = new int[capacity]; // Array for stack
        front = -1;
        rear = -1;
        cout << "Stack of size: " << capacity << " has been created." << endl;
    }

    void push(int value) {
        if (rear == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }

    void pop() {
        if (front == -1 || front > rear) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Popped element: " << arr[front] << endl;
        
        // Shift elements forward
        for (int i = front; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;
        
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    int top_element() {
        if (front == -1 || front > rear) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return arr[front];
    }

    void print_stack() {
        if (front == -1 || front > rear) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
        cout << "Memory destroyed" << endl;
    }
};

int main() {
    Stack s1(6);
    s1.pop();
    s1.push(4);
    s1.push(14);
    s1.push(45);
    s1.push(35);
    s1.push(454);
    s1.print_stack();
    cout << "Top element: " << s1.top_element() << endl;
    s1.pop();
    s1.print_stack();
    s1.pop();
    s1.print_stack();
    s1.pop();
    s1.print_stack();
    s1.pop();
    s1.print_stack();
    s1.pop();
    s1.print_stack();
    return 0;
}