//
//  main.cpp
//  homework4- Glätten eines Signals, bzw filten
//
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void filtern( const double* const f, const int N, const string noisy);
void reading( const double* const f, const int N, const string noisy); // Unterfunktionen
void ausgabe( const double* const f, const int N, const string noisy);

int main(){
    int n;
    const int N= 237;
    const double* const f=new double [n]; // neuer dynamischer Array mit unbekanntem n
    const string noisy= "noisy.txt"; // string "noisy" wird gebildet mit dem Inhalt "noisy.txt"
    
    filtern(f,N,noisy);
    reading(f,N,noisy); // Unterfunktionen sollen aufgerufen werden
    ausgabe(f,N,noisy);
    
    delete[] f; // Pointer f wird geschlossen, damit nicht zu viel Speicher benutzt wird..
    
    return 0;
    
}

void filtern(const double* const f, const int N, const string noisy){ // (Noisy soll gelesen werden und) mit
    // g[i] = (f[i-1] + f[i] + f[i+1])/3 gefiltert werden   Funktion: f[N]=f[0]
    
    // für i=0: g[0]=f[N-1]+f[0]+f[1] ----> f[0]=g[0]
    // für i=1: g[1]=f[0]+f[1]+f[2]-----> f[1]=g[1]
    // für i=2; g[2]=f[1]+f[2]+f[3]   ---> f[i]=g[1]    das neue f[N-1] ist immer das vorherige f[i]; altesf:f[i]
    
    double neuesf=f[N-1];
    double altesf ;
    
    for(int i=0; i<N; i++){
        altesf =f[i]; // altes F wird hier erwähnt und dann in die For schleufe gegeben
        f[i]=(neuesf+f[i]+f[i+1])/3;
        neuesf=altesf; //neues F wird mit dem alten F überschrieben , verschieb sich dann also zu f[i]
    }
    
    
    // hier ist irgendwas falsch!!! " Read only variable is not assignable"
}

void reading (const double* const f, const int N, const string noisy){
    ifstream in(noisy.c_str()); // Lesen des strings "noisy"(in main gesagt, dass string noisy="noisy.txt."
                                //ist , char Pointer, warum man den verwendet KP ;)
    
    for(int i=0; i<N; i++){
        
        in >> f[i];// aus der gefilterten Funktion werden f[i] übernommen und in Noisy gepackt
    
    }
        in.close();
    // hier ist auch was falsch, "invalid operands to binary expression('istream'aka'basic_ifstream<char>') and 'double'
    
}
void ausgabe( const double* const f, const int N, const string noisy){ // die gefilterte Funktion (gefiltert+noisy) soll ausgegeben werden
    ofstream out( "filtered.txt");
    
    for (int i=0; i<N; i++){
        out << f[i]<< endl;
    }
    
    out.close(); // aufhören zu speichern
}  
