#include <stdio.h>

void my_toupper(char * s){
    int i = 1;
    if(s[0] <= 'z' && s[0] >= 'a'){
        s[0] = s[0] - 'a' + 'A';
    }
    while(s[i] != 0){
        if(s[i] <= 'Z' && s[i] >= 'A'){
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }
}

void my_toupper_second(char * s){
    if(*s <= 'z' && *s >= 'a'){
        *s = *s - 'a' + 'A';
    }
    s++;
    while(*s != 0){
        if(*s <= 'Z' && *s >= 'A'){
            *s = *s - 'A' + 'a';
        }
        s++;
    }
}

void print_string(char * s){
    int i = 0;
    while(s[i] != 0){
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}

int main(void){
    char string[] = "snEEuwwITJE<3!!";
    char woord[80];
    my_toupper_second(string);
    print_string(string);

    fgets(woord, 80, stdin);
    my_toupper(woord);
    print_string(woord);

    return 0;
}
