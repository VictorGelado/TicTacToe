#include <stdio.h>

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#else

#endif


int hash[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }; // 0 == nada 1 == X, 2 == O
char hashLetter[3][3] = { {'1',  '2', '3'}, {'4',  '5', '6'}, {'7',  '8', '9'} }; // Definir as letras X e O com base em <hash>

int hashCopy[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }; // 0 == nada 1 == X, 2 == O
char hashLetterCopy[3][3] = { {'1',  '2', '3'}, {'4',  '5', '6'}, {'7',  '8', '9'} }; // Definir as letras X e O com base em <hash>


const char X = 'x';  // Possibilidade de escolher outros caracteres para o jogador 1 e 2
const char O = 'o';
int whichPlayer = 1;
int oldWinner = 0;
int whoseTurn;



// Declaracao das funcoes
void resetHashs();
int winnerVerify(int lines, int columns, int hash[lines][columns]);
int fillHash();
void fillHashLetter(int lines, int columns, int hash[lines][columns]);
void display(int lines, int columns, int hash[lines][columns]);
void gameLoop();


int main() { 
    // Main somente para chamar outras funcoes

    whoseTurn = oldWinner == 0? 1: oldWinner;

    gameLoop();

    return 0;
}


// Funcoes abaixo para despoluir o código

void fillHashLetter(int lines, int columns, int hash[lines][columns]) { 
    // Preenche o hash letter com x ou o

    int c, j;
    for (c = 0; c <= 2; c++) { 
        for (j = 0; j <= 2; j++) {
            switch(hash[c][j]) {
                case 1:
                    hashLetter[c][j] = X;
                    break;
                case 2:
                    hashLetter[c][j] = O;
                    break;
            }
        }
    }
}

int winnerVerify(int lines, int columns, int hash[lines][columns]) { 
    // Verificar vencendor 
    int verifiedWinner;

    if ((hash[0][0] == hash[0][1]) && (hash[0][1] == hash[0][2]) && (hash[0][0] != 0)) {
        verifiedWinner = hash[0][0];
    } else if ((hash[1][0] == hash[1][1]) && (hash[1][1] == hash[1][2]) && (hash[1][0] != 0)) {
        verifiedWinner = hash[1][0];
    } else if ((hash[2][0] == hash[2][1]) && (hash[2][1] == hash[2][2]) && (hash[2][0] != 0)) {
        verifiedWinner = hash[2][0];
    } else if ((hash[0][0] == hash[1][0]) && (hash[1][0] == hash[2][0]) && (hash[0][0] != 0)) {
        verifiedWinner = hash[0][0];
    } else if ((hash[0][1] == hash[1][1]) && (hash[1][1] == hash[2][1]) && (hash[0][1] != 0)) {
        verifiedWinner = hash[0][1];
    } else if ((hash[0][2] == hash[1][2]) && (hash[1][2] == hash[2][2]) && (hash[0][2] != 0)) {
        verifiedWinner = hash[0][2];
    } else if ((hash[0][0] == hash[1][1]) && (hash[1][1] == hash[2][2]) && (hash[0][0] != 0)) {
        verifiedWinner = hash[0][0];
    } else if ((hash[0][2] == hash[1][1]) && (hash[1][1] == hash[2][0]) && (hash[0][2] != 0)) {
        verifiedWinner = hash[0][2];
    }     
    else {
        verifiedWinner = 0;
        oldWinner = 1;
    }

    oldWinner = (verifiedWinner != 0)? verifiedWinner: oldWinner;

    return verifiedWinner;
}

int fillHash() { 
    // Preenche o <hash> com 0 ou 1

    int winner = 0;
    int position;
    int valuePosition;
    int verifyPosition;

    while (winner == 0) {
        do {
            verifyPosition = 1;
            printf("Jogador %c, em qual posicao você deseja jogar? ", whoseTurn == 1? X: O);
            scanf("%d", &position);

            switch (position){  // Verifica a posicao referente ao <hash>
                case 1:
                    if (hash[0][0] == 0) {
                        hash[0][0] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 2:
                    if (hash[0][1] == 0) {
                        hash[0][1] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 3:
                    if (hash[0][2] == 0) {
                        hash[0][2] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 4:
                    if (hash[1][0] == 0) {
                        hash[1][0] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 5:
                    if (hash[1][1] == 0) {
                        hash[1][1] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 6:
                    if (hash[1][2] == 0) {
                        hash[1][2] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 7:
                    if (hash[2][0] == 0) {
                        hash[2][0] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 8:
                    if (hash[2][1] == 0) {
                        hash[2][1] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
                case 9:
                    if (hash[2][2] == 0) {
                        hash[2][2] = (whoseTurn == 1)? 1: 2;
                        verifyPosition = 0;
                    }
                    break;
            }

           if (verifyPosition == 0) whoseTurn = (whoseTurn == 1)? 2: 1;
        } while (verifyPosition);

        winner = winnerVerify(3, 3, hash); // Verifica se apos digitar houve vencendor

        display(3, 3, hash); 
    }

    resetHashs();

    return winner;

}

void display(int lines, int columns, int hash[lines][columns]) {
    // Exibe o jogo da velha com os campos preenchidos
    system("clear");
    fillHashLetter(3, 3, hash);

    printf("Quem comeca jogando e: %c\n\n", (oldWinner == 1 || oldWinner == 0)? X: O);

    printf("       |      |      \n");
    printf("       |      |      \n");
    printf("   %c   |  %c   |  %c    \n", hashLetter[0][0], hashLetter[0][1], hashLetter[0][2]);
    printf("       |      |      \n");
    printf(" ______|______|______\n");

    printf("       |      |      \n");
    printf("       |      |      \n");
    printf("   %c   |  %c   |  %c    \n", hashLetter[1][0], hashLetter[1][1], hashLetter[1][2]);
    printf("       |      |      \n");
    printf(" ______|______|______\n");

    printf("       |      |       \n");
    printf("       |      |       \n");
    printf("   %c   |  %c   |  %c    \n", hashLetter[2][0], hashLetter[2][1], hashLetter[2][2]);
    printf("       |      |       \n");
    printf("       |      |       \n");

    printf("\n\n"); 
}


void gameLoop() { 
    // Reinicia o jogo ate quando o usuario quiser
    
    int c = 1;

    do {
        display(3, 3, hash);
        int winnerLoop = fillHash();

        if (winnerLoop == 0) printf("O vencendor é a velha\n");
        else printf("O vencendor é %c\n", (oldWinner == 1)? X: O);

        printf("Gostaria de jogar mais uma vez?\n[1] Sim\n[2] Nao\n");
        
        do {
            scanf("%d", &c);
        } while (c != 1 && c != 2);
    } while (c != 2);
}


void resetHashs() {
    int c, j;

    for (c = 0; c <= 2; c++) { 
        for (j = 0; j <= 2; j++) {
            hash[c][j] = hashCopy[c][j];
            hashLetter[c][j] = hashLetterCopy[c][j];
        }
    }
}

