#include <iostream>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
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

   ll n,a;
   cin in n in a;

   vi v(n+5);
   fo(i,0,n-1) cin in v[i];

   vi dp(n+5);
   vi mdp(n+5);

   // dp[i] = maximum number of coins we can collect if we take the ith

   // base case :

   fo(i,0,a) {
       dp[i] = v[i];
       mdp[i] = max(mdp[i-1],dp[i]);
   }

   // recurrence relation :

   fo(i,a+1,n-1){
       dp[i] = v[i]+mdp[i-a-1];
       mdp[i] = max(mdp[i-1],dp[i]);
   }

   // answer :

   ll ans = -INF;

   fo(i,n-a-1,n-1) mmax(ans,dp[i]);

   cout out ans;

   return 0;

}
