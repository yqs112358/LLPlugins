// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "PredictableProjectile.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FallingBlock : public PredictableProjectile {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FALLINGBLOCK
public:
    class FallingBlock& operator=(class FallingBlock const&) = delete;
    FallingBlock(class FallingBlock const&) = delete;
    FallingBlock() = delete;
#endif

public:
    /*0*/ virtual void reloadHardcoded(int /*enum enum Actor::InitializationMethod*/, class VariantParameterList const&);
    /*1*/ virtual void reloadHardcodedClient(int /*enum enum Actor::InitializationMethod*/, class VariantParameterList const&);
    /*2*/ virtual ~FallingBlock();
    /*3*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*4*/ virtual void __unk_vfn_0();
    /*5*/ virtual float getInterpolatedHeadRot(float) const;
    /*6*/ virtual float getInterpolatedBodyYaw(float) const;
    /*7*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*8*/ virtual void __unk_vfn_1();
    /*9*/ virtual void teleportTo(class Vec3 const&, bool, int, int);
    /*10*/ virtual void normalTick();
    /*11*/ virtual float getRidingHeight();
    /*12*/ virtual void __unk_vfn_2();
    /*13*/ virtual void __unk_vfn_3();
    /*14*/ virtual float getCameraOffset() const;
    /*15*/ virtual float getShadowHeightOffs();
    /*16*/ virtual float getShadowRadius() const;
    /*17*/ virtual void __unk_vfn_4();
    /*18*/ virtual void __unk_vfn_5();
    /*19*/ virtual void playerTouch(class Player&);
    /*20*/ virtual bool isPickable();
    /*21*/ virtual void __unk_vfn_6();
    /*22*/ virtual bool isSleeping() const;
    /*23*/ virtual void setSleeping(bool);
    /*24*/ virtual void __unk_vfn_7();
    /*25*/ virtual bool isBlocking() const;
    /*26*/ virtual bool isDamageBlocked(class ActorDamageSource const&) const;
    /*27*/ virtual void __unk_vfn_8();
    /*28*/ virtual bool isSurfaceMob() const;
    /*29*/ virtual void __unk_vfn_9();
    /*30*/ virtual void __unk_vfn_10();
    /*31*/ virtual void __unk_vfn_11();
    /*32*/ virtual class Actor* findAttackTarget();
    /*33*/ virtual bool isValidTarget(class Actor*) const;
    /*34*/ virtual void adjustDamageAmount(int&) const;
    /*35*/ virtual void onTame();
    /*36*/ virtual void onFailedTame();
    /*37*/ virtual bool isJumping() const;
    /*38*/ virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    /*39*/ virtual void animateHurt();
    /*40*/ virtual void onBounceStarted(class BlockPos const&, class Block const&);
    /*41*/ virtual float getPickRadius();
    /*42*/ virtual void awardKillScore(class Actor&, int);
    /*43*/ virtual int /*enum enum ArmorMaterialType*/ getArmorMaterialTypeInSlot(int /*enum enum ArmorSlot*/) const;
    /*44*/ virtual int /*enum enum ArmorTextureType*/ getArmorMaterialTextureTypeInSlot(int /*enum enum ArmorSlot*/) const;
    /*45*/ virtual float getArmorColorInSlot(int /*enum enum ArmorSlot*/, int) const;
    /*46*/ virtual void setEquippedSlot(int /*enum enum EquipmentSlot*/, class ItemStack const&);
    /*47*/ virtual class HashedString const& queryEntityRenderer() const;
    /*48*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*49*/ virtual bool canFreeze() const;
    /*50*/ virtual int getPortalWaitTime() const;
    /*51*/ virtual bool canChangeDimensions() const;
    /*52*/ virtual void __unk_vfn_12();
    /*53*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*54*/ virtual void causeFallDamage(float, float, class ActorDamageSource);
    /*55*/ virtual bool canPickupItem(class ItemStack const&) const;
    /*56*/ virtual bool canBePulledIntoVehicle() const;
    /*57*/ virtual bool inCaravan() const;
    /*58*/ virtual void __unk_vfn_13();
    /*59*/ virtual bool canSynchronizeNewEntity() const;
    /*60*/ virtual void buildDebugInfo(std::string&) const;
    /*61*/ virtual int getDeathTime() const;
    /*62*/ virtual void swing();
    /*63*/ virtual void __unk_vfn_14();
    /*64*/ virtual void __unk_vfn_15();
    /*65*/ virtual float getYHeadRot() const;
    /*66*/ virtual bool isWorldBuilder() const;
    /*67*/ virtual void __unk_vfn_16();
    /*68*/ virtual bool isAdventure() const;
    /*69*/ virtual bool canDestroyBlock(class Block const&) const;
    /*70*/ virtual void setAuxValue(int);
    /*71*/ virtual void stopSpinAttack();
    /*72*/ virtual void __unk_vfn_17();
    /*73*/ virtual void __unk_vfn_18();
    /*74*/ virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    /*75*/ virtual void __unk_vfn_19();
    /*76*/ virtual bool _hurt(class ActorDamageSource const&, int, bool, bool);
    /*77*/ virtual void readAdditionalSaveData(class CompoundTag const&, class DataLoadHelper&);
    /*78*/ virtual void addAdditionalSaveData(class CompoundTag&);
    /*79*/ virtual void __unk_vfn_20();
    /*80*/ virtual void _onSizeUpdated();
    /*
    inline float getDeletionDelayTimeSeconds() const{
        float (FallingBlock::*rv)() const;
        *((void**)&rv) = dlsym("?getDeletionDelayTimeSeconds@FallingBlock@@UEBAMXZ");
        return (this->*rv)();
    }
    */
    MCAPI FallingBlock(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&, class OwnerPtrT<struct EntityRefTraits> const&);
    MCAPI class Block const& getFallingBlock() const;
    MCAPI void setFallDamageAmount(float);
    MCAPI void setFallingBlock(class Block const&, bool);

protected:

private:
    MCAPI void _breakBlock();
    MCAPI void _waitRemoval();

};