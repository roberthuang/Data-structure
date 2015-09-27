#include <iostream>
using namespace std;
class Node {
    public:
        Node* next;
        int value;
    
        Node():next(NULL),value(0) {}
        Node(int theValue ,Node* theNext) : value(theValue) ,  next(theNext) { } 

};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList(); 
        void push_front(int value);
        void push_back(int value);
        void delete_front();    
        void show_element();
      
        void BubbleSort();
        void SelectSort();
        void InsertSort();
       

    private:
        Node* head;
        Node* swap( Node*, Node* );
};

LinkedList::LinkedList() : head(NULL) {}

LinkedList::~LinkedList() {
    if (head) {
        delete_front();   
    } 
}

void LinkedList::push_front(int value) {
    Node* newnode = new Node(value,head);
    head = newnode;              
}

void LinkedList::push_back(int value) {
    //null
    if (!head) {
        push_front(value);    
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current -> next;          
        }
        Node *newnode = new Node(value, NULL);
        current -> next = newnode;
    }
}

void LinkedList::delete_front() {
    if (!head) {
        return;
    } else {
        Node* temp = head;
        head = head -> next;
        delete temp;    
    }
}

void LinkedList::show_element() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> value << " ";
        temp = temp -> next;  
    }
    cout << endl;
}

void LinkedList::BubbleSort() {
    if (head == NULL) {
        return;
    } else {
        bool change = true;
        while (change == true) {
            change = false;
            Node* prev = NULL;
            Node* current = head;
            while (current -> next != NULL) {
                if (current -> value > current -> next -> value) {
                    change = true;
                    current = swap(current, current -> next);                   
                    if (prev != NULL) {
                    //not move head
                        prev -> next = current;                
                    } else {   
                    //move head                
                        head = current;
                    }
                }
                prev = current;
                current = current -> next;            
            }                
        }
        //show_element( );
    }
}

void LinkedList::SelectSort() {
    Node* i = head;
    Node* j = NULL;
    Node* min = NULL;
    for (i = head;i->next != NULL;i = i -> next) {
        min = i;
        for (j = i ->next; j != NULL;j=j->next) {
            if (min -> value > j -> value) {
                min =j;            
            }                       
        }
        if (min != i) {
            int temp;
            temp = min -> value;
            min -> value = j -> value; 
            j -> value = temp;
        }        
    }
}


void LinkedList::InsertSort() {
    Node* dummy = new Node();
    Node* cur = head;
    while(cur != NULL) {
        Node* pre = dummy;
        while(pre -> next != NULL && pre -> next -> value < cur -> value) {
            pre = pre -> next;
        }
        Node* n = cur -> next;
        Node* t = pre -> next;
        pre -> next = cur;
        cur -> next = t;
        cur = n;   
   }
   head = dummy -> next;
}


Node* LinkedList::swap( Node* p, Node* q) {
    Node* temp = q -> next;
    q -> next = p;
    p -> next = temp;
    return q;
}

int main() {
    LinkedList list;
    list.push_back( 4 );
    list.push_back( 7 );
    list.push_back( 5 );
    list.push_back( 1 );
    list.push_back( 3 );
    list.push_back( 2 );
    list.push_front( 6 );
    list.push_front( 0 );
    list.show_element( );

    list.delete_front( );
    list.show_element( );
    
    
    cout << "After Bubblesort: ";
    list.BubbleSort();
    list.show_element( );
    
    cout << "After Selectsort: ";
    list.SelectSort();
    list.show_element( );
    
    cout << "After Insertsort: ";
    list.InsertSort();
    list.show_element( );

}
