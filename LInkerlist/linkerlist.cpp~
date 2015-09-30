#include <iostream>
using namespace std;

struct Node {
    int number;
    Node* next;
};


void add_to_the_end(Node* &head ,Node* &last ,int number);
void remove_from_head(Node* &head ,Node* &last);
void show(Node* List_for_head);
void add_to_after(Node* &position);
Node* reverse(Node* & head);
Node* find_position(Node* head,int number1);

char menu();


int main() {
    Node* head = NULL;
    Node* last = NULL;
    Node* temp2 = new Node;
    Node* reverse2 =new Node;
    char choice;
    int number;
    do {
        
        choice = menu();
        switch (choice) {
            case '1': cout << "Please enter a number: ";
                      cin >> number;
                      add_to_the_end(head, last, number);
        	      break;    
            case '2': remove_from_head(head, last);                    
        	      break; 	
        	      
            case '3': show(head);           
        	      break;
            case '4': cout << "Please enter a number: ";
                      cin >> number;
                      //Node* temp2 = new Node;
                      temp2 = find_position(head,number); 
                      add_to_after(temp2);          
        	      break;
            case '5': ;
                      reverse2 = reverse(head);
                      cout << "Reverse: ";
                      show(reverse2);       
        	      break;       	       	 
            default: cout << "System exit\n";     	            
        }
    
    
    }while (choice != '6');
    return 0;
}


void add_to_the_end(Node* &head ,Node* &last ,int number) {
    if (head == NULL) {
         Node* temp = new Node;
         temp -> number = number;
         temp -> next = NULL;
         head = temp;
         last = temp;
    } else {
         Node* temp = new Node;
         temp -> number = number;
         temp -> next = NULL;
         last -> next = temp;
         last = temp;
    }
}

void remove_from_head(Node* &head ,Node* &last) {
     if (head == NULL) {
         cout <<  "The LinkeList is Empty!.\n";  
     } else if (head == last) {
         delete head;
         head == NULL;
         last == NULL;
     } else {
         Node* temp = head;
         head = head -> next;
         delete temp;
     }
}

void show(Node* List_for_head) {
    if (List_for_head == NULL) {
         cout << "Empty Linker List!.\n";
    } else {

	    while (List_for_head != NULL) {
		cout << List_for_head -> number;    
		List_for_head = List_for_head -> next;
		if (List_for_head != NULL) {
		    cout << "---->";
		}else {
		    cout << "---->NULL";
		}
		
	    }
    }
    cout << endl;
    
}

char menu() {
    char choice;
    
    cout << "Menu" << endl;
    cout << "1. Add an item" << endl;
    cout << "2. Remove from head" << endl;
    cout << "3. Show Linker List" << endl;
    cout << "4. Add an item after" << endl;
    cout << "5. Reverse Linker List" << endl;
    cout << "6. Exit" << endl;
    
    cin >> choice;
    return choice;
}

Node* find_position(Node* head,int number1) {
    Node* temp =  new Node;
    while (head != NULL) {
       if ((head -> number) == number1) {
           temp = head;
           break;
       }
       head = head -> next;
    }
    return temp;
}

void add_to_after(Node* &position) {
     int number;
     cout  << "Enter a number you want to inset after:";
     cin >> number;
     Node* temp = new Node;
     temp -> number = number;
     temp -> next = position -> next;
     position -> next = temp;
}

Node* reverse(Node* & head) {
     Node* new_head = NULL;
     Node* next;
     while (head != NULL) {
         next = head -> next;
         head -> next = new_head;
         new_head = head;
         head = next;
     }
     return new_head;
}
