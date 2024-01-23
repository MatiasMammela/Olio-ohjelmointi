#include <iostream>
#include <string>
using namespace std;
class Cheff
{

protected:
  string name;

public:
  Cheff(string name);
  ~Cheff();
  void makeSalad();
  void makeSoup();
};

class ItalianCheff : public Cheff
{
public:
  ItalianCheff(string name, int water, int flour);
  string getName();
  void makePasta(int water, int flour);

private:
  int water;
  int flour;
};

Cheff::~Cheff()
{
  cout << "Cheff " << name << " destruktori" << endl;
}

Cheff::Cheff(string name)
{
  this->name = name;
  cout << "Cheff " << name << " konstruktori" << endl;
}
void Cheff::makeSalad()
{
  cout << "Cheff " << name << " makes salad" << endl;
}
void Cheff::makeSoup()
{
  cout << "Cheff " << name << " makes soup" << endl;
}

ItalianCheff::ItalianCheff(string name, int water, int flour) : Cheff(name)
{
  this->water = water;
  this->flour = flour;
  cout << "ItalianCheff " << name << " konstruktori" << endl;
}
string ItalianCheff::getName()
{
  return name;
}
void ItalianCheff::makePasta(int water, int flour)
{
  cout << "ItalianCheff " << name << " makes pasta with " << water << " water and " << flour << " flour " << endl;
}

int main()
{
  Cheff cheff1("Kokki1");
  ItalianCheff cheff2("Kokki2", 1, 2);
  cheff1.makeSalad();
  cheff1.makeSoup();
  cheff2.makePasta(1, 2);

  return 0;
}