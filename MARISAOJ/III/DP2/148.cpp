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
ll dp[2][nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // dp[0][l][r]; xet den luc marisa di
  // dp[1][l][r]; xet den luc reimu di
  // neu o luot marisa ma marisa chon a[l] -> dp[1][l-1][r]
  // neu o luot marisa ma marisa chon a[r] -> dp[1][l][r-1]
  // do do dp[0][l][r]=max(dp[1][l+1][r]+a[l], dp[1][l][r-1]+a[r]);
  // tuong tu dp[1][l][r]=min(dp[0][l+1][r]-a[l], dp[0][l][r-1]-a[r]);
  // kq la dp[0][1][n];
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    dp[0][i][i]+=a[i];
    dp[1][i][i]-=a[i];
  }
  for (int l = n; l >= 1; --l) {
    for (int r = l+1; r <= n; ++r) {
      dp[0][l][r]=max(dp[1][l+1][r]+a[l], dp[1][l][r-1]+a[r]);
      dp[1][l][r]=min(dp[0][l+1][r]-a[l], dp[0][l][r-1]-a[r]);
    }
  }
  cout << dp[0][1][n] << endl;
  return 0;
}
