#include <stdio.h> 
#include <string.h>
#include "main.h"

void print_game_intro()
{
    printf("========================================\n");
    printf("WELCOME TO MADLIBS\n");
    printf("========================================\n\n");
}

void print_story(char adjective_one[64], char noun[64], char adjective_two[64], char verb[64], char adjective_three[64])
{
    printf("========================================\n");
    printf("The Madlib Story:\n");
    printf("========================================\n");
    printf("\nToday, I went to a %s zoo. \n", adjective_one);
    printf("In an exhibit, I saw a %s.\n", noun);
    printf("The %s was %s and %s!\n", noun, adjective_two, verb);
    printf("I was %s!\n\n", adjective_three);
    printf("========================================\n");
}

int main(int argc, char const *argv[])
{
    print_game_intro();

    char adjective_one[64] = "";
    printf("Type an adjective about a location (description): ");
    fgets(adjective_one, sizeof(adjective_one), stdin);
    adjective_one[strlen(adjective_one) - 1] = '\0'; // removes whitespace end
    
    char noun[64] = "";
    printf("Type a noun (animal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';
    
    char adjective_two[64] = "";
    printf("Type an adjective about the %s (description): ", noun);
    fgets(adjective_two, sizeof(adjective_two), stdin);
    adjective_two[strlen(adjective_two) - 1] = '\0';
    
    char verb[64] = "";
    printf("Type a verb (ending with -ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) - 1] = '\0';
    
    char adjective_three[64] = "";
    printf("Type an adjective about an experience (description): ");
    fgets(adjective_three, sizeof(adjective_three), stdin);
    adjective_three[strlen(adjective_three) - 1] = '\0';

    print_story(adjective_one, noun, adjective_two, verb, adjective_three);

    return 0;
}


