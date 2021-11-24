#include <bits/stdc++.h>
using namespace std;

void fastInput() {
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
	node* left;
	node* right;

	node( int d ) {
		this->data = d;
		left = NULL;
		right = NULL;
	}
	~node();

};

class genNode {

public:
	int data;
	vector<genNode*> children;
	genNode(int d) {
		this->data = d;
	}

};


// NODES AT A DIST. OF K UNITS FROM TARGET !


void printGenTree(genNode*root) {

	// cout << root->data << "\n";
	// for (int i = 0 ; i < root->children.size(); i++) {
	// 	cout << root->children[i]->data << " ";
	// }

	queue<genNode*>st_;
	st_.push(root);

	// st_.push(NULL);

	// while ( !st_.empty() ) {
	// 	genNode*currNode = st_.front();
	// 	st_.pop();

	// 	if (currNode != NULL) {
	// 		cout << currNode->data << " ";

	// 		for (int i = 0 ; i < currNode->children.size(); i++) {
	// 			st_.push(currNode->children[i]);
	// 	 	}

	// 	} else if ( currNode == NULL && !st_.empty()) {
	// 		cout << "\n";
	// 		st_.push(NULL);
	// 	}
	// }

	while (!st_.empty()) {

		int siz = st_.size();

		for (int i = 0; i < siz; ++i)	{
			genNode*currNode = st_.front();
			st_.pop();
			cout << currNode->data << ' ';

			for (int j = 0; j < currNode->children.size() ; ++j)
				st_.push(currNode->children[j]);
		}
		cout << endl;
	}
	return;
}

genNode* makeGenTree( genNode * root ) {

	stack<genNode*>st_;
	int n;
	cin >> n;
	root = new genNode(n);
	st_.push(root);

	while (!st_.empty()) {

		genNode* currNode = st_.top();

		int num;
		cin >> num;
		if (num != -1) {
			genNode* child = new genNode(num);
			currNode->children.push_back(child);
			st_.push(child);
		} else {
			st_.pop();
		}
	}

	printGenTree(root);
	return root;
}

bool findd(genNode* root, int key, vector<genNode*> &vec_ ) {

	if (root->data == key) {
		vec_.push_back(root);
		return 1;
	}

	for (int i = 0; i < root->children.size(); ++i) {
		bool found = findd(root->children[i] , key, vec_ );
		if (found) {
			vec_.push_back(root);
			return 1;
		}
	}

	return 0;
}

void find_helper(genNode* root, int key) {
	vector<genNode*>vec_;

	bool ans = findd(root, key, vec_);

	for (int i = 0 ; i < vec_.size() ; i++) {
		cout << vec_[i]->data << " ";
	}

	return;
}

void findLca(genNode* root, int d1 , int d2) {

	vector<genNode*>vec_1 ;
	vector<genNode*>vec_2 ;

	findd(root, d1, vec_1);
	findd(root, d2, vec_2);

	int i = vec_1.size() ,  j = vec_2.size();

	while (j >= 0 && i >= 0 && vec_1[i] == vec_2[j] ) {
		j--;
		i--;
	}

	j++;
	i++;

	cout << "lca of " << d1 << " ," << d2 << " is : " << vec_1[i]->data << '\n';

	return;
}

int main(int argc, char const * argv[]) {
	fastInput();

	/*

		preorder - root -> left -> right
		inorder - left -> root -> right
		postorder - left -> right -> root


	*/


//---------------------GENERIC TREE:-------------

	cout << endl;
// 	cout << endl;
	genNode* root;

	root = makeGenTree(root);

// find the node and its path in the generic tree :
	int key = 110;
	cout << "the path from node to root is :\n";
	find_helper(root, key);

	findLca(root, 110, 120);

	return 0;
}