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

int n, q, a[nmax];
vector<int> tree[4*nmax];

vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> c=a;
  for (int i : b) c.pb(i);
  sort(allin(c));
  return c;
}

void build(int node, int l, int r) {
  if (l==r) {
    tree[node].pb(a[l]);
    return ;
  }
  int mid = (l+r)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);
  tree[node]=merge(tree[node*2], tree[node*2+1]);
}

int query(int node, int l, int r, int L, int R, int k) {
  if (r<L || R<l) return {};
  if (L<=l && r<=R) return tree[node].end()-upper_bound(allin(tree[node]), k);
  int mid = (l+r)/2;
  return query(node*2, l, mid, L, R, k) + query(node*2+1, mid+1, r, L, R, k);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << query(1, 1, n, l, r, k) << endl;
  }
  return 0;
}
