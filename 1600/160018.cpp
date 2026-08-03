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

  
const int MAX=1000;
vi dist(MAX+1,INF_INT);

void precom(){
    dist[1]=0;
    for(int i=1;i<=MAX;i++){
        for(int x=1;x<=i;x++){
            int nxt=i+i/x;
            if(nxt<=MAX) dist[nxt]=min(dist[nxt],dist[i]+1);
        }
    }
}

void shiv(){
  
    int n,k; cin>>n>>k;
    vi brr(n),crr(n);
    for(int i=0;i<n;i++) cin>>brr[i];
    for(int i=0;i<n;i++) cin>>crr[i];
    // cout<<powerSum(n)<<endl;
    k=min(k,12000);
    vl dp(k+1,0);
    for(int i=0;i<n;i++)
        {
            int weight=dist[brr[i]];
            int value=crr[i];

            for(int j=k;j>=weight;j--)
            {
                dp[j]=max(dp[j],dp[j-weight]+value);
            }
        }

        cout<<*max_element(dp.begin(),dp.end())<<"\n";


    }


int main(){
    
    fastio;
    precom();
    int t;
    cin>>t;
    while(t--){
        shiv();
    }
    return 0;
}
