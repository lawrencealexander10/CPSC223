#include <stdio.h>
#include <ctype.h>
/* copy input to output; 1st version */
int wordelse();
int detectNewLine();
int isValid();
int checkIfRestOfLine();

int main()
{
	int c;
//holds previous character
	int previouschar = 0;
//holds line number
	int linenumber = 0;
//detects if there is whitespace between newlines and is 1 when there is a character
	int isThereACharacter= 0;
//splice
	int splice = 0;
//else keyword
	int elseword= 0;
//specialwhitespace
	int specialwhitespace = 0;
// do not reset previous char
	int donotreset = 0;
//comment
	int comment = 0;
//open
	int open = 0;

	while ((c = getchar()) != EOF) {
		 //checks for line splices
		if (c == '\\'){
			putchar(c);
			if((c= getchar()) == '\n'){
				donotreset = 1;
			}
		}

//check if lines of code contain a character, if so not valid
		if(!isspace(c) &&  c != '{' && c !='}' && c != '(' && c != ')'  ){isThereACharacter = 1;} 

//check for specialwhitespace
		if( c == '{' || c =='}' || c == '(' || c == ')'){
			specialwhitespace = 1;
			//printf("specialwhitespace");
		}

//comments
		// if(previouschar == '/' && c == '/'){
		// 	comment = 1;
		// }
		// if(previouschar == '/' && c == '*'){
		// 	open = 1;
		// }
		// if(open == 1 && previouschar == '*' && c == '/'){
		// 	open = 3;
		// }
//quotes

//set previouschar
		if(donotreset != 1){
			previouschar = c;
		}

//if there is a new line
		if(detectNewLine(c)){
			++linenumber;
 	//check if previous line is valid
			if(isValid(isThereACharacter, donotreset, specialwhitespace, comment, open)){
 		//replace \n with  " //%d\n"
			printf(" //%d\n", linenumber);
			//set variables to original state
			isThereACharacter = 0;
			donotreset = 0;
			specialwhitespace = 0;
				continue;
			}
			else{
				--linenumber;
			//set variables to original state
				//do not turn comment to 0 if there is a splice
				//possibly refactor
					if(comment == 1 && donotreset==1){
					}
					else{
						comment =0;
					}
					if(open == 3){
						open = 0;
					}
			isThereACharacter = 0;
			donotreset = 0;
			specialwhitespace = 0;
			}


			
			//elseword = 0;
		}
		putchar(c);
	}
}

//functions

int detectNewLine( int c ){
	if(c == '\n'){  
		return 1;
	}
	else{ 
		return 0;
	}  
}


int isValid( int isThereACharacter, int donotreset, int specialwhitespace, int comment, int open){
	specialwhitespace = checkIfRestOfLine(isThereACharacter, specialwhitespace);
	comment = checkIfRestOfLine(isThereACharacter, comment);
	return (isThereACharacter == 1 && specialwhitespace == 0 && donotreset == 0 && comment == 0 && open == 0) ? 1: 0;
}

int checkIfRestOfLine(int isThereACharacter, int specialwhitespace){
	if(( isThereACharacter == 1 && specialwhitespace == 1 ) || specialwhitespace == 0 ){
		return 0;
	}
	else{
		return 1;
	}
}
