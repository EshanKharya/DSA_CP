#include <bits/stdc++.h>

using namespace std;

vector<bool> findUniqueDigits(int n) {
    vector<bool> digits(10, 0);
    while(n > 0) {
        digits[n%10] = 1;
        n /= 10;
    }
    return digits;
}

int main () {

    int n;
    cin >> n;

    vector<int> dp (n+1, 1e7);
    dp[0] = 0;

    for(int i = 1; i<=n; i++) {
        vector<bool> digits = findUniqueDigits(i);
        for(int j = 0; j< 10; j++) {
            if(digits[j]) dp[i] = min(dp[i], 1 + dp[i-j]);
        } 
    }

    cout << dp[n] << endl;

    return 0;
}