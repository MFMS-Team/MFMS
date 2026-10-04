#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define TYPE_COUNT 6
#define CONDITION_COUNT 4

/* Parallel arrays: the same index belongs to the same asset.
   They are declared here with extern and created once in assets.c. */
extern int asset_count;
extern char asset_id[MAX_ASSETS][20];
extern char asset_name[MAX_ASSETS][50];
extern char asset_type[MAX_ASSETS][50];
extern char asset_department[MAX_ASSETS][50];
extern char asset_condition[MAX_ASSETS][30];
extern float purchase_value[MAX_ASSETS];

/* The choices offered in the menus (also used by the reports) */
extern char type_list[TYPE_COUNT][20];
extern char condition_list[CONDITION_COUNT][20];

/* Menu */
void assetMenu(void);

/* CRUD Operations */
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void updateAsset(void);
void deleteAsset(void);

/* Display */
void displayAssetDetails(int position);

/* Validation */
int validateAssetId(char id[]);
int validateAssetName(char name[]);
int validateAssetType(char type[]);
float validatePurchaseValue(float value);

/* Selection Functions */
void selectAssetType(char type[]);
void selectAssetDepartment(char department[]);
void selectAssetCondition(char condition[]);

#endif
