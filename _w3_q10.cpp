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

   bool foundx = 0;
   bool foundy = 0;
   string ans = "";
   int firstY = 1;

   for (int i = 0; i < text.size() ; ++i) {
      if (text[i] == 'X' ) {
         foundx = 1;
      }

      if (foundx && (text[i] == 'Y')) {
         foundy = 1;
         firstY++;
      }

      if (foundx && foundy) {
         if ((text[i] == 'Y') && (firstY == 3)) {
            break;
         } else {

            if (text[i] != 'Y')
               ans += text[i];
         }
      }
   }

   reverse(ans.begin(), ans.end());
   cout << ans << endl;



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