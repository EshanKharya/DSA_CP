#include <bits/stdc++.h>

using namespace std;

#define EVENCOST 3
#define ODDCOST 1

int cost(int digit) {
    return digit%2 ? ODDCOST : EVENCOST;
}

int main() {

    int n;
    cin >> n;

    vector<int> dp (n+1, 1e9);
    vector<int> path(n+1, 1e9);
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        int temp = i;
        while(temp > 0) {
            int digit = temp%10;
            int c = cost(digit) + dp[i-digit];
            if(c < dp[i]) {
                dp[i] = c;
                path[i] = i-digit;
            }
            temp/=10;
        }
    }

    int currvalue = n;
    cout << "Path: " << currvalue;
    while(currvalue != 0) {
        cout << " -> " << path[currvalue];
        currvalue = path[currvalue];
    }
    cout << "Total cost: " << dp[n] << endl;
    return 0;
}