/*
https://www.acmicpc.net/problem/9613

양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.
 */

#include <iostream>

int gcd(int a, int b);

using namespace std;

int main()
{   
    int test_num; // number of test cases
    cin>>test_num;

    for (int i=0; i<test_num; i++){

        long long GCD_sum = 0;
        int sub_arr[100];

        int num_num; // numer of numbers per each line
        cin>>num_num;
        
        for (int j=0; j<num_num; j++){
            int A;
            cin>>A;
            sub_arr[j] = A;    
        }

        // consider all pairs within the sub_arr
        for (int k_1=0; k_1< num_num-1; k_1++){
            for (int k_2= (k_1 + 1); k_2< num_num; k_2++){
                GCD_sum +=  gcd(sub_arr[k_1], sub_arr[k_2]);
            }
        }

        // print output
        cout<< GCD_sum <<endl;
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



////////////////////////////////////////////////////////////////////////////////////////
/* 이 아래가 모범 답안

#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y,x%y);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[111];
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        long long sum=0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                sum += gcd(a[i],a[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}


 */