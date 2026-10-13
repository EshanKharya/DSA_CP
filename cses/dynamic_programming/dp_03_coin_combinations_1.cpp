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

    if(x == 0)
        cout << 0 << endl;

    dp[0] = 1;
    for (int i=1; i <= x; i++) {
        int poss = 0;
        for(auto& d: denominations) {
            poss += d <= i ? dp[i-d] : 0;
        }
        dp[i] = poss;
    }

    cout << dp[x] << endl;

    return 0;
}