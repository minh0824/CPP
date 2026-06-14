#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int nmax = 1e5 + 7;

int tree[4*nmax];
ll ans;

void update(int node, int l, int r, int pos) {
  if (l==r) {
    ++tree[node];
    return;
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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    ans+=query(1, 1, n, x, n);
    update(1, 1, n, x);
  }
  cout << ans << endl;
  return 0;
}
