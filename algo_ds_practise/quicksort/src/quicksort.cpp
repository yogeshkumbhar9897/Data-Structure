//============================================================================
// Name        : quicksort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iomanip>
#define SIZE 8
#define SWAP(a,b) { int t = a; a = b; b = t; }

void display_array_elements(int arr[]);
void merge_sort(int arr[], int left, int right);

int main(void)
{
	int arr[SIZE] = {80,70,60,50,40,30,20,10};
	display_array_elements(arr);
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

	int mid = (left+right)/2;
	cout<<"\nIn Left	:	";
	display_array_elements(arr);
	merge_sort(arr,left, mid);
	cout<<"\nIn Right	:	";
	display_array_elements(arr);
	merge_sort(arr,mid+1, right);
	cout<<"\nTotal	:	";
	display_array_elements(arr);
	merge(arr,left,mid,right);

}
void display_array_elements(int arr[])
{
for(int i=0;i<SIZE;i++)

	cout<<setw(10)<<left<<arr[i];

cout<<endl;
}

