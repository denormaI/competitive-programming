#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int max_len = 1, len = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i-1])
        {
            len++;
            max_len = max(max_len, len);
        }
        else
            len = 1;
    }

    cout << max_len << endl;
}

