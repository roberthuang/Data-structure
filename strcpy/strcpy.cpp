#include <stdio.h>
#include <string.h>

#ifndef HELLO_MESSAGE
# error "You have forgotten to define the header file name."
#endif
void copy_string(char*s) {
    char * t = new char[strlen(s)+1];
    int i ;
    for (i = 0; s[i] != '\0';i++) {
        t[i] = s[i];
    }
    t[i] = '\0';
    printf("string of t: %s",t);
}
int main() {
    char s[] = "Hello";
    copy_string(s);
}

