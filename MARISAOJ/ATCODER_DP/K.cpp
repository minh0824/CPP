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
const int nmax = 1e5 + 7;

int n, k, a[nmax], dp[nmax];


signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  // dp[i] xet den luc con i vien da lieu co the dua doi thu vao trang thai thua hay ko
  // dp[i-a[j]]==0 && i-a[j]>=0 --> dp[i]=1;
  for (int i = 1; i <= k; ++i) {
    for (int j=1; j<=n; ++j) {
      if (i-a[j]>=0&&dp[i-a[j]]==0) dp[i]=1;
    }
  }
  cout << ((dp[k])?"First":"Second");
  return 0;
}
