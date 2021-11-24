#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//---------------------------------------------------------------------------
void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

void solve() {

   int n;
   cin >> n;

   stack<int>stack1, stack2, stack3;
   for (int i = 1; i <= n; ++i) {
      stack1.push( (100 + i) % 13);
      stack3.push( (100 + i) % 13);
   }

   cout << "inital stack" << endl;
   while (!stack3.empty()) {
      cout << stack3.top() << " ";
      stack3.pop();
   }

   int div = n / 2;
   while ( div >= 1 ) {
      stack2.push(stack1.top());
      stack1.pop();
      div--;
   }

   cout << "elem of 1st stack after dividing" << endl;
   while (!stack1.empty()) {
      cout << stack1.top() << " " ;
      stack1.pop();
   }

   while (!stack2.empty()) {
      stack3.push(stack2.top());
      stack2.pop();
   }

   cout << "elem of 2nd stack after dividing" << endl;

   while (!stack3.empty()) {
      cout << stack3.top() << " " ;
      stack3.pop();
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