#include <iostream>
#include <math.h>
using namespace std;

int getMid(int s, int e) {
    return (s+(e-s)/2);
}

void updateValueUtil(int* st, int ss, int se, int i, int diff, int si) {
    if (i < ss|| i > se) {
        return;
    }
    st[si] = st[si] + diff;
    if(ss != se) {
        int min = getMid(ss, se);
        updateValueUtil(st, ss, min, i, diff , 2*si+1);
        updateValueUtil(st, min+1, se, i, diff , 2*si+2);
    }
}

void updateValue(int arr[], int* st, int n, int i, int new_val) {
    if(i < 0 || i > n-1) {
        cout << "Invalid Input";
        return;
              
    }
    int diff = new_val - arr[i];
    //Update array's value
    arr[i] = new_val;
    
    updateValueUtil(st, 0, n-1, i, diff, 0);
    
    
}



// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss,int se,int* st,int si) {
    if(ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr,  mid+1, se, st, si*2+2);
    return st[si];
}

int* constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,x) - 1    ;
    int *st = new int[max_size];
    // Fill the allocated memory st
    constructSTUtil(arr,0,n-1,st,0);
    for (int i = 0; i < max_size;i++) {
        cout << st[i] << " ";
    }
    cout << endl;
    return st;
}

int main() {

    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int* st = constructST(arr, n);
    
}
