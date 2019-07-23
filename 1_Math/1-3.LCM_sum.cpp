// https://www.acmicpc.net/problem/1934

/*
�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�. 
�̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.
�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */


#include <iostream>
#include <string>

int gcd(int a, int b);

using namespace std;

int main()
{   
    int num;
    cin>>num;

    int arr[1000];

    // get input
    for (int i=0; i<num; i++){
        int A,B;
        cin>>A>>B;
        int GCD = gcd(A,B);
        int LCM = (A*B)/GCD;
        arr[i] = LCM;    
    }

    // print output
    for (int i=0; i<num; i++){
        cout<<arr[i]<<endl;  
    }

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