// https://codeforces.com/problemset/problem/158/A

#include <iostream>
#include <string>

using namespace std;

int n, k;
int a[51];

int solve()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= a[k] && a[i] > 0)
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << solve() << endl;

    return 0;
}
