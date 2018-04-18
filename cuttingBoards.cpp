//
// Cutting Boards
// Problem: https://www.hackerrank.com/challenges/board-cutting/problem
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

long long boardCutting(vector <long long> y, vector <long long> x) {
    int m = y.size();
    int n = x.size();
    
    int i = 0;
    int j = 0;
    
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    
    int seg_m = 1, seg_n = 1;
    long long res = 0;
    while (i < n && j < m) {
        if (x[i] >= y[j]) {
            
            res += x[i] * seg_n;
            seg_m ++;
            i++;
        } else {
            
            res += y[j] * seg_m;
            seg_n ++;
            j++;
        }
    }
    
    while (i < n) {
        res += x[i] * seg_n;
        seg_m ++;
        i++;
    }
    
    while (j < m) {
        res += y[j] * seg_m;
        seg_n ++;
        j++;
    }
    
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int m;
        int n;
        cin >> m >> n;
        
        vector<long long> cost_y(m-1);
        for(int cost_y_i = 0; cost_y_i < m-1; cost_y_i++){
            cin >> cost_y[cost_y_i];
        }
        
        vector<long long> cost_x(n-1);
        for(int cost_x_i = 0; cost_x_i < n-1; cost_x_i++){
            cin >> cost_x[cost_x_i];
        }
        
        long long result = boardCutting(cost_y, cost_x);
        cout << result%1000000007 << endl;
    }
    return 0;
}
