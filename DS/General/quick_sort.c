#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int *)b);
}

int main(){
	int a[10] = {88, 43, 55, 56, 76, 45, 23, 89, 98, 10};

	printf("Unsorted Array: \n");
	for (int i = 0; i < 10; ++i)
		printf("%d  ", a[i]);
	printf("\n");

	qsort(a, sizeof(a), sizeof(int), compare);
	printf("Sorted Array: \n");
	for (int i = 0; i < 10; ++i)
		printf("%d  ", a[i]);
	printf("\n");	

	return 0;
}