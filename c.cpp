#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpil = vector<pil>;
using vpli = vector<pli>;
#define psb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

constexpr int INF = 1e9;
constexpr ll LINF = 1e18;
constexpr int MOD = 1e9 + 7;
constexpr int MOD2 = 998244353;
constexpr int MAXN = 300005;


map<vector<int>, ll> dp;

ll solve(vector<int> arr)
{
    if (arr.empty()) return 0;

    if (dp.count(arr))
        return dp[arr];

    ll ans = 0;
    set<int> vis;

    for (int x : arr)
    {
        if (vis.count(x)) continue;
        vis.insert(x);

        int l = -1, r = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == x)
            {
                if (l == -1) l = i;
                r = i;
            }
        }

        vector<int> nxt;
        for (int i = 0; i < l; i++) nxt.push_back(arr[i]);
        for (int i = r + 1; i < arr.size(); i++) nxt.push_back(arr[i]);

        ll len = r - l + 1;
        ans = max(ans, len * len + solve(nxt));
    }

    return dp[arr] = ans;
}
void shiv()
{
     int n;
        cin >> n;
        int k=2*n;
        vi arr(k);
        for (int i = 0; i < k; i++) cin >> arr[i];
            cout << solve(arr) <<endl;
}


int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
        shiv();

    return 0;
} 