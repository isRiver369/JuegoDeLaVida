#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

class Coso
{
private:
    // información Personal
    int id = 0;
    string nombre1, nombre2;
    string apellido1, apellido2;
    int edad = 0;
    bool trabajo; // true: trabaja, false: no trabaja
    int sueldo = 0;
    string sexo;
    int posX, posY;
    string estadoCivil;
    string tipoSangre;
    string factorRh;
    bool estado; // true: vivo, false: muerto
    int resistencia = 0;

    // familia
    int idPadre = 0;
    int idMadre = 0;
    int idPareja = 0;
    int idFamilia = 0;

    // combate
    int vida = 0;    // 50 - 70
    int ataque = 0;  // 30 - 75
    int defensa = 0; // 20 - 50
    int arma = 0;    // 5 - 10

public:
    // constructor con parámetros
    Coso(int i, string n1, string n2, string a1, string a2, int e, bool t,
         int s, string sx, int pX, int pY, string eC, string tS, string rH,
         bool est, int r, int iP, int iM, int iPar, int iF, int vid, int atc,
         int def, int arm) :

                             id(i), nombre1(n1), nombre2(n2), apellido1(a1), apellido2(a2),
                             edad(e), trabajo(t), sueldo(s), sexo(sx), posX(pX), posY(pY),
                             estadoCivil(eC), tipoSangre(tS), factorRh(rH), estado(est),
                             resistencia(r), idPadre(iP), idMadre(iM), idPareja(iPar),
                             idFamilia(iF), vida(vid), ataque(atc), defensa(def), arma(arm)
    {
    }

    // setters
    void setId(int i) { id = i; };
    void setNombre1(string n1) { nombre1 = n1; };
    void setNombre2(string n2) { nombre2 = n2; };
    void setApellido1(string a1) { apellido1 = a1; };
    void setApellido2(string a2) { apellido2 = a2; };
    void setEdad(int e) { edad = e; };
    void setTrabajo(bool t) { trabajo = t; };
    void setSueldo(int s) { sueldo = s; };
    void setSexo(string sX) { sexo = sX; };
    void setPosX(int pX) { posX = pX; };
    void setPosY(int pY) { posY = pY; };
    void setEstadoCivil(string eC) { estadoCivil = eC; };
    void setTipoSangre(string tS) { tipoSangre = tS; };
    void setFactorRh(string rH) { factorRh = rH; };
    void setEstado(bool est) { estado = est; };
    void setResistencia(int r) { resistencia = r; };

    void setIdPadre(int iP) { idPadre = iP; };
    void setIdMadre(int iM) { idMadre = iM; };
    void setIdPareja(int iPar) { idPareja = iPar; };
    void setIdFamilia(int iF) { idFamilia = iF; };

    void setVida(int vid) { vida = vid; };
    void setAtaque(int atc) { ataque = atc; };
    void setDefensa(int def) { defensa = def; };
    void setArma(int arm) { arma = arm; };

    // getters
    int getId() { return id; };
    string getNombre1() { return nombre1; };
    string getNombre2() { return nombre2; };
    string getApellido1() { return apellido1; };
    string getApellido2() { return apellido2; };
    int getEdad() { return edad; };
    bool getTrabajo() { return trabajo; };
    int getSueldo() { return sueldo; };
    string getSexo() { return sexo; };
    int getPosX() { return posX; };
    int getPosY() { return posY; };
    string getEstadoCivil() { return estadoCivil; };
    string getTipoSangre() { return tipoSangre; };
    string getFactorRh() { return factorRh; };
    bool getEstado() { return estado; };
    int getResistencia() { return resistencia; };

    int getIdPadre() { return idPadre; };
    int getIdMadre() { return idMadre; };
    int getIdPareja() { return idPareja; };
    int getIdFamilia() { return idFamilia; };

    int getVida() { return vida; };
    int getAtaque() { return ataque; };
    int getDefensa() { return defensa; };
    int getArma() { return arma; };
};

vector<string> lista_Sangre = {"O", "A", "B", "AB"};
vector<string> lista_factorRH = {"-", "+"};
vector<string> lista_sexo = {"Hembra", "Macho"};

vector<string> lista_Nombres_M;
vector<string> lista_Nombres_H;
vector<string> lista_Apellidos;

