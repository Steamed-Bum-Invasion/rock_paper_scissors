static int player_total = 0;
static int computer_total = 0;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
  ROCK = 0,
  PAPER = 1,
  SCISSORS = 2,
} hands;

void who_won(hands player_hand, hands computer_hand) {

  switch (player_hand - computer_hand) {
  case 0:
    printf("tie! the score is player:%d computer:%d\n", player_total,
           computer_total);
    break;

  case 1:
    printf("player won! the score is player:%d computer:%d\n", player_total,
           computer_total);
    player_total++;
    break;

  case -1:
    printf("bot won! the score is player:%d computer:%d\n", player_total,
           computer_total);
    computer_total++;
    break;

  case 2:
    printf("bot won! the score is player:%d computer:%d\n", player_total,
           computer_total);
    break;

  case -2:
    printf("player won! the score is player:%d computer:%d\n", player_total,
           computer_total);
    break;
    player_total++;
    break;

  default:
    break;
  }
}

const char *hand_to_string(hands hand) {
  switch (hand) {
  case ROCK:
    return "ROCK";
  case PAPER:
    return "PAPER";
  case SCISSORS:
    return "SCISSORS";
  default:
    return "UNKNOWN"; // In case of an invalid value
  }
}

int main(int argc, char const *argv[]) {

  srand(time(NULL));

  printf("Do you want to play rock paper scissors with me? type 'y' if yes, "
         "and 'n' if no!\n");

  char decision_to_play = getchar();
  while ((getchar()) != '\n')
    ;

  // getchar();

  if (decision_to_play == 'y') {
    // gameplay loop
    while (1) {
      printf("what hand do you choose?\n");

      char chosen_hand = getchar();
      while ((getchar()) != '\n')
        ;

      while (chosen_hand != 'r' && chosen_hand != 'p' && chosen_hand != 's') {

        printf("invalid hand!\n");
        chosen_hand = getchar();
        while ((getchar()) != '\n')
          ;
      }

      hands player_hand;

      switch (chosen_hand) {
      case 'r':
        player_hand = ROCK;
        break;

      case 'p':
        player_hand = PAPER;
        break;

      case 's':
        player_hand = SCISSORS;
        break;

      default:
        break;
      }

      hands computer_hand =
          0 + rand() % (2 - 0 + 1); // random number in range [0,2]

      printf("your hand is: %s, computer hand is: %s\n",
             hand_to_string(player_hand), hand_to_string(computer_hand));
      who_won(player_hand, computer_hand);

      printf("Do you still want to play? Press 'y' for yes and 'n' for no\n");

      // Read the user's decision to continue playing
      char continue_game = getchar();
      while ((getchar()) != '\n')
        ; // Consume the newline after entering the decision

      if (continue_game == 'y') {
        printf("Okay then, let's go!\n");
      }

      else if (continue_game == 'n') {
        printf("final score player: %d, computer: %d\n", player_total,
               computer_total);
        // printf("Okay then, bye!\n");
        return EXIT_SUCCESS; // Exit the program
      }
    }
  }
}
