#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

using vi = vector<int>;
using vvi = vector<vi>;

vvi adj;
vi count;

void dfs(ll node, ll prev) {
    count[node] = 1;
    for (auto u : adj[node]) {
        if (u == prev) continue;
        dfs(u, node);
        count[node] += count[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    adj = vvi(n);
    count = vi(n);

    for (int i=1; i<n; i++) {
        ll v;
        cin >> v;
        v--;
        adj[v].push_back(i);
    }

    dfs(0,0);
    
    for (auto c : count)
        cout << c-1 << " ";
    cout << endl; 
}
