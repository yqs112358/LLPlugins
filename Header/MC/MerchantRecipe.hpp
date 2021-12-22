// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MerchantRecipe {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MERCHANTRECIPE
public:
    class MerchantRecipe& operator=(class MerchantRecipe const&) = delete;
    MerchantRecipe() = delete;
#endif

public:
    MCAPI MerchantRecipe(class MerchantRecipe const&);
    MCAPI MerchantRecipe(class ItemInstance const&, class ItemInstance const&, class ItemInstance const&);
    MCAPI MerchantRecipe(class ItemInstance const&, class ItemInstance const&);
    MCAPI void calculateDemandPrices(int, int, int, bool);
    MCAPI std::unique_ptr<class CompoundTag> createTag(bool) const;
    MCAPI int getBaseCountA() const;
    MCAPI int getBaseCountB() const;
    MCAPI class ItemInstance const& getBuyAItem() const;
    MCAPI class ItemInstance const& getBuyBItem() const;
    MCAPI int getDemand() const;
    MCAPI int getMaxUses() const;
    MCAPI class ItemInstance const& getSellItem() const;
    MCAPI int getTier() const;
    MCAPI unsigned int getTraderExp() const;
    MCAPI int getUses() const;
    MCAPI bool hasSecondaryBuyItem() const;
    MCAPI void increaseMaxUses(int);
    MCAPI void increaseUses();
    MCAPI void init(class ItemInstance const&, class ItemInstance const&, class ItemInstance const&);
    MCAPI bool isOutOfUses() const;
    MCAPI bool isSame(class MerchantRecipe const&) const;
    MCAPI void legacyCalculateDemandPrices(int, int);
    MCAPI void load(class CompoundTag const*);
    MCAPI void setDemand(int);
    MCAPI void setMaxUses(int);
    MCAPI void setPriceMultiplierA(float);
    MCAPI void setPriceMultiplierB(float);
    MCAPI void setRewardExp(bool);
    MCAPI void setTier(int);
    MCAPI void setTraderExp(unsigned int);
    MCAPI void setUses(int);
    MCAPI bool shouldRewardExp() const;
    MCAPI ~MerchantRecipe();

protected:

private:

};