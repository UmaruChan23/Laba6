#include <iostream>
#include "Stack.h"
#include "DoubleStack.h"
using namespace std;

int main() {

    Stack<string> stackList("1");
    //DoubleStack<int> doubleStack(1);

    //doubleStack.push(2);
    //doubleStack.push(3);

    stackList.push("2");
    stackList.push("3");
    stackList.push("4");


    Stack<string> listList = stackList;
    Stack<string> tList = move(stackList);

    listList.push("5");
    tList.pop();

    cout << stackList << endl;
    cout << listList << endl;
    cout << tList << endl;
   // cout << doubleStack << endl;

    return 0;
}
