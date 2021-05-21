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

With the simple modification of randomly permuting array, we can get the same performance
as with the previous HIRE_ASSISTANT algorithm.
***************************************************************
Why Randomization of array ?
For a problem such as the hiring problem, in which it is helpful to assume that
all permutations of the input are equally likely, a probabilistic analysis can guide
the development of a randomized algorithm. Instead of assuming a distribution
of inputs, we impose a distribution. In particular, before running the algorithm,
we randomly permute the candidates in order to enforce the property that every
permutation is equally likely. Although we have modified the algorithm, we still
expect to hire a new office assistant approximately ln n times. But now we expect
this to be the case for any input, rather than for inputs drawn from a particular
distribution.
**************************************************************
Ways to randomize the array are given in below functions, this includes,
1. Permute by Sorting 
2. 
Pseudo-Code -> 
RANDOMIZED_HIRE_ASSISTANT
randomly permute the array
best = 0 // dummy candidate which is least-qualified
for i = 1 to n
    interview candidate i
    if candidate i is better than the best candidate
    best = i
    hire candidate i

Analysis of Hire Assistant Algorithm
1. The expected hiring cost of the procedure RANDOMIZED-HIRE-ASSISTANT is
O(ch*ln n).
2. Worst - Case - This occurs if we hire every candidate that we interview, this results in cost of O(ch*n).
*/
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>
using namespace std;

int Random(int lower, int upper) 
{ 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num; 
} 
/*
Procedure - 
assign each element AOEi of the array a random priority
P [i], and then sort the elements of A according to these priorities. For example,
if our initial array is A = {1; 2; 3; 4} and we choose random priorities
P = {36; 3; 62; 19}, we would produce an array B = {2; 4; 1; 3}, since the second
priority is the smallest, followed by the fourth, then the first, and finally the third.
We call this procedure PERMUTE-BY-SORTING:
************************************************************8
Pseudo Code for Permute_By_Sorting
PERMUTE_BY_SORTING(A)
1. n=A.length
2. let P[1....n] new array
3. for i =1 to n
4.   p[i] = RANDOM(1, n^3) // generate random value from 1 to n^3 as key
5. sort(A), with P as sort keys
*/
int Permute_By_Sorting(int a[], int n){
    int p[n];
    for (int i=0; i<n; i++){
        p[i]= Random(1, pow(n,3));
        

    }
}

int Randomized_Hire_Assistant(int a[], int size){
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
    //int result=Randomized_Hire_Assistant(a, sizeof(a)/sizeof(a[0]));
    
    return 0;
}

