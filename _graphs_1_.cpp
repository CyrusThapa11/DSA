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

// UNWEIGHTED GRAPH :
class Graph1 {
   int V;
   list<int>*l;

public:
   Graph(int V) {
      this->V = V;
      l = new list<int>[V];
   }

   void addEdge(int x, int y) {
      l[x].pb(y);
      l[y].pb(x);
   }

   void printAdjList() {
      for (int i = 0 ; i < V ; i++) {
         cout << "Vertex : " << i << "->";
         for (int nbr : l[i]) {
            cout << nbr << ",";
         }
         cout << "\n";
      }
   }
};

// FOR WEIGHTED GRAPHS :- > unordered_map
template<typename T>
class Graph2 {
   unordered_map<T, list<pair<T, int>>>mapping_;
public:
   Graph2() { }

   void addEdge(T x, T y, bool bidir , int wt) {
      mapping_[x].pb({y, wt});
      if (bidir) {
         mapping_[y].pb({x, wt});
      }
   }

   void printAdjList() {

      for (pair<T, list<pair<T, int>>> p : mapping_) {

         T city = p.ff;
         list<pair<T, int>>list_ = p.ss;
         cout << "" << city << "-> ";

         for (auto neighbour : list_) {
            T dest = neighbour.ff;
            int dist = neighbour.ss;
            cout << "(" << dest << "," << dist << "), ";
         }

         cout << endl;
      }
   }

   // mapping of node & neighbours  ,final distance map initially set to inf ,
   // set containing node and their distance of the current processing node.

   void DijsktraSSSP(T src) {

      unordered_map<T, int>finalDistance;
      set<pair<int, T>>pairSet;

      for (auto node : mapping_) {
         finalDistance[node.ff] = INT_MAX;
      }

      pairSet.insert({ 0 , src });
      finalDistance[src] = 0;

      while (!pairSet.empty()) {

         auto node = *(pairSet.begin());
         pairSet.erase(node);

         int nodeDistance = node.ff;
         T currentSource = node.ss;

         for (auto elemPair : mapping_[currentSource]) {

            T neighbour = elemPair.ff;
            int neighbourDist = elemPair.ss;

            // look in the final distance array :

            if (nodeDistance + neighbourDist < finalDistance[neighbour]) {
               auto neighbourPosInSet = pairSet.find( { finalDistance[neighbour] , neighbour  } );

               if (neighbourPosInSet != pairSet.end()) {
                  pairSet.erase(neighbourPosInSet);
               }
               finalDistance[neighbour] = nodeDistance + neighbourDist;
               pairSet.insert({nodeDistance + neighbourDist , neighbour});
            }
         }
      }

      for (auto d : finalDistance) {
         cout << d.ff << " is located at " << d.ss << "\n";
      }
   }
};

// GENERIC GRAPH WITHOUT WEIGHTS :
// requires a mapping :

template < typename T>
class Graph3 {
   map<T, list<T>>mapping_;

public:
   Graph3() {}

   void addEdge(T x , T y , bool bidir = true ) {
      mapping_[x].pb(y);
      if (bidir)
         mapping_[y].pb(x);
   }

//---ACTUAL BFS
   // bfs requires - map of visited nodes and a queue for processing
   void bfs(T src) {

      map<T, bool> visited;
      queue<T>q;
      q.push(src);
      visited[src] = 1;

      while (!q.empty()) {
         T node = q.front();
         q.pop();
         cout << node << "\n";
         for (int neighbour : mapping_[node]) {
            if (!visited[neighbour]) {
               q.push(neighbour);
               visited[neighbour] = 1;
            }
         }
      }
   }

// ---------SINGLE SOURCE SHORTEST PATH USIGN BFS
   // requires a mapping of distance and a queue and the adj list which is a map
   void singleSourceShortestPath_BFS(int src) {
      map<T, int> distance ;
      queue<T>q;
      q.push(src);

      for (auto pair_ : mapping_) {
         T src = pair_.ff;
         distance[src] = INT_MAX;
      }

      distance[src] = 0;

      while (!q.empty()) {
         T node = q.front();
         q.pop();

         // cout << node << "\n";

         for (int neighbour : mapping_[node]) {
            if (distance[neighbour] == INT_MAX ) {
               q.push(neighbour);
               distance[neighbour] = distance[node] + 1;
            }
         }
      }

      // dist to every node:
      for (auto n_pair : mapping_) {
         T node = n_pair.ff;;
         int d = distance[node];
         cout << "Node: " << node << " dist from src " << d << '\n';
      }
   }

//-----------DFS HELPER

