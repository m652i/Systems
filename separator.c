#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct		Word{
	char*		textPtr_;
	struct Word*	nextPtr_;
};


struct Word* obtainCommaSeparatedList (const char* string){
	struct Word* toReturn = NULL;
	struct Word* curPtr = NULL;
	//check comma
	while(1){
		//char* r = strchr(string,',');
		//if (r != NULL){r = '\0';}               
		const char* comPtr = strchr(string,',');
		struct Word* temp = (struct Word*)malloc(sizeof(struct Word));

		if (toReturn == NULL){
			toReturn = temp;
			curPtr = temp;
			temp -> nextPtr_ = NULL;
		}
	
		else{
			curPtr -> nextPtr_ = temp;
			curPtr = temp;
			temp -> nextPtr_ =  NULL;
		}

		if (comPtr == NULL){
			temp -> textPtr_ = (char*)malloc(strlen(string) + 1); //rem +1
			strncpy (temp -> textPtr_, string, strlen(string)); //no +1
			break;
		}

		else{
			temp -> textPtr_ = (char*)malloc((comPtr - string) +1);
			strncpy (temp -> textPtr_, string,(comPtr - string));
			char* r = strchr(temp -> textPtr_,',');
	     		if (r != NULL){r = '\0';}
             		string = comPtr + 1;
			}

	}
	return(toReturn);
}

void printCommaSeparatedList (const struct Word* list){
	if(list != NULL){
		printf("\"%s\"\n", list -> textPtr_);
		printCommaSeparatedList (list -> nextPtr_); //recur eas
	} 
}

void freeCommaSeparatedList (struct Word* list){
	if (list != NULL){
		freeCommaSeparatedList (list -> nextPtr_);
		list -> textPtr_ = NULL;
		free(list);
	}
}
int			main(		)		 {
	char string[256];
	
	printf("Please enter a string with commas : ");
	fgets(string, 256, stdin);
	char* k = strchr(string,'\n');//seems like theres always a \n
	*k ='\0'; 
	struct Word* list = obtainCommaSeparatedList(string);
	printCommaSeparatedList(list);
	freeCommaSeparatedList(list);
     return(EXIT_SUCCESS);
}
