#include "kShingleGen.h"


bool kShingling(string path,int k, set<string>& shingles){
	ifstream inFile;
	inFile.open(path);
	string s;
	if (!inFile)
	{
		cerr << "Error opening doc1";
		exit(1);
	}


	string total = "";
	int words = 0;
	int chars = 0;
	while (inFile >> s){
		words++;
		for (char c : s)
		{
			chars++;
			if (c >= 'A' and c<= 'Z')
			{
				c = tolower(c);
				total += c;
			} else if ((c>='a' and c<='z') or (c>='0' and c<='9'))
			{
				total += c;
			}
		}
		total += " ";
		chars++;
		
	}
	total = total.substr(0,total.size()-1);

	set<string>::iterator it = shingles.begin();
	int schars = 0;
	int shin = 0;
	if (total.length()>=k)
	{
		for (int i = 0; i < total.length(); i++)
		{
			if (i+k <= total.length())
			{
				shin++;
				shingles.insert(it,total.substr(i,k));
				it++;
			}
			schars = i+k;
		}
		cout << "--------------------------------------------------------" << endl;
		cout << "Estadístiques generació:" << endl << endl;
		cout << "Document: " << path << endl;
		cout << "Paraules del document:                          " << words << endl;
		cout << "Caràcters analitzats del document:              " << chars << endl;
		cout << "Caràcters considerats per a " << k <<"-shingles:         " << schars << endl;
		cout << "Número de " << k << "-shingles:                           "  << shin << endl;
		cout << "--------------------------------------------------------" << endl;

		return true;

	} else return false;
}
