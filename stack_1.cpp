#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;


class Stack {

	int n = 50;
	int currpos = -1;
	int *arr;
public:
	Stack() {
		arr = new int[n];
	}

	void push(int x) {
		if (currpos == n - 1) {
			cout << "Stack is full..." << endl;
			return;
		}

		currpos++;
		arr[currpos] = x;
	}

	void pop() {
		if (currpos == -1) {
			cout << "empty Stack cant pop..." << endl;
			return;
		}
		currpos--;
	}

	bool empty() {
		return currpos == -1;
	}

	int top() {
		if (currpos == -1)return -1;

		return arr[currpos];
	}

	~Stack() {
		delete arr;
	}

};

void reverseSentence(string sent) {

	stack<string>stack1;

	for (int i = 0; i < sent.length() ; ++i) {

		string word = "";
		while (sent[i] != ' ' && i < sent.length()) {
			word += sent[i];
			i++;
		}

		stack1.push(word);
	}

	while (!stack1.empty()) {
		cout << stack1.top() << " ";
		stack1.pop();
	}
	return;
}

int calcPrefixExp(string expressionn) {

	// debug(expressionn);
	int len = expressionn.length();
	stack<int>stack2;
	// debug(len);

	for (int i = len - 1; i >= 0; i--) {

		if (expressionn[i] >= '0' && expressionn[i] <= '9') {
			stack2.push(expressionn[i] - '0');
		} else {

			int operand1 = stack2.top() ;
			stack2.pop();
			int operand2 = stack2.top() ;
			stack2.pop();

			// debug(operand1);
			// debug(operand2);

			switch (expressionn[i]) {
			case '+':
				stack2.push( operand1 + operand2 );
				break;
			case '-':
				stack2.push( operand1 - operand2 );
				break;
			case '%':
				stack2.push( operand1 % operand2 );
				break;
			case '/':
				stack2.push( operand1 / operand2 );
				break;
			case '*':
				stack2.push( operand1 * operand2 );
				break;
			case '^':
				stack2.push( pow(operand1 , operand2) );
				break;
			}

		}

	}

	cout << stack2.top() << " ";
	return stack2.top();

}

int calcPostfixExp(string expressionn) {

	int len = expressionn.length();
	debug(expressionn);
	stack<int>stack2;

	for (int i = 0 ; i < len ; i++) {

		if (expressionn[i] >= '0' && expressionn[i] <= '9') {
			stack2.push(expressionn[i] - '0');

		} else {

			int operand2 = stack2.top() ;
			stack2.pop();
			int operand1 = stack2.top() ;
			stack2.pop();

			debug(operand1);
			debug(operand2);

			switch (expressionn[i]) {
			case '+':
				stack2.push( operand1 + operand2 );
				debug(stack2.top());
				break;
			case '-':
				stack2.push( operand1 - operand2 );
				debug(stack2.top());
				break;

			case '%':
				stack2.push( operand1 % operand2 );
				debug(stack2.top());
				break;

			case '/':
				stack2.push( operand1 / operand2 );
				debug(stack2.top());
				break;

			case '*':
				stack2.push( operand1 * operand2 );
				debug(stack2.top());
				break;

			case '^':
				stack2.push( pow(operand1 , operand2) );
				debug(stack2.top());
				break;


			default:
				break;
			}

		}

	}

	debug(stack2.top());
	return stack2.top();

}

int precedencee(char opr) {
	if (opr == '^')return 3;
	if (opr == '*' || opr == '/'  )return 2;
	if (opr == '+' || opr == '-')return 1;
	return -1;
}

string  infixToPostFix(string expressionn2) {

	stack<char>stack3;
	string result;
	int len = expressionn2.length();

	for (int i = 0; i < len ; ++i)
	{

		if ( (expressionn2[i] >= 'a' && expressionn2[i] <= 'z') || (expressionn2[i] >= 'A' && expressionn2[i] <= 'Z') )
			result += expressionn2[i];

		else if (expressionn2[i] == '(')
			stack3.push(expressionn2[i]);

		else if (expressionn2[i] == ')')
		{

			while (!stack3.empty() && stack3.top() != '(' )
			{
				result += stack3.top();
				stack3.pop();
			}

			if (!stack3.empty())stack3.pop();

		} else
		{

			while (!stack3.empty() && precedencee(stack3.top()) > expressionn2[i]  )
			{
				result += stack3.top();
				stack3.pop();
			}
						stack3.push(expressionn2[i]);
		}
	}

	while (!stack3.empty())
	{
		result += stack3.top();
		stack3.pop();
	}
	return result;
}

