#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 505

ll n;
vector<vi> dist(N,vi(N,INF));

void bellmanFord(){

    fo(i,1,n) dist[i][i] = 0;

    fo(k,1,n){
        fo(i,1,n){
            fo(j,1,n){
                mmin(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

}

int main() {

    fast;

    ll m,q;
    cin in n in m in q;

    fo(i,0,m-1){

        ll a,b,c;
        cin in a in b in c;

        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    bellmanFord();

    while(q--){

        ll a,b;
        cin in a in b;

        ll d = dist[a][b];

        if(d == INF) cout out "-1\n";
        else cout out d nextline;
    }

    return 0;
}
