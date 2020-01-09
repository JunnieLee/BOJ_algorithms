/*
https://www.acmicpc.net/problem/1929

M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 */


#include <iostream>

using namespace std;

int main()
{   
    int start, finish;
    cin>>start>>finish;

    int prime[finish-start+1]; // array to store prime numbers
    int num=0; // number of primes
    int check[finish-start+1]={0}; // if erased, marked as "True"
    

    for (int i=2; i<=finish; i++){
        if (check[i]==0){ // if the number is not erased yet
            prime[num++]=i;
            for (int j=i+i; j<=finish; j+=i){ //  for (int j=i*i; j<=finish; j+=i) 
                check[j] = 1;
            }
        }
    } // marking all done

    // print out the prime numbers from range start~finish
    for (int k=0; k < num; k++){
        if (prime[k]>=start){
            cout<< prime[k] <<endl;
        }
    }

    return 0;
}
