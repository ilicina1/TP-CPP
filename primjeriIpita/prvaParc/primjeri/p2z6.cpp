#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

//template <typename prvitTip, typename drugiTip, typename treciTip>
void funkcija(std::vector<double> p1, std::deque<double> p2)
{
    double **matrica;
    try {
        matrica = new double*[p1.size()];
        matrica[0] = new double[p1.size() * p2.size()];
        for(int i = 1; i < p1.size(); i++) matrica[i] = matrica[i - 1] + p2.size();
    } catch(std::logic_error) {
        std::cout << "Allocation failed!" << std::endl;
    }
    for(int i = 0; i < p1.size(); i++) {
        for(int j = 0; j < p2.size(); j++) {
            matrica[i][j] = p1.at(i) * p2.at(j);
        }
    }
    for(int i = 0; i < p1.size(); i++) {
        for(int j = 0; j < p2.size(); j++) {
            std::cout << std::setw(5) << matrica[i][j] << " ";
        }
        std::cout << std::endl;
    }
    //return matrica;
}

int main()
{
    std::vector<double> p1(5);
    std::deque<double> p2(5);
    for(int i = 0; i < p1.size(); i++){
        std::cout << "Unesi " << i+1 << ". element prvog vektora: ";
        std::cin >> p1.at(i);
        std::cout << "Unesi " << i+1 << ". element drugog vektora: ";
        std::cin >> p2.at(i);
    }
    funkcija(p1, p2);
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         std::cout << *p[i] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}
