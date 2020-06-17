#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;


void permute(set<string>& perm, string str, string out="") 
{
    if (str.size() == 0) 
    { 
        perm.insert(out);
        return; 
    } 
  
    for (int i = 0; i < str.size(); i++) 
    { 
        permute(perm, str.substr(1), out + str[0]); 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    set<string> perms;
    permute(perms, s);

    cout << perms.size() << endl;
    for (auto& s : perms)
        cout << s << endl;
}

