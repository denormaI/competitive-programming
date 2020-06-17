// https://codeforces.com/contest/236/problem/A

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    bool dcm[256];
    memset(dcm, false, sizeof(bool)*256);

    for (auto& c : str)
         dcm[c] = true;

    int dc = 0;
    for (auto& b : dcm)
        if (b)
            dc++;

    if (dc % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;

    return 0;
}
