// TP 16/17 (Tutorijal 9, Zadatak 2)
#include <iostream>
#include <cmath>

class Vektor3d {
	double koordinate[3];
public:
	void Postavi(double x, double y, double z) {
           koordinate[0] = x; koordinate[1] = y; koordinate[2] = z;
         }
	void Ocitaj(double &x, double &y, double &z) const { x = DajX(); y = DajY(); z = DajZ();}
	void Ispisi() const {
           std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
         }
	double DajX() const { return koordinate[0]; }
	double DajY() const { return koordinate[1]; }
	double DajZ() const { return koordinate[2]; }
	double DajDuzinu() const { return sqrt(DajX() * DajX() + DajY() * DajY() + DajZ() * DajZ()); }
	Vektor3d &PomnoziSaSkalarom(double s) {
          Postavi(DajX() * s, DajY() * s, DajZ() * s);
	return *this; }
	Vektor3d &SaberiSa(const Vektor3d &v) { Postavi(DajX() + v.DajX(), DajY() + v.DajY(), DajZ() + v.DajZ());
	return *this; }
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
	void PostaviX(double x) { Postavi(x, DajY(), DajZ()); }
	void PostaviY(double y) { Postavi(DajX(), y, DajZ()); }
	void PostaviZ(double z) { Postavi(DajX(), DajY(), z); }
	int DajBrojIspisa() {  }
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
	Vektor3d v3;
	v3.Postavi(0, 0, 0);
	v3.SaberiSa(v1);
	v3.SaberiSa(v2);

	return v3;
}

int main ()
{
	Vektor3d v1, v2;
	v1.Postavi(10, 5, 2);
	v2.Postavi(21, 2, 13);
	std::cout << v1.DajDuzinu() << std::endl;
	v1.PomnoziSaSkalarom(8);
	v1.Ispisi();
	std::cout << std::endl;
	v2.PomnoziSaSkalarom(3);
	v2.Ispisi();
	std::cout << std::endl;
	v1.SaberiSa(v2);
	v1.Ispisi();
	std::cout << std::endl;
	Vektor3d v3;
	v3 = ZbirVektora(v1, v2);
	v3.Ispisi();
	return 0;
}
