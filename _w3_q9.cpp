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

   string text;
   cin >> text;
   stack<char>stack_;
   queue<char>queue_;

   for (int i = 0; i < text.size(); ++i) {
      char ch = tolower(text[i]);
      stack_.push(ch);
      queue_.push(ch);
   }
   bool ans = 1;
   while (1) {

      if (  stack_.top() == queue_.front()) {
         stack_.pop();
         queue_.pop();
         if (stack_.empty() && queue_.empty() )break;
      } else   {
         cout << "NO not a pallindrome" << endl;
         return;
      }
   }

   cout << "YES it is a pallindrome" << endl;


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