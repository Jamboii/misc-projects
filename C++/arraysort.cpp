#include <iostream>
#include <array>
using namespace std;

void merge(int arr1[], int arr2[], int arrMerged[]);
void sort(int arrMerged[]);
void printList(int arr[]);

int const SMALL_LIST_SIZE = 10;
int const LARGE_LIST_SIZE = 20;

int main(){

// Here are the two lists of numbers
int list1       [SMALL_LIST_SIZE] = {5,2,8,4,6,2,90,12,1,50};
int list2       [SMALL_LIST_SIZE] = {85,34,1,6,23,7,8,12,4,0};

// This is where the final merged and sorted list should be stored
int sorted_list [LARGE_LIST_SIZE];

// Note: Declare and use any other variable or array you may need.
    merge(list1,list2,sorted_list);
    cout << "Merged List: ";
    printList(sorted_list);
    sort(sorted_list);
    cout << "Sorted List: ";
    printList(sorted_list);
} // end of main()

void merge(int arr1[], int arr2[], int arrMerged[]) { //Merge the two arrays depending on position of larger array
    for (int i=0;i<LARGE_LIST_SIZE;i++) {
        if (i<10)
            arrMerged[i] = arr1[i];
        else
            arrMerged[i] = arr2[i-10];
    }
}

void sort(int arrSorted[]) { //Sort Array using bubble sort
    for (int i=0;i<LARGE_LIST_SIZE;i++) {
        for (int j=0;j<LARGE_LIST_SIZE-1;j++) {
            if (arrSorted[j] > arrSorted[j+1])
                swap(arrSorted[j],arrSorted[j+1]);
        }
    }
}

void swap (int x, int y) { //swap holder
    int holder = x;
    x = y;
    y = holder;
}

void printList(int arr[]) { //print both the merged and sorted lists
    for (int i=0;i<LARGE_LIST_SIZE;i++)
        cout << arr[i] << " ";
    cout << endl;
}
