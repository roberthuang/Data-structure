/*Given an array and a value, remove all occurrences of that value in place and return the new length.

The order of elements can be changed, and the elements after the new length don't matter.

Example

Given an array [0,4,4,0,0,2,4,4], value=4

return 4 and front four elements of the array is [0,0,0,2]*/
#include <iostream>
using namespace std;
int remove_element(int a[], int n, int element);

int main() {
    
    int a[8] = {0,4,4,0,0,2,4,4};
    
    cout << remove_element(a, 8, 4) << endl;  
}

int remove_element(int a[], int n, int element) {
    for (int i = 0; i < n;i++) {
        if(a[i] == element) {
            a[i] = a[n-1];
            i--;
            n--;        
        }    
    }
    return n;
}


