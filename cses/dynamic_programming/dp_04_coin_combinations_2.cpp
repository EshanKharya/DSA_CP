#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main () {

    int n;
    int x;

    cin >> n >> x;

    vector<int> denominations (n);
    vector<int> dp (x+1, 0);
    
    for (int i=0; i<n; i++) {
        cin >> denominations[i];
    }    

    dp[0] = 1;
    for (auto& d : denominations) {
        for(int i=1; i<=x; i++) {
            dp[i] = (dp[i] + (i >= d ? dp[i-d] : 0)) % mod;
        }
    }

    cout << dp[x] << endl;

    return 0;
}