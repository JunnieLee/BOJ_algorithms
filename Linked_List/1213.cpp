// https://www.acmicpc.net/problem/1213

// 순열로 모든 경우를 구하는 것이 아니라, 다른 방법으로 구해줘야 한다. (시간초과 문제)

// 1. 인풋 문자열로 팰린드롬이 가능한지 부터 따져봄.
// -> 홀수개인 알파벳이 1개를 초과하면 팰린드롬 문자열이 될 수 없음.
//    즉, 팰린드롬 문자열이 되기 위해서는 문자열속에 존재하는 모든 알파벳이 짝수개 있거나, 홀수개 존재하는 알파벳이 한 개만 존재해야 한다. 


// 2. 입력과 동시에, 문자열 속에 존재하는 알파벳의 갯수를 Count. 
// -> 홀수인 알파벳에 대해서는 총 몇개인지 , 홀수인 알파벳을 따로 저장 (홀수 알파벳 종류가 2개 이상이 되면 곧바로 Sorry 문구 출력)


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
    odd = 0; // 홀수개인 알파벳 종류의 개수
    
    for (int i = 0; i < ALPHABET; i++) { 
        if (alphabet[i] % 2 == 1) { 
            odd++; 
            odd_index = i; 
        } 
    } 
    
    if (odd > 1) {  // 홀수번 등장한 알파벳이 1개를 초과하면 팰린드롬을 만들 수 없다. 
        result = "I\'m Sorry Hansoo"; 
    } 
    
    // 홀수번 등장한 알파벳이 1번이면 
    // AAABBBA -> AABBBAA 
    else if (odd == 1) { 
        char odd_char = odd_index + 'A'; 
        // temp : 홀수번 등장한 알파벳을 제외한 string 저장. 
        // AAABBBA -> AAABBA, odd_char = 'B' 
        string temp = ""; 
        bool do_once = true; 
        for (int i = 0; i < input_size; i++) { 
            if (do_once && input[i] == odd_char) { 
                do_once = false; // 첫번째나왔을땐 temp에 concat안시켜줌
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
        
    // 모두 짝수번 등장. 
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



