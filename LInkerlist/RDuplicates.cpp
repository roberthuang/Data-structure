#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void insert_from_head(Node* &head, int k) {
    if (head == NULL) {
        Node* temp =  new Node();
        temp -> value = k;
        temp -> next = NULL;
        head  = temp;
    } else {
        Node* temp = new Node();
        temp -> value = k;
        temp -> next = head;
        head = temp;
    }
}

void remove_duplicate(Node* &head) {
    Node* temp = head;
    while (temp -> next != NULL) {
        if  (temp -> value == temp -> next -> value) {
            Node* next_1 = temp -> next;
            temp -> next = temp -> next -> next;
            delete next_1;
        } else {       
            temp = temp -> next;  
        }  
    }    
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {     
        cout << temp -> value  ;
        if (temp -> next != NULL) cout << "->";
        temp = temp -> next; 
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    insert_from_head(head ,3);
    insert_from_head(head ,3);
    insert_from_head(head ,2);
    insert_from_head(head ,1);
    insert_from_head(head ,1);
    
    print(head);
    cout << "After Remove Duplicates: " << endl;
    remove_duplicate(head);
    print(head);
    
    
    
}
