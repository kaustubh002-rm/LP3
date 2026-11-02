#include<bits/stdc++.h>
using namespace std;

int iterative(int n){

    if(n <= 1) return n;

    int a = 0;
    int b = 1;

    for(int i=2; i<=n; i++){
        int c = a+b;
        a = b;
        b = c;
    }

    return b;
}

int recursive(int n){
    if(n <= 1)return n;

    return recursive(n-1)+recursive(n-2);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    cout<<"Result of iterative: "<<iterative(n)<<endl;
    cout<<"Result of Recursive: "<<recursive(n)<<endl;
}

// Comparison
// Parameter	Recursive	         Non-Recursive
// Approach	Function calls	     Iteration (loop)
// TC      	O(2ⁿ)	             O(n)
// SC      	O(n)	             O(1)
// Speed	    Slower	             Faster
// Memory      Higher	             Lower
// Efficiency	Less efficient	     More efficient