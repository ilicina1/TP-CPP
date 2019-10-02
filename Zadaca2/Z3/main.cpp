// TP, 2018/2019
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

template<typename nekiTip1, typename nekiTip2, typename nekiTip3>
    nekiTip3 SimetricnaRazlikaBlokova(nekiTip1 p1, nekiTip1 p2, nekiTip2 p3, nekiTip2 p4, nekiTip3 p5) {
        
        nekiTip1 pocetakPrvog = p1;
        nekiTip2 pocetakDrugog = p3;
        nekiTip3 kraj = p5;
        
        std::cout << *p1 << " " << *pocetakPrvog;
        
        // while(pocetakPrvog != p2){
        //     bool nekiBool = true;
            
          
        //     while(p3 != p4){
        //         if(*pocetakPrvog == *pocetakDrugog){
        //             nekiBool = false;
        //             break;
        //         } else {
        //             ++pocetakDrugog;
        //         }
        //     }
        //     if(nekiBool && std::count(p5, kraj, *pocetakPrvog) == 0) {
        //         *kraj=*pocetakPrvog;
        //     }
            
        //     ++pocetakPrvog;
        // }
        
        /*pocetakPrvog = p1;
        pocetakDrugog = p3;
        
        while(pocetakDrugog != p4){
            bool nekiBool = true;
            
            while(pocetakPrvog != p2){
                if(*pocetakDrugog == *pocetakPrvog){
                    nekiBool = false;
                    break;
                } else ++pocetakDrugog;
            }
            if(nekiBool && std::count(p5, kraj, *pocetakDrugog) == 0) {
                *kraj=*pocetakDrugog;
            }
            
            ++pocetakDrugog;
        }*/
        
        return kraj;
    }

int main ()
{
    int brojElemenataNiza;

    std::cout << "Unesite broj elemenata niza" << std::endl;
    std::cin >> brojElemenataNiza;

    std::cout << "Unesite elemente niza" << std::endl;

    int *dinamckiNiz = new int[brojElemenataNiza];

    for(int i = 0; i < brojElemenataNiza; i++) {
        int a = 0;
        std::cin >> a;
        dinamckiNiz[i] = a;
    }
    
    int brojElemenataDeka;
    
    std::cout << "Unesite broj elemenata deka" << std::endl;
    std::cin >> brojElemenataDeka;

    std::cout << "Unesite elemente deka" << std::endl;
    
    std::deque<int> dek;
    
    for(int i = 0; i < brojElemenataDeka; i++){
        int a = 0;
        std::cin >> a;
        dek.push_back(a);
    }
    
    std::vector<int> odredisni(brojElemenataDeka+brojElemenataNiza);
    
    // auto kraj = SimetricnaRazlikaBlokova(dinamckiNiz, dinamckiNiz + brojElemenataNiza, dek.begin(), dek.end(), odredisni.begin());
    
    // for(int i = 0; i < 5; i++) std::cout << odredisni[i] << " ";
    //while(poc < kraj) std::cout << *poc++ << " ";
    
    return 0;
}
