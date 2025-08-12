~~~

 ___  ___  ________  ________   ________  _____ ______   ________  ________      
|\  \|\  \|\   __  \|\   ___  \|\   ____\|\   _ \  _   \|\   __  \|\   ___  \    
\ \  \\\  \ \  \|\  \ \  \\ \  \ \  \___|\ \  \\\__\ \  \ \  \|\  \ \  \\ \  \   
 \ \   __  \ \   __  \ \  \\ \  \ \  \  __\ \  \\|__| \  \ \   __  \ \  \\ \  \  
  \ \  \ \  \ \  \ \  \ \  \\ \  \ \  \|\  \ \  \    \ \  \ \  \ \  \ \  \\ \  \ 
   \ \__\ \__\ \__\ \__\ \__\\ \__\ \_______\ \__\    \ \__\ \__\ \__\ \__\\ \__\
    \|__|\|__|\|__|\|__|\|__| \|__|\|_______|\|__|     \|__|\|__|\|__|\|__| \|__|
                                                                                 
~~~




Our project is a console-based version of the Hangman game that is implemented in the C language.

Within a limited number of attempts, the player tries to guess a secret word by suggesting letters.

The correctly guessed letters are displayed, whereas the mistakes cause a change in the hangman figure.



Features of the program:

* The current state of the word is displayed.
* The frequency of attempts and previous attempts are all recorded and displayed.
* The hangman figure is visualized using ASCII art.
* Input of repeated or wrong guesses are validated accordingly.


How to run it?

Clone or download this repository:
```bash
git clone https://github.com/Rahat624Imran/Group_3_Project.git
cd Group_3_Project
```

Compile the program:
```bash
gcc main.c -o hangman
```
