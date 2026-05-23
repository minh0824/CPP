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

int n, child[nmax];
vector<int> adj[nmax];
ll dp[2][nmax];

void dfs(int u, int parent) {
  for (int v : adj[u]) {
    if (v != parent) {
      dfs(v, u);
      dp[0][u]*=(dp[0][v]+dp[1][v])%mod;
      dp[0][u]%=mod;
      dp[1][u]*=dp[0][v];
      dp[1][u]%=mod;
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    adj[x].pb(y); adj[y].pb(x);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    ++dp[0][i], ++dp[1][i];
  }
  dfs(1, 0);
  cout << (dp[1][1]+dp[0][1])%mod;
  return 0;
}
