#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 11
#define C 41

typedef struct
{
    char nome[50];
    int vida;
    int atk;
    char tipo;
} Algomon;

typedef struct
{
    Algomon algm[15];
    char nome[10];
    int linha;
    int coluna;
    int algodex;
    int insig;

} Player;

void desenha_mapa(char mapa[L][C], Player jogador)
{
    // mapa[Px][Py]='A';

    printf("\n");

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == jogador.linha && j == jogador.coluna)
            {
                printf("A");
            }
            else if ('a' <= mapa[i][j] && mapa[i][j] <= 'z')
            {
                printf("#");
            }
            else
                printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
    printf("\nAlgodex (%d/15) Algomons: %d Insignias: %d\n", jogador.algodex,
           jogador.algodex, jogador.insig);
}

void desenha_algomons(Player jogador)
{
    for (int i = 0; i < jogador.algodex; i++)
    {
        printf("%s Atk: %d HP: %d Type: %c\n", jogador.algm[i].nome,
               jogador.algm[i].atk, jogador.algm[i].vida, jogador.algm[i].tipo);
    }
}

void tela_batalha(Player jogador, Player treinador)
{
    printf("\e[1;1H\e[2J");
    printf("Treinador %s:\n", treinador.nome);
    desenha_algomons(treinador);
    printf("\n/////////////////// C O N T R A ///////////////////\n");
    printf("\nJogador:\n");
    desenha_algomons(jogador);
    printf("Qual seu movimento (a, r, f)?\n");
    printf(
        "a = Ataque\nr = rolar a lista pra cima\nf = rolar a lista pra baixo\n");
}

Algomon cria_algomon(int var)
{
    Algomon algmn[12];
    if (var == 3)
    {
        strcpy(algmn[0].nome, "Charbok");
        algmn[0].atk = 6;
        algmn[0].vida = 10;
        algmn[0].tipo = 'D';

        return algmn[0];
    }
    if (var == 4)
    {
        strcpy(algmn[1].nome, "Nidarray");
        algmn[1].atk = 4;
        algmn[1].vida = 30;
        algmn[1].tipo = 'C';

        return algmn[1];
    }
    if (var == 5)
    {
        strcpy(algmn[2].nome, "Zubint");
        algmn[2].atk = 5;
        algmn[2].vida = 15;
        algmn[2].tipo = 'D';

        return algmn[2];
    }
    if (var == 6)
    {
        strcpy(algmn[3].nome, "Doublett");
        algmn[3].atk = 5;
        algmn[3].vida = 25;
        algmn[3].tipo = 'C';

        return algmn[3];
    }
    if (var == 7)
    {
        strcpy(algmn[4].nome, "Miautwo");
        algmn[4].atk = 3;
        algmn[4].vida = 50;
        algmn[4].tipo = 'D';

        return algmn[4];
    }
    if (var == 8)
    {
        strcpy(algmn[5].nome, "Ifduck");
        algmn[5].atk = 6;
        algmn[5].vida = 15;
        algmn[5].tipo = 'R';

        return algmn[5];
    }
    if (var == 9)
    {
        strcpy(algmn[6].nome, "Poliwhile");
        algmn[6].atk = 4;
        algmn[6].vida = 30;
        algmn[6].tipo = 'C';

        return algmn[6];
    }
    if (var == 10)
    {
        strcpy(algmn[7].nome, "Scanbra");
        algmn[7].atk = 6;
        algmn[7].vida = 20;
        algmn[7].tipo = 'D';

        return algmn[7];
    }
    if (var == 11)
    {
        strcpy(algmn[8].nome, "CHARmander");
        algmn[8].atk = 5;
        algmn[8].vida = 30;
        algmn[8].tipo = 'R';

        return algmn[8];
    }
    if (var == 12)
    {
        strcpy(algmn[9].nome, "Matpod");
        algmn[9].atk = 6;
        algmn[9].vida = 25;
        algmn[9].tipo = 'C';

        return algmn[9];
    }
    if (var == 13)
    {
        strcpy(algmn[10].nome, "Algochu");
        algmn[10].atk = 6;
        algmn[10].vida = 30;
        algmn[10].tipo = 'D';

        return algmn[10];
    }
}

