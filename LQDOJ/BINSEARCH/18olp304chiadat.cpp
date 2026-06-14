#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 500 + 7;

int n, a[nmax][nmax], p[nmax][nmax];

int calc(int x1, int y1, int x2, int y2) {
  return p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    }
  }
  int ans=1e9;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int p1=calc(1,1,i-1,j-1);
      int p2=calc(i,1,n,j-1);
      int p3=calc(1,j,i-1,n);
      int p4=calc(i,j,n,n);
      int a = min(min(p1, p2), min(p3, p4));
      int b = max(max(p1, p2), max(p3, p4));
      ans=min(ans, b-a);
    }
  }
  cout << ans << endl;
  return 0;
}
