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

void quickSort(int a[], int l, int r){
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
  if (i < r){
    quickSort(a, i, r);
  }
  if (l < j){
    quickSort(a, l, j);
  }
}

int a[nmax];

int ucln(int a, int b) {
  if (b==0) return a;
  return ucln(b, a%b);
}

ll bcnn(ll a, ll b) {
  return a/ucln(a, b)*b;
}


signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int cur{};
  while (cin>>a[cur]) {
    ++cur;
  }
  quickSort(a, 0, cur-1);
  for (int i = cur-1; i >= 0; --i) cout << a[i] << ' ';
  cout << endl;
  ll ans{};
  for (int i = 0; i < cur; ++i) {
    for (int j = i+1; j < cur; ++j) {
      if (ucln(a[i], a[j])==1) {
        ++ans;
        // cout << a[i] << ' ' << a[j] << endl;
      }
    }
  }
  cout << ans;
  return 0;
}
