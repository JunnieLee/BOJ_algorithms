// https://www.acmicpc.net/problem/1158



#include <iostream>

using namespace std;

class Node {
    public:
	    int value;
	    Node * next;
};

class Circular_Linked_List{ 
    
    private: 
        Node *head;
        Node *tail;
        int size = 0; // 링크 길이 
        
    public: 
        // 1. 생성자
        Circular_Linked_List() : head(nullptr), tail(nullptr) {}
        
        // 2. 일반 Add
        void AddNode(int num){ // 맨 뒤에 할당
            Node *node = new Node; //노드 동적 할당 
            size++; 
            node->value = num; 
            node->next = nullptr; 
            if (head == nullptr) { // 첫 adding일 때
                head = node; 
                tail = node;
            } 
            else{ 
                tail->next = node; 
                tail = node;
                tail->next = head; // circular라서 추가해준 내용! 
            } 
        } 
        
        // 3. 특수 Remove (순서기반)
        void RemoveNode(Node starter_node, int order_num) { // starter_node에서부터 order_num번째 원소 지우기
            if (order_num>size){
                order_num = order_num%size;
            }
            size--;

            Node *ptr = starter_node; 
            Node *tmp = ptr; 

            for (int i=1; i < order_num; i++){
                tmp = ptr; //목표의 전 노드 
                ptr = ptr->next;
            } // 이 loop가 끝날떄쯤 ptr은 우리가 remove하고 싶은 원소를 가리키고 있을것임.
            
            cout<< ptr->value; // 삭제하기 직전에 삭제하는 값 출력

            tmp->next = ptr->next; // 연결관계 재정비

            delete ptr; // 동적 할당 해제
        }

        // 4. n으로 1~n까지의 값을 갖는 linked list 생성
        void CreateValues(int n){
            for (int i=1; i<=n; i++){
                AddNode(i); 
            }
        }

        // 5. size
        int get_size(){
            return size;
        }

        // 6. Head
        Node get_head(){
            return head;
        }

    } // end of class definition        
            


int main()
{
    int k,n;
    cin>>k>>n; // input

    cout<< '<';

    Circular_Linked_List *my_linked_list = new Circular_Linked_List; // 클래스 객체 생성
    my_linked_list-> CreateValues(n); // 1~n까지의 value를 가지는 노드들 생성

    Node *ptr = my_linked_list->get_head(); 
    // 계속 제거해서 아무것도 안 남을떄까지 k번째 애를 계속해서 제거
    while (my_linked_list-> get_size() != 0){
        my_linked_list-> RemoveNode(ptr, int k);
        if (my_linked_list-> get_size() == 0) {  // 이 바로 위에 remove한걸로 끝났으면 while loop에서 나오기
            break;
        }

        for (int i=0; i<k-1; i++){
            ptr = ptr->next;     
        }
        cout<<', ';    
    }

    cout<< '>'<<endl;
    
    return 0;
}
