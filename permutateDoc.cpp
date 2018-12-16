#include <iostream> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sys/stat.h>
using namespace std;

void usage(){
	cerr << "Usage: ./permutateDoc file_path n_permutations" << endl;
	exit(1);
}


int main(int argc, char** argv){
	if (argc != 3)
	{
		usage();
	}
	
	struct stat info;
	if (stat("perms",&info) != 0)
	{
		system("mkdir -p perms");
	} else {

		system("rm -r perms/*");
	}
	string originalPath = argv[1];
	ifstream oriFile;
	oriFile.open(originalPath);
	string temp;
	vector<string> permutation;
	while(oriFile >> temp){
		permutation.push_back(temp);
	}
	int perms = stoi(argv[2]);

	for (int i = 0; i < perms; ++i)
	{
		fstream f;
		random_shuffle(permutation.begin(), permutation.end());
		f.open("perms/perm_"+ to_string(i) + ".txt", ios::out|ios::in|ios::trunc);
		for (string s : permutation)
		{
			f<<s<<" ";
		}
		f.close();

	}

}
