//
// Equal
// Problem: https://www.hackerrank.com/challenges/equal/problem
//

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

int numToNull(int n) {
    int res = 0;
    
    if (n >= 5) {
        res += n/5;
        
        n %= 5;
    }
    
    if (n >= 2) {
        res += n/2;
        n %= 2;
    }
    
    if (n >= 1) {
        res += n;
    }
    
    return res;
}

int equal(vector <int> arr) {
    sort(arr.begin(), arr.end());
    
    int size = arr.size();
    int sum = numeric_limits<int>::max();
    
    for (int j = 0; j < 3; j++) {
        int res = 0;
        for (int i = 0; i < size; i ++) {
            res += numToNull(arr[i] - arr[0] + j);
        }
        sum = min(sum, res);
    }
    
    
    return sum;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            cin >> arr[arr_i];
        }
        int result = equal(arr);
        cout << result << endl;
    }
    return 0;
}
