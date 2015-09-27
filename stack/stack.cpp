#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;    
};

class Stack {
    public:
        Stack() : top(NULL), stack_size(0) {}
        void push(int k);
        void pop();
        
    private:
        Node* top;
        int stack_size;
        enum { full = 5};
};

void Stack::push(int k) {
    if (stack_size == full) {
        cout << "Stack is Full! " << endl;
    } else {
        if (top == NULL) {
            stack_size++;
            Node* temp = new Node();
            temp -> value = k;
            temp -> next = NULL;
            top = temp;
        
        } else {
            stack_size++;
            Node* temp = new Node();
            temp -> value = k;
            temp -> next = top;
            top = temp;   
        }         
    }    
}

void Stack::pop() {
    if (top == NULL) {
        cout << "Stack is Empty! " << endl;        
    } else {
        stack_size--;
        int value = top -> value;
        cout << value << " ";
        Node* temp = top;
        top = top -> next;    
        delete temp;    
    }
}


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Pop: ";
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
   
    

}
