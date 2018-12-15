#include "Jsim.h"


float Jsim(set<string> A, set<string> B){
	set<string> intersection;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(intersection, intersection.begin()));

	set<string> uni;
	set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(uni, uni.begin()));

	float c = (float)intersection.size()/(float)uni.size();
	cout << "Similitud de Jaccard: " << c << endl;
	return c;
} 
