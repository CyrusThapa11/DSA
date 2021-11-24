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


void reverseString(string &str) {

   stack<char>stack_;

   for (int i = 0; i < str.length(); ++i) {
      stack_.push(str[i]);
   }
   str = "";
   while (!stack_.empty()) {
      char st = stack_.top();
      str += (st);
      stack_.pop();
   }

   cout << "reversed string : " << str << endl;


   return;
}

void solve() {

   string ans = "";
   cin >> ans;
   reverseString(ans) ;

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