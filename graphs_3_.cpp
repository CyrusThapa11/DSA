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
   vector<pair<int, int>>*adjList2;

   // int indegree[V];
   int*indegree;
public:
   graph_1(int v) {
      this->V = v;
      adjList = new vector<int>[v];
      adjList2 = new vector<pair<int, int>>[v];

      indegree = new int[V];

      // NOTE THIS MEMSET DOES NOT WORK HERE !!
      // memset(indegree, 0, sizeof(indegree));

      // for (int i = 0; i < V; ++i)
      //    indegree[i] = 0;

   }

   void addEdge( int u, int v, bool bdir = 1 ) {
      adjList[u].pb(v);
      // indegree[v] += 1;
      if (bdir)
         adjList[v].pb(u);
   }


   void addEdge2( int u, int v , int wt ) {
      adjList2[u].pb({v, wt});
   }


// SHORTEST PATH IN AN UNWTED GRAPH : USING BFS :

   void SPath() {
      int src = 6;
      queue<int>que_;
      bool visited[V];
      int distance[V];
      memset(distance, 0, sizeof(distance));

      que_.push(src);

      // memset(distance, -1, sizeof(distance));
      visited[src] = 1;

      while (!que_.empty()) {
         int currNode = que_.front();
         que_.pop();
         for (int neigh : adjList[currNode]) {

            if (!visited[neigh]) {

               // MARK THE NODE VISITED HERE --------!

               visited[neigh] = 1;
               distance[neigh] = distance[currNode] + 1;
               que_.push(neigh);
            }
         }
      }

      int i = 0;
      for (auto dist : distance) {
         cout << i << " -> " << dist << nline;
         i++;
      }

   }

// SHORTEST PATH IN AN UNWTED GRAPH : USING BFS :

