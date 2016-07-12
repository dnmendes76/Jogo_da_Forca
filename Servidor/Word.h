#ifndef WORD_H
#define WORD_H

#include<string>

using namespace std;

class Word
{
private:
    string word = "";
    string tip = "";
public:

    Word();
    Word(string word, string tip);
    ~Word();

    string getWord();
    string getTip();
    string getShaded(string kicks);

};

#endif // WORD_H
