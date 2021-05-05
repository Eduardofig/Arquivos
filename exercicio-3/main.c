#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binarioNaTela(char *nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}

int main(int argc, char *argv[])
{
    char *nome_do_arquivo, *nome;
    int num, id, idade;
    scanf("%s %d", nome_do_arquivo, &num);
    FILE *stream;
    stream = fopen(nome_do_arquivo, "wb");
    for (int i = 0; i < num; ++i) {
        scanf("%d %s %d", &id, nome, &idade);
        fwrite(&id, sizeof(int), 1, stream);
        fwrite(nome, sizeof(char), strlen(nome) + 1, stream);
        fwrite(&idade, sizeof(int), 1, stream);
    }
    fclose(stream);
    binarioNaTela(nome_do_arquivo);
    return 0;
}