const int MAX_COSOS = 50;
int contadorTotalParejas = 0;
int contadorIDTotal = 1;
vector<Coso> cosos;

void archivoCSV(vector<string> *auxV, string aux)
{
    ifstream MyReadFile(aux);

    while (getline(MyReadFile, aux))
    {
        auxV->push_back(aux);
    }

    MyReadFile.close();
}

void carga()
{
    int posX;
    int posY;

    gotoxy(50, 12);
    cout << "[";
    gotoxy(71, 12);
    cout << "]";
    gotoxy(47, 13);
    cout << "Rivera Mosquera Israel Rivera";

    for (posX = 51; posX < 71; posX++)
    {
        gotoxy(posX, 12);
        cout << ".";
    }

    for (posX = 51; posX < 71; posX++)
    {
        Sleep(50);
        gotoxy(posX, 12);
        cout << "#";
    }
}

void posicionCosos()
{
    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstado() == true)
        {
            string cosoSexo = (cosos[i].getSexo() == "Hembra") ? "H" : "M";

            gotoxy(cosos[i].getPosX(), cosos[i].getPosY());
            cout << cosoSexo;
        }
    }
}

void mapa()
{
    int MAX_COLUMNA = 83;
    int MAX_FILA = 20;
    int cososVivosLogico = 0;

    for (int columna = 1; columna < MAX_COLUMNA; columna++)
    {
        gotoxy(columna, 0);
        cout << "-";
        gotoxy(columna, MAX_FILA);
        cout << "-";
    }

    for (int fila = 1; fila < MAX_FILA; fila++)
    {
        gotoxy(0, fila);
        cout << "|";
        gotoxy(MAX_COLUMNA, fila);
        cout << "|";
    }

    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstado() == true)
        {
            cososVivosLogico++;
        }
    }

    posicionCosos();
    gotoxy(0, 21);
    cout << "Total de cosos: " << cososVivosLogico;
    gotoxy(0, 22);
    cout << "Total de parejas: " << contadorTotalParejas;
}

void menu()
{
    system("cls");

    mapa();
    int posX = 85;
    int posY = 1;
    gotoxy(posX, posY++);
    cout << "JUEGO DE LA VIDA";
    gotoxy(posX, posY++);
    cout << "1. Creación de primer grupo";
    gotoxy(posX, posY++);
    cout << "2. Generar parejas";
    gotoxy(posX, posY++);
    cout << "3. Generar hijos";
    gotoxy(posX, posY++);
    cout << "4. Enfermedad covid";
    gotoxy(posX, posY++);
    cout << "5. Lucha del más fuerte";
    gotoxy(posX, posY++);
    cout << "6. Avance del tiempo";
    gotoxy(posX, posY++);
    cout << "7. Resucitar";
    gotoxy(posX, posY++);
    cout << "8. Ir al cine";
    gotoxy(posX, posY++);
    cout << "9. Identificación y reporte";
    gotoxy(posX, posY++);
    cout << "0. Salir";
    gotoxy(posX, posY++);
    cout << "Ingrese un opción: ";
}

void buscarCoso(vector<int> *totalVivos)
{
    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstado() == true)
        {
            totalVivos->push_back(i);
        }
    }
}

