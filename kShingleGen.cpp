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
		
	}

	set<string>::iterator it = shingles.begin();
	int schars = 0;
	int shin = 0;
	if (total.length()>=k)
	{
		cout << "Valid document: creating " << k << "-shingles" << endl;
		for (int i = 0; i < total.length(); i = i+k)
		{
			schars++;
			if (i+k <= total.length())
			{
				shin++;
				shingles.insert(it,total.substr(i,k));
				it++;
			}
		}
		cout << "Generació finalitzada. Stats:" << endl;
		cout << "Paraules del document:" << words << endl;
		cout << "Caràcters analitzats del document:" << chars << endl;
		cout << "Caràcters considerats per a " << k <<"-shingles:" << schars << endl;
		cout << "Número de " << k << "-shingles:" << shin << endl;

		return true;

	} else return false;
}
