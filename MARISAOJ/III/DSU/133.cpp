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

int n, parent[nmax], sz[nmax];

int find(int v) {
  return v==parent[v] ? v : parent[v]=find(parent[v]);
}

void union_set(int a, int b) {
  a = find(a), b = find(b);
  if (a!=b) {
    parent[a]=b;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    parent[i]=i;
    sz[i]=1;
  }
  for (int i = 1; i <= n; ++i) {
    int p; cin >> p;
    p = find(p);
    cout << p << ' ';
    union_set(p, ((p+1)%n==0?n:(p+1)%n));
  }
  return 0;
}
