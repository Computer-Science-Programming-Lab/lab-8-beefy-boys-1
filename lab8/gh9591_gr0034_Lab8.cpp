//==========================================================
//
// Title:      Lab 8
// Course:     CSC 1501
// Lab Number: Lab 8
// Author:     Austin Murad, Timothy Armstrong
// Date:       3/10/2020
// Description:
//   this program will
// - test differnt sorting algorithms
// 
// 
//==========================================================
#include <conio.h> // For function getch()
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <stdio.h>
using namespace std; // So "std::cout" may be abbreviated to "cout"

// class decalration
class sort
{
public:
	
	//Generate random integers
	void randomIntegers(int size);

	//function to swap to elements
	void swap(int* p_1, int* p_2);

	//Function for Select Sort 
	//input: arr = array of numbers, l = size of the array
	//output: run time and sorted array
	void selectSort(int arr[], int l);
	
	//Partition function 
	//takes the last element as pivot then moving all the 
    //#'s > pivot to the right and #'s < pivot to the left
	int partition(int arr[], int first, int last);


	//Function for Quick Sort
	//input: arr = array of numbers to be sorted, first = starting index
	//       last = ending index 
	//output: run time and sorted array
	void quickSort(int arr[],int first, int last);

	//Function for dividing the input array in half then merges the two halves into an arrays
	void merge(int arr[], int l, int m, int r);

	//Function for merge sort
	//input:arr[] = arr of numbers, int l = left, int r = right
	//output: sorted array and the run time
	void mergeSort(int arr[], int l, int r);

private:
	int arr[4];
};

//function to provide the random intergers
//input: size = number emements in the array
//output:
void sort::randomIntegers(int size)
{
	sort s;
	int arr[5];
	int j = 0;
	int k = 1;
	
	for (int i = 0; i <= size - 1; i++)
	{
		j = pow(10, k);
		arr[i] = rand() % j + 1;
		k++;
	}

	for (k = 0; k <= size - 1; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;
}

//Swap function for selcet sort
//swap the values
void sort::swap(int* a, int* b)
{
	int save = *a;
	*a = *b;
	*b = save;
}

//function for solect sort
//input: arr = array of numbers, l = length of the array
//output: run time and sorted array
void sort::selectSort(int arr[], int l)
{
	int minVal = 0;
	sort s;

	//for loop moveing through the unsorted subarray
	for (int u = 0; u < l - 1; u++)
	{
		minVal = u;

		//for loop to find the smallest element
		for (int c = u + 1; c < l; c++)
		{
			if (arr[c] < arr[minVal])
				minVal = c;
		}
		//call swap function to swap the elements
		s.swap(&arr[minVal], &arr[u]);
	}

	//for loop to print out the array
	for (int i = 0; i <= l-1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//Partition function 
//takes the last element as pivot then moving all the 
//#'s > pivot to the right and #'s < pivot to the left
int sort::partition(int arr[], int first, int last)
{
	//decalre variables
	int pivot = arr[last];
	int i = (first - 1);
	sort s;

	//for loop for looping throught the array 
	for (int j = first; j <= last - 1; j++)
	{
		//swaps if current element is smaller then pivot
		if (arr[j] < pivot)
		{
			i++;
			s.swap(&arr[i], &arr[j]);
		}
	}
	s.swap(&arr[i + 1], &arr[last]);
	
	
	return(i + 1);
}

//Function for the quick sort
//input: arr = array of numbers to be sorted, first = starting index
//       last = ending index
//output: run time and sorted array
void sort::quickSort(int arr[], int first, int last)
{
	sort s;
	

	if (first < last)
	{
		//partition index
		int p = s.partition(arr, first, last);

		//separate elements into pre and post partition
		quickSort(arr, first, p - 1);
		quickSort(arr, p + 1, last);
	}

}

//Funtion for the soft sort
//input: l = leftmost position, m = middle, r = right most position
//       arr = array of inputs
//output:
void sort::merge(int arr[], int l ,int m, int r)
{
	//decalre variables
	int i;
	int j;

	//length of the the two arrays 
	int n1 = m - l + 1;
	int n2 = r - m;

	//temp arrays
	int left[10];
	int right[10];

	//copy data to left array
	for (i = 0; i < n1; i++)
	{
		left[i] = arr[l + i];
	}
	
	//copy data to right array
	for (j = 0; j < n2; j++)
	{
		right[j] = arr[m + 1 + j];
	}

	//reset indexes
	i = 0;
	j = 0;
	//merge index
	int k = l;

	//merge the temp arrays back into one array
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	//to get the remaining elements of left[]
	while (i < n1)
	{
		arr[k] = left[i];
		k++;
		i++;
		
	}

	//to get the remaining elements of right[]
	while (j < n2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}

}

//Function for merge sort
//input:arr[] = arr of numbers, int l = left, int r = right
//output: sorted array and the run time
void sort::mergeSort(int arr[], int l, int r)
{
	sort s;

	if (l < r)
	{

		int m = l + (r - l) / 2;

		s.mergeSort(arr, l, m);
		s.mergeSort(arr, m + 1, r);

		s.merge(arr, l, m , r);
	}

	//print array
	for (int i = 0; i <= 4; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



int main()
{
	// Declared object
	sort s;
	int arr[] = { 55,24,64,1,36};
	int arraySize = sizeof(arr) / sizeof(arr[0]);

	// application header
	cout << "start of Application " << endl;
	cout << "--------------------" << endl << endl;

	s.randomIntegers(4);
	s.quickSort(arr, 0, arraySize - 1);
	s.selectSort(arr, arraySize);
	s.mergeSort(arr, 0, arraySize - 1);

	// application close
	cout << "------------------" << endl;
	cout << "End of Application" << endl;


}
