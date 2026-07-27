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
    int n; cin>>n;
    int U,v;
    vi deg(n,0);

    for(int i=0;i<n-1;i++){
        cin>>U>>v;
        --U, --v;
		deg[U]++;
		deg[v]++;
    }
    string s;
    cin>>s;
    int z=0,o=0,q=0,u=0;
    //q == ? , u= internal ?
    for(int i=1;i<n;++i){
        if(deg[i]==1){
            if(s[i]=='0')++z;
            else if(s[i]=='1') ++o;
            else ++q;
        }
        else{
            if(s[i]=='?') ++u;
        }
    }
if(s[0]!='?') cout<<((s[0]=='1' ? z:o)+(q+1)/2)<<endl;
else{
    if(z==o &&(u%2==1)) cout<<(z+(q+1)/2)<<endl;
    else cout<<(max(z,o)+q/2)<<endl;
}
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
