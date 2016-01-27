#include <stdio.h>
#include <ctype.h>
/* copy input to output; 1st version */
main()
{
int c;
int previouschar;

//this is for lines of whitespace; detects if there is a character between newlines and turns to 1
int charactermark;

while (c = getchar() != EOF) {

//detect new line
//if(detectNewLine()) either print numbers of n or don't print else continue with loop ;
	//for(int i, a, i++)
putchar(c);

}
}

int detectNewLine( int c ){ return (c == '\n')?  1 :  0; }

int isVaid(){}