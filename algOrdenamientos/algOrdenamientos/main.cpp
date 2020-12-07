//
//  main.cpp
//  algOrdenamientos
//
//  Created by Sebas Neira Gzz on 13/09/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>

using namespace std;

void iniciaTiempo(struct timeval &begin) {
    gettimeofday(&begin, 0);
}

void calculaTiempo(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}


template<class T>
void intercambia(vector<T> &lista, int a, int b) {
    T aux = lista[b];
    lista[b] = lista[a];
    lista[a] = aux;
}

template<class T>
void ordenaIntercambio(vector<T> &lista, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i=0; i<lista.size()-1; i++) {
        for (int j=i+1; j<lista.size(); j++) {
            comparaciones++;
            if (lista[i] > lista[j]) {
                intercambia(lista,i,j);
                intercambios++;
            }
        }
    }
}

template<class T>
void ordenaBurbuja(vector<T> &lista, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    bool ordenado = false;
    for (int i=lista.size()-1; i>0 && !ordenado; i--){
        ordenado = true;
        for(int j=0; j<i; j++){
            comparaciones ++;
            if (lista[j] > lista[j+1]){
                ordenado = false;
                intercambia(lista,j,j+1);
                intercambios++;
            }
        }
    }
}

template<class T>
void ordenaSeleccion(vector<T> &lista, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    int menor;
    for (int i=0;i<lista.size()-1; i++){
        menor = i;
        for (int j=i+1; j<lista.size();j++){
            comparaciones++;
            if(lista[menor] > lista[j]){
                menor = j;
            }
        }
        if (i!=menor){
            intercambios++;
            intercambia(lista, i, menor);
        }
    }
}

template<class T>
void ordenaInsercion(vector<T> &lista, int &comparaciones, int &intercambios) {
    for (int i=1;i<lista.size();i++){

        int j = i-1;
        comparaciones++;
        while (lista[j]> lista[j+1] && j>=0){
            intercambios++;
            intercambia(lista, j, j+1);
            j--;
            comparaciones++;
            
        }
    }
}

template <class T>
void Merge(vector<T> &lista, int inicio,int medio, int fin, int &comparaciones){
    int tamI = medio - inicio + 1;
    int tamD = fin - medio;
    vector<T> listaI;
    vector<T> listaD;
    
    for (int i=0;i<tamI;i++){
        listaI.push_back(lista[inicio+i]);
    }
    for (int j=0 ;j<tamD;j++){
        listaD.push_back(lista[medio+1+j]);
    }
    
    int k = inicio;
    int i=0;
    int j=0;
    
    while(i<tamI && j<tamD){
        comparaciones++;
        if(listaI[i]<listaD[j]){
            lista[k]=listaI[i];
            i++;
        } else {
            lista[k] =listaD[j];
            j++;
        }
        k++;
    }
    while(i<tamI){
        lista[k] = listaI[i];
        i++;
        k++;
    }
    while(j<tamD){
        lista[k] = listaD[j];
        j++;
        k++;
    }
}

template<class T>
void ordenaMergeSort(vector<T> &lista,int inicio, int fin , int &comparaciones) {
    if(inicio < fin){
        int medio = (inicio + fin)/2;
        ordenaMergeSort(lista,inicio,medio,comparaciones);
        ordenaMergeSort(lista,medio+1,fin,comparaciones);
        
        Merge(lista,inicio,medio,fin,comparaciones);
    }
}

template<class T>
void ordenaQuickSort(vector<T> &lista,int inicio, int fin , int &comparaciones) {
    if (inicio < fin){
        vector<T> listaAux=lista;
        T pivote = lista[inicio];
        int pos = inicio;
        for (int i = inicio+1;i<=fin;i++){
            comparaciones++;
            if (pivote > lista[i]){
                listaAux[pos] = lista [i];
                pos++;
            }
        }
        listaAux[pos]=pivote;
        int posPivote = pos;
        pos++;
        for(int i = inicio+1;i<=fin;i++){
            comparaciones++;
            if(lista[i] >= pivote){
                listaAux[pos] = lista[i];
                pos++;
            }
        }
        lista = listaAux;
        ordenaQuickSort(lista,inicio,posPivote-1,comparaciones);
        ordenaQuickSort(lista,posPivote+1,fin,comparaciones);
        
    }
}

