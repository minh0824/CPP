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
const int nmax = 5e3 + 7;

int n, k;
ll a[nmax], dp[2][nmax][2];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i <= 1; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i][j][0]=-1e18;
      dp[i][j][1]=-1e18;
    }
  }
  dp[0][0][0]=0;
  for (int i = 1; i <= n; ++i) {
    int cur = i&1, prev = (i-1)&1;
    for (int j = 0; j <= k; ++j) {
      dp[cur][j][0]=max(dp[prev][j][0], dp[prev][j][1])+a[i];
      dp[cur][j][1]=dp[prev][j][1];
      if (j>0) {
        dp[cur][j][1]=max(dp[cur][j][1], dp[prev][j-1][0]);
      }
    }
  }
  ll ans{};
  n=n&1;
  for (int i = 0; i <= k; ++i) ans=max(ans, max(dp[n][i][0], dp[n][i][1]));
  cout << ans;
  return 0;
}
