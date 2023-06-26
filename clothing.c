#ifndef BAM_CLOTHING
#define BAM_CLOTHING

class BAM_Clothing {
    string top;
    string pants;
    string shoes;
    string backpack;
    string helmet;
    string hands;

    void BAM_Clothing(
            string top,
            string pants,
            string shoes,
            string backpack,
            string helmet,
            string hands,
    ) {
        this.top = top;
        this.pants = pants;
        this.shoes = shoes;
        this.backpack = backpack;
        this.helmet = helmet;
        this.hands = hands;
	}

    void applyToPlayer(PlayerBase player) {
        player.RemoveAllItems();
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        if (this.top) {
            inventory.CreateInInventory(this.top);
        }
        
        if (this.pants) {
            inventory.CreateInInventory(this.pants);
        }
        
        if (this.shoes) {
            inventory.CreateInInventory(this.shoes);
        }
        
        if (this.backpack) {
            inventory.CreateInInventory(this.backpack);
        }
        
        if (this.helmet) {
            inventory.CreateInInventory(this.helmet);
        }
        
        if (this.hands) {
            inventory.CreateInInventory(this.hands);
        }
    }
};

#endif