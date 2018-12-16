#include <iostream>
#include "kShingleGen.h"
#include "Jsim.h"
#include "SignSimil.h"
#include "LSH.h"

using namespace std;


void usage()
{
    cerr << "SignSimilMain file_path1 file_path2 [... filepath-n]" << endl;
    exit(1);
}

int main(int argc, char** argv)
{
    if (argc < 3)
	{
		usage();
	}
    int k, t;
    cout << "Llargada dels shingles: "; cin >> k;
    cout << "Funcions Hash a utilitzar: "; cin >> t;
    vector<string> s;
    for(int i = 1; i < argc; i++)
    {
        s.push_back(argv[i]);
    }

    vector<vector<int> > matriu = SignatureSimilarity(s, k, t);
    
    int bands = 5; // bands es lo nombre de bands 
    double threshold = 0.5; // llindar t a partir del qual dos parelles son parelles candidates
    vector<parella> CandidatePairs;
    CandidatePairs = LSH_Function(matriu, bands, threshold);
    string doc1, doc2;
    set<string> C1, C2;
    
    for (int i=0; i<CandidatePairs.size(); ++i){
        cout << "Parelles de documents candidates: " << CandidatePairs[i].i << ":" << CandidatePairs[i].j << endl;
        doc1 = s[CandidatePairs[i].i];
        doc2 = s[CandidatePairs[i].j];
        kShingling(doc1,k,C1);
        kShingling(doc2,k,C2);
        Jsim(C1,C2);
    }
}
