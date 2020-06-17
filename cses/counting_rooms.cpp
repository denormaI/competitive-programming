#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

char map[1001][1001];
bool visited[1001][1001];
vector<pair<int,int>> adj[1001][1001];

int visit_count = 0;

void dfs(pair<int,int> n) {
    int y = get<0>(n);
    int x = get<1>(n);

    // ignore nodes already visited and walls
    if (visited[y][x] || map[y][x] == '#')
        return;

    visited[y][x] = true;
    visit_count++;

    for (auto& p : adj[y][x])
        dfs(p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin >> n >> m; // height/width

    for (int h=0; h<n; h++)
        memset(visited[h],false,m*sizeof(bool));

    // read map
    for (int h=0; h<n; h++) {
        for (int w=0; w<m; w++) {
            char c;
            cin >> c;
            map[h][w] = c;
        }
    }

    // process map in to adjacent graph
    for (int h=0; h<n; h++) {
        for (int w=0; w<m; w++) {
            switch (map[h][w]) {
            case '#': // ignore walls
                break;
            case '.': {
                if (w > 0) // adj left
                    if (map[h][w-1] == '.')
                        adj[h][w].push_back({h,w-1});
                if (w < m-1) // adj right
                    if (map[h][w+1] == '.')
                        adj[h][w].push_back({h,w+1}); 
                if (h > 0) // adj top
                    if (map[h-1][w] == '.')
                        adj[h][w].push_back({h-1,w});
                if (h < n-1) // adj bottom
                    if (map[h+1][w] == '.')
                        adj[h][w].push_back({h+1,w});
                } break;
            } 
        }
    }
    
    int rooms = 0;
    for (int h=0; h<n; h++) {
        for (int w=0; w<m; w++) {
            dfs({h,w});
            if (visit_count > 0) {
                rooms++;
                visit_count = 0;
            }
        }
    }
    
    cout << rooms << endl;
}

