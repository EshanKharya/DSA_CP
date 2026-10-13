#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int findDiceCombinations(int n, vector<int>& dp) {
    // Base Condition
    if (n <= 0)
        return n == 0;
    
    // Memoization
    if (dp[n] > 0)
        return dp[n];
    
    // Recurse on possibilities
    int poss = 0;
    for (int i=1; i<=6; i++) {
        poss = (poss % mod + findDiceCombinations(n-i, dp) % mod) % mod;
    }

    // Return and set dp array
    return dp[n] = poss;
}

int main() {

    int n;
    cin >> n;
    vector<int> dp (n+1, -1);
    int ans = n <= 0 ? 0 : findDiceCombinations(n, dp);

    cout << ans << endl;

    return 0;
}