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

string toBinary(int numero){
    string binario = "";
    if (numero > 0) {
        while (numero > 0) {
            if (numero%2 == 0) {
                binario = "0"+binario;
            } else {
                binario = "1"+binario;
            }
            numero = (int) numero/2;
        }
    } else if (numero == 0) {
        binario = "0";
    }
    
    return binario;
}

bool match(string ip, string destinataryIP){
	string total_ip_1 = "";
	string temp = "";
	for(int i=0; i < ip.size(); i++){
		if(ip[i] != '.'){
			temp+=ip[i];
		} else {
			total_ip_1 += toBinary(stoi(temp));
			temp = "";
		}
	}
	total_ip_1 += toBinary(stoi(temp));
	
	string total_ip_2 = "";
	temp = "";
	for(int i=0; i < destinataryIP.size(); i++){
		if(ip[i] != '.'){
			temp+=destinataryIP[i];
		} else {
			total_ip_2 += toBinary(stoi(temp));
			temp = "";
		}
	}
	total_ip_2 += toBinary(stoi(temp));
	
	if(total_ip_1.substr(0,26) == total_ip_2.substr(0,26)){
		return true;
	} else {
		return false;
	}
}


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
				cout << endl << "PC agregada!!" << endl;
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
						string ip = comando.substr(5);
						cout << ip << endl;
						
						bool matched = false;
						for(int i=0; i < pcs.size();i++){
							if(pcs[i].getIP() == ip)
								matched = true;
						}
						
						if(matched){
							if(match(pcs[sel].getIP(),ip)){
								cout << endl << "Pinging to " << ip << " with 32 bytes of data:" << endl << endl;
								for(int i=0; i < 4; i++){
									cout << "Reply from " << ip << ": bytes=32 time=37s TTL=46" << endl;
								}
								
								cout << endl << "Ping statistics for " << ip << ":" << endl;
								cout << "     Packets: Sent =  4, Received = 4, Lost = 0 (0% Lost)" << endl; 
							} else {
								cout << endl << "Pinging to " << ip << " with 32 bytes of data:" << endl << endl;
								for(int i=0; i < 4; i++){
									cout << "Reply from " << ip << ": Destination host unreachable" << endl;
								}
								
								cout << endl << "Ping statistics for " << ip << ":" << endl;
								cout << "     Packets: Sent =  4, Received = 4, Lost = 0 (0% Lost)" << endl; 
							}
							
						} else {
							cout << endl << "Pinging to " << ip << " with 32 bytes of data:" << endl << endl;
							for(int i=0; i < 4; i++){
								cout << "Request timed out" << endl;
							}
							
							cout << endl << "Ping statistics for " << ip << ":" << endl;
							cout << "     Packets: Sent =  4, Received = 0, Lost = 4 (100% Lost)" << endl; 
						}
						
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
