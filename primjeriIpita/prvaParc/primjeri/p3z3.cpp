#include <iostream>
#include <functional>

std::function<int(int)> IteriranaFunkcija(std::function<int(int)> f, int n)
{
    return [&f,n](int x) {
        for(int i = 0; i < n; i++) {
            x = f(x);
        }
        return a;
    };
}

int main()
{
    std::function<int(int)> f = [](int x){
        return 3 * x - 5;
    };
    auto g(IteriranaFunkcija(f ,10));
    std::cout << g(5);
}
