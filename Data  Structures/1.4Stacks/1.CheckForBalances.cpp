

// Expression-                                    Solution- 

// 1. )( - Unbalanced                         1. Scan from left  to right
// 2. [()] - Balanced                         2. if opening symbol, add it to stack
// 3. [(]) - Unbalanced                       3. if closing symbol, remove last opening
// 4. [()()] - Balanced                          symbol from stack
//                                            4. should end with empty stack



#include<bits/stdc++.h>
#define ll long long
#include<stack>
#define ln "\n"
using namespace std;
bool ArePair(char opening, char ending){
	if (opening=='(' and ending==')')
		return true;
	else if (opening=='{' and ending=='}')
		return true;
	else if (opening=='[' and ending==']')
		return true;
	else
		return false;
}
void check_balanced(string str){
	stack<char> s;
	for(int i=0; i<str.length(); i++){
		if (str[i]=='(' or str[i]=='{' or str[i]=='['){
			s.push(str[i]);
		}
		else if(str[i]==')' or str[i]=='}' or str[i]==']')
		{
			if (s.empty() or !(ArePair(s.top(),str[i]))) {
					cout<<"Unbalanced"<<ln;
					return;
			}
			else{
				s.pop();
			}
		}
	}
	if (s.empty()){
		cout<<"Balanced"<<ln;
		return;
	}
	else{
		cout<<"Unbalanced"<<ln;
	}
}
int main()
{
	string s;
	s=")(";
	check_balanced(s); // Unbalanced
	s="[()]";
	check_balanced(s); // Balanced
	s="[(])";
	check_balanced(s); // Unbalanced
	s="[()()]";
	check_balanced(s); // Balanced
	return 0;
}
