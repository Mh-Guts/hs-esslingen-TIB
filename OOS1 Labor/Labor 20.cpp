//Themen:

//Interfaces, Dependency Inversion Principle
//Ihre Aufgabe :

//Setzen Sie das Dependency Inversion Principle um.

//Implementieren Sie eine Klasse "AuthenticationResult" mit den konstanten Attributen "_c_is_authenticated" von Typ bool und "_c_username" vom typ string, einem parametrisierten Kontruktor, der die Attribute initialisiert sowie getter - Methoden um die jeweilingen Werte auszulesen.Der Parameter für den Usernamen soll den default - Wert "unauthenticated_user" enthalten.

//Schreiben Sie ein Interface "IAuthenticationProcedure", das die rein virtuelle Methode "authenticate" mit dem Rückgabewert "AuthenticationResult" enthält.

//Schreiben Sie eine Klasse "Client" mit dem Attribut "_authentication_procedure" vom Typ Pointer auf "IAuthenticationProcedure".Die Methode "set_authentication_procedure" nimmt einen Pointer auf "IAuthenticationProcedure" entgegen und setzt das Attribut "_authentication_procedure" entsprechend.Die methode "execute" nimmt keine Parameter entgegen und führt die folgende Logik aus : Es führt zunächst auf dem "_authentication_procedure" - Attribut die Methode "authenticate" aus und weist das Ergebnis einer konstanten vom Typ "AuthenticationResult" zu.Weist das "AuthenticationResult" ein positives Ergebnis aus, so wird auf der Konsole folgendes ausgegeben :

//Das Programm wird ausgeführt für[user].

//War die Authentifizierung nicht erfolgreich so wird folgendes ausgegeben :

//Das Programm konnte nicht ausgeführt werden.

//Schreiben Sie drei verschiedene Implementierungen des Interfaces "IAuthenticationProcedure" : "MockAuth", "UsernamePassword" und "Certificate".

//Die Klasse "MockAuth" gibt in jedem Fall ein positives "AuthenticationResult" für den Username "Default" zurück.

//Die Klasse "UsernamePassword" liest nacheinander zunächst den Usernamen und das Passwort ein.Dazu wird der Anwender jeweils über die Konsole zur Eingabe aufgefordert :

//Username:

//bzw.

//Password :

//	Sind Username und Passwort identisch, so gibt die Klasse ein positives "AuthenticationResult" für den entsprechenden Username zurück.Andernfalls wird ein negatives "AuthenticationResult" zurückgegeben.

//	Die Klasse "Certificate" liest den Zertifikatsaussteller von der Konsole ein.Der Anwender wird hierzu folgendermaßen aufgefordert :

//Zertifikatsaussteller:

//Ist der Zertifikatsaussteller "hs-esslingen" so gibt die Klasse ein positives "AuthenticationResult" zurück mit dem Usernamen "certificate.owner".Andernfalls wird ein negatives "AuthenticationResult" zurückgegeben.

//Für die Eingaben :

//Username:
//Maier
//Passwort :
//Maier

//Zertifikatsaussteller :
//hs - esslingen

//erzeugt das Programm die folgende(Ein - )Ausgabe :

	//Authentifizierung über MockAuth
	//Das Programm wird ausgeführt für Default.
	//Authentifizierung über UsernamePassword
	//Username :
//Maier
//Password :
//Maier
//Das Programm wird ausgeführt für Maier.
//Authentifizierung über Zertifikat
//Zertifikatsaussteller :
//hs - eslingen
//Das Programm wird ausgeführt für certificate.owner.

#include <string>
#include <iostream>

using namespace std;

class AuthenticationResult {
    bool authenticated;
    string username;
public:
    AuthenticationResult(bool authenticated, string username);
    bool isAuthenticated();
    string getUsername();
    void set_authentication_procedure(bool authenticated);
    void setUsername(string username);
};

AuthenticationResult::AuthenticationResult(bool authenticated, string username = "unauthenticated_user")
    : authenticated(authenticated), username(username) {}
bool AuthenticationResult::isAuthenticated() {
    return authenticated;
}
string AuthenticationResult::getUsername() {
    return username;
}
void AuthenticationResult::set_authentication_procedure(bool authenticated) {
    this->authenticated = authenticated;
}
void AuthenticationResult::setUsername(string username) {
    this->username = username;
}

class IAuthenticationProcedure {
public:
    virtual AuthenticationResult authenticate() = 0;
};

class Client {
    IAuthenticationProcedure* auth = nullptr;
    AuthenticationResult authResult = AuthenticationResult(false, "unauthenticated_user");
public:
    void set_authentication_procedure(IAuthenticationProcedure* auth);
    void execute();
};

void Client::set_authentication_procedure(IAuthenticationProcedure* auth) {
    this->auth = auth;
}

void Client::execute() {
    authResult = auth->authenticate();
    if (authResult.isAuthenticated()) {
        cout << "Das Programm wird ausgeführt für " << authResult.getUsername() << "." << endl;
    }
    else {
        cout << "Das Programm konnte nicht ausgeführt werden." << endl;
    }
}


class MockAuthentication : public IAuthenticationProcedure {
public:
    AuthenticationResult authenticate();
};

AuthenticationResult MockAuthentication::authenticate() {
    return AuthenticationResult(true, "Default");
}





class UsernamePassword : public IAuthenticationProcedure {
public:
    AuthenticationResult authenticate();
};

AuthenticationResult UsernamePassword::authenticate() {
    string username;
    string password;
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    if (username == password) {
        return AuthenticationResult(true, username);
    }
    else {
        return AuthenticationResult(false, username);
    }
}





class Certificate : public IAuthenticationProcedure {
public:
    AuthenticationResult authenticate();
};

AuthenticationResult Certificate::authenticate() {
    string certOwner;
    cout << "Zertifikatsaussteller: " << endl;
    cin >> certOwner;
    if (certOwner == "hs-esslingen") {
        return AuthenticationResult(true, "certificate.owner");
    }
    else {
        return AuthenticationResult(false);
    }
}



int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure* mock_authentication = new MockAuthentication();
    client.set_authentication_procedure(mock_authentication);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
    IAuthenticationProcedure* username_password = new UsernamePassword();
    client.set_authentication_procedure(username_password);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
    IAuthenticationProcedure* certificate = new Certificate();
    client.set_authentication_procedure(certificate);
    client.execute();
    return 0;
}

