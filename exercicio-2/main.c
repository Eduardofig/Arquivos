#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nome_arquivo[50], nome[50];
    int id, idade;
    FILE *stream;
    scanf("%s", nome_arquivo);
    stream = fopen(nome_arquivo, "rb");
    while(fread(&id, sizeof(int), 1, stream)) {
        fread(nome, sizeof(char), 50, stream);
        fread(&idade, sizeof(int), 1, stream);
        if(idade >= 18) {
            if(strlen(nome) == 0) {
                printf("O usuario de identificacao %d eh de maior.\n", id);;
            } else {
                printf("O usuario %s eh de maior.\n", nome);
            }
        }
    }
    fclose(stream);
    return 0;
}
