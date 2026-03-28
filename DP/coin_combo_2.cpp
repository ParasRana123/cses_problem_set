#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

long long f(int ind , int sum , vector<vector<long long>> &dp , vector<int> &c) {
    if(sum == 0) return 1;
    if(ind == c.size()) return 0;
    if(dp[ind][sum] != -1) return dp[ind][sum];
    long long take = 0;
    if(sum - c[ind] >= 0) {
        take = f(ind , sum - c[ind] , dp , c);
    }
    long long notTake = f(ind + 1 , sum , dp , c);
    return dp[ind][sum] = take + notTake;
}

int main() {
    int n , x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> c[i];
    }
    vector<vector<long long>> dp(n + 1 , vector<long long>(x + 1 , -1));
    int res = f(0 , x , dp , c);
    cout << res << endl;
    return 0;
}
