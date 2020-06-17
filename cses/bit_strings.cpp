#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
T modpow(T base, T exp, T modulus) 
{
    base %= modulus;
    T result = 1;
    while (exp > 0) 
    {
        if (exp & 1) 
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull n;
    cin >> n;

    ull b = modpow<ull>(2,n,(ll)1e9+7);
    cout << b << endl;

    return 0;
}

