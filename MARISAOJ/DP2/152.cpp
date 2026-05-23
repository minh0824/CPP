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

ll dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s; cin>>s;
  int n = sz(s);
  s=" "+s;
  // dp[i][j] la so cach tao ngoac khi xet den vi tri i co j = ( - )
  // ( -> dp[i][j]=dp[i-1][j-1];
  // ) -> dp[i][j]=dp[i-1][j+1];
  // ? -> dp[i][j]+=dp[i-1][j-1]+dp[i-1][j+1];
  //
  dp[0][0]=1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if ((s[i]=='('||s[i]=='?') && j>0) dp[i][j]+=dp[i-1][j-1];
      if ((s[i]==')'||s[i]=='?')) dp[i][j]+=dp[i-1][j+1];
      dp[i][j]%=mod;
    }
  }
  cout << (n%1?0:dp[n][0]);
  return 0;
}
