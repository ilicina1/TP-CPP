#include <iostream>

class Zivotinja {
    public:
        virtual void OglasiSe() const = 0;
        virtual Zivotinja *DajKopiju() const = 0;
};

class Pas : public Zivotinja{
    public:
        void OglasiSe() const override { std::cout << "Av!"; }
        Zivotinja *DajKopiju() const override { return new Pas(*this); }
};

class Macka : public Zivotinja{
    public:
        void OglasiSe() const override { std::cout << "Mjau!"; }
        Zivotinja *DajKopiju() const override { return new Macka(*this); }
};

class Krava : public Zivotinja{
    public:
        void OglasiSe() const override { std::cout << "Muu!"; }
        Zivotinja *DajKopiju() const override { return new Krava(*this); }
};

class PolimorfnaZivotinja {
    Zivotinja *pok;
    public:
        PolimorfnaZivotinja(){ throw std::logic_error("Nema nista ocam"); }
        PolimorfnaZivotinja(const Zivotinja &zivotinja) : pok(zivotinja.DajKopiju()) {}
        void OglasiSe() const { pok->OglasiSe(); }
};

int main()
{
    Krava krava;
    PolimorfnaZivotinja a(krava);
    a.OglasiSe();

}
