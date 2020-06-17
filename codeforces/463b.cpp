// https://codeforces.com/contest/463/problem/B

#include <iostream>
#include <cmath>

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

    int energy = 0;
    int dollars = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        int cost = a[i] - a[i+1];

        if (energy + cost < 0)
        {
            dollars += abs(cost) - energy;
            energy = 0;
        }
        else
        {
            energy += cost;
        }
    }

    cout << dollars << endl;
}