// PROCESO 1
void creacionPrimerGrupo()
{
    archivoCSV(&lista_Nombres_M, "nombresMacho.csv");
    archivoCSV(&lista_Nombres_H, "nombresHembra.csv");
    archivoCSV(&lista_Apellidos, "apellidos.csv");

    for (int i = 0; i < MAX_COSOS; i++)
    {
        int auxTrabajo = rand() % 2;

        int id = contadorIDTotal;
        string sexo = lista_sexo[rand() % lista_sexo.size()];
        string nombre1 = (sexo == "Hembra") ? lista_Nombres_H[rand() % lista_Nombres_H.size()] : lista_Nombres_M[rand() % lista_Nombres_M.size()];
        string nombre2 = (sexo == "Hembra") ? lista_Nombres_H[rand() % lista_Nombres_H.size()] : lista_Nombres_M[rand() % lista_Nombres_M.size()];
        string apellido1 = lista_Apellidos[rand() % 100];
        string apellido2 = lista_Apellidos[rand() % 100];
        int edad = 18 + rand() % 23;
        bool trabajo = (auxTrabajo == 1) ? true : false;
        int sueldo = (trabajo == true) ? 450 + rand() % 551 : 0;
        int posX = 1 + rand() % 81;
        int posY = 1 + rand() % 19;
        string estadoCivil = "Soltero";
        string tipoSangre = lista_Sangre[rand() % lista_Sangre.size()];
        string factorRh = lista_factorRH[rand() % lista_factorRH.size()];
        bool estado = true;
        int resistencia = 0;
        int idPadre = 0;
        int idMadre = 0;
        int idPareja = 0;
        int idFamilia = 0;
        int vida = 50 + rand() % 21;
        int ataque = 30 + rand() % 46;
        int defensa = 20 + rand() % 31;
        int arma = 5 + rand() % 6;

        contadorIDTotal++;

        Coso nuevo(id, nombre1, nombre2, apellido1, apellido2, edad, trabajo, sueldo, sexo, posX, posY,
                   estadoCivil, tipoSangre, factorRh, estado, resistencia, idPadre, idMadre, idPareja,
                   idFamilia, vida, ataque, defensa, arma);

        cosos.push_back(nuevo);
    }

    gotoxy(85, 14);
    cout << "+ " << MAX_COSOS << " cosos";
    gotoxy(85, 15);
    system("pause");
}

// PROCESO 2
void generarParejas()
{
    system("cls");
    int Macho;
    int Hembra;
    int posX = 0;
    int posY = 2;
    int contadorNuevasParejas = 0;

    int contadorMachos = 0;
    int contadorHembras = 0;
    // BUSCAR COSOS SOLTEROS
    vector<int> cososSolterosHembras;
    vector<int> cososSolterosMachos;
    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstadoCivil() == "Soltero" &&
            cosos[i].getEdad() > 17 &&
            cosos[i].getEstado() == true &&
            cosos[i].getSexo() == "Hembra")
        {
            cososSolterosHembras.push_back(i);
        }

        if (cosos[i].getEstadoCivil() == "Soltero" &&
            cosos[i].getEdad() > 17 &&
            cosos[i].getEstado() == true &&
            cosos[i].getSexo() == "Macho" &&
            cosos[i].getTrabajo() == true)
        {
            cososSolterosMachos.push_back(i);
        }
    }

    for (int i = 0; i < cososSolterosMachos.size(); i++)
    {
        Macho = cososSolterosMachos[i];

        for (int j = 0; j < cososSolterosHembras.size(); j++)
        {
            Hembra = cososSolterosHembras[j];

            if (cosos[Hembra].getEstadoCivil() == "Soltero" &&
                cosos[Macho].getEdad() > cosos[Hembra].getEdad() &&
                cosos[Macho].getSueldo() > cosos[Hembra].getSueldo())
            {
                contadorNuevasParejas++;
                contadorTotalParejas++;

                cosos[Macho].setEstadoCivil("Emparejado");
                cosos[Hembra].setEstadoCivil("Emparejado");

                cosos[Macho].setIdPareja(contadorTotalParejas);
                cosos[Hembra].setIdPareja(contadorTotalParejas);

                cout << cosos[Macho].getId() << " <3 " << cosos[Hembra].getId() << endl;
                break;
            }
        }
    }

    cout << "Nuevas parejas: " << contadorNuevasParejas << endl;
    system("pause");
}

