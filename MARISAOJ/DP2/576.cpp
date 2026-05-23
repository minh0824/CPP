#include <iostream>
#include <math.h>
#include <cstring>
#include <unordered_map>
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
const int nmax = 1e5 + 7;

unordered_map<int, ll> val;

ll dp(int x) {
  if (val.count(x)) return val[x];
  return val[x]=max(1ll*x, dp(x/2)+dp(x/3)+dp(x/4));
  // return val[x];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // y tuong dung de quy
  // de quy dp(x)->dp(x/2,3,4);
  // base case: 1->12 giu nguyen;
  for (int i = 0; i < 12; ++i) val[i]=i;
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    cout << dp(n) << endl;
  }
  return 0;
}
