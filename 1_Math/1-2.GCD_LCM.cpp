// https://www.acmicpc.net/problem/2609
// ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������,��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.

#include <iostream>

int gcd(int a, int b);

using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

    int GCD = gcd(A,B);
    int LCM = (A*B)/GCD;

    // GCD - �ִ�����
    cout<< GCD <<endl;

    // LCM - �ּҰ����
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