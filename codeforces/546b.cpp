// https://codeforces.com/contest/546/problem/C

#include <iostream>
#include <deque>
#include <utility>

using namespace std;

deque<int> read_cards()
{
    int k;
    cin >> k;

    deque<int> cards;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        cards.push_back(t);
    }

    return cards;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> k1 = read_cards();
    deque<int> k2 = read_cards();

    int fights = 0;
    int winner;

    while (1)
    {
        int c1 = k1.front(); k1.pop_front();
        int c2 = k2.front(); k2.pop_front();

        if (c1 > c2) // player 1 win
        {
            k1.push_back(c2);
            k1.push_back(c1);
        }
        else if (c2 > c1) // player 2 win
        {
            k2.push_back(c1);
            k2.push_back(c2);
        }

        fights++;
        if (k1.empty())
        {
            cout << fights << " " << 2 << endl;
            break;
        }
        if (k2.empty())
        {
            cout << fights << " " << 1 << endl;
            break;
        }
        if (fights >= n * 100)
        {
            cout << -1 << endl;
            break;
        }
    }
}

