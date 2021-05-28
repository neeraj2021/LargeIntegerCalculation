#include <cstdlib>
using namespace std;

struct Node
{
    Node *PREV;
    int VALUE;
    Node *NEXT;
};

class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        head = NULL;
        tail = NULL;
    }

    Node *GET_LAST()
    {
        return tail;
    }

    Node *GET_FIRST()
    {
        return head;
    }

    Node *NEXT_RIGHT(Node *N)
    {
        return N->NEXT;
    }

    Node *NEXT_LEFT(Node *N)
    {
        return N->PREV;
    }

    void INSERT_FIRST(int V)
    {
        head = new Node;
        head->VALUE = V;
        head->PREV = NULL;
        head->NEXT = NULL;
        tail = head;
    }

    void INSERT_RIGHT(int V)
    {
        Node *temp = tail;
        temp->NEXT = new Node;
        temp = temp->NEXT;
        temp->PREV = tail;
        temp->NEXT = NULL;
        temp->VALUE = V;
        tail = temp;
    }

    void INSERT_LEFT(int V)
    {
        Node *temp = head;
        temp->PREV = new Node;
        temp = temp->PREV;
        temp->NEXT = head;
        temp->PREV = NULL;
        temp->VALUE = V;
        head = temp;
    }

    bool IS_FIRST(Node *N)
    {
        return (N == head);
    }

    bool IS_LAST(Node *N)
    {
        return (N == tail);
    }

    int NODE_COUNT()
    {
        int count = 0;
        if (head == NULL)
            return count;
        Node *temp = head;
        count++;
        while (NEXT_RIGHT(temp) != NULL)
        {
            temp = NEXT_RIGHT(temp);
            count++;
        }
        return count;
    }

    int NODE_VALUE(Node *N)
    {
        return N->VALUE;
    }

    bool IS_EMPTY()
    {
        return (head == NULL);
    }

    void CHANGE_NODE_VALUE(Node *N, int I)
    {
        N->VALUE = I;
    }

    void MOVE_HEAD(Node *N)
    {
        head = N;
        head->PREV = NULL;
    }
};