Player cria_treinador(char mapa[L][C], Player treinador, Player jogador)
{
    if (mapa[jogador.linha][jogador.coluna] == 'Y')
    {
        treinador.algm[0] = cria_algomon(5);
        strcpy(treinador.nome, "Y");
        treinador.algm[0].vida = treinador.algm[0].vida + 20;
    }
    if (mapa[jogador.linha][jogador.coluna] == 'R')
    {
        treinador.algm[0] = cria_algomon(11);
        strcpy(treinador.nome, "R");
        treinador.algm[0].vida = treinador.algm[0].vida + 20;
    }
    if (mapa[jogador.linha][jogador.coluna] == 'X')
    {
        treinador.algm[0] = cria_algomon(7);
        strcpy(treinador.nome, "x");
        treinador.algm[0].vida = treinador.algm[0].vida + 20;
    }
    if (mapa[jogador.linha][jogador.coluna] == 'Z')
    {
        strcpy(treinador.algm[0].nome, "Ceepluplus");
        treinador.algm[0].atk = 8;
        treinador.algm[0].vida = 50;
        treinador.algm[0].tipo = 'L';
        strcpy(treinador.nome, "Z");
        treinador.algm[0].vida = treinador.algm[0].vida + 20;
    }
    return treinador;
}

Player rolar_cima(Player jogador)
{
    Algomon aux;
    int final = jogador.algodex - 1;
    aux = jogador.algm[final];

    for (int i = jogador.algodex; i > 0; i--)
    {
        jogador.algm[i] = jogador.algm[i - 1];
    }
    jogador.algm[0] = aux;
    return jogador;
}

Player rolar_baixo(Player jogador)
{
    Algomon aux;
    int final = jogador.algodex - 1;
    int i;
    aux = jogador.algm[0];

    for (i = 0; i < final; i++)
    {
        jogador.algm[i] = jogador.algm[i + 1];
    }
    jogador.algm[final] = aux;
    return jogador;
}

Player ataque_treinador(Player jogador, Player treinador)
{
    if (treinador.algm[0].tipo == 'C' && jogador.algm[0].tipo == 'R')
    {
        jogador.algm[0].vida = jogador.algm[0].vida - (treinador.algm[0].atk * 2);
        return jogador;
    }
    if (treinador.algm[0].tipo == 'R' && jogador.algm[0].tipo == 'D')
    {
        jogador.algm[0].vida = jogador.algm[0].vida - (treinador.algm[0].atk * 2);
        return jogador;
    }
    if (treinador.algm[0].tipo == 'D' && jogador.algm[0].tipo == 'C')
    {
        jogador.algm[0].vida = jogador.algm[0].vida - (treinador.algm[0].atk * 2);
        return jogador;
    }
    if (treinador.algm[0].tipo == 'L')
    {
        jogador.algm[0].vida = jogador.algm[0].vida - (treinador.algm[0].atk * 2);
        return jogador;
    }

    jogador.algm[0].vida = jogador.algm[0].vida - (treinador.algm[0].atk);
    return jogador;
}

Player ataque_jogador(Player jogador, Player treinador)
{
    if (jogador.algm[0].tipo == 'C' && treinador.algm[0].tipo == 'R')
    {
        treinador.algm[0].vida = treinador.algm[0].vida - (jogador.algm[0].atk * 2);
        return treinador;
    }
    if (jogador.algm[0].tipo == 'R' && treinador.algm[0].tipo == 'D')
    {
        treinador.algm[0].vida = treinador.algm[0].vida - (jogador.algm[0].atk * 2);
        return treinador;
    }
    if (jogador.algm[0].tipo == 'R' && treinador.algm[0].tipo == 'C')
    {
        treinador.algm[0].vida = treinador.algm[0].vida - (jogador.algm[0].atk * 2);
        return treinador;
    }

    treinador.algm[0].vida = treinador.algm[0].vida - (jogador.algm[0].atk);
    return treinador;
}

Player rolar_tela(Player jogador, char comando)
{
    if (comando == 'r' || comando == 'R')
    {
        jogador = rolar_cima(jogador);
    }
    if (comando == 'f' || comando == 'F')
    {
        jogador = rolar_baixo(jogador);
    }
    return jogador;
}

