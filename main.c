#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 51
#define MAX_LETTER 27


int main()
{
    int is_word_valid;
    char word[MAX];


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


}
