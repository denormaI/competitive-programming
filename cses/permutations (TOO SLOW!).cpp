#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

ll n;
vector<ll> pv;
bool chosen[1000001];

bool beautiful_permute()
{
    if (pv.size() == n) // process permutation
    {
        for (ll i = 1; i < n; i++)
        {
            if (abs(pv[i] - pv[i-1]) == 1)
                return false; // not beautiful
        }

        return true; // beautiful
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (chosen[i]) 
                continue;
            chosen[i] = true;
            pv.push_back(i);
            if (beautiful_permute())  // if beautiful found, return
                return true;
            chosen[i] = false;
            pv.pop_back();
        }
    }

    // no solution
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    memset(chosen, false, 1000001*sizeof(bool));

    pv.reserve(n);
    if (beautiful_permute())
    {
        for (auto& e : pv)
            cout << e << " ";
        cout << endl;
    }
    else
        cout << "NO SOLUTION" << endl;

    return 0;
}

