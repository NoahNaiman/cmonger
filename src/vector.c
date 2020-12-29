/*TODO:
  1. Finish necessary functions
  2. Flush out all routes for different data types
*/

#include "cmonger.h"

//CURRENTLY ONLY DEALS WITH INTS
Vector* vectorize(void* items, int itemsLength, int typeLength, char* type){
	Vector* newVector = (Vector *)malloc(sizeof(Vector));

	if(items != NULL){
		newVector->bufferLength = itemsLength*4;
		newVector->index= itemsLength-1;
		newVector->typeLength = typeLength;
		newVector->type = type;
		newVector->buffer = calloc(itemsLength*4, typeLength);

		int i = 0;
		unsigned int typeHash = hash_ui(type);
		newVector->typeHash = typeHash;

		switch(typeHash){
			case(INT):
				for(; i < itemsLength; ++i){
					((int*)newVector->buffer)[i] = ((int*)items)[i];
				}
				break;
			default:
				printf("This type of data is not supported!\n");
				return(NULL);
		}
	}
	return(newVector);
}
void append_to_int_vector(Vector* vector, int item){
	int index = vector->index;
	int bufferLength = vector->bufferLength;

	if(index == (bufferLength-1)){
		bufferLength = bufferLength*2;
		if(!(realloc(vector->buffer, bufferLength))){
			printf("ERROR: Enlargment of vector failed!\n");
			return;	
		}
		vector->bufferLength = bufferLength;
	}
	index = index+1;
	vector->index = index;
	((int*)vector->buffer)[index] = item;
	return;
}

void insert_into_int_vector(Vector* vector, int item, int location){
    int index = index->vector;
    int bufferLength = vector->bufferLength;

    if(location < 0){
        printf("ERROR: invalid insertion location!\n")
    }
    else if(location > bufferLength){
        while(location > bufferLength){
            bufferLength = bufferLength*2;
            if(!(realloc(vector->buffer, bufferLength))){
                printf("ERROR: Enlargment of vector failed!\n");
                return;
            }
        }
        vector->bufferLength = bufferLength;
    }
    else if(location == index){
        append_to_int_vector(vector, item);
    }
    else{
        
    }
}

int get_fromv_int(Vector* items, int index){
	return(((int*)items->buffer)[index]);
}

