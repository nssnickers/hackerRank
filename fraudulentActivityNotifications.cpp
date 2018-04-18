//
// Fraudulent Activity Notifications
// Problem: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
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


using namespace std;

vector <int> countingSort(vector <int> arr, int start, int end) {
    vector <int> output(201, 0);
    for (int i = start; i < end; i++) {
        output[arr[i]] += 1;
    }
    
    vector <int> result;
    for (int i = 0; i <= 200; i++) {
        if (output[i] > 0) {
            int j = output[i];
            while (j>0) {
                result.push_back(i);
                j--;
            }
            
        }
    }
    
    return result;
}

float getMediana(vector <int> arr, int d) {
    float mediana = 0.0;
    if (d % 2) {
        mediana = (float)arr[(d + 1)/2 - 1];
    } else {
        mediana = ((float)arr[d/2 - 1] + (float)arr[d/2]) / 2.0 ;
    }
    
    return mediana;
}

void insertA( vector <int> &cont, int value ) {
    cont.insert(lower_bound(cont.begin(), cont.end(), value), value);
}

int activityNotifications(vector <int> expenditure, int d) {
    vector<int> result = countingSort(expenditure, 0, d);
    
    int notify = 0;
    int i = d;
    int expSize = expenditure.size();
    
    while (i < expSize) {
        float mediana = 0.0;
        if (d % 2) {
            mediana = (float)result[(d + 1)/2 - 1];
        } else {
            mediana = ((float)result[d/2 - 1] + (float)result[d/2]) / 2.0 ;
        }
        
        if ((float)expenditure[i] >= mediana * 2.0 ) {
            notify += 1;
        }
        
        if (i < expSize - 1) {
            result.erase(equal_range(result.begin(), result.end(), expenditure[i-d]).first);
            insertA(result, expenditure[i]);
        }
        
        i++;
    }
    
    return notify;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
        cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}