template<class T>
void imprimir(vector<T> lista) {
    for (int i=0;i<lista.size(); i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

void creaListaEO(vector<int> &lista, int cantidad) {
    lista.clear();
    for (int i=0; i<cantidad; i++) {
        lista.push_back(rand() % 100 + 1);
    }
}

void creaListaCO(vector<char> &lista, int cantidad) {
    lista.clear();
    int r;
    for (int i=0; i<cantidad; i++) {
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

/*void creaListaSO(vector<char> &lista, int cantidad) {
    lista.clear();
    string nombres;
    for (int i=0; i<cantidad; i++) {
        cout << "Inserta un nombre: "<< endl;
        cin >> nombres;
        lista.push_back(nombres);
    }
}*/




int main()
{
    srand(time(NULL));
    int cant,comparaciones, intercambios;
    struct timeval begin, end;
    long seconds, microseconds;
    double elapsed;
    int menu = 0;
    
    
    vector<int> listaI;
    vector<char> listaC;
    
    
    
    
    while(menu <= 10){
        cout << "Menu:\n" << "1) Selecciona tipo de dato de lista a crear\n" << "2) Orden por Intercambio\n" << "3) Orden por Burbuja\n" << "4) Orden por Seleccion Directa\n" << "5) Orden por Inserción\n" << "6) Orden por Merge Sort\n" << "7) Orden por Quick Sort\n" << "8) Busqueda Sequencial\n" << "9) Busqueda Binaria\n" << "10) Salir\n" << endl;
        
        cout << "\nTeclea una opción" << endl;
        cin >> menu;
        
        switch (menu) {
            case 1:
                // CREAR VECTOR DE TIPO T
                int op;
                cout << "Teclea el tipo de datos deseado 1.enteros, 2.doble, 3. char, 4.string"<< endl;
                cin >> op;
                
                switch(op){
                    case 1:
                    {   //Vector tipo entero
                        creaListaEO(listaI, 20);
                        imprimir(listaI);
                        cout<<"\n"<< endl;
                        break;
                    }
                    case 2:
                        //Vector tipo fraccion
                        break;
                        
                    case 3:
                    {//Vector tipo char
                        creaListaCO(listaC, 20);
                        imprimir(listaC);
                        cout<<"\n"<< endl;
                        break;
                    }
                        
                    case 4:
                        //Vector tipo string
                        break;
                }
                
                break;
                
            case 2:
                // Intercambio
                iniciaTiempo(begin);
                ordenaIntercambio(listaI, comparaciones, intercambios);
                calculaTiempo(begin, end);
                cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                imprimir(listaI);
            
                break;
                
            case 3:
                // Burbuja
                iniciaTiempo(begin);
                ordenaBurbuja(listaI, comparaciones, intercambios);
                calculaTiempo(begin, end);
                cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                imprimir(listaI);
                break;
                
            case 4:
                // Selección Directa
                iniciaTiempo(begin);
                ordenaSeleccion(listaI, comparaciones, intercambios);
                calculaTiempo(begin, end);
                cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                imprimir(listaI);
                break;
            
            case 5:
                // Inserción
                iniciaTiempo(begin);
                ordenaInsercion(listaI, comparaciones, intercambios);
                calculaTiempo(begin, end);
                cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                imprimir(listaI);
                break;
            
            case 6:
                // Merge Sort
                iniciaTiempo(begin);
                comparaciones = 0;
                ordenaMergeSort(listaI, 0, listaI.size()-1, comparaciones);
                calculaTiempo(begin, end);
                cout << "Comparaciones: " << comparaciones << endl;
                imprimir(listaI);
                break;
            
            case 7:
                // Quick Sort
                iniciaTiempo(begin);
                comparaciones = 0;
                ordenaQuickSort(listaI,0, listaI.size()-1, comparaciones);
                calculaTiempo(begin, end);
                cout << "Comparaciones: " << comparaciones << endl;
                imprimir(listaI);
                break;
                
            case 8:
                // Sequencial
                break;
                
            case 9:
                // Binaria
                break;
                
            case 10:
                // Salir
                break;
            
                
            default:
                //OPCION INCORRECTA INTENTE DE NUEVO
                break;
        }
        
    }
    /*srand(time(NULL));
    int cant,comparaciones, intercambios;
    struct timeval begin, end;
    long seconds, microseconds;
    double elapsed;


    vector<int> listaE;
    vector<int> listaEO;
    vector<char> listaC;

    creaListaEO(listaEO, 20);
    imprimir(listaE);

   // Intercambio
    listaE = listaEO;
    iniciaTiempo(begin);
    ordenaIntercambio(listaE, comparaciones, intercambios);
    calculaTiempo(begin, end);
    cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
    imprimir(listaE);
    
    // Burbuja
    listaE = listaEO;
    iniciaTiempo(begin);
    ordenaBurbuja(listaE, comparaciones, intercambios);
    calculaTiempo(begin, end);
    cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
    imprimir(listaE);
    
    // Seleccion
    listaE = listaEO;
    iniciaTiempo(begin);
    ordenaSeleccion(listaE, comparaciones, intercambios);
    calculaTiempo(begin, end);
    cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
    imprimir(listaE);
    
    // Insercion
    listaE = listaEO;
    iniciaTiempo(begin);
    ordenaInsercion(listaE, comparaciones, intercambios);
    calculaTiempo(begin, end);
    cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
    imprimir(listaE);
    
    // Merge Sort
    listaE = listaEO;
    iniciaTiempo(begin);
    comparaciones = 0;
    ordenaMergeSort(listaE, 0, listaE.size()-1, comparaciones);
    calculaTiempo(begin, end);
    cout << "Comparaciones: " << comparaciones << endl;
    imprimir(listaE);
    
    // Quick Sort
    listaE = listaEO;
    iniciaTiempo(begin);
    comparaciones = 0;
    ordenaQuickSort(listaE,0, listaE.size()-1, comparaciones);
    calculaTiempo(begin, end);
    cout << "Comparaciones: " << comparaciones << endl;
    imprimir(listaE);*/
    
    
    
    

    return 0;
}

