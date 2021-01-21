#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp pake_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
 
string s;
 
int main() {
 
    fast;
 
    ll n;
    cin in n;
    vi a(n+5);
    fo(i,0,n-1) cin in a[i];
    ll cnt = 0;
 
    fo(i,1,n-1) {
        if(a[i] < a[i-1]) {
            cnt += abs(a[i] - a[i-1]);
            a[i] = a[i-1];
        }
    }
    cout out cnt;
 
    return 0;
