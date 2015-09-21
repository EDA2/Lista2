#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int extract_max(int array[], int left, int right, int root){
	int max_child = 0;

	if(array[left] > array[root]){
		max_child = left;
	}else{
		max_child = root;
	}

	if(array[right] > array[max_child]){
		max_child = right;
	}	

	return max_child;
}

void print_heap(int array[], int array_size) {
	for (int i = 0; i < array_size; ++i)
	{
		printf("%d ", array[i]);
		if (array[i] != array[array_size-1])
		{
			cout << ",";
		}
	}
	cout << endl;
}

void heapify(int array[], int i, int array_size) {
	int left = 2*i;
	int right = 2*i + 1;
	int max_child = 0;

	if(left < array_size && right < array_size){
		
		max_child = extract_max(array, left, right, i);

		if(max_child != i){
			swap(array[i], array[max_child]);
			heapify(array, max_child, array_size);
		}
	}
}

void build_heap(int array[], int array_size) {
	for (int i = (array_size/2)-1; i >= 0; --i)
		heapify(array, i, array_size);
}

void heap_sort(int array[], int array_size)
{

  build_heap(array, array_size);

  for (int i = array_size-1; i > 1; i--)
  {
    swap(array[0], array[i]);
    heapify(array, 0, i-1);
  }
}

int main(){
	unsigned int size_vector = 0;
	int i = 0;

	printf("Insira o tamanho do vetor que deseja estudar: ");
	scanf("%d", &size_vector);

	while (size_vector <= 0) {
		printf("Você precisa de um vetor de tamanho acima de 0: ");
		scanf("%d", &size_vector);
	}

	int *my_array;
	my_array = (int *) malloc(sizeof(int)*size_vector);

	for(i=0; i<size_vector; i++) {
		printf("Insira o valor de a[%d]: ", i);
		scanf("%d", (my_array+i));
	}

	print_heap(my_array, size_vector);
	heap_sort(my_array, size_vector);
	print_heap(my_array, size_vector);
	
	return 0;
}

