#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
 
vector<bool> visited(100005);
vi adj[100005];
 
void dfs(ll s){
    if(visited[s] == true) return;
    visited[s] = true;
    for(auto u : adj[s]) dfs(u);
}
 
int main() {
 
    ll n,m;
    cin in n in m;
 
    fo(i,0,m-1){
        ll x,y;
        cin in x in y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
 
    vi nodes(0);
 
    fo(i,0,n-1){
        if(visited[i] == false){
            if(i != 0) nodes.pb(i+1);
            dfs(i);
        }
    }
 
    cout out nodes.size() nextline;
    for(auto node : nodes){
        cout out 1 space node nextline;
    }
 
    return 0;
}
