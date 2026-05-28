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

int n, q;
int parent[nmax], sz[nmax], h[nmax];

// khoi tao tap con ban dau
void make_set() {
  for (int i = 1; i <= n; ++i) {
    parent[i]=i;
    sz[i]=1;
    h[i]=0;
  }
}

// tim cha cua mot phan tu bat ki
int findnaive(int u) {
  if (u==parent[u]) return u;
  return findnaive(parent[u]);
}

// int find(int v) {
//   if (v==parent[v]) return v;
//   int p = find(parent[v]);
//   parent[v]=p;
//   return p;
// }

// gan parent moi ptu them vao = cay goc dau tien cua tap hop;
int find(int v) {
  return v==parent[v] ? v : parent[v]=find(parent[v]);
}

// hop 2 phan tu
void union_set(int a, int b) {
  a = find(a), b = find(b);
  if (a!=b) {
    if (sz[a]<sz[b]) swap(a, b);
    parent[b]=a;
    sz[a]+=sz[b];
  }
}

void union_seth(int a, int b) {
  a = find(a), b = find(b);
  if (a!=b) {
    if (h[a]<h[b]) swap(a, b);
    parent[b]=a;
    if (h[a]==h[b]) h[a]++;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  make_set();
  while (q--) {
    int state, u, v; cin >> state >> u >> v;
    if (state==1) {
      union_set(u, v);
    } else {
      cout << (find(u)==find(v)?"YES":"NO") << endl;
    }
  }

  return 0;
}