// TRY THIS AGAIN !------------!

   void SPath2() {
      int src = 6;
      queue<int>que_;
      bool visited[V];
      int distance[V];

      que_.push(src);
      memset(distance, INT_MAX, sizeof(distance));

      distance[src ] = 0;
      while (!que_.empty()) {

         int currNode = que_.front();
         que_.pop();
         debug(currNode);
         debug(distance[currNode]);

         for (int neigh : adjList[currNode]) {
            if (distance[neigh] == -1) {
               distance[neigh] = distance[currNode] + 1;
               que_.push(neigh);
            }
         }

         int i = 0;
         for (auto dist : distance) {
            cout << i << " -> " << dist << nline;
            i++;
         }
      }
   }

   // cycle detection in an undirected graph :
   // has 2 methods -> dfs & bsf both maintain parent !
   bool dfsCycle(int src, bool*visited, int parent) {

      visited[src] = true;
      for (int neigh : adjList[src]) {

         if (visited[neigh] == false) {
            // bool x =
            // if (x)
            return dfsCycle(neigh, visited, src);
         } else if (visited[neigh] == true && neigh != parent ) {
            return true;
         }
         // NOTE : DO NOT DO LIKE THIS :
         // if(!vis[neigh]) return dfsCycle(neigh,vis,src);
         //
      }


      return false;
   }

   // USES BFS FOR CYCLE DETECTION MAINTAIN A PARENT AND VISITED ARRAY

   bool bfsCycle() {
      int src = 0;
      bool visited[V];
      memset(visited, false , sizeof(visited));

      vector<int>parent(V, -1);

      queue<int>que_;
      que_.push(src);
      visited[src] = 1;

      while (!que_.empty()) {

         int currNode = que_.front();
         que_.pop();

         for (auto neigh : adjList[currNode]) {
            if (!visited[neigh]) {
               visited[neigh] = 1;
               parent[neigh] = currNode;
               que_.push(neigh);
            } else if (visited[neigh] && neigh != parent[currNode] ) {
               // cout << "YES cycle present" << nline;
               return 1;
            }
         }
      }

      return 0;
   }

   // USES DFS FOR CYCLE DETECTION MAINTAIN A VISITED ARRAY

   void detectCycleDfs() {

      bool visited[V];

      int src = 0;
      memset(visited, false, sizeof(visited));

      int parent = -1;
      if (dfsCycle(src, visited, -1)) {
         cout << "YES has cycle " << nline;
      } else {
         cout << "NO does not have cycle" << nline;
      }
      return;
   }

   void detectCycleBfs() {

      bool visited[V];

      int src = 0;
      if (bfsCycle()) {
         cout << "YES has cycle " << nline;
      } else {
         cout << "NO does not have cycle" << nline;
      }
      return;
   }


   // cycle detection in an directed graph :
   // has 2 methods -> dfs & bsf both restack array : !

   bool detectCycleDirectedHelper(int src , bool*visited, bool*stack_) {

      visited[src] = true;
      stack_[src] = true;

      for (auto neigh : adjList[src]) {

         if ( stack_[neigh] ) {
            return true;
         } else if ( !visited[neigh] && detectCycleDirectedHelper(neigh, visited, stack_) ) {
            return true ;
         }
      }
      stack_[src] = false;
      return false;
   }

   void detectCycleDirected() {
      bool visited[V ];
      bool stack_[V ];

      memset(visited, false, sizeof(visited));
      memset(stack_, false, sizeof(stack_));
      // int stack_[1000] ;
      // vector<int>stack_;

      int src = 0;
      if (detectCycleDirectedHelper(src, visited, stack_)) {
         cout << "YES has cycle " << nline;
      } else {
         cout << "NO does not have cycle" << nline;
      }

   }

   void detectCycleDirectedBfs() {

      vector<bool >stack_(V) ;
      bool visited[V];
      queue<int>que_;
      int src = 0;

      stack_[src] = 1;
      visited[src] = 1;
      que_.push(src);

      while (!que_.empty()) {

         int node = que_.front();
         que_.pop();

         for (int neigh : adjList[node]) {

            if (!visited[neigh]) {
               visited[neigh] = 1;
               que_.push(neigh);
               stack_[neigh] = 1;
            } else if (visited[neigh] == true && stack_[neigh] == 1 ) {

            }

         }


      }






   }

   // NOTE : NO NEED TO USE VISITED ARRAY !
   // JUST REDUCE THE INDGREE OF NEIGHBOURSE AND IF IT BECOMES 0
   // THEN PUSH IT INTO THE Q_.
   // ALSO CALLED AS KHANS ALGO ...
   void topologicalBFS() {
      int src = 0;

      queue<int>que_;
      bool *visited = new bool[V];

      memset(visited, false, sizeof(visited));

      cout << nline;
      que_.push(src);
      visited[src] = 1;
      while (!que_.empty()) {

         int curr = que_.front();
         que_.pop();
         cout << curr << " -> ";

         for (auto neigh : adjList[curr]) {
            indegree[neigh]--;

            // THIS IS NOT REQ --------!

            // if (!visited[neigh]) {
            //    visited = 1;
            //    indegree[neigh]--;
            // }

            if (indegree[neigh] == 0) {
               que_.push(neigh);
            }
            // cout << neigh << " " << indegree[neigh] << nline;
         }
      }
      return;
   }

   // DETECTING CYCLE USING KHANS ALGO ( VIA TOPO. SORT )

   void khansSort() {
      int src = 0;
      queue<int>que_;
      bool *visited = new bool[V];
      memset(visited, false, sizeof(visited));

      cout << nline;
      que_.push(src);
      visited[src] = 1;
      int count = 1;
      while (!que_.empty()) {
         int curr = que_.front();
         que_.pop();
         cout << curr << " -> ";

         for (auto neigh : adjList[curr]) {
            indegree[neigh]--;

            if (indegree[neigh] == 0) {
               que_.push(neigh);
               count++;
            }
         }
      }

      if (count == V) {
         cout << "NO cycle " << nline;
      } else {
         cout << "YES cycle present" << nline;
      }
   }

   // THIS IS KHANS SORT USING DFS !!
   // JUST MAINTAIN A ORDERING ARRAY , VISITED ARRAY
   // PUSH THE ELEM INTO ORDERING ONCE ALL ITS NEIGHBOURS ARE PROCESSED.

   void topologicalDFS_helper(int elem, bool*visited, vector<int>&ordering) {
      debug(elem);
      visited[elem] = true;
      for (auto neigh : adjList2[elem]) {
         if (!visited[neigh.ff]) {
            topologicalDFS_helper(neigh.ff, visited, ordering);
         }
      }
      ordering.push_back(elem );
      return;
   }

   void topologicalDFS(vector<int>&ordering) {
      int src = 0;

      // vector<int>ordering;
      bool visited[V];

      // for (auto elem : adjList )
      //    if (!visited[elem])
      //       topologicalDFS_helper(elem, visited, ordering);

      for (int i = 0; i < V; ++i) {
         if (!visited[i])
            topologicalDFS_helper(i, visited, ordering);
      }

      reverse(ordering.begin(), ordering.end());

      return;
   }

   void SP_DAG_helper() {

      vector<int>ordering;
      // first find the topoSort
      topologicalDFS(ordering);
      for (auto el : ordering)cout << el << " ";
      int distance_[V];
      cout << nline;
      memset(distance_, INT_MAX , sizeof(distance_));

      for (int i = 0; i < V; ++i)
         distance_[i] = INT_MAX;

      distance_[ordering[0]] = 0;

      for (int i = 0; i < V; ++i) {
         int currNode = ordering[i];
         for (auto neigh : adjList2[currNode]) {
            if (distance_[neigh.ff] > distance_[currNode] + neigh.ss  ) {
               distance_[neigh.ff] = distance_[currNode] + neigh.ss;
            }
         }
      }

      for (auto el : distance_) {
         cout << el << " ";
      }
   }
};

