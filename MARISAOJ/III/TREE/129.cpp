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

int n, k, d[nmax];
vector<int> adj[nmax];

void dfs(int u, int parent) {
  for (int v : adj[u]) {
    if (v!=parent) {
      d[v]=d[u]+1;
      dfs(v, u);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  dfs(1, 0);
  ll ans{};
  sort(d+1, d+n+1, greater<int>());
  for (int i = 1; i <= k; ++i) ans+=d[i];
  cout << ans;

  return 0;
}
