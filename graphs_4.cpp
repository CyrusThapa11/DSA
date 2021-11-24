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
#include<list>
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
#define nline           "\n"
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

#define fi(a,b,step)       for( ll i = a; i < b; i+=step)
#define fj(a,b,step)       for( ll j = a; j < b; j+=step)
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

// DFS IN UNDIRECTED GRAPH :

// void helperDfs( vector<int>&dfs , vector<int>adj[],int src,bool *vis ){

//         vis[src] = 1;
//         dfs.push_back(src);

//         for(auto neigh : adj[src]){
//             if(!vis[neigh]){
//                 helperDfs(dfs,adj,neigh,vis);
//             }
//         }
//     }

//     // Function to return a list containing the DFS traversal of the graph.
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//         // Code here
//         int src = 0;
//         int parent = -1;
//         bool vis[V+1];
//         memset(vis, 0 ,sizeof(vis));
//         vector<int>dfs_;
//         helperDfs(dfs_, adj,src,vis);
//         return dfs_;
//     }


// iterative dfs --
// {
//     // Create a stack for DFS
//     stack<int> stack;

//     // Push the current source node.
//     stack.push(s);

//     while (!stack.empty())
//     {
//         // Pop a vertex from stack and print it
//         int s = stack.top();
//         stack.pop();

//         // Stack may contain same vertex twice. So
//         // we need to print the popped item only
//         // if it is not visited.
//         if (!visited[s])
//         {
//             cout << s << " ";
//             visited[s] = true;
//         }

//         // Get all adjacent vertices of the popped vertex s
//         // If a adjacent has not been visited, then push it
//         // to the stack.
//         for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
//             if (!visited[*i])
//                 stack.push(*i);
//     }
// }

class graph_1
{
   int V;
   vector<int>*adjList;
public:
   graph_1(int v) {
      this->V = v;
      adjList = new vector<int>[v];
   }

   void addEdge( int u, int v ) {
      adjList[u].pb(v);
      adjList[v].pb(u);
   }

   void SPath() {
      int src = 6;
      queue<int>que_;
      bool visited[V];
      int distance[V];
      // memset(distance, 0, sizeof(distance));

      que_.push(src);

      // visited[src] = 1;
      // while (!que_.empty()) {
      //    int currNode = que_.front();
      //    que_.pop();
      //    for (int neigh : adjList[currNode]) {
      //       if (!visited[neigh]) {
      //          visited[neigh] = 1;
      //          distance[neigh] = distance[currNode] + 1;
      //          que_.push(neigh);
      //       }
      //    }
      // }

      int i = 0;
      // for (auto dist : distance) {
      //    cout << i << " -> " << dist << nline;
      //    i++;
      // }

      // memset(distance, -1, sizeof(distance));
      distance[src] = 0;
      i = 0;

      // for (auto dist : distance) {
      //    cout << i << " -> " << dist << nline;
      //    i++;
      // }

      while (!que_.empty()) {

         int currNode = que_.front();
         que_.pop();
         debug(currNode);
         debug(distance[currNode]);

         for (int neigh : adjList[currNode]) {
            if (distance[neigh] == -1) {
               distance[neigh] = distance[currNode] + 1;
               // cout << distance[neigh] << " " << currNode << nline ;
               que_.push(neigh);
            }
         }
      }

      i = 0;
      for (auto dist : distance) {
         cout << i << " -> " << dist << nline;
         i++;
      }

   }
};

// SHORTEST PATH IN AN UNWTED GRAPH : USING BFS :
void solve() {

   graph_1 g1(7);

   g1.addEdge(0, 1);
   g1.addEdge(2, 1);
   g1.addEdge(5, 1);
   g1.addEdge(2, 3);
   g1.addEdge(4, 2);
   g1.addEdge(3, 6);

   g1.SPath();




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