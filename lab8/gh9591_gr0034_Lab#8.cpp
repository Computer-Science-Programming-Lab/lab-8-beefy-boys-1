//==========================================================
//
// Title:      Fundamental Structures Lab 8
// Course:     CSC 1501
// Lab Number: Lab #8
// Author:     Austin Murad, Timothy Armstrong
// Date:       03/06/2020
// Description:
//   This program will run through different sorting
// algorithms
//==========================================================
#include <cstdlib> //For several general-purpose functions
#include <iomanip> //For formatted output
#include <iostream> //For cin, cout, and system
#include <string> //For string data type
#include <cmath> //For several math functions
#include <fstream> //For file handling
using namespace std;

//==========================================================
//Global
//==========================================================
int arrSize = 6;

//==========================================================
//create a class of Sort
//==========================================================
class Sort
{
public:
    void randNumGen(int arr[]);
    //Will generate the random number of either 10, 100, 1000, 10000 or 100000
    
    void selectionSort(int arr[]);
    //
    
    void quickSort(int arr[]);
    //
    
    void mergeSort(int arr[]);
    //
};

//==========================================================
//implement the randNumGen
//==========================================================
void Sort::randNumGen(int arr[])
{
    //to generate random see for rand()
    srand(time(0));
    
    //loop through the array
    for (int i = 0; i < arrSize; i++)
    {
        //randomize an idex number in the range of 6
        int index = rand() % 6;
        //assign a value of the random index to a temperary variable then equat the numbers to the reandom index given in the array to get 1 of each of the elements in the array
        swap(arr[i], arr[index]);
    }
    
    //output the array, might not use...
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}

//==========================================================
//implement selectionSort
//==========================================================
//look over this algorithm and make sure it is what he wants in the pseudo code given
void Sort::selectionSort(int arr[])
{
    //declare variable
    int minIndex;
    //loop to find index
    for (int i = 0; i < arrSize - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            swap(arr[i], arr[minIndex]);
        }
    }
}

//==========================================================
//implement quickSort
//==========================================================
void Sort::quickSort(int arr[])
{
    cout << "working" << endl;
}

//==========================================================
//implement mergeSort
//==========================================================
void Sort::mergeSort(int arr[])
{
    cout << "working" << endl;
}

//==========================================================
//Main
//==========================================================
int main()
{
    //create an object
    Sort temp;
    int array[] = {1, 10, 100, 1000, 10000, 100000};
    temp.randNumGen(array);
    temp.selectionSort(array);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << array[i] << endl;
    }
    
    return 0;
}

