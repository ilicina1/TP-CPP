#include <iostream>
#include <stack>

std::stack<int> funkcija(std::stack<int> stek, int n)
{
    std::stack<int> pom;
    while(!stek.empty()){
        pom.push(stek.top() * n);
        stek.pop();
    }
    return pom;
}

int main()
{
    std::stack<int> pom;
    pom.push(2);
    pom.push(3);
    pom.push(4);
    pom.push(5);
    pom.push(6);
    pom = funkcija(pom, 3);
    while (!pom.empty()) {
        std::cout << '\t' << pom.top();
        pom.pop();
    }
    return 0;
}
