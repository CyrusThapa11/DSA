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

void moveNFront(queue<int> q_, int index) {

   vector<int>stack_;

   int i = 1;
   int num = 0;
   while (1) {

      if (i == index) {
         num = q_.front();
         q_.pop();
         break;
      }

      i++;
      stack_.push_back(q_.front());
      q_.pop();
   }
   queue<int>q_2;
   q_2.push(num);

   for (auto i = stack_.begin() ; i != stack_.end() ; ++i) {
      q_2.push(*i);
   }

   while (!q_.empty()) {
      q_2.push(q_.front());
      q_.pop();
   }

   cout << " elem of new queue is " << endl;
   while (!q_2.empty()) {
      cout << q_2.front() << " ";
      q_2.pop();
   }

   return;
}

void solve() {

   int n , n2;
   cin >> n;
   n2 = n;
   queue<int>q_;

   while (n2--) {
      int num;
      cin >> num;
      q_.push(num);
   }
   int index;
   cin >> index;
   moveNFront(q_, index);


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