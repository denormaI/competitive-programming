#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int counts[256];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.length() == 1) {
        cout << s << endl;
        return 0;    
    }

    memset(counts, 0, 256*sizeof(int));

    // find distinct character counts
    for (char& c : s)
        counts[c]++;

    // find number of distinct characters with odd counts 
    ll odd_counts = 0;
    for (int& e : counts)
        if (e % 2 == 1)
            odd_counts++;

    // check for no solution
    bool oddlen = s.length() % 2 == 1;
    if ((oddlen && odd_counts != 1) ||
        (!oddlen && odd_counts > 0)) {
            cout << "NO SOLUTION\n";
            return 0;
    }

    // create even part of the string
    string ps(s.length(),' ');
    for (int i=0; i<s.length()/2; i++) {
        for(int c='A'; c<='Z'; c++) {
            if (counts[c]>=2) {
                counts[c]-=2;
                ps[i] = c;
                ps[s.length()-1-i] = c;
                break;
            }
        }
    }

    // add odd part in the middle
    if (oddlen) {
        char oddc = -1;
        for(int c='A'; c<='Z'; c++)
            if (counts[c] == 1) {
                oddc = c;
                break;
            }
        ps[s.length()/2] = oddc;
    }

    cout << ps << endl;
}
