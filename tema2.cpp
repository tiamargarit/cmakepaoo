// Example program
#include <iostream>
#include <string>

using namespace std;



class Animal{

  protected:

    string nume;
    int nr_componente;


  public:
  
    static int nr; 
    
    Animal(string n , int c) {
        nume = n;
        nr_componente = c;
        nr++; 
        cout<<"Un obiect de tip Animal a fost creat\n";
    };

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
    
    virtual ~Animal() {
        cout<<"Un obiect de tip Animal a fost sters\n";
    }

    Animal(const Animal& f) {
        cout << "Copy constructor din Animal\n";
    }

};

int Animal::nr = 0;

class Caine : public Animal {
    
    public:
    
        Caine(string n, int c): Animal(n, c) {
            cout<<"Un obiect de tip Caine a fost creat\n";
        }
        
        Caine(const Caine &c) : Animal(c.nume, c.nr_componente){
            cout << "Copy constructor din Caine\n";
        }
        
        ~Caine(){
            cout << "Un obiect de tip Caine a fost sters\n";
        }
        
        Caine& operator=(Caine const& c){
        if(this != &c){
            this->nume = c.nume;
            this->nr_componente = c.nr_componente;
            cout << "Copy assigment in Caine\n";
            return *this;
        }
        cout << "Self assigment in Caine\n";
        return *this;
    }
};

class Pisica : public Animal {
    
    public:
    
        Pisica(string n, int c): Animal(n, c) {
            cout<<"Un obiect de tip Pisica a fost creat\n";
        }
        
        Pisica(const Pisica &m) : Animal(m.nume, m.nr_componente){
            cout << "Copy constructor din Pisica\n";
        }
        
        ~Pisica(){
            cout << "Un obiect de tip Pisica a fost sters\n";
        }
        
        Pisica& operator=(Pisica const& p){
        if(this != &p){
            this->nume = p.nume;
            this->nr_componente = p.nr_componente;
            cout << "Copy assigment in Pisica\n";
            return *this;
        }
        cout << "Self assigment in Pisica\n";
        return *this;
    }
};


int main()
{
    Animal a1("animal1", 30);
    
    std::cout << a1.get_nume() << std::endl;
    
    a1.set_nr_componente(5);
    
    std::cout << a1.get_nume() << " " << a1.get_nr_componente() << std::endl;
    
    Caine c1("caine1", 20);
    Caine c2("caine2", 5);
    Caine c3("caine3", 9);
    
    c1 = c2 = c3;           //copy assignmet
    
    std::cout << c1.get_nume() << " " << c1.get_nr_componente() << std::endl;

    c2 = c2;               //self assignmet
    
    
    Pisica p1("pisica1", 2);
    Pisica p2("pisica2", 3);
    Pisica p3("pisica3", 4);
    
    p1 = p2 = p3;           //copy assignmet
    
    std::cout << p1.get_nume() << " " << p1.get_nr_componente() << std::endl;

    p3 = p3;               //self assignmet
    
};