   void dfs_helper( T src, map<T, bool>&visited ) {

      cout << " node : " << src << '\n';
      visited[src] = true;
      for (auto neighbour : mapping_[src] ) {
         if (!visited[neighbour]) {
            dfs_helper(neighbour, visited);
         }
      }
   }

//---------ACTUAL DFS
   void dfs(T src) {
      map<T, bool>visited;
      for (auto p : mapping_) {
         T node = p.ff;
         visited[node] = false;
      }
      dfs_helper(src, visited);
   }

//-------CONNECTED COMPONENTS FROM DFS
   void connectedComponents() {

      map<T, bool>visited;

      for (auto node : mapping_) {
         T element = node.ff;
         visited[element] = false;
      }

      int count = 0;

      for (auto node : mapping_) {
         T elem = node.ff;
         if (!visited[elem] ) {
            count++;
            cout << "In Component : " << elem << '\n';
            dfs_helper(elem, visited);
         }
      }
      cout << "Total Components are : " << count << '\n';
   }

   //--------TOPOLOGICAL SORT USING DFS :
   void topologicalSort_helper(T src, map<T, bool>&visited, list<T>&ordering) {

      visited[src] = true;

      for (auto neighbour : mapping_[src] ) {
         if (!visited[neighbour]) {
            topologicalSort_helper(neighbour, visited, ordering);
         }
      }

      ordering.push_front(src);
      return;

   }

   //--------TOPOLOGICAL SORT USING DFS :
   void topologicalSort_DFS() {

      map<T, bool>visited;
      list<T>ordering;

      for (auto node : mapping_) {
         visited[node.ff] = false;
      }

      for (auto node : mapping_) {
         if (!visited[node.ff]) {
            topologicalSort_helper(node.ff, visited, ordering);
         }
      }

      for (auto elem : ordering) {
         cout << elem << "\n";
      }
   }

   void topologicalSort_BFS(int V) {

      int *indegree = new int[V] {0};

      // vector<int>indegree = {0} ;

      for (auto elem : mapping_) {
         for (auto neighbour : mapping_[elem.ff]) {
            indegree[neighbour]++;
         }
      }
      queue<T>queue_;
      for (auto elem : mapping_) {
         if (indegree[elem.ff] == 0) {
            queue_.push(elem.ff);
         }
      }

      while (!queue_.empty()) {

         T element = queue_.front();
         queue_.pop();
         cout << "Elem - " << element << "\n";

         for (auto neighbour : mapping_[element]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
               queue_.push(neighbour);
            }
         }
      }
      return;
   }
};

class Graph4 {

   list<int>*listPtr;
   int V;

public:
   Graph4(int V) {
      this->V = V;
      listPtr = new list<int>[V];
   }

   void addEdge(int x , int y, bool bidir = true) {
      // debug(x);
      // debug(y);
      listPtr[x].pb(y);
      if (bidir) {
         listPtr[y].pb(x);
      }
   }

   void printGraph() {

      fri(0, V, 1) {
         cout << "Elem " << i << " -> ";
         for (int neighbour : listPtr[i]) {
            cout << neighbour << " ";
         }
         cout << "\n";
      }

      // for (auto elm : listPtr) {
      //    cout << "elem " << elm.ff << "-> ";
      //    for (auto neighbour : listPtr[elm]) {
      //       cout << neighbour << " ";
      //    }
      // }
   }

