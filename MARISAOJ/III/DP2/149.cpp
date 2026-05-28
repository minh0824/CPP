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

const int mod = 100;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // dp[i][j] la chi phi nho nhat de hop doan tu i->j
  // neu ta hop nhat phan tu k va k+1 trong doan i->j
  // dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum(i->j));
  int n; cin >> n;
  vector<ll> pref(n+1, 0), a(n+1);
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, 1e18));
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    pref[i]=pref[i-1]+a[i];
    pref[i]%=mod;
  }
  for (int i=n; i>=1; --i) {
    for (int j=i; j<=n; ++j) {
      dp[j][j]=0;
      for (int k=i; k<j; ++k) {
        ll l = pref[j]-pref[k]+mod, r = pref[k]-pref[i-1]+mod;
        dp[i][j]=min(dp[i][k]+dp[k+1][j]+(l%mod)*(r%mod), dp[i][j]);
      }
    }
  }
  cout << dp[1][n];
  return 0;
}
