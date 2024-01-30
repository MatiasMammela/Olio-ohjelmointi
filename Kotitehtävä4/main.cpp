#include <iostream>
using namespace std;
class Asunto
{

public:
    int asukasMaara;
    int neliot;
    Asunto()
    {
        cout << "Luodaan asunto" << endl;
    }
    void maarita(int asukasMaara, int neliot)
    {
        cout << "Määritetään asunnon tiedot" << endl;
        this->asukasMaara = asukasMaara;
        this->neliot = neliot;
    }
    double laskeKulutus(double kulutus)
    {
        kulutus = asukasMaara * neliot;
        return kulutus;
    }
};

class Kerros
{
public:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;
    Kerros()
    {
        cout << "Luodaan kerros" << endl;
    }
    virtual void maaritaAsunnot()
    {
        as1.maarita(1, 100);
        as2.maarita(2, 100);
        as3.maarita(3, 100);
        as4.maarita(4, 100);
    }
    virtual double laskeKulutus(double kulutus)
    {
        kulutus = as1.laskeKulutus(kulutus) + as2.laskeKulutus(kulutus) + as3.laskeKulutus(kulutus) + as4.laskeKulutus(kulutus);
        return kulutus;
    }
};

class Katutaso : public Kerros
{
public:
    Katutaso()
    {
        cout << "Luodaan katu" << endl;
    }
    Asunto as1;
    Asunto as2;
    void maaritaAsunnot() override
    {
        as1.maarita(1, 100);
        as2.maarita(2, 100);
    }
    double laskeKulutus(double kulutus) override
    {
        kulutus = as1.laskeKulutus(kulutus) + as2.laskeKulutus(kulutus);
        return kulutus;
    }
};
class Kerrostalo
{
private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;

public:
    Kerrostalo()
    {
        cout << "Luodaan kerrostalo" << endl;
    }
    double laskeKulutus(double kulutus)
    {
        kulutus = eka.laskeKulutus(kulutus) + toka.laskeKulutus(kulutus) + kolmas.laskeKulutus(kulutus);
        return kulutus;
    }
};

int main()
{
    Asunto as1;
    as1.maarita(1, 100);
    cout << as1.laskeKulutus(100) << endl;

    Kerros kerros;
    kerros.maaritaAsunnot();
    cout << kerros.laskeKulutus(100) << endl;

    Katutaso katu;
    katu.maaritaAsunnot();
    cout << katu.laskeKulutus(100) << endl;
    return 0;
}