#include <iostream>
#include <algorithm>

using namespace std;

int stacks[51][30];
int pref[51][30];

int rec(int n, int k, int p, int idx, int taken)
{
    if (taken == p)
        return 0;
    if (idx >= n || taken > p)
        return 0;
    int ans = -1;
    for (int i = 0; i < k; i++)
    {
        ans = max(ans, pref[idx][i] + rec(n, k, p, idx + 1, taken + i));
    }
    return ans;
}

// returns the total sum of beauty values picked 
int solve(int n, int k, int p)
{
    return rec(n,k,p,0,0);
}

int main()
{
    int t;
    cin >> t;
   
    for (int i = 0; i < t; i++)
    {
        int n, k, p;
        cin >> n >> k >> p;
        for (int ni = 0; ni < n; ni++)
        {
            int sum = 0;
            for (int ki = 0; ki < k; ki++)
            {
                cin >> stacks[ni][ki];
                sum += stacks[ni][ki];
                pref[ni][ki] = sum;
            }
        }
        cout << "Case #" << i+1 << ": " << solve(n,k,p) << endl;
    }
}
