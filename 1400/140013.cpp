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
    int n,k;
    cin>>n>>k;
    vi arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=0,cnt=0;
    int l=0,r=0; //for window
    while(r<k){// subar o to k-1
        if(arr[r]<2*arr[r+1]) cnt++;// condition 
        r++;
    }
    //slide window over all 
    while(r<n-1){
        if(cnt==k) ans++;
        if(arr[l]<2*arr[l+1]) cnt--;//remove leftmost comp
        if(arr[r]<2*arr[r+1]) cnt++;//add next comp on //right 
        l++;
        r++;
    }
    //last window
    if(cnt==k) ans++;

    cout<<ans<<endl;

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

/*
git add .
git commit -m "added solutions"
git push
*/