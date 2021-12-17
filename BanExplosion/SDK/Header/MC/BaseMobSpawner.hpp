// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BaseMobSpawner {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BASEMOBSPAWNER
public:
    class BaseMobSpawner& operator=(class BaseMobSpawner const&) = delete;
    BaseMobSpawner(class BaseMobSpawner const&) = delete;
    BaseMobSpawner() = delete;
#endif

public:
    /*0*/ virtual ~BaseMobSpawner();
    /*1*/ virtual void tick(class BlockSource&);
    /*2*/ virtual void load(class CompoundTag const&);
    /*3*/ virtual void save(class CompoundTag&);
    /*4*/ virtual class BlockPos const& getPos() = 0;
    /*
    inline  ~BaseMobSpawner(){
         (BaseMobSpawner::*rv)();
        *((void**)&rv) = dlsym("??1BaseMobSpawner@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI BaseMobSpawner(struct ActorDefinitionIdentifier);
    MCAPI class Mob* getDisplayEntity(class BlockSource&);
    MCAPI void setEntityId(struct ActorDefinitionIdentifier);

protected:
    MCAPI void _delay(class BlockSource&);

private:

};