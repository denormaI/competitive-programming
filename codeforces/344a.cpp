// https://codeforces.com/contest/344/problem/A

#include <iostream>
#include <string>

using namespace std;

int a[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int groups = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i-1])
            groups++;
    }

    cout << groups << endl;

    return 0;
}
