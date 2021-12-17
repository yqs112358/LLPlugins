// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "MoveToPOIGoal.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HideGoal : public MoveToPOIGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HIDEGOAL
public:
    class HideGoal& operator=(class HideGoal const&) = delete;
    HideGoal(class HideGoal const&) = delete;
    HideGoal() = delete;
#endif

public:
    /*0*/ virtual ~HideGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual void __unk_vfn_0();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void appendDebugInfo(std::string&) const;
    /*7*/ virtual void __unk_vfn_1();
    /*8*/ virtual void __unk_vfn_2();
    /*9*/ virtual unsigned __int64 _getRepathTime() const;
    /*10*/ virtual class std::weak_ptr<class POIInstance> _getOwnedPOI(int /*enum enum POIType*/) const;
    MCAPI HideGoal(class Mob&, float, float, float, enum POIType);

protected:

private:

};