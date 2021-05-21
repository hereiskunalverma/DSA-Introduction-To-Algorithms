/*
Problem Statement - 

Suppose that you need to hire a new office assistant. Your previous attempts at
hiring have been unsuccessful, and you decide to use an employment agency. The
employment agency sends you one candidate each day. You interview that person
and then decide either to hire that person or not. You must pay the employment
agency a small fee to interview an applicant. To actually hire an applicant is more
costly, however, since you must fire your current office assistant and pay a substantial
hiring fee to the employment agency. You are committed to having, at all times,
the best possible person for the job. Therefore, you decide that, after interviewing
each applicant, if that applicant is better qualified than the current office assistant,
you will fire the current office assistant and hire the new applicant. You are willing
to pay the resulting price of this strategy, but you wish to estimate what that price
will be.
The procedure HIRE-ASSISTANT, given below, expresses this strategy for hiring
in pseudocode. It assumes that the candidates for the office assistant job are numbered
1 through n. The procedure assumes that you are able to, after interviewing
candidate i , determine whether candidate i is the best candidate you have seen so
far. To initialize, the procedure creates a dummy candidate, numbered 0, who is
less qualified than each of the other candidates.

Pseudo-Code -> 
HIRE_ASSISTANT
best = 0 // dummy candidate which is least-qualified
for i = 1 to n
    interview candidate i
    if candidate i is better than the best candidate
    best = i
    hire candidate i

Analysis of Hire Assistant Algorithm
1. Assuming that the candidates are presented in a random order, algorithm HIREASSISTANT
has an average-case total hiring cost of O(ch * ln n), Calculated by using Indicator Random Variables
2. Worst - Case - This occurs if we hire every candidate that we interview, this results in cost of O(ch*n).
*/

#include <iostream>
using namespace std;

int Hire_Assistant(int a[], int size){
    int best=0;
    int hire_candidate=0;
    for (int i=0; i<size; i++){
        int interview_candidate = a[i];        
        if (interview_candidate>best){
            best=interview_candidate;
            hire_candidate=best;
        }
    }
    return hire_candidate;
}


int main(){
    int a[] = {1,2,3,4,5,5,6,19};
    int result=Hire_Assistant(a, sizeof(a)/sizeof(a[0]));
    cout<<result<<endl;
    return 0;
}