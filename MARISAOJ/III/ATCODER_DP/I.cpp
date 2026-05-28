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
const int nmax = 3e3 + 7;

int n;
double p[nmax], dp[nmax][nmax];
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // dp[i][j] xac xuat tung den dong xu thu i co j mat ngua
  // neu dong xu i la ngua
  // dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j-1]*(1-p[i]);
  //
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j-1>=0) dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
      else dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
    }
  }
  double ans{};
  for (int i = n; i > n/2; --i) {
    ans+=dp[n][i];
  }
  cout << ans;
  return 0;
}
