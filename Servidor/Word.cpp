#include "Word.h"

Word::Word(){
}

Word::Word(string word, string tip){
    this->word = word;
    this->tip = tip;

}

string Word::getWord(){
    return this->word;
}

string Word::getTip(){
    return this->tip;
}

string Word::getShaded(string kicks){

    string empty (this->word.size(), '_');
    for(int i = 0; i < (int)kicks.size(); i++){
        for(int j = 0; j < (int)this->word.size(); j++){
            if(kicks[i] == this->word[j])
                empty[j] = this->word[j];
        }
    }
    return empty;

}

Word::~Word(){

}
