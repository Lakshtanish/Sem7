#include <iostream>
using namespace std;


int recursive_fibo(int n){
    if(n <= 1) return n;
    return recursive_fibo(n-1) + recursive_fibo(n-2);
}

int iterative_fibo(int n){
    int a = 0; int b = 1; int c;

    for(int i = 0; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int choice;
    while(true){
        cout<<"Enter numberr: ";
        int n;
        cin>>n;
        cout<<"Enter 1 for recussive\n Enter 2 for iterative\n Enter 0 to exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice == 0) break;
        if(choice == 1) cout<<recursive_fibo(n)<<"\n";
        if(choice == 2) cout<<iterative_fibo(n)<<"\n";
    }
}