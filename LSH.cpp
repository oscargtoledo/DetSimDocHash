#include "LSH.h"

int generateNextPrimeNumber(int n){
    int i=n;
    bool trobat=false;
    
    while (i<1000000 and not trobat){
        for (int j=2; j<i; j++)
        {
            if (i % j == 0){
                j=i;
                trobat=false;
            }
                
            else if (i == j+1)
                trobat = true;

        }
        ++i;
        if (trobat) return i;
    }
}

int hashFunction(int n, int hashedValue, int &primer){
    primer = generateNextPrimeNumber(n);
    return ((5*hashedValue+76) % primer);
}

vector<parella> LSH_Function(vector< vector <int>> SignatureMatrix, int bands, double threshold){
    vector<parella> vReturn; // vector a retornar
    int primeNumber, n, primer, hashValue; 
    int nConjunts = SignatureMatrix.size(); // nombre de conjunts a analitzar
    int r = SignatureMatrix[0].size() / bands; // files per banda
    
    
    for (int i=0; i<bands; ++i){                            // Per a cada band
        vector<int> setValuesForBand(nConjunts, 0);         // Valors a hashehar de la band i per a cada columna(conjunt)
        n = (i+1)*100;                                      // Valor n per a la hashFunction
        for (int j=i*r; j<(i+1)*r; ++j){                    // Analitzem totes les files de la banda i
            for(int c=0; c<nConjunts; ++c){                 // Per a cada columna c
                
                setValuesForBand[c] = (10*setValuesForBand[c]) + SignatureMatrix[c][j];
            }
        }
        
        /* A setValuesForBand[c] tenim el valor de la columna c en la band i per a hashejar a un bucket */
        
        hashValue = hashFunction(n, setValuesForBand[0], primer);   // hashejem el valor de la primera columna
        vector < vector <int> > Buckets(primer, vector<int>());     // Vector de Buckets
        Buckets[hashValue].push_back(0);
        
        for (int h=1 ;h<nConjunts; ++h){                            // per a cada columna hashejem lo valor
            hashValue = hashFunction(n, setValuesForBand[h], primer);
            
            if (Buckets[hashValue].size() != 0){                    // Si lo bucket[hashValue] conte ja algun valor,
                                                                    // formem una parella candidata dels valors de
                                                                    // bucket[hashedValue] amb h i afegim h al bucket
                parella candidatePair;
                candidatePair.i = h;
                
                for(int u=0; u<Buckets[hashValue].size(); ++u){
                    candidatePair.j = Buckets[hashValue][u];
                    vReturn.push_back(candidatePair);
                }
            }
            
            Buckets[hashValue].push_back(h);
        }
    }
    return vReturn;
}
