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

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m, k, layer[nmax];
vector<int> adj[nmax];
vector<pair<int, int>> elec;
bool visited[nmax];

void bfs() {
  queue<pair<int,int>> q;
  for (pair<int,int> i : elec) {
    if (i.ss>layer[i.ff]) {
      layer[i.ff]=i.ss;
      q.push({i.ff,i.ss});
    }
  }
  while(!q.empty()) {
    pair<int,int> i = q.front();
    q.pop();
    if (len==0) continue;
    for (int v : adj[u]) {
      if (!visited[v]) {
        visited[v]=1;
        q.push(v);
      }
      layer[v]=max(layer[v], layer[u]-1);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= k; ++i) {
    int a, r; cin >> a >> r;
    elec.pb({a, r});
  }
  bfs();
  int cnt{};
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) ++cnt;
  }
  cout << cnt;

  return 0;
}
