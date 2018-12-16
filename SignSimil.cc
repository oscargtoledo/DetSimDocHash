#include "SignSimil.h"

void error_i_exit(string s)
{
    cerr << s << endl;
    exit(1);
}

set<string> getAllElements(const vector<set<string> >& sets)
{
    set<string> s;
    for(int i = 0; i < sets.size(); i++)
    {

        for(set<string>::iterator it1 = sets[i].begin(); it1 != sets[i].end(); ++it1)
        {
            s.insert(*it1);
        }
    }
    return s;
}

vector<float> computeSimilarity(const vector<vector<int> >& Matrix, int index)
{
    vector<float> r(Matrix.size());
    for(int i = 0; i < Matrix.size(); i++)
    {
        float suma = 0;
        for(int j = 0; j < Matrix[i].size(); j++)
        {
            if(Matrix[i][j] == Matrix[index][j]) suma++;
        }
        r[i] = (suma/Matrix[i].size())*100;
    }
    return r;
}

bool isPrime(int n)
{
    if(n == 1) return true;
    for(int i = 3; i*i < n; i += 2)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int nextPrime(int n)
{
    if(n%2 == 0) --n;
    else ----n;
    while(!isPrime(++++n)){}   // +2 perque els parells no son primers
    return n;
}

void RandomInts(vector<int> &V, int t, int p)
{
    for(int i = 0; i < t; i++)
    {
        V[i] = rand()%p;
    }
}

vector<vector<int> > SignatureSimilarity(const vector<string> &paths, int k, int t)
{
    vector<set<string> > vSet;
    for(int i = 0; i < paths.size(); i++)
    {
        set<string> auxSet;
        if(!kShingling(paths[i], k, auxSet)) error_i_exit("No hi ha shingles de la mida posada en l'arxiu:\n\t" + paths[i]);
        vSet.push_back(auxSet);
    }

    set<string> elements = getAllElements(vSet);

    vector<vector<int> > signMatrix(paths.size(),vector<int>(t, -1));

    int p = nextPrime(elements.size());
    vector<int> A(t),B(t);
    srand(time(NULL));
    RandomInts(A, t, elements.size());
    RandomInts(B, t, elements.size());

    int row = 0;
    for(set<string>::iterator it = elements.begin(); it != elements.end(); ++it)    // for every element
    {
        vector<int> hashf(t);
        for(int i = 0; i < t; i++)                                              //COMPUTO LAS FUNCIONES HASH
        {
            hashf[i] = (A[i]*row + B[i])%p;
        }

        for(int i = 0; i < vSet.size(); i++)                                    //for every set
        {
            if(vSet[i].find(*it) != vSet[i].end())                              // if the set contains the element
            {
                for(int j = 0; j < t; j++)                                      // for every hash
                {
                    if(signMatrix[i][j] == -1 or signMatrix[i][j] > hashf[j])   // if current hash is smaller than the existing hash in the slot
                            signMatrix[i][j] = hashf[j];                        //then replace with the smaller hash value
                }
            }
        }

        row++;
    }
    return signMatrix;
}