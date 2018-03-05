#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main(int argc, char** argv) {
	struct gameState G;
	int v = 0;

	int k[10] = { smithy,village,  sea_hag, outpost, adventurer, baron,tribute, cutpurse, embargo };
	printf("Unitest for getCost\n");

	v = initializeGame(2, k, 9, &G);

	assert(v == 0);
	v = getCost(curse);
	if (v != 0) {
		printf("\t There is wrong at getCost for curse card \n");
		return 1;
	}
	else
		printf("\t curse card pass\n");
	v = getCost(cutpurse);
	if (v != 4) {
		printf("\t There is wrong at getCost for cutpurse card \n");
		return 1;
	}
	else
		printf("\t cutpurse card pass\n");

	v = getCost(sea_hag);
	if (v != 4) {
		printf("\t There is wrong at getCost for sea_hag card \n");
		return 1;
	}
	else
		printf("\t sea_hag card pass\n");
	v = getCost(smithy);
	if (v != 4) {
		printf("\t There is wrong at getCost for smithy card \n");
		return 1;
	}
	else
		printf("\t smithy card pass\n");

	v = getCost(estate);
	if (v != 2) {
		printf("\t There is wrong at getCost for estate card\n");
		return 1;
	}
	else
		printf("\t estate card pass\n");
	v = getCost(adventurer);
	if (v != 6) {
		printf("\tThere is wrong at getCost for adventurer card\n");
		return 1;
	}
	else
		printf("\t adventurer card pass\n");
	v = getCost(duchy);
	if (v != 5) {
		printf("\tThere is wrong at getCost for duchy card\n");
		return 1;
	}
	else
		printf("\t duchy card pass\n");
	v = getCost(province);
	if (v != 8) {
		printf("\tThere is wrong at getCost for province card\n");
		return 1;
	}
	else
		printf("\t province card pass\n");

	v = getCost(gardens);
	if (v != 4) {
		printf("\tThere is wrong at getCost for gardens card\n");
		return 1;
	}
	else
		printf("\t gardens card pass\n");

	return 0;
}