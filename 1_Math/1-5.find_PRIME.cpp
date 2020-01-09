/*
https://www.acmicpc.net/problem/1978

주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
 */

#include <iostream>

bool isPrime(int n);

using namespace std;

int main()
{   
    int result=0;

    int num;
    cin>>num;

    while (num--){
        int n;
        cin>>n;
        if (isPrime(n)) result++;
    }
    cout<< result <<endl;

    return 0;
}


bool isPrime(int n){
    if (n < 2){
        return false;
    }
    // n이 소수가 되려면 2 이상, 루트n 이하의 자연수로 나누어 떨어지면 안된다.
    for (int i=2; i*i <=n; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}