// PROCESO 3 - PENDIENTE
void generarHijos()
{
    system("cls");
    int contador = 0;
    int Macho = 0;
    int Hembra = 0;

    // BUSCAR COSOS EMPAREJADOS
    vector<int> cososEmparejadosHembras;
    vector<int> cososEmparejadosMachos;

    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstadoCivil() == "Emparejado" &&
            cosos[i].getEstado() == true &&
            cosos[i].getSexo() == "Hembra")
        {
            cososEmparejadosHembras.push_back(i);
        }

        if (cosos[i].getEstadoCivil() == "Emparejado" &&
            cosos[i].getEstado() == true &&
            cosos[i].getSexo() == "Macho")
        {
            cososEmparejadosMachos.push_back(i);
        }
    }

    for (int i = 0; i < cososEmparejadosMachos.size(); i++)
    {
        Macho = cososEmparejadosMachos[i];

        for (int j = 0; j < cososEmparejadosHembras.size(); j++)
        {
            Hembra = cososEmparejadosHembras[j];

            if (cosos[Macho].getIdPareja() == cosos[Hembra].getIdPareja() &&
                cosos[Macho].getFactorRh() == cosos[Hembra].getFactorRh() &&
                cosos[Macho].getSueldo() > cosos[Hembra].getSueldo())
            {
                // NUEVO COSO
                int auxTrabajo = rand() % 2;

                int id = contadorIDTotal;
                string sexo = lista_sexo[rand() % lista_sexo.size()];
                string nombre1 = (sexo == "Hembra") ? cosos[Hembra].getNombre1() : cosos[Macho].getNombre1();
                string nombre2 = (sexo == "Hembra") ? cosos[Hembra].getNombre2() : cosos[Macho].getNombre2();
                string apellido1 = cosos[Macho].getApellido1();
                string apellido2 = cosos[Hembra].getApellido2();
                int edad = 0;
                bool trabajo = (auxTrabajo == 1) ? true : false;
                int sueldo = (trabajo == true) ? 450 + rand() % 551 : 0;
                int posX = 1 + rand() % 81;
                int posY = 1 + rand() % 19;
                string estadoCivil = "Soltero";
                string tipoSangre = lista_Sangre[rand() % lista_Sangre.size()];
                string factorRh = lista_factorRH[rand() % lista_factorRH.size()];
                bool estado = true;
                int resistencia = 0;
                int idPadre = cosos[Macho].getId();
                int idMadre = cosos[Hembra].getId();
                int idPareja = 0;
                int idFamilia = cosos[Hembra].getIdPareja();
                int vida = 50 + rand() % 21;
                int ataque = 30 + rand() % 46;
                int defensa = 20 + rand() % 31;
                int arma = 5 + rand() % 6;

                // ID FAMILIA
                cosos[Hembra].setIdFamilia(cosos[Hembra].getIdPareja());
                cosos[Macho].setIdFamilia(cosos[Hembra].getIdPareja());

                Coso nuevo(id, nombre1, nombre2, apellido1, apellido2, edad, trabajo, sueldo, sexo, posX, posY,
                           estadoCivil, tipoSangre, factorRh, estado, resistencia, idPadre, idMadre, idPareja,
                           idFamilia, vida, ataque, defensa, arma);

                cosos.push_back(nuevo);

                cout << cosos[Macho].getId() << " y " << cosos[Hembra].getId()
                     << " tuvieron un bebé!" << endl;

                contadorIDTotal++;
                break;
            }
        }
    }

    system("pause");
}

// PROCESO 4
void enfermedadCovid()
{
    int posX = 85;
    int posY = 14;
    int porcentajeIngresado = 0;
    int infectadosPoblacion = 0;
    int contadorMuertos = 0;
    int contadorVivos = 0;

    // RANDOM NO REPETIR
    vector<int> idInfectados;
    vector<int> totalVivos;
    int auxIdCosos = 0;
    bool repetido = false;

    do
    {
        system("cls");
        menu();

        posX = 85;
        posY = 14;

        gotoxy(posX, posY++);
        cout << "Ingrese porcentaje de";
        gotoxy(posX, posY++);
        cout << "población a infectar: ";
        cin >> porcentajeIngresado;

        if (porcentajeIngresado > 100 || porcentajeIngresado < 0)
        {
            gotoxy(posX, posY++);
            cout << "Opcion no valida";
            gotoxy(posX, posY++);
            cout << system("pause");
        }
    } while (porcentajeIngresado > 100 || porcentajeIngresado < 0);

    // COSOS VIVOS(ESTADO: TRUE)
    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstado() == true)
        {
            totalVivos.push_back(cosos[i].getId());
            contadorVivos++;
        }
    }

    infectadosPoblacion = (porcentajeIngresado * contadorVivos) / 100;

    // RANDOM NO REPETIR
    for (int i = 0; i < infectadosPoblacion; i++)
    {
        do
        {
            repetido = false;
            auxIdCosos = totalVivos[rand() % totalVivos.size()];

            for (int j = 0; j < i; j++)
            {
                if (auxIdCosos == idInfectados[j])
                {
                    repetido = true;
                    break;
                }
            }
        } while (repetido == true);

        idInfectados.push_back(auxIdCosos);
    }

    for (int i = 0; i < infectadosPoblacion; i++)
    {
        if (cosos[idInfectados[i]].getEstado() == true &&
            cosos[idInfectados[i]].getEdad() >= 40 &&
            cosos[idInfectados[i]].getSexo() == "Macho" &&
            cosos[idInfectados[i]].getEstadoCivil() == "Soltero")
        {
            cosos[idInfectados[i]].setEstado(false);
            contadorMuertos++;
        }
    }

    gotoxy(posX, posY++);
    cout << "Infectados: " << infectadosPoblacion;
    gotoxy(posX, posY++);
    cout << "Fallecidos: " << contadorMuertos;
    gotoxy(posX, posY++);
    system("pause");
}

