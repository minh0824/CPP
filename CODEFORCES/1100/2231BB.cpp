#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(a) (int)(a.size())


#ifdef LOCAL
#define __lg(n) log2(n)
#endif

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

template<typename T>
using PQ = priority_queue<T, vector<T>, greater<>>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mx = 0;
    for (int i = 0; i < n - 1; ++i) {
        mx = max(mx, a[i] - a[i + 1]);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            a[i] += mx;
        }
    }
    if (is_sorted(all(a))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
