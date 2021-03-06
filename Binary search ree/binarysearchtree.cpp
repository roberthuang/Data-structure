#include <iostream>
using namespace std;
struct Node {
    int key_value;
    Node* left;
    Node* right;
};

class Btree {
    public:
        Btree() {
            root = NULL;           
        }
        void insert(int k);
        void print_inorder(Node* root); 
        Node* get_root() { return root; }
    private:
        Node* root;
        void insert(Node* root, int k);   
         
};

void Btree::insert(int k) {
    if (root == NULL) {
        root = new Node();
        root -> key_value = k;
        root -> left = NULL;        
        root -> right = NULL;
    } else {
        insert(root, k);
    
    }
}

void Btree::insert(Node* root, int k) {
          
    
    if (root -> key_value > k) {
        if (root -> left != NULL) {
            insert(root -> left, k); 
        } else {  
            root -> left = new Node();
            root -> left -> key_value = k;
            root -> left -> left = NULL;        
            root -> left -> right = NULL;
        }
    } else {
        if (root -> right != NULL) {
            insert(root -> right, k);   
        } else {
            root -> right = new Node();
            root -> right -> key_value = k;
            root -> right -> left = NULL;        
            root -> right -> right = NULL;
        }
    } 
     
} 

void Btree::print_inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root -> left);
    cout << root -> key_value << " ";
    print_inorder(root -> right);
}


int main() {
    Btree t;
    t.insert(20);
    t.insert(9);
    t.insert(18);
    t.insert(17);
    t.insert(15);

    cout << "After Inorder: ";
    t.print_inorder(t.get_root());
    cout << endl;
}