// AUX LUCHA DEL MÁS FUERTE
void presentarLuchadores(int posX, int posY, int luchador)
{
    gotoxy(posX, posY++);
    cout << "ID: " << cosos[luchador].getId();
    gotoxy(posX, posY++);
    cout << "Nombre: " << cosos[luchador].getNombre1() << " " << cosos[luchador].getNombre2();
    gotoxy(posX, posY++);
    cout << "Apellidos: " << cosos[luchador].getApellido1() << " " << cosos[luchador].getApellido2();

    posY++;

    gotoxy(posX, posY++);
    cout << "Vida: " << cosos[luchador].getVida();
    gotoxy(posX, posY++);
    cout << "Defensa: " << cosos[luchador].getDefensa();
    gotoxy(posX, posY++);
    cout << "Ataque: " << cosos[luchador].getAtaque();
    gotoxy(posX, posY++);
    cout << "Arma: " << cosos[luchador].getArma();

    posY++;

    gotoxy(posX, posY++);
    cout << "Vida total inicial (vida + defensa): " << cosos[luchador].getVida() + cosos[luchador].getDefensa();
    gotoxy(posX, posY++);
    cout << "Ataque total inical (ataque + arma): " << cosos[luchador].getAtaque() + cosos[luchador].getArma();
}

void laLucha(int atacante, int atacado)
{
    int ataqueTotal = 0;
    int vidaTotal = 0;
    int nuevaVida = 0;

    ataqueTotal = cosos[atacante].getAtaque() + cosos[atacante].getArma();
    vidaTotal = cosos[atacado].getVida() + cosos[atacado].getDefensa();
    nuevaVida = vidaTotal - ataqueTotal;
    cosos[atacado].setVida(nuevaVida);

    cout << cosos[atacante].getNombre1() << " causa " << ataqueTotal << " de daño\n"
         << cosos[atacado].getNombre1() << " vida disminuya a " << nuevaVida << endl;
}

void finDeLucha(int ganador, int perdedor)
{
    cout << cosos[ganador].getNombre1() << " gana!\n"
         << cosos[perdedor].getNombre1() << " ha muerto!\n";

    cosos[ganador].setResistencia(+1);
    cosos[perdedor].setEstado(false);
}

// PROCESO 5
void luchaDelMasFuerte()
{
    system("cls");
    cout << "Lucha del más fuerte!\n";

    int luchador1 = 0;
    int luchador2 = 0;
    int auxIdCosos = 0;
    bool repetido;

    // BUSCAR Y ALMACENAR COSOS VIVOS
    vector<int> totalVivos;
    buscarCoso(&totalVivos);

    // DEFINIR LUCHADORES
    luchador1 = totalVivos[rand() % totalVivos.size()];

    do
    {
        repetido = false;
        luchador2 = totalVivos[rand() % totalVivos.size()];

        if (luchador2 == luchador1)
        {
            repetido = true;
        }
    } while (repetido == true);

    // PRESENTAR LUCHADORES
    presentarLuchadores(0, 2, luchador1);
    presentarLuchadores(60, 2, luchador2);

    // LUCHA
    int turno = 1;
    cout << endl
         << endl;

    do
    {
        if (turno % 2 == 0)
        {
            laLucha(luchador1, luchador2);
        }
        else
        {
            laLucha(luchador2, luchador1);
        }

        turno++;
    } while (cosos[luchador1].getVida() > 0 && cosos[luchador2].getVida() > 0);

    cout << "\nFin de la lucha!\n";

    if (cosos[luchador1].getVida() > 0)
    {
        finDeLucha(luchador1, luchador2);
    }

    if (cosos[luchador2].getVida() > 0)
    {
        finDeLucha(luchador2, luchador1);
    }

    system("pause");
}

