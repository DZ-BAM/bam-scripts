#ifndef BAM_WEAPON
#define BAM_WEAPON

#ifndef BAM_ERROR
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/error.c"
#endif

class BAM_Weapon {
    string name;
    ref array<string> attachments;
    ref BAM_Magazine magazine;

    void BAM_Weapon(
            string name,
            ref array<string> attachments,
            ref BAM_Magazine magazine,
    ) {
        this.name = name;
        this.attachments = attachments;
        this.magazine = magazine;
    }

    void addToPlayer(PlayerBase player) {
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        auto entity = inventory.CreateInInventory(this.name);
        Weapon_Base weapon;

        if (Class.CastTo(weapon, entity)) {
            foreach (auto attachment: this.attachments) {
                weapon.GetInventory().CreateInInventory(attachment);
            }

            this.magazine.addToWeapon(weapon);
        } else {
            BAM_error("Entity '" + this.name + "' is not a weapon!");
        }
    }
};

class BAM_Magazine {
    string name;
    int flags;

    void BAM_Magazine(string name, int flags) {
        this.name = name;
        this.flags = flags;
    }

    void addToPlayer(PlayerBase player) {
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        inventory.CreateInInventory(this.name);
    }

    void addToWeapon(Weapon_Base weapon) {
        weapon.SpawnAmmo(this.name, this.flags);
    }
};

#endif