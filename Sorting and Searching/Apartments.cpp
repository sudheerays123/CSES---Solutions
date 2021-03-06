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
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

   ll n,m,k;
   cin in n in m in k;

   vi needed(n+5);
   multiset<ll> apartment;

   fo(i,0,n-1){
        cin in needed[i];
   }

   sort(needed.begin(),needed.begin()+n);

    ll ans = 0;

   fo(i,1,m){
       ll x;
       cin in x;
       apartment.insert(x);
   }

   fo(i,0,n-1){
       auto low = apartment.lower_bound(needed[i]-k);
       if(low != apartment.end() && *low <= needed[i]+k){
           ans++;
           apartment.erase(low);
       }
   }

    cout out ans;

    return 0;
}
