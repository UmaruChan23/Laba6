#include <ostream>
#include "DoubleNode.h"
#include "Structure.h"

template<typename T>
class DoubleStack : public Structure<T>{
public:
    DoubleNode<T> pTop;
    DoubleNode<T> lst;
    DoubleNode<T> nxt;
    int size = 0;

    void init(T value) {
        auto *root = new DoubleNode<T>;
        root->value = value;
        root->next = root;
        root->last = nullptr;
        pTop = root;
        lst = root;
        nxt = nullptr;
        lst->next = pTop;
        size++;
    }

    void copy(const DoubleStack &source) {
        Node<T> *temp = source.pTop->next;
        do {
            push(temp->value);
            temp = temp->next;
        } while (size < source.getSize());
    }

    DoubleStack() {
        pTop = nullptr;
        lst = nullptr;
        nxt = nullptr;
    }

    DoubleStack(T value) {
        init(value);
    }

    DoubleStack(const DoubleStack &source) {
        DoubleStack temp;
        temp.init(source.pTop->value);
        temp.copy(source);
        init(temp.pTop->value);
        copy(temp);
    }

    DoubleStack(DoubleStack &&other) {
        pTop = other.pTop;
        lst = other.lst;
        nxt = other.nxt;
        size = other.size;
        other.pTop = nullptr;
        other.lst = nullptr;
        other.nxt = nullptr;
        other.size = 0;
    }

    void push(const T &value) override {
        auto *newNode = new DoubleNode<T>;
        newNode->value = value;
        newNode->next = pTop;
        pTop->last = newNode;
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

    ~DoubleStack() {
        int value = size;
        for (int i = 0; i < value - 1; i++) {
            pop();
        }
    }

    void assignValue(const DoubleStack &source) {
        this->~Stack();
        pTop = nullptr;
        lst = nullptr;
        size = 0;
        DoubleStack temp;
        temp.init(source.pTop->value);
        temp.copy(source);
        init(temp.pTop->value);
        copy(temp);
    }

    DoubleStack<T> &operator=(const DoubleStack &source) {
        if (this == &source) {
            return *this;
        }
        assignValue(source);
        return *this;
    }

    DoubleStack<T> &operator=(DoubleStack &&source) {
        if (this == &source) {
            return *this;
        }
        assignValue(source);
        source.size = 0;
        source.pTop = nullptr;
        source.lst = nullptr;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const DoubleStack<T> &node) {
        if (node.size > 0) {
            Node<T> *temp;
            temp = node.pTop;
            do {
                out << temp->value << " ";
                temp = temp->next;
            } while (temp != node.pTop);
            return out;
        } else {
            out << "The list does not exist";
            return out;
        }
    }
};