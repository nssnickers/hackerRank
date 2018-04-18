//
// Abbreviation
// Problem: https://www.hackerrank.com/challenges/abbr/problem
//
// Copyright © 2018 Маргарита. All rights reserved.
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

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<char> alphabet(alpha, alpha+sizeof(alpha)-1);

map <pair <int, int>, int> dp;

bool abbreviation(string a, string b) {
    int a_size = a.size();
    int b_size = b.size();
    
    if (a_size < b_size) {
        return false;
    }
    
    if (b_size == 0) {
        for (int i = 0; i < a_size; i++ ) {
            if (find(alphabet.begin(), alphabet.end(), a[i]) != alphabet.end()) {
                return false;
            }
        }
        
        return true;
    }
    
    if (dp.count(make_pair(a_size, b_size)) == 1 ) {
        return dp[make_pair(a_size, b_size)];
    }
    
    char a_last = a[a_size-1];
    char b_last = b[b_size-1];
    
    if (a_last == b_last) {
        dp[make_pair(a_size, b_size)] = abbreviation(a.substr(0, a_size-1), b.substr(0, b_size-1));
        
        return  dp[make_pair(a_size, b_size)];
        
    } else if (toupper(a_last) == b_last) {
        dp[make_pair(a_size, b_size)] = abbreviation(a.substr(0, a_size-1), b.substr(0, b_size-1)) ||  abbreviation(a.substr(0, a_size-1), b);
        
        return  dp[make_pair(a_size, b_size)];
    } else {
        if (a_last == toupper(a_last)) {
            return false;
        } else {
            dp[make_pair(a_size, b_size)] = abbreviation(a.substr(0, a_size-1), b);
            
            return dp[make_pair(a_size, b_size)];
        }
    }
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        map <pair<int, int>, int> tmp;
        dp = tmp;
        bool result = abbreviation(a, b);
        cout << (result == true ? "YES" : "NO") << endl;
    }
    return 0;
}