   bool isTree() {
      bool *visited = new bool[V];
      int *parent = new int[V];

      fri(0, V, 1) {
         parent[i] = i;
         visited[i] = false;
      }

      int src = 0;
      queue<int>queue_;
      queue_.push(src);
      visited[src] = true;

      printGraph();
      cout << endl;

      while (!queue_.empty()) {
         int node = queue_.front();
         queue_.pop();

         for (int neighbour : listPtr[node]) {
            if (visited[neighbour] == true and parent[node] != neighbour ) {
               return false;
            } else if (visited[neighbour] == false) {
               visited[neighbour] = true  ;
               queue_.push(neighbour);
               parent[neighbour] = node;
            }
         }
      }
      return true;
   }

   bool cycle_helper(int src , bool *visited, bool *stack_) {

      visited[src] = true;
      stack_[src] = true;

      for (int neighbour : listPtr[src]) {
         if (stack_[neighbour])return true;
         else {
            // bool nextCycle = cycle_helper()
            if (!visited[neighbour] && cycle_helper(neighbour, visited, stack_) ) {
               return true;
            }
         }
      }

      stack_[src] = false;
      return false;
   }

   bool checkCycle() {
      bool * visited = new bool[V];
      bool * stack_ = new bool[V];

      fri(0, V, 1) {
         visited[i] = stack_[i] = false;
      }
      int src = 0;
      return cycle_helper(src , visited, stack_ );
   }

   bool checkCycle_dfs_helper( int src , bool * visited, int parent ) {
      visited[src] = true;

      for (int neighbour : listPtr[src]) {
         if (visited[neighbour] == true && parent != neighbour ) {
            return true;
         } else if (visited[neighbour] == false) {
            bool chec_next = checkCycle_dfs_helper(neighbour, visited, src);
            if (chec_next)return true;
         }
      }
      return false;
   }

   bool checkCycle_dfs() {

      bool *visited = new bool[V];
      // int *parent = new int[V];
      int src = 0;

      fri(0, V, 1) {
         visited[i] = false;
         // parent[i] = i;
      }
      return checkCycle_dfs_helper( src, visited, -1 );
   }

};

template<typename T>
class DSU {
   int n;
   int total_components = 0;
   vector<T>parent;
   vector<int>sizee;
public:
   DSU() {}
   DSU(int N) {
      this->n = N;
   }

   void init() {
      int n ; int edges;
      cin >> n >> edges;

      // parent = new vector<T>(n, 0) ;
      total_components = n;
      sizee.resize(n);
      parent.resize(n);
      for ( int i = 0; i < n ; i++ ) {
         (parent[i]) = i;
         sizee[i] = 0;
      }

      bool cycle = 0;
      for (int i = 0 ; i < edges ; i++) {
         int x, y;
         cin >> x >> y;
         // x--; y--;
         unite(x, y, cycle);
         if (cycle) {
            // cout << "Cycle in graph \n";
            break;
         }

      }
      if (cycle) {
         cout << "Cycle in graph \n";
         // break;
      } else {
         cout << "No cycle in graph \n";
      }

      return;
   }

   T get_parent(T node_) {
      if (parent[node_] == node_) return node_;
      //path compression:
      return parent[node_] = get_parent(parent[node_]);
   }

   void unite(T node1, T node2 , bool & cycle) {

      T parent_node1 = get_parent(node1);
      T parent_node2 = get_parent(node2);
      // change the superParent of the current node and not the
      // parent of current node !
      if (parent_node1 != parent_node2) {
         parent[parent_node1] = parent_node2;
         sizee[parent_node2] += sizee[parent_node1];
         sizee[parent_node1] = 0;
         total_components--;
      } else {
         cycle = true;
      }
      return;
   }

};

