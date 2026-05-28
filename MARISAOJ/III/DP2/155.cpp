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

const int mod = 123456789;
const int nmax = 2e3 + 7;

int n, k, a[nmax];
ll dp[nmax][nmax], sum[nmax], sum_i[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // y tuong tuong tu bai truoc
  // dp[a[i]][k] cach chon day con do dai k ket thuc o a[i];
  // goi sum[j] la so cach chon day con do dai j
  // sum_i[j] = sum[j] + 1;
  // sum[j] = sum[j] - dp[a[i]][j-1] + sum_i[j];
  // dp[a[i]][j] = sum_i[j];
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = k; j >= 1; --j) {
      sum_i[j] = sum[j-1]%mod;
      sum_i[1]=1;
      sum[j] = (sum[j] - dp[a[i]][j] + sum_i[j]+mod)%mod;
      dp[a[i]][j] = sum_i[j]%mod;
    }
  }
  cout << sum[k];
  return 0;
}
