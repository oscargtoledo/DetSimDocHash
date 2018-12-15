#ifndef SIGNSIMIL
#define SIGNSIMIL

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "kShingleGen.h"
using namespace std;

vector<vector<int> > SignatureSimilarity(const vector<string> &paths, int k, int t);

vector<float> computeSimilarity(const vector<vector<int> >& Matrix, int index);


#endif
