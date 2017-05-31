#include <bits/stdc++.h>

using namespace std;


void merge(int items[], int left[], int lengthL, int right[], int lengthR, bool isRev){
    
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

void mergeSort(int items[], int length, bool isRev){
    int middle = length / 2;
    int left[middle];
    int right[length-middle];
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

void printArry(int items[], int length){
    for(int i = 0 ; i < length; i++){
        cout << items[i] << " ";
    }
}

int getMoneySpent(int keyboards[], int drives[], int s, int keyboardLength, int drivesLength){
    // Complete this function
    int max = -1;
    
    mergeSort(keyboards, keyboardLength, true);
    mergeSort(drives, drivesLength, false);
    
    //printArry(drives, drivesLength);
    
    for(int k = 0; k < keyboardLength; k++){
        for(int d = 0; d < drivesLength; d++){
            if(drives[d] + keyboards[k] > s){
                break;
            } else if(max < drives[d] + keyboards[k]) {
                max = drives[d] + keyboards[k];
            }
        }
    }
    return max;
}

int main() {
    int s;
    int n;
    int m;
    cin >> s >> n >> m;
    int keyboards[n];
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
       cin >> keyboards[keyboards_i];
    }
    int drives[m];
    for(int drives_i = 0; drives_i < m; drives_i++){
       cin >> drives[drives_i];
    }
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s, n, m);
    cout << moneySpent << endl;
    return 0;
}
