
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)        cout<<#x<<" "<<x<<endl;
#define outel()         cout<<endl;
#define fri(a,b,step)   for( int i = a; i < b; i+=step)
#define frj(a,b,step)   for( int j = a; j < b; j+=step)
#define frk(a,b,step)   for( int k = a; k < b; k+=step)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

void bfs( ) {

   int n, m;
   cin >> n >> m;

   // requires vis array and a queue
   vector<int>vec_[10003] ;
   bool visited[10003] = {0};

   fri(0, m, 1) {
      int x, y;
      cin >> x >> y;
      vec_[x].push_back(y);
      vec_[y].push_back(x);
   }


   // BFS :
   queue<int>queue_;
   queue_.push(1);
   visited[1] = 1;

   while (!queue_.empty()) {

      int node = queue_.front();
      queue_.pop();
      cout << node << endl;

      vector<int> :: iterator it;

      // we iterate over graph neighbours and not in the tree neighbours !!
      for (it = vec_[node].begin(); it != vec_[node].end(); it++ ) {
         if (!visited[*it]) {
            // mark it visited while pushing it to the queue.
            visited[*it] = 1;
            queue_.push(*it);
         }
      }
   }
   return;
}

// dfs requi. only visited arr
void dfs(vector<int>vec_[10003], bool visited[10003] , int currNode) {

   // mark the node visited very first  !!
   // preorder
   visited[currNode] = 1;
   // cout << currNode << " ";
   // 1 2 4 5 6 7 3

   // inorder
   vector<int>::iterator it;
   for (it = vec_[currNode].begin(); it != vec_[currNode].end() ; it++) {

      if (visited[*it]);
      else {
         dfs( vec_, visited, *it);
      }
   }

   // postorder
   cout << currNode << " ";
   // 4 5 6 3 7 2 1

   return;
}

void dfs_helper() {

   int n, m;
   cin >> n >> m;

   vector<int>vec_[10003] ;
   bool visited[10003] = {0};

   fri(0, m, 1) {
      int x, y;
      cin >> x >> y;
      vec_[x].push_back(y);
      vec_[y].push_back(x);
   }

   // DFS
   dfs( vec_, visited, 1);

   return;
}

// requires indegree array and a queue !!
void topologicalSort() {
   // sequence of ordering
   int n, m; cin >> n >> m;// no of vertices & edges
   vector<int>indegree(n, 0);
   vector<int>adj_list[n];

   fri(0, m, 1) {

      int edge1, edge2;
      cin >> edge1 >> edge2;
      // debug(edge1);
      adj_list[edge1].pb(edge2);
      indegree[edge2]++;
   }

   queue<int>queue_;
   // push 0 indegree into the q
   fri(0, n, 1) {
      if (indegree[i] == 0)
         queue_.push(i);
   }

   int count = 0;
   while (!queue_.empty()) {

      count++;
      int currNode = queue_.front();
      cout << currNode << " ";
      queue_.pop();
      vector<int>::iterator it;
      for ( it = adj_list[currNode].begin() ; it != adj_list[currNode].end(); it++  ) {
         indegree[*it]--;
         if (indegree[*it] == 0) {
            queue_.push(*it);
         }
      }
      // for (auto it : adj_list[currNode]) {
      //    indegree[it]--;
      //    if (indegree[it] == 0) {
      //       queue_.push(it);
      //    }
      // }
   }

   return;
}

// FOR UNDIRECTED GRAPH :
bool isCycle(int source, vector<vector<int>>adj_list , bool visited[], int parent) {

   visited[source] = 1;
   for (auto edge : adj_list[source]) {

      if (edge != parent) {
         if (visited[edge] == 1)return 1;
         else if (!visited[edge] && isCycle(edge , adj_list, visited, source) ) {
            return 1;
         }
      }
   }

   return 0;
}

// FOR UNDIRECTED GRAPH :
// m1 -> 1) via dfs !
bool detectCycle() {
   int n, m; cin >> n >> m;
   // no of vertices & edges

   vector<vector<int>>adj_list(n);

   fri(0, m, 1) {
      int edge1, edge2;
      cin >> edge1 >> edge2;

      adj_list[edge1].pb(edge2);
      adj_list[edge2].pb(edge1);
   }

   bool visited[n] = { 0 };

   fri(0, n, 1) {
      if ( !visited[i] and isCycle(i, adj_list , visited, -1) )return 1;
   }

   return 0;
}

