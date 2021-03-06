#pragma once

#include "Utils.h"

class RenderView {
public:
    void setBlend(float alpha)
    {
        return callVirtualFunction<void(__thiscall*)(void*, float)>(this, 4)(this, alpha);
    }

    void setColorModulation(const float* colors)
    {
        return callVirtualFunction<void(__thiscall*)(void*, const float*)>(this, 6)(this, colors);
    }
};
