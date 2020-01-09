// https://www.acmicpc.net/problem/2609
// 첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

#include <iostream>

int gcd(int a, int b);

using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

    int GCD = gcd(A,B);
    int LCM = (A*B)/GCD;

    // GCD - 최대공약수
    cout<< GCD <<endl;

    // LCM - 최소공배수
    cout<< LCM <<endl;
  
    return 0;
}

// Euclidean algorithm
// recursive version
int gcd(int a, int b){
        if (b==0){
            return a;
        } else {
            return gcd(b, a%b);
        }
}