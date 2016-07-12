#include "Start.h"

Start::Start(){
}

Start::Start(Word word, int limMistake){
    this->word = word;
    this->kicks = "";
    this->limMistake = limMistake;
    this->numHits = 0;
    this->numMistakes = 0;
}

bool Start::win(){
    bool w = word.getWord() == word.getShaded(this->kicks);
    return w;

}

bool Start::lost(){
    bool l = this->numMistakes >= this->limMistake;
    return l;
}

string Start::getShaded(){
    return this->word.getShaded(this->kicks);
}

Start::~Start(){

}
