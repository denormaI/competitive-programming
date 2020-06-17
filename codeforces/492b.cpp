// https://codeforces.com/contest/492/problem/B

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int a[1002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    a[n] = 0;
    a[n+1] = l;
    sort(a, a+n+2);

    double max_d = max(a[1]-a[0], a[n+1]-a[n]);;

    for (int i = 1; i < n+2; i++)
        max_d = max(max_d, (a[i] - a[i-1]) / 2.0);

    std::cout << setprecision(10) << max_d << endl;
}

