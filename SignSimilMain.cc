#include <iostream>
#include "SignSimil.h"
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
    int n; 
    while(n != 0)
    {
        cout << "De quin dels arxius anteriors vols fer la comparacio? (enter del 1 al " << s.size() << ", 0 per sortir) ";
        cin >> n;
        if(n != 0)
        {
            vector<float> resultat = computeSimilarity(matriu, n-1);

            cout << "La aproximacio de la similitud dels documents es: " << endl;
            for(int i = 0; i < resultat.size(); i++)
            {
                cout << i+1 << '\t';
            }
            cout << endl;
            for(int i = 0; i < resultat.size(); i++)
            {
                cout << resultat[i] << '%' << '\t';
            }
            cout << endl;
        }
    }
}
