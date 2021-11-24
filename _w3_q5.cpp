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

// POSTFIX -> OPERAND OPERAND OPERATOR
// EG - ((4*2)+3) = 4 2 * 3 +
// (5-(6/3)) = 5 6 3 / - ( COMP MOVES FROM LR)


// INFIX -> OPERAND OPERATOR OPERAND
// EG - ((4*2)+3) = (4*2) + 3

// PREFIX -> OPERATOR OPERAND OPERAND
// EG : ((4*2) + 3) -> + * 4 2 3
// EG : (5-(6/3) -> - 5 / 6 3

// evaluate prefix ->
// traverse from right
// if got a num . push to stack
// if got a op -> pop 2 elm from stack and
// apply the op. and push the result into stack

// evaluate postfix ->
//do same just traverse from L2R

// infix to postfix

void postToPre() {

   string text;
   cin >> text;

   // postfix to prefix :
   // iterate from L2R on post

   stack<string>stack_;
   int siz = text.size();

   for (int i = 0; i < siz ; ++i) {

      if (text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/' ) {

         // pick out 2 operands from stack:
         string op1 = stack_.top();
         stack_.pop();
         string op2 = stack_.top();
         stack_.pop();

         string temp = text[i] + op2 + op1;
         stack_.push(temp);

      } else {
         stack_.push(string(1, text[i]));
      }

   }

   string ans = "";

   while (!stack_.empty()) {
      ans += stack_.top();
      stack_.pop();
   }
   cout << ans << endl;



   return;
}


void preToPost() {

   string text;
   cin >> text;

   // postfix to prefix :
   // iterate from L2R on post

   stack<string>stack_;
   int siz = text.size();

   for (int i = siz - 1 ; i >= 0   ; --i) {

      if (text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/' ) {

         // pick out 2 operands from stack:
         string op1 = stack_.top();
         stack_.pop();
         string op2 = stack_.top();
         stack_.pop();

         string temp = op2 + op1 + text[i] ;
         stack_.push(temp);

      } else {
         stack_.push(string(1, text[i]));
      }

   }

   string ans = "";

   while (!stack_.empty()) {
      ans += stack_.top();
      stack_.pop();
   }
   cout << ans << endl;

   return;
}

int prec_( char ch ) {

   if (ch == '^')return 3;
   else if (ch == '*' || ch == '/' )return 2;
   else if (ch == '+' || ch == '-' )return 1;

   return -1;
}

void infixToPostfix() {

   string text;
   cin >> text;

   stack<char>stack_;
   string ans = "";

   for (int i = 0; i < text.size() ; ++i) {

      if (( text[i] >= 'a' && text[i] <= 'z' ) || (text[i] >= 'A' && text[i] <= 'Z' )  ) {
         ans += text[i] ;
      } else if ( text[i] == '(' ) {
         stack_.push(text[i]);
      } else if ( text[i] == ')' ) {

         while ( !stack_.empty() && stack_.top() != '(' ) {
            ans += stack_.top();
            stack_.pop();
         }

         if (!stack_.empty())
            stack_.pop();

      } else {

         while (!stack_.empty() && prec_(text[i]) < prec_(stack_.top()) ) {
            ans += stack_.top();
            stack_.pop();
         }
         stack_.push(text[i]);
      }
   }

   while (!stack_.empty()) {
      ans += stack_.top();
      stack_.pop();
   }

   cout << ans << endl;
   return;
}


void solve() {

   // infixToPostfix();
   // preToPost();
   postToPre();

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