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
const int nmax = 1e6 + 7;

int n, a[nmax];
ll dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // goi dp[i] la so doan con khac nhau ket thuc o i
  // goi sum la tong doan con khac nhau tinh den i-1
  // khi xet den i
  // ta co the tao doan con khac nhau bang cach chon
  // rieng i hoac them i vao moi doan con khac nhau
  // va cho ket thuc o i
  // *** Nhung truoc do da mot so doan con ket thuc o i
  // do vay
  // sum update lai
  // dp[a[i]] = sum+1;
  // sum = sum - dp[a[i]] + sum + 1;
  //
  ll sum{}, newsum{};
  for (int i = 1; i <= n; ++i) {
    newsum = sum+1;
    newsum%=mod;
    sum = (sum - dp[a[i]] + newsum + mod) % mod;
    dp[a[i]]=newsum%mod;
  }
  cout << sum;
  return 0;
}
