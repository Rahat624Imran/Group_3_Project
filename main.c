#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 51
#define MAX_LETTER 27


int main()
{
    int is_word_valid;
    char word[MAX];
    int chances = 6;
    char used_word;
    char used_letter[MAX_LETTER];
    char letter;
    int count = 0;
    int guess_letter = 0;
    int found = 0;
    int chance = 6;
    int correct_guess = 0;
    int all_revealed = 0;
    int match;

    printf("Let's play Hangman!");
    
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

    while (1)
    {
    printf("Enter a letter: ");
    scanf(" %c", &letter);
    guess_letter = 0;

    for (int i = 0; i<count; i++)
        {
            if (used_letter[i] == tolower(letter))
            {
                guess_letter = 1;
            }
        }
    if (guess_letter == 1)
    {
        printf("You have already guessed used this letter!\n");
    }
    else
      {
        used_letter[count] = tolower(letter);
        count+= 1;
      }
    found = 0;
      for (int i = 0; word[i] != '\0'; i++)
      {

        if (tolower(letter) == tolower(word[i]))
        {
          found = 1;
          break;
        }

      }
        if(found == 0) 
    {
        chance --;
        printf("The letter you guessed is incorrect! You have %d chances left. \n", chance);
    }

    if(chance == 0)
    {
        printf("Game Over");
        break;
    }
        
   }

    all_revealed = 1;
      for (int i = 0; word[i] != '\0'; i++)
      {
        match = 0;
        for (int j = 0; j < count; j++)
        {
          if (word[i]== used_letter[j])
          {
            match = 1;
          }
        }
        if (match == 1)
        {
          printf("%c ", word[i]);
        }
        else
        {
          printf("_ ");
          all_revealed = 0;
        }

           if (all_revealed == 1)
      {
        printf("Congratulations, You win!\n");
        break;
      }


      }


    


}





