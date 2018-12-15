#include <iostream> 
#include "kShingleGen.h"
#include "Jsim.h"
using namespace std;

void quitError(string s){
	cerr << s << endl;
	exit(1);
}

int main(int argc, char ** argv){
	if (argc != 3)
	{
		quitError("Ús incorrecte. S'esperen com a arguments dos paths, un per cada document");
	}
	set<string> C1, C2;
	cout << "Mida per als k-shingles:";
	int k = 3;
	cin >> k;
	while (k<=0){
		cout << "k incorrecte (no pot ser menor o igual a 0). Introdueix una k válida:" << endl;
		cin>>k;
	}
	string doc1 = argv[1];
	string doc2 = argv[2];
	if (!kShingling(doc1,k,C1)) quitError("El primer document no és válid per a generar shingles amb la k introduida.");
	if (!kShingling(doc2,k,C2))	quitError("El primer document no és válid per a generar shingles amb la k introduida");
	Jsim(C1,C2);
}