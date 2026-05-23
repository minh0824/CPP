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

string a[nmax];

void quickSort(string a[], int l, int r){
  string p = a[(l+r)/2];
  int i = l, j = r;
  while (i < j){
    while (a[i] < p){
    i++;
   }
    while (a[j] > p){
    j--;
   }
   if (i <= j){
    string temp = a[i];
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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int cur{};
  while (cin>>a[cur]) {
    ++cur;
  }
  quickSort(a, 0, cur-1);
  for (int i = cur-1; i >= 0; --i) cout << a[i];
  return 0;
}
