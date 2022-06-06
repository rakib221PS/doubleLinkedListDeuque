#include <iostream>
#include <stdexcept>
#include <time.h>
struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int v) : value(v),
                  next(nullptr),
                  prev(nullptr) {}
};

class Deque
{
    Node *head;
    Node *tail;

public:
    // write a constructor
    Deque() : head(nullptr), tail(nullptr)
    {
    }

    // write a copy constructor
    Deque(const Deque &cp) : head(nullptr), tail(nullptr)
    {
        if (!cp.isEmpty())
        {
            head = new Node(cp.head->value);
            tail = head;
            Node *tmpCopy = cp.head->next;
            while (tmpCopy != nullptr)
            {
                // Node *tmp = new Node(tmpCopy->value);
                push_back(tmpCopy->value);
                tmpCopy = tmpCopy->next;
                // tail->next = tmp;
                // tmp->prev = tail;
                // tail = tmp;
            }
        }
    }

    // write an assignment operator

    Deque &operator=(const Deque &original)
    {
        if (!original.isEmpty())
        {
            if (isEmpty())
            {
                head = new Node(original.head->value);
                tail = head;
                Node *tmpCopy = original.head->next;
                while (tmpCopy != nullptr)
                {
                    Node *tmp = new Node(tmpCopy->value);
                    tmpCopy = tmpCopy->next;
                    tail->next = tmp;
                    tmp->prev = tail;
                    tail = tmp;
                }
            }
            else
            {
                Node *tmpCopy = original.head;
                while (tmpCopy != nullptr)
                {
                    Node *tmp = new Node(tmpCopy->value);
                    tail->next = tmp;
                    tmp->prev = tail;
                    tail = tmp;
                    tmpCopy = tmpCopy->next;
                }
            }
        }
        return *this;
    }

    // write a destructor
    ~Deque()
    {
        while (head != nullptr)
        {
            Node *delTmp = head;
            head = head->next;
            delete delTmp;
        }
    }
    bool isEmpty() const
    {
        return ((head == nullptr) && (tail == nullptr));
    }

    int back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to read from an empty memory");
        }
        return tail->value;
    }

    int front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to read from an empty memory");
        }
        return head->value;
    }

    void push_back(const int x)
    {
        if (isEmpty())
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            Node *tmp = new Node(x);
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }

    void push_front(const int x)
    {
        if (isEmpty())
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            Node *tmp = new Node(x);
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to delete from an empty memory");
        }
        if (tail == head)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            // std::cout << tmp->value << std::endl;
            delete tmp;
        }
        else
        {
            Node *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            std::cout << tmp->value << std::endl;
            delete tmp;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to delete from an empty memory");
        }
        if (tail == head)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            // std::cout << tmp->value << std::endl;
            delete tmp;
        }
        else
        {
            Node *tmp = head;
            head = head->next;
            head->prev = nullptr;
            std::cout << tmp->value << std::endl;
            delete tmp;
        }
    }
};

int main()
{
    clock_t tStart = clock();
    Deque DoubleLinkedListDeque, AnotherDoubleLinkedListDeque;
    for (int i = 1; i <= 1; i++)
    {
        DoubleLinkedListDeque.push_back(i);
    }

    for (int i = 0; i <= 3; i++)
    {
        AnotherDoubleLinkedListDeque.push_back(-i * i - 3);
    }
    // DoubleLinkedListDeque = AnotherDoubleLinkedListDeque;
    DoubleLinkedListDeque.pop_back();
    std::cout<<std::endl;
    // std::cout << DoubleLinkedListDeque.back();
    // AnotherDoubleLinkedListDeque(DoubleLinkedListDeque);
    Deque CopyDoubleLinkedList(DoubleLinkedListDeque);
    // AnotherDoubleLinkedListDeque.remove(DoubleLinkedListDeque.head);
    std::cout<<"time "<<(double)(clock()-tStart);

    return 0;
}