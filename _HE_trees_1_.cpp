#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
using namespace std;

typedef                 unsigned long long ull;
typedef                 long double lld;

#define ff              first
#define ss              second
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

#define fi(a,b,step)   for( ll i = a; i < b; i+=step)
#define fj(a,b,step)   for( ll j = a; j < b; j+=step)
#define fr(var,a,b,step)   for( ll var = a; var < b; var+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(ll t)     { cerr << t ; }
void _print(int t)    { cerr << t ; }
void _print(string t) { cerr << t ; }
void _print(char t)   { cerr << t ; }
void _print(lld t)    { cerr << t ; }
void _print(double t) { cerr << t ; }
void _print(ull t)    { cerr << t ; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//---------------------------------------------------------------------------
void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

vector<int>adj_list[100000];
class graph_ {

public:
   int N;
   string nodes;
   // vector<int>*adj_list;
   graph_(int n) {
      N = n;
      // adj_list = new vector<int>[n];
   }

   void addEdge(int x, int y) {
      adj_list[x].pb(y);
      adj_list[y].pb(x);
      return;
   }

   void dfs(int src, bool *visited, ll currLen, ll &totalLen, ll &node_farthest) {

      if (visited[src]) return;

      visited[src ] = 1;

      if (totalLen < currLen) {
         node_farthest = src;
         totalLen = currLen;
      }

      for (auto neighbour : adj_list[src]) {
         if (!visited[neighbour])dfs(neighbour, visited, currLen + 1, totalLen, node_farthest);
      }

      return;
   }


   void findLargestCycle() {

      bool visited[N + 1];
      // int visited[N + 1];
      memset(visited, false, sizeof(visited));

      ll totalLen = -1;
      ll node_farthest;
      ll currLen = 1;
      dfs(1, visited, currLen, totalLen, node_farthest);

      cout << node_farthest << " ";
      currLen = 1;
      totalLen = -1;
      memset(visited, false, sizeof(visited));

      dfs(node_farthest, visited, currLen, totalLen, node_farthest);

      cout << node_farthest << " ";
   }

   void dfs2(int node_, char data, bool *visited, int &ans) {
      // cout << node_ << " ";
      if (visited[node_] )return;

      if (nodes[node_ - 1] == data) {
         ans++;
      }
      visited[node_] = 1;
      for (auto neighbour : adj_list[node_]) {
         if (!visited[neighbour])dfs2(neighbour, data, visited, ans);
      }
      return;
   }

   void dfs3(int src, int parent, vector<vector<int>>&freq_) {

      // if (visited[src])return;

      freq_[src][ nodes[src - 1] - 'a' ]++;

      // visited[src] = 1;

      for (auto neighbour : adj_list[src]) {

         if (neighbour == parent)continue;

         // if (!visited[neighbour]) {
         dfs3(neighbour, src, freq_);
         for (int i = 0 ; i < 26 ; i++) {
            freq_[src][  i ] += freq_[neighbour][ i ];
         }
         // }
      }

      return;
   }

   void findSubTree(int q) {

      // bool visited[N + 1];
      // memset(visited, false, sizeof(visited));

      vector<vector<int>>freq_(N + 1, vector<int>(26, 0));

      dfs3(1, -1, freq_);

      while (q--) {
         int n ;
         char ch;
         cin >> n >> ch;
         cout << freq_[n][ch - 'a'] << '\n' ;

      }
      return;
   }

   void dfs4( int node , int parent, int color , int *parents, int *colors ) {

      if (node == 1) {
         cout << "-1 ";
         return;
      }
      // cout << parent << " " ;
      if (colors[parent] == color) {
         cout << parent << " ";
         return;
      }

      dfs4(parent, parents[parent - 1], color, parents, colors);
      return;
   }

   void colorTree(int n, int c) {

      int colors[n + 1] , parents[n + 1];
      parents[0] = -1;
      // bool visited[n + 1];
      // memset(visited, false, sizeof(visited));

      fr(i, 1, n , 1) {
         cin >> parents[i];
      }

      fr(i, 1, n + 1, 1) {
         cin >> colors[i];
      }
      // cout << n;
      for (int i = 1 ; i <= n ; i++) {

         if (i == 1) {
            cout << "-1 ";
         }
         else {
            dfs4( i , parents[i - 1] , colors[i] , parents, colors);
         }
      }

   }
};


void solve() {

   // largest cycle in a tree :

   int n , c;
   cin >> n >> c;
   graph_ g1(n);
   // cin >> g1.nodes;
   // n--;
   // while (n--) {
   //    int a, b;
   //    cin >> a >> b;
   //    g1.addEdge(a, b);
   // }
   // cout << "Hi";
   // g1.findLargestCycle();
   // g1.findSubTree(q);
   g1.colorTree(n, c);


   return;
}


int main() {

   fastInput();

   ll t = 1;
   // cin>>t;
   while (t--) {
      solve();
      // cout << "solve";
   }

   return 0;


}


#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n;
   int width[n + 1] , leftHmax[n + 1] , rightHmax[n + 1] , num = -1 , height[n + 1];
   int N = n , i = 0 , sum = 0;
   while (N--) {
      int w, h;
      cin >> w >> h;
      if (i == 0)leftHmax[i] = h;
      else leftHmax[i] = max(leftHmax[i], leftHmax[i - 1]);
      width[i] = w;
      height[i] = h;
      sum += w;
      i++;
   }

   for (int i = n - 1 ; i >= 0  ; i--) {
      if (i == n - 1)rightHmax[i] = height[i];
      else rightHmax[i] = max(rightHmax[i], rightHmax[i + 1]);
   }

   for (int i = 0 ; i < n ; i++) {

      if (i == 0) {
         cout << ( sum - width[i] ) * ( rightHmax[i + 1] ) << " " ;
      } else if ( i == n - 1) {
         cout << ( sum - width[i] ) * ( leftHmax[i - 1] ) << " " ;
      } else {
         cout << ( sum - width[i] ) * ( max(rightHmax[i + 1] , leftHmax[i - 1] )  ) << " " ;
      }

   }

   return 0;
}
