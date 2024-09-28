#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Field.h"
#include "House.h"
#include "Tree.h"
#include "NPC.h"

class World {
private:
    int worldSizeX;
    int worldSizeY;
    std::vector<Field> fieldList;
    std::vector<NPC> npcList;
    std::vector<House> houseList;
    std::vector<Tree> treeList;  

    void initializeNPCs();
public:
    World();

    bool checkBounds(int posX, int posY) const;

    // Getters
    const std::vector<House>& getHouseList() const;
    const std::vector<Tree>& getTreeList() const;
    const std::vector<Field>& getFieldList() const;
    const std::vector<NPC>& getNPCList() const;
};

#endif // WORLD_H