// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DespawnSystem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DESPAWNSYSTEM
public:
    class DespawnSystem& operator=(class DespawnSystem const&) = delete;
    DespawnSystem(class DespawnSystem const&) = delete;
    DespawnSystem() = delete;
#endif

public:
    /*0*/ virtual ~DespawnSystem();
    /*1*/ virtual void __unk_vfn_0();
    /*2*/ virtual void tick(class EntityRegistry&);

protected:

private:

};