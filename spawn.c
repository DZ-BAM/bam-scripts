#ifndef BAM_SPAWN
#define BAM_SPAWN

#ifndef BAM_CLOTHING
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/clothing.c"
#endif

#ifndef BAM_INVENTORY
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/inventory.c"
#endif

const ref BAM_Clothing CLOTHING = new BAM_Clothing(
	"ChernarusSportShirt",
	"SlacksPants_Beige",
	"WorkingBoots_Yellow",
	"",
	"",
	"",
);
const ref BAM_Inventory INVENTORY = new BAM_Inventory(
	{},
	{
		{
			"Chemlight_White",
			"Chemlight_Yellow",
			"Chemlight_Green",
			"Chemlight_Red",
		},
		{"Apple", "Pear", "Plum"},
	},
	BAM_quantizedItems(),
	{},
);

ref map<string, int> BAM_quantizedItems() {
	auto items = new map<string, int>();
	items["Rag"] = 4;
	return items;
}

void BAM_SetStartingEquipment(PlayerBase player) {
	CLOTHING.applyToPlayer(player);
	INVENTORY.addToPlayer(player);
}

#endif