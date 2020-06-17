#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll min_dif = 0x7ffffffffffffffLL;

ll n;
vector<ll> a;
vector<ll> sub;

void solve(int i) {
    if (i == n) {
        if (sub.size() == 0) return;

        ll si = 0, sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) {
            if (si < sub.size() && sub[si] == j) {
                sum1 += a[j];
                si++;
            } else {
                sum2 += a[j];
            }
        }
    
        min_dif = min(min_dif, abs(sum1-sum2));
        return;
    }
    solve(i + 1);
    sub.push_back(i);
    solve(i + 1);
    sub.pop_back();
}

ll sum_vec(vector<ll>& v) {
    int sum = 0;
    for (auto& e : v)
        sum += e;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++) {
        ll t;
        cin >> t;
        a.push_back(t);
    }

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    solve(0);
    
    cout << min_dif << endl;
}

