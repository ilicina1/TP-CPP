#include <iostream>
#include <iostream>
#include <functional>

std::function<int(int)> IteriranaFunkcija(std::function<int(int)> f, int n)
{
    return [&f,n](int x) {
        for(int i = 0; i < n; i++) {
            x = f(x);
        }
        return x;
    };
}

int main()
{
    std::function<int(int)> f = [](int x){
        return x*x;
    };
    auto g(IteriranaFunkcija(f ,2));
    std::cout << g(3);
    //std::cout << IteriranaFunkcija([](int x) { return x * x; }, 2)(3) << std::endl;
}
