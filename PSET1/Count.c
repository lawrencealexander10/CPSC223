#include <stdio.h>
#include <ctype.h>
/* copy input to output; 1st version */
int wordelse();
int detectNewLine();
int isValid();

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

	while ((c = getchar()) != EOF) {
//check if lines of code contain a character, if so not valid
		if(!isspace(c) &&  c != '{' && c !='}' && c != '(' && c != ')'  ){isThereACharacter = 1;} 

 //checks for line splices
		if (previouschar == '\\' && c == '\n'){
			splice = 1;
		}

//check for specialwhitespace
		if( c == '{' || c =='}' || c == '(' || c == ')'){
			specialwhitespace = 1;
			//printf("specialwhitespace");
		}
//check for "each"
	// 	if(previouschar == ' ' && c == 'e'){
	// 		elseword = wordelse(c);
	// //in case wordelse reaches EOF
	// 		if(elseword == 100){
	// 			break;
	// 		}
	// 	}

//set previouschar
		previouschar = c;

//if there is a new line
		if(detectNewLine(c)){
			++linenumber;
 	//check if previous line is valid
			if(isValid(isThereACharacter, splice, specialwhitespace)){
 		//replace \n with  " //%d\n"
				printf(" //%d\n", linenumber);
				 		//set variables to original state
			isThereACharacter = 0;
			splice = 0;
			specialwhitespace = 0;
				continue;
			}
			else{
				--linenumber;
				 		//set variables to original state
			isThereACharacter = 0;
			splice = 0;
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


int isValid( int isThereACharacter, int splice, int specialwhitespace){
	int together = 0;
	if((specialwhitespace == 1 && isThereACharacter == 1) || isThereACharacter == 1 ){
		//printf("specialwhitespace"  );
		together = 1;
	}
	// if (isThereACharacter)
	// {
	// 	printf("isThereACharacter"  );
	// }
	// 
	// if( (isThereACharacter == 1 && specialwhitespace == 1) || specialwhitespace == 0) {
	// 	together = 1;
	// }
	return (isThereACharacter == 1 && splice == 0 && together == 1 ) ? 1: 0;
}

// int wordelse(int pastc){
// 	int c;
//  putchar(pastc)
// 	for(int i = 0; i < 4; i++ ){
// 		if((c = getchar()) != EOF){
// 			switch(i){
// 				case '0':
// 				if(c != 'l'){
// 					return 0;
// 				}
// 				else{
// 					printf("#2");
// 				}
// 				break;

// 				case '1':
// 				if(c != 's'){
// 					return 0;
// 				}
// 				else{
// 					printf("#2");
// 				}
// 				break;

// 				case '2':
// 				if(c != 'e'){
// 					return 0;
// 				}
// 				else{
// 					putchar(c);
// 				}				
// 				break;

// 				case '3':
// 				if(c != ' '){
// 					return 0;
// 				}
// 				else{
// 					return 1;
// 				}
// 				break;

// 				// default:
// 				// printf("Case is broken");
// 				// return 99;
// 				// break;
// 			}
// 		}
// 		// else{
// 		// 	return 100;
// 		// }
// 	}
// 	return 0;
// }