// PROCESO 6
void avanceTiempo()
{
    int posX = 85;
    int posY = 14;
    const int avanceAnios = 5;
    int contadorMuertos = 0;

    for (int i = 0; i < cosos.size(); i++)
    {
        int nuevaEdad = cosos[i].getEdad();
        nuevaEdad += avanceAnios;
        cosos[i].setEdad(nuevaEdad);

        if ((cosos[i].getEdad() >= 70 && cosos[i].getSexo() == "Macho") ||
            (cosos[i].getEdad() >= 85 && cosos[i].getSexo() == "Hembra"))
        {
            cosos.erase(cosos.begin() + i);
            contadorMuertos++;
        }
    }

    gotoxy(posX, posY++);
    cout << "+" << avanceAnios << " años";
    gotoxy(posX, posY++);
    cout << "Muertos: " << contadorMuertos;
    gotoxy(posX, posY++);
    system("pause");
}

// PROCESO 7
void resucitar()
{
    int contadorResucitados = 0;

    // BUSCAR COSOS MUERTOS
    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstado() == false)
        {
            cosos[i].setVida(50 + rand() % 21);
            cosos[i].setEstado(true);
            contadorResucitados++;
        }
    }

    gotoxy(85, 14);
    cout << "+" << contadorResucitados << " resucitados";
    gotoxy(85, 15);
    system("pause");
}

// PROCESO 8

void irAlCine()
{
    system("cls");
    int posX = 0;
    int posY = 0;
    bool repetido = false;

    gotoxy(27, 0);
    cout << "P A N T A L L A";

    // BUSCAR COSOS CON FAMILIA
    vector<int> idDeFamilias;
    vector<int> noRepetido;

    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getIdFamilia() > 0)
        {
            idDeFamilias.push_back(cosos[i].getIdFamilia());
        }
    }

    // ID FAMILIAR SIN REPETIR
    for (int i = 0; i < idDeFamilias.size(); i++)
    {
        repetido = false;
        int aux = idDeFamilias[i];

        for (int j = 0; j < noRepetido.size(); j++)
        {
            if (aux == noRepetido[j])
            {
                repetido = true;
                break;
            }
        }

        if (repetido == true)
        {
            continue;
        }

        noRepetido.push_back(aux);
    }

    // COSOS EN EL CINE
    posX = 25;
    posY = 6;

    for (int i = 0; i < noRepetido.size(); i++)
    {
        for (int j = 0; j < cosos.size(); j++)
        {
            if (cosos[j].getIdFamilia() == noRepetido[i])
            {
                gotoxy(posX += 2, posY);
                string cosoSexo = (cosos[j].getSexo() == "Hembra") ? "H" : "M";
                cout << cosoSexo;

                if (posX == 41)
                {
                    posX = 25;
                    posY++;
                }
            }
        }
    }

    // LISTA DE COSOS
    gotoxy(70, 0);
    cout << "ID(ID familiar)";
    gotoxy(70, 1);
    cout << "Orden de asientos: siguen el mismo orden de lista";
    gotoxy(70, 2);
    cout << "presentada.";
    gotoxy(70, 3);
    cout << "De izquierda a derecha y lueg baja para recorrer";
    gotoxy(70, 4);
    cout << "el mismo camino.";

    posY = 5;
    posX = 70;

    for (int i = 0; i < noRepetido.size(); i++)
    {
        for (int j = 0; j < cosos.size(); j++)
        {
            if (cosos[j].getIdFamilia() == noRepetido[i])
            {
                posY++;
                gotoxy(posX, posY);
                cout << cosos[j].getId();
                gotoxy(posX + 4, posY);
                cout << "(" << cosos[j].getIdFamilia() << ")";

                if (posY == 12)
                {
                    posX += 10;
                    posY = 5;
                }
            }
        }
    }

    gotoxy(0, 29);
    system("pause");
}

