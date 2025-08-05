#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 51
#define MAX_LETTER 27

void print_hangman(int chances_left);

bool print_game_state(char secret_word[], char used_letters[], int num_used);

char get_player_guess(char used_letters[], int num_used);
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

    

           if (all_revealed == 1)
      {
        printf("Congratulations, You win!\n");
        break;
      }


      }

void print_hangman(int chances_left)
{
    printf("\n--- Hangman ---\n");
    printf("  +---+\n");
    printf("  |   |\n");

    if (chances_left <= 5) {
        printf("  O   |\n");
    } else {
        printf("      |\n");
    }

    
    if (chances_left <= 2) {
        printf(" /|\\  |\n");
    } else if (chances_left <= 3) {
        printf(" /|   |\n");
    } else if (chances_left <= 4) {
        printf("  |   |\n");
    } else {
        printf("      |\n");
    }

    
    if (chances_left <= 0) {
        printf(" / \\  |\n");
    } else if (chances_left <= 1) {
        printf(" /    |\n");
    } else {
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
          if (secret_word[i]== used_letters[j])
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
    char guess ;
    bool is_new_valid_guess=false;
    while(!is_new_valid_guess){
    printf("Enter your guess: ");
    if(scanf(" %c", &guess)!= 1){
        while(getchar() != '\n' && getchar() != EOF);
        printf("Invalid input format.Please try again.\n");
        continue;
    }
     while(getchar() != '\n' && getchar() != EOF);
    if(!isalpha(guess)){
     printf("That's not a letter.Please try again.\n");
     continue;
    }
        
    guess = tolower(guess);

    bool already_used = false;    
    for(int i = 0;i < num_used; i++){
        if(used_letters[i] == guess){
        already_used = true;
        break;
        }
    }
    if (already_used)
    {
        printf("You already guessed '%c'.Try another letter.\n",guess);
    }else
      {
        is_new_valid_guess = true;
      }
    }   
return guess;    
}






