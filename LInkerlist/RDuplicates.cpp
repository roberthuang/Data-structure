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
void remove_duplicate_2(Node* &head) {
    Node* dummy = new Node();
    dummy -> next = head;
    Node* t = dummy;
    while (t -> next != NULL && t -> next -> next != NULL) {
         if (t -> next -> value == t ->next -> next -> value) {
             int delete_value = t -> next -> value;
             while (t -> next != NULL && delete_value == t-> next -> value) {
                 Node* node = t -> next;
                 t -> next = t -> next -> next;
                 delete node;
             }             
         } else {
             t = t -> next;        
         }
           
    }
    head = dummy -> next;
}


void remove_duplicate_1(Node* &head) {
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

void remove_duplicate_3(Node* &head) {
    Node* i = NULL;
    Node* j = NULL;
    for (i = head; i!= NULL; i = i -> next) {
        Node* p = i;
        Node* j = p -> next;
        while (p -> next != NULL) {
            if (j -> value != i -> value) {
                p = p-> next ;
                j = j -> next;
            } else {
                Node* t = j;
                p -> next = j -> next;
                delete t;
                j = p -> next;
            }
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
    insert_from_head(head ,21);
    insert_from_head(head ,43);
    insert_from_head(head ,41);
    insert_from_head(head ,21);
    insert_from_head(head ,12);
    insert_from_head(head ,11);
    insert_from_head(head ,12);
    
    print(head);
    cout << "After Remove Duplicates: ";
    
    /*remove_duplicate_1(head);
    print(head);*/
    remove_duplicate_3(head);
    print(head);
}
