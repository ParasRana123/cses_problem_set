#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> desired(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> desired[i];
    }
    vector<int> arr(m);
    for(int i = 0 ; i < m ; i++) {
        cin >> arr[i];
    }
    sort(desired.begin() , desired.end());
    sort(arr.begin() , arr.end());
    int i = 0 , j = 0;
    int cnt = 0;
    while(i < n && j < m) {
        if(abs(desired[i] - arr[j]) <= k) {
            cnt++;
            i++;
            j++;
        } else if(arr[j] < desired[i] - k) {
            j++;
        } else {
            i++;
        }
    }
    cout << cnt << endl;
    return 0;
}