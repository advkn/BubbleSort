
#include <iostream>
#include <vector>
#include <map>
//using namespace std;


//Print the contents of an array.
void print(int input[], int n) {
	for(int i = 0; i < n; i++) {
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}


/*
void printVector(std::vector<int> v) {

	std::vector<int>::iterator pos = v.begin();		//create an iterator for a vector
	while(pos != v.end()) {
		std::cout << *pos << " ";
		++pos;
	}
	std::cout << std::endl;
}
*/



/* BUBBLE SORT

Description:
Bubble sort is the simplest sorting algorithm.  It works by iterating the input array from the 
first element to the last, comparing each pair of elements and swapping them if needed. It continues
the iterations until no swaps are needed.

Advatage:
	1. Very simple algo to implement

Disadvantage:
	1. Very bad comlpexity

The swapped variable is a flag. When there are no more swaps, it indicates
the completion of sorting.  If the list is already sorted, by using this flag we can skip the remaining processes.*/

void bubbleSort(int input[], int n) {
	int swapped = 1;
	int count = 0;	//Used to count the number of times the input list is parsed
	for(int pass = n-1; pass >=0 && swapped; pass--) {
		swapped = 0;
		for(int i = 0; i < pass; i++) {
			if ( input[i] > input[i+1] )
			{
				count++;
				//swap elements
				int temp = input[i];
				input[i] = input[i+1];
				input[i+1] = temp;
				swapped = 1;
				std::cout << "Parse " << count << ": ";
				print(input, n);
			}
		}	
	}
}


/*SELECTION SORT

Description: This algo is called a selection sort because it "repeatedly
			 selects the smallest element."

Advantages: 
	1. Easy to implement.
	2. In-place sort (requires no extra storage).

Disadvantages:
	1. Does NOT scale well. O(n^2)

Algorithm:
	1. Find the minimum value in the list.
	2. Swap it with the value in the current position.
	3. Repeat this process for all the elements until the entire array is sorted.

*/
void selectionSort(int input[], int n) {

	int i, j, minIndex, temp;
	for(i = 0; i < n; i++) {
		minIndex = i;
		for(int j = i+1; j < n; j++) {
			if(input[j] < input[minIndex]) {
				minIndex = j;
			}
		}
		//swap elements
		if(minIndex != i) {
			temp = input[i];
			input[i] = input[minIndex];
			input[minIndex] = temp;	
			print(input, n);
		}
	}
}


/*INSERTION SORT

Description:
Insertion sort is a simple and effecient comparison sort.
In this algorithm, each iteation removes an element from the input data and inserts it into the correct
position in the list being sorted.The choice of the element  being removed from the input is random
and this process is repeated until all input elements have been gone through.
Sorting is done IN PLACE.

Advantages:
	1. Simple implementation.
	2. Efficient for small data.
	3. Adaptive: If the input list is presorted, then insertion sort takes O(n+d), 
	   where d is the number of inversions.
	4. Practically more efficient than Selection or Bubble sorts even though all of
		them have have O(n^2) worst case complexity.
	5. Stable: Maintains relative order of input data if the keys are the same.
	6. In place: It requires only constant amount O(1) of additional memory space.
	7: Online: Insertion sort can sort the list as it retrieves it.

Performance:
	Worst: Best: Average case: O(n^2)
	Space complexity: O(1)
*/
void insertionSort(int input[], int n) {
	int i, j, temp;
	for(i = 1; i < n; i++) {
		j = i;
		while(j > 0 && input[j-1] > input[j]) {
			temp = input[j];
			input[j] = input[j-1];
			input[j-1] = temp;
			j--;
			print(input,n);
		}
	}
	
}



/*QUICKSORT*/
void Quicksort(int input[], int left, int right) {
	
	int pivot, temp, i, j;
	i = left;
	j = right;
	pivot = input[(left+right)/2];	//pivot point

	//while the left index is LESS than the right index
	while(i <= j) {
		//increment the left index UNTIL the while condition is false(when a value GREATER than the pivot is found).
		while(input[i] < pivot) {
			i++;
		}
		//decrement the right index UNTIL the while condition is false(when a value LESSER the the pivot is found).
		while(input[j] > pivot) {
			j--;
		}
		/*If the above conditions are falsified AND the left index is still LESS THAN the right index, 
		perform the necessary swap, increment the left index and decrement the right index until the
		pivot point is reached.*/
		if(i <= j) {
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;	
			i++;
			j--;
		}	
	}

	/*After the swaps, the incrementation of index i puts it on the right side of the pivot (beginning element of
	the right array).  And the decrementation of j puts it on the left side of the pivot (last element of the left array).*/

	//recusively sort the left side
	if(left < j) {
		Quicksort(input, left, j);
	}
	//recursively sort the right side
	if(i < right) {
		Quicksort(input, i, right);
	}
	print(input, 6);	//the harcoded 6 corresponds to the input4 array that has 6 elements

}


/* MergeSort - Used to combine two already SORTED arrays/files into one bigger sorted file.
   Uses an auxillary array.
   m - size of A[]
   n - size of B[]
   size of auxiallary array C[] must be EQUAL TO or GREATER than m+n.
*/
void merge(int m, int n, int A[], int B[], int C[]) {

	int i, j, k;
	i = 0;	//corresponds to the index of array A[]
	j = 0;	//corresponds to the index of array B[]
	k = 0;	//corresponds to the index of array C[]

	/*while the current index of both arrays is LESS than the SIZE of their
	respective arrays, compare the values at each index and choose which one to insert into the auxillary array.*/
	while (i < m && j < n) {
		if(A[i] <= B[j]) {
			C[k] = A[i];
			i++;
		}
		else {
			C[k] = B[j];
			j++;
		}
		k++;
	}
	
	/*Any array elements that are left over, finish adding them to the newly sorted and merged array.*/
	if(i < m) {
		for(int p = i; p < m; p++) {
			C[k] = A[p];
			k++;
		}
	}
	else {
		for(int p = j; p < n; p++) {
			C[k] = B[p];
			k++;
		}
	}
}

//Merge function using the backfill method. -- UNFINISHED
void mergeBackfill(int m, int n, int A[], int B[]) {
	
	int i = 0;
	int j = 0;
	int k = 0;


}

//Find the first empty index of an array.
int findCount(int b[]) {
	int i = 0;
	while (b[i] != 0) {
		i++;
	}
	return i;
}

//Find duplicates in an array
void checkDuplicates(int A[], int n) {
	int duplicate;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(A[i] == A[j]) {
				duplicate = A[i];
				std::cout << duplicate << ", ";
			}
		}
	}
}

