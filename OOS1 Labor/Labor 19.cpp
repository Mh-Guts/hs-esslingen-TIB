//Themen:

//Polymorphismus, abstract classes
//Ihre Aufgabe :

//Schreiben Sie die abstrakte Basisklasse 'Meal' mit den Methoden 'add_topping' und 'prepare'.Implementieren sie die Klassen Pizza und Burger, sodass das vorhandene Programmfragment kompiliert werden und mittels der Zeile* [1] folgendes auf der Konsole ausgegeben werden kann :

//Pizza Mista.Pizzaboden, belegt mit :
//-Salami
//- Pilzen
//Pizza Hawaii.Pizzaboden, belegt mit :
//-Schinken
//- Ananas
//Hamburger.Brötchen mit :
//-Hackfleisch
//Cheesburger.Brötchen mit :
//-Hackfleisch
//- Käse

//Nutzen Sie die Vererbung von Instanzvariablen und Instanzmethoden entsprechend

#include <array>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//Klasse Meal
class Meal {
protected:
    string name;
    vector<string> zutaten;

public:
    Meal(string name);
    void add_topping(string zutat);
    virtual void prepare() = 0;
};

Meal::Meal(string name): name(name){}
void Meal::add_topping(string zutat) {
    zutaten.push_back(zutat);
}

//Klasse Pizza 
class Pizza : public Meal {
public:
    Pizza(string name);
    void add_topping(string zutat);
    void prepare() override;
};

Pizza::Pizza(string name) : Meal(name) {}
    void Pizza::add_topping(string zutat) {
        Meal::add_topping(zutat);
    }
    void Pizza::prepare() {
        cout << "Pizza " << name << ". Pizzaboden, belegt mit:" << endl;
        for (string zutat : zutaten) {
            cout << "- " << zutat << endl;
        }
    }

    //Klasse Burger
    class Burger : public Meal {
    public:
        Burger(string name);
        void add_topping(string zutat);
        void prepare() override;
    };
    Burger::Burger(string name): Meal(name) {}
    void Burger::add_topping(string zutat) {
        Meal::add_topping(zutat);
    }
    void Burger::prepare() {
        cout << name << ". Brötchen mit:" << endl;
        for (string zutat : zutaten) {
            cout << "- " << zutat << endl;
        }
    }


int main(int argc, char* argv[])
{
    Pizza* mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal* hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger* hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal* cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal*, 4> menu = { mista, hawaii, hamburger, cheesburger };
    for (Meal* g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}
