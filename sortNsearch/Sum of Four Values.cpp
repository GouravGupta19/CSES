/*
Author: gourav_27
*/

#include<bits/stdc++.h>
using namespace std;

#define hurry_up ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define int long long int

#define ll long long
#define dd long double
#define sz size()
#define rtn return
#define rnt return
#define ff first
#define ss second
#define endl '\n'
#define nl '\n'
#define TCS  ll T;cin>>T;while(T--)

inline void ln(){cout<<'\n';}
template<typename X> inline void outln(X x){ cout<<x<<'\n';}
template<typename X> inline void out(X x){ cout<<x<<' ';}

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vl vector<ll>
#define vvl vector<vl>
#define vd vector<dd>
#define vvd vector<vd>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vb>

#define pi pair<int,int>
#define vpi vector<pi>
#define pl pair<ll,ll>
#define vpl vector<pl>

#define loop(i,a,b)         for(int i=a;i<b;i++)     //for loop from a(included)->b(included)
#define roop(i,b,a)         for(int i=b;i>=a;i--)    //rev. for loop from b(included)->a(inluded)
#define all(x)              x.begin(),x.end()
#define sortAll(x)          sort(all(x));            //sort in ascending
#define tr(it,a)            for(auto it=a.begin();it!=a.end();it++)   // to iterate in something named a
#define rtr(it,a)           for(auto it=a.rbegin();it!=a.rend();it--)   // to iterate in something named 
#define inp(a,n)            for(int i=0;i<n;i++) cin>>a[i]
#define inp_vec(vec, n)     for(int i=0;i<n;i++) {int x;cin>>x;vec.push_back(x);}
#define inp_mat(mat, n, m)  for(int i=0;i<n;i++) {for(int j=0;j<m;j++) {int x;cin>>x;mat[i][j]=x;}}

// ================================== take ip/op like vector directly!==================================
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename T> ostream &operator<<(ostream& cout,const vector<pair<T,T>> &v){ int n= v.size(); if(!n){ return cout;} cout<<"{ "<<v[0].first<<" , "<<v[0].second<<" } "; for(int i=1;i<n;i++){ cout<<",{ "<<v[i].first<<" , "<<v[i].second<<" } "; } return cout; }
// ===================================END Of the inp/op module ==========================================

//===================min-max====================
template<typename T> T _max(T a,T b){ rtn (a>b)? (a):(b); }
template<typename T> T _min(T a,T b){ rtn (a<b)? (a):(b); }
//=================end of min-max=================

//===================floor-ciel===================
template<typename T>
T cl(T num,T k){
    if(num==0) rnt 0;
    else if(num>0){
        rtn (num+k-1)/k;
    }else{ //-ve
        rtn -1*(abs(num)/k);
    }
}
template<typename T>
T fl(T num,T k){
    if(num==0) rnt 0;
    else if(num>0){
        rtn (num/k);
    }else{ //-ve
        rtn -1*((abs(num)+k-1)/k);
    }
}
//===============end of floor-ciel===================

//=================Maths================================
int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b; 
}
//======================================================

//================BIT MANIPULATION=========================================
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))
//==========================================================================

//=============================strings=============================
bool isSubstring(const string& substring, const string& mainStr) {
    return mainStr.find(substring) != string::npos;
}
//=================================================================

//===============================modular arithmetic====================
const int mod=1000000000+7;
    
ll mod_pow(ll a,ll b){
    if(b==0) return 1;
    if(b%2){
        return a* mod_pow(a,b-1) %mod;
    }
    ll temp= mod_pow(a,b/2);
    return temp*temp %mod;
}
ll mod_mul(ll a,ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll mod_add(ll a,ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll mod_sub(ll a, ll b){
    return ((a - b) % mod + mod) % mod;
}
ll mod_inv(ll a,ll b=mod-2){
    return mod_pow(a,b);
}
ll mod_div(ll a,ll b){
    int invb=mod_inv(b);
    return mod_mul(a,invb);
}
//=============================================================================


int dr[]={-1,0,1,0}; //up,left,down,right
int dc[]={0,-1,0,1};
bool in(int i,int j,int n,int m){
    rtn (i>=0 && i<n && j>=0 && j<m);
}



void solve(){
    int n,x; cin>>n>>x;
    vi a(n); cin>>a;

    map<int, vpi> mp;
    loop(i,0,n){
        loop(j,i+1,n){
            mp[a[i]+a[j]].emplace_back(i,j);
        }
    }

    for(auto& it:mp){
        int sum=it.ff;
        vpi& vec=it.ss;
        int comp=x-sum;
        if(mp.count(comp)){
            for(auto& p1:vec){
                for(auto& p2:mp[comp]){
                    if (p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second) {
                        cout << p1.first + 1 << " " << p1.second + 1 << " "
                             << p2.first + 1 << " " << p2.second + 1 << "\n";
                        return;
                    }
                }
            }
        }
    }
    
    outln("IMPOSSIBLE");
}

int32_t main(){
    hurry_up

    solve();
    
    rtn 0;
}
