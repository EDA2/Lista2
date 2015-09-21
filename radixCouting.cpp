/* 
  Pedro Thiago Rocha de Alcantara - 110019121
  
*/

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int digit (int number, int position){
	int digit = 0;
	for(int i = 0; i<position; i++)
		number = number /10;
	 
	digit = number % 10;
	
	return digit;
}

int main(){
	cout << "----------------\n";
	cout << "Tamnho-----Tempo\n";
	cout << "----------------\n";
	
	//run 20 times the algorithm
	for (int l = 1 ; l < 21; l++){
	
	// initialize elements vector with variable length and random elements
	int length = 100000*l;
	vector <int> elements(length, 0);
	srand (time(NULL));// initialize random seed: 

	for (int i = 0; i < length; i++){
		int random;
		random = rand() % 99999999 + 10000000;
		elements[i] = random;
	}

	
	int count [10];
	vector <int> elementsOrder(length, 0);

	/*cout << "\nElementos desordenados:\n[ ";
	for (int i = 0; i < length; i++){
		cout<< elements[i]<<" ";
	}
	cout << "]\n";*/

	clock_t beforeOrder;
	clock_t afterOrder;
	beforeOrder = clock();
	
	for(int j = 0; j < 8; j++){
	
		for (int i = 0; i < 10; i++){
			count [i] = 0;
		}
	
		for(int i = 0; i < length; i++){
			int d = digit (elements[i], j);
			count [d]++;
		}
	
		for (int i = 1; i < 10; i++){
			count [i] = count[i]+count[i-1];
		}
	
		for (int i = (length-1); i >= 0; i--){
			int element = elements[i];
			int positon = count [digit (elements[i], j)]-1;
			count [digit (elements[i], j)] --;
		
			elementsOrder [positon] = element;
		
		}
	
		for (int i = 0; i < length; i++){
		elements[i] = elementsOrder [i];
		}
		
	}
	afterOrder = clock();

	/*cout << "\nElementos ordenados:\n[ ";
	for (int i = 0; i < length; i++){
		cout<< elementsOrder[i]<<" ";
	}
	cout << "]\n";*/
	
	double seconds = (afterOrder - beforeOrder) * 1000.0/ CLOCKS_PER_SEC;
	cout <<"-"<< length <<" -- "<< seconds <<"-\n";
	}
	cout << "----------------\n";
}