template<typename T>
class dsu_by_rank {
   int n;
   T *Super_parent;
   int *rank_or_size;

public:
   dsu_by_rank(T v) {
      this -> n = v;
      Super_parent = new T[v];
      rank_or_size = new int[v];
      for (int i = 0 ; i < v ; i++) {
         Super_parent[i] = i;
         rank_or_size[i] = 1;
      }
   }

   T find_superParent( T node1) {
      if (Super_parent[node1] == node1) return node1;
      return Super_parent[node1] = find_superParent( Super_parent[node1]);
   }

   void printParents() {
      for (int i = 0 ; i < (n ); i++) {
         // cout << i << " ";
         cout << "parent of " << i << " is " << Super_parent[i] << "\n ";
      }
   }

   void unite(T node1, T node2) {

      T Super_parent1 = find_superParent(node1);
      T Super_parent2 = find_superParent(node2);



      if (Super_parent1 != Super_parent2) {
         // we need to unite :

         // int rank1 = rank_or_size[node1];
         // int rank2 = rank_or_size[node2];

         // if (rank1  < rank2) {
         //    Super_parent[node1] = Super_parent2;
         //    rank_or_size[node2] += rank_or_size[node1];

         // } else {
         //    Super_parent[node2] = Super_parent1;
         //    rank_or_size[node1] += rank_or_size[node2];

         // }

         Super_parent[Super_parent1] = Super_parent2;
         rank_or_size[node2] += rank_or_size[node1];
         rank_or_size[node1] = 1;

      }
   }

};

template<typename T>
class Krusklas_mst_ {
   vector<vector<T>>EdgeList_;
   int V;
public:
   Krusklas_mst_(int V) {
      this->V = V;
      // cout << 'h';
   }

   void addEdge(T x, T y, int w) {
      EdgeList_.pb({w, x, y});

   }

   int find_mst() {

      sort(EdgeList_.begin(), EdgeList_.end());
      int ans = 0;
      // cout << "HI\n";
      dsu_by_rank<int> d1(V);

      // for (auto edgeVector : EdgeList_) {
      //    cout << "weight " << edgeVector[0] << " x " << edgeVector[1] << " y " << edgeVector[2] << '\n';
      // }

      // DSU<int> d2(V);
      // d2.init();

      for (auto edgeVector : EdgeList_) {

         int w = edgeVector[0];
         int x = edgeVector[1];
         int y = edgeVector[2];
         bool ans1 = 0;
         if (d1.find_superParent(x) != d1.find_superParent(y)) {
            d1.unite(x, y);
            // cout<<
            ans += w;
         }
      }
      // d1.printParents();
      return ans;
   }

};


class primsGraph {
   int v;
   // vector< vector< pair<int, int>>>*list_;
   vector<pair<int, int>>*listPtr;

public:
   primsGraph(int V) {
      this->v = V;
      listPtr = new vector<pair<int, int>>[V + 1];
      //   cout<<typeid(listPtr).name() ;
      // cout<<listPtr[0] <<" ";

      //   cout << "hi\n";
   }

   void addEdge(int x, int y, int w) {
      //   cout << "ji";
      listPtr[x].push_back( {y, w} );
      listPtr[y].push_back( {x, w} );
   }

   int prims_mst() {
      //   cout << "HI";
      // list_ = new vector< vector< pair<int, int>>>[v] ;

      // min heap:
      priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>>queue_;
      queue_.push({0, 0});
      int ans = 0;

      bool *visited = new bool[v] ;
      for (int i = 0 ; i < v ; i++)visited[i] = 0;

      while (!queue_.empty()) {

         auto currNode = queue_.top();
         queue_.pop();

         int destination = currNode.second;
         int weight = currNode.first;

         //cout << weight << " " << destination << "\n";

         if (visited[destination]) {
            continue;
         }

         visited[destination] = 1;
         ans += weight;

         for (auto neighbour : listPtr[destination]) {
            if (!visited[neighbour.first]) {
               queue_.push({neighbour.second, neighbour.first});
            }
         }
      }
      return ans;
   }

};

