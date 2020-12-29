#include "cmonger.h"
int main(int argc, char** argv){
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
	Vector* myVec = vector_init(c);

	printf("Data type length of items in vector is: %zu\n", myVec->typeLength);
	printf("Buffer length of vector is: %zu\n", myVec->bufferLength);
	printf("Last filled index of vector is: %zu\n", myVec->index);
	printf("Type is: %s\n", myVec->type);
	int i;
	for(i = 0; i <= myVec->index; ++i){
		printf("%d\n", get_fromv_int(myVec, i));
	}

	printf("\n");
	appendtov(myVec, 6);
	appendtov(myVec, 8);

	for(i=0; i <= myVec->index; ++i){
		printf("%d\n", get_fromv_int(myVec, i));
	}
	return(0);
}
