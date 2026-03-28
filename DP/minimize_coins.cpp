#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int f(int sum , vector<int> &dp , vector<int> &c) {
    if(sum == 0) return 0;
    if(sum < 0) return INF;
    if(dp[sum] != -1) return dp[sum];
    int ans = INF;
    for(int i = 0 ; i < c.size() ; i++) {
        int res = f(sum - c[i] , dp , c);
        if(res != INF) {
            ans = min(ans , 1 + res);
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
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}