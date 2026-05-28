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

int n, m, q, parent[nmax], sz[nmax], cnt[nmax];
vector<pair<int, int>> query, adj;

int find(int v) {
  return v==parent[v]?v:parent[v]=find(parent[v]);
}

void union_set(int a, int b) {
  a = find(a), b = find(b);
  if (a!=b) {
    if (sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b];
    parent[b]=a;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    adj.pb({x, y});
  }
  for (int i = 1; i <= q; ++i) {
    int e, c; cin >> e >> c;
    query.pb({e, c});
  }
  // for (pair<int,int> i : adj) cout << i.ff << ' ' << i.ss << endl;
  // for (pair<int,int> i : query) cout << i.ff << ' ' << i.ss << endl;
  reverse(allin(query));
  for (int i = 1; i <= n; ++i) {
    parent[i]=i;
    sz[i]=1;
  }
  for (pair<int,int> i : query){ ++cnt[i.ff-1]; }
  for (int i = 0; i < adj.size(); ++i) {
    if (!cnt[i]) union_set(adj[i].ff, adj[i].ss);
  }
  vector<int> ans;
  for (pair<int,int> i : query) {
    int e = i.ff, c = i.ss;
    ans.pb(sz[find(c)]);
    // cout << sz[find(c)] << ' ';
    union_set(adj[e-1].ff, adj[e-1].ss);
  }
  reverse(allin(ans));
  for (int i : ans) cout << i << ' ';
  return 0;
}
