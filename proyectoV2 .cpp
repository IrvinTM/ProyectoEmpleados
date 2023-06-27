#include <iostream>
#include <stdio.h>
#include "string"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<stdlib.h>

using namespace std;

class Empleados
{
	protected:
	string primerNombre,segundoNombre,primerApellido,segundoApellido;
    string fecha_Nacimiento,direccion,cargo;
    char sexo;
    int telefono,dui;
    double descuento,sueldo;
public:
//istream& getline (istream& is, string& str);

    void setPrimerNombre(string primerNombre)
        {
            this->primerNombre=primerNombre;
        }
    string getPrimerNombre()
        {
            return primerNombre;
        }
    void setSegundoNombre(string segundoNombre)
        {
            this->segundoNombre=segundoNombre;
        }
    string getSegundoNombre()
        {
            return segundoNombre;
        }
    void setPrimerApellido(string primerApellido)
        {
            this->primerApellido=primerApellido;
        }
    string getPrimerApellido()
        {
            return primerApellido;
        }
    void setSegundoApellido(string segundoApellido)
        {
            this->segundoApellido=segundoApellido;
        }
    string getSegundoApellido()
        {
            return segundoApellido;
        }
    void setSexo(char sexo)
        {
            this->sexo=sexo;
        }
    char getSexo()
        {
            return sexo;
        }
    void setFecha_Nacimiento(string fecha_Nacimiento)
        {
            this->fecha_Nacimiento=fecha_Nacimiento;
        }
    string getFecha_Nacimiento()
        {
            return fecha_Nacimiento;
        }
    void setDireccion(string direccion)
        {
            this->direccion=direccion;
        }   
    string getDireccion()
        {
            return direccion;
        }
    void setTelefono(int telefono)
        {
            this->telefono=telefono;
        }
    int getTelefono()
        {
            return telefono;
        }
    void setDui(int dui)
        {
            this->dui=dui;
        }
    int getDui()
        {
            return dui;
        }
        
    void setSueldo(double sueldo)
        {
            this->sueldo=sueldo;
        }

    double getSueldo()
        {
            return sueldo;
        }
     void setCargo(string cargo)
        {
            this->cargo=cargo;
        }
        string getCargo()
        {
            return cargo;
        }

 Empleados() : sueldo(0.0) {}

virtual double calcularDescuento() 
    {
        double afp = 0.0725, seguro, totalConDescuento, exceso, porcentajeRenta;
        double porcentajeAplicado, rentaFinalAplicada, sueldoTotal;
        double cuota;

        if (sueldo < 1000) {
            seguro = sueldo * 0.03;
        } else if (sueldo >= 1000) {
            seguro = 30;
        }

        // Calculamos el sueldo sin los descuentos nominales
        totalConDescuento = sueldo - ((sueldo * afp) + seguro);

        // TRAMO I
        if (totalConDescuento < 472.00) {
            exceso = 0;
            porcentajeAplicado = 0;
            porcentajeRenta = exceso * porcentajeAplicado;
            cuota = 0;
            rentaFinalAplicada = porcentajeRenta + cuota;
            sueldoTotal = totalConDescuento - rentaFinalAplicada;
            cout << "El sueldo total es " << sueldoTotal << endl;
        }
        // TRAMO II
        else if (totalConDescuento > 472 && totalConDescuento < 895.24) {
            exceso = totalConDescuento - 472.00;
            porcentajeAplicado = 0.1;
            porcentajeRenta = exceso * porcentajeAplicado;
            cuota = 17.67;
            rentaFinalAplicada = porcentajeRenta + cuota;
            sueldoTotal = totalConDescuento - rentaFinalAplicada;

            cout << "El sueldo total es " << sueldoTotal << endl;
        }
        // TRAMO III
        else if (totalConDescuento > 895.24 && totalConDescuento < 2038.1) {
            exceso = totalConDescuento - 895.24;
            porcentajeAplicado = 0.2;
            porcentajeRenta = exceso * porcentajeAplicado;
            cuota = 60;
            rentaFinalAplicada = porcentajeRenta + cuota;
            sueldoTotal = totalConDescuento - rentaFinalAplicada;
            cout << "El sueldo total es " << sueldoTotal << endl;
        }
        // TRAMO IV
        else if (totalConDescuento > 2038.1) {
            exceso = totalConDescuento - 2038.11;
            porcentajeAplicado = 0.3;
            porcentajeRenta = exceso * porcentajeAplicado;
            cuota = 288.57;
            rentaFinalAplicada = porcentajeRenta + cuota;
            sueldoTotal = totalConDescuento - rentaFinalAplicada;
            cout << "El sueldo total es: " << sueldoTotal << endl;
        }
        return sueldoTotal;
    }
};

