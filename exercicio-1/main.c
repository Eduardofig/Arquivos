#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analisar_linha(char *linha)
{
    char *id = strsep(&linha, ",");
    char *nome = strsep(&linha, ",");
    int idade = atoi(strsep(&linha, ","));
    if(idade >= 18) {
        if(!strcmp(nome, "")) {
            printf("O usuario de identificacao %s eh de maior.\n", id);
            return;
        } 
        printf("O usuario %s eh de maior.\n", nome);
    }
    return;
}

int main(int argc, char *argv[])
{
    FILE *stream;
    char linha[1024];
    scanf("%s", linha);
    stream = fopen(linha, "r");
    fgets(linha, 1024, stream);
    while(fgets(linha, 1024, stream)) {
        analisar_linha(linha);
    }
    fclose(stream);
    return 0;
}
