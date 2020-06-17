// https://codeforces.com/contest/734/problem/A

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
   
    int a = 0;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        if (c == 'A')
            a++;
        if (c == 'D')
            d++;
    }

    if (a < d)
        cout << "Danik";
    else if (a > d)
        cout << "Anton";
    else
        cout << "Friendship";

    return 0;
}
