#include <iostream>
#include <cmath>
#include <fstream>
#include "kShingleGen.h"
#include "Jsim.h"
#include "SignSimil.h"
#include "LSH.h"

using namespace std;

void usage()
{
    cerr << "LSHMain directory_path where the documents have documentx.txt from 0 to x and X documents number" << endl;
    exit(1);
}


 
int main(int argc, char** argv){
    
    if (argc != 3){
        usage();
    }
    
    int k, t, bands;
    double proporcio = 0.5;
    cout << "Llargada dels shingles: "; cin >> k;
    cout << "Funcions Hash a utilitzar: "; cin >> t;
    cout << "Nombre de bands en que volem dividir les funcions hash(t % bands = 0): "; cin >> bands;
    //cout << "Nombre del 0<percentatge<1 minim per a calcular la proporcio de parelles candidates que el superen: "; cin >> proporcio; 
    vector<string> s;
    string directoryPath = argv[1];
    int documentNumbers = stoi(argv[2]);
    
    for(int q = 0; q < documentNumbers; q++){
        s.push_back( directoryPath + "document"+ to_string(q) + ".txt");
    }
    
    vector<vector<int> > matriu = SignatureSimilarity(s, k, t);
    
    set<parella> CandidatePairs;
    CandidatePairs = LSH_Function(matriu, bands);
    string doc1, doc2;
    set<string> C1, C2;
    
    
    double contador;
    for (set<parella>::iterator it = CandidatePairs.begin(); it != CandidatePairs.end(); ++it){
        cout << "Parelles de documents candidates: " << (*it).i << ":" << (*it).j << endl;
        doc1 = s[(*it).i];
        doc2 = s[(*it).j];
        kShingling(doc1,k,C1);
        kShingling(doc2,k,C2);
        if (Jsim(C1,C2)>proporcio) contador++;
    }
    fstream fitxerSortida;
    fitxerSortida.open("analisisPermutacions.txt", ios::app);
    fitxerSortida << "Parelles candidates: " << CandidatePairs.size() << ". K-Shingles: " << k << ". Funcions hash: " << t << ". Bands: " << bands << ". Proporcio de parelles candidates amb un Jsim superior al " << proporcio << ": " << contador/double(CandidatePairs.size()) << endl;
    fitxerSortida.close();
    
    /*ofstream fs("analisis.txt", ios::ate);
    fs << "Parelles candidates: " << CandidatePairs.size() << ". K-Shingles: " << k << ". Funcions hash: " << t << ". Bands: " << bands << ". Percentatge de parelles candidates amb un Jaccard similarity superior al " << proporcio << ": " << contador/double(CandidatePairs.size()) << endl;
    fs.close();
    */
}
