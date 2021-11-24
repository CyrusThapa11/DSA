
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define debug(x) cout<<#x<<" "<<x<<endl;

//----------------------------------------------------------------------------------


using namespace std;

void init_code() {
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

int setBit(int i , int n ) {
   // mask -> or
   int mask = 1 << i;
   return n | mask;
}

int getBit(int i , int n) {
   // mask -> and
   int mask = 1 << i;
   return n & mask;
}

int clearBit(int i , int n) {
   // mask -> invert -> and
   int mask = 1 << i;
   mask = ~mask;
   return n & mask;
}

int updateBit(int i , int n , int value) {
   // mask -> invert -> and -> or
   int mask = 1 << i;
   int mask2 =  value << i ;
   mask = ~mask;
   int clearedBit = n & mask;
   return clearedBit | mask2  ;
}


int main() {
   init_code();
   int t = 1;
   // cin >> t;
   while (t--) {

      int n = 5;
      cout << endl << setBit(1, n) << endl;
      cout << endl << getBit(1, n) << endl;
      cout << endl << clearBit(1, n) << endl;
      cout << endl << clearBit(1, n , 0) << endl;
      cout << endl << updateBit(1, n , 0) << endl;

   }
   return 0;
}
