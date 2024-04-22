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


char X = 'x';  // Possibilidade de escolher outros caracteres para o jogador 1 e 2
char O = 'o';
int oldWinner = 0;
int whoseTurn = 1;



// Declaracao das funcoes
void resetHashs();
int winnerVerify(int lines, int columns, int hash[lines][columns]);
int checkFilledPositions();
int fillHash();
void fillHashLetter(int lines, int columns, int hash[lines][columns]);
void display(int lines, int columns, int hash[lines][columns]);
void gameLoop();


int main() { 
    // Main somente para chamar outras funcoes

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
    } else {
        verifiedWinner = 0;
        oldWinner = 0;
    }

    oldWinner = (verifiedWinner != 0)? verifiedWinner: oldWinner;

    return verifiedWinner;
}

int fillHash() { 
    // Preenche o <hash> com 0 ou 1

    int winner = 0;
    int position;
    int verifyPosition;
    int chechedFilledPositions;

    do {
        do { // Pede pro usuário escolher uma posicao valida da velha
            verifyPosition = 1;
            printf("Jogador %c, em qual posicao você deseja jogar? ", (whoseTurn == 1)? X: O);
            scanf("%d", &position);

            switch (position) {  // Verifica a posicao referente ao <hash>
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
                default:
                    printf("\nDigite um número de 1 a 9 e que nao esteja preenchido!!\n");
                    break;
            } 
        } while (verifyPosition);

            display(3, 3, hash); 

            winner = winnerVerify(3, 3, hash); // Verifica se apos digitar houve vencendor

            if (checkFilledPositions()) { // Verifica se tudo foi preenchido e mesmoa assim nao houve vencedor (Velha)
                break;
            } 

            whoseTurn = (whoseTurn == 1)? 2: 1;
    } while (winner == 0); // (!(!(winner != 0) && checkFilledPositions()))

    whoseTurn = (winner == 0)? 1: winner; // Coloca o vencendor como sendo o proximo a jogar caso se inicie uma nova partida

    resetHashs();

    return winner;

}

void display(int lines, int columns, int hash[lines][columns]) {
    // Exibe o jogo da velha com os campos preenchidos
    system("clear");
    fillHashLetter(3, 3, hash);

    printf("Quem joga e: %c\n\n", (oldWinner == 1 || oldWinner == 0)? X: O);

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
    // Reinicia o jogo ate quando o usuario quiser (loop inicial)
    
    int c = 1;
    int newCharacters = 2;

    do {
        printf("Gostaria de escolher caracteres para cada jogador?\n[1] Sim\n[2] Nao\n");
        scanf("%d", &newCharacters);
    } while (newCharacters > 2 || newCharacters < 1);
    

    if (newCharacters == 1) {
        printf("Qual o caractere do 1? \n");
        scanf(" %c", &X);

        printf("Qual o caractere do 2? \n");
        scanf(" %c", &O);
    }


    do {
        system("clear");
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


void resetHashs() { // Reseta as matrizes para que o usuario possa jogar novamente
    int c, j;

    for (c = 0; c <= 2; c++) { 
        for (j = 0; j <= 2; j++) {
            hash[c][j] = hashCopy[c][j];
            hashLetter[c][j] = hashLetterCopy[c][j];
        }
    }
}

int checkFilledPositions() {
    int c, j;

    for (c = 0; c <= 2; c++) { 
        for (j = 0; j <= 2; j++) {
            if (hash[c][j] != 1 && hash[c][j] != 2) {
                return 0;
            }
        }
    }

    return 1;
}