vector<int> bellmanFord_helper(int v, int src , vector<vector<int>>edgeList) {

   vector<int>distance(v + 1, INT_MAX) ;
   distance[src] = 0;

   for (int i = 0 ; i < v - 1; i++) {
      for (auto edge : edgeList) {

         int u = edge[0];
         int v = edge[1];
         int wt = edge[2];

         if ( (distance[u] != INT_MAX) and (distance[v] > distance[u] + wt) ) {
            distance[v] = distance[u] + wt;
         }

      }
   }

   for (int i = 0 ; i < 1; i++) {
      for (auto edge : edgeList) {

         int u = edge[0];
         int v = edge[1];
         int wt = edge[2];

         if (distance[v] > distance[u] + wt ) {
            cout << "Has -ve wt cycle \n";
         }
      }
   }
   return distance;
}

void bellmanFord() {
   int n , m;
   cin >> n >> m;
   vector<vector<int>>edgeList;
   for (int i = 0; i < m ; i++) {
      int u, v, wt;
      cin >> u >> v >> wt;
      // edgeList[i].pb(u);
      // edgeList[i].pb(v);
      // edgeList[i].pb(wt);
      edgeList.pb({u, v, wt});
   }

   vector<int>dist = bellmanFord_helper( n , 1 , edgeList );

   for (int i = 1; i < n + 1 ; i++) {
      cout << "NODE " << i << " AT a distance of " << dist[i] << '\n';
   }

}

void floydwarshall() {

   vector<vector<int>> graph__ = {
      {0, 1000, -2, 1000},
      {4 , 0, 3, 1000 },
      {1000, 1000, 0 , 2 },
      {1000, -1, 1000, 0}
   };

   vector<vector<int>>distance(graph__);

   for (int k = 0; k < 4 ; k++) {

      for (int i = 0 ; i < 4 ; i++ ) {
         for (int j = 0 ; j < 4 ; j++) {
            if (distance[i][j] > distance[i][k] + distance[k][j] ) {
               distance[i][j] = distance[i][k] + distance[k][j];
            }
         }
      }
   }

   for (int i = 0 ; i < 4 ; i++ ) {
      for (int j = 0 ; j < 4 ; j++) {
         cout << distance[i][j] << " ";
      } cout << '\n';
   }

}