// 1   6   7   8   9
// ....1...1....1...3
void SP_DAG() {

   graph_1 g2(6);

   g2.addEdge2(0, 1, 2);
   g2.addEdge2(0, 4, 1);
   g2.addEdge2(1, 2, 3);
   g2.addEdge2(4, 2, 2);
   g2.addEdge2(2, 3, 6);
   g2.addEdge2(4, 5, 4);
   g2.addEdge2(5, 3, 1);

   g2.SP_DAG_helper();

}

void solve() {

// SHORTEST PATH IN AN UNWTED GRAPH : USING BFS :

   graph_1 g1(7);

   g1.addEdge(0, 1);
   g1.addEdge(1, 4);
   g1.addEdge(4, 6);
   g1.addEdge(1, 2);
   g1.addEdge(2, 3);
   g1.addEdge(3, 5);

   // add this for cycle

   // g1.addEdge(5, 2);
   // g1.addEdge(6, 2);
   // g1.addEdge(2, 4);
   // g1.addEdge(6, 3);

   // g1.SPath();

   // CYCLE DETECTION IN DIRECTED GRAPH

   // g1.detectCycleDfs();
   cout << nline;
   // CYCLE DETECTION IN DIRECTED GRAPH

   // g1.detectCycleDirected();

   // TOPOLOGICAL SORT :
   // g1.topologicalBFS();
   // g1.khansSort();

   // KHANS SORT USING DFS :
   // g1.topologicalDFS();

   // SHORTEST PATH IN A DAG :

   // 1. USING BELLMANFORD , 2. DIJKASTRA
   // IN (VE)              IN ( E*LOGV)
   // IDEA - USE TOPOLOGICAL SORTING !

   // SP_DAG();

   // FOR CYCLE DETECTION USING BFS...

   g1.detectCycleBfs();


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