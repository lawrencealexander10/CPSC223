#include <stdio.h>
#include <ctype.h>
/* copy input to output; 1st version */
int wordelse();

void main()
{
int c;
//holds previous character
int previouschar;
//holds line number
long linenumber;
//detects if there is whitespace between newlines and is 1 when there is a character
int isThereACharacter;
//splice
int splice;
//else keyword
int elseword;

while (c = getchar() != EOF) {
//check if lines of code contain a character, if so not valid
 if(!isSpace() && isThereACharacter != 1){isThereACharacter = 1;} 

 //checks for line splices
if (previouschar == '\\' && c == '\n'){
	splice = 1;
}

//check for "each"
if(previouschar == ' ' && c == 'e'){
	elseword = wordelse();
	//in case wordelse reaches EOF
	if(elseword == 100){
		break;
	}
}

//set previouschar
previouschar = c;

//if there is a new line
 if(detectNewLine(c)){
 	++linenumber;
 	//check if previous line is valid
 	if(isValid(isThereACharacter, splice, elseword)){
 		//replace \n with  " //%d\n"
 		printf(" //%d\n", linenumber, 'n');
 		continue;
 	}
 	else{
 		--linenumber;
 	}

 		//set variables to original state
			isThereACharacter = 0;
			splice = 0;
			elseword = 0;
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


int isValid( int isThereACharacter, int splice, int elseword){
	return (isThereACharacter == 1 && splice == 0 && elseword == 0) ? 1: 0;
}

int wordelse(){
	for(int i = 0; i < 4; i++ ){
		if(c = getchar() != EOF){
			switch(i){
				case '0':
				if(c != 'l'){
					return 0;
				}
				break;

				case '1':
				if(c != 's'){
					return 0;
				}
				break;

				case '2':
				if(c != 'e'){
					return 0;
				}
				break;

				case ' 3':
				if(c != ''){
					return 0;
				}
				else{
					return 1;
				}
				break;

				default:
				printf("Case is broken");
				break;
			}
		}
		else{
			return 100;
		}
	}
}

	
