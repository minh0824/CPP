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

const int mod = 1e9+7;
const int nmax = 1e5 + 7;

int n, k, a[107], pref[107];
ll dp[107][nmax], p[107][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    pref[i]=a[i]+pref[i-1];
  }
  // xet den vi tri i lay x vien keo
  // dp[i][j]=dp[i-1][j-x] voi 0<=x<=a[i];
  // nhung vi tri truoc do chi co the lay toi da pref[i-1] vien keo
  // neu j-x>pref[i-1] thi ko update
  //
  for (int i = 0; i <= k+1; ++i) {
    dp[0][i]=1;
    p[0][i]=p[0][max(0, i-1)]+dp[0][i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= min(k, pref[i]); ++j) {
      dp[i][j] = (p[i-1][min(j, pref[i-1])+1]-p[i-1][max(0, j-a[i])] + mod) % mod;
    }
    for (int j = 0; j <= min(k, pref[i]); ++j) {
      p[i][j+1]=(p[i][j]+dp[i][j])%mod;
    }
  }
  cout << dp[n][k];
  return 0;
}
