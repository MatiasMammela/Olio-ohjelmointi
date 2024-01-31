#include <iostream>
using namespace std;
class Asunto
{

public:
    int asukasMaara;
    int neliot;
    void maarita(int asukasMaara, int neliot)
    {
        cout << "Määritetään asunnon tiedot" << endl;
        this->asukasMaara = asukasMaara;
        this->neliot = neliot;
    }
    double laskeKulutus(double kulutus)
    {
        cout << "Lasketaan asunnon kulutus" << endl;
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
    virtual void maaritaAsunnot()
    {
        as1.maarita(1, 100);
        as2.maarita(2, 100);
        as3.maarita(3, 100);
        as4.maarita(4, 100);
    }
    virtual double laskeKulutus(double kulutus)
    {
        cout << "Lasketaan kerroksen kulutus" << endl;
        kulutus = as1.laskeKulutus(kulutus) + as2.laskeKulutus(kulutus) + as3.laskeKulutus(kulutus) + as4.laskeKulutus(kulutus);
        return kulutus;
    }
};

class Katutaso : public Kerros
{
public:
    Asunto as1;
    Asunto as2;
    void maaritaAsunnot() override
    {
        as1.maarita(1, 100);
        as2.maarita(2, 100);
    }
    double laskeKulutus(double kulutus) override
    {
        cout << "Lasketaan kadun kulutus" << endl;
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
    double laskeKulutus(double kulutus)
    {
        eka.maaritaAsunnot();
        toka.maaritaAsunnot();
        kolmas.maaritaAsunnot();
        cout << "Lasketaan kerrostalon kulutus" << endl;
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

    Kerrostalo talo;
    cout << talo.laskeKulutus(100) << endl;
    return 0;
}