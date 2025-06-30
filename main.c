#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 51
#define MAX_LETTER 27


int main()
{
    int is_word_valid;
    char word[MAX];

    printf("Let's play Hangman!");
    printf("Choose who you would like to be Player 1 and Player 2");
    while (1)
    {
      is_word_valid = 1;
      printf("Player 1, insert the secret word (letters only, max %d characters):\n", MAX - 1);

    if (fgets(word, MAX, stdin) != NULL)
    {
        word[strcspn(word, "\n")] = '\0';

        if (strlen(word)== 0)
        {
          printf("Error: Word cannot be empty. Please try again.\n");
          is_word_valid = 0;
        }
        else
        {
          for (int i = 0; word[i] != '\0'; i++)
        {

            if (!isalpha(word[i]))
            {
                printf("Error:Only alphabets allowed. Please try again. \n");
                is_word_valid = 0;

            }

        }
        }
        if (is_word_valid)
            {
              break;
            }


    }


    }
    for (int i=0; i<50; i++)
        {
        printf("\n");
        }
    printf("Word to guess: ");
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("_ ");
    }
    printf("\n");


}