Player batalha(char mapa[L][C], Player jogador)
{
    printf("\e[1;1H\e[2J");
    Player treinador;
    char controle;

    treinador.algodex = 1;
    treinador = cria_treinador(mapa, treinador, jogador);

    printf("\nO Jogador encontrou um Treinador!!!!\n");
    getchar();

    while (jogador.algm[0].vida > 0 && treinador.algm[0].vida > 0)
    {
        tela_batalha(jogador, treinador);
        controle = getchar();
        getchar();
        if (controle == 'A' || controle == 'a')
        {
            jogador = ataque_treinador(jogador, treinador);
            treinador = ataque_jogador(jogador, treinador);
        }
        if (controle == 'r' || controle == 'R' || controle == 'F' ||
            controle == 'f')
        {
            jogador = rolar_tela(jogador, controle);
        }
    }

    if (treinador.algm[0].vida <= 0)
    {
        printf("\e[1;1H\e[2J");
        printf("Parabens voce venceu o Treinador %s e ganhou 1 insignia\n",
               treinador.nome);
        jogador.insig++;
        printf("Agora voce possui %d\n", jogador.insig);
        getchar();
    }

    printf("\e[1;1H\e[2J");
    return jogador;
}

Player resolve_cidade(char mapa[L][C], Player jogador)
{
    char codigo = mapa[jogador.linha][jogador.coluna];
    jogador.algm[jogador.algodex] = cria_algomon(codigo - 'a');

    printf("O Jogador capturou o algomon %d\n", (codigo - 'a' + 1));

    mapa[jogador.linha][jogador.coluna] = '+';
    jogador.algodex++;
    return jogador;
}

Player resolve_local(char mapa[L][C], Player jogador)
{
    if ('a' <= mapa[jogador.linha][jogador.coluna] &&
        mapa[jogador.linha][jogador.coluna] <= 'z')
    {
        if (mapa[jogador.linha][jogador.coluna] == 'f' && jogador.insig < 1)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 1 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'g' && jogador.insig < 1)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 1 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'h' && jogador.insig < 2)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 2 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'i' && jogador.insig < 2)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 2 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'j' && jogador.insig < 3)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 3 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'k' && jogador.insig < 3)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 3 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'l' && jogador.insig < 3)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 3 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'm' && jogador.insig < 3)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 3 insignias\n");

            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'n' && jogador.insig < 3)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 3 insignias\n");

            return jogador;
        }

        jogador = resolve_cidade(mapa, jogador);

        return jogador;
    }

    if ('A' <= mapa[jogador.linha][jogador.coluna] &&
        mapa[jogador.linha][jogador.coluna] <= 'Z')
    {
        if (mapa[jogador.linha][jogador.coluna] == 'R' && jogador.insig < 1)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 1 insignias\n");
            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'X' && jogador.insig < 2)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 2 insignias\n");
            return jogador;
        }
        if (mapa[jogador.linha][jogador.coluna] == 'Z' && jogador.insig < 3)
        {
            printf("O Jogador possui apenas %d insignias\n", jogador.insig);
            printf("Retorne quando conseguir 3 insignias\n");
            return jogador;
        }

        jogador = batalha(mapa, jogador);
    }
    return jogador;
}

Player move_cima(char mapa[L][C], Player jogador)
{
    if (jogador.linha == 0 || mapa[jogador.linha - 1][jogador.coluna] == ' ')
    {
        return jogador;
    }
    jogador.linha--;
    while (mapa[jogador.linha][jogador.coluna] == '|')
    {
        jogador.linha--;
    }

    jogador = resolve_local(mapa, jogador);

    return jogador;
}

Player move_baixo(char mapa[L][C], Player jogador)
{
    if (jogador.linha == 11 || mapa[jogador.linha + 1][jogador.coluna] != '|')
    {
        return jogador;
    }
    jogador.linha++;
    while (mapa[jogador.linha][jogador.coluna] == '|')
    {
        jogador.linha++;
    }

    jogador = resolve_local(mapa, jogador);
    return jogador;
}

