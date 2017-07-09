#include <bits/stdc++.h>
#include <string.h>

using namespace std;

string largestOfTwo(string right, string left){
    for(int i = 0; i < right.length(); i++){
        if((int)right[i] < (int)left[i]){
            return right;
        } else if((int)left[i] < (int)right[i]) {
            return left;
        }
    }
    
    return right;
}

void sort(string org[], string left[], int lSize, string right[], int rSize){
    int l = 0;
    int r = 0;
    int x = 0;
    
    while(l < lSize && r < rSize){
        if(left[l].length() < right[r].length()){
            org[x] = left[l];
            l++;
        } else if(right[r].length() < left[l].length()){
            org[x] = right[r];
            r++;
        } else {
            org[x] = largestOfTwo(right[r], left[l]);
            if(org[x] == right[r]){
              r++;  
            } else {
              l++;                
            }

        }
        x++;
    }
    
    while(l < lSize){
        org[x] = left[l];
        x++;
        l++;
    }
    
    while(r < rSize){
        org[x] = right[r];
        x++;
        r++;
    }
}

void merge(string arr[], int size){
    
    int middle = size/2;
    string left[middle];
    string right[size-middle];
    int x = 0;
    
    for(int i = 0; i < middle; i++){
        left[i] = arr[x];
        x++;
    }
    
    for(int j = 0; j < size-middle; j++){
        right[j] = arr[x];
        x++;
    }
    
    if(middle != 0){
            merge(left, middle);
            merge(right, size-middle);
            sort(arr, left, middle, right, size-middle);
    }
}

void printArr(string arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int n;
    string handler;
    cin >> n;
    string unsorted[n];
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];

    }
    
    merge(unsorted, n);
     printArr(unsorted, n);
    // your code goes here
    return 0;
}
