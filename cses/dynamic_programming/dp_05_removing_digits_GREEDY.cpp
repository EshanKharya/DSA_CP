#include <bits/stdc++.h>

using namespace std;

int getLargestDigit(int n) {
    int largest = -1;
    while(n > 0) {
        largest = max(largest, n%10);
        n /= 10;
    }
    return largest;
}

int main () {

    int n;
    cin >> n;

    int steps = 0;
    while (n > 0) {
        n -= getLargestDigit(n);
        steps ++;
    }

    cout << steps << endl;

    return 0;
}