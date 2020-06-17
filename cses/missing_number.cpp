#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll

ll a[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    for (int i = 0; i < n-1; i++)
        cin >> a[i];
    
    sort(a, a+n-1);
    a[n-1] = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != i+1)
        {
            cout << i+1 << endl;
            break;
        }
    }
}

