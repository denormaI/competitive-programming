#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
        for (char c : to_string(i))
            dp[i] = min(dp[i], dp[i-(c-'0')]+1);

    cout << dp[n] << endl;
}
