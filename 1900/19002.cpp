#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<string>vstr;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pair<ll, int>> vpli;
typedef vector<pair<int, ll>> vpil;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
#define ppb pop_back
#define psb push_back
#define all(x) (x).begin(), (x).end()
#define rsort(x) sort((x).rbegin(), (x).rend())
// const ll INF = 1e18;
const int INF_INT = 1e9;
const int MOD = 1e9 + 7;
const int mod = 998244353;
const int MAXI = 100000;
// const int maxi = 200005;
const int MAXN = 300005;
const int MAXP = 32000;
const int N = 1e6 + 5;
struct Node {
    ll l, r;
    int id;
};
  

void shiv(){
   int n;
    cin >> n;

    vector<Node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }

    vl L(n, -1), R(n, -1);

    map<pair<ll,ll>, int> freq;

    for (auto &x : a)
        freq[{x.l, x.r}]++;

    sort(a.begin(), a.end(), [](Node &x, Node &y) {
        if (x.l != y.l)
            return x.l < y.l;
        return x.r > y.r;
    });

    set<ll> rights;

    for (auto &x : a) {

        auto it = rights.lower_bound(x.r);

        if (it != rights.end()) {
            R[x.id] = *it;
        }

        rights.insert(x.r);
    }

    sort(a.begin(), a.end(), [](Node &x, Node &y) {
        if (x.r != y.r)
            return x.r > y.r;
        return x.l < y.l;
    });

    set<ll> lefts;

    for (auto &x : a) {

        auto it = lefts.upper_bound(x.l);

        if (it != lefts.begin()) {
            --it;
            L[x.id] = *it;
        }

        lefts.insert(x.l);
    }

    vl ans(n);

    for (auto &x : a) {

        if (freq[{x.l, x.r}] > 1) {
            ans[x.id] = 0;
            continue;
        }

        if (L[x.id] == -1 || R[x.id] == -1) {
            ans[x.id] = 0;
            continue;
        }

        ans[x.id] =
            (x.l - L[x.id]) +
            (R[x.id] - x.r);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    }


int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        shiv();
    }
    return 0;
}
