// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockRaycastComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKRAYCASTCOMPONENT
public:
    struct BlockRaycastComponent& operator=(struct BlockRaycastComponent const&) = delete;
    BlockRaycastComponent(struct BlockRaycastComponent const&) = delete;
    BlockRaycastComponent() = delete;
#endif

public:
    MCAPI class AABB const& getTransformedAABB() const;

protected:

private:

};