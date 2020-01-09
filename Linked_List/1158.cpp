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
        int size = 0; // ��ũ ���� 
        
    public: 
        // 1. ������
        Circular_Linked_List() : head(nullptr), tail(nullptr) {}
        
        // 2. �Ϲ� Add
        void AddNode(int num){ // �� �ڿ� �Ҵ�
            Node *node = new Node; //��� ���� �Ҵ� 
            size++; 
            node->value = num; 
            node->next = nullptr; 
            if (head == nullptr) { // ù adding�� ��
                head = node; 
                tail = node;
            } 
            else{ 
                tail->next = node; 
                tail = node;
                tail->next = head; // circular�� �߰����� ����! 
            } 
        } 
        
        // 3. Ư�� Remove (�������)
        void RemoveNode(Node starter_node, int order_num) { // starter_node�������� order_num��° ���� �����
            if (order_num>size){
                order_num = order_num%size;
            }
            size--;

            Node *ptr = starter_node; 
            Node *tmp = ptr; 

            for (int i=1; i < order_num; i++){
                tmp = ptr; //��ǥ�� �� ��� 
                ptr = ptr->next;
            } // �� loop�� �������� ptr�� �츮�� remove�ϰ� ���� ���Ҹ� ����Ű�� ��������.
            
            cout<< ptr->value; // �����ϱ� ������ �����ϴ� �� ���

            tmp->next = ptr->next; // ������� ������

            delete ptr; // ���� �Ҵ� ����
        }

        // 4. n���� 1~n������ ���� ���� linked list ����
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

    Circular_Linked_List *my_linked_list = new Circular_Linked_List; // Ŭ���� ��ü ����
    my_linked_list-> CreateValues(n); // 1~n������ value�� ������ ���� ����

    Node *ptr = my_linked_list->get_head(); 
    // ��� �����ؼ� �ƹ��͵� �� ���������� k��° �ָ� ����ؼ� ����
    while (my_linked_list-> get_size() != 0){
        my_linked_list-> RemoveNode(ptr, int k);
        if (my_linked_list-> get_size() == 0) {  // �� �ٷ� ���� remove�Ѱɷ� �������� while loop���� ������
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