//INCORRECT NEEDS FIXING
//find the count of the maximum repeated element.
int checkElectionWinner(int A[], int n) {

	int i, j, counter, maxCounter, candidate;
	counter = 0;

	maxCounter = 0;
	candidate = A[0];

	for(i = 0; i < n; i++) {
		//initialize each successive candidate as the current candidate, initialize/reset the counter to 0.
		candidate = A[i];
		counter = 0;
		/*secondary iteration to check if the candidate shows up anywhere else.  
		If true, increment the counter by one, each time it is found.*/
		for(j = i+1; j < n; j++) {
			if(A[i] == A[j]) {
				counter++;
			}
		}
		/*check if the current candidate count supercedes the previous
			cadidate's count.  If so, the current candiate is the winner.*/
			if(counter > maxCounter) {
				maxCounter = counter;
				candidate = A[i];
			}
	}
	return candidate;
}




void main() {

	int output[12];

	/*Reason for different inputs: the other alogos will recieve a sorted list, not a new instance
	of the input[] variable/array, and therefore will not process.*/
	int input[10] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
	int input2[6] = {500, 400, 300, 600, 200, 100};
	int input3[6] = {780, 400, 450, 1200, 900, 800};
	int input4[6] = {990, 500, 450, 1200, 1600, 243};

	int input5[6] = {1,3,6,9,12,15};
	int input6[6] = {2,3,5,7,8,11};
	int input7[12] = {2,3,5,7,8,11};

	
	std::cout << "Original unsorted input: ";
	print(input, 10);	//original unsorted input
	std::cout << "\n" << std::endl;
	bubbleSort(input, 10);

	std::cout << "\n\n" << std::endl;
	std::cout << "Using Selection Sort:" << std::endl;
	selectionSort(input2, 6);

	std::cout << "\n\n" << std::endl;
	std::cout << "Using Insertion Sort:" << std::endl;
	insertionSort(input3, 6);

	std::cout << "\n\n" << std::endl;
	std::cout << "Using Quicksort Sort:" << std::endl;
	Quicksort(input4, 0, 5);
	

	std::cout << "\n\n" << std::endl;
	std::cout << "Using Mergesort:" << std::endl;
	merge(6, 6, input5, input6, output);
	print(output, 12);

	//printVector(myVector);


	//gets the size of an array (number of elements), will NOT work in a function outside of main
	int size = sizeof input5/sizeof(int);
	std::cout << "\n\nReturn the size of an array: ";
	std::cout << size;

	//check for duplicates in the given array.
	int inputDup[12] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 400, 1000, 600};
	std::cout << "\n\nCheck for duplicates: ";
	checkDuplicates(inputDup, 12);


	//Find the winning candidate (element with the highest count).
	int inputElection[11] = {2,2,2,2,2,2,2,2,3,3,3};
	std::cout << "\n\nFind the election winner: ";
	std::cout << checkElectionWinner(inputElection, 11);


	getchar();
}