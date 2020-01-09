/*
https://www.acmicpc.net/problem/1978

�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
    // n�� �Ҽ��� �Ƿ��� 2 �̻�, ��Ʈn ������ �ڿ����� ������ �������� �ȵȴ�.
    for (int i=2; i*i <=n; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}