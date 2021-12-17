// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ArrowItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ARROWITEM
public:
    class ArrowItem& operator=(class ArrowItem const&) = delete;
    ArrowItem(class ArrowItem const&) = delete;
    ArrowItem() = delete;
#endif

public:
    /*0*/ virtual ~ArrowItem();
    /*1*/ virtual void tearDown();
    /*2*/ virtual int getMaxUseDuration(class ItemStack const*) const;
    /*3*/ virtual void __unk_vfn_0();
    /*4*/ virtual void __unk_vfn_1();
    /*5*/ virtual void executeEvent(class ItemStackBase&, std::string const&, class RenderParams&) const;
    /*6*/ virtual void __unk_vfn_2();
    /*7*/ virtual bool isArmor() const;
    /*8*/ virtual bool isBlockPlanterItem() const;
    /*9*/ virtual void __unk_vfn_3();
    /*10*/ virtual void __unk_vfn_4();
    /*11*/ virtual bool isDyeable() const;
    /*12*/ virtual bool isDye() const;
    /*13*/ virtual int /*enum enum ItemColor*/ getItemColor() const;
    /*14*/ virtual bool isFertilizer() const;
    /*15*/ virtual void __unk_vfn_5();
    /*16*/ virtual bool isThrowable() const;
    /*17*/ virtual bool isUseable() const;
    /*18*/ virtual class ItemComponent* getComponent(class HashedString const&) const;
    /*19*/ virtual class FuelItemComponent* getFuel() const;
    /*20*/ virtual int /*enum enum BlockShape*/ getBlockShape() const;
    /*21*/ virtual bool canDestroySpecial(class Block const&) const;
    /*22*/ virtual int getLevelDataForAuxValue(int) const;
    /*23*/ virtual short getMaxDamage() const;
    /*24*/ virtual int getAttackDamage() const;
    /*25*/ virtual bool isGlint(class ItemStackBase const&) const;
    /*26*/ virtual void __unk_vfn_6();
    /*27*/ virtual int getPatternIndex() const;
    /*28*/ virtual void __unk_vfn_7();
    /*29*/ virtual bool isWearableThroughLootTable(class CompoundTag const*) const;
    /*30*/ virtual bool canDestroyInCreative() const;
    /*31*/ virtual bool isDestructive(int) const;
    /*32*/ virtual bool isLiquidClipItem(int) const;
    /*33*/ virtual bool shouldInteractionWithBlockBypassLiquid(class Block const&) const;
    /*34*/ virtual bool requiresInteract() const;
    /*35*/ virtual void appendFormattedHovertext(class ItemStackBase const&, class Level&, std::string&, bool) const;
    /*36*/ virtual bool isValidRepairItem(class ItemStackBase const&, class ItemStackBase const&, class BaseGameVersion const&) const;
    /*37*/ virtual int getEnchantSlot() const;
    /*38*/ virtual int getEnchantValue() const;
    /*39*/ virtual int getArmorValue() const;
    /*40*/ virtual void __unk_vfn_8();
    /*41*/ virtual bool isValidAuxValue(int) const;
    /*42*/ virtual float getViewDamping() const;
    /*43*/ virtual void __unk_vfn_9();
    /*44*/ virtual void __unk_vfn_10();
    /*45*/ virtual void __unk_vfn_11();
    /*46*/ virtual class mce::Color getColor(class CompoundTag const*, class ItemDescriptor const&) const;
    /*47*/ virtual bool hasCustomColor(class CompoundTag const*) const;
    /*48*/ virtual void __unk_vfn_12();
    /*49*/ virtual void clearColor(class ItemStackBase&) const;
    /*50*/ virtual void clearColor(class CompoundTag*) const;
    /*51*/ virtual void setColor(class ItemStackBase&, class mce::Color const&) const;
    /*52*/ virtual void __unk_vfn_13();
    /*53*/ virtual void __unk_vfn_14();
    /*54*/ virtual void __unk_vfn_15();
    /*55*/ virtual void __unk_vfn_16();
    /*56*/ virtual bool canUseOnSimTick() const;
    /*57*/ virtual bool dispense(class BlockSource&, class Container&, int, class Vec3 const&, unsigned char) const;
    /*58*/ virtual float getDestroySpeed(class ItemStackBase const&, class Block const&) const;
    /*59*/ virtual void hitActor(class ItemStack&, class Actor&, class Mob&) const;
    /*60*/ virtual void hitBlock(class ItemStack&, class Block const&, class BlockPos const&, class Mob&) const;
    /*61*/ virtual bool mineBlock(class ItemInstance&, class Block const&, int, int, int, class Actor*) const;
    /*62*/ virtual bool mineBlock(class ItemStack&, class Block const&, int, int, int, class Actor*) const;
    /*63*/ virtual void __unk_vfn_17();
    /*64*/ virtual std::string buildDescriptionId(class ItemDescriptor const&, class CompoundTag const*) const;
    /*65*/ virtual std::string buildEffectDescriptionName(class ItemStackBase const&) const;
    /*66*/ virtual unsigned char getMaxStackSize(class ItemDescriptor const&) const;
    /*67*/ virtual bool inventoryTick(class ItemStack&, class Level&, class Actor&, int, bool) const;
    /*68*/ virtual void refreshedInContainer(class ItemStackBase const&, class Level&) const;
    /*69*/ virtual void fixupCommon(class ItemStackBase&, class Level&) const;
    /*70*/ virtual void __unk_vfn_18();
    /*71*/ virtual void __unk_vfn_19();
    /*72*/ virtual bool validFishInteraction(int) const;
    /*73*/ virtual std::string getInteractText(class Player const&) const;
    /*74*/ virtual int getAnimationFrameFor(class Mob*, bool, class ItemStack const*, bool) const;
    /*75*/ virtual struct TextureUVCoordinateSet const& getIcon(class ItemStackBase const&, int, bool) const;
    /*76*/ virtual int getIconYOffset() const;
    /*77*/ virtual class Item& setIcon(std::string const&, int);
    /*78*/ virtual bool canBeCharged() const;
    /*79*/ virtual void playSoundIncrementally(class ItemStack const&, class Mob&) const;
    /*80*/ virtual void __unk_vfn_20();
    /*81*/ virtual std::string getAuxValuesDescription() const;
    /*82*/ virtual bool _calculatePlacePos(class ItemStackBase&, class Actor&, unsigned char&, class BlockPos&) const;
    MCAPI ArrowItem(std::string const&, int);
    MCAPI void applyEffect(class Arrow*, class ItemInstance const&) const;

protected:
    MCAPI std::vector<class MobEffectInstance> getMobEffects(int) const;

private:

};