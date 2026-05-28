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

int n, tree[4*nmax];
vector<int> adj[nmax];
int tin[nmax], tout[nmax], cnt;

void dfs(int u, int parent) {
  tin[u]=++cnt;
  for (int v : adj[u]) {
    if (v!=parent) {
      dfs(v, u);
    }
  }
  tout[u]=cnt;
}

void update(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return ;
  if (L<=l && r<=R) {
    ++tree[node];
    return ;
  }
  int mid = (l+r)/2;
  update(node*2, l, mid, L, R);
  update(node*2+1, mid+1, r, L, R);
}

int query(int node, int l, int r, int val) {
  if (l==r) return tree[node];
  int mid = (l+r)/2;
  if (val<=mid) {
    return tree[node]+query(node*2, l, mid, val);
  } else {
    return tree[node]+query(node*2+1, mid+1, r, val);
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    cout << query(1, 1, n, tin[x]) << ' ';
    update(1, 1, n, tin[x], tout[x]);
  }
  return 0;
}
