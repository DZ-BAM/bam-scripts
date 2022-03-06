/*
 * Trader world building.
 */
#ifndef DZBAM_TRADER
#define DZBAM_TRADER
#include "$CurrentDir:\\bam-scripts\\worldbuilder.c"

const string TRADER_OBJECTS = "$profile:\\dzbam_traderobjects.json";

void DZBAM_CreateTraderObjects()
{
        DZBAM_CreateObjects(TRADER_OBJECTS);
}

#endif
