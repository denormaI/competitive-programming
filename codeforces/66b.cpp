// https://codeforces.com/contest/66/problem/B

#include <iostream>
#include <string>

using namespace std;

int a[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for (int sect = 0 ; sect < n; sect++)
    {
        int found = 1;

        // search back
        for (int i = sect-1; i >= 0 && a[i] <= a[i+1]; i--)
            found++;

        // search forward
        for (int i = sect+1; i < n && a[i] <= a[i-1]; i++)
            found++;

        ans = max(ans, found);    
    }

    cout << ans << endl;

    return 0;
}
