#include <iostream>
#include <string>
#include <memory>
using namespace std;



class Animal{

  protected:

    string nume;
    int nr_componente;
    bool capturat;

  public:
  
    static int nr; 
    
    Animal(string n , int c) {
        nume = n;
        nr_componente = c;
        nr++; 
        capturat = false;
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
    void setCapturat (bool v) {
        this->capturat = v;
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

//lucrarea 6
void lock(Animal *A) {
    A->setCapturat(true);
    cout << "Animalul este capturat" << std::endl;
}

void unlock(Animal *A) {
    A->setCapturat(false);
    cout << "Animalul este in libertate " << std::endl;
}

class AnimalCapturat {
    private:
    shared_ptr<Animal> animalptr;

    public:
    explicit AnimalCapturat(Animal *A):animalptr(A, unlock) {
        lock(animalptr.get());
    }
};

Animal* createAnimal(string nume, int nr_componente) {
    return (new Animal(nume,nr_componente));
}


int main()
{
    // Animal a1("animal1", 30);
    
    // cout << a1.get_nume() << std::endl;
    
    // a1.set_nr_componente(5);
    
    // cout << a1.get_nume() << " " << a1.get_nr_componente() << std::endl;
    
    // Caine c1("caine1", 20);
    // Caine c2("caine2", 5);
    // Caine c3("caine3", 9);
    
    // c1 = c2 = c3;           //copy assignmet
    
    // cout << c1.get_nume() << " " << c1.get_nr_componente() << std::endl;

    // c2 = c2;               //self assignmet
    
    
    // Pisica p1("pisica1", 2);
    // Pisica p2("pisica2", 3);
    // Pisica p3("pisica3", 4);
    
    // p1 = p2 = p3;           //copy assignmet
    
    // cout << p1.get_nume() << " " << p1.get_nr_componente() << std::endl;

    // p3 = p3;               //self assignmet
    
    
    auto_ptr<Animal> autoA1(createAnimal("tigru", 20));
    cout << autoA1->get_nume() << endl;
    
    unique_ptr<Animal> uniqueA1(createAnimal("delfin", 20));
	cout << uniqueA1->get_nume() << endl;
	//unique_ptr<Animal> uniqueA2(uniqueA1);
	//nu merge pentru ca nu putem copia un unique_ptr
	
	unique_ptr<Animal> uniqueA2 = std::move(uniqueA1);
	cout << uniqueA2->get_nume() << endl;
	
    Animal a1("maimuta", 20);
    AnimalCapturat ac1(&a1);
    AnimalCapturat ac2(ac1); 
    //animalul este capturat dupa care este lasat in libertate
};