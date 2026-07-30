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

  

void shiv(){
    string s;
        cin >> s;

        ll pos;
        cin >> pos;

        ll n =s.size();
        string stk;
        stk.reserve(s.size());

        for(char c:s){
            while(!stk.empty()&& stk.back()>c && pos>n){
                stk.ppb();
                pos-=n;--n;
            }
            stk.psb(c);
        }
        while(pos>n){
            stk.ppb();
            pos-=n;
            --n;
        }

        cout << stk[size_t(pos) - 1];
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
