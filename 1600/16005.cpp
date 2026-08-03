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

struct ST{
    vi t;
    ST(int n){
        t.assign(4*n+5,0);
    }
    void upd(int v,int l,int r,int idx){
        if(l==r){
            t[v]=1;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) upd(v*2,l,mid,idx);
        else upd(v*2+1,mid+1,r,idx);
        t[v]=t[v*2]+t[v*2+1];
    }
    int qry(int v,int l,int r,int ql,int qr){
        if(qr<l||r<ql) return 0;
        if(ql<=l&&r<=qr) return t[v];

        int mid=(l+r)/2;

        return qry(v*2,l,mid,ql,qr)+qry(v*2+1,mid+1,r,ql,qr);
    }
};

void shiv(){
   int n,m;
        cin>>n>>m;

        vector<pair<int,int>> seg(m);

        for(auto &i:seg)
            cin>>i.first>>i.second;

        int q;
        cin>>q;

        vi pos(q);

        for(int &i:pos)
            cin>>i;

        auto check=[&](int mid){

            ST st(n);

            for(int i=0;i<mid;i++)
                st.upd(1,1,n,pos[i]);

            for(auto [l,r]:seg){
                int one=st.qry(1,1,n,l,r);

                if(one>(r-l+1)/2)
                    return true;
            }

            return false;
        };

        if(!check(q)){
            cout<<-1<<"\n";
            return;
        }

        int l=1,r=q,ans=q;

        while(l<=r){
            int mid=(l+r)/2;

            if(check(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        cout<<ans<<"\n";
    
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
