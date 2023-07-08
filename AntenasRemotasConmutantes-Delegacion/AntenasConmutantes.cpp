#include <iostream>
#include <string>
using namespace std;

class Antena { //<<Abstract>> <<Interfaz>>
public:
	virtual void f() = 0; //MVP
};


class AntenaRemotaA :public Antena {
public: void f() {
	cout << "A:: f() Conectando y Transmitiendo" << endl;
	cout << "por la Antena Remota A." << endl;
    }
};

class AntenaRemotaB :public Antena {
public: void f() {
	cout << "B:: f() Conectando y Transmitiendo" << endl;
	cout << "por la Antena Remota B." << endl;
   }
};

// La siguienta clase tiene un interruptor de
//delegado para antenaRemotaA o antenaRemotaB

class AntenaRemota : public Antena {
private:
	Antena * antPtr; //aqui puede llegar cualquier antena
public:
	AntenaRemota() {
		antPtr = new AntenaRemotaA(); //antena remota A es el default
	}

	void f() {
		antPtr->f();
	}

	void conmutarHaciaA() {
		delete antPtr; //eliminar la otra antena
		antPtr = new AntenaRemotaA();
	}

	void conmutarHaciaB() {
		delete antPtr; //eliminar la otra antena
		antPtr = new AntenaRemotaB();
	}
};

int main() {
	AntenaRemota* remota = new AntenaRemota();
	remota->f();
	cout << "haciendo conmutacion hacia AntenaRemotaB" << endl;
	remota->conmutarHaciaB();
	remota->f();
	cout << "haciendo conmutacion hacia AntenaRemotaA" << endl;
	remota->conmutarHaciaA();
	remota->f();

	system("pause");
	return 0;
}