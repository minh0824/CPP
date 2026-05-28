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

int n, a[nmax], id[nmax];
ll p[nmax], tmp[nmax], tree[4*nmax];

// tuc la id[i];

// de bai yeu cau tim dem moi j sao cho
// pref[i]-pref[j]>=0
// pref[j]<=pref[i];
// nhu vay ta se nen moi pref[x]
// thanh cac node tren segtree
//
// khi do ta chi can query(1, 1, ind[pref[i]]);
// khi update ta chi can update(1, 1, ind[pref[i]]);

void proc() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i]=p[i-1]+a[i];
    tmp[i]=p[i];
  }
  sort(tmp, tmp+n+1);
  for (int i = 0; i <= n; ++i) id[i]=lower_bound(tmp, tmp+n+1, p[i])-tmp;
}

// segment tree dem tan suat cua mang cnt;

void update(int node, int l, int r, int pos) {
  if (l==r) {
    ++tree[node];
    return ;
  }
  int mid = (l+r)/2;
  if (pos<=mid) {
    update(node*2, l, mid, pos);
  } else {
    update(node*2+1, mid+1, r, pos);
  }
  tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return 0;
  if (L<=l && r<=R) return tree[node];
  int mid = (l+r)/2;
  return query(node*2, l, mid, L, R)+query(node*2+1, mid+1, r, L, R);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  proc();
  ll ans{};
  // for (int i = 0; i <= n; ++i) cout << id[i] << endl;
  update(1, 0, n, id[0]);
  for (int i = 1; i <= n; ++i) {
    ans+=query(1, 0, n, 0, id[i]);
    update(1, 0, n, id[i]);
  }
  cout << ans;
  return 0;
}
