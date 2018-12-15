#include "SignSimil.h"
#include "kShingleGen.h"

void error_i_exit(string s)
{
    cerr << s << endl;
    exit(1);
}

set<string> getAllElements(const set<string>& set1, const set<string>& set2)
{
    set<string> s;
    int i = 0;
    for(set<string>::iterator it1 = set1.begin(); it1 != set1.end(); ++it1)
    {
        s.insert(*it1);
    }
    for(set<string>::iterator it2 = set2.begin(); it2 != set2.end(); ++it2)
    {
        s.insert(*it2);
    }
    return s;
}

float computeSimilarity(const vector<vector<int> >& Matrix)
{
    float suma = 0;
    for(int i = 0; i < Matrix[0].size(); i++)
    {
        if(Matrix[0][i] == Matrix[1][i]) suma++;
    }
    return suma/Matrix[0].size();
}

float SignatureSimilarity(string path1, string path2, int k, int t)
{
    set<string> set1, set2;
    if(!kShingling(path1, k, set1)) error_i_exit("No hi ha shingles de la mida posada en l'arxiu 1");
    if(!kShingling(path2, k, set2)) error_i_exit("No hi ha shingles de la mida posada en l'arxiu 2");

    set<string> elements = getAllElements(set1, set2);

    vector<vector<int> > signMatrix(2,vector<int>(t, -1));

//auto hash = [i, sizeMax](int a){return (a+i)%sizeMax;};
    int row = 0;
    for(set<string>::iterator it = elements.begin(); it != elements.end(); ++it)    // for every element
    {
        vector<int> hashf(t);
        for(int i = 0; i < t; i++)                                          //COMPUTO LAS FUNCIONES HASH
        {
            if(i%2 == 0) hashf[i] = (row + i)%elements.size();              //TODO: posar mes funcions de hash "random"
            else hashf[i] = (2*row + i)%elements.size();
        }

                                                                            //for every set
        if(set1.find(*it) != set1.end())                                    // if the set contains the element
        {
            for(int i = 0; i < t; i++)                                      // for every hash
            {
                if(signMatrix[0][i] == -1 or signMatrix[0][i] > hashf[i])   // if current hash is smaller than the existing hash in the slot
                        signMatrix[0][i] = hashf[i];                        //then replace with the smaller hash value
            }
        }

        if(set2.find(*it) != set2.end())
        {
            for(int i = 0; i < t; i++)
            {
                if(signMatrix[1][i] == -1 or signMatrix[1][i] > hashf[i])
                        signMatrix[1][i] = hashf[i];
            }
        }
        row++;
    }

    for(int i = 0; i < signMatrix.size(); ++i)
    {
        for(int j = 0; j < signMatrix[i].size(); ++j)
        {
            cout << signMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return computeSimilarity(signMatrix);
}