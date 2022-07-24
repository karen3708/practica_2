#include<iostream>
using namespace std;

char ** crearMatrizCine();
bool disponibilidadAsiento(int fila, int columna, char **matriz);
void reservaCancelaAsientoCine(int fila,int columna,char **matriz);
int filaLetra2Numero(char );
void determinarmatrizmagica(int ,int **);
void llenarmatriz(int , int ** );
void imprimirmatriz(int,int , int **);
void imprimirMatrizChar(char ** );
unsigned long long int factorial(int );
int tamanodearreglochar(char *);


int main(){
    int problema=1;
    while(problema!=0){


        cout<<"\nSolucion de practica de laboratorio N2 de Informatica "
              "2\n*******************************************************************************\n";
        cout<<"\nIngrese nuemero del ejercicio que quiera resolver:"
              "\n11: Simulador de asientos de sala cine"
              "\n12:Programa que determina un cuadrado magico"
              "\n16: Programa que determinar cuantos caminos posibles hay"
              "\n\nSi requiere salir del programa ingrese el numero cero:\n";

        cin>>problema;

        switch(problema){


            case 11:{
            char ** matriz=crearMatrizCine();
            bool continuar=true;char yesNo;
            int columna;char fila;
            imprimirMatrizChar(matriz);
            while(continuar){

                cout<< "Ingrese la fila (A-O): ";
                cin>>fila;
                cout<< "\nIngrese el asiento (1-30): ";
                cin>>columna;
                reservaCancelaAsientoCine(filaLetra2Numero(fila),columna,matriz);
                imprimirMatrizChar(matriz);
                cout<< "Desea continuar con el simulador? y/n: ";
                cin>>yesNo;
                if(yesNo=='n' || yesNo=='N')continuar=false;
            }
            break;
        }
        case 12:{
            cout<<"\nIngrese el tamano del cuadro magico (NxN): ";
            int dimensionmatriz;
            int **matriz;

            cin>>dimensionmatriz;
            matriz=new int*[dimensionmatriz];
            llenarmatriz(dimensionmatriz,matriz);
            determinarmatrizmagica(dimensionmatriz,matriz);
            delete []matriz;
            break;
        }
            case 16:{
            cout<<"\nIngrese el tamano de la matriz a determinar el numero de caminos: ";
            int tamanomatriz;
            unsigned long long int ncaminos=0,nx2=0,n2=0;
            cin>>tamanomatriz;
            nx2=factorial(tamanomatriz*2);
            n2=factorial(tamanomatriz);
            ncaminos=nx2/(n2*n2);
            cout<<"\n"<<ncaminos<<"\n";
            break;
        }
        default:{
            cout<<"\n El numero ingresado no corresponde al \n grupo de problemas que se asignaron para resolver\n";
            problema=0;
            break;
        }
        }
        system("pause");
        system("CLS");

    }
    return 0;
}

void imprimirCadena(char *cadena){
       for(int i=0;i<tamanodearreglochar(cadena);i++){
           cout<< *(cadena+i);
    }
}
//**************************************************
//********************** funciones para el problema 11**************
void reservaCancelaAsientoCine(int fila,int columna,char **matriz){
    int opcion=0;
    cout<<"\n1. Reservar\n2. Cancelar\nIngrese la opcion deseada:";
    cin>>opcion;
    switch (opcion) {
    case 1:{
        if(disponibilidadAsiento(fila,columna,matriz)){
            *(*(matriz+fila)+columna-1)='+';
            cout<<"\nReserva exitosa!!!"<<endl;
        }
        else{
            cout<<"\nLa ubicacion ya esta reservada!!!"<<endl;
        }
        break;
    }
    case 2:{
        if(!disponibilidadAsiento(fila,columna,matriz)){
            *(*(matriz+fila)+columna-1)='-';
            cout<<"\nCancelacion exitosa!!!"<<endl;
        }
        else{
            cout<<"\nLa ubicacion no esta reservada!!!"<<endl;
        }
        break;
    }
    default:{
        cout<<"\nLa opcion ingresada no es valida"<<endl;
        break;
    }
    }

}
bool disponibilidadAsiento(int fila, int columna, char **matriz){
    bool esDisponible = false;
    if(*(*(matriz+fila)+columna-1)=='-') esDisponible=true;

    return esDisponible;
}
char ** crearMatrizCine(){
    char ** matriz= new char*[15];

    for(int fila=0;fila<15;fila++){
        matriz[fila]=new char[20];
        for(int colum=0;colum<20;colum++){
            *(*(matriz+fila)+colum)='-';
        }
    }

    return matriz;
}
void imprimirMatrizChar(char ** matriz){

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<20;j++)
        {
            cout<<matriz[i][j]<<"|";
        }
        cout<<"\n";
    }

}
int filaLetra2Numero(char fila ){
    int f=0;
    if(fila>=65 && fila<=79){
        f=fila-65;
    }
    if(fila>=97 && fila<=111){
        f=fila-97;
    }
    return f;
}
//********************** funcion para el problema 12******************
void llenarmatriz(int tamanomatriz, int **matriz){
    int dato;
    for(int i=0;i<tamanomatriz;i++)
    {//i representa las filas
        matriz[i]=new int[tamanomatriz];
        for(int j=0;j<tamanomatriz;j++)
        {//j representa las columnas
            cout << "Ingrese elemento:["<< i+1 <<"]["<< j+1<<"]=";
            cin>>dato;
            *(*(matriz+i)+j)=dato;
        }
    }
    imprimirmatriz(tamanomatriz,tamanomatriz,matriz);
}
void determinarmatrizmagica(int tamanomatriz,int **matriz){
    int sumac=0,sumaf=0,sumad=0,i=0,bandera=0;
    while(bandera==0)
    {
        for(int j=0;j<tamanomatriz;j++){
            sumaf+=matriz[i][j];
            sumac+=matriz[j][i];
            sumad+=matriz[j][j];
        }
        if(sumaf==sumac & sumac==sumad){

            bandera=1;
            cout<<"Es cuadrado magico\n";break;
            break;
        }
        else
        {
            cout<<"No es cuadrado magico\n";break;
        }
    }
    if(bandera==0)cout<<"Si es cuadrado magico\n";
}
void imprimirmatriz(int f,int c,int **matriz){
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(matriz[i][j]>10){cout<<matriz[i][j]<<" ";}
            else{cout<<matriz[i][j]<<"  ";}
        }
        cout<<"\n";
    }

}
//********************** funcion para el problema 16******************
unsigned long long int factorial(int tamanomatriz){
    unsigned long long int nfac=1;
    if(tamanomatriz==0)
    {
        nfac=1;
    }
    else
    {
        for(int i=1;i<tamanomatriz;i++){
            nfac*=i;
        }
    }
    return nfac;
}
