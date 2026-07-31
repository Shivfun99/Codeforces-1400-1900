//https://codeforces.com/problemset/problem/2217/G
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

  
int add(int a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
    return a;
}

int subb(int a,int b){
    a-=b;
    if(a<0) a+=MOD;
    return a;
}

int mul(ll a,ll b){
    return a*b%MOD;
}

int power(int a,long long e){
    int r=1;
    while(e){
        if(e&1) r=mul(r,a);
        a=mul(a,a);
        e>>=1;
    }
    return r;
}

void shiv(){
  
    }


int main(){
     int T;
    cin>>T;

    vector<pair<int,int>> query(T);

    int mx=0;

    for(int i=0;i<T;i++){
        cin>>query[i].first>>query[i].second;
        mx=max(mx,query[i].first);
    }

    int LIM=2*mx+5;

    vi fact(LIM),invFact(LIM),inv(mx+5),cat(mx+5);

    fact[0]=1;
    for(int i=1;i<LIM;i++)
        fact[i]=mul(fact[i-1],i);

    invFact[LIM-1]=power(fact[LIM-1],MOD-2);

    for(int i=LIM-2;i>=0;i--)
        invFact[i]=mul(invFact[i+1],i+1);

    inv[1]=1;
    for(int i=2;i<=mx+1;i++)
        inv[i]=MOD-(ll)(MOD/i)*inv[MOD%i]%MOD;

    for(int i=0;i<=mx;i++){
        cat[i]=mul(
            mul(fact[2*i],invFact[i]),
            mul(invFact[i],inv[i+1])
        );
    }

    auto C=[&](int n,int r)->int{

        if(r<0||r>n) return 0;

        return mul(fact[n],mul(invFact[r],invFact[n-r]));
    };

    vi pre1(mx+1),pre2(mx+1);

    auto calc=[&](int N,int A)->int{

        if(A<0) return 0;

        pre1[0]=1;

        for(int i=1;i<=N;i++){

            pre1[i]=subb(add(pre1[i-1],pre1[i-1]),C(i-1,A));

        }

        long long ans=0;

        for(int i=0;i<=N;i++){

            ans+=1LL*cat[i]*cat[N-i]%MOD*pre1[i]%MOD*pre1[N-i]%MOD;

            ans%=MOD;
        }

        return ans%MOD;
    };

    for(auto [n,k]:query){

        int N=n-1;

        cout<<subb(calc(N,k),calc(N,k-2))<<"\n";
    }

    return 0;
}
