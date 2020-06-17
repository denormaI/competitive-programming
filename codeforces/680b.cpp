// https://codeforces.com/contest/680/problem/B

#include <iostream>

using namespace std;

int a[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, city;
    cin >> n >> city;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    if (a[city])
        ans++;

    for (int dist = 1; dist < n; dist++)
    {
        int left = city - dist;
        int right = city + dist;

        if (left < 1 && right > n)
            break;
        else if (left < 1 && right <= n)
        {
            if (a[right])
                ans++;
        }
        else if (left >= 1 && right > n)
        {
            if (a[left])
                ans++;
        }
        else
        {
            if (a[left] && a[right])
                ans += 2;
        }
    }

    cout << ans << endl;

    return 0;
}
