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
//create a class of Sort
//==========================================================
class Sort
{
public:
    int randNumGen();
    //Will generate the random number of either 10, 100, 1000, 10000 or 100000
    
    int selectionSort(int arr[]);
    //
    
    int quickSort(int arr[]);
    //
    
    int mergeSort(int arr[]);
    //
    
private:
    int iNum;
};

//==========================================================
//implement the randNumGen
//==========================================================
int Sort::randNumGen()
{
    //declare predefined array
    int arr[] = {10, 100, 1000, 10000, 100000};
    
    //generate random integer in range of 1 - 5
    srand(time(0));
    int randNum = rand() % 5 + 1;
    
    //loop through the array in the range of 0 to randNum
    for (int i = 0; i < randNum; i++)
    {
        //assign the value of element of the array to iNum
        iNum = arr[i];
    }
    return iNum;
}

//==========================================================
//implement selectionSort
//==========================================================
int Sort::selectionSort(int arr[])
{
    //initialize all elements in the array in the range of 0 to size of iNum
    for (int i = 0; i < iNum; i++)
    {
        //randomize all elements in the array
        srand(time(0));
        arr[i] = rand() % iNum;
    }
    
    
    return 0;
}

//==========================================================
//implement quickSort
//==========================================================
int Sort::quickSort(int arr[])
{
    return 0;
}

//==========================================================
//implement mergeSort
//==========================================================
int Sort::mergeSort(int arr[])
{
    return 0;
}

//==========================================================
//Main
//==========================================================
int main()
{
    //create an object
    Sort Temp;
    cout << Temp.randNumGen() << endl;
    
    
    
    return 0;
}

