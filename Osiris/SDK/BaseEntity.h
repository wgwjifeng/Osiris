#pragma once

#include "ClientEntity.h"
#include "Vector.h"

class BaseEntity {
public:
    int* getFlags();
    int getHealth();
    Vector getVelocity();
    int getMoveType();
    int getTeamNumber();
    bool isScoped();
    int getCrosshairID();
    bool isAlive();
    ClientRenderable* getRenderable();
    void drawModel(int flags, unsigned char alpha);
};
