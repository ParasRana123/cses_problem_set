#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int f(int sum , vector<int> &dp , vector<int> &c) {
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum];
    long long ans = 0;
    for(int i = 0 ; i < c.size() ; i++) {
        if(sum - c[i] >= 0) {
            ans = (ans + f(sum - c[i] , dp , c)) % MOD;
        }
    }
    return dp[sum] = ans;
}

int main() {
    int n , x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> c[i];
    }
    vector<int> dp(x + 1 , -1);
    int res = f(x , dp , c);
    cout << res << endl;
    return 0;
}
