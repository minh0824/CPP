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

int n, q, parent[nmax];
ll sz[nmax];

void make_set() {
  for (int i = 1; i <= n; ++i) {
    parent[i]=i;
    sz[i]=i;
  }
}

int find(int v) {
  return v==parent[v] ? v : parent[v] = find(parent[v]);
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
  cin >>n >> q;
  make_set();
  while(q--) {
    int s, u, v; cin >> s;
    if (s==1) {
      cin >> u >> v;
      union_set(u, v);
    } else {
      cin >> u;
      cout << sz[find(u)] << endl;
    }
  }
  return 0;
}