void solve() {

   // Graph1 g1(4);
   // g1.addEdge(0, 1);
   // g1.addEdge(0, 2);
   // g1.addEdge(2, 3);
   // g1.addEdge(1, 2);
   // g1.printAdjList();

   // Graph2 g2;
   // g2.addEdge("A", "B", true , 10);
   // g2.addEdge("B", "D", true , 40);
   // g2.addEdge("A", "C", true , 10);
   // g2.addEdge("C", "D", true , 40);
   // g2.addEdge("A", "D", false , 50);
   // g2.printAdjList();

   // Graph3<int> g3;
   // g3.addEdge(1, 0);
   // g3.addEdge(1, 2);
   // g3.addEdge(2, 3);
   // g3.addEdge(3, 4);
   // g3.addEdge(3, 0);
   // g3.addEdge(4, 5);
   // g3.bfs(0);
   cout << '\n';
   // g3.singleSourceShortestPath_BFS(0);
   // cout << '\n';
   // g3.dfs(3);

   // g3.addEdge(7, 8);
   // g3.addEdge(7, 9);

   // g3.addEdge(10, 11);

   // g3.connectedComponents();

   //------TOPOLOGICAL SORT
   // Graph3<string> g3_;
   // g3_.addEdge( "python", "dataPreprocessing", false );
   // g3_.addEdge( "python", "PyTorch", false );
   // g3_.addEdge( "python", "ML", false );
   // g3_.addEdge( "dataPreprocessing", "ML", false );
   // g3_.addEdge( "ML", "DL", false );
   // g3_.addEdge( "DL", "FaceRecognition", false );
   // g3_.addEdge( "dataSet", "FaceRecognition", false );

   // g3_.topologicalSort_DFS();
   // cout << "\n";
   // Graph3<int> g3__;
   // g3__.addEdge(0, 2, false);
   // g3__.addEdge(1, 2, false);
   // g3__.addEdge(2, 3, false);
   // g3__.addEdge(2, 5, false);
   // g3__.addEdge(1, 4, false);
   // g3__.addEdge(4, 5, false);
   // g3__.addEdge(3, 5, false);
   // g3__.topologicalSort_BFS(6);

   // cycle detection / figure out whether the graph is a tree or not of UNDIRECTED graph :

   // Graph4 g4(4);
   // g4.addEdge(0, 1);
   // g4.addEdge(3, 2);
   // g4.addEdge(1, 2);
   // g4.addEdge(0, 3);

   // if (g4.isTree())cout << "Yes it is a tree \n";
   // else cout << "No it is not a tree \n";

   // cycle detection / figure out whether the graph is a tree or not of DIRECTED graph :

   // Graph4 g5(7);

   // just check for back edge
   // g5.addEdge(0, 1, false);
   // g5.addEdge(1, 2, false);
   // g5.addEdge(2, 3, false);
   // g5.addEdge(3, 4, false);
   // g5.addEdge(4, 5, false);
   // g5.addEdge(1, 5, false);
   // g5.addEdge(5, 1, false);

   // if (g5.checkCycle()) {
   //    cout << "Yes has cycle ";
   // } else cout << "No does not have cycle";


   // Graph4 g6(5);
   // g6.addEdge(0, 1);
   // g6.addEdge(1, 2);
   // g6.addEdge(2, 3);
   // g6.addEdge(3, 4);
   // g6.addEdge(4, 0);
   // g6.addEdge();

   // if (g6.checkCycle_dfs())cout << "Yes cycle is present \n";
   // else cout << "Cycle is not present \n";

   //implicit graphs - 2d matrix representation

   // Graph2<string> g2;
   // g2.addEdge("Amritsar", "Delhi", true, 1);
   // g2.addEdge("Amritsar", "Jaipur", true, 4);
   // g2.addEdge("Jaipur", "Delhi", true, 2);
   // g2.addEdge("Jaipur", "Mumbai", true, 8);
   // g2.addEdge("Bhopal", "Agra", true, 2);
   // g2.addEdge("Mumbai", "Bhopal", true, 3);
   // g2.addEdge("Agra", "Delhi", true, 1);

   // Graph2<int> g2_;
   // g2_.addEdge(1, 2, true, 1);
   // g2_.addEdge(1, 3, true, 4);
   // g2_.addEdge(2, 3, true, 1);
   // g2_.addEdge(3, 4, true, 2);
   // g2_.addEdge(1, 4, true, 7);

   // g2_.printAdjList();
   // cout << "\n";
   // g2.DijsktraSSSP("Amritsar");

   //NOTE: for path make a parent hashmap and store its parent when we are updating the distance !

   // DSU : DISJOINT SET UNION :

   // DSU<int> ds1;
   // ds1.init();

//   Kruskals MST:
   // Krusklas_mst_<int> mst1(4);
   // mst1.addEdge(0, 1, 10);
   // mst1.addEdge(1, 2, 15);
   // mst1.addEdge(0, 2, 5);
   // mst1.addEdge(3, 1, 2);
   // mst1.addEdge(3, 2, 40);
   // mst1.addEdge(1, 2, 2);

   // cout << mst1.find_mst() << "\n";

   // PRIMS ALGO :

   //BELLMAN FORD ALGO :
   // bellmanFord();

   // floydwarshall algo :

   // floydwarshall();

   primsGraph graph6(4);

   // cout<<"HI2";

   graph6.addEdge(1, 3, 15);
   graph6.addEdge(2, 3, 20);
   graph6.addEdge(0, 1, 5);
   graph6.addEdge(0, 2, 8);
   graph6.addEdge(1, 2, 10);

   cout << "mst weight : " << graph6.prims_mst() << endl ;
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