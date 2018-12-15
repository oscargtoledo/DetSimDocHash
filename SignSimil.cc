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

    int row = 0;
    for(set<string>::iterator it = elements.begin(); it != elements.end(); ++it)    // for every element
    {
        vector<int> hashf(t);
        for(int i = 0; i < t; i++)                                              //COMPUTO LAS FUNCIONES HASH
        {
            if(i%2 == 0) hashf[i] = (row + i)%elements.size();                  //TODO: posar mes funcions de hash "random"
            else hashf[i] = (2*row + i)%elements.size();
        }

        for(int j = 0; j < vSet.size(); j++)                                    //for every set
        {
            if(vSet[j].find(*it) != vSet[j].end())                              // if the set contains the element
            {
                for(int i = 0; i < t; i++)                                      // for every hash
                {
                    if(signMatrix[j][i] == -1 or signMatrix[j][i] > hashf[i])   // if current hash is smaller than the existing hash in the slot
                            signMatrix[j][i] = hashf[i];                        //then replace with the smaller hash value
                }
            }
        }

        row++;
    }
    return signMatrix;
}
