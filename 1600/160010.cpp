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
   int n; cin >> n;
        string s; cin >> s;

        vi f(26);
        for (char c : s) f[c-'a']++;

        int ans = n + 1;
        string res;

        for (int k = 1; k <= 26; k++) {
            if (n % k) continue;

            int need = n / k;
            vector<pair<int,int>> v;
            for (int i = 0; i < 26; i++) v.psb({f[i], i});
            sort(v.rbegin(), v.rend());

            vi lim(26);
            for (int i = 0; i < k; i++) lim[v[i].second] = need;

            string t = s;
            vi used(26), pos;

            for (int i = 0; i < n; i++) {
                int c = t[i] - 'a';
                if (used[c] < lim[c]) used[c]++;
                else pos.psb(i);
            }

            int p = 0;
            for (int c = 0; c < 26; c++)
                while (used[c] < lim[c]) {
                    t[pos[p++]] = char('a' + c);
                    used[c]++;
                }

            int diff = 0;
            for (int i = 0; i < n; i++)
                diff += (s[i] != t[i]);

            if (diff < ans) ans = diff, res = t;
        }

        cout << ans << "\n" << res << "\n";
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