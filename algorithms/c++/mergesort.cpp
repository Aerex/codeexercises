#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
void merge(int items[], int left[], int lengthL, int right[], int lengthR){
    
    int l = 0;
    int r = 0;
    
    int x = 0;
    
    while(l < lengthL && r < lengthR){
        if(left[l] <= right[r]){
            items[x] = left[l];
            l++;
        } else {
            items[x] = right[r];
            r++;
        }
        x++;
    }
    
    while(l < lengthL){
        items[x] = left[l];
        l++;
        x++;
    }
    
    while(r < lengthR){
        items[x] = right[r];
        r++;
        x++;
    }    
    
}

void mergeSort(int items[], int length){
    int middle = length / 2;
    int leftLength = middle;
    int left[leftLength];
    int rightLength = length - middle;
    int right[rightLength];
    int j = 0;
    
    for(int i = 0; i < leftLength; i++){
        left[i] = items[j];
        j++;
    }
    
    for(int i = 0; i < rightLength; i++){
        right[i] = items[j];
        j++;
    }

    if(leftLength != 0){
        mergeSort(left, leftLength);     
        mergeSort(right, rightLength);
        merge(items, left, leftLength, right, rightLength); 
    }
    
}

void printArray(int items[], int size){
    for(int i = 0; i < size; i++){
        cout << items[i] << " " ;
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {12, 11, 13, 5, 6, 99,1, 100};

   mergeSort(array, 8);

    printArray(array, 8);

    return 0;
}