// https://programmers.co.kr/learn/courses/30/lessons/42577

// shorter algorithm

#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++){
        if (phone_book[i+1].find(phone_book[i]) == 0) // 더 긴데서 더 작은데가 부분적으로 있는지 찾겠지
            return false;
    }
    
    return true;
}