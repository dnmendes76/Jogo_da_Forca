#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdbool.h> // conserto bug size_struct
#include <unistd.h> // conserto bug close()
#include <sstream>

#include "Start.h"
#include "BDFile.h"

using namespace std;

char* getDados(Start *game);

int main(){
    // declarar as variáveis
    struct sockaddr_in info;

    int socket_input, socket_conexao;
    time_t data_e_hora;
    int tamanho_estrutura;
    char *data_hora_por_extenso;

    socklen_t sin_size; // size

    char recv[10];
    int op;
    Start* game;
    BDFile bd;

    // inicializar o socket
    socket_input = socket(AF_INET, SOCK_STREAM, 0);
    info.sin_family = AF_INET;
    info.sin_port = htons(7000);
    info.sin_addr.s_addr = INADDR_ANY;

    tamanho_estrutura = sizeof(info);

    if(bind(socket_input, (struct sockaddr*) &info, tamanho_estrutura) == 0){
        listen(socket_input, 2);

        while(1){
            // receber conexões
            sin_size = sizeof(struct sockaddr_in);
            socket_conexao = accept(socket_input, (struct sockaddr*) &info, &sin_size);

            // pegar a hora do sistema e mandar
            data_e_hora = time(NULL);
            data_hora_por_extenso = ctime(&data_e_hora);
            printf("Cliente conectado as %s\n", data_hora_por_extenso);

            do{

                cout << read(socket_conexao, recv, strlen(recv));
                op = atoi(recv);

                game = new Start(bd.getWord());
                char chute = ';';

                int sizeAll = strlen(getDados(game))+ 30;
                char *allText = (char*)malloc( sizeof( char ) *(sizeAll) );
                strcpy(allText, getDados(game));
                write(socket_conexao, allText , strlen(allText));

                while(1){

                    if (game->win() || game->lost()){
                        break;
                    }

                    cout << read(socket_conexao, &chute, 1)<<endl;
                    cout <<chute<<endl;

                    string palavra = game->word.getWord();
                    if(palavra.find(chute) != string::npos){
                        game->numHits++;
                    }
                    else{
                        game->numMistakes++;
                    }
                    game->kicks += chute;

//                    cout << "aqui" << endl;
                    strcpy(allText, getDados(game));

                    if (game->win()){
                        allText = strcat(allText, ";:);");
                    }
                    else if(game->lost()){
                        allText = strcat(allText, ";:(;");
                    }
                    else{
                        allText = strcat(allText, ";:|;");
                    }

                    allText = strcat(allText, palavra.c_str());

                    cout<<write(socket_conexao, allText , strlen(allText))<<endl;
//                    cout << "aqui2" << endl;


                }// loop

            }while(op == 1);

            close(socket_conexao);
        }

        close(socket_input);
    }
    else{
        printf("Tente outra Vez! Nao deu pra abri a porta! :/ \n");
    }

    return 0;
}

// pega todos os dados de uma iteração do usuário com o jogo e concatena pra ser enviado para o cliente.
char* getDados(Start *game){

    int chances = (game->limMistake - game->numMistakes);
    int acertos = game->numHits;

    char *chutes = (char*)malloc( sizeof( char ) *(game->kicks.length() +1) );
    strcpy(chutes, game->kicks.c_str());
    char *pMap = (char*)malloc( sizeof( char ) *(game->getShaded().length() +1) );
    strcpy(pMap, game->getShaded().c_str());
    char *dica = (char*)malloc( sizeof( char ) *(game->word.getTip().length() +1) );
    strcpy(dica, game->word.getTip().c_str());

    char temp1[10];
    sprintf(temp1, "%i", chances);
    char temp2[10];
    sprintf(temp2, "%i", acertos);
    char *quebra = ";";

    int sizeAllText = strlen(temp1) + strlen(temp2) + strlen(chutes) + strlen(pMap) + strlen(dica)+ 7;
    char *allText = (char*)malloc( sizeof( char ) *(sizeAllText +1) );
    allText = strcat(temp1, quebra);
    allText = strcat(allText, temp2);
    allText = strcat(allText, quebra);
    allText = strcat(allText, chutes);
    allText = strcat(allText, quebra);
    allText = strcat(allText, pMap);
    allText = strcat(allText, quebra);
    allText = strcat(allText, dica);

    return allText;
}
