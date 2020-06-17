// https://codeforces.com/contest/677/problem/A

#include <iostream>
#include <string>

using namespace std;

int n, h;
int a[1001];

int solve()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > h)
            ans += 2;
        else
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];    

    cout << solve() << endl;

    return 0;
}
