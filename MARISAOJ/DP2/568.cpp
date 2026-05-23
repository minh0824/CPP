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

string s;
int dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // dp[i][j] so ki tu it nhat phai them vao doan i->j de tro thanh palin
  // neu a[i]==a[j] -> dp[i][j]=dp[i+1][j-1];
  // neu a[i]!=a[j] -> dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;
  cin >> s;
  int n = sz(s);
  s=" "+s;
  for (int i = n; i >= 1; --i) {
    for (int j = i+1; j <= n; ++j) {
      if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
      else dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;
    }
  }
  cout << dp[1][n];
  return 0;
}
