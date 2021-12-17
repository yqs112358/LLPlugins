// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Enchant.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FishingEnchant : public Enchant {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FISHINGENCHANT
public:
    class FishingEnchant& operator=(class FishingEnchant const&) = delete;
    FishingEnchant(class FishingEnchant const&) = delete;
    FishingEnchant() = delete;
#endif

public:
    /*0*/ virtual ~FishingEnchant();
    /*1*/ virtual int getMinCost(int) const;
    /*2*/ virtual int getMaxCost(int) const;
    /*3*/ virtual void __unk_vfn_0();
    /*4*/ virtual int getMaxLevel() const;
    /*5*/ virtual int getDamageProtection(int, class ActorDamageSource const&) const;
    /*6*/ virtual float getDamageBonus(int, class Actor const&) const;
    /*7*/ virtual void doPostAttack(class Actor&, class Actor&, int) const;
    /*8*/ virtual void doPostHurt(class ItemInstance&, class Actor&, class Actor&, int) const;
    /*9*/ virtual void __unk_vfn_1();
    /*10*/ virtual void __unk_vfn_2();
    /*11*/ virtual void __unk_vfn_3();
    /*12*/ virtual void __unk_vfn_4();
    /*13*/ virtual bool _isValidEnchantmentTypeForCategory(int /*enum enum Enchant::Type*/) const;

protected:

private:

};