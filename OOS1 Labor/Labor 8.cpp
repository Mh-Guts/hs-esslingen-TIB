//Themen:

//Komposition
//Ihre Aufgabe:

//Das Programm, das sie entwickeln werden, kann grafische Objekte (Punkte, Kreise, ...) als Objekte von Klassen darstellen. Sie können sich die Objekte als Datenrepräsentationen von grafischen Objekten in einem Zeichenprogramm vorstellen. Die grafischen Objekte sind definiert über Koordinaten und könnten (später) Eigenschaften haben wie z.B. eine Strichstärke und -art.

//Sie sollen zwei Klassen definieren: Point und Circle.

//(a) Die Klasse Point repräsentiert das geometrische Objekt Punkt.

//(b) Die Klasse hat die Instanzvariablen '_x' und '_y' vom Typ double. Diese beiden Instanzvariablen repräsentieren die x- und y-Koordinaten eines Punktes.

//(c) Die Klasse Circle repräsentiert einen Kreis.

//(d) Sie hat die Instanzvariablen '_centre' vom Typ 'Point' und '_radius' vom Typ double. Die Variable '_centre' steht also für den Mittelpunkt des Kreises.

//(e) In beiden Klassen sollen die Instanzvariablen vor Zugriff von außerhalb der Klasse geschützt sein.

//(f) Schreiben Sie für beide Klassen Konstruktoren mit geeigneten Defaultparametern.

//(g) Schreiben sie get- und set-Methoden für alle Instanzvariablen.

//(h) Die Instanzfunktion 'move(double dx, double dy)' verschiebt einen Punkt bzw. einen Kreis um die Werte 'dx' und 'dy' in x- bzw. y-Richtung.

//(i) Beide Klassen sollen eine Funktion 'print' besitzen, welche die Koordinaten eines Punktes bzw. die Koordinaten des Mittelpunktes und den Radius eines Kreises auf dem Bildschirm ausgibt. Die Funktion 'print' besitzt einen Parameter vom Typ 'bool', der steuert, ob nach der Ausgabe ein Zeilenvorschub (endl) durchgeführt wird oder nicht. Der Defaultwert für diesen Parameter soll 'true' sein. Die Ausgabe des gegebenen Hauptprogrammes ist unten angegeben:

//Ausgabe:

//Ausgabe 1:
//(0, 0)
//[(0, 0), 1]
//Ausgabe 2:
//(1.1, 2.2) == (1.1, 2.2)
//[(1.1, 2.2), 3.3]
//Ausgabe 3:
//(2.1, 3.2)
//[(3.1, 4.2), 3.3]



#include <iostream>
#include <iomanip>
using namespace std;

// Klasse Point und Circle implementieren
class Point {
private: 
	double _x;
	double _y;

public:
	//Konstruktor mit Default-Parametern
		Point(double x = 0.0, double y = 0.0) : _x(x), _y(y){}

	//Getter und Setter 
	double get_x() const { return _x; }
	double get_y() const { return _y; }
	void set_x(double x) { _x = x; }
	void set_y(double y) { _y = y; }

	//Funktion zum Verschieben des Punktes
	void move(double dx, double dy) {
		_x += dx;
		_y += dy;
	}

	//Funktion zum Ausgeben der Koordinaten
	void print(bool newline = true) const {
		cout << "(" << _x << ", " << _y << ")";
		if (newline)
			cout << endl;
	}
};

class Circle {
private:
	Point _centre;
	double _radius;

public:
	//Konstruktor mit Default-Parametern
	Circle(const Point& centre = Point(), double radius = 1.0) : _centre(centre), _radius(radius) {}

	//Getter und Setter
	const Point& get_centre() const { return _centre; }
	double get_radius() const { return _radius; }
	void set_centre(const Point& centre) { _centre = centre; }
	void set_radius(double radius) { _radius = radius; }

	//Funktion verschieben
	void move(double dx, double dy) {
		_centre.move(dx, dy);
	}

	//Funktion zum Ausgeben der Koordinaten des Mittelpunktes und des Radius
	void print(bool newline = true) const {
		cout << "["<<"("<<_centre.get_x()<<", "<<
		_centre.get_y()<<"), "<<_radius<< "]";
			if (newline)
				cout << endl;
	}
};


// Hauptprogramm
int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_centre(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}