class Gerentes: public Empleados
{   
	public:
        Gerentes()
        {
         sueldo=5000;
         cargo="Gerente";
        }
};

class Tecnicos: public Empleados
{
	public:
    Tecnicos(){
        sueldo=350;
        cargo="Tecnico";
    }
};

class JefeAreas: public Empleados
{
	public:
	 JefeAreas(){
         sueldo=1500;
         cargo="Jefe de area";
     }
};

class Supervisor: public Empleados
{
	public:
        Supervisor(){
            sueldo=750;
            cargo="Supervisor";
        }
};

void escribirEnArchivoCSV(Empleados* empleado, const string& nombreArchivo) {

    // Se abre el archivo en modo "append" para agregar nuevos registros
    ofstream archivo(nombreArchivo, ios::app); 

    if (archivo.is_open()) {
        archivo << empleado->getPrimerNombre() << ",";
        archivo << empleado->getSegundoNombre() << ",";
        archivo << empleado->getPrimerApellido() << ",";
        archivo << empleado->getSegundoApellido() << ",";
        archivo << empleado->getSexo() << ",";
        archivo << empleado->getFecha_Nacimiento() << ",";
        archivo << empleado->getDireccion() << ",";
        archivo << empleado->getTelefono() << ",";
        archivo << empleado->getDui() << ",";
        archivo << empleado->getCargo()<<",";
        archivo << empleado->calcularDescuento() << endl;

        archivo.close();
        cout << "Datos del empleado escritos en el archivo CSV correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo CSV." << endl;
    }
}
void leerArchivoCSV(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            string dato;
            size_t pos = 0;
            while ((pos = linea.find(",")) != string::npos) {
                
                dato = linea.substr(0, pos);
                cout << dato << " ";
                linea.erase(0, pos + 1);
                
            }
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo CSV." << endl;
    }
}
//estruct para almacenar los datos y ser manipulados con mayor facilidad
struct empleado // estructura de empleado
{
    string primerNombre, segundoNombre, primerApellido, segundoApellido, sexo;
    string fechaNacimiento, direccion, telefono, dui, cargo;
    double sueldo;
};
//metodo para ordenar los datos segun el parametro que pasemos y el nombre del archivo
void ordenarDatos(const string& nombreArchivo, const string& opcionOrdenamiento)
{
    //leer archivo csv y guardar en el struct
    ifstream archivo(nombreArchivo);//abrir archivo
    string linea;//guardar linea
    vector<empleado> empleados;//vector de empleados
    while (getline(archivo, linea))//leer linea por linea
    {
        empleado e;//crear empleado
        stringstream ss(linea);//convertir la linea en un stream
        getline(ss, e.primerNombre, ',');//obtener el primer nombre
        getline(ss, e.segundoNombre, ',');//
        getline(ss, e.primerApellido, ',');
        getline(ss, e.segundoApellido, ',');
        getline(ss, e.sexo, ',');
        getline(ss, e.fechaNacimiento, ',');
        getline(ss, e.direccion, ',');
        getline(ss, e.telefono, ',');
        getline(ss, e.dui, ',');
        getline(ss, e.cargo, ',');
        ss >> e.sueldo;
        empleados.push_back(e);//agregar el empleado al vector
    }
    archivo.close();
    //ordenar por sueldo
    if (opcionOrdenamiento == "sueldo") {
        // Ordenar por sueldo de menor a mayor
        sort(empleados.begin(), empleados.end(), [](const empleado& a, const empleado& b) {
            return a.sueldo < b.sueldo;
        });
    } else if (opcionOrdenamiento == "apellido") {
        // Ordenar por primer apellido alfabéticamente
        sort(empleados.begin(), empleados.end(), [](const empleado& a, const empleado& b) {
            return a.primerApellido < b.primerApellido;
        });
    }
    else 
    {
        cout << "Opción de ordenamiento inválida." << endl;
        return;
    }
    //escribir en el archivo
    ofstream archivo2(nombreArchivo);//abrir archivo
    for (auto e : empleados)//recorrer el vector
    {
        archivo2 << e.primerNombre << ",";//escribir en el archivo
        archivo2 << e.segundoNombre << ",";
        archivo2 << e.primerApellido << ",";
        archivo2 << e.segundoApellido << ",";
        archivo2 << e.sexo << ",";
        archivo2 << e.fechaNacimiento << ",";
        archivo2 << e.direccion << ",";
        archivo2 << e.telefono << ",";
        archivo2 << e.dui << ",";
        archivo2 << e.cargo << ",";
        archivo2 << e.sueldo << endl;
    }
    archivo2.close();
    
    cout << "Datos ordenados correctamente." << endl;
}
//metodo mostrar segun cargo ejercido en empresa
void mostrarPorTipo()
{  
    ifstream archivo("empleados.csv");//abrir archivo
    string linea;//guardar linea
    vector<empleado> empleados;//vector de empleados
    while (getline(archivo, linea))//leer linea por linea
    {
        empleado e;//crear empleado
        stringstream ss(linea);//convertir la linea en un stream
        getline(ss, e.primerNombre, ',');//obtener el primer nombre
        getline(ss, e.segundoNombre, ',');//
        getline(ss, e.primerApellido, ',');
        getline(ss, e.segundoApellido, ',');
        getline(ss, e.sexo, ',');
        getline(ss, e.fechaNacimiento, ',');
        getline(ss, e.direccion, ',');
        getline(ss, e.telefono, ',');
        getline(ss, e.dui, ',');
        getline(ss, e.cargo, ',');
        ss >> e.sueldo;
        empleados.push_back(e);//agregar el empleado al vector
    }
    archivo.close();
    int cargo=0;
    string cargobuscado;
    cout << "Digite la opcion de los empleados que desea ver:" << endl;
    cout << "1. Gerente" << endl;
    cout << "2. Tecnico" << endl;
    cout << "3. Jefe de area" << endl;
    cout << "4. Supervisor" << endl;
    cin >> cargo;
//asignamos la variables cargo con un numero que corresponda para facilitar la eleccion del comparativo que buscamos
    switch (cargo)
    {
    case 1:
        cargobuscado = "Gerente";
        break;
    case 2:
        cargobuscado = "Tecnico";
        break;
    case 3:
        cargobuscado = "Jefe de area";
        break;
    case 4:
        cargobuscado = "Supervisor";
        break;
    default:
        break;
    }
    // recorreremos el vector completo y lo mostramos en pantalla solo si cumple los requisitos
    for (auto e : empleados)          
    {
        if (e.cargo == cargobuscado)
        {
            cout << e.primerNombre << " ,";
            cout << e.segundoNombre << " ,";
            cout << e.primerApellido << ",";
            cout << e.segundoApellido << ",";
            cout << e.sexo << ",";
            cout << e.fechaNacimiento << ",";
            cout << e.direccion << ",";
            cout << e.telefono << ",";
            cout << e.dui << ",";
            cout << e.cargo << ",";
            cout << e.sueldo << endl;
        }
    }
    
};

