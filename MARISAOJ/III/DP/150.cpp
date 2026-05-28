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

typedef unsigned long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 500 + 7;

int a, b;
int dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> a >> b;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) dp[i][j]=1e9;
    dp[i][i]=0;
  }
  // axb cat thanh hcn a*k+a*(b-k)
  // axb cat thanh hcn k*b+(a-k)*b
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      for (int k = 1; k <= max(i, j); ++k) {
        if (i-k>=1) dp[i][j]=min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
        if (j-k>=1) dp[i][j]=min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
      }
    }
  }
  cout << dp[a][b];
  return 0;
}
