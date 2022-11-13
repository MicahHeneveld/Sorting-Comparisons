/*
Sorting Comparisons
Micah Heneveld
5/19/2022
Acknowledgements: "MergeSort.h"  //Got from geekforgeeks.org
couldn't get the book's merge code to work so I grabbed a merge code from geeks
*/


int swapCounter;  //counts the swaps
int compCounter;  //counts the comparisons
const int size1 = 100;  //size of first list of numbers
const int size2 = 1000;  //size of second list of numbers

#include <fstream>  
#include <iostream>
typedef int ItemType;  //define ItemType as a int type

using std::ifstream;  //needed to read files in
using std::ofstream;  //needed to output data to files
using std::endl;
using std::cout;  //allows output to console


#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"  //Got from geekforgeeks.org
#include "QuickSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"

void CopyValues1(int[], int[]);  //copies files from one array with 100 numbers to another array with 100 numbers
void CopyValues2(int[], int[]);  //copies files from one arrray with 1000 numbers to another array with 1000 numbers
void InitValues(ifstream&, int[]);  //Reads the numbers from the file unto a array
void Print1(ofstream&, int[]);  //prints the array to the output file
void Print2(ofstream&, int[]);  //prints the array to the output file


int main()
{
	/*Declare variables*/
	ItemType values1[size1];  //stores the values for the 100 number list
	ItemType values2[size2];  //stores the values for the 1000 number list
	ItemType initValues1[size1];  //store the 100 number list's initial values
	ItemType initValues2[size2];  //stores the 1000 number list's intial values
	ifstream inFile1;  //the 100 number list
	ifstream inFile2;  //the 1000 number list
	ofstream outFile;  //output file



	inFile1.open("100.txt");  //opens the 100 list of numbers
	inFile2.open("1000.txt");  //opens the 1000 list of numbers
	outFile.open("Out.txt");  //opens the ouput file

	InitValues(inFile1, values1);  //gets the intial values from the 100 number list
	InitValues(inFile2, values2);  //gets the inital values from the 1000 number list

	outFile << "Initial values for file 1\n\n" << endl;  //prints out the intial list of numbers from file 1
	Print1(outFile, values1);
	outFile << "\n\nInitial values for file 2\n\n" << endl;  //prints out the  intial lsit of numbers from file 2
	Print2(outFile, values2);

	CopyValues1(values1, initValues1);  //copies the intial numbers from file 1 unto a another array
	CopyValues2(values2, initValues2);  //copies the initial numbers from file 2 unto a another array

	/*
	Sets counters to zero and runs through the list, using Selectionsort to sort the numbers.
	The number of comparisons and swaps are given to the ouput file along with the new ordered list.
	*/
	compCounter =0 , swapCounter =0;
	SelectionSort(values1, size1 - 1);
	outFile << "\n\nResults from SelectionSort1:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized Selection list of 100 below\n\n" << endl;
	Print1(outFile, values1);
	compCounter = 0, swapCounter = 0;
	SelectionSort(values2, size2 - 1);
	outFile << "\n\nResults from SelectionSort2:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nList of 1000 below for SelectionSort\n" << endl;
	Print2(outFile, values2);

	/*
	Resets the lists so that way they are random again
	Displays the unsorted list to the output file
	*/
	CopyValues1(initValues1, values1);
	CopyValues2(initValues2, values2);
	outFile << "Initial values for file 1\n\n" << endl;
	Print1(outFile, values1);
	outFile << "\n\nInitial values for file 2\n\n" << endl;
	Print2(outFile, values2);

	/*
	Sets counters to zero and runs through the list, using BubbleSort to sort the numbers.
	The number of comparisons and swaps are given to the ouput file along with the new ordered list.
	*/
	compCounter = 0, swapCounter = 0;
	BubbleSort(values1, size1);
	outFile << "Results from BubbleSort1:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized BubbleSort1 of 100 below\n" << endl;
	Print1(outFile, values1);
	compCounter = 0, swapCounter = 0;
	BubbleSort(values2, size2);
	outFile << "Results from BubbleSort2:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized BubbleSort2 of 1000 below\n" << endl;
	Print2(outFile, values2);
	

	/*
	Resets the lists so that way they are random again
	Displays the unsorted list to the output file
	*/
	CopyValues1(initValues1, values1);
	CopyValues2(initValues2, values2);
	outFile << "Initial values for file 1\n\n" << endl;
	Print1(outFile, values1);
	outFile << "\n\nInitial values for file 2\n\n" << endl;
	Print2(outFile, values2);

	/*
	Sets counters to zero and runs through the list, using MergeSort to sort the numbers.
	The number of comparisons and swaps are given to the ouput file along with the new ordered list.
	*/
	compCounter = 0, swapCounter = 0;
	mergeSort(values1, 0, 99);
	outFile << "Results from MergeSort1:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized MergeSort1 of 100 below\n" << endl;
	Print1(outFile, values1);
	compCounter = 0, swapCounter = 0;
	mergeSort(values2, 0, 999);
	outFile << "Results from MergeSort2:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized MergeSort2 of 1000 below\n" << endl;
	Print2(outFile, values2);
	


	/*
	Resets the lists so that way they are random again
	Displays the unsorted list to the output file
	*/
	CopyValues1(initValues1, values1);
	CopyValues2(initValues2, values2);
	outFile << "Initial values for file 1\n\n" << endl;
	Print1(outFile, values1);
	outFile << "\n\nInitial values for file 2\n\n" << endl;
	Print2(outFile, values2);

	/*
	Sets counters to zero and runs through the list, using QuickSort to sort the numbers.
	The number of comparisons and swaps are given to the ouput file along with the new ordered list.
	*/
	compCounter = 0, swapCounter = 0;
	QuickSort(values1, 0, 99);
	outFile << "Results from QuickSort1:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized QuickSort1 below" << endl;
	Print1(outFile, values1);
	compCounter = 0, swapCounter = 0;
	QuickSort(values2, 0, 999);
	outFile << "Results from QuickSort2:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized QuickSort2 below" << endl;
	Print2(outFile, values2);
	

	/*
	Resets the lists so that way they are random again
	Displays the unsorted list to the output file
	*/
	CopyValues1(initValues1, values1);
	CopyValues2(initValues2, values2);
	outFile << "Initial values for file 1\n\n" << endl;
	Print1(outFile, values1);
	outFile << "\n\nInitial values for file 2\n\n" << endl;
	Print2(outFile, values2);

	/*
	Sets counters to zero and runs through the list, using InsertionSort to sort the numbers.
	The number of comparisons and swaps are given to the ouput file along with the new ordered list.
	*/
	compCounter = 0, swapCounter = 0;
	InsertionSort(values1, size1);
	outFile << "Results from InsertionSort1:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized Insertion list 1 below" << endl;
	Print1(outFile, values1);
	compCounter = 0, swapCounter = 0;
	InsertionSort(values2, size2);
	outFile << "Results from InsertionSort2:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized Insertion list 2 below" << endl;
	Print2(outFile, values2);

	/*
	Resets the lists so that way they are random again
	Displays the unsorted list to the output file
	*/
	CopyValues1(initValues1, values1);
	CopyValues2(initValues2, values2);
	outFile << "Initial values for file 1\n\n" << endl;
	Print1(outFile, values1);
	outFile << "\n\nInitial values for file 2\n\n" << endl;
	Print2(outFile, values2);

	/*
	Sets counters to zero and runs through the list, using HeapSort to sort the numbers.
	The number of comparisons and swaps are given to the ouput file along with the new ordered list.
	*/
	compCounter = 0, swapCounter = 0;
	HeapSort(values1, size1);
	outFile << "Results HeapSort1:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized Heap list 1 below" << endl;
	Print1(outFile, values1);
	compCounter = 0, swapCounter = 0;
	HeapSort(values2, size2);
	outFile << "Results HeapSort2:  \nThere were " << compCounter << " comparisons and " << swapCounter << " swaps.\n\nOrganized Heap list 2 below" << endl;
	Print2(outFile, values2);

	//Prints that the program ran successfully and values are stored inside Out.txt
	cout << "Sorting complete!  Results are found in the 'Out.txt' file" << endl;
	
	//close input and output files
	inFile1.close(); //closes the 100 list of numbers
	inFile2.close();  //closes the 1000 list of numbers
	outFile.close();  //closes the ouput file

	return 0;
}

