#ifndef LSH
#define LSH

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct parella{
    int i,j;
}:

int generateNextPrimeNumber(int n);
/* Pre: n es un enter > 1
 * Post: Retorna el primer enter despres de n, < 1000000.
 */

int hashFunction(int n, int hashedValue, int &primer);
/* Pre: Millor si n es primer
 * Post: Retorna un enter de valor 0..m, on m es el primer nombre primer despres de n, que representa un bucket
 */

vector<parella> LSH_Function(vector< vector <int>> SignatureMatrix, int bands, double threshold);
/* Pre: L'enter bands es multiple de SignatureMatrix.size(), 0<=threshold<=1
 * Post: Retorna el conjunt de parelles de documents a comparar
 */


#endif