string infixToPreFix(			string expressionn2) {

	reverse(expressionn2.begin(), expressionn2.end());
	int len = expressionn2.length();
	string result = "" ;


	for (int i = 0; i < len; ++i)
	{
		if (expressionn2[i] == '(')expressionn2[i] = ')';
		else if (expressionn2[i] == ')')expressionn2[i] = '(';
	}

	debug(expressionn2);

	stack<char>stack3;

	for (int i = 0; i < len; ++i)
	{

		if ((expressionn2[i] >= 'a' && expressionn2[i] <= 'z') || (expressionn2[i] >= 'A' && expressionn2[i] <= 'Z'))
			result += expressionn2[i];
		else if (expressionn2[i] == '(')
			stack3.push('(');
		else if (expressionn2[i] == ')') {

			while (!stack3.empty() && stack3.top() != '(' ) {
				result += stack3.top();
				stack3.pop();
			}
			if (!stack3.empty())
				stack3.pop();
		}
		else {

			while (!stack3.empty() && precedencee( stack3.top() ) > expressionn2[i] ) {
				result += stack3.top();
				stack3.pop();
			}
			stack3.push(expressionn2[i]);
		}
	}

	while (!stack3.empty()) {
		result += stack3.top();
		stack3.pop();
	}

	reverse(result.begin(), result.end());
	return result;
}


class stackQueue1
{
	int N;
	queue<int>q1;
	queue<int>q2;

public:
	stackQueue1(){
		N = 0;
	}

	void push(int val){
		q2.push(val);

		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}

		queue<int>temp;
		temp = q1;
		q1 = q2;
		q2 = temp;
		N++;

		return;
	}

	void pop(){
		q1.pop();
		N--;
	}

	int top(){
		return q1.front();
	}

	int size(){
		return N;
	}

};


class stackQueue2
{
	int N;
	queue<int>q1;
	queue<int>q2;

public:
	stackQueue2(){
		N = 0;
	}

	void push(int val){
		q1.push(val);
		N++;
		return;
	}

	void pop(){

		if(q1.empty())return;

		int currSize= q1.size();
		while(currSize > 1){
			q2.push(q1.front());
			q1.pop();
			currSize--;
		}

		q1.pop();
		N--;
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}

	return;
	}

	int top(){
		int currSize= q1.size();
		while(currSize > 1){
			q2.push(q1.front());
			q1.pop();
			currSize--;
		}

		

		int elem = q1.front();
		 // q1.push(elem);
		q2.push(elem);
		N--;
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}

		return elem;
	}

	int size(){
		return N;
	}

};


int main(int argc, char const *argv[]) {

	Stack stk;
	stk.push(132);
	stk.push(32);
	stk.push(12);
	stk.push(2);
	stk.push(1);
	stk.pop();
	// cout << stk.top() << endl;

	// REVERSING A STACK:

	// string sent;
	// getline(cin, sent);
	// reverseSentence(sent);

	// string expressionn = "46+2/5*7+";
	// cin >> expressionn;
	// cout << calcPostfixExp(expressionn) << endl;


	string expressionn2 = "(a-b/c)*(a/k-l)";
	cout << infixToPreFix(expressionn2) << endl;

	// stackQueue1 stackq1;
	// stackq1.push(101);
	// stackq1.push(201);
	// stackq1.push(301);
	// stackq1.push(401);

	// cout<<stackq1.top()<<endl;
	// stackq1.pop();
	// cout<<stackq1.top()<<endl;


	stackQueue2 stackq1;
	stackq1.push(101);
	stackq1.push(201);
	stackq1.push(301);
	stackq1.push(401);

	cout<<stackq1.top()<<endl;
	stackq1.pop();
	cout<<stackq1.top()<<endl;


	return 0;
}