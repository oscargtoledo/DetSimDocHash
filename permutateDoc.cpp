#include <iostream> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
using namespace std;

void usage(){
	cerr << "Usage: permutateDoc file_path n_permutations" << endl;
	exit(1);
}


int main(int argc, char** argv){
	if (argc != 3)
	{
		usage();
	}
	string originalPath = argv[1];

	ifstream oriFile;

	oriFile.open(originalPath);

	string temp;
	string permutation = "";
	while(oriFile >> temp){
		cout << temp << endl;
		permutation += temp;
	}
	int perms = stoi(argv[2]);

	for (int i = 0; i < perms; ++i)
	{
		fstream f;
		next_permutation(permutation.begin(),permutation.end());
		f.open("perm_"+ to_string(i) + ".txt", ios::out|ios::in|ios::trunc);
		f<<permutation;
		f.close();

	}


}
