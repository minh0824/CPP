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

int n, a[nmax];
ll pref[nmax], dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i]=pref[i-1]+a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) dp[i][j]=1e18;
    dp[i][i]=0;
  }
  // goi dp[i][j] la chi phi min de ghep doan tu i -> j
  // de ghep doan tu i->j se mat chi phi pref[j]-pref[i-1], gia tri sau do la pref[j]-pref[i-1];
  // xet k tu i->j
  // dp[i][j]=min(dp[i][k]+dp[k+1][j]+pref[j]-pref[i-1], dp[i][j])
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = i; k < j; ++k) {
        dp[i][j]=min(dp[i][k]+dp[k+1][j]+pref[j]-pref[i-1], dp[i][j]);
      }
    }
  }
  cout << dp[1][n];
  return 0;
}
