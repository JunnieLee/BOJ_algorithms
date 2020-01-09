/////////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;


class Node{
   friend class List;      // ListŬ������ NodeŬ������ private�� ������ �� ����

    private:
        int value;      // ��� �����
        Node *next;      // Node�� ����ų �� �ִ� ������(ȭ��ǥ)
        Node(int v, Node *n) : value(v), next(n) { } // ������
};


// �ϴ� ���븸 define
class List{
    private:
        Node *head,      // ����Ʈ�� ù ��带 ����Ŵ
             *tail;      // ����Ʈ�� ������ ��带 ����Ŵ
        int size;      // ����� ����

    public:
        List();            //������
        void pushBack(int);      //����Ʈ�� �� �������� ��带 ����
        void popFront();      //����Ʈ�� �� ó�� ��带 ����
        void insert(int);      //����Ʈ�� �߰��� ��带 ���� (value�� ũ�� ������� �����Ѵ�) --> //////////// �̰� �� �ٲ���ҵ�!!
        void print();         //����Ʈ�� ���빰�� ����Ѵ�
    ~List();            //�Ҹ���
};


List:: List()      // ��尡 �ϳ��� ����Ʈ�� ����
{
    head = tail = NULL;
    size = 0;
}


void List::pushBack(int value)      //����Ʈ�� �� �������� ��带 ����
{
    Node *newNode = new Node(value, NULL); // ������ ��� ����
    if (head == NULL)      // ����Ʈ�� ����ٸ�
        head = newNode;      //    ������ ��尡 ù ��尡 �ȴ�.
    else
        tail->next = newNode;   // ����Ʈ�� ���Ұ� �ϳ��̻� �����Ѵٸ� ������ ������ ����� ������ ������ ���� �����Ѵ�.
        tail = newNode;      // ����Ʈ�� ������� ������ ������ ���� ����� ������.
        size++;         //������ 1 ����.
}


void List::popFront()      //����Ʈ�� �� ó�� ��带 ����
{
    if (head != NULL)      // ����Ʈ�� ��尡 �ּ� �ϳ� �����ؾ��� ���Ű� ����
    {
        Node *removal = head;   // ���ŵ� ����� ������ ���� �ӽó�� ���� (swap �����Ҷ� temp ������ ���� �뵵)
        head = head->next;   // �ι�° ��尡 ù ��尡 �ȴ�.
        delete removal;      // ù° ��� ����
        size--;         // ������ 1 ����
    }
}


void List::insert(int value)      //����Ʈ�� �߰��� ��带 ���� (value�� ũ�� ������� �����Ѵ�)
{
    Node *insert = new Node(value, NULL);
    Node *scan; //Ž���� �ӽó��
    if (head != NULL) //����Ʈ�� ���Ұ� �ּ� �Ѱ� �ִٸ� (������� �ʴٸ�)
    {
        if (head->value > value) {      //������ ��尡 ����Ʈ�� ù ��庸�� ������� (pushFront)
            insert->next = head;
            head = insert;
        }
        else if (tail->value < value) {      //������ ��尡 ����Ʈ�� ��������庸�� ū ��� (pushBack)
            tail->next = insert;
            tail = insert;
        }
        else {      //�� ���� ���
            scan = head;
            while (scan->next->value < insert->value) // ��尡 ���Ե� ��ġ�� ã������ scan�� �����Ѵ�.
                scan = scan->next;
            insert->next = scan->next;  //������(ȭ��ǥ) ����
            scan->next = insert;   //������(ȭ��ǥ)���� 2
        }
    }
    else //����Ʈ�� ����ٸ� �׳� ����
    {
        head = insert;
        tail = insert;
        head->next = NULL;
    }
    size++; //������ 1 ����
    }



    void List::print()
    {
        Node *scan = head;
        while (scan != NULL)
        {
            cout << scan->value << endl;
            scan = scan->next;
        }
    }

    List::~List()         // �Ҹ���
    {
    while (head != NULL)
        popFront();      
    }
