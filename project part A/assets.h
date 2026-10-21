#ifndef ASSETS_H
#define ASSETS_H
#include <stdio.h>
#include <string.h>
#define MAX_ASSETS 100
/* Variables */
extern int asset_start;
extern int asset_end;
extern int asset_count;
extern char asset_id[MAX_ASSETS][20];
extern char asset_name[MAX_ASSETS][50];
extern char asset_type[MAX_ASSETS][50];
extern char asset_department[MAX_ASSETS][50];
extern char asset_condition[MAX_ASSETS][30];
extern float purchase_value[MAX_ASSETS];
/* Menu */
void AssetMenu();
/* CRUD */
void AddAsset(void);
void DisplayAsset(void);
void SearchAsset(void);
void UpdateAsset(void);
void DeleteAsset(void);
/* Display */
void PrintAsset(int index);
/* Validation */
int ValidateAssetID(char id[]);
int ValidateAssetName(char name[]);
/* Selection */
void SelectAssetType(char assets_type[]);
void SelectAssetCondition(char assets_condition[]);
void SelectAssetDepartment(char assets_department[]);
#endif
