#include <bits/stdc++.h>
using namespace std;

class node {

public:
	int data;
	node* left;
	node* right;

	node( int d ) {
		this->data = d;
		left = NULL;
		right = NULL;
	}
	~node();

};

int maxPathUtil(node*root , int*ans ) {
	if (root == NULL)return 0;

	int left = maxPathUtil(root->left, ans);
	int right = maxPathUtil(root->right, ans);
	int maxSum = max(max(left + root->data , right + root->data) , max(root->data ,
	                 root->data + left + right) );

	*ans = max(maxSum , *ans);
	int singlePathSum = max(max(left + root->data , right + root->data) , root->data  );
	return singlePathSum;
}

int maxPath(node*root) {
	int ans = INT_MIN;

	maxPathUtil(root, &ans);

	return ans;
}

void nodeAtKdist(node*root , int k) {
	if (root == NULL || k < 0)return;
	if ( k == 0 ) {
		cout << root->data << " ";
		return;
	}
	// cout << root->data << " data of r " << endl;
	nodeAtKdist(root->left, k - 1);
	nodeAtKdist(root->right, k - 1);
	return;
}

// NODES AT A DIST. OF K UNITS FROM TARGET !

int kDistantNodes(node* root , int target , int k) {
	//  BASE :
	if (root == NULL ) {
		return -1;
	}

	if (root->data == target ) {
		// CALL ON THE NEXT SUBTREE;
		// cout << " found the target " << endl;
		nodeAtKdist(root, k);
		// cout << " returning 0 " << endl;
		return 0;
		// cout << " after return " << endl;
	}
	// cout << distFromLeftOfTarget << " 1 " << root->data << endl;

	int distFromLeftOfTarget = kDistantNodes( root->left, target, k );
	// cout << distFromLeftOfTarget << " " << root->data << endl;

	if (distFromLeftOfTarget != -1) {

		if ( distFromLeftOfTarget + 1  == k ) {
			cout << root->data << " ";
		} else {
			//	CALL ON RIGHT TREE OF CURRENT ROOT !
			nodeAtKdist(root->right, k - distFromLeftOfTarget - 2);
		}
		return distFromLeftOfTarget + 1;

	}


	int distFromRightOfTarget = kDistantNodes( root->right, target, k );

	if (distFromRightOfTarget != -1) {

		if (distFromRightOfTarget + 1 == k ) {
			cout << root->data << " ";
		} else {
			//	CALL ON RIGHT TREE OF CURRENT ROOT !
			nodeAtKdist(root->left, k - distFromRightOfTarget - 2);
		}
		return distFromRightOfTarget + 1;

	}
	return -1;
}

//  ACTUAL STATED ALGO ON APNA COLLEGE !

void flattenBTree2(node*root) {
	if ((root->left == NULL && root->right == NULL ) || root == NULL )return ;

	if (root->left != NULL && root->right != NULL) {
		flattenBTree2(root->left);
		flattenBTree2(root->right);
	}
	else if (root->right != NULL && root->left == NULL) {
		flattenBTree2(root->right);
		return;
	}


	node * tempPointingToRightRoot = root->right;

	root->right = root->left;
	root->left = NULL;

	node * t = root->right;
	while (t -> right != NULL)
		t = t->right;

	t->right = tempPointingToRightRoot;

	return;
}

// THE ALGO GIVEN BUT THIS WAS NOT STATED !

void flattenBTree(node*root) {
	if ((root->left == NULL && root->right == NULL ) || root == NULL )return ;

	if (root->left != NULL) {

		flattenBTree(root->left);
		node * tempPointingToRightRoot = root->right;

		root->right = root->left;
		root->left = NULL;

		node * t = root->right;
		while (t -> right != NULL)
			t = t->right;


		t->right = tempPointingToRightRoot;
	}

	flattenBTree(root->right);

	return;
}

// LCA OF 2 NODES

node* findLCA(node* root , int n1, int n2 ) {
	if (root == NULL)return NULL;

	if (root->data == n1 || root->data == n2) return root;

	node* leftLCA = findLCA(root->left, n1, n2);
	node* rightLCA = findLCA(root->right, n1, n2);

	if (rightLCA && leftLCA) return root;
	else if (rightLCA) return rightLCA;
	else if (leftLCA) return leftLCA;

	return NULL;
}

int findDist(node*root , int key , int dist) {
	// base :

	if (root == NULL)return -1;
	if (root->data == key)return dist;

	// work :

	int distFromLeft = findDist(root->left , key , dist + 1);
	int distFromRight = findDist(root->right , key , dist + 1);

	if (distFromRight != -1)return distFromRight;
	if (distFromLeft != -1)return distFromLeft;

	return -1;
}

