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

int n, a[nmax];
ll val[nmax][nmax], dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // goi val[l][r] = x la gia tri khi nen mang l->r ve dung 1 phan tu la x
  // neu khong nen duoc -> val[l][r]=-1;
  // xet l<=mid<=r; neu val[l][mid]==val[mid+1][r];
  // val[l][r]=val[l][mid]+1;
  // bai toan ban dau: val[i][i] = a[i];
  cin >> n;
  memset(val, -1, sizeof(val));
  for (int i = 1; i <= n; ++i) dp[i]=1e9;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    val[i][i]=a[i];
  }
  for (int l = n; l >= 1; --l) {
    for (int r = l+1; r <= n; ++r) {
      for (int mid = l; mid < r; ++mid) {
        if (val[l][mid]==val[mid+1][r] && val[l][mid]!=-1) val[l][r]=val[l][mid]+1;
      }
    }
  }
  // goi dp[i] la so cach nen i phan tu dau sao cho co it phan tu nhat
  // xet val[j][i] nen duoc thanh 1 phan tu
  // if (val[j][i]!=-1) dp[i]=min(dp[i], dp[j-1]+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (val[j][i]!=-1) dp[i]=min(dp[i], dp[j-1]+1);
    }
  }
  cout << dp[n];
  return 0;
}
