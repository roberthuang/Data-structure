#include <iostream>
using namespace std;
class Linker {
    private:
        struct Node {
            int value;
            Node* next;
        };
        Node* head ;
    public:
        Linker() { head = NULL;}
        void add_front(int value) {  
            if (head == NULL) {
                Node* temp = new Node();
                temp -> next = NULL;
                temp -> value = value;
                head = temp;
            
            } else {
                Node* temp = new Node();                             
                temp -> value = value;    
                temp -> next = head;
                head = temp;        
            }
               
        } 
        
        void show() {
             Node* temp = head;
             while(temp != NULL) {
                 cout << temp ->value <<endl;
                 temp = temp -> next;
             
             }
        
        
        }
};

int main() {
    Linker l;
    l.add_front(7);
    l.add_front(8);
    l.add_front(9);
    l.add_front(10);
    l.show();   
}
