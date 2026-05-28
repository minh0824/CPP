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

int n, q, a[nmax], pre[nmax];
int tree[4*nmax];
pair<int,int> p[nmax], tmp[nmax];
map<pair<int,int>, int> mp;

void update(int node, int l, int r, int pos, int val) {
  if (l==r) {
    tree[node]+=val;
    return ;
  }
  int mid = (l+r)/2;
  if (pos<=mid) {
    update(node*2, l, mid, pos, val);
  } else {
    update(node*2+1, mid+1, r, pos, val);
    // tree[node]=tree[node*2]+val;
  }
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
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; ++i) {
    cin >> p[i].ss >> p[i].ff;
    tmp[i]=p[i];
  }
  sort(tmp+1, tmp+q+1);
  tmp[0].ss=0;
  // xet den vi tri i;
  // update(vi tri pre[i], -1);
  // update(vi tri i, +1);
  for (int i = 1; i <= q; ++i) {
    for (int j = tmp[i-1].ff+1; j <= tmp[i].ff; ++j) {
      if (pre[a[j]]!=0) update(1, 1, n, pre[a[j]], -1);
      update(1, 1, n, j, 1);
      pre[a[j]]=j;
    }
    mp[{tmp[i].ss, tmp[i].ff}]=query(1, 1, n, tmp[i].ss, tmp[i].ff);
  }
  for (int i = 1; i <= q; ++i) {
    cout << mp[{p[i].ss, p[i].ff}] << endl;
  }

  return 0;
}
