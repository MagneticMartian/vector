#include <stdio.h>
#include <stdlib.h>

const int MAXCAP = 1024;

typedef struct vec {
	int *array;
	int length;
	int capacity;
} Vec;

Vec new(Vec arr, int size)
{
	arr.array = malloc(size*sizeof(int));
	arr.length = size;
	arr.capacity = MAXCAP;

	return arr;
}

Vec expand(Vec arr, int size)
{
	int new_length = 2*size;
	if(new_length < arr.capacity){
		arr.array = realloc(arr.array, new_length*sizeof(int));
		arr.length = new_length;

		return arr;
	} else {
		fprintf(stderr, "Vector capacity exceeded\n");
		exit(1);
	}
}

int main(void)
{
	const int MAX = 10;
	Vec arr = new(arr, MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, 2*MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, 4*MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, 8*MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, 16*MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, 32*MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
	arr = expand(arr, 64*MAX);
	printf("%p, %d, %d, \n", arr.array, arr.length, arr.capacity);
}