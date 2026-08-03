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

const int MAXA = 300000;

int n, s, t;
vi a;
vi spf;

vvi factors;
vvi primeNodes;

vi parent;
vb visSpider;
vb visPrime;

void buildSPF() {
    spf.resize(MAXA + 1);

    for (int i = 0; i <= MAXA; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vi getPrimeFactors(int x) {

    vi primes;

    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);

        while (x % p == 0)
            x /= p;
    }

    return primes;
}

void buildGraphInfo() {

    factors.assign(n + 1, {});
    primeNodes.assign(MAXA + 1, {});

    for (int i = 1; i <= n; i++) {

        factors[i] = getPrimeFactors(a[i]);

        for (int p : factors[i])
            primeNodes[p].push_back(i);
    }
}

void bfs() {

    parent.assign(n + 1, -1);
    visSpider.assign(n + 1, false);
    visPrime.assign(MAXA + 1, false);

    queue<int> q;

    q.push(s);
    visSpider[s] = true;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        if (u == t)
            return;

        for (int p : factors[u]) {

            if (visPrime[p])
                continue;

            visPrime[p] = true;

            for (int v : primeNodes[p]) {

                if (visSpider[v])
                    continue;

                visSpider[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

vi getPath() {

    vi path;

    if (!visSpider[t])
        return path;

    int cur = t;

    while (cur != -1) {
        path.psb(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    return path;
}

void shiv(){
  cin >> n;

    a.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> s >> t;

    if (s == t) {
        cout << 1 << "\n";
        cout << s << "\n";
        return;
    }

    buildSPF();
    buildGraphInfo();
    bfs();

    vi path = getPath();

    if (path.empty()) {
        cout << -1 << "\n";
        return;
    }

    cout << path.size() << "\n";

    for (int x : path)
        cout << x << " ";
    }


int main(){
    // fastio;
    // int t;
    // cin>>t;
    // while(t--){
        shiv();
    // }
    return 0;
}
