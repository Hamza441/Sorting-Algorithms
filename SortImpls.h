
#ifndef Program4Sorting_H
#define Program4Sorting_H

#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int first, int last);
void InsertionSort(vector<int> &arr, int first, int last);
void MergeSort(vector<int> &arr, int first, int last);
void IterativeMergeSort(vector<int> &arr, int first, int last);
void QuickSort(vector<int> &arr, int first, int last);
void ShellSort(vector<int> &arr, int first, int last);
void Merge(vector<int> &itemVector, int first,int mid, int last);


void BubbleSort(vector<int> &arr, int first, int last)
{
    for (int i = first; i < last; i++)
    {
        for (int j = first; j < last - i + first; j++)
        {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
}

void MergeSort(vector<int> &arr, int first, int last)
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(arr, first, mid);
        MergeSort(arr,mid + 1, last);
        Merge(arr,first,mid,last);
    }
}

void InsertionSort(vector<int> &arr, int first, int last)
{
    for(int place = first + 1; place < last + 1; place++)
    {
        int temp = arr[place];
        int i = place;
        while(i > first && (arr[i-1] > temp))
        {
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = temp;
    }
}


void QuickSort(vector<int> &arr, int first, int last)
{
    if(last - first < 10)
    {
        InsertionSort(arr,first,last);
        return;
    }

    int mid = (first + last) / 2;
    if(arr[first] > arr[last])
    {
        swap(arr[first],arr[last]);
    }
    if(arr[first] > arr[mid])
    {
        swap(arr[first],arr[mid]);
    }
    else if(arr[mid] > arr[last])
    {
        swap(arr[mid],arr[last]);
    }
    int pivot = arr[mid];
    swap(arr[mid],arr[last - 1]);
    int left = first + 1;
    int right = last - 2;
    bool done = false;
    while(!done)
    {
        while(arr[left] < pivot)
        {
            left++;
        }
        while(arr[right] > pivot)
        {
            right--;
        }
        if(right > left)
        {
            swap(arr[left],arr[right]);
            right--;
            left++;
        }
        else
        {
            done = true;
        }


    }
    swap(arr[left],arr[last - 1]);
    QuickSort(arr,first,left-1);
    QuickSort(arr,left +1, last);
}

void ShellSort(vector<int> &arr, int first, int last)
{
    for (int space = (last + 1)/2; space > first; space /= 2)
    {
        for (int i = space; i < last + 1; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= space && arr[j - space] > temp; j -= space)
            {
                arr[j] = arr[j - space];
            }
            arr[j] = temp;
        }
    }
}

void Merger(vector<int>& array, int start, int mid, int end) {
	int* tempArr;
	int size = end - start + 1;
	tempArr = new int[size];
	int start1 = start;
	int start2 = mid + 1;
	int end1 = mid;
	int end2 = end;
	int index = 0;

	while ((start1 <= end1) && (start2 <= end2)) {
		if (array[start1] < array[start2]) {
			tempArr[index] = array[start1];
			start1++;
		}
		else {
			tempArr[index] = array[start2];
			start2++;
		}
		index++;
	}
	while (start1 <= end1) {
		tempArr[index] = array[start1];
		start1++;
		index++;
	}
	while (start2 <= end2) {
		tempArr[index] = array[start2];
		start2++;
		index++;
	}
	for (index = 0; index < size; index++) {
		array[start] = tempArr[index];
		start++;
	}
	delete[] tempArr;
}

void MergeSort(vector<int>& array, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);
		Merger(array, start, mid, end);
	}
}


void IterativeMerger(vector<int>& array, int*& array2, int start, int mid, int end){

	int size = end - start + 1;
	int start1 = start;
	int start2 = mid + 1;
	int end1 = mid;
	int end2 = end;
	int index = 0;

	while ((start1 <= end1) && (start2 <= end2)) {
		if (array[start1] < array[start2]) {
			array2[index] = array[start1];
			start1++;
		}
		else {
			array2[index] = array[start2];
			start2++;
		}
		index++;
	}
	while (start1 <= end1) {
		array2[index] = array[start1];
		start1++;
		index++;
	}
	while (start2 <= end2) {
		array2[index] = array[start2];
		start2++;
		index++;
	}
	for (index = 0; index < size; index++) {
		array[start] = array2[index];
		start++;
	}
}

void IterativeMergeSort(vector<int>& array, int start, int end) {
	int currentSize;
	int LS;
	int* tempArray = new int[end + 1];
	for (currentSize = 1; currentSize <= end; currentSize = 2 * currentSize) {
		for (LS = 0; LS < end; LS += 2 * currentSize) {
			int mid = min(LS + currentSize - 1, end);
			int RE = min(LS + 2 * currentSize - 1, end);
			IterativeMerger(array, tempArray, LS, mid, RE);
		}
	}
}


void printArray(const vector<int>& array)
{
	int size = array.size();
	for (int i = 0; i < size; i++) {
		std::cout << array[i];
	}
	std::cout << endl;
}

#endif 
