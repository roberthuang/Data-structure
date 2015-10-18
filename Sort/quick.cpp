#include <iostream> 
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

using namespace std;

void quick_sort_v1(int* a, int left, int right);
void quick_sort_v2(int* a, int left, int right);

int main() {
    int a[5] = {5,4,3,2,1};
    
    cout << "Before Sorted: ";
    for (int i = 0;i < 5;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    /*
    quick_sort_v1(a, 0, 4);
    cout << "After Sorted_v1: ";
    for (int i = 0;i < 5;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << endl;*/
    quick_sort_v2(a, 0, 4);
    cout << "After Sorted_v2: ";
    for (int i = 0;i < 5;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
   
}

void quick_sort_v1(int* a, int left, int right) {

    if (left < right) {
        int pivot = a[left];
        int i = left;
        int j = right + 1;
        while(1) {
            while (i+1 <= right && a[++i] < pivot);
            while (j-1 >= left && a[--j] > pivot);
            if (i >= j) break;
            SWAP(a[i], a[j]);      
        }    
        a[left] = a[j];
        a[j] = pivot;
        quick_sort_v1(a, left, j-1);
        quick_sort_v1(a, j+1, right); 
    }
}

void quick_sort_v2(int* a, int left, int right) {
    if (left < right) {
        int pivot = a[(left+right)/2];
        int i = left - 1;
        int j = right + 1;
        while (1) {
            while (a[++i] < pivot);
            while (a[--j] > pivot);
            if (i >= j) break;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        quick_sort_v2(a, left, i-1);
        quick_sort_v2(a, j+1, right);   
    }
}
