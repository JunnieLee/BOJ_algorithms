// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    for(string phone : phone_book) {
        map<string, int> m;
        int size = phone.length();
        
        for(string num : phone_book){ // ���� for loop 1 (compare each string)
            if(num.length() < size) continue; // ex) "1195524421" �� "119"�� ���� �ʿ䰡 ���� ������ continue;
            string cut_num = num.substr(0,size); // ex) "1195524421"�� ��� "119"�� �����.
            if(phone.compare(cut_num)==0){ 
                m[cut_num]++;
            }
        } // ���� for loop 1 ��
        
        map<string, int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){ // ���� for loop 2
            if(iter->second > 1) { // ���� ���� �ι� �̻��ϰ�� value�� 2 �̻��� �ɰ��̴�.
                return false;
            }
            // ���� ���� ÷��:
            // dereferencing a std::map iterator gives you a std::pair, 
            // you can then access its elements with first and second. 
            // For example, (*it).first will give you the key and (*it).second will give you the value. 
            // These are equivalent to it->first and it->second.
        } // ���� for loop 2 ��
        
    }
    return true;
}

// �ؽ� ������� �ߴµ�.. �ؽ��� �̿����� ���� Ǯ��..
// ��� �ؽ��� �̿��� �� ������?