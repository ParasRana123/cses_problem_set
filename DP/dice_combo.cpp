#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

long long f(int sum , vector<long long> &dp) {
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum];
    // if i get a number 1
    long long ans = 0;
    long long getOne = 0;
    if(sum - 1 >= 0) {
        getOne = f(sum - 1 , dp) % MOD;
    }
    long long getTwo = 0;
    if(sum - 2 >= 0) {
        getTwo = f(sum - 2 , dp) % MOD;
    }
    long long getThree = 0;
    if(sum - 3 >= 0) {
        getThree = f(sum - 3 , dp) % MOD;
    }
    long long getFour = 0;
    if(sum - 4 >= 0) {
        getFour = f(sum - 4 , dp) % MOD;
    }
    long long getFive = 0;
    if(sum - 5 >= 0) {
        getFive = f(sum - 5 , dp) % MOD;
    }
    long long getSix = 0;
    if(sum - 6 >= 0) {
        getSix = f(sum - 6 , dp) % MOD;
    }
    ans = (getOne + getTwo + getThree + getFour + getFive + getSix) % MOD;
    return dp[sum] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1 , -1);
    int res = f(n , dp);
    cout << res << endl;
}