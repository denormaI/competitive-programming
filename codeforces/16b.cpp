// https://codeforces.com/contest/16/problem/B

#include <iostream>

using namespace std;

int a[21], b[21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
   
    int ans = 0;
    while (n > 0)
    {
        // Search for a container with the largest matchboxes available.
        int max_idx = -1;
        int max_matches = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] > 0 && b[i] > max_matches)
            {
                max_matches = b[i];
                max_idx = i;
            }
        }

        if (max_idx == -1)
            break;

        while (a[max_idx] && n > 0)
        {
            ans += b[max_idx];
            a[max_idx]--;
            n--;
        }
    }

    cout << ans << endl;
}
