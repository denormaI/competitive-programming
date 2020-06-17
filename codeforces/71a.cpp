// https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>

using namespace std;

string abbrev(string word)
{
    if (word.length() > 10)
        return word[0] + to_string(word.length() - 2) + word.back();
    return word;
}

int main()
{
    int wc;
    cin >> wc;

    while (wc-- > 0)
    {
        string word;
        cin >> word;
        cout << abbrev(word) << endl;
    }

    return 0;
}
