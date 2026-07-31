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


ll mergeSort(vector<int> &a) {
    int n = a.size();
    if (n <= 1) return 0;

    int mid = n / 2;

    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    ll inv = mergeSort(left) + mergeSort(right);

    int i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
            inv += left.size() - i;
        }
    }

    while (i < left.size())
        a[k++] = left[i++];

    while (j < right.size())
        a[k++] = right[j++];

    return inv;
}
void shiv(){
         int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        vector<int> sa = a, sb = b;

        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());

        if (sa != sb) {
            cout << "NO\n";
            return;
        }

        ll invA = mergeSort(a);
        ll invB = mergeSort(b);

        if ((invA % 2) == (invB % 2))
            cout << "YES\n";
        else
            cout << "NO\n";
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
