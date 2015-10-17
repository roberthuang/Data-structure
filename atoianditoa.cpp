#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool isNumeric(char x) {
    return (x>= '0' && x <= '9') ? true : false;
}

int Myatoi(const char* str) {
    /*
    if (*str == NULL) {
        return 0;
    }*/
    
    int result = 0;
    int sign = 1;
    int i = 0;
    
    if (str[0] == '-') {
       sign = -1;
       i++;   
    }
    
    for (; str[i] != '\0'; i++) {
        if(!isNumeric(str[i])) {
            printf("Not the integer!\n");
            return 0;
        }
        result = result*10 + str[i] - '0';
    }
    
    return sign*result;
    
}


void reverse(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char c = str[start];
        str[start] = str[end];
        str[end] = c;
        
        start++;
        end--;
    }
}


char* itoa(int number, char* str, int base) {
    bool isNegative = false;
    int i = 0;
    if (base == 10 && number < 0) {
        isNegative = true;
        number = -number;
    }
    
    while (number != 0) {
        int result = number%base;
        str[i++] = (result > 9) ? (result - 10) + 'a' : result + '0';
        number = number / base;
    }
    
    if (isNegative) {
        str[i++] = '-';
    }
    
    str[i] = '\0';
    reverse(str, i);
    return str;

}

int main() {
    const char *str = "-AA";
    printf("%d\n", Myatoi(str));
    
    
    char string[100];
    cout << itoa(1567, string, 16) << endl;
    
    
}
