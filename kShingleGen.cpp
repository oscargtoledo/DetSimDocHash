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
	while (inFile >> s){
		for (char c : s)
		{
			if (c >= 'A' and c<= 'Z')
			{
				c = tolower(c);
				total += c;
			} else if (c>='a' and c<='z')
			{
				total += c;
			}
		}
		
	}
	//cout << total << endl;

	//set<string> shingles;
	if (total.length()>=k)
	{
		cout << "Valid document: creating " << k << "-shingles" << endl;
		for (int i = 0; i < total.length(); i = i+k)
		{
			if (i+k <= total.length())
			{
				shingles.insert(total.substr(i,k));
			}
		}

		return true;

	} else return false;
}


/*int main(){
	set<string> C1, C2;
	string doc1 = "doc1.txt";
	string doc2 = "doc2.txt";
	if (kShingling(doc1,2,C1))
	{
		for (string s : C1)
		{
			cout << s << endl;
		}

		if (kShingling(doc2,2,C2))
		{
			for (string s : C2)
			{
				cout << s << endl;
			}
		}
	}



}*/