int distanceBwNodes(node*root , int n1 , int n2) {

	node*lca = findLCA(root, n1, n2);
	int d1 = findDist(lca, n1, 0);
	int d2 = findDist(lca, n2, 0);

	return d1 + d2;
}

// LEFT VIEW OF BTREE

void printLeftView(node*root) {
	if (root == NULL)return;

	queue<node*>q;
	q.push(root);

	while (!q.empty()) {

		int siz = q.size();
		for (int i = 0; i < siz; ++i) {

			node*currNode = q.front();
			q.pop();

			if (i == 0)cout << currNode->data << " ";

			if (currNode->left != NULL )
				q.push(currNode->left);
			if (currNode->right != NULL)
				q.push(currNode->right);
		}
	}
	cout << endl;
}

// RIGHT VIEW OF BTREE

void printRightView(node*root) {
	if (root == NULL)return;

	queue<node*>q;
	q.push(root);

	while (!q.empty()) {

		int siz = q.size();
		for (int i = 0; i < siz; ++i) {

			node*currNode = q.front();
			q.pop();

			if (i == siz - 1)cout << currNode->data << " ";

			if (currNode->left != NULL )
				q.push(currNode->left);
			if (currNode->right != NULL)
				q.push(currNode->right);
		}
	}
	cout << endl;
}

//  CHECK IS THE BTREE HEIGHT BALANCED

bool isHeightBalanced(node*root , int *h) {

	if (root == NULL)return 1;

	int lh = 0 , rh = 0;

	if (!isHeightBalanced(root->left, &lh ))
		return 0;
	if (!isHeightBalanced(root->right , &rh))
		return 0;

	*h = max(lh, rh) + 1;
	if (abs(lh - rh) <= 1) return 1;

	return 0;
}

// REPLACE NODE BY SUM OF ITS CHILDREN

void sumReplace( node*root  ) {
	if (root == NULL)return;


	if (root->left != NULL) {
		sumReplace(root->left);
		root->data += root->left->data;
	}

	if (root->right != NULL) {
		sumReplace(root->right);
		root->data += root->right->data;
	}

	return;
}

//  DIAMETER OPTIMIZED

int diaMeterOptimized(node*root , int *height ) {

	if (root == NULL) {
		*height = 0;
		return 0;
	}

	int leftH , rightH;

	int leftDia = diaMeterOptimized(root->left , &leftH );
	int rightDia = diaMeterOptimized(root->right , &rightH );

	int currDia = leftH + rightH + 1 ;

	*height = max(leftH , rightH) + 1 ;

	return max(currDia , max(leftDia , rightDia));
}

// HEIGHT OF BTREE

int height(node*root) {
	return root == NULL ? 0 : max(height(root->left) , height(root->right)) + 1;
}

// DIAMETER OF BTREE

int diaMeter(node*root) {
	if (root == NULL)return 0;

	int leftDia = diaMeter(root->left );
	int rightDia = diaMeter(root->right );

	int leftH = height(root->left )  ;
	int rightH = height(root->right )  ;

	return max( leftH + rightH + 1 , max(leftDia  , rightDia ) );
}

// TOTAL NODES

int totalNodes(node*root) {
	return root == NULL ? 0 : totalNodes(root->left) + totalNodes(root->right) + 1;
}

// SUM OF ALL NODES

int sumOfTotalNodes(node*root) {
	return root == NULL ? 0 : sumOfTotalNodes(root->left) + sumOfTotalNodes(root->right) + root->data ;
}

// SUM AT LEVEL K

int sumAtKthLevel(node*root, int level) {

	int sum = 0;
	int k = 1;

	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node*currNode = q.front();
		q.pop();

		if (currNode != NULL ) {

			if (k == level)
				sum += currNode->data;

			if (currNode->left)
				q.push(currNode->left);
			if (currNode->right)
				q.push(currNode->right);

		} else if (currNode == NULL && !q.empty()) {
			k++;
			q.push(NULL);
		}
	}
	cout << " sum is : ";
	return sum;
}

// LEVEL ORDER TRAVERSAL

void printLevelOrder(node * root) {

	if (root == NULL)return;

	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node* currNode = q.front();
		q.pop();

		if (currNode != NULL) {
			cout << currNode->data << " ";
			if (currNode->left)
				q.push(currNode->left);
			if (currNode->right)
				q.push(currNode->right);
		}
		else if (currNode == NULL && (!q.empty())) {
			cout << endl;
			q.push(NULL);
		}
	}
}

// PREORDER PRINT

void preorderr(node * root) {
	if (root == NULL)return;

	cout << root->data << " ";
	preorderr(root -> left);
	preorderr(root -> right);
	return;
}