Player move_esquerda(char mapa[L][C], Player jogador)
{
    if (jogador.coluna == 0 || mapa[jogador.linha][jogador.coluna - 1] != '-')
    {
        return jogador;
    }
    jogador.coluna--;
    while (mapa[jogador.linha][jogador.coluna] == '-')
    {
        jogador.coluna--;
    }

    jogador = resolve_local(mapa, jogador);
    return jogador;
}

Player move_direita(char mapa[L][C], Player jogador)
{
    if (jogador.coluna == 41 || mapa[jogador.linha][jogador.coluna + 1] != '-')
    {
        return jogador;
    }
    jogador.coluna++;
    while (mapa[jogador.linha][jogador.coluna] == '-')
    {
        jogador.coluna++;
    }

    jogador = resolve_local(mapa, jogador);
    return jogador;
}

Player movimento(char mapa[L][C], char ctrl, Player jogador)
{
    if (ctrl == 'w' || ctrl == 'W')
    {
        jogador = move_cima(mapa, jogador);
    }

    if (ctrl == 's' || ctrl == 'S')
    {
        jogador = move_baixo(mapa, jogador);
    }

    if (ctrl == 'a' || ctrl == 'A')
    {
        jogador = move_esquerda(mapa, jogador);
    }

    if (ctrl == 'd' || ctrl == 'D')
    {
        jogador = move_direita(mapa, jogador);
    }

    if (ctrl == 'r' || ctrl == 'R')
    {
        jogador = rolar_cima(jogador);
    }

    if (ctrl == 'f' || ctrl == 'F')
    {
        jogador = rolar_baixo(jogador);
    }
    return jogador;
}

void primeira_chamada(char mapa[L][C], Player jogador)
{
    printf("\e[1;1H\e[2J");
    printf("Bem vindo ao Jogo Algomon!!\n");
    printf("Autoria: Joao Victor Pereira dos Anjos.\n");
    desenha_mapa(mapa, jogador);
    desenha_algomons(jogador);
}

int main()
{
    char mapa[L][C] = {

        {'Z', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'd', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', '-', '-', '-', '-', '-',
         '-', '-', '-', '-', '-', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'n', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '-', '-',
         '-', '-', '-', '-', '-', '-', '-', '-', 'm', '-', '-', '-', '-', '-',
         '-', '-', '-', '-', '-', 'j', '-', '-', '-', '-', '-', '-', 'X'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', 'h', '-', '-', '-', '-', '-', '-', '-', '-', '-',
         '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'i'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ',
         ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'Y', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'e', '-', '-',
         '-', '-', '-', '-', 'f', '-', '-', '-', '-', '-', '-', '-', '-', '-',
         '-', 'g', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'R'}

    };
    char controle;
    Player jogador;
    int true = 0;
    jogador.linha = 4;
    jogador.coluna = 11;
    jogador.algodex = 3;
    jogador.insig = 0;

    strcpy(jogador.algm[0].nome, "Ifssauro");
    jogador.algm[0].atk = 5;
    jogador.algm[0].vida = 20;
    jogador.algm[0].tipo = 'C';

    strcpy(jogador.algm[1].nome, "Whiledle");
    jogador.algm[1].atk = 3;
    jogador.algm[1].vida = 40;
    jogador.algm[1].tipo = 'R';

    strcpy(jogador.algm[2].nome, "vectray");
    jogador.algm[2].atk = 4;
    jogador.algm[2].vida = 30;
    jogador.algm[2].tipo = 'D';

    primeira_chamada(mapa, jogador);

    while (jogador.insig < 4)
    {
        printf("Qual seu movimento (w, a, s, d, r, f)?\n");

        controle = getchar();
        getchar();

        if (controle == 'a' || controle == 'd' || controle == 's' ||
            controle == 'w' || controle == 'r' || controle == 'f' ||
            controle == 'A' || controle == 'D' || controle == 'S' ||
            controle == 'W' || controle == 'R' || controle == 'F')
        {
            printf("\e[1;1H\e[2J");
            jogador = movimento(mapa, controle, jogador);
            desenha_mapa(mapa, jogador);
            desenha_algomons(jogador);
        }
        else
        {
            printf("\e[1;1H\e[2J");
            desenha_mapa(mapa, jogador);
            desenha_algomons(jogador);
            printf("Comando invalido!! por favor digite outro comando\n");
        }
    }
    return 0;
}