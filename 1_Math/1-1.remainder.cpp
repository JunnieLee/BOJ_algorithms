// https://www.acmicpc.net/problem/10430
// ù° �ٿ� (A+B)%C, ��° �ٿ� (A%C + B%C)%C, ��° �ٿ� (A��B)%C, ��° �ٿ� (A%C �� B%C)%C�� ����Ѵ�.


#include <iostream>
#include <string>

using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    
    cout<< (A+B)%C <<endl;
    cout<< (A%C + B%C)%C <<endl;
    
    cout<< (A*B)%C <<endl;
    cout<< (A%C * B%C)%C <<endl;
    
  
    return 0;
}
