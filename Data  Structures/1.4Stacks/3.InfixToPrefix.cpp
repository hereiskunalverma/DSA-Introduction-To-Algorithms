/*
  Infix to postfix conversion in C++
  Input Postfix expression must be in a desired format.
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.

  Process :
  reverse the expression
  replace ( with ) or below is the trick [in function consider '(' with ')'],

  Iterate over the expression,
  1. if operand, print it
  2. if '(', push to stack
  3. if ')',

       print and pop till we get ')' from stack
       if not empty stack
         pop the last
  4. if operator,

      print and pop while the precedence of top is greater than current operator

      push the new operator

  5. reverse the result



*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

string InfixToPrefix(string str)
{	// below is the implementation without replacing '(' with ')'
	reverse(str.begin(), str.end());
	stack<char> s;
	string res;
	for (int i = 0; i < str.length(); i++) {
		if (isOperand(str[i]))
			res += str[i];
		else if (str[i] == ')') {
			s.push(str[i]);
		}
		else if (str[i] == '(' and not s.empty()) {
			while (s.top() != ')') {
				res += s.top();
				s.pop();
			}
			if (not s.empty())
				s.pop();
		}
		else {
			while (not s.empty() and precedence(s.top()) >= precedence(str[i])) {
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
	reverse(res.begin(), res.end());

	return res;

}
int main()
{
	string expression = "(a-b/c)*(a/k-l)";
	cout << InfixToPrefix(expression) << ln;

	// output : *-a/bc-/akl
	return 0;
}