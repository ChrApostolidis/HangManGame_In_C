#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>


// #define MAX_T 5
#define LISZ 100
#define RISZ 20
#define CLEARSCREEN system ( "cls" )
char words[LISZ][RISZ];

void loadData() {
    int i =0;

    FILE *fptr;

    if((fptr=fopen("../ListofWords.txt","r"))==NULL)
    {
        printf("De mporo na anoikso to arxeio");
        exit(1);
    }
    while (fgets(words[i], RISZ, fptr))
    {
        words[i][strlen(words[i]) - 1] = '\0';
        i++;
    }

    printf("\nThe content of the file are:\n");
    for(i = 0; i< LISZ; i++)
    {
        printf("%s\n", words[i]);
    }
    printf("\n");
};

void printHangman(int attempts, const char *difficulty) {
    if (strcmp(difficulty, "easy") == 0) {
        switch (attempts) {
            case 1:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |           \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 2:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |   |       \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 3:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|       \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 4:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 5:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |  /        \n");
                printf("-------------\n");
                break;
            case 6:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |  / \\      \n");
                printf("-------------\n");
                printf("GAME OVER! The hangman is complete.\n");
                break;
        }
    } else if (strcmp(difficulty, "medium") == 0) {
        switch (attempts) {
            case 1:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |           \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 2:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |   |       \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 3:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 4:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |  /     \n");
                printf("-------------\n");
                break;
            case 5:
                printf("-------------\n");
            printf("  ____       \n");
            printf(" |   |       \n");
            printf(" |   O       \n");
            printf(" |  /|\\      \n");
            printf(" |  / \\      \n");
            printf("-------------\n");
            printf("GAME OVER! The hangman is complete.\n");
            break;
        }
    } else if (strcmp(difficulty, "hard") == 0) {
        switch (attempts) {
            case 1:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |           \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 2:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |   |       \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 3:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |           \n");
                printf("-------------\n");
                break;
            case 4:
                printf("-------------\n");
                printf("  ____       \n");
                printf(" |   |       \n");
                printf(" |   O       \n");
                printf(" |  /|\\      \n");
                printf(" |  / \\      \n");
                printf("-------------\n");
                printf("GAME OVER! The hangman is complete.\n");
                break;
        }
    }
}

// Function to check if the input is a valid number
int isValidNumber(const char *input) {
    for (size_t i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            return 0; // Not a valid number
        }
    }
    return 1;
}

int menu(char *difficulty) {
    char input[100];
    int choice;

    do {
        printf("Welcome to the kremela!! \tDifficulty:%s\n",difficulty);
        printf("1.Play Game\n2.Play AI\n3.Options\n0.Exit game\n");
        printf("Please Select:");
        if (fgets(input, sizeof(input), stdin)) {
            // Remove trailing newline, if any
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
            }

            // Validate input format before conversion
            if (isValidNumber(input)) {
                choice = atoi(input); // Convert to integer

                // Check if the choice is within the valid range
                if (choice < 0 || choice > 3) {
                    printf("Invalid input. Please enter 0, 1, 2, or 3.\n");
                }
            } else {
                printf("Invalid input. Please enter a number (0, 1, 2, or 3).\n");
            }
        }
    } while ((choice < 0 || choice > 3));

    return choice;
}

char playAI() {
    char weightedLetters[] = "eeeeeeeeeeeeeeeeeeeeeeeeettttttttttttttaaaaaaaaaaaooooooooooiiiiiiiinnnnnnnnsssssssshhhhhhhrrrrrrrddddddlllllllcccccuuuuuuummmmmwwwwfffgpybvkjxqz";

    int randomIndex = rand() % (sizeof(weightedLetters) - 1);

    return weightedLetters[randomIndex];
}



