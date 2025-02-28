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

int n,m;
vpi monsters;
vvi g;
map<pi,pi> par;
pi s,e;
vpi moves= {{-1,0}, {1,0}, {0,1}, {0,-1}};

bool isValid(int x,int y,int timer){
    if(!in(x,y,n,m)) rtn 0;
    if(g[x][y]<=timer) rtn 0;
    rtn 1;
}

bool isEscape(int x,int y,int timer){
    if(!isValid(x,y,timer)) rtn 0;
    if(x==0 or y==0 or x==n-1 or y==m-1) rtn 1;
    rtn 0;
}

bool bfs(){
    queue<pair<pi,int>> q;
    q.push(make_pair(s,0));
    par[s]={-1,-1};
    while(!q.empty()){
        int cx= q.front().first.first;
        int cy= q.front().first.second;
        int timer= q.front().ss;
        timer++; q.pop();

        for(auto mv:moves){
            int tx=cx+mv.first;
            int ty = cy+mv.second;
            if(isEscape(tx,ty,timer)){
                par[{tx,ty}]= {cx,cy};
                e= {tx,ty};
                rtn 1;
            }
            if(isValid(tx,ty,timer)){
                par[{tx,ty}] = {cx,cy};
                g[tx][ty] = timer;
                q.push({{tx,ty},timer});
            }
        }
    }
    rtn 0;
}

void preprocess_lava_flow(){
    queue<pair<pi,int>> q;
    for(auto mon:monsters){
        q.push({mon,0});
    }
    while(!q.empty()){
        int cx= q.front().ff.ff;
        int cy= q.front().ff.ss;
        int timer= q.front().ss;
        timer++; q.pop();

        for(auto mv:moves){
            int tx= cx+mv.ff;
            int ty =cy + mv.ss;
            if(isValid(tx,ty,timer)){
                g[tx][ty]= timer;
                q.push({{tx,ty},timer});
            }
        }
    }
}



int32_t main(){
    hurry_up
    
    cin>>n>>m;
    g.resize(n);
    loop(i,0,n)
        g[i].resize(m);
    
    loop(i,0,n)loop(j,0,m){
        g[i][j] = INT_MAX;
    }

    loop(i,0,n)loop(j,0,m){
        char ch;cin>>ch;
        if(ch=='#') g[i][j]=0;
        else if(ch=='M'){
            g[i][j]=0;
            monsters.emplace_back(i,j);
        }else if(ch=='A'){
            g[i][j]=0;
            s={i,j};
        }else{
            g[i][j] = INT_MAX;
        }
    }

    if(s.ff==0 or s.ss==0 or s.ff==n-1 or s.ss== m-1){
        outln("YES");
        outln(0);
        rtn 0;
    }

    preprocess_lava_flow();

    if(!bfs()){
        outln("NO");
        rtn 0;
    }
    outln("YES");
    pi tmp=e;
    pi tmp1= par[tmp];
    pi end={-1,-1};
    vc ans;

    while(tmp1!=end){
        if((tmp.ss-tmp1.ss==1) and (tmp.ff-tmp1.ff==0) ) ans.emplace_back('R');
        if((tmp.ss-tmp1.ss==-1) and (tmp.ff-tmp1.ff==0) ) ans.emplace_back('L');
        if((tmp.ss-tmp1.ss==0) and (tmp.ff-tmp1.ff==1) ) ans.emplace_back('D');
        if((tmp.ss-tmp1.ss==0) and (tmp.ff-tmp1.ff==-1) ) ans.emplace_back('U');

        tmp=par[tmp];
        tmp1=par[tmp];
    }

    reverse(all(ans));
    outln(ans.sz);
    for(auto c:ans) cout<<c;
    ln();
    
    rtn 0;
}
