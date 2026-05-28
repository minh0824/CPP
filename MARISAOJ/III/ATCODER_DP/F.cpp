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

string s, t;
int dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> t;
  int n=sz(s), m=sz(t);
  s=" "+s, t=" "+t;
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
      if (s[i]==t[j]) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
    }
  }
  if (dp[n][m]==0) {
    return 0;
  }
  string res{};
  for(; n>0 && m>0; ) {
    if (s[n-1]>t[m-1]) { res+=s[n-1], --n, --m; }
    else {
      if (dp[n-1][m]>dp[n][m-1]) --n;
      else --m;
    }
  }
  reverse(allin(res));
  cout << res;
  return 0;
}
