
/*
 * main.cpp
 *
 *  Created on: 27-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#define SIZE 9

#define SWAP(a,b) { int t = a; a = b; b = t; }

void selection_sort(int arr[]);
void display_array_elements(int arr[]);
void bubble_sort(int arr[]);
void insertion_sort(int arr[]);
void quick_sort(int arr[], int left, int right);
void merge_sort(int arr[], int left, int right);

int main(void)
{
	//int arr[SIZE] = {10,20,30,40,50,60};
	int arr[SIZE] = {50,20,70,10,80,90,30,60,40};
	display_array_elements(arr);
	//quick_sort(arr, 0, SIZE-1);
	merge_sort(arr,0,SIZE-1);
	display_array_elements(arr);

	return 0;
}


void merge(int arr[],int left,int mid,int right)
{
	int i = left;
	int j = mid+1;
	int k = 0;
	int size = (right-left)+1;
	int *temp = new int[size];

	while( i <= mid && j <= right )
	{
		if( arr[i] < arr[j] )
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	//copy remaining ele's from left sub array into temp array
	while( i <= mid )
		temp[k++] = arr[i++];

	//copy remaining ele's from right sub array into temp array
	while( j <= right )
		temp[k++] = arr[j++];

	//copy all ele's from temp array into an original array
	i=left;
	k=0;
	while( i <= right )
		arr[i++] = temp[k++];

	delete []temp;
	temp = NULL;
}

void merge_sort(int arr[], int left, int right)
{
	if( left >= right )
		return;
	static int i = 0;
	int mid = (left+right)/2;
	cout<<"sort to  left :"<<endl;
	i++;
	cout<<i;
	merge_sort(arr,left, mid);
	cout<<endl;
	cout<<"sort to right :"<<endl;
	merge_sort(arr,mid+1, right);
	cout<<endl;
	cout<<"sort the total independant set :"<<endl;
	merge(arr,left,mid,right);
}

void quick_sort(int arr[], int left, int right)
{
	if( left >= right )
		return;

	int i = left;
	int j = right;
	//partitioning
	while ( i < j )
	{
		while( i <= j && arr[i] <= arr[left] )
			i++;

		while( arr[j] > arr[left] )
			j--;

		//if i & j have not crossed
		if( i < j )
			SWAP(arr[i], arr[j]);
	}

	//swap jth pos ele with pivot ele
	SWAP(arr[j], arr[left]);

	//apply quick sort on left partition
	quick_sort(arr, left, j-1);
	//apply quick sort on left partition
	quick_sort(arr, j+1, right);

}

void display_array_elements(int arr[])
{
	cout << "array ele's are: ";
	for( int index = 0 ; index < SIZE ; index++ )
		cout << setw(4) << left << arr[index];
	cout << endl;

}
