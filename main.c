#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Sonda.h"

#define STRING 100

int main(){
    char data[Data];
    time_t mytime;
    mytime = time(NULL);

    int numsondas;
    double lat_i, long_i;
    int  c_i, v_i, vc_i, identificador;

    scanf("%d", &numsondas);//A primeira entrada é o numero de sondas que irão ser inicializadas

    //for(int i=0;i<numsondas;i++){
        Sonda NovaSonda;
        identificador = 1;
        scanf("%lf %lf %d %d %d %d", &lat_i, &long_i, &c_i, &v_i, &vc_i);
        InicializaSonda(NovaSonda, lat_i, long_i, c_i, vc_i, identificador);
    //}

    int numoperacoes;
    char operacao;
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];

    scanf("%d", &numoperacoes);
    ListaMinerais lista;
    for(int i=0;i<numoperacoes;i++){
        scanf("%c", &operacao);
        if(operacao=='R'){
            scanf("%lf %lf %d %s %s %s", &latrocha, &longrocha, &pesorocha, mineral1, mineral2, mineral3);
            InsMineral(&lista, mineral1);
            InsMineral(&lista, mineral2);
            InsMineral(&lista, mineral3);
            RochaMineral RochaTeste;
            InicializaRocha(&RochaTeste, pesorocha, &lista, latrocha, longrocha, ctime(&mytime));
            InsereRocha(&NovaSonda->Compartimento, &RochaTeste, c_i);
        }
    }
    
    

    /*for(int k = 0; k < RochasColetadas; k++){
        IniVListaM(&ListaT);

        char minerais[TSTRING];    
        char cadamineral[TSTRING]; 


        int i, j = 0;

        getchar();
        fgets(minerais, sizeof(minerais), stdin);


        for (i = 0; i < strlen(minerais); i++) {
            if (minerais[i] == ' ' || minerais[i] == '\n' || minerais[i] == '\0') {  
                cadamineral[j] = '\0';       // Finaliza a string cadamineral
                if (strlen(cadamineral) > 0) { // Verifica se cadamineral não está vazio
                    InsMineral(&ListaT, cadamineral); // Chama a função InsMineral passando nome por nome
                    j = 0; // Reseta o índice de cadamineral para o próximo cadamineral
                }
                if (minerais[i] == '\n' || minerais[i] == '\0') {
                    break; // Sai do loop se encontrar o fim da linha ou da string
                }
            } else {
                cadamineral[j++] = minerais[i];
            }
        }

        char data[Data];

        time_t mytime;
        mytime = time(NULL);

        RochaMineral RochaTeste;
        InicializaRocha(&RochaTeste, Peso, &ListaT, Latitude, Longitude, ctime(&mytime));
        InsereRocha(&CompartimentoTeste, &RochaTeste, PesoMax);
    }*/

    ImprimiLista(&NovaSonda->Compartimento);
    return 0;
}