#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int f(int sum , vector<int> &dp) {
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum];
    // if i get a number 1
    int ans = 0;
    int getOne = 0;
    if(sum - 1 >= 0) {
        getOne = f(sum - 1 , dp) % MOD;
    }
    int getTwo = 0;
    if(sum - 2 >= 0) {
        getTwo = f(sum - 2 , dp) % MOD;
    }
    int getThree = 0;
    if(sum - 3 >= 0) {
        getThree = f(sum - 3 , dp) % MOD;
    }
    int getFour = 0;
    if(sum - 4 >= 0) {
        getFour = f(sum - 4 , dp) % MOD;
    }
    int getFive = 0;
    if(sum - 5 >= 0) {
        getFive = f(sum - 5 , dp) % MOD;
    }
    int getSix = 0;
    if(sum - 6 >= 0) {
        getSix = f(sum - 6 , dp) % MOD;
    }
    ans = (getOne + getTwo + getThree + getFour + getFive + getSix) % MOD;
    return dp[sum] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1 , -1);
    int res = f(n , dp);
    cout << res << endl;
}