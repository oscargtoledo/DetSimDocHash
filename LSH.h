#ifndef LSH
#define LSH

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "kShingleGen.h"
#include "SignSimil.h"
#include "Jsim.h"

using namespace std;

struct parella{
    int i,j;
    
    bool operator==(const parella& a) const
    {
        return (i == a.i && j == a.j);
    }
    
    
    bool operator<(const parella& lhs) const
    {
        return lhs.i < i || (lhs.i == i && lhs.j < j);
    }
};

int generateNextPrimeNumber(int n);
/* Pre: n es un enter > 1
 * Post: Retorna el primer enter despres de n, < 1000000.
 */

int hashFunction(int n, int hashedValue, int &primer);
/* Pre: Millor si n es primer
 * Post: Retorna un enter de valor 0..m, on m es el primer nombre primer despres de n, que representa un bucket
 */

set<parella> LSH_Function(vector< vector <int>> SignatureMatrix, int bands);
/* Pre: L'enter bands es multiple de SignatureMatrix.size(), 0<=threshold<=1
 * Post: Retorna el conjunt de parelles de documents a comparar
 */


#endif
