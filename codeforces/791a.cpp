// https://codeforces.com/contest/791/problem/A

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    
    int y = 0;

    while (a <= b)
    {
        a *= 3;
        b *= 2;
        y++;
    }

    cout << y << endl;

    return 0;
}
