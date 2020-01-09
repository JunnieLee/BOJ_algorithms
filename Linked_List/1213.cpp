// https://www.acmicpc.net/problem/1213

// ������ ��� ��츦 ���ϴ� ���� �ƴ϶�, �ٸ� ������� ������� �Ѵ�. (�ð��ʰ� ����)

// 1. ��ǲ ���ڿ��� �Ӹ������ �������� ���� ������.
// -> Ȧ������ ���ĺ��� 1���� �ʰ��ϸ� �Ӹ���� ���ڿ��� �� �� ����.
//    ��, �Ӹ���� ���ڿ��� �Ǳ� ���ؼ��� ���ڿ��ӿ� �����ϴ� ��� ���ĺ��� ¦���� �ְų�, Ȧ���� �����ϴ� ���ĺ��� �� ���� �����ؾ� �Ѵ�. 


// 2. �Է°� ���ÿ�, ���ڿ� �ӿ� �����ϴ� ���ĺ��� ������ Count. 
// -> Ȧ���� ���ĺ��� ���ؼ��� �� ����� , Ȧ���� ���ĺ��� ���� ���� (Ȧ�� ���ĺ� ������ 2�� �̻��� �Ǹ� ��ٷ� Sorry ���� ���)


#include <bits/stdc++.h> 
#define ALPHABET 26 
using namespace std; 

int alphabet[ALPHABET]; 
string result; 

int main() { 
    string input; 
    cin >> input; 
    int input_size = input.size(); 
    
    for (int i = 0; i < input_size; i++) {
        alphabet[input[i] - 'A']++;
    } 
    
    int odd_index, odd; 
    odd_index = -1; 
    odd = 0; // Ȧ������ ���ĺ� ������ ����
    
    for (int i = 0; i < ALPHABET; i++) { 
        if (alphabet[i] % 2 == 1) { 
            odd++; 
            odd_index = i; 
        } 
    } 
    
    if (odd > 1) {  // Ȧ���� ������ ���ĺ��� 1���� �ʰ��ϸ� �Ӹ������ ���� �� ����. 
        result = "I\'m Sorry Hansoo"; 
    } 
    
    // Ȧ���� ������ ���ĺ��� 1���̸� 
    // AAABBBA -> AABBBAA 
    else if (odd == 1) { 
        char odd_char = odd_index + 'A'; 
        // temp : Ȧ���� ������ ���ĺ��� ������ string ����. 
        // AAABBBA -> AAABBA, odd_char = 'B' 
        string temp = ""; 
        bool do_once = true; 
        for (int i = 0; i < input_size; i++) { 
            if (do_once && input[i] == odd_char) { 
                do_once = false; // ù��°�������� temp�� concat�Ƚ�����
                continue; 
            } 
            temp += input[i]; 
        } 

        // temp = AAAABB 
        // half = AAB 
        sort(temp.begin(), temp.end()); 
        string half = ""; 
        int temp_size = temp.size(); 
        for (int i = 0; i < temp_size; i += 2) { 
            half += temp[i]; 
        } 
        result = half + odd_char; 

        // half = BAA 
        reverse(half.begin(), half.end()); 
        result += half; 
    } 
        
    // ��� ¦���� ����. 
    // ABAABA -> AABBAA 
    else { 
        sort(input.begin(), input.end()); 
        string half = ""; 
        for (int i = 0; i < input_size; i += 2) { 
            half += input[i]; 
        } 
        result += half; 
        reverse(half.begin(), half.end()); 
        result += half; 
    } 
        
    cout << result; 
}



