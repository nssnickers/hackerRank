//
// Balanced Brackets
// Problem: https://www.hackerrank.com/challenges/balanced-brackets/problem
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

bool is_balanced(string expression) {
    stack<char> bracketStack;
    
    for (int i = 0; i < expression.length(); i++) {
        switch (expression[i]) {
            case '{':
                bracketStack.push('}');
                break;
            case '[':
                bracketStack.push(']');
                break;
            case '(':
                bracketStack.push(')');
                break;
            default:
                if (bracketStack.empty() || expression[i] != bracketStack.top()) {
                    return false;
                } else {
                    bracketStack.pop();
                }
                break;
        }
    }
    
    return bracketStack.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
