#include <iostream>
#include <string>
#include <iomanip>
class Criptomoneda
{
private:
    std::string nume;
    float val_fractionara;
    float val_curenta;
public:
    Criptomoneda(std::string nume,float val_fractionara,float val_curenta)
     :nume(nume),val_fractionara(val_fractionara), val_curenta(val_curenta){}
    void afisare()
    {
        std::cout<<this->nume<<" ";
        std::cout<<std::fixed<<std::setprecision(2)<<this->val_fractionara<<" ";
        std::cout<<std::fixed<<std::setprecision(2)<<this->val_curenta<<std::endl;
    }
    std::string get_nume()
    {
        return this->nume;
    }
    float get_val_fractionara()
    {
        return this->val_fractionara;
    }
    float get_val_curenta()
    {
        return this->val_curenta;
    }
    void adaugare_val_fractionara(float valoare)
    {
        this->val_fractionara=this->val_fractionara+valoare;
    }
    void set_val_fractionara(float valoare)
    {
        this->val_fractionara=valoare;
    }
    
};
class Portofel
{
private:
    float sold_initial;
    int n;
    int capacitate;
    Criptomoneda **c;
public:
    Portofel(float sold_initial,int capacitate):sold_initial(sold_initial),capacitate(capacitate),n(0)
    {
        c=new Criptomoneda*[capacitate];
    }
    ~Portofel()
    {
        for(int i=0;i<n;i++) delete c[i];
        delete[] c;
    }
    void set_criptomoneda(std::string nume,float val_fractionara,float val_curenta)
    {
        c[n]=new Criptomoneda(nume,val_fractionara,val_curenta);
        n++;
    }
    void afisare_criptomoneda(int test)
    {
        if(test==1 || test==4) std::cout<<std::fixed<<std::setprecision(2)<<this->sold_initial<<std::endl;
        for(int i=0;i<n;i++)
        {
            c[i]->afisare();
        }
    }
    void cumparare_criptomonede(std::string nume,float val_fractionara,int test)
    {
        float unitati;
        for(int i=0;i<n;i++)
        {
            if(c[i]->get_nume()==nume)
            {
                float suma=val_fractionara*c[i]->get_val_curenta();
                if(suma<=this->sold_initial)
                {
                  c[i]->adaugare_val_fractionara(val_fractionara);
                  this->sold_initial -= suma;
                }
                else if(suma>this->sold_initial)
                {
                    unitati=this->sold_initial/c[i]->get_val_curenta();
                    c[i]->adaugare_val_fractionara(unitati);
                    this->sold_initial=0;
                }
                if(test==2) c[i]->afisare();
                
            }
        }
    }
    void vanzare_criptomonede(std::string nume,float val_fractionara,int test)
    {
        for(int i=0;i<n;i++)
        {
            float f=c[i]->get_val_fractionara();
            if(c[i]->get_nume()==nume)
            {
                float valoare_tranzactie=0;
                if(f<=val_fractionara)
                {
                    valoare_tranzactie=f;
                    f=0;
                }
                else if(f>val_fractionara)
                {
                    valoare_tranzactie= val_fractionara;
                    f=f-val_fractionara;
                }
                c[i]->set_val_fractionara(f);
                this->sold_initial += valoare_tranzactie * c[i]->get_val_curenta();
                if(test==3) c[i]->afisare();
            }
        }
    }
};
int main()
{
    float sold_initial;
    int n;
    std::cin>>sold_initial>>n;
    
    Portofel p(sold_initial,n);
    
    std::string nume;
    float val_fractionara;
    float val_curenta;
    for(int i=0;i<n;i++)
    {
        std::cin>>nume>>val_fractionara>>val_curenta;
        p.set_criptomoneda(nume,val_fractionara,val_curenta);
    }
    
    int test;
    std::cin>>test;
    
    if(test==1)
    {
        p.afisare_criptomoneda(test);
    }
    else if(test==2)
    {
        std::cin>>nume>>val_fractionara;
        p.cumparare_criptomonede(nume,val_fractionara,test);
        
    }
    else if(test==3)
    {
        std::cin>>nume>>val_fractionara;
        p.vanzare_criptomonede(nume,val_fractionara,test);
    }
    else if(test==4)
    {
        int nr;
        std::string tranzactie[100];
        std::string nume[100];
        float val_fractionara[100];
        std::cin>>nr;
        for(int i=0;i<nr;i++)
        {
            std::cin>>tranzactie[i]>>val_fractionara[i]>>nume[i];
        }
        for(int i=0;i<nr;i++)
        {
        if(tranzactie[i]=="cumpara")
        {
            p.cumparare_criptomonede(nume[i],val_fractionara[i],test);
        }
        else if(tranzactie[i]=="vinde")
        {
            p.vanzare_criptomonede(nume[i],val_fractionara[i],test);
        }
        }
        p.afisare_criptomoneda(test);
    }
}
