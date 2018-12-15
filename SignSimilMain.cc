#include <iostream>
#include "SignSimil.h"
using namespace std;


void usage()
{
    cerr << "SignSimilMain file_path1 file_path2" << endl;
    exit(1);
}

int main(int argc, char** argv)
{
    if (argc != 3)
	{
		usage();
	}
    int k, t;
    cout << "Llargada dels shingles: "; cin >> k;
    cout << "Funcions Hash a utilitzar: "; cin >> t;
    cout << "La aproximacio de la similitud dels 2 documents es: " << SignatureSimilarity(argv[1], argv[2], k, t) << endl;
}
