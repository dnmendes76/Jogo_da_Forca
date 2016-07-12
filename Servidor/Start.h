#ifndef START_H
#define START_H

#include "Word.h"

class Start
{
public:

    Word word;
    int limMistake = 10;
    int numHits = 0;
    int numMistakes = 0;
    string kicks = "";

    Start();
    Start(Word word, int limMistake = 10);
    ~Start();

    bool win();
    bool lost();

    string getShaded();


};

#endif // START_H

