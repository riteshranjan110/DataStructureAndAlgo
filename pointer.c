#include <stdio.h>

int main(){
    char c[] = "limericks";
    char * s;
    s = &c[6]-6;
    while(*s){
        printf("%c",*s++);
    }
    return 0;
}