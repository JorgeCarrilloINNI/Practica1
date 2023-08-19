#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Paquete {
public:
    int id;
    string origen;
    string destino;
    float peso;
    Paquete* siguiente;

    Paquete(int _id, string _origen, string _destino, float _peso) : id(_id), origen(_origen), destino(_destino), peso(_peso), siguiente(nullptr){
	}
};

class Paqueteria {
	public:
	    Paquete* inicio;
	    Paqueteria() : inicio(nullptr){
		}
	    
	    void agregarPaquete(int id, string origen, string destino, float peso){
		    Paquete* nuevoPaquete = new Paquete(id, origen, destino, peso);
		
		    nuevoPaquete->siguiente = inicio;
		    inicio = nuevoPaquete;
		
		    cout<<"Paquete registrado"<<endl;
		}
		
		void eliminarPaquete(){
			int opcion;
			
			if (!inicio) {
     	   		cout << "La lista de paquetes está vacía." << endl;
        		return;
    		}
			
			Paquete* paqueteEliminacion = inicio;
			cout<<"Desea eliminar el paquete: "<<endl;
			cout<<"Id: "<<paqueteEliminacion->id<<", Origen: "<<paqueteEliminacion->origen<<", Destino: "<<paqueteEliminacion->destino<<", Peso: "<<paqueteEliminacion->peso<<endl;
			cout<<"1.- Si"<<endl;
			cout<<"2.- No"<<endl;
			cin>>opcion;
			
			if(opcion == 1){
				inicio = inicio->siguiente;
				delete paqueteEliminacion;
				cout<<"Paquete eliminado"<<endl;
			}
			
		}
	
	    void mostrarPaquetes() {
	        Paquete* actual = inicio;
	        while (actual){
	            cout<<"Id: "<<actual->id<<", Origen: "<<actual->origen<<", Destino: "<<actual->destino<<", Peso: "<<actual->peso<<endl;
	            actual = actual->siguiente;
	        }
	    }
	    
	    void guardarArchivo(){
	    	ofstream archivo("paquetes.txt");
	    	
	    	if(!archivo.is_open()){
	    		cout<<"No se pudo abrir el archivo"<<endl;
	    		return;
			}
			
			Paquete* actual = inicio;
			while(actual){
				archivo<<actual->id<<endl;
		        archivo<<actual->origen<<endl;
		        archivo<<actual->destino<<endl;
		        archivo<<actual->peso<<endl;
		        actual = actual->siguiente;
			}
			archivo.close();
			cout<<"Consulta el archivo paquetes.txt para ver los registros"<<endl;
		}
		
		void recuperarArchivo(){
			ifstream archivo("paquetes.txt");
			int id;
			string origen, destino;
			float peso;
			
			if(!archivo.is_open()){
	    		cout<<"No se pudo abrir el archivo"<<endl;
	    		return;
			}
			
			while(archivo >> id >> origen >> destino >> peso){
				agregarPaquete(id, origen, destino, peso);
			}
			
			archivo.close();
			cout<<"Informacion recuperada desde paquetes.txt revise los paquetes"<<endl;
		}
	
	    ~Paqueteria() {
	        Paquete* actual = inicio;
	        while (actual) {
	            Paquete* siguiente = actual->siguiente;
	            delete actual;
	            actual = siguiente;
	        }
	    }
};

int main() {
    Paqueteria paqueteria;
    int opcion = 0, id;
	string origen, destino;
	float peso;

    while (opcion != 6) {
        cout<<"*****Menu*****"<<endl;
		cout<<"1.- Agregar paquete"<<endl;
		cout<<"2.- Eliminar paquete"<<endl;
		cout<<"3.- Mostrar paquetes"<<endl;
		cout<<"4.- Guardar"<<endl;
		cout<<"5.- Recuperar"<<endl;
		cout<<"6.- Salir"<<endl;
		cout<<"Ingrese su opcion: ";
		cin>>opcion;

        switch (opcion) {
            case 1:	
				cout<<"Ingrese el id"<<endl;
				cin>>id;
				cout<<"Ingrese el origen"<<endl;
				cin>>origen;
				cout<<"Ingrese el destino"<<endl;
				cin>>destino;
				cout<<"Ingrese el peso"<<endl;
				cin>>peso;
				
                paqueteria.agregarPaquete(id, origen, destino, peso);
                break;
            case 2:
            	paqueteria.eliminarPaquete();
                break;
            case 3:
                paqueteria.mostrarPaquetes();
                break;
            case 4:
            	paqueteria.guardarArchivo();
            	break;
            case 5:
            	paqueteria.recuperarArchivo();
            	break;
            case 6:
                cout << "Saliendo..." << endl;
            	break;
            default:
                cout << "Selecciona otra opcion..." << endl;
                break;
        }
    }

    return 0;
}
