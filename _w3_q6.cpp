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

      if (text[i] == '(' || text[i] == '{' || text[i] == '[' || (text[i] == '/' && text[i + 1] == '*' ) ) {

         stack_.push(text[i]);
         if (text[i] == '/') {
            i++;
         }
      }
      else if ( (text[i] == ')' && (stack_.top() == '('))
                || ( text[i] == '}'  && (stack_.top() == '{'))
                || (text[i] == ']'  && (stack_.top() == '['))
                || (text[i] == '*' && text[i + 1] == '/' && stack_.top() == '/')) {

         stack_.pop();
         if (text[i] == '*') {
            i++;
         }
      } else {
         cout << "not balanced" << endl;
         return;
      }
   }

   cout << "YES a balanced string " << endl;

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