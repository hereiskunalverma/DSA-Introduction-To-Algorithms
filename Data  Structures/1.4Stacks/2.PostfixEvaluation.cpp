/*
  Evaluation Of postfix Expression in C++ 
  Input Postfix expression must be in a desired format. 
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected. 
*/


#include<bits/stdc++.h>
#include<stack>
#define ll long long
#define ln "\n"
using namespace std;
// Function to verify whether a character is operator symbol
bool IsOperator(char C){
	if (C=='+' or C=='-' or C=='*' or C=='/')
		return true;
	return false;
}
// Funtion to perform an operation and return output
int PerformOperation(char operation, int x, int y){
	if(operation=='+')return x+y;
	else if (operation=='-')return x-y;
	else if (operation=='*')return x*y;
	else if (operation=='/')return x/y;
	else
		cout<<"Unexpected Error\n";
	return -1;
}
// Function to verify whether a character is numeric digit
bool IsNumericDigit(char C){
	if (C>='0' and C<='9')return true;
	return false;
}
// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression){
	stack<int> s;
	for(int i=0;i<expression.length();i++){
		// Scanning each character from left
		// If character is a delimiter, move on.
		if((expression[i]==' ' or expression[i]==','))continue;
		// If character is operator, pop two elements
		else if (IsOperator(expression[i])){
			// Pop two operands
			int operand2=s.top();s.pop();
			int operand1=s.top();s.pop();
			// Perform operation
			int res=PerformOperation(expression[i],operand1,operand2);
			// Push back result of operation on stack
			s.push(res);
		}
		else if (IsNumericDigit(expression[i])){
			// Extract the numeric operand from the string
			// keep incrementing i as long as we are getting a numeric value
			int operand=0;
			while(i<expression.length() and IsNumericDigit(expression[i])){
				// For a numeric with more than one digits, as we are scanning from left to right
				// Everytime, we get a digit towards right, we can multiply current operand by 10
				// and add the new digit
				operand=(operand*10)+(expression[i]-'0');
				i++;
			}
			// Finally we will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again.
			// We do not want to skip the non-numeric character by incrementing i twice.
			i--;

			// Push operand on stack
			s.push(operand);
		}
	}
	// If expression is corrent format, stack will finally have one element as our result
	return s.top();
}



int main()
{
	string expression;
	expression="2 3 * 5 4 * + 9 -";
	// getline(cin,expression);
	int res=EvaluatePostfix(expression);
	cout<<"Output : "<<res<<ln; // 17
	return 0;
  
}
