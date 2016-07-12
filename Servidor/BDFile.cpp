#include "BDFile.h"

BDFile::BDFile(){

    this->file.open("../words.txt");
    if(this->file.fail()){
        cout << "Don't found words.txt " << endl;
    }
    string name, tip;
    while (this->file >> name >> tip){
        this->words.push_back(Word(name, tip));

    }

}

Word BDFile::getWord(){
    srand(time(NULL));
    int index = rand() % this->words.size();
    return this->words[index];

}

BDFile::~BDFile(){
    this->file.close();
}
