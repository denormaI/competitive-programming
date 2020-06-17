// https://codeforces.com/contest/263/problem/A

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i1, j1;

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int n;
            cin >> n;
            if (n == 1)
            {
                i1 = i;
                j1 = j;
            }
        }
    }

    int id = abs(i1 - 3);
    int jd = abs(j1 - 3);

    cout << id + jd;

    return 0;
}
