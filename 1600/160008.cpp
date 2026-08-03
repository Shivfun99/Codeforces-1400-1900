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


void shiv()
{
    int n; cin>>n;
    vl arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
     sort(all(arr));

        if (arr.front() == 0 && arr.back() == 0) {
            cout << "No\n";
            return;
        }

        vl ans;
        int l = 0, r = n - 1;
        ll sum = 0;

        while (l <= r) {
            if (sum >= 0)
                sum += arr[l], ans.psb(arr[l++]);
            else
                sum += arr[r], ans.psb(arr[r--]);
        }

        cout << "Yes\n";
        for (ll x : ans) cout << x << " ";
        cout << "\n";
  
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