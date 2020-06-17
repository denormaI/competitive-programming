// https://codeforces.com/contest/236/problem/A

#include <iostream>
#include <string>
#include <locale>

using namespace std;

string tolower_s(string s)
{
    for (auto& c : s)
        c = tolower(c);
    return s;
}

string toupper_s(string s)
{
    for (auto& c : s)
        c = toupper(c);
    return s;
}

string case_fix(string str)
{
    int n_upper = 0;
    int n_lower = 0;
    for (auto& c : str)
    {
        if (c >= 'a' && c <= 'z')
            n_lower++;
        if (c >= 'A' && c <= 'Z')
            n_upper++;
    }
    if (n_upper <= n_lower)
        return tolower_s(str);
    else
        return toupper_s(str);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    cout << case_fix(str) << endl;

    return 0;
}
