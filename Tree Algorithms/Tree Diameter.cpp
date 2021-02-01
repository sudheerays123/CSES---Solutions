#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vector<bool> visited(200005);
ll maxdist1 = -INF, maxdistpos;
vi adj[200005];

void dfs(ll s , ll dist){
    if(visited[s]) return;
    visited[s] = true;

    if(dist > maxdist1){
        maxdist1 = dist;
        maxdistpos = s;
    }

    for(auto u : adj[s]) dfs(u,dist+1);

}

int main() {

    ll n;
    cin in n;

    fo(i,0,n-2){
        ll a,b;
        cin in a in b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1,0);
    maxdist1 = -INF;
    visited.clear();
    visited.resize(n+5);
    dfs(maxdistpos,0);
    cout out maxdist1;

    return 0;
}
