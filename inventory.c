#ifndef BAM_INVENTORY
#define BAM_INVENTORY

#ifndef BAM_ERROR
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/error.c"
#endif

#ifndef BAM_WEAPON
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/weapon.c"
#endif

class BAM_Inventory {
    ref array<string> items;
    ref array<ref array<string>> random_items;
    ref map<string, int> quantized_items;
    ref array<ref BAM_Weapon> weapons;

    void BAM_Inventory(
            ref array<string> items,
            ref array<ref array<string>> random_items,
            ref map<string, int> quantized_items,
            ref array<ref BAM_Weapon> weapons,
    ) {
        this.items = items;
        this.random_items = random_items;
        this.quantized_items = quantized_items;
        this.weapons = weapons;
	}

    void addToPlayer(PlayerBase player) {
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        foreach (auto item: this.items) {
            inventory.CreateInInventory(item);
        }

        foreach (auto selection: this.random_items) {
            inventory.CreateInInventory(selection.GetRandomElement());
        }

        this.addQuantizedItemsToInventory(inventory);
        this.addWeaponsToInventory(inventory);
    }

    void addQuantizedItemsToInventory(GameInventory inventory) {
        EntityAI entity;
        ItemBase item;

        foreach (auto name, auto quantity: this.quantized_items) {
            entity = inventory.CreateInInventory(name);

            if (Class.CastTo(item, entity)) {
                item.SetQuantity(quantity);
            } else {
                BAM_error("Entity '" + name + "' is not an item!");
            }
        }
    }

    void addWeaponsToInventory(GameInventory inventory) {
        foreach (auto weapon: this.weapons) {
            weapon.addToInventory(inventory);
        }
    }
};

#endif