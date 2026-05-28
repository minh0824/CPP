#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int INF = 1e9;
const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m, k;
vector<int> adj[nmax];
bool visited[nmax];

void bfs() {
  vector<vector<int>> d(n+1, vector<int>(k, INF));
  // goi d[u][j] la so canh nho nhat de di den duoc u
  // va da du j canh o buoc hien tai;
  queue<pair<int,int>> q;
  d[1][0]=0;
  q.push({1, 0});

  while (!q.empty()) {
    pair<int,int> i = q.front();
    int u = i.ff, r = i.ss;
    q.pop();

    for (int v : adj[u]) {
      int newr = (r+1)%k;
      if (d[v][newr]>d[u][r]+1) {
        d[v][newr]=d[u][r]+1;
        q.push({v, newr});
      }
    }
  }
  if (d[n][0]==INF) {
    cout << -1;
  } else {
    cout << d[n][0]/k;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    adj[x].pb(y); adj[y].pb(x);
  }
  bfs();
  return 0;
}
