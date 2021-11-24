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

void hailStoneSequence(int n) {
   int num = n;
   int temp = n;

   while (temp > 1) {

      cout << temp << " ";
      if (temp & 1) {
         temp = temp * 3 + 1;
      } else temp /= 2;

      if (temp == 1) {
         break;
      }
   }
   cout << temp;

   return;
}

void solve() {

   int ans ;
   cin >> ans;
   hailStoneSequence(ans) ;

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