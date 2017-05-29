#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int in;
    map<int, int> hash;
    cin >> n;
    int result;
    int values[n];
    
    for(int i = 1; i <= n; i++){
        cin >> in;
        values[i-1] = in;
        hash[in] = i;
    }
    
    for(int i = 1; i <=n; i++){
        if(hash.find(i) != hash.end()){
            result = hash[i];
            if(hash.find(result) != hash.end()){
                result = hash[result];
                    cout << result << endl;                    
                

            }
        }
    }
    return 0;
}