// stack & vis array !
bool isCycleDir( int source , vector<vector<int>>adj_list, vector<bool>visited, vector<bool>stack_ ) {

   // mark both true !
   visited[source] = 1;
   stack_[source] = 1 ;

   for (auto edge : adj_list[source]) {

      if (!visited[edge] && isCycleDir(edge, adj_list, visited, stack_) )
         return 1;
      if (stack_[edge])return 1;
   }
   stack_[source] = 0;
   return 0;
}

bool detectCycleDirected() {
   int n, m; cin >> n >> m;
   // no of vertices & edges
   vector<vector<int>>adj_list(n);
   vector<bool>visited(n, 0);
   vector<bool>stack_(n, 0);

   fri(0, m, 1) {
      int edge1, edge2;
      cin >> edge1 >> edge2;

      adj_list[edge1].pb(edge2);
      // adj_list[edge2].pb(edge1);
   }

   fri(0, n, 1) {
      if (!visited[i] && isCycleDir( i , adj_list, visited , stack_ ) ) {
         return 1;
      }
   }


   return 0;
}

// do 1 dfs only !
int getConnectedComponents(int source , vector<vector<int>>&adj_list, vector<bool>&visited) {

   if (visited[source])return 0;
   visited[source] = 1;
   int ans = 1;
   for (auto edge : adj_list[source]) {

      if (!visited[edge]) {
         ans += getConnectedComponents(edge, adj_list, visited);
         visited[edge] = 1;
      }
   }

   return ans;
}

int connectedComponents() {
   int n, m; cin >> n >> m;
   // no of vertices & edges
   vector<vector<int>>adj_list(n);
   vector<bool>visited(n, 0);

   fri(0, m, 1) {
      int edge1, edge2;
      cin >> edge1 >> edge2;
      adj_list[edge1].pb(edge2);
      adj_list[edge2].pb(edge1);
   }

   vector<int>connectedCompo;
   // debug(vector[3]);
   fri(0, n, 1) {
      // debug(i);
      if (!visited[i]) {
         // debug(i);
         connectedCompo.pb(getConnectedComponents(i , adj_list, visited));
      }
   }
   cout << "No of components : " << connectedCompo.size() << endl;

   for (auto i : connectedCompo)
      cout << i << " ";

   return 0;
}

//  NOTE HERE THE VISITED ARRAY CAN BE AVOIDED !!
// BY SETTING COLOR -> 0 , 1 , 2
void isBirpartite(vector<vector<int>>&adj_list, vector<bool>&visited, vector<int>&colored  , int element , int color , int &Bipartite ) {
   // debug(element);
   // check for colored element !
   if ( colored[element] != -1 && colored[element] != color  ) {
      Bipartite = 0;
      return ;
   }

   colored[element] = color;
   if (visited[element])return ;
   visited[element] = 1;
   for (auto neighbour : adj_list[element]) {
      isBirpartite(adj_list, visited, colored, neighbour, !color , Bipartite);
   }

   return ;
}

void checkBipartite() {
   int n, m; cin >> n >> m;
   // no of vertices & edges
   // debug(n);
   // debug(m);

   vector<vector<int>>adj_list(n);
   vector<bool>visited(n, 0);
   vector<int>colored(n, -1);

   fri(0, m, 1) {
      // debug(i);
      int edge1, edge2;
      cin >> edge1 >> edge2;
      adj_list[edge1].pb(edge2);
      adj_list[edge2].pb(edge1);
      // debug(edge1);
      // debug(edge2);
   }

   int Bipartite = 1;
   int color = 1;

   // debug();

   fri(0, n, 1) {
      debug(i);
      if ( !visited[i]  ) {
         isBirpartite(adj_list, visited, colored , i , color , Bipartite);
      }
   }

   // debug(Bipartite);
   if (Bipartite) {
      cout << "yes graph is Bipartite" << endl;
   } else cout << "No graph is not Bipartite" << endl;

}

void solve() {


   // bfs();
   // dfs_helper();
   // topologicalSort();

   // undirected :
   // if (detectCycle()) cout << "Yes cycle is present " << endl;
   // else cout << "No cycle is not present" << endl;

   // directed :
   // if (detectCycleDirected()) cout << "Yes cycle is present " << endl;
   // else cout << "No cycle is not present" << endl;

   // connected components :
   // connectedComponents() ;

   // bipartite check:
   // checkBipartite();

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
