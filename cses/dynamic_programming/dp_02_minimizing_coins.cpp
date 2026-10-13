#include <bits/stdc++.h>

using namespace std;

int main () {

    int n;
    int x;

    cin >> n >> x;

    vector<int> denominations (n);
    vector<int> dp (x+1, 0);
    
    for (int i=0; i<n; i++) {
        cin >> denominations[i];
    }    

    for (int i=1; i <= x; i++) {
        int minCoins = 1e9;
        for(auto& d: denominations) {
            if(i - d >= 0 && dp[i-d] >= 0) {
                minCoins = min(minCoins, 1 + dp[i-d]);
            }
        }
        dp[i] = minCoins != 1e9 ? minCoins : -1;
        // cout << "x = " << i << ": " << dp[i] << endl;
    }

    cout << dp[x] << endl;

    return 0;
}