//shedule management 
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

vi fr;//prof in i 
bool check(int n,int m ,int t){
    ll possible=0;
    for(int i=0;i<n;i++){
        if(fr[i]>t){
            possible+=t;
        }
        else{
            possible+=fr[i];
            int remtime=t-fr[i];
            possible+=remtime/2;
        }
    }
    return possible>=m;
}
int bs(int n,int m){
    int l=0;
    int h=2*m;
    while(l<h){
        int mid=l+(h-l)/2;
        if(check(n,m,mid)){
            h=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
void shiv(){
  int n,m;
  cin>>n>>m;
  fr.assign(n,0);

  for(int i=0;i<m;i++){
    int x;cin>>x;

    fr[x-1]++;
  }
  cout<<bs(n,m)<<endl;

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