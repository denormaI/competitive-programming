#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll n,x;
ll dp[1000001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    vector<ll> coins;
    for (int i=0; i<n; i++) {
        ll c;
        cin >> c;
        coins.push_back(c);
    }

    sort(coins.begin(),coins.end());

    dp[0] = 1;
    for (int i=1; i<=x; i++) {
        for (auto c : coins) {
            if (i-c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= (ll)1e9+7;
            }
        }
    }

    cout << dp[x] << endl;
}

