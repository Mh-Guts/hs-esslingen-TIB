//Themen:

//Klassen, Attribute, Methoden
//Ihre Aufgabe :

//Ergänzen Sie das Programmgerippe um die Klasse Punkt mit den Koordinaten x und y vom Typ double.Schreiben sie für die Klasse Punkt die Methode print() sowie getter - und setter - Methoden für die Koordinaten x und y, sodass das Hauptprogramm folgende Ausgabe erzeugt :

//print - Methode :
	//X = 1
	//Y = 10.5
	//X ohne print() : 5
	//Y ohne print() : 10.5



#include<iostream>
using namespace std;

// hier die Klasse Punkt implementieren
class Point
{
private:
    double x;
    double y;

public:
    Point() {
        x = 0.0;
        y = 0.0;
    }

    void set_x(double x_value) {
        x = x_value;
    }
    double get_x() {
        return x;
    }

    void set_y(double y_value) {
        y = y_value;
    }
    double get_y() {
        return y;
    }

    void print() {
        cout << "print-Methode:" << endl;
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }
};

int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}

