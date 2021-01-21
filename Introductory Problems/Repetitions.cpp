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
 
    cin in s;
    ll ans = 0;
    for(ll i = 0; i < s.size();){
        char x = s[i];
        ll count = 1;
        i++;
        while(s[i] == x) {
            count++;i++;
        }
        ans = max(ans , count);
    }
 
    cout out ans;
 
    return 0;
}
