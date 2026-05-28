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

int n, q, a[nmax], parent[nmax];
int b[nmax], query[nmax], tmp[nmax];
map<int,int> id, sz;

// b = sort(a);
//
// xet tung ptu cua b
// xet find(b[i]) voi a[id[find(b[i])]+1];

void make_set() {
  for (int i = 1; i <= n; ++i) {
    parent[i]=i;
    sz[i]=1;
  }
}

int find(int v) {
  return v==parent[v] ? v : parent[v]=find(parent[v]);
}

void union_set(int a, int b) {
  a = find(a), b = find(b);
  if (a!=b) {
    parent[a]=b;
    sz[b]+=sz[a];
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i]=a[i];
    id[a[i]]=i;
  }
  make_set();
  sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
    // b[i];
    if (a[id[b[i]]+1]<=b[i]) union_set(a[id[b[i]]], b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << sz[b[i]] << ' ';
  }

  return 0;
}
