#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main() {

    int n;
    cin >> n;
    vector<vector<char>> grid (n, vector<char>(n, '.'));
    vector<vector<int>> dp (n, vector<int> (n, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    if(grid[0][0] == '*' || grid[n-1][n-1] == '*') {
        cout << 0 << endl;
        return 0;
    }
    
    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if(i > 0 && grid[i-1][j] != '*')
                dp[i][j] =(dp[i][j] + dp[i-1][j]) % mod;
            if(j > 0 && grid[i][j-1] != '*')
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n-1][n-1] << endl;

    return 0;
}