#include <ostream>
#include "Node.h"
#include "Structure.h"

template<typename T>
class Stack : public Structure<T>{
    Node<T> *pTop;
    Node<T> *lst;
    int size = 0;
public:
    void init(T value) {
        auto *root = new Node<T>;
        root->value = value;
        root->next = root;
        pTop = root;
        lst = root;
        lst->next = pTop;
        size++;
    }

    void copy(const Stack &source) {
        Node<T> *temp = source.pTop->next;
        do {
            push(temp->value);
            temp = temp->next;
        } while (size < source.getSize());
    }

    Stack() {
        pTop = nullptr;
        lst = nullptr;
    }

    Stack(T value) {
        init(value);
    }

    Stack(const Stack &source) {
        Stack temp;
        temp.init(source.pTop->value);
        temp.copy(source);
        init(temp.pTop->value);
        copy(temp);
    }

    Stack(Stack &&other) {
        pTop = other.pTop;
        lst = other.lst;
        size = other.size;
        other.pTop = nullptr;
        other.lst = nullptr;
        other.size = 0;
    }

    void push(const T &value) override {
        Node<T> *newNode = new Node<T>;
        newNode->value = value;
        newNode->next = pTop;
        pTop = newNode;
        lst->next = pTop;
        size++;
    }

    T pop() override {
        if (size <= 0) {
            delete this;
            pTop = lst = nullptr;
        } else {
            T value = pTop->value;
            Node<T> *temp;
            temp = pTop->next;
            delete pTop;
            pTop = temp;
            lst->next = pTop;
            size--;
            return value;
        }
    }

    T peek() override {
        return pTop->value;
    }

    int getSize() const override {
        return this->size;
    }

    ~Stack() {
        int value = size;
        for (int i = 0; i < value - 1; i++) {
            pop();
        }
    }

    void assignValue(const Stack &source) {
        this->~Stack();
        pTop = nullptr;
        lst = nullptr;
        size = 0;
        Stack temp;
        temp.init(source.pTop->value);
        temp.copy(source);
        init(temp.pTop->value);
        copy(temp);
    }

    Stack<T> &operator=(const Stack &source) {
        if (this == &source) {
            return *this;
        }
        assignValue(source);
        return *this;
    }

    Stack<T> &operator=(Stack &&source) {
        if (this == &source) {
            return *this;
        }
        assignValue(source);
        source.size = 0;
        source.pTop = nullptr;
        source.lst = nullptr;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const override
    {
        if (this->size > 0) {
            Node<T> *temp;
            temp = this->pTop;
            do {
                out << temp->value << " ";
                temp = temp->next;
            } while (temp != this->pTop);
            return out;
        } else {
            out << "The list does not exist";
            return out;
        }
    }
};
