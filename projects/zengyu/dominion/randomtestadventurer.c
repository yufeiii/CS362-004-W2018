/*
* Function: randomtestadventurer for testing play_adventurer
* Function: Draw cards from deck until you get 2 treasure cards and discard the other drawn cards.
* Introduce bug: initialize drawntreasure as 1 and draw only 1 treasure card.
* Output: Output should be the test didnt pass due to the introduce bug in dominion.c
*/
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define RUNS 50

int main() {

	  int k[10] = { council_room, smithy, great_hall, ambassador, adventurer, remodel, village, feast, gardens, mine };

	  int seed;
	  int ps;
	  int p;
	  int handCount;
	  int numActions; 
	  int check_act;
	  int deckCount;
	  struct gameState g;
	  int i;
	  for (i = 0; i < RUNS; i++) {
			ps = (rand() % 4) + 1;
	 		p = rand() % ps;
	 		numActions = (rand() % 25) + 1;

			seed = rand();		
	 		initializeGame(ps, k, seed, &g);	

	 		g.deckCount[p] = rand() % MAX_DECK; 
	 		g.discardCount[p] = rand() % MAX_DECK;
	 		g.handCount[p] = rand() % MAX_HAND;
	 		g.numPlayers = ps;
	 		g.whoseTurn = p;
	 		g.numActions = numActions;

			handCount = g.handCount[p];
			//check_act = g.numActions;
			deckCount = g.deckCount[p];
			cardEffect((adventurer), 0, 0, 0, &g, 0, 0);
			handCount += 2;

			if(handCount == g.handCount[p])
				printf("The test pass!\n");
			else
				printf("The test didnt pass\n");


	  }

	  return 0;
}