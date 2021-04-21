#include <iostream>
#include "Stack.h"
#include "DoubleStack.h"

using namespace std;

template<typename T>
void testPointer(Structure<T> *structure) {
    structure->push("aaa");
    structure->push("bbb");
    structure->push("ccc");
    cout << structure << endl;
    structure->pop();
    cout << structure << endl;

}

template<typename T>
void testLink(Structure<T> &structure) {
    dynamic_cast<Stack<T> &>(structure).push("ddd");
    dynamic_cast<Stack<T> &>(structure).push("eee");
    dynamic_cast<Stack<T> &>(structure).push("fff");
    cout << dynamic_cast<Stack<T> &>(structure) << endl;
    dynamic_cast<Stack<T> &>(structure).pop();
    cout << dynamic_cast<Stack<T> &>(structure) << endl;

}

int main() {

    cout << "Stack" << endl;

    auto testStackPointer = new Stack<string>("1");
    testPointer(testStackPointer);

    auto testStackLink = new Stack<string>("2");
    testLink(*testStackLink);

    cout << "DoubleStack" << endl;

    auto testDoubleStackPointer = new DoubleStack<string>("3");
    testPointer(testDoubleStackPointer);

    auto testDoubleStackList = new DoubleStack<string>("4");
    testLink(*testDoubleStackList);

    return 0;
}
