// Example program
#include <iostream>
#include <string>

using namespace std;



class Fabrica{

  protected:

    string nume;
    int nr_componente;


  public:
  
    static int nr;  //pt a stii cate computere exista
    
    Fabrica(string n , int c):nume(n),nr_componente(c){nr++; cout<<"Object created!\n";};

    int get_nr_componente() {
        return this->nr_componente;
    }

    void set_nr_componente(int nr) {
        nr_componente = nr;
    }

    string get_nume() {
        return this->nume;
    }
    
    void set_nume(string nume_nou) {
        nume = nume_nou;
    }
    
    virtual ~Fabrica()
    {
        cout<<"Oobject has been destroyed!\n";
    }

  private:
    Fabrica(const Fabrica& other); //uncopyable
    Fabrica& operator=(const Fabrica&);//copy assignment not allowed

 
};

int Fabrica::nr = 0;


int main()
{
    Fabrica f("fabrica de bere", 30);
    
    std::cout << f.get_nume() << std::endl;
    
    f.set_nume("fabrica de pantofi");
    f.set_nr_componente(5);
    
    std::cout << f.get_nume() << " " << f.get_nr_componente() << std::endl;

}