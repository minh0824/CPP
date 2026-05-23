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
const int nmax = 1e6 + 7;

ll A, B, c[nmax], s[nmax], a[nmax], pref[nmax], p[nmax];

int low_bound(int l, int r, ll val) {
  int ans = -1;
  while (l<=r) {
    int mid = (l+r)/2;
    if (a[mid]>=val) {
      r = mid-1;
      ans=mid;
    } else l = mid+1;
  }
  return ans;
}

int rev_lower_bound(int l, int r, ll val) {
  int ans = -1;
  while (l<=r) {
    int mid = (l+r)/2;
    if (a[mid]<=val) {
      l = mid+1;
      ans=mid;
    } else r = mid-1;
  }
  return ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> A >> B;
  int mm = sqrt(B)+1;
  // c[1] = 1,2,3;
  // c[2] = 4,5,6,7,8;
  // c[3] = 9,10,11,12,13,14,15;
  // c[4] = 16,17,18,19,20,21,22,23,24;
  // c[i] = (i+1)*(i+1)-i*i;
  // tong tu c[1]->c[sqrt(n)] + phan du ra;
  // s[1]=c[1]*1;
  // s[2]=c[2]*2;
  // s[3]=c[3]*3;
  // ...
  // s[i]=c[i]*i;

  for (ll i = 0; i < nmax; ++i) c[i]=(i+1)*(i+1)-i*i;
  for (ll i = 1; i < nmax; ++i) {
    s[i]=1ll*c[i]*i;
    p[i]=p[i-1]+s[i];
  }

  // tao mang arr[i] la i*i;
  // tim lower_bound cua a trong arr;
  for (ll i = 1; i < nmax; ++i) {
    a[i]=(i+1)*(i+1)-1;
    pref[i]=pref[i-1]+a[i];
  }
  // for (int i = 1; i <= 10; ++i) cout << a[i] << endl;
  int ia = low_bound(1, mm, A);
  int ib = rev_lower_bound(0, mm, B);
  // cout << a[ia] << endl;
  // cout << ia << ' ' << ib;
  // cout << endl;
  // cout << a[ia] << ' ' << a[ib];
  ll ans{};
  // cout << ia << ' ' << ib << endl;
  ans += (a[ia]-A+1)*ia;
  // cout << ans << endl;
  ans += (B-a[ib])*(ib+1);
  // cout << ans << endl;
  int ii = int(sqrt(B)-1), jj = int(sqrt(A));
  // cout << ii << ' ' << jj << endl;
  // cout << p[ii] << ' ' << p[jj] << endl;
  // for (int i = 1; i <= 10; ++i) cout << p[i] << endl;
  ans += p[int(sqrt(B))-1]-p[int(sqrt(A))];
  cout << ans;
  return 0;
}
