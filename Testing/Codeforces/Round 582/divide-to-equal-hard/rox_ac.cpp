#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, vector<int>> vals;
    for (auto x : a) {
        int cnt = 0;
        while (x) {
            vals[x].push_back(cnt);
            x /= 2;
            cnt++;
        }
        vals[x].push_back(cnt);
    }

    int ans = INT_MAX;
    for (auto p : vals) {
        auto cnts = p.second;
        if (sz(cnts) < k)
            continue;

        sort(all(cnts));
        ans = min(ans, accumulate(cnts.begin(), cnts.begin() + k, 0));
    }

    cout << ans << endl;
}
