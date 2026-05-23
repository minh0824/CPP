#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int color[MAXN];
bool hasCycle = false;

void dfs(int u) {
    if (hasCycle) return;
    color[u] = 1;

    for (int v : adj[u]) {
        if (color[v] == 1) {
            hasCycle = true;
            return;
        }
        if (color[v] == 0) {
            dfs(v);
        }
    }

    color[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n && !hasCycle; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    cout << (hasCycle ? "YES" : "NO") << "\n";
    return 0;
}
