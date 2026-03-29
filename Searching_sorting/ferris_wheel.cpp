#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    sort(arr.begin() , arr.end());
    int cnt = 0;
    int sum = 0;
    int l = 0 , r = n - 1;
    while(l <= r) {
        if(arr[l] + arr[r] <= x) {
            l++;
        }
        r--;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}