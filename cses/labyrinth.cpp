#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define idx(y,x,w) ((y)*(w)+(x))

bool visited[1001*1001];
char cmap[1001*1001];
int dist[1001*1001];
vector<ll> adj[1001*1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n >> m; // height/width

    memset(visited,false,n*m*sizeof(bool));
    memset(dist,-1,n*m*sizeof(int));

    ll start = -1;
    ll end = -1;
    
    // read map
    for (int h=0; h<n; h++) {
        for (int w=0; w<m; w++) {
            char c;
            cin >> c;
            if (c == 'A') {
                start = idx(h,w,m);
                c = '.';
            } else if (c == 'B') {
                end = idx(h,w,m);
                c = '.';
            } 
            cmap[idx(h,w,m)] = c;
        }
    }
    
    // process map in to adjacent graph
    for (int h=0; h<n; h++) {
        for (int w=0; w<m; w++) {
           if (cmap[idx(h,w,m)] == '.') {
                auto& radj = adj[idx(h,w,m)];
                radj.reserve(4);
                if (w > 0) // adj left
                    if (cmap[idx(h,w-1,m)] == '.')
                        radj.push_back(idx(h,w-1,m));
                if (w < m-1) // adj right
                    if (cmap[idx(h,w+1,m)] == '.')
                        radj.push_back(idx(h,w+1,m)); 
                if (h > 0) // adj top
                    if (cmap[idx(h-1,w,m)] == '.')
                        radj.push_back(idx(h-1,w,m));
                if (h < n-1) // adj bottom
                    if (cmap[idx(h+1,w,m)] == '.')
                        radj.push_back(idx(h+1,w,m));
            }
        }
    }

    deque<ll> q;
    unordered_map<ll, ll> parent;

    q.push_back(start);

    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        ll node = q.front(); q.pop_front();
        
        if (end == node) {
            vector<ll> path = {end};

            while (path.back() != start)
                path.push_back(parent[path.back()]);

            reverse(path.begin(), path.end());

            string str;
            for (int i=0; i<path.size()-1; i++) {
                ll delta = path[i+1] - path[i];
                
                if (delta == -1) str += 'L';
                if (delta == 1) str += 'R';
                if (delta == -m) str += 'U';
                if (delta == m) str += 'D';
            }

            cout << "YES\n" << dist[end] << endl << str << endl;

            return 0;
        }

        for (ll adjn : adj[node]) {
            if (visited[adjn]) continue;
            visited[adjn] = true;

            dist[adjn] = dist[node]+1;
            
             parent[adjn] = node;
            q.push_back(adjn);
        }
    }

    cout << "NO\n";
}

