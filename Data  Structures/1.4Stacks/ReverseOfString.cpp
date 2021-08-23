#include<bits/stdc++.h>
#define ll long long
#include<stack>
#define ln "\n"
using namespace std;

void Reverse(char *c, int n){
	stack<char> s;
	// loop for push
	for(int i=0; i<n; i++){
		s.push(c[i]);
	}
	// loop for pop
	for(int i=0;i<n;i++){
		c[i]=s.top(); // setting charcter at i
		s.pop();
	}
}
int main()
{
  char s[100];
  gets(s);
  Reverse(s,strlen(s));
  cout<<s<<ln;
}
