#include <iostream>
#include <vector>


using namespace std;


class PC{
	private:
		string IP, netmask,hostname;
	public:
		PC(string _IP, string _netmask, string _hostname){
			IP = _IP;
			netmask = _netmask;
			hostname = _hostname;
		}
		void ping(string _IPdestination){
			
		}
		string getHostName(){
			return hostname;
		}
		string getIP(){
			return IP;
		}
		string getNetMask(){
			return netmask;
		}
};

vector<PC>pcs;

int main(int argc, char** argv) {
	while(true){
		int opcion;
		cout << "1. Agregar PC" << endl
		<< "2. Ingresar a PC" << endl
		<< "3. Salir" << endl
		<< "Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		
		switch(opcion){
			case 1:{
				string IP,netmask,hostname;
				cout << "Ingrese IP: ";
				cin >> IP;
				cout << "Ingrese netmask: ";
				cin >> netmask;
				cout << "Ingrese hostname: ";
				cin >> hostname;
				
				
				break;
			}
			case 2:{
				int sel;
				for(int i=0; i < pcs.size();i++){
					cout << (i+1) << ". " << pcs[i].getHostName() << endl;
				}
				cout << "Seleccione pc: ";
				cin >> sel;
				sel--;
				
				string comando;
				cout << endl << pcs[sel].getHostName() << "#";
				cin >> comando;
				
				if(comando == "show"){
					
				} else if(comando == "exit"){
					return 0;
				}
				break;
			}
			default:{
				cout << "Opcion incorrecta" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
