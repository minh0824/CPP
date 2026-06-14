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
const int nmax = 1e5 + 7;

int n, a[nmax];
ll k, p[nmax], tree[4*nmax], tmp[nmax];
map<ll, int> id;

// xet pref[i] dem xem co bn pref[j] ma sum(ij) <= val;
// pref[i]-pref[j]<=val;
// pref[i]<=val+pref[j];

void update(int node, int l, int r, int pos) {
  if (l==r) {
    tree[node]++;
    return ;
  }
  int mid = (l+r)/2;
  if (pos<=mid) update(node*2, l, mid, pos);
  else update(node*2+1, mid+1, r, pos);
  tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return 0;
  if (L<=l && r<=R) return tree[node];
  int mid = (l+r)/2;
  return query(node*2, l, mid, L, R)+query(node*2+1, mid+1, r, L, R);
}

bool check(ll val) {
  ll ans{};
  fill(tree, tree+4*nmax, 0);
  for (int i = 1; i <= n; ++i) {
    update(1, 0, n, id[p[i-1]]);
    int pos = upper_bound(tmp, tmp + n + 1, p[i] - val) - tmp - 1;
      if (pos >= 0) ans += query(1, 0, n, 0, pos);
      if (ans >= k) return true;
  }
  return false;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i]=p[i-1]+a[i];
    tmp[i]=p[i];
  }
  sort(tmp, tmp+n+1);
  for (int i = 0; i <= n; ++i) { id[tmp[i]]=i; }
  // for (int i = 0; i <= n; ++i) cout << p[i] << ' ' << id[p[i]] << endl;
  ll l = -1e14, r = 1e14;
  ll res{};
  while (l<=r) {
    ll mid = (l+r)/2;
    if (check(mid)) {
      l = mid+1;
      res = mid;
    } else {
      r = mid-1;
    }
  }
  cout << res << endl;
  return 0;
}
