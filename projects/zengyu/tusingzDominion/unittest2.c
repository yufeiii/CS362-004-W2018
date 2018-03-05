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

  printf("Smithy card test result\n");
  struct gameState G;
  int k[9] = { smithy,village,  feast, outpost, adventurer, baron,tribute, cutpurse, embargo };
  initializeGame(2, k, 9, &G);

  G.whoseTurn = 1;
  G.hand[1][0] = smithy;
  int handCount = G.handCount[1];
	
  myAssert(G.handCount[1] == handCount + 2, "Smithy adds wrong number card for player");




}