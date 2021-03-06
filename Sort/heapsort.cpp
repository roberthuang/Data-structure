#include <iostream>
using namespace std;

void build_max_heap(int* a ,int n);
void max_heapify(int* a ,int n ,int index_now);

int main() {
    int n;
    int a[15];
    cout << "Enter the number you want to put in: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Put in:";
        cin >> a[i];
    }
    build_max_heap(a,n);
    cout << "The Max_heap: ";
    for (int i = 1 ; i <= n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;   


}

void build_max_heap(int*a ,int n) {
    for (int i = n/2; i >= 1;i--) {
        max_heapify(a , n , i);
    }
}

void max_heapify(int* a ,int n ,int index_now) {

    int temp = a[index_now];
    int j = 2*index_now;
    while(j <= n) {
        if (j+1 <= n && a[j+1] > a[j] ) {
            j = j+1;   
        }
        if (a[j] > temp) {
            a[index_now] = a[j];
            index_now = j;
        }
        j = j*2;
    }
    a[index_now] = temp; 
}

