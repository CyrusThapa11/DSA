#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;

class Queue
{

	int * array;
	int front;
	int back;

public:
	Queue() {
		back = -1;
		front = -1;
		array = new int[100];
	}

	void push( int data ) {

		if (front > back) {
			cout << " Queue is full " << endl;
			return;
		}

		back++;
		array[back] = data;

		if (front == -1)
			front++;

	}

	void pop() {

		if (front == -1 || front > back) {
			cout << " cant remove " << endl;
			return;
		}

		front++;
		return;

	}

	int peek() {
		if (front == -1 || front > back) {
			cout << " no element to peek \n";
			return -1;
		}
		return array[front];
	}

	bool empty() {
		return front == -1;
	}


	~Queue() {
		delete array;
	}

};

class node
{
public:

	int data ;
	node*next;

	node(int d) {
		this->data = d;
		this->next = NULL;
	}

};

class QueueLL
{
	node *front , *back;

public:

	QueueLL() {
		front = NULL;
		back = NULL;
	}

	void push(int d) {
		node* newNode = new node(d);

		if (front == NULL) {
			front = newNode;
			back = newNode;
			return;
		}

		// debug(newNode->data);

		back->next = newNode;
		back = newNode;

		return;
	}

	void pop() {
		if (front == NULL  ) {
			cout << " no element to pop " << endl;
			return;
		}
		debug(front->data);
		node*temp = front;
		front = temp->next;
		delete temp;
		return;
	}

	int peek() {
		if (front == NULL) {
			cout << " no element \n";
			return -1;
		}
		debug(front->data);
		return front->data;
	}

	bool empty() {
		return front == NULL;
	}

	~QueueLL() {
		delete front;
		delete back;
	}

};


class QueueStk
{
public:

	stack<int>st1;
	stack<int>st2;

	void push(int x) {
		st1.push(x);
		return;
	}

	int popRecursive() {
		cout << st1.top() << endl;
		if (st1.empty()) {
			cout << " no element to pop" << endl;
			return -1;
		}

		int elem = st1.top();
		st1.pop();

		if (st1.empty())return elem;

		int item = popRecursive();
		st1.push(elem);

		return item ;
	}


	int pop() {

		if (st1.empty() && st2.empty()) {
			cout << " no element to pop" << endl;
			return -1;
		}

		while (!st1.empty()) {
			st2.push(st1.top());
			st1.pop();
		}

		int val = st2.top();
		st2.pop();

		while (!st2.empty()) {
			st1.push(st2.top());
			st2.pop();
		}

		return val;

	}

	bool empty() {
		return st1.empty() && st2.empty();
	}

	QueueStk() {}
};


int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


// #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
// #endif


	Queue Queue_;
	Queue_.push(12);
	Queue_.push(121);
	Queue_.push(212);
	Queue_.push(132);
	Queue_.push(1221);
	// cout << Queue_.peek() << " ";
	// Queue_.pop();
	// cout << Queue_.peek() << " ";

	// 	QUEUE USING LINKED LIST :

	cout << endl;
	QueueLL QueueLL_;
	QueueLL_.push(12);
	QueueLL_.push(121);
	QueueLL_.push(212);
	QueueLL_.push(132);
	QueueLL_.push(1221);
	cout << QueueLL_.peek() << endl;
	QueueLL_.pop();
	cout << QueueLL_.peek() << endl;


	QueueStk Queuestack;
	Queuestack.push(10);
	Queuestack.push(20);
	Queuestack.push(30);
	Queuestack.push(40);

	cout << " popping " << Queuestack.pop() << endl;
	cout << " popping " << Queuestack.pop() << endl;
	cout << " popping " << Queuestack.pop() << endl;

	Queuestack.push(300);
	Queuestack.push(400);
	cout << " popping " << Queuestack.popRecursive() << endl;
	cout << " popping " << Queuestack.popRecursive() << endl;

// DEQUE ------------------------------------------------


	deque<int>dq;
	dq.push_back(10);
	dq.push_front(20);
	dq.push_front(30);
	dq.push_back(40);
	dq.push_back(50);

	cout << endl;
	for (auto i : dq)
		cout << i << " ";

	cout << endl;

	dq.pop_back();
	dq.pop_front();

	for (auto i : dq)
		cout << i << " ";

	cout << dq.size() << endl;


