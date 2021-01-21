#include<iostream>
#include <vector>
using namespace std;
#define ll long long int
#define in >>
#define out <<
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tc ll test; cin in test; while(test--)
#define ff first
#define ss second
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define MOD 20011
 
ll n,m;
vector<vector<char>> grid(1000+5 , vector<char>(1000+5));
vector<vi> visited(1000+5 , vi(1000+5,0));
 
void dfs(ll x , ll y){
 
    if(visited[x][y] == 1) return;
    visited[x][y] = 1;
 
    if(x != 0 && grid[x-1][y] == '.') dfs(x-1 , y);
    if(x != n-1 && grid[x+1][y] == '.') dfs(x+1 , y);
    if(y != m-1 && grid[x][y+1] == '.') dfs(x , y+1);
    if(y != 0 && grid[x][y-1] == '.') dfs(x , y-1);
}
 
int main(){
 
    fast;
 
    cin in n in m;
 
    fo(i,0,n-1){
        fo(j,0,m-1){
            cin in grid[i][j];
        }
    }
 
    ll cnt = 0;
 
    fo(i,0,n-1){
        fo(j,0,m-1){
            if(visited[i][j] == 1 || grid[i][j] == '#') continue;
            cnt++;
            dfs(i,j);
        }
    }
 
    cout out cnt;
 
    return 0;
}
