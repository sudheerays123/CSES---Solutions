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
#define INF 1e18
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

vector<pair<ll,ll>> adj[100005];
vi dist(100005,INF);

void dijkstra(ll s){

    priority_queue<pair<ll,ll>> q;
    vector<bool> visited(100005,false);

    dist[s] = 0;
    q.push({0,s});

    while(!q.empty()){
        ll a = q.top().second;
        q.pop();

        if(visited[a]) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            ll b = u.first;
            ll w = u.second;

            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main() {

    ll n,m;
    cin in n in m;

    fo(i,0,m-1){
        ll u,v,w;
        cin in u in v in w;

        adj[u].pb(mp(v,w));
    }

    dijkstra(1);

    fo(i,1,n) cout out dist[i] spacef;

    return 0;
}
