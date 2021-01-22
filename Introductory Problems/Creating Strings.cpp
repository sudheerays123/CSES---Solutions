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
 
ll fact(ll n){
 
    ll res = 1;
    fo(i,2,n) res = res * i;
 
    return res;
}
 
int main() {
 
    string x;
    cin in x;
 
    vector<char> s;
 
    ll ans = x.size();
    ans = fact(ans);
 
    unordered_map<char,ll> m;
 
    for(auto i : x) {
        s.pb(i);
        m[i]++;
    }
 
    for(auto i : m){
        if(i.second == 1) continue;
        ans /= fact(i.second);
    }
 
    cout out ans nextline;
 
    sort(s.begin(),s.end());
    print(s);
    cout nextline;
 
    while(next_permutation(s.begin(),s.end())){
        print(s);
        cout nextline;
    }
 
    return 0;
}
