#include "cmonger.h"

/* djb2a hashing functions */

unsigned int hash_ui(char* string){
	unsigned int hash = 5381;
	int c;

	while((c = *string++)){
		hash = hash*33^c;
	}
	return(hash);
}

unsigned long hash_ul(char* string){
	unsigned long hash = 5381;
	int c;

	while((c = *string++)){
		hash = hash*33^c;
	}
	return(hash);
}

