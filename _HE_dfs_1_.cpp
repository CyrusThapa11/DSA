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
#include<list>
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

class graph_1 {
   int N;
   unordered_map<int, vector<pair<int, int>>>mapp_;
   unordered_map<int, vector<int>>mapp_2;

public:
   graph_1() {}
   graph_1(int n) {
      N = n;
   }

   void addEdge(int u , int v) {
      mapp_[u].push_back({v, INT_MAX});
      mapp_[v].push_back({u, INT_MAX});
      return;
   }
   void addEdge2(int u , int v) {
      mapp_2[u].push_back(v);
      mapp_2[v].push_back(u);
      return;
   }

   void dfs(int root, bool *visited , int d) {

      if (visited[root] == 1)return;

      visited[root] = 1;

      for (auto &nbrPair : mapp_[root]) {
         if (!visited[nbrPair.first]) {
            nbrPair.second = d + 1;
            dfs(nbrPair.first, visited,  d + 1);
         }
      }
      return;
   }

   void dfs_heleper(int n , int m) {
      int sizee = max(n, m);
      bool visited[ sizee ];
      for (int i = 0 ; i <= sizee ; i++) {
         visited[i] = 0;
      }
      ll ans = 0;

      for (auto elem : mapp_) {
         // cout << elem.first << " \n";
         for (auto nbrPair : mapp_[elem.first]) {
            if (nbrPair.second != INT_MAX)
               ans += nbrPair.second;
         }
      }
      cout << ans + 1;
   }


   void dfs2(char graph_[10001][10001], ll&siz , int i , int j , int n, int m ) {

      if ( i >= n || j >= m || i < 0 || j < 0 || graph_[i][j] == '#' )return;

      graph_[i][j] = '#';
      siz++;

      dfs2(graph_, siz, i + 1, j, n, m);
      dfs2(graph_, siz, i, j + 1, n, m);
      dfs2(graph_, siz, i, j - 1, n, m);
      dfs2(graph_, siz, i - 1, j, n, m);

      return;
   }

   void dfs3(int src , ll&ans , bool *visited , ll &totalOr, ll &orr , int *arr ) {
      if (visited[src] == 1)return;

      visited[src] = 1;

      debug(arr[src]);
      debug(totalOr);

      if (totalOr ^ arr[src] == orr + arr[src]) {
         ans++;
      }
      totalOr ^= arr[src];
      orr += arr[src];
      for (auto nbr : mapp_2[src]) {
         if (!visited[nbr])dfs3(nbr, ans, visited, totalOr, orr, arr);
      }
      return;
   }

   void dfs_heleper3(int *arr) {

      bool visited[N + 1];
      ll totalOr = 0;

      fr(i, 1, N + 1, 1) {
         visited[i] = 0;
         totalOr = totalOr | arr[i];
      }
      debug(totalOr);

      ll src = 1;

      for ( auto el : mapp_2) {
         if (el.second.size() == 1)src = el.first;
      }
      ll ans = 0;
      ll orr = 0;

      debug(src);
      dfs3(src, ans, visited , totalOr , orr , arr );

      cout << ans << "\n";
   }

};

char graph_[10001][10001];

void solve() {

   int n  ;
   cin >> n ;

   int arr[n + 1];
   fr(i, 1, n + 1, 1)cin >> arr[i];
   graph_1 g2(n);
   n--;
   while (n--) {
      int u, v;
      cin >> u >> v;
      g2.addEdge2(u, v);
   }

   g2.dfs_heleper3(arr);


   return;
}


int main() {

   fastInput();

   ll t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}