// POSTORDER PRINT

void postorderr(node * root) {
	if (root == NULL)return;


	postorderr(root -> left);
	postorderr(root -> right);
	cout << root->data << " ";

	return;
}

// INORDER PRINT

void inorderr(node * root) {
	if (root == NULL)return;


	inorderr(root -> left);
	cout << root->data << " ";
	inorderr(root -> right);

	return;
}


// BUILD BTREE FROM PREORDER AND INORDER !

node* buildTreeInAndPreorder(int *preorder , int *inorder , int start , int end) {
	if (start > end)return NULL;

	static int index = 0;

	int curr = preorder[index];
	node *n = new node( curr );
	++index;
	// cout << " making node data - " << n->data << " " << endl;

	if (start == end)return n;

	int pos  ;


	for (int i = start ; i <= end ; i++)
		if (curr == inorder[i] ) {
			pos = i ;
			break;
		}

	n->left = buildTreeInAndPreorder( preorder, inorder  , start , pos - 1 );
	n->right = buildTreeInAndPreorder( preorder, inorder  , pos + 1 , end);

	// if (! (n->left == NULL))
	// 	cout << " left subt " << n->left->data << " & ";

	// if (!(n->right == NULL))
	// 	cout << " right subt " << n->right->data << " ";

	return n;
}

// BUILD BTREE FROM POSTORDER AND INORDER !

node* buildTreeInAndPostorder(int *postorder , int *inorder , int start , int end) {
	if (start > end)return NULL;

	static int index = 4;

	int curr = postorder[index];
	node *n = new node( curr );
	--index;

	if (start == end)return n;

	int pos  ;
	for (int i = start ; i <= end ; i++)
		if (curr == inorder[i] ) {
			pos = i ;
			break;
		}

	n->right = buildTreeInAndPostorder( postorder, inorder  , pos + 1 , end);
	n->left = buildTreeInAndPostorder( postorder, inorder  , start , pos - 1 );

	return n;
}

int main(int argc, char const * argv[]) {

	/*

		preorder - root -> left -> right
		inorder - left -> root -> right
		postorder - left -> right -> root


	*/

	node * root = new node(10);

	root->left = new node(20);
	root->right = new node(30);

	root->left->left = new node(-40);
	root->left->right = new node(-50);

	root->right->left = new node(70);
	root->right->right = new node(80);

	node * root1 = new node(1);

	root1->left = new node(2);
	root1->right = new node(3);

	root1->left->left = new node(4);
	root1->left->right = new node(-5);

	root1->right->left = new node(9);
	root1->right->right = new node(5);

	// root->left->left->left = new node(540);
	// root->left->left->right = new node(750);


	node * root2 = NULL ;
	node * root3 = NULL ;

	int preorder[] = { 1, 2, 4 , 3 , 5 };
	int inorder[] = { 4 , 2 , 1 , 5 , 3 };
	int postorder[] = { 4 , 2 , 5 , 3 , 1 };

	// root2 = buildTreeInAndPreorder(preorder, inorder , 0 , 4  );
	// root3 = buildTreeInAndPostorder(postorder, inorder , 0 , 4   );
	// cout << endl;
	// inorderr(root2);
	// inorderr(root3);

	node* root4 = new node(100);

	root4->left = new node(200);
	root4->right = new node(300);

	root4->left->left = new node(400);
	root4->left->right = new node(500);

	root4->right->left = new node(700);
	root4->right->right = new node(800);

	root4->left->left->left = new node(760);
	root4->left->left->left->right = new node(860);

	printLevelOrder(root4);
	// cout << endl;
	// cout << sumAtKthLevel(root4 , 2) << endl;

	// cout << totalNodes(root4) << endl;
	// cout << sumOfTotalNodes(root4) << endl;

	// cout << "height " << height(root4) << endl;

	// cout << "diaMeter " << diaMeter(root4) << endl;
	int h = 0;
	// cout << "diaMeter opt " << diaMeterOptimized(root4, &h) << endl;

	// sumReplace(root4);

	// printLevelOrder(root4);

	// cout << endl;

	// cout << "isHeightBalanced " << isHeightBalanced(root4, &h)  << endl;

	// printRightView(root4);
	cout << endl;

	// printLeftView(root4);
	// cout << endl;

	// node* lca = findLCA(root4, 800, 860);

	// cout << "LCA : " << lca->data << endl;

	// cout << distanceBwNodes(root4, 800, 860) << endl;

	// flattenBTree2(root4);
	cout << endl;
	preorderr(root4);
	cout << endl;
	int n = kDistantNodes(root4, 200 , 3);
	cout << endl;

	cout << "max sum path :" << maxPath(root1);


	return 0;
}