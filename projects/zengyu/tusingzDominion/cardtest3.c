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

  printf("Adventurer card test result\n");
  struct gameState G;
  int k[9] = { smithy,village,  feast, outpost, adventurer, baron,tribute, cutpurse, embargo };
  initializeGame(2, k, 9, &G);

  G.whoseTurn = 1;
  G.hand[1][0] = adventurer;
  int handCount = G.handCount[1];
  int deckCount = G.deckCount[1];
  int playedCount = G.playedCardCount;
	
  myAssert(G.handCount[1] == handCount + 1, "Adventurer did not add 2 cards for player");
  myAssert(G.deckCount[1] == deckCount - 1, "Adventurer changes wrong amount cards in deck");



}