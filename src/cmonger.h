/* Included headerfiles */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/* Enums */
enum DataNumbers {CHAR = 2087773917, CHARPTR = 177062487, INT = 193418006, INTPTR = 2087826940};


/* Macro-fu */
#define lengthof(x) (sizeof(x)/sizeof((x)[0]))

#define typename(x) _Generic((x),				\
	_Bool: "_Bool",						\
	char: "char", 						\
	char*: "char*",						\
	double: "double",					\
	float: "float",						\
	int: "int",						\
	int*: "int*",						\
	long double: "long double",				\
	long int: "long int",					\
	long long int: "long long int",				\
	short int: "short int",					\
	signed char: "signed char",				\
	unsigned char: "unsigned char",				\
	unsigned int: "unsigned int",				\
	unsigned long int: "unsigned long int",			\
	unsigned long long int: "unsigned long long int",	\
	unsigned short int: "unsigned short int",		\
	void*: "void*",						\
	default: "unknown")

#define casto(x) _Generic((x),					\
	char: (char)x,						\
	char*: (char*)x,					\
	double: (double)x,					\
	double*: (double*)x,					\
	float: (float)x,					\
	float*: (float*)x,					\
	int: (int)x,						\
	int*: (int*)x,						\
	default: (int*)x)

#define vector_init(x) vectorize(x, (lengthof(x)), sizeof((x)[0]), typename((x)[0]));

#define appendtov(vector, item) _Generic((item),			\
	int: append_to_int_vector(vector, item),			\
	default: append_to_int_vector(vector, item))

#define printf(f_, ...) printf((f_), ##__VA_ARGS__); 

/* Structures */
typedef struct{
	size_t typeLength;
	size_t bufferLength;
	size_t index;
	char* type;
	unsigned int typeHash;
	void* buffer;
}Vector;

/* Function definitions */

/* Vector functions */
Vector* vectorize(void* items, int itemsLength, int typeLength, char* type);
void append_to_int_vector(Vector* vector, int item);
int get_fromv_int(Vector* items, int index);

/* HashTable functions */
unsigned int hash_ui(char* string);
unsigned long hash_ul(char* string);
