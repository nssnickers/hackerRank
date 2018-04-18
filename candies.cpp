//
// Candies
// Problem: https://www.hackerrank.com/challenges/candies/problem
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

long long candies(int n, vector <int> arr) {
    long long sum;
    vector <int> dp(n, 1);
    
    for(int i = 1 ; i < n  ;i++){
        if (arr[i] > arr[i-1]){
            dp[i] = dp[i] + dp[i-1];
        }
    }
    
    sum = dp[n-1];
    for(int i = n-2 ; i >= 0 ; i--){
        if (arr[i] > arr[i+1] && dp[i] <= dp[i+1]){
            dp[i] = dp[i+1] + 1;
        }
        sum += dp[i];
    }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }
    long long result = candies(n, arr);
    cout << result << endl;
    return 0;
}
