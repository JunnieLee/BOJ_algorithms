// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    for(string phone : phone_book) {
        map<string, int> m;
        int size = phone.length();
        
        for(string num : phone_book){ // 이중 for loop 1 (compare each string)
            if(num.length() < size) continue; // ex) "1195524421" 로 "119"를 비교할 필요가 없기 때문에 continue;
            string cut_num = num.substr(0,size); // ex) "1195524421"의 경우 "119"만 남긴다.
            if(phone.compare(cut_num)==0){ 
                m[cut_num]++;
            }
        } // 이중 for loop 1 끝
        
        map<string, int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){ // 이중 for loop 2
            if(iter->second > 1) { // 같은 수가 두번 이상일경우 value는 2 이상이 될것이다.
                return false;
            }
            // 문법 설명 첨부:
            // dereferencing a std::map iterator gives you a std::pair, 
            // you can then access its elements with first and second. 
            // For example, (*it).first will give you the key and (*it).second will give you the value. 
            // These are equivalent to it->first and it->second.
        } // 이중 for loop 2 끝
        
    }
    return true;
}

// 해쉬 문제라고 했는데.. 해쉬를 이용하지 않은 풀이..
// 어떻게 해쉬를 이용할 수 있을까?