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
const int nmax = 1e5 + 7;

int n, m, a[nmax], dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
  }
  // xet tu 1->n;
  // dp[i]: hien tai voi i coc ruou co the thang hay ko
  // neu i-a[j]>=0 va dp[i-a[j]]==0 thi co the win
  // dp[0]=0 do den luot marisa hien tai da ko the chon coc ruou nao;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i-a[j]>=0 && dp[i-a[j]]==0) dp[i]=1;
    }
  }
  cout << ((dp[n])?"Marisa":"Reimu");
  return 0;
}
