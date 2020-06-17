// https://codeforces.com/contest/231/problem/A

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    while (n-- > 0)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            int a;
            cin >> a;
            sum += a;
        }
        if (sum >= 2)
            ans++;
    }

    cout << ans;

    return 0;
}
