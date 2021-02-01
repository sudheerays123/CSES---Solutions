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

vi adj[100005];
vi dist(100005,INF);
vi parent(100005);

void dijkstra(ll s){

    priority_queue<pair<ll,ll>> q;
    vector<bool> visited(100005,false);

    dist[s] = 1;
    q.push({1,s});

    while(!q.empty()){
        ll a = q.top().second;
        q.pop();

        if(visited[a]) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            if(dist[a] + 1 < dist[u]){
                dist[u] = dist[a] + 1;
                q.push({-dist[u],u});
                parent[u] = a;
            }
        }
    }
}
int main() {

    ll n,m;
    cin in n in m;

    fo(i,0,m-1){
        ll u,v;
        cin in u in v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dijkstra(1);

    if(dist[n] != INF) {
        cout out dist[n] nextline;
        vi path(0);
        path.pb(n);
        ll last = n;
        while(last != 1){
            last = parent[last];
            path.pb(last);
        }
        for(ll i = path.size()-1; i >= 0; i--) cout out path[i] spacef;

    }
    else cout out "IMPOSSIBLE";

    return 0;
}
