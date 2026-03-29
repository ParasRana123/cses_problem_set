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
    priority_queue<long long , vector<long long> , greater<long long>> pq;
    unordered_map<long long , int> mpp;
    // long long mini = LLONG_MAX;
    while(r < n) {
        pq.push(arr[r]);
        if(r - l + 1 == k) {
            while(!pq.empty() && mpp[pq.top()] > 0) {
                mpp[pq.top()]--;
                pq.pop();
            }
            res.push_back(pq.top());
            mpp[arr[l]]++;
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