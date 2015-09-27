#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};

class Queue {
    public:
	Queue() : front(NULL),rear(NULL) {}
	void enqueue(int k);
	void dequeue();      
    private:
        Node* front;
        Node* rear;
};

void Queue::enqueue(int k) {
    if (rear == NULL) {
        Node* temp = new Node();
        temp -> value = k;
        front = rear = temp;
        temp -> next = NULL;
    } else {
        Node* temp = new Node();
        temp -> value = k;
        Node* t = rear -> next;
        rear -> next = temp;
        temp -> next = t;
        rear = temp;
    }
}

void Queue::dequeue() {
    if (front == NULL) {
        cout << "Queue is Empty! " << endl;  
    } else {
        Node* temp =  front;
        cout << "delete: " << front -> value << endl;
        front = front -> next;            
        delete temp;
    }
}

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();


}