/*
Reads the values from the input file and stores them into an array
*/
void InitValues(ifstream& inFile, int values[])
{
	int count = 0;
	while (inFile >> values[count]) {
		count++;
	}
}
/*
Prints the content of an array with the size of 100
*/
void Print1(ofstream& outFile, int values[])
{
	for (int count = 0; count < size1; count = count + 10)
		outFile << values[count] << ", " << values[count + 1] << ", " << values[count + 2] << ", "
		<< values[count + 3] << ", " << values[count + 4] << ", " << values[count + 5] << ", "
		<< values[count + 6] << ", " << values[count + 7] << ", " << values[count + 8]
		<< ", " << values[count + 9] << endl << endl;

}
/*
Prints the content of an array with the size of 1000
*/
void Print2(ofstream& outFile, int values[])
{
	for (int count = 0; count < size2; count = count + 10)
		outFile << values[count] << ", " << values[count + 1] << ", " << values[count + 2] << ", "
		<< values[count + 3] << ", " << values[count + 4] << ", " << values[count + 5] << ", "
		<< values[count + 6] << ", " << values[count + 7] << ", " << values[count + 8]
		<< ", " << values[count + 9] << endl << endl;

}
/*
Copies one array data with the size of 100 into another array with the size of 100
*/
void CopyValues1(int inData[], int outData[])
{
	for (int count = 0; count < size1; count++)
		outData[count] = inData[count];
}
/*
Copies one array data with the size of 1000 into another array with the size of 1000
*/
void CopyValues2(int inData[], int outData[])
{
	for (int count = 0; count < size2; count++)
		outData[count] = inData[count];
}