int main(){
    srand(time(NULL));
    loadData();
    char word[20];
    int choose;
    int maxTries = 5;
    char *difficultyOfGame = "medium";


    do  {
    choose = menu(difficultyOfGame);
    int value = rand() % LISZ;

    strcpy(word,words[value]);

    int wordLength = strlen(word);
    char guessedW[wordLength+1];
    char guessedL[30] = {0};
    int tries = 0;
    int correctG = 0;
    int i,wrong = 0;

    switch(choose) {
     case 1:
        // printf("%s\n", word);
        for (i = 0; i<wordLength; i++) {
            guessedW[i] = '_';
        }
            guessedW[wordLength] = '\0';

        while (tries < maxTries && correctG < wordLength) {
            char inputGuess[50];
            char guess;
            int correct = 0;

            printf("\nWord: %s\n", guessedW);
            printf("Guesses left: %d\n", maxTries - tries);
            printf("Guessed letters: %s\n", guessedL);

            // Get the player guess
            printf("Enter a letter: ");
            // scanf(" %c", &guess);
            fgets(inputGuess, sizeof(inputGuess), stdin);

            // Remove trailing newline, if any
            size_t len = strlen(inputGuess);
            if (len > 0 && inputGuess[len - 1] == '\n') {
                inputGuess[len - 1] = '\0';
            }
            // Taking the first Character of the guess
            guess = tolower(inputGuess[0]);

            // Check if the letter was already guessed
            if (strchr(guessedL, guess)) {
                printf("You've already guessed that letter\n");
                continue;
            }

            // add the guess to the guessed letters list
            strncat(guessedL, &guess, 1);

            // Check if the guess is in the word
            for (i = 0; i < wordLength; i++) {
                if (word[i] == guess && guessedW[i] != guess) {
                PlaySound("../correct.wav", NULL,SND_SYNC| SND_LOOP| SND_FILENAME);
                guessedW[i] = guess;
                correctG++;
                correct = 1;
                }
            }

            if (!correct) {
                printf("Wrong guess!\n");
                wrong++;
                printHangman(wrong, difficultyOfGame);
                PlaySound("../wrong.wav", NULL,SND_SYNC| SND_LOOP| SND_FILENAME);
                tries++;
            }
        }

        // check if the player won or lost
        if (correctG == wordLength) {
            printf("\nBravo! You found the word: %s\n", word);
        } else {
            printf("\nNo more ties! The word was: %s\n", word);
        }
        break;

        case 2:
             printf("%s\n", word);
        for (i = 0; i<wordLength; i++) {
            guessedW[i] = '_';
        }
            guessedW[wordLength] = '\0';

        while (tries < maxTries && correctG < wordLength) {
            char inputGuess[50];
            char guess;
            int correct = 0;

            printf("\nWord: %s\n", guessedW);
            printf("Guesses left: %d\n", maxTries - tries);
            printf("Guessed letters: %s\n", guessedL);

            // Get the player guess
            printf("Enter a letter: ");
            do {
                guess = playAI();
            }while(strchr(guessedL, guess));
            printf("%c\n",guess );

            // add the guess to the guessed letters list
            strncat(guessedL, &guess, 1);

            // Check if the guess is in the word
            for (i = 0; i < wordLength; i++) {
                if (word[i] == guess && guessedW[i] != guess) {
                PlaySound("../correct.wav", NULL,SND_SYNC| SND_LOOP| SND_FILENAME);
                guessedW[i] = guess;
                correctG++;
                correct = 1;
                }
            }

            if (!correct) {
                printf("Wrong guess!\n");
                wrong++;
                printHangman(wrong, difficultyOfGame);
                PlaySound("../wrong.wav", NULL,SND_SYNC| SND_LOOP| SND_FILENAME);
                tries++;
            }
        }

        // check if the player won or lost
        if (correctG == wordLength) {
            printf("\nBravo! You found the word: %s\n", word);
        } else {
            printf("\nNo more ties! The word was: %s\n", word);
        }
        break;

        case 3:
            char selectedOption[100];
            do {

                // Clear the input buffer after scanf in the menu
                // while (getchar() != '\n');

                printf("Options:\n");
                printf("Current Difficulty: %s\n",difficultyOfGame);
                printf("------------------------\n");
                printf(" Level easy(tries:6)\n Level medium(tries:5)\n Level hard(tries:4)\n");
                printf("------------------------\n");
                printf("Exit to Menu(exit)\n");
                printf("Please Select:");

                // Getting Users Choice
                fgets(selectedOption, sizeof(selectedOption), stdin);

                // Remove the newline character from the input
                size_t len = strlen(selectedOption);
                if (len > 0 && selectedOption[len - 1] == '\n') {
                    selectedOption[len - 1] = '\0';
                }

                if (strcmp(selectedOption, "easy") == 0) {
                    difficultyOfGame = "easy";
                    maxTries = 6;
                    printf("Difficulty changed to easy!!\n");
                    // break;
                } else if (strcmp(selectedOption, "hard") == 0) {
                    difficultyOfGame = "hard";
                    maxTries = 4;
                    printf("Difficulty changed to hard!!\n");
                    // break;
                } else if (strcmp(selectedOption, "medium") == 0) {
                    difficultyOfGame = "medium";
                    maxTries = 5;
                    printf("Difficulty changed to medium!!\n");
                    // break;
                } else if (strcmp(selectedOption, "exit") != 0) {
                    printf("\nInvalid choice! Please select a valid option.\n");
                }

                // printf("Selected Difficulty: %s", selectedOption);
            } while  (strcmp(selectedOption, "exit") != 0); // checks if the string are equally and returns 0 if they are equal
        break;
        }

    }
     while (choose != 0);
     printf("Exiting Game...");

    return 0;
}
