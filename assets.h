#ifndef ASSETS_H
#define ASSETS_H

#include "structures.h"

/* ======================================================================
   ASSET MANAGEMENT MODULE — Municipal Financial Management System
   ======================================================================
   Provides a basic asset register: add, display, and search assets by
   ID or by name. Condition is restricted to "Good", "Fair", or "Poor"
   so Reports can reliably tally assets by condition.
   ====================================================================== */

/* Entry point called from the main menu's "4. Asset Management" option. */
void assetMenu(Asset assets[], int *count, int maxSize);

/* Core operations */
int  addAsset(Asset assets[], int *count, int maxSize);
void displayAssets(Asset assets[], int count);
void searchAssetMenu(Asset assets[], int count);

/* Lookups, exposed so other modules (e.g. Reports) can reuse them. */
int  findAssetIndexByID(Asset assets[], int count, int id);
int  findAssetIndexByName(Asset assets[], int count, const char *name);

#endif /* ASSETS_H */
