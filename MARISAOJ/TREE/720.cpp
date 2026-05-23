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

int n, d[nmax];
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

  return 0;
}
