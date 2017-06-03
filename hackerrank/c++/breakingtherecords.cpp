#include <bits/stdc++.h>

using namespace std;


void merge(vector<int> items, vector<int> left, int lengthL, vector<int> right, int lengthR, bool isRev){
    
    int l = 0;
    int r = 0;
    int x = 0;
    

    while(l < lengthL && r < lengthR){
        if(isRev && left[l] > right[r]){
            items[x] = left[l];
            l++;
        } else if(!isRev && left[l] < right[r]){
            items[x] = left[l];
            l++;
        }else {
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

void mergeSort(vector<int> items, int length, bool isRev){
    int middle = length / 2;
    vector<int> left(middle);
    vector<int>right(length-middle);
    int j = 0;
    
    for(int i = 0; i < middle; i++){
        left[i] = items[j];
        j++;
    }
    
    for(int i; i < length-middle; i++){
        right[i] = items[j];
        j++;
    }
    
    if(middle != 0){
        mergeSort(left, middle, isRev);
        mergeSort(right, length-middle, isRev);
        merge(items, left, middle, right, (length-middle), isRev);
    }
   
}


vector < int > getRecord(vector < int > s, int length){
    vector<int> lowest(length);
    vector<int> highest(length);
    vector<int> result(2);
    for(int i = 0; i < length; i++){
        lowest[i] = s[i];
        highest[i] = s[i];
    }
    mergeSort(lowest, length, true);
    mergeSort(highest, length, false);
    int currentValue = 0;
    int inc = 0;
    
    currentValue = highest[0];
    for(int i = 1; i < length; i++){
        if(highest[i] > currentValue){
            currentValue = highest[i];
            inc++;
        }
    }
    
    result[0] = inc;
    inc = 0;
    
    currentValue = lowest[0];
    for(int i = 1; i < length; i++){
        if(lowest[i] < currentValue){
            currentValue = lowest[i];
            inc++;
        }
    }
    
    result[1] = inc;
    return result;
    
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s, n);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
