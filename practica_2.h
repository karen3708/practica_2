#ifndef PRACTICA_2_H
#define PRACTICA_2_H
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

#endif // PRACTICA_2_H
