//TP 2018/2019: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<int> intVector;

std::vector<intVector> PascalovTrougao(int n)
{
  if (n<0) throw std::domain_error("Broj redova ne smije biti negativan");
  std::vector<intVector> pascTrougao;

  for (int i=0; i<n; i++) {
    intVector tempVek;
    for (int j=0; j<i+1; j++) {
      if(i!=0 && j!=0 && j!=i)
        tempVek.push_back(pascTrougao.at(i-1).at(j-1) + pascTrougao.at(i-1).at(j));
      else
        tempVek.push_back(1);
    }
    pascTrougao.push_back(tempVek);
  }

  return pascTrougao;
}

int SirinaBroja(int n)
{
  int sirina=0;

  while(n!=0) {
    sirina++;
    n/=10;
  }

  return sirina;
}

int NajvecaSirina(std::vector<intVector> mat)
{
  int najduziBroj=0;

  for (int i=0; i<mat.size(); i++) {
    for (int j=0; j<mat.at(i).size(); j++) {
      int sirina = SirinaBroja(mat.at(i).at(j));
      if(sirina>najduziBroj) najduziBroj=sirina;
    }
  }

  return najduziBroj;
}

int main ()
{
  int brRedova;
  std::cout << "Unesite broj redova: ";
  std::cin >> brRedova;
  std::cout <<std::endl;

  std::vector<intVector> pascTrougao;
  try {
    pascTrougao = PascalovTrougao(brRedova);
  } catch(std::domain_error izuzetak) {
    std::cout << izuzetak.what() << std::endl;
  }

  int brojCifara = NajvecaSirina(pascTrougao);

  for (auto pascVek : pascTrougao) {
    for (auto pascElementi : pascVek) {
      std::cout << " " << std::setw(brojCifara) << pascElementi;
    }
    std::cout << std::endl;
  }

  return 0;
}
