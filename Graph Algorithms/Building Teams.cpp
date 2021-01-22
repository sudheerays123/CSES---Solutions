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

vi adj[100005];
vector<bool> visited(100005);
vi ans(100005,INF);
bool pos = true;

void dfs(ll s){
    if(visited[s] == true) return;
    visited[s] = true;

    for(auto u : adj[s]) {
        if ((visited[u] == false && ans[s] == 2 && ans[u] == 2) || (visited[u] == false && ans[s] == 1 && ans[u] == 1)) {
            pos = false;
            return;
        }
    }

    for(auto u : adj[s]){
        if(visited[u] == true || ans[u] != INF) continue;
        if(ans[s] == 1) ans[u] = 2;
        else ans[u] = 1;
    }

    for(auto u : adj[s]){
        dfs(u);
    }
}

int main() {

    ll n,m;
    cin in n in m;

    fo(i,0,m-1){
        ll a,b;
        cin in a in b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    fo(i,0,n-1){
        if(visited[i] == false){
            ans[i] = 1;
            dfs(i);
        }
    }

    if(pos == true ) fo(i,0,n-1) cout out ans[i] spacef;
    else cout out "IMPOSSIBLE\n";

    return 0;
}
