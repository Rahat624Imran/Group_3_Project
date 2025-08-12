#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 51
#define MAX_USED_LETTERS 27

void print_hangman(int chances_left);
bool print_game_state(char secret_word[], char used_letters[], int num_used);
char get_player_guess(char used_letters[], int num_used);


int main()
{
    char secret_word[MAX_WORD_LENGTH];
    char used_letters[MAX_USED_LETTERS] = {0};
    int num_used_letters = 0;
    int chances_left = 6;
    bool is_word_valid;

    printf("Let's play Hangman!");
    
    while (1)
    {
      is_word_valid = true;
      printf("Player 1, insert the secret word (letters only, max %d characters):\n", MAX_WORD_LENGTH - 1);

    if (fgets(secret_word, MAX_WORD_LENGTH, stdin) != NULL)
    {
        secret_word[strcspn(secret_word, "\n")] = '\0';

        if (strlen(secret_word)== 0)
        {
          printf("Error: Word cannot be empty. Please try again.\n");
          is_word_valid = false;
        }
        else
        {
          for (int i = 0; secret_word[i] != '\0'; i++)
        {

            if (!isalpha(secret_word[i]))
            {
                printf("Error:Only alphabets allowed. Please try again. \n");
                is_word_valid = false;

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
    
    

    while (chances_left > 0)
    {
        print_hangman(chances_left);
        bool word_is_guessed = print_game_state(secret_word, used_letters, num_used_letters);

       
        if (word_is_guessed)
        {
            printf("\nCongratulations, You Win!\n");
            break; 
        }

        
        char guess = get_player_guess(used_letters, num_used_letters);

      
        used_letters[num_used_letters] = guess;
        num_used_letters++;

       
        bool found_in_word = false;
        for (int i = 0; secret_word[i] != '\0'; i++) {
            if (tolower(secret_word[i]) == guess) {
                found_in_word = true;
                break;
            }
        }

        
        if (found_in_word)
        {
            printf("\nGood guess!\n");
        }
        else
        {
            printf("\nSorry, '%c' is not in the word.\n", guess);
            chances_left--; 
        }
    }

    
    if (chances_left == 0)
    {
        print_hangman(chances_left); 
        printf("\nGame Over! You ran out of chances.\n");
        printf("The word was: %s\n", secret_word);
    }

    
}

void print_hangman(int chances_left)
{
    printf("\n--- Hangman ---\n");
    printf("  +---+\n");
    printf("  |   |\n");

    if (chances_left <= 5)
    {
        printf("  O   |\n");
    } else
    {
        printf("      |\n");
    }

    
    if (chances_left <= 2)
    {
        printf(" /|\\  |\n");
    } else if (chances_left <= 3) 
    {
        printf(" /|   |\n");
    } else if (chances_left <= 4)
    {
        printf("  |   |\n");
    } else
    {
        printf("      |\n");
    }

    
    if (chances_left <= 0) 
    {
        printf(" / \\  |\n");
    } else if (chances_left <= 1)
    {
        printf(" /    |\n");
    } else
    {
        printf("      |\n");
    }

    printf("      |\n");
    printf("=========\n");
    printf("Chances Left: %d\n", chances_left);
}
    
bool print_game_state(char secret_word[], char used_letters[], int num_used)
{
    bool all_revealed = 1;

    printf("Word: ");
      for (int i = 0; secret_word[i] != '\0'; i++)
      {
        bool match_found = 0;
        for (int j = 0; j < num_used; j++)
        {
          if (tolower(secret_word[i])== used_letters[j])
          {
            match_found = 1;
              break;
          }
        }
        if (match_found)
        {
          printf("%c ", secret_word[i]);
        }
        else
        {
          printf("_ ");
          all_revealed = 0;
        }
}

    printf("\n");

    printf("Used Letters: ");
    if(num_used == 0)
    {
        printf("None");
    }
    else
    {
        for(int i = 0; i<num_used; i++)
            {
                printf("%c ", toupper(used_letters[i]));
            }
    }
    printf("\n");

    return all_revealed;

}
char get_player_guess(char used_letters[],int num_used)
{
    int c;
    char guess;
    bool is_new_valid_guess=false;
    while(!is_new_valid_guess)
    {
        printf("Enter your guess: ");
        if(scanf(" %c", &guess)!= 1)
        {
            while(c = getchar() != '\n' && c != EOF);
            printf("Invalid input format.Please try again.\n");
            continue;
            
        }
        while(c = getchar() != '\n' && c != EOF);
        if(!isalpha(guess))
        {
            printf("That's not a letter.Please try again.\n");
            continue;
         }
                
        guess = tolower(guess);
        
        bool already_used = false;    
        for(int i = 0;i < num_used; i++)
        {
            if(used_letters[i] == guess)
            {
                already_used = true;
                break;
            }
        }
        if (already_used)
        {
            printf("You already guessed '%c'.Try another letter.\n",guess);
        }
        else
        {
            is_new_valid_guess = true;
        }
           
      
}
    return guess;  
}








