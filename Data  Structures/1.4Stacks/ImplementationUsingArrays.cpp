#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;
void Push(int data){
  if (top==MAX_SIZE-1){
    cout<<"Error: Stack Overflow\n";
    return;
  }
  A[++top]=data;
}
void Pop(){
  if(top==-1){
    cout<<"Error: No element to pop"<<ln;
    return;
  }
  top--;
}
int Top(){
  return A[top];
}
void Print(){
  int i;
  cout<<"Stack"<<ln;
  for(i=0;i<=top;i++)
    cout<<A[i]<<" ";
  cout<<ln;
}
int main(){
  // Your code goes here
  Push(2);
  Print();
  Push(5);
  Print();
  Push(10);
  Print();
  Pop();
  Print();
  Push(12);
  Print();
}



