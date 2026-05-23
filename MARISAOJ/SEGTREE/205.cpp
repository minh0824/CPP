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

const ll INF = 1e18+7;
const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, q;
ll dp[nmax], tree[4*nmax];
pair<pair<int,int>, int> a[nmax];

// segment tree quan ly dp

void build(int node, int l, int r) {
  if (l==r) {
    tree[node]=dp[l];
    return ;
  }
  int mid=(l+r)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);
  tree[node]=min(tree[node*2], tree[node*2+1]);
}

void update(int node, int l, int r, int pos, ll val) {
  if (l==r) {
    tree[node]=min(tree[node], val);
    return ;
  }
  int mid = (l+r)/2;
  if (pos<=mid) {
    update(node*2, l, mid, pos, val);
  } else {
    update(node*2+1, mid+1, r, pos, val);
  }
  tree[node]=min(tree[node*2], tree[node*2+1]);
}

// query tim dp[i] nho nhat thuoc doan L, R
ll query(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return INF;
  if (L<=l && r<=R) return tree[node];
  int mid = (l+r)/2;
  return min(query(node*2, l, mid, L, R), query(node*2+1, mid+1, r, L, R));
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) dp[i]=INF;
  build(1, 0, n);
  for (int i = 1; i <= q; ++i) {
    cin >> a[i].ff.ss >> a[i].ff.ff >> a[i].ss;
  }
  sort(a+1, a+q+1);
  for (int i = 1; i <= q; ++i) {
    int l = a[i].ff.ss, r = a[i].ff.ff, c = a[i].ss;
    dp[r]=min(dp[r], query(1, 0, n, l-1, r-1)+c);
    update(1, 0, n, r, dp[r]);
  }
  cout << ((dp[n]==INF)?-1:dp[n]);
  return 0;
}
