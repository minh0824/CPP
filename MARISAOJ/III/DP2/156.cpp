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
const int nmax = 1e4 + 7;

int n, S;
ll dp[1407][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> S;
  vector<pair<int,int>> knapsacks;
  for (int i = 1; i <= n; ++i) {
    int w, v, a;
    cin >> w >> v >> a;

    // tach a thanh cac nhom 2^k: 1, 2, 4, 8,...
    int k = 1;
    while (k<=a) {
      knapsacks.pb({k*w, k*v});
      a-=k;
      k*=2;
    }
    if (a>0) knapsacks.pb({a*w, a*v});
  }
  for (int i = 1; i <= knapsacks.size(); ++i) {
    int w = knapsacks[i-1].ff, v = knapsacks[i-1].ss;
    for (int j = S; j >= 1; --j) {
      dp[i][j]=dp[i-1][j];
      if (j-w>=0) dp[i][j]=max(dp[i][j], dp[i-1][j-w]+v);
    }
  }
  cout << dp[sz(knapsacks)][S];
  return 0;
}