// SLIDING WINDOW :

	// -----------------------------rainwater trapping :
	/*
		stack<int>	stack_;

		int n ;
		cin >> n;
		int arr[n];
		debug(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		// cout<<" hi "<<endl;

		stack_.push(arr[0]);
		int i = 1;
		int maxxH = arr[0] , ans = 0;

		while (!stack_.empty() && i < n ) {

			if (arr[i] <= arr[stack_.top()] ) {
				stack_.push(i);
			} else {

				while (!stack_.empty() && arr[stack_.top()] < arr[i] ) {

					int currIdx = i , prevIdx = stack_.top();
					stack_.pop();
					if (stack_.empty())break;

					int width = currIdx - stack_.top() - 1 ;
					int len = min(arr[currIdx] , arr[stack_.top()] ) - arr[prevIdx] ;
					ans += len * width;

				}
				stack_.push(i);

			}

			i++;

		}
		cout << ans;

		*/

	// -------------------------REDUNDANT PARENTHESIS

	/*
		string operations;
		cin >> operations;

		stack<int>stack_;
		bool isRedundant = 0;
		int len = operations.length();

		for (int i = 0; i < len ; ++i)
		{
			if (operations[i] == '(' or operations[i] == '-' or operations[i] == '+' or operations[i] == '/' or operations[i] == '*'  ) {
				stack_.push(operations[i]);
			} else if (operations[i] == ')') {

				if (stack_.top() == '(') {
					isRedundant = 1;
					break;
				} else {
					while (stack_.top() != '(')
						stack_.pop();
					stack_.pop();
				}
			}

		}

		if (isRedundant) {
			cout << endl << "YES isRedundant " << endl;
		} else
			cout << endl << "NOT isRedundant " << endl;
	*/

// -------------------------------stock span

	/*
		int n = 7 ;
		// cin >> n;
		int arr[] = {100, 80, 70, 60, 75, 85, 90} ;
		// for (auto &i : arr)
		// 	cin >> i;
		vector<int>answer;
		stack<pair<int, int>>stack_2;

		for (int i = 0; i < n; ++i) {

			int days = 1;
			while (!stack_2.empty() && stack_2.top().first <= arr[i]) {
				days += stack_2.top().second;
				stack_2.pop();
			}
			stack_2.push({arr[i], days});
			answer.push_back(days);
		}

		for (auto p : answer)
			cout << p << " ";
	*/

// ----------------  3 SUM

	/*
		int n = 6 , ans = 0;
		int target = 24;
		// cin>>n>>target;
		int arr[n] = {1, 3, 6, 9, 34, 25} ;
		// for (auto &i : arr)
		// 	cin >> i;
		sort(arr, arr + n);
		for (int i = 0; i < n; ++i)
		{
			int currElem = arr[i];
			int lowIndex = i + 1 , highIndex = n - 1;
			while (lowIndex < highIndex) {
				int currSum = currElem + arr[lowIndex] + arr[highIndex];
				if (currSum == target) {
					ans = 1;
					break;
				} else if (currSum < target ) {
					lowIndex++;
				} else
					highIndex--;
			}
			if (ans)break;
		}

		if (ans)cout << endl << " Yes possible " << endl;
		else cout << endl << " No not possible " << endl;
	*/

// ------------------ max consecutive ones with k swaps :

	/*
		int n = 5 ;
		// cin >> n;
		int arr[n] = { 1 , 0 , 0, 0 , 1};
		int zeroCount = 0 , ans = 0 , lowPointer = 0;
		int k  = 1;
		for (int j = 0; j < n; ++j)
		{
			if (arr[j] == 0)
				zeroCount++;

			while (zeroCount > k) {

				if (arr[lowPointer] == 0)
					zeroCount--;

				lowPointer++;
			}
			// debug(ans);
			ans = max(ans , j - lowPointer + 1);
		}
		cout << endl << ans << " is max no of ones " << endl;

	*/

// max non reapeating substring in string's length

	/*
		string string_ = "pwwekw";
		int start = -1, i = 0;
		int len = string_.length();
		int lastPositionOccured[26] = { -1 };
		int ans = 0;
		for (; i < len ; ++i) {

			char currChar = string_[i];

			if (lastPositionOccured[currChar - 'a'] > start )
				start = lastPositionOccured[currChar - 'a'];

			lastPositionOccured[currChar - 'a'] = i;
			ans = max(ans , i - start );
		}

		cout << endl << " max len : " << ans << endl;

		*/

	return 0;
}