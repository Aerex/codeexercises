#include <bits/stdc++.h>

using namespace std;

struct node {
    int leftPage;
    int rightPage;
    node *prev;
    node *next;
};

node *root = NULL;
node *tail = NULL;

void add(node *current, int left, int right){
    node* newNode = new node;
    newNode->leftPage = left;
    newNode->rightPage = right;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = newNode;
    tail = current->next;
    current->next->prev = current;
}

int search(node *current, bool rev, int value){
    int count = 0;
    if(!rev){
        while(current->next != NULL){
            if(current->leftPage == value|| current->rightPage == value){
                return count;
            }
            current = current->next;
            count++;
        }
    } else {
        while(current->prev != NULL){
            if(current->leftPage == value || current->rightPage == value){
                return count;
            }
            current = current->prev;
            count++;
        }
    }
    
    return count;
}

int solve(int n, int p){
    // Complete this function
    
    root = new node;
    root->leftPage = 0;
    root->rightPage = 1;
    root->next = NULL;
    root->prev = NULL;
    
    tail = root;
    
    for(int i = 2; i <= n; i+=2){
        add(root, i, i+1);
    }   
    
    int halfway = n/2;
    
    if(p > halfway){
        return search(tail, true, p);    
    } else {
        return search(root, false, p);
    }
    //add(root, n, null);
    
//    int fromStart = search(root, false, p);
  //  int fromEnd = search(tail, true, p);
    
    //return fromStart < fromEnd ? fromStart : fromEnd;
    
    
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}
