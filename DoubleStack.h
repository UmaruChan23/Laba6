#include <ostream>
#include "DoubleNode.h"

template<typename T>
class DoubleStack : public Structure<T>{
public:
    DoubleNode<T> *pTop;
    DoubleNode<T> *nxt;
    int size = 0;

    void init(T value) {
        auto *root = new DoubleNode<T>;
        root->value = value;
        root->next = nullptr;
        root->last = nullptr;
        pTop = root;
        nxt = nullptr;
        size++;
    }

    void copy(const DoubleStack &source) {
        DoubleNode<T> *temp = source.pTop->next;
        do {
            push(temp->value);
            temp = temp->next;
        } while (size < source.getSize());
    }

    DoubleStack() {
        pTop = nullptr;
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
        nxt = other.nxt;
        size = other.size;
        other.pTop = nullptr;
        other.nxt = nullptr;
        other.size = 0;
    }

    void push(const T &value) override {
        auto *newNode = new DoubleNode<T>;
        newNode->value = value;
        newNode->next = pTop;
        newNode->last = nullptr;
        nxt = newNode;
        pTop->last = nxt;
        pTop = newNode;
        size++;
    }

    T pop() override {
        if (size <= 0) {
            delete this;
            pTop = nxt = nullptr;
        } else {
            T value = pTop->value;
            DoubleNode<T> *temp;
            temp = pTop->next;
            delete pTop;
            pTop = temp;
            pTop->last = nullptr;
            nxt = nullptr;
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
        this->~DoubleStack();
        pTop = nullptr;
        nxt = nullptr;
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
        source.nxt = nullptr;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const DoubleStack<T> &node) {
        if (node.size > 0) {
            DoubleNode<T> *temp;
            temp = node.pTop;
            int tempSize = 0;
            do {
                out << temp->value << " ";
                temp = temp->next;
                tempSize++;
            } while (tempSize < node.size);
            return out;
        } else {
            out << "The list does not exist";
            return out;
        }
    }
};