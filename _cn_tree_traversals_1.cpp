
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


#define fri(a,b,step)   for( ll i = a; i < b; i+=step)
#define frj(a,b,step)   for( ll j = a; j < b; j+=step)
#define frvar(var,a,b,step)   for( ll var = a; var < b; var+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//-----------------------------------------------------------------------------

// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define nline "\n"
// #define pb push_back
// #define ppb pop_back

// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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


template <typename T>

class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void printTree( TreeNode<int>* root) {

    if (root == NULL)return;

    cout << root->data << " ";

    printTree(root->left);
    printTree(root->right);
    return;
}


void reverseLevelOrder() {

    int data; cin >> data;
    queue<TreeNode<int>*>queue_;

    TreeNode<int> * root = new TreeNode<int> (data) ;
    // cout << "HI \n";
    root->data = data;
    queue_.push(root);

    while (!queue_.empty()) {
        TreeNode<int> * currNode = queue_.front() ;
        queue_.pop();

        int L, R;
        cin >> L >> R;

        if (L == -1) {
            currNode->left = NULL;
        } else {
            currNode->left = new TreeNode<int>(L);
            queue_.push(currNode->left);
        }
        if (R == -1) {
            currNode->right = NULL;
        } else {
            currNode->right = new TreeNode<int>(R);
            queue_.push(currNode->right);
        }
    }


    vector<int>vec_;

    queue_.push(root);
    queue_.push(NULL);

    while (!queue_.empty()) {

        TreeNode<int>* currNode = queue_.front();
        queue_.pop();

        if (currNode != NULL ) {
            vec_.pb(currNode->data);
            // cout << currNode->data << " ";
            // stk_.push(currNode->data);
            if (currNode->left != NULL)
                queue_.push(currNode->left);
            if (currNode->right != NULL)
                queue_.push(currNode->right);

        } else if ( currNode == NULL && !queue_.empty() ) {
            queue_.push(NULL);
        }
    }

    reverse(vec_.begin(), vec_.end());

    for (auto v : vec_)cout << v << ' ';

    // return vec_;
}

void addToQ(queue<TreeNode<int>*>&queue_, BinaryTreeNode<int>* root_) {
    BinaryTreeNode<int>* temp;
    temp = root_;
    while (1) {

        queue_.push(temp);
        temp = temp->right;
        if (temp ->right == NULL || (temp ->left == NULL && temp ->right == NULL ))
            break;
    }

    return;
}

bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {

    queue<TreeNode<int>*>queue1;
    queue<TreeNode<int>*>queue2;

    bool ans = 1;
    unordered_map<int, int>mapping;

    addToQ(queue1, root1);
    addToQ(queue2, root2);

    if (queue2.size() != queue1.size()) {
        cout << "False\n";
    } else {




    }



}

void diagonalAnagramHelper() {
    int data; cin >> data;
    queue<TreeNode<int>*>queue_;

    TreeNode<int> * root1 = new TreeNode<int> (data) ;

    root1->data = data;
    queue_.push(root1);

    while (!queue_.empty()) {
        TreeNode<int> * currNode = queue_.front() ;
        queue_.pop();

        int L, R;
        cin >> L >> R;

        if (L == -1) {
            currNode->left = NULL;
        } else {
            currNode->left = new TreeNode<int>(L);
            queue_.push(currNode->left);
        }
        if (R == -1) {
            currNode->right = NULL;
        } else {
            currNode->right = new TreeNode<int>(R);
            queue_.push(currNode->right);
        }
    }

    // tree  2:
    cin >> data;
    queue<TreeNode<int>*>queue_;

    TreeNode<int> * root2 = new TreeNode<int> (data) ;

    root2->data = data;
    queue_.push(root2);

    while (!queue_.empty()) {
        TreeNode<int> * currNode = queue_.front() ;
        queue_.pop();

        int L, R;
        cin >> L >> R;

        if (L == -1) {
            currNode->left = NULL;
        } else {
            currNode->left = new TreeNode<int>(L);
            queue_.push(currNode->left);
        }
        if (R == -1) {
            currNode->right = NULL;
        } else {
            currNode->right = new TreeNode<int>(R);
            queue_.push(currNode->right);
        }
    }

    diagonalAnagram(root1, root2);

}

void solve() {

    // TreeNode<int>*root;
    // vector<int>ans;
    // ans = reverseLevelOrder(root);
    // for (auto v : ans)cout << v << ' ';

    // reverseLevelOrder();

    diagonalAnagramHelper();

    return;
}


int main() {

    fastInput();

    ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
