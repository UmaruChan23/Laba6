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
    structure.push("ddd");
    structure.push("eee");
    structure.push("fff");
    cout << &structure << endl;
    structure.pop();
    cout << &structure << endl;
}

int main() {

    cout << "Stack" << endl;
    Stack<string> testStackPointer("1");
    Structure<string> *structurePointer = &testStackPointer;
    testPointer(structurePointer);

    Stack<string> testStackLink ("2");
    Structure<string> &structureLink = testStackLink;
    testLink(structureLink);

    cout << "DoubleStack" << endl;
    DoubleStack<string> testDoubleStackPointer("3");
    structurePointer = &testDoubleStackPointer;
    testPointer(structurePointer);

    DoubleStack<string> testDoubleStackLink("4");
    Structure<string> &structureLink2 = testDoubleStackLink;
    testLink(structureLink2);

    return 0;
}
