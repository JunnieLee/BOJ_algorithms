
#include <iostream>

int gcd(int a, int b);

using namespace std;

int main()
{   
    int test_num; // number of test cases
    cin>>test_num;

    int arr[100]; // array to store sum val per each line

    // [1] get input
    for (int i=0; i<test_num; i++){

        long GCD_sum = 0;
        long sub_arr[100];

        int num_num; // numer of numbers per each line
        cin>>num_num;
        
        for (int j=0; j<num_num; j++){
            int A;
            cin>>A;
            sub_arr[j] = A;    
        }

        // consider all pairs within the sub_arr
        for (int k_1=0; k_1< num_num; k_1++){
            for (int k_2=0; k_2< num_num; k_2++){
                if (k_1 != k_2){
                    int GCD = gcd(sub_arr[k_1], sub_arr[k_2]);
                    GCD_sum += GCD;
                }
            }
        }

        arr[i] = (long)(GCD_sum/2); // because the pair vals are added twice    
    }


    // [2] print output
    for (int i=0; i<test_num; i++){
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