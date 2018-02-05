#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>


int myAssert(int test, char* msg) {
  if (!test) {
    printf ("Aseert failed: %s\n", msg);
    if (0) {
      exit(1);
    }
  }
  return 0;
}

int main() {

  printf("Villag card test result:\n");

  struct gameState G;
  int k[9] = {smithy,village,  feast, outpost, adventurer, baron,tribute, cutpurse, embargo};

  initializeGame(2, k, 9, &G);

  G.whoseTurn = 1;
  G.hand[1][0] = village;
  int handCount = G.handCount[1];
  int numActions = G.numActions;
  int deckCount = G.deckCount[1];
  int playedCount = G.playedCardCount;
  playCard(0, 0, 0, 0, &G);

  myAssert(G.handCount[1] == handCount, "Village adds wrong number card for player");
  myAssert(G.deckCount[1] == deckCount - 1, "Village changes wrong number card on deck");
  myAssert(G.playedCardCount == playedCount + 1, "There are wrong amount play cards");
  myAssert(G.numActions == numActions + 1, "Village adds wrong number of action for players");

}