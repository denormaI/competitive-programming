#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


/*
Thanks user491874
https://math.stackexchange.com/a/2596072
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if (n % 4 != 0 && n % 4 != 3)
        cout << "NO" << endl;
    else
    {
        vector<ll> a;
        a.reserve(a);
        for (int i = 1; i <= n; i++)
            a.push_back(i);
    
        vector<ll> set1, set2;
        set1.reserve(n);
        set2.reserve(n);

        // could be faster by storing indices instead of elements
        while (n > 0)
        {
            if (n < 4) // n mod 4 = 3
            {
                // set1: 1 2
                // set2: 3
                set2.push_back(a.back()); a.pop_back();
                set1.push_back(a.back()); a.pop_back();
                set1.push_back(a.back()); a.pop_back();
            }
            else // n mod 4 = 0
            {
                // set1: 2 3
                // set2: 1 4
                set2.push_back(a.back()); a.pop_back();
                set1.push_back(a.back()); a.pop_back();
                set1.push_back(a.back()); a.pop_back();
                set2.push_back(a.back()); a.pop_back();  
            }

            n -= 4;
        }

        cout << "YES\n" << set1.size() << endl;
        for (auto& e : set1)
            cout << e << " ";
        cout << endl;

        cout << set2.size() << endl;
        for (auto& e : set2)
            cout << e << " ";
        cout << endl;

    }
}

