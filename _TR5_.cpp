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
void IO() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

class node {
public:
   int data;
   node*left, *right;
   node(int d) {
      this->data = d;
      left = right = NULL;
   }
};

void ino(node*r) {
   if (r == NULL)return;

   ino(r->left);
   cout << r->data << " ";
   ino(r->right);

   return;
}

void lo1(node*r) {

   queue<node*>q;
   q.push(r);
   q.push(NULL);

   vector<vector<int>>v;
   vector<int>v1;

   while (!q.empty()) {
      node*c = q.front();
      q.pop();

      if (c != NULL) {
         // cout << c->data << " ";
         v1.push_back(c->data);

         if (c->left != NULL) q.push(c->left);
         if (c->right != NULL)q.push(c->right);

      } else if (c == NULL && !q.empty()) {

         v.push_back(v1);
         v1.erase(v1.begin(), v1.end());
         // cout << nline;
         q.push(NULL);
      }
   }
   v.push_back(v1);
   // cout << v.size() << " - " << nline;
   for (int i =  0 ; i < v.size() ; i++) {
      for (int j = 0; j < v[i].size() ; ++j) {
         cout << v[i][j] << " ";
      } cout << nline;
   }

   return;
}

void lo2(node*r) {

   queue<node*>q;
   q.push(r);
   q.push(NULL);

   vector<vector<int>>v;
   vector<int>v1;

   while (!q.empty()) {
      node*c = q.front();
      q.pop();

      if (c != NULL) {
         // cout << c->data << " ";
         v1.push_back(c->data);

         if (c->left != NULL) q.push(c->left);
         if (c->right != NULL)q.push(c->right);

      } else if (c == NULL && !q.empty()) {

         v.push_back(v1);
         v1.erase(v1.begin(), v1.end());
         // cout << nline;
         q.push(NULL);
      }
   }
   v.push_back(v1);
   // cout << v.size() << " - " << nline;
   for (int i =  0 ; i < v.size() ; i++) {
      for (int j = 0; j < v[i].size() ; ++j) {
         cout << v[i][j] << " ";
      } cout << nline;
   }

   return;
}

// return -1 if not h bal else return the height in bottum up manner
// return height from the balanced fx !!
int bal(node*r) {
   if (r == NULL)return 0;

   int lh, rh;

   lh = bal(r->left);
   rh = bal(r->right);

   if (lh == -1 || rh == -1)return -1;

   if (abs(lh - rh) <= 1 ) {
      return max(lh, rh) + 1;
   }

   return -1;
}

void bal_(node*root) {
   if (bal(root) == -1)cout << "NOT h balanced" << nline;
   else cout << "YES h balanced" << nline;

   return;
}

// NOTE : RETURN THE DIA BUT ALSO FIND THE HEIGHT RECURSIVELY !
// return dia from the fx !!
int maxw(node*r , int &h) {
   if (r == NULL)return h = 0;

   int lh, rh;

   int ld = maxw(r->left, lh );
   int rd = maxw(r->right, rh );

   h = max(lh, rh) + 1;
   int cd = lh + rh + 1;


   return max(cd , max(ld, rd) );
}

void maxw_(node*r) {
   int h = 0;
   cout << maxw(r, h) << nline;

   return;
}

// will return its height and
int burnTree_(node*r , int lf, int &dist, int &ans) {

   if (r == NULL)return 0;
   if (r->data == lf) {
      cout << "found" << nline;
      dist = 0 ; return 1;
   }

   int ldist, rdist;
   ldist = rdist = -1;
   int lh = burnTree_(r->left, lf, ldist ,  ans);
   int rh = burnTree_(r->right, lf,  rdist , ans);

   if (ldist != - 1) {
      dist = ldist + 1;
      ans = max(ans, rh +  dist );
   }
   else if (rdist != -1) {
      dist = rdist + 1;
      ans = max(ans, lh + dist);
   }

   return max(lh, rh) + 1;
}

void burnTree(node * r) {
   int h , ans = - 1;
   int p = burnTree_(r, 700, h, ans);
   cout << ans << nline ;
   return;
}

void solve() {

   // node*root = NULL;

   // root = new node(130);

   // root->left = new node(210);
   // root->right = new node(120);

   // root->left->left = new node(1210);
   // root->left->right = new node(4210);

   // root->right->left = new node(5120);
   // root->right->right = new node(280);

   // root->left->left->right = new node(98);

   // root->right->right->left = new node(680);
   // root->right->right->left->right = new node(7680);

   // ino(root);
   // lo1(root);
   // cout << nline;
   // maxw_(root);


   node*root = NULL;
   root = new node(100);

   root->left = new node(120);
   root->right = new node(320);

   root->left->left = new node(500);
   root->left->right = new node(700);

   root->left->left->left = new node(39);
   root->left->left->left->left = new node(99);


   lo1(root);
   burnTree(root);



   return;
}

int main() {

   IO();

   ll t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}