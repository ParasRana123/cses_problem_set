#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;
    long long x , a , b , c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0] = x;
    for(int i = 1 ; i < n ; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    
    // apply sliding window technique
    int l = 0 , r = 0;
    vector<long long> res;
    long long sum = 0;
    while(r < n) {
        sum += arr[r];
        if(r - l + 1 == k) {
            res.push_back(sum);
            sum -= arr[l];
            l++;
        }
        r++;
    }
    long long ans = 0;
    for(int i = 0 ; i < res.size() ; i++) {
        ans = ans ^ res[i];
    }
    cout << ans << endl;
    return 0;
}