// https://codeforces.com/contest/405/problem/A

#include <iostream>
#include <string>

using namespace std;

int a[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    if (n > 1)
    {
        // step n times
        for (int step = 0; step < n; step++)
        {
            bool has_swapped = false;

            // start at last column - 1, end at first
            for (int i = n-1; i > 0; i--)
            {
                // add boxes to the next column if they would fall
                if (a[i] > a[i+1])
                {
                    has_swapped = true;
                    int taken = a[i] - a[i+1];
                    a[i] -= taken;
                    a[i+1] += taken;
                }
            }

            // if all boxes are in place just break out
            if (!has_swapped)
                break;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
