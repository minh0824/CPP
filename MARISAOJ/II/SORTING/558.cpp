#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int nmax = 1e6 + 7;

int n;
ll a[nmax], p[nmax], sum;

bool cmp(string a, string b) {
  return a+b>b+a;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum+=a[i];
  }

  ll avg = sum/n;
  for (int i = 1; i <= n; ++i) {
    p[i]=p[i-1]+a[i]-avg;
  }

void quickSort(int a[], int l, int r) {
  int p = a[(l+r)/2];
  int i = l, j = r;
  while (i < j){
    while (a[i] < p){
    i++;
    }
    while (a[j] > p){
    j--;
    }
    if (i <= j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    i++;
    j--;
    }
  }
  if (i < r) quickSort(a, i, r);
  if (l < j) quickSort(a, l, j);
}


  sort(p+1, p+n+1, cmp);
  ll mid = p[(n+1)/2];

  ll ans{};
  for (int i = 1; i <= n; ++i) {
    ll d = p[i]-mid;
    ans+=(d<0?-d:d);
  }
  cout << ans;
  return 0;
}