void ingresarDatos(){

    string primerNombre,segundoNombre,primerApellido,segundoApellido,fecha_Nacimiento,direccion;
    char sexo='n';
    int telefono=0,dui=0;
    int opcion=1;
    //hacemos la instanciacion de las clases para usarlas en este metodo
    Empleados *empleadoGerente=new Gerentes(); 
    Empleados *empleadoTecnico=new Tecnicos();
    Empleados *empleadoJefeArea=new JefeAreas();
    Empleados *empleadoSupervisor=new Supervisor();

        while (opcion!=0)
        {
              //Repetir cada ingreso y elegir que tipo es
            cout<<"INGRESE LOS DATOS A CONTINUACION ELIJA EL TIPO DE EMPLEADO"<<endl;
            cout<<"Primer nombre: \n";
            fflush(stdin);
            getline(cin, primerNombre);
            cout << "Segundo nombre:\n";
            fflush(stdin);
            getline(cin, segundoNombre);
            cout << "Primer apellido:\n";
            fflush(stdin);
            getline(cin, primerApellido);
            cout << "Segundo apellido:\n";
            fflush(stdin);
            getline(cin, segundoApellido);
            cout << "Sexo:\n";
            cin >> sexo;
            cout << "Fecha de nacimiento:\n";
            fflush(stdin);
            getline(cin, fecha_Nacimiento);
            cout << "Direccion:\n";
            fflush(stdin);
            getline(cin, direccion);
            cout << "Telefono:\n";
            cin >> telefono;
            cout << "DUI:\n";
            cin >> dui;
        //Mostramos un menu al usuario para que elija el tipo de empleado que es
            cout <<"SELECCIONE TIPO DE EMPLEADO A GUARDAR: "<<endl;
            cout <<"1. Gerente"<<endl;
            cout <<"2. Tecnico"<<endl;
            cout <<"3. Jefe de area"<<endl;
            cout <<"4. Supervisor"<<endl;
            cout <<"0. Para salir"<<endl;
            cin>>opcion;

            switch (opcion)
            {
            case 1:
                //Guardamos los datos del empleado segun su categoria
                empleadoGerente->setPrimerNombre(primerNombre);
                empleadoGerente->setSegundoNombre(segundoNombre);
                empleadoGerente->setPrimerApellido(primerApellido);
                empleadoGerente->setSegundoApellido(segundoApellido);
                empleadoGerente->setSexo(sexo);
                empleadoGerente->setFecha_Nacimiento(fecha_Nacimiento);
                empleadoGerente->setDireccion(direccion);
                empleadoGerente->setTelefono(telefono);
                empleadoGerente->setDui(dui);
                escribirEnArchivoCSV(empleadoGerente, "empleados.csv");
                cout<<"Datos ingresados correctamente"<<endl;
                //Mostramos al usuario todos los datos ingresados.
                leerArchivoCSV("empleados.csv");  
                //Terminamos la ejecucion del bucle para salir.
                opcion=0;         
                break;
            case 2:
                
                empleadoTecnico->setPrimerNombre(primerNombre);
                empleadoTecnico->setSegundoNombre(segundoNombre);
                empleadoTecnico->setPrimerApellido(primerApellido);
                empleadoTecnico->setSegundoApellido(segundoApellido);
                empleadoTecnico->setSexo(sexo);
                empleadoTecnico->setFecha_Nacimiento(fecha_Nacimiento);
                empleadoTecnico->setDireccion(direccion);
                empleadoTecnico->setTelefono(telefono);
                empleadoTecnico->setDui(dui);
                escribirEnArchivoCSV(empleadoTecnico, "empleados.csv");
                cout<<"Datos ingresados correctamente"<<endl;
                leerArchivoCSV("empleados.csv"); 
                opcion=0;       
                break;
            case 3:
                empleadoJefeArea->setPrimerNombre(primerNombre);
                empleadoJefeArea->setSegundoNombre(segundoNombre);
                empleadoJefeArea->setPrimerApellido(primerApellido);
                empleadoJefeArea->setSegundoApellido(segundoApellido);
                empleadoJefeArea->setSexo(sexo);
                empleadoJefeArea->setFecha_Nacimiento(fecha_Nacimiento);
                empleadoJefeArea->setDireccion(direccion);
                empleadoJefeArea->setTelefono(telefono);
                empleadoJefeArea->setDui(dui);
                escribirEnArchivoCSV(empleadoJefeArea, "empleados.csv");
                cout<<"Datos ingresados correctamente"<<endl;
                leerArchivoCSV("empleados.csv"); 
                opcion=0;       
                break;         
            case 4:
                empleadoSupervisor->setPrimerNombre(primerNombre);
                empleadoSupervisor->setSegundoNombre(segundoNombre);
                empleadoSupervisor->setPrimerApellido(primerApellido);
                empleadoSupervisor->setSegundoApellido(segundoApellido);
                empleadoSupervisor->setSexo(sexo);
                empleadoSupervisor->setFecha_Nacimiento(fecha_Nacimiento);
                empleadoSupervisor->setDireccion(direccion);
                empleadoSupervisor->setTelefono(telefono);
                empleadoSupervisor->setDui(dui);
                escribirEnArchivoCSV(empleadoSupervisor, "empleados.csv");
                cout<<"Datos ingresados correctamente"<<endl;
                leerArchivoCSV("empleados.csv"); 
                opcion=0;       
                break;        
            default:
            system("close");
                break;
            };
        };

};

int main(){
    //variables de los datos para pasar en tiempo de ejecucion

    
    int opcion =1;
    while (opcion!=0)
    {
        cout<<"Bienvenido al sistema de talleres el rafa irvin y melvin"<<endl;
        cout<<"A continuacion elija una opcion del menu"<<endl;
        cout<<"1- Ordenar alfabeticamente por primer apellido"<<endl;
        cout<<"2- Ordenar empleados por el sueldo con descuentos incluidos"<<endl;
        cout<<"3- Mostrar cantidad empleados segun cargo"<<endl;
        cout<<"4- Agregar nuevo empleado por categoria"<<endl;
        cout<<"0- Para salir de la ejecucion"<<endl;
        cin>> opcion;

        switch (opcion)
        {
            case 1:
                ordenarDatos("empleados.csv","apellido");
                leerArchivoCSV("empleados.csv");
                break;
            case 2:
                ordenarDatos("empleados.csv","sueldo");
                leerArchivoCSV("empleados.csv");
                break;       
            case 3:
                mostrarPorTipo();
                break;
            case 4:
                ingresarDatos();
                break;  
            default:
                break;
        }
    }
}   