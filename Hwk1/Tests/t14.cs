char *hdr = "Preprocessor directives (graceful)"; //1
#include <stdio.h> //2
#define TRUE  1                 /* Truth and falsity */ //3
#define FALSE 0 //4
int main() { //5
    char c = '!'; //6
    #ifdef DEBUG //7
        printf ("c = >%c<\n", c); //8
    #endif //9
    printf ("Hello world%c\n", c); //10
    return 0; //11
}
