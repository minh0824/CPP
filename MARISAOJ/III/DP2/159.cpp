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
const int nmax = 1e3 + 7;

int n, k, a[nmax];
ll dp[nmax][nmax][2];

ll ucln(ll a, ll b) {
  if (b==0) return a;
  return ucln(b, a%b);
}

ll bcnn(ll a, ll b) {
  return a/ucln(a, b)*b;
}


signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // dp[i][j][state] hien tai ke i ko chon lay dc j sach
  // dp[n][k][0]=dp[n-1][k][1]+dp[n-1][k][0];
  // dp[n][k][1]=dp[n-1][k-1][1]+dp[n-1][k-1][0];
  // foundation: dp[1][0][0]=0, dp[1][1][1]=a[i];
  cin >> n >> k;
  dp[0][0][0]=1;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1];
    dp[i][0][0]%=mod;
    for (int j = 1; j <= k; ++j) {
      dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
      dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
      dp[i][j][1]*=a[i];
      dp[i][j][0]%=mod;
      dp[i][j][1]%=mod;
    }
  }
  cout << (dp[n][k][1]+dp[n][k][0])%mod;
  return 0;
}
