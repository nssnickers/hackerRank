//
// Gridland Metro
// Problem: https://www.hackerrank.com/challenges/gridland-metro/problem
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

int main() {
    long n;
    long m;
    long k;
    cin >> n >> m >> k;
    
    map <int, vector<pair<int, int>>> grid;
    
    for (int i = 0; i < k; i++) {
        long r;
        long c1;
        long c2;
        
        cin >> r >> c1 >> c2;
        
        grid[r].push_back(make_pair(c1, c2));
    }
    
    
    
    long long result = m * n;
    
    
    
    for (auto &it : grid) {
        
        sort(it.second.begin(), it.second.end());
        
        auto it1 = it.second.begin();
        
        int c1 = it1->first;
        int c2 = it1->second;
        
        it1++;
        
        for (; it1 != it.second.end(); it1++) {
            if (it1->first <= c2) {
                c2 = max(c2, it1->second);
            }
            else {
                result -= (c2 - c1 + 1);
                c1 = it1->first;
                c2 = it1->second;
            }
        }
        
        result -= (c2 - c1 + 1);
    }
    
    
    
    cout << result << endl;
    return 0;
}


