#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {

    ll n,q;
    cin in n in q;

    vector<vi> pre(n+5,vi(n+5,0));

    fo(i,1,n){
        string s;
        cin in s;
        fo(j,0,n-1){
            if(s[j] == '*') pre[i][j+1] = 1+pre[i-1][j+1]+pre[i][j]-pre[i-1][j];
            else pre[i][j+1] = pre[i-1][j+1]+pre[i][j]-pre[i-1][j];
        }
    }

    while(q--){
        ll a,b,c,d;
        cin in a in b in c in d;
        cout out pre[c][d]+pre[a-1][b-1]-pre[a-1][d]-pre[c][b-1] nextline;
    }

    return 0;
}
