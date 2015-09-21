/* 
  Pedro Thiago Rocha de Alcantara - 110019121
  
*/

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int parent (int index){
	int parent = 0;
	parent = (index+1)/2;
	parent--;
	return parent;
}
int left (int index){
	int left = 0;
	left = 2*(index+1);
	left--; 
	return left;
}
int right (int index){
	int right = 0;
	right = (2*(index+1))+1;
	right--;
	return right;
}
vector <int> changeParent (vector <int> heap, int element, int index){
	
	int temp = 0;
	temp = heap[parent (index)];
	heap[parent (index)] = element;
	heap[index] = temp;
	
	if(parent (parent(index)) >= 0){
		if(element <= heap[parent (parent(index))]){
			return heap; 
		}else{
			return changeParent (heap, element, parent(index));			
		}
	}else{
		return heap;
	}
	
}
vector <int> heapfy (vector <int> heap, int parentIndex, int length);

vector <int> insertElement (vector <int> heap, int element, int index){
	if (index == 0){
		heap [0] = element;
		
	}else{
		int parentI = 0;
		parentI = parent(index);
		
		if(element <= heap [parentI]){
			heap [index] = element; 
		}else{
			heap = changeParent (heap, element, index);			
		}
		
	}
	return heap;
}

vector <int> removeElement (vector <int> heap, int length){
	int temp = 0;
	temp = heap [0];
	heap [0] = heap [length-1];
	heap [length-1] = temp;
	
	heap = heapfy (heap, 0, length);
	
	return heap;
}
vector <int> heapfyComplete (vector <int> heap, int parentIndex, int length){
	
	int rightI = 0;
	rightI = right (parentIndex);
	int leftI = 0;
	leftI = left(parentIndex);
	
	if((heap[parentIndex]>=heap[leftI]) && (heap[parentIndex]>=heap[rightI])){
		return heap;
	}else{
		if(heap[leftI] >= heap[rightI]){
			int temp = 0;
			temp = heap[parentIndex];
			heap[parentIndex] = heap[leftI];
			heap[leftI] = temp;
			return heapfy (heap, leftI, length);
		}else{
			int temp = 0;
			temp = heap[parentIndex];
			heap[parentIndex] = heap[rightI];
			heap[rightI] = temp;
			return heapfy (heap, rightI, length);
		}
	}
}

vector <int> heapfyLeft (vector <int> heap, int parentIndex){
	
	int leftI = 0;
	leftI = left(parentIndex);
	
	if(heap[parentIndex] >= heap[leftI]){
		return heap;
	}else{
		int temp = 0;
		temp = heap[parentIndex];
		heap[parentIndex] = heap[leftI];
		heap[leftI] = temp;
		return heap;
	}
}

vector <int> heapfy (vector <int> heap, int parentIndex, int length){
	
	int rightI = 0;
	rightI = right (parentIndex);
	int leftI = 0;
	leftI = left(parentIndex);
	
	if (leftI <= (length-1)){
		if (rightI <= (length-1)){
			return heapfyComplete(heap, parentIndex, length);	
		}else{
			return heapfyLeft(heap, parentIndex);
		}
	}else{
		return heap;
	}
}

int main(){
	int length = 10;
	
	vector <int> elements(length, 0);
	
	/* initialize random seed: */
	srand (time(NULL));

	for (int i = 0; i < length; i++){
		int random;
		random = rand() % 10 + 0;
		elements[i] = random;
	}
	cout << "\nElementos desordenados:\n[ ";
	for (int i = 0; i < length; i++){
		cout<< elements[i]<<" ";
	}
	cout << "]\n";
	
	vector <int> heap(length, 0);
	
	
	for (int i = 0; i < length; i++){
		heap = insertElement (heap, elements[i], i);
	}
	
	cout << "\nElementos na Heap:\n[ ";
	for (int i = 0; i < length; i++){
		cout<< heap[i]<<" ";
	}
	cout << "]\n";
	
	for(int i = length-1; i >=0 ; i--){
		heap = removeElement (heap, i+1);
	cout << "\nElementos ordenados:\n[ ";
	for (int i = 0; i < length; i++){
		cout<< heap[i]<<" ";
	}
	cout << "]\n";
	}
	
	cout << "\nElementos ordenados:\n[ ";
	for (int i = 0; i < length; i++){
		cout<< heap[i]<<" ";
	}
	cout << "]\n";
	
}
