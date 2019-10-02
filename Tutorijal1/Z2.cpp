//TP 2017/2018: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>

int main ()
{
    double a, b, c, povrsina, obim, min_ugao, s, pi, ugao_a, ugao_b, ugao_c;
    int i;

    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a || a < 0 || b < 0 || c < 0) {

        std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!";

        return 0;
    }

    s = (a + b + c) / 2;

    povrsina = sqrt(s * (s - a) * (s - b) * (s - c));
    obim = a + b + c;

    pi = 4 * atan(1);

    ugao_a = acos( ( pow(b,2) + pow(c,2) - pow(a,2) ) / (2 * b * c) );
    ugao_b = acos( ( pow(a,2) + pow(c,2) - pow(b,2) ) / (2 * a * c) );
    ugao_c = acos( ( pow(a,2) + pow(b,2) - pow(c,2) ) / (2 * a * b) );

    double niz[] = {ugao_a, ugao_b, ugao_c};

    min_ugao = niz[0];

    for(i = 0; i < 3; i++) {
        if(min_ugao > niz[i])
            min_ugao = niz[i];
    }

    min_ugao *= (180 / pi);


    double stepen = int(min_ugao);
    int minuta = (min_ugao - stepen) * 60;
    int sekunda = (min_ugao - int(min_ugao) - (minuta/60.)) * 3600;

    std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << obim << ".\n";
    std::cout << "Njegova povrsina iznosi " << povrsina << ".\n";
    std::cout << "Njegov najmanji ugao ima " << stepen << " stepeni, " << minuta << " minuta i " << sekunda << " sekundi.\n";

    return 0;

}
