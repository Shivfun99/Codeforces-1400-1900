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

 int check(int x, int y) {
    if (x > y) swap(x, y);

    cout << "? " << x << " " << y << endl;

    int a;
    cin >> a;

    if (a == -1) exit(0);

    if (a == x * y) return 0;
    if (a == x * (y + 1)) return 1;
    return 2;
}

void shiv() {
    int l = 2, r = 999;

    while (l < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        int res = check(mid1, mid2);

        if (res == 0) {
            l = mid2 + 1;
        }
        else if (res == 1) {
            l = mid1 + 1;
            r = mid2;
        }
        else {
            r = mid1;
        }
    }

    cout << "! " << l << endl;
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
