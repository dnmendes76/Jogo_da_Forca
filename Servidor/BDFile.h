#ifndef BDFILE_H
#define BDFILE_H

#include"Word.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

class BDFile
{
private:
    vector<Word> words;
    ifstream file;

public:
    BDFile();
    ~BDFile();

    Word getWord();

};

#endif // BDFILE_H
