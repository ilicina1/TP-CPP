#include <iostream>

class Zivotinja
{
public:
    virtual void OglasiSe() const = 0;
    virtual Zivotinja *DajKopiju() const = 0;
};

class Pas : public Zivotinja
{
public:
    void OglasiSe() const override{ std::cout << "aw!"; }
    Zivotinja *DajKopiju() const override { return new Pas(*this); }
};

class Macka : public Zivotinja
{
public:
    void OglasiSe() const override { std::cout << "mew!"; }
    Zivotinja *DajKopiju() const  override{ return new Macka(*this); }
};

class PolimorfnaZivotinja
{   
    Zivotinja *zivotinja;
public:
    PolimorfnaZivotinja(){ throw std::logic_error("nejma majke mi!"); }
    PolimorfnaZivotinja(const Zivotinja &zivotinjica) : zivotinja(zivotinjica.DajKopiju()) {}
    void OglasiSe() const { zivotinja->OglasiSe(); }
};

int main()
{
    // Pas a;
    // Macka m;
    // m.OglasiSe();
    // std::cout << std::endl;
    // a.OglasiSe();
    // std::cout << std::endl;
    // PolimorfnaZivotinja zivotinjica(a);
    Pas pas;
    PolimorfnaZivotinja a(pas);
    a.OglasiSe();
}
