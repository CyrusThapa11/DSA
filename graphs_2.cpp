#include<iostream>
#include<vector>
#include<list>
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

typedef                 long long ll;
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


#define fri(a,b,step)   for( int i = a; i < b; i+=step)
#define frj(a,b,step)   for( int j = a; j < b; j+=step)
#define frk(a,b,step)   for( int k = a; k < b; k+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; cerr<<(x)<<" "; cerr << endl;
#else
#define debug(x)
#endif

//---------------------------------------------------------------------------
void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif

}

// gfg :
// shortest path in an unweighted graph :

class unWtedGraph {
public:
   int V;
   vector<pair<int, int>>*adjList;

   unWtedGraph() {}
   unWtedGraph(int n) {
      this->V = n;
      adjList = new vector<pair<int, int>>[n];
   }

   void addEdge( int u, int v , int w ) {
      adjList[u].pb({v, w});
      adjList[v].pb({u, w});
      return;
   }

   void printGraph() {

      for (int i = 0 ; i < V; i++) {
         cout << i << "->";
         for (auto j = adjList[i].begin() ; j != adjList[i].end(); j++) {
            cout << j->first << " wt - " << j->second  << " ";
         }
         cout << endl;
      }
   }

   void dijkastra(int src) {

      vector<int>distance(V);
      vector<bool>visited(V);

      set<pair<int, int>>pairSet;
      pairSet.insert({0, src});

      while (!pairSet.empty()) {
         auto currDestination = pairSet.begin();
         int desti = currDestination.ss;
         int wt = currDestination.ff;

         for (auto neigh : adjList[desti]) {

            int neighbourDestnations = neigh.ff  ;
            int neighbourDestnationsDistace = neigh



         }

      }

   }

};



void solve() {

   unWtedGraph g1(4) ;
   g1.addEdge(0, 1, 10);
   g1.addEdge(1, 3, 1);
   g1.addEdge(2, 3, 20);
   g1.addEdge(0, 3, 11);
   g1.printGraph();
   g1.dijkastra(0);

   return;
}


int main() {

   fastInput();

   int t = 1;
   // cin>>t;
   while (t--) {
      solve();
   }

   return 0;
}