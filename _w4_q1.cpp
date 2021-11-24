#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

void insertAtPos(stack<int>&stack_, int num) {

   if (stack_.empty() || stack_.top() <= num ) {
      stack_.push(num);
      return;
   }

   if (stack_.top() > num) {
      int num2 = stack_.top();
      stack_.pop();
      insertAtPos(stack_, num);
      stack_.push(num2);
      return;
   }
   return;
}

void sortStack(stack<int>&stack_) {
   if (stack_.empty()) {
      return;
   }

   int topp = stack_.top();
   stack_.pop();
   sortStack(stack_);

   insertAtPos(stack_, topp);
   return;
}

void solve() {

   stack<int>stack_, stack2;
   int n = 10;
   for (int i = 0; i < n; ++i) {
      stack_.push((100 + i ) % 13);
      stack2.push((100 + i ) % 13);
   }

   cout << "elem of initial stack " << endl;
   while (!stack2.empty()) {
      cout << stack2.top() << " " ;
      stack2.pop();
   }

   cout << "sorted stack" << endl;
   sortStack(stack_);
   while (!stack_.empty()) {
      cout << stack_.top() << " " ;
      stack_.pop();
   }

   return;
}

int main() {

   fastInput();

   int t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}