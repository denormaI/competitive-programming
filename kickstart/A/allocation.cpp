#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

// return maximum number of houses you can buy
int solve(int n, int b)
{
    sort(a, a+n);

    int h = 0;
    for (int i = 0; i < n; i++)
    {
        b -= a[i];
        if (b < 0)
            break;
        h++;
    }

    return h;
}

int main()
{
    int t;
    cin >> t;
   
    for (int i = 0; i < t; i++)
    {
        int n, b;
        cin >> n >> b;
        for (int j = 0; j < n; j++)
            cin >> a[j];
        cout << "Case #" << i+1 << ": " << solve(n,b) << endl;
    }
}
