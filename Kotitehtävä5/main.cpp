#include <iostream>
using namespace std;
class Asunto
{
public:
    int *asukasMaara;
    int *neliot;
    Asunto()
    {
        asukasMaara = new int;
        neliot = new int;
    }
    ~Asunto()
    {
        delete asukasMaara;
        delete neliot;
    }
    void maarita(int asukasMaara, int neliot)
    {
        cout << "Määritetään asunnon tiedot" << endl;
        *this->asukasMaara = asukasMaara;
        *this->neliot = neliot;
    }
    double laskeKulutus(double kulutus)
    {
        cout << "Lasketaan asunnon kulutus" << endl;
        kulutus = *asukasMaara * *neliot;
        return kulutus;
    }
};

class Kerros
{
public:
    Asunto *as1;
    Asunto *as2;
    Asunto *as3;
    Asunto *as4;
    Kerros()
    {
        as1 = new Asunto();
        as2 = new Asunto();
        as3 = new Asunto();
        as4 = new Asunto();
    }
    virtual void maaritaAsunnot()
    {
        as1->maarita(1, 100);
        as2->maarita(2, 100);
        as3->maarita(3, 100);
        as4->maarita(4, 100);
    }
    virtual double laskeKulutus(double kulutus)
    {
        cout << "Lasketaan kerroksen kulutus" << endl;
        kulutus = as1->laskeKulutus(kulutus) + as2->laskeKulutus(kulutus) + as3->laskeKulutus(kulutus) + as4->laskeKulutus(kulutus);
        return kulutus;
    }
};

class Katutaso : public Kerros
{
public:
    Asunto *as1;
    Asunto *as2;
    Katutaso() : Kerros()
    {
        as1 = new Asunto();
        as2 = new Asunto();
    }
    void maaritaAsunnot() override
    {
        as1->maarita(1, 100);
        as2->maarita(2, 100);
    }
    double laskeKulutus(double kulutus) override
    {
        cout << "Lasketaan kadun kulutus" << endl;
        kulutus = as1->laskeKulutus(kulutus) + as2->laskeKulutus(kulutus);
        return kulutus;
    }
};

class Kerrostalo
{
private:
    Katutaso *eka;
    Kerros *toka;
    Kerros *kolmas;

public:
    Kerrostalo()
    {
        eka = new Katutaso();
        toka = new Kerros();
        kolmas = new Kerros();
    }
    double laskeKulutus(double kulutus)
    {
        eka->maaritaAsunnot();
        toka->maaritaAsunnot();
        kolmas->maaritaAsunnot();

        kulutus = eka->laskeKulutus(kulutus) + toka->laskeKulutus(kulutus) + kolmas->laskeKulutus(kulutus);
        return kulutus;
    }
};

int main()
{
    Kerrostalo *kerrostalo = new Kerrostalo();
    cout << "Kerrostalon kulutus on " << kerrostalo->laskeKulutus(100) << endl;
    delete kerrostalo;
    return 0;
}