// AUX REPORTE
void listaCosos(int posX, int posY, bool estado)
{
    for (int i = 0; i < cosos.size(); i++)
    {
        if (cosos[i].getEstado() == estado)
        {
            gotoxy(posX, posY++);
            cout << cosos[i].getId();

            if (posY == 12)
            {
                posY = 2;
                posX += 5;
            }
        }
    }
}

// PROCESO 9
void reporte()
{
    char opcion;

    do
    {
        int id = 0;
        int auxId = 0;

        system("cls");
        cout << "Lista de cosos por ID\n"
             << "Cosos vivos";
        listaCosos(0, 2, true);

        gotoxy(65, 1);
        cout << "Cosos muertos (no por edad)";
        listaCosos(65, 2, false);

        // BUSCAR ID
        gotoxy(0, 13);
        bool idEncontrado = false;

        do
        {
            cout << "Ingrese ID de un coso para mayor información: ";
            cin >> id;

            for (int i = 0; i < cosos.size(); i++)
            {
                if (id == cosos[i].getId())
                {
                    auxId = i;
                    idEncontrado = true;
                    break;
                }
            }

            if (idEncontrado == false)
            {
                cout << "Opcion no válida\n";
            }
        } while (idEncontrado != true);

        // MOSTRAR INFORMACIÓN
        string auxTrabajo = (cosos[auxId].getTrabajo() == true) ? "Si" : "No";
        string auxEstado = (cosos[auxId].getEstado() == true) ? "Vivo" : "Muerto";

        system("cls");
        cout << "ID: " << cosos[auxId].getId()
             << "\nNombres: " << cosos[auxId].getNombre1() << " " << cosos[id].getNombre2()
             << "\nApellidos: " << cosos[auxId].getApellido1() << " " << cosos[id].getApellido2()
             << "\nEdad: " << cosos[auxId].getEdad()
             << "\nTrabajo: " << auxTrabajo
             << "\nSueldo: " << cosos[auxId].getSueldo()
             << "\nSexo: " << cosos[auxId].getSexo()
             << "\nPosición X & Y: " << "(" << cosos[id - 1].getPosX() << ", " << cosos[id].getPosY() << ")"
             << "\nEstado Civil: " << cosos[auxId].getEstadoCivil()
             << "\nTipo de sangre: " << cosos[auxId].getTipoSangre() << cosos[auxId].getFactorRh()
             << "\nResistencia: " << cosos[auxId].getResistencia()
             << "\nEstado: " << auxEstado << endl

             << "\nID Padre: " << cosos[auxId].getIdPadre()
             << "\nID Madre: " << cosos[auxId].getIdMadre()
             << "\nID Pareja: " << cosos[auxId].getIdPareja()
             << "\nID Familliar: " << cosos[auxId].getIdFamilia() << endl

             << "\nVida: " << cosos[auxId].getVida()
             << "\nAtaque: " << cosos[auxId].getAtaque()
             << "\nDefensa: " << cosos[auxId].getDefensa()
             << "\nArma: " << cosos[auxId].getArma() << endl;

        do
        {
            cout << "\nDesea buscar otro coso?(s/n): ";
            cin >> opcion;

            if (opcion != 's' && opcion != 'n')
            {
                cout << "Opción no válida\n";
            }
        } while (opcion != 's' && opcion != 'n');

    } while (opcion != 'n');
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    srand(time(NULL));
    SetConsoleOutputCP(65001);

    int opcion;
    char salir;

    // carga();
    SetConsoleTextAttribute(hConsole, 7);

    do
    {
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            creacionPrimerGrupo();
            break;

        case 2:
            generarParejas();
            break;

        case 3:
            generarHijos();
            break;

        case 4:
            enfermedadCovid();
            break;

        case 5:
            luchaDelMasFuerte();
            break;

        case 6:
            avanceTiempo();
            break;

        case 7:
            resucitar();
            break;

        case 8:
            irAlCine();
            break;

        case 9:
            reporte();
            break;

        case 0:
            gotoxy(85, 14);
            cout << "Fin del programa";
            gotoxy(85, 15);
            cout << "Presione cualquier tecla para salir";
            break;
        }
    } while (opcion != 0);

    gotoxy(0, 23);
    SetConsoleTextAttribute(hConsole, 0);

    return 0;
}
