// https://codeforces.com/contest/112/problem/A

#include <iostream>
#include <string>
#include <locale>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    
    int ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);
        if (c1 < c2)
        {
            ans = -1;
            break;
        }
        if (c1 > c2)
        {
            ans = 1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
