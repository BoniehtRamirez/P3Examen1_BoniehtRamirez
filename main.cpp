#include <iostream>
#include <vector>
#include <string>

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
		<< "Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		
		switch(opcion){
			case 1:{
				string IP,netmask,hostname;
				cout << "Ingrese IP: ";
				cin >> IP;
				cout << "Ingrese Netmask: ";
				cin >> netmask;
				cout << "Ingrese Hostname: ";
				cin >> hostname;
				
				pcs.push_back(PC(IP,netmask,hostname));
				cout << "PC agregada!!" << endl;
				break;
			}
			case 2:{
				if(pcs.size() == 0){
					cout << "No hay PCs creadas..." << endl;
				} else {
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
						cout << "      IP : " << pcs[sel].getIP() << endl;
						cout << "      Netmask : " << pcs[sel].getNetMask() << endl;
						cout << pcs[sel].getHostName() << "#" << endl;
					} else if(comando == "exit"){
						return 0;
					} else {
						string ping = comando.substr(5);
						cout << ping << endl;
					}
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
