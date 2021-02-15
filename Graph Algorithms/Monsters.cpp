#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 13371337
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 1005

ll n,m;
vector<vector<char>> grid(N,vector<char>(N));
vector<vi> monster(N,vi(N,INF));

vi dx = {0,-1,0,+1};
vi dy = {-1,0,+1,0};

void Monsters(){

    queue<pair<ll,ll>> q;

    fo(i,1,n){
        fo(j,1,m){
            if(grid[i][j] == 'M') {
                q.push({i,j});
                monster[i][j] = 0;
            }
        }
    }

    while(!q.empty()){

        ll x = q.front().first;
        ll y = q.front().second;

        q.pop();

        fo(t,0,3){
            ll i = x + dx[t];
            ll j = y + dy[t];

            if(i >= 1 && i <= n && j >= 1 && j <= m && grid[i][j] != '#' && monster[i][j] > monster[x][y] + 1){
                monster[i][j] = monster[x][y] + 1;
                q.push({i,j});
            }
        }
    }

}

ll mex , mey;
vector<vi> me(N,vi(N,INF));
vector<vector<char>> parent(N,vector<char>(N));

void bfs(ll startx , ll starty){

    queue<pair<ll,ll>> q;

    q.push({startx,starty});
    me[startx][starty] = 0;
    parent[startx][starty] = 'N';

    while(!q.empty()){

        ll x = q.front().first;
        ll y = q.front().second;

        q.pop();

        fo(d,0,3){

            ll i = x + dx[d];
            ll j = y + dy[d];

            if(i >= 1 && i <= n && j >= 1 && j <= m && grid[i][j] == '.' && me[i][j] > me[x][y] + 1){
                me[i][j] = me[x][y] + 1;
                q.push({i,j});

                if(d == 0) parent[i][j] = 'L';
                if(d == 1) parent[i][j] = 'U';
                if(d == 2) parent[i][j] = 'R';
                if(d == 3) parent[i][j] = 'D';
            }
        }

    }
}


int main() {

    fast;

    cin in n in m;

    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];

            if(grid[i][j] == 'A'){
                mex = i;
                mey = j;
            }
        }
    }

    Monsters();

    bfs(mex , mey);

    ll ans = INF;
    ll endx , endy;

    fo(j,1,m) {
        if(me[1][j] < monster[1][j] ){
            if(me[1][j] <= ans){
                ans = me[1][j];
                endx = 1;
                endy = j;
            }
        }
    }

    fo(j,1,m) {
        if(me[n][j] < monster[n][j] ){
            if(me[n][j] <= ans){
                ans = me[n][j];
                endx = n;
                endy = j;
            }
        }
    }

    fo(i,1,n) {
        if(me[i][1] < monster[i][1] ){
            if(me[i][1] <= ans){
                ans = me[i][1];
                endx = i;
                endy = 1;
            }
        }
    }

    fo(i,1,n) {
        fo(i,1,n) {
            if(me[i][m] < monster[i][m] ){
                if(me[i][m] <= ans){
                    ans = me[i][m];
                    endx = i;
                    endy = m;
                }
            }
        }
    }

    if(ans == INF) {
        cout out "NO";
        return 0;
    }

    cout out "YES\n";
    cout out ans nextline;

    vector<char> path(0);
    char lastc = 'Q';
    ll lastx = endx;
    ll lasty = endy;

    while(lastc != 'N'){

        lastc = parent[lastx][lasty];

        if(lastc != 'N') path.pb(lastc);

        if(lastc == 'L') lasty++;
        if(lastc == 'R') lasty--;
        if(lastc == 'U') lastx++;
        if(lastc == 'D') lastx--;
    }


    reverse(path.begin(),path.end());
    print(path);

    return 0;
}
