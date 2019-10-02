#include <iostream>
#include <fstream>

int main()
{
    std::ofstream izlazni_tok("kompleksni.txt");
    for(int i = 2; i < 10; i++){
        izlazni_tok << i << "," << i*i << std::endl;
    }
    return 0;
}
