#include "RegistroPersonal.h"

#define MAX_REG 100

void obtenerDatos (char*, double &, char*, char*, char*);

void registrarMed (fstream &arch, ofstream &archError, double sueldo,
        char *nombre, char* apellido, char* especialidad);

void inicializar (fstream &arch)
{
    arch.open("RegistroPersonal.dat",ios::in | ios::out | ios::binary);

    if (!arch){
        /*Si el archivo no existe, creo uno con 100 reg vacios*/
        cout << "Archivo no existe. Se creará.\n";
        arch.open("RegistroPersonal.dat",ios::in | ios::out | ios::binary);
        Medico med (0); //Registro vacío
        for (int i = 0; i < MAX_REG; i++)
            arch.write(reinterpret_cast <const char* > (&med), sizeof(med));
    } else
        cout << "Archivo existe. Abierto existosamente.\n";
    
    //Se coloca el cursor al inicio para empezar a grabar datos
    arch.seekg(0,ios::beg);
}

void cargarMedicos (fstream &arch)
{
    //Archivo de mensajes de errores
    ofstream archError ("Carga.log", ios::out);
    
    if (!archError){
        cerr << "Hubo un error al crear el archivo Carga.log\n";
        exit(1);
    }
    
    //Archivo de entrada
    ifstream archEntrada ("Medicos.csv", ios::in);
    
    if (!archEntrada){
        cerr << "Hubo un error al abrir el archivo Medicos.csv\n";
        exit(1);
    }
    
    char buff[200];
    double sueldo;
    char nombre[21], apellido[21], especialidad[21];
    
    while (archEntrada.getline(buff,200)){
        obtenerDatos(buff,sueldo, nombre, apellido, especialidad);
        registrarMed(arch, archError, sueldo, nombre, apellido, especialidad);
    }
}

void listar (fstream &arch)
{
    //Se coloca el cursor al inicio para leer todo
    arch.seekg(0, ios::beg);
    
    Medico med(0);
    while (1){
        arch.read(reinterpret_cast <char *> (&med), sizeof(med));
        if (med.GetCodigo() == 0) break;
        med.imprime();
    }
    cout << "<FIN>\n" ;
}

//Privates

void obtenerDatos (char* buff, double &sueldo, char* nombre, 
                   char* apellido, char* especialidad)
{
    char* palabras[5];
    int cantPal = 0;
    palabras[0] = buff; //Esto marca el codigo, no importa, yo genero el codigo
    cantPal++;
    for (int i = 1; buff[i]; i++) {
        if (buff[i] == ','){
            buff[i] == 0;
            palabras[cantPal] = &(buff[i+1]);
            cantPal++;
        }
    }
    
    strcpy(apellido, palabras[1]);
    strcpy(nombre, palabras[2]);
    strcpy(especialidad, palabras[3]);
    sueldo = atof(palabras[4]);
}

void registrarMed (fstream &arch, ofstream &archError, double sueldo,
        char *nombre, char* apellido, char* especialidad)
{
    static int codigo = 1;
    Medico med (codigo);
    
    med.SetApellido(apellido);
    med.SetEspecialidad(especialidad);
    med.SetNombre(nombre);
    med.SetSueldo(sueldo);
    
    //Lee el registro cargado anteriormente y revisar si su codig no se
    //repite con el que se va a registrar
    if (codigo > 1) {
        Medico aux(0);
        int cursor = arch.tellg() - sizeof(med); //Se coloca el cursor un registro anterior
        arch.seekg(cursor, ios::beg);
        arch.read(reinterpret_cast <char *> (&aux), sizeof(aux));
        //Si el nuevo codigo es menor o igual al registro anterior, se produce un error
        if (med.GetCodigo() <= aux.GetCodigo())
            archError << "Hubo un problema al generar un codigo nuevo.\n";
    }
    arch.write(reinterpret_cast <const char*> (&med), sizeof(med));
    codigo++;
}