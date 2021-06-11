/*

Process :

Iterate the expression,

1. if operand, print
2. if '(', push to stack
3. if ')',

    print and pop while s.top!='('

    if s.empty:
      s.pop

4. if operator,

   print and pop while precedence of top > precedence of current operator

   push current operator to stack

5. if not empty stack, print and pop

*/


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


using namespace std;
#define ln "\n"
bool isOperand(char c) {
  return isalpha(c);
}
int precedence(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' or c == '*')
    return 2;
  else if (c == '+' or c == '-')
    return 1;
  return -1;
}
string InfixToPostfix(string str) {
  stack<char> s;
  string res;
  for (int i = 0; i < str.length(); i++) {
    if (isOperand(str[i]))
      res += str[i];
    else if (str[i] == '(')
      s.push(str[i]);
    else if (str[i] == ')') {
      while (not s.empty() and s.top() != '(') {
        res += s.top();
        s.pop();
      }
      if (not s.empty())
        s.pop();
    }
    else {
      while (not s.empty() and precedence(s.top()) > precedence(str[i])) {
        res += s.top();
        s.pop();
      }
      s.push(str[i]);
    }
  }
  while (not s.empty()) {
    res += s.top();
    s.pop();
  }
  return res;
}
int main()
{
  string expression = "(a-b/c)*(a/k-l)";
  cout << "Postfix : " << InfixToPostfix(expression) << ln;
  // output : abc/-ak/l-*
  return 0;
}