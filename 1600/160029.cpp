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

const int MAX = 200000;

vector<int> spf(MAX + 1);
vector<vector<int>> expo(MAX + 1);

//spf
void buildSPF() {

    for(int i = 0; i <= MAX; i++)
        spf[i] = i;
    for(int i = 2; i * i <= MAX; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= MAX; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void factorize(int x) {
    while(x > 1) {

        int p = spf[x];
        int cnt = 0;

        while(x % p == 0) {
            cnt++;
            x /= p;
        }

        expo[p].psb(cnt);
    }
}

void shiv(){
   buildSPF();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        factorize(x);
    }

    ll ans = 1;

    for(int p = 2; p <= MAX; p++) {

        if(expo[p].empty())
            continue;

        int missing = n - expo[p].size();

if(missing >= 2)
    continue;

if(missing == 1) {
    int mn = *min_element(expo[p].begin(), expo[p].end());
    while(mn--) ans *= p;
}
else {
    nth_element(expo[p].begin(),
                expo[p].begin() + 1,
                expo[p].end());

    int second = expo[p][1];
    while(second--) ans *= p;
}

    }

    cout << ans << "\n";
    }



int main(){
    fastio;
    // int t;
    // cin>>t;
    // while(t--){
        shiv();
    // }
    return 0;
}
