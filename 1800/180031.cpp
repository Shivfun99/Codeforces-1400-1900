// #include<bits/stdc++.h>
// using namespace std;
// #define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<char> vc;
// typedef vector<bool> vb;
// typedef vector<ll> vl;
// typedef vector<string>vstr;
// typedef vector<vector<int>> vvi;
// typedef vector<vector<ll>> vvl;
// typedef vector<pair<ll, int>> vpli;
// typedef vector<pair<int, ll>> vpil;
// typedef vector<pair<int, int>> vpii;
// typedef vector<pair<ll, ll>> vpll;
// #define ppb pop_back
// #define psb push_back
// #define all(x) (x).begin(), (x).end()
// #define rsort(x) sort((x).rbegin(), (x).rend())
// // const ll INF = 1e18;
// const int INF_INT = 1e9;
// const int MOD = 1e9 + 7;
// const int mod = 998244353;
// const int MAXI = 100000;
// // const int maxi = 200005;
// const int MAXN = 300005;
// const int MAXP = 32000;
// const int N = 1e6 + 5;

// // brute
// void shiv(){
//     int n,m;
//     cin>>n>>m;
//     vl arr(n);
//     set<ll>occupied;

//     for(auto &i:arr){
//         cin>>i;
//         occupied.insert(i);
//     }
//     vl ans;
//     ll sum=0;
    
//     for(ll d=1;ans.size()<m;d++){
//         for(int i=0;i<n && ans.size()<m;i++){
//             ll left=arr[i]-d;
//             if(!occupied.count(left)){
//                 occupied.insert(left);
//                 ans.psb(left);
//                 sum+=d;
//             }
//             if(ans.size()==m) break;

//             ll right=arr[i]+d;
//             if(!occupied.count(right)){
//                 occupied.insert(right);
//                 ans.psb(right);
//                 sum+=d;
//             }
//         }
//     }
//     cout<<sum<<endl;
//     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

//     }


// int main(){
//     fastio;
//     // int t;
//     // cin>>t;
//     // while(t--){
//         shiv();
//     // }
//     return 0;
// }
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
 int n,m;
    cin>>n>>m;

    set<ll> occupied;
    queue<pair<ll,ll>> q;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;

        occupied.insert(x);
        q.push({x,0});
    }

    vl ans;
    ll sum=0;

    while(ans.size()<m){

        auto [x,d]=q.front();
        q.pop();

        ll left=x-1;

        if(!occupied.count(left)){
            occupied.insert(left);
            ans.psb(left);
            sum+=d+1;

            q.push({left,d+1});

            if(ans.size()==m)
                break;
        }

        ll right=x+1;

        if(!occupied.count(right)){
            occupied.insert(right);
            ans.psb(right);
            sum+=d+1;

            q.push({right,d+1});
        }
    }

    cout<<sum<<'\n';

    for(auto x:ans)
        cout<<x<<" ";
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