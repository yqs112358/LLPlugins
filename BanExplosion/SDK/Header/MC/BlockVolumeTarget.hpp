// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockVolumeTarget {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKVOLUMETARGET
public:
    class BlockVolumeTarget& operator=(class BlockVolumeTarget const&) = delete;
    BlockVolumeTarget(class BlockVolumeTarget const&) = delete;
    BlockVolumeTarget() = delete;
#endif

public:
    /*0*/ virtual ~BlockVolumeTarget();
    /*1*/ virtual void __unk_vfn_0();
    /*2*/ virtual short getMinHeight() const;
    /*3*/ virtual void __unk_vfn_1();
    /*4*/ virtual void __unk_vfn_2();
    /*5*/ virtual class Block const& getExtraBlock(class BlockPos const&) const;
    /*6*/ virtual bool hasBiomeTag(unsigned __int64, class BlockPos const&) const;
    /*7*/ virtual bool setBlock(class BlockPos const&, class Block const&, int);
    /*8*/ virtual bool setBlockSimple(class BlockPos const&, class Block const&);
    /*9*/ virtual void __unk_vfn_3();
    /*10*/ virtual void __unk_vfn_4();
    /*11*/ virtual void __unk_vfn_5();
    /*12*/ virtual void __unk_vfn_6();
    /*13*/ virtual short getMaxHeight() const;
    /*14*/ virtual void __unk_vfn_7();
    /*15*/ virtual void __unk_vfn_8();
    /*16*/ virtual short getHeightmap(int, int);
    /*17*/ virtual bool isLegacyLevel();
    /*18*/ virtual class Biome const* getBiome(class BlockPos const&) const;
    /*19*/ virtual bool isInBounds(class Pos const&) const;
    /*20*/ virtual short getLocalWaterLevel(class BlockPos const&) const;
    /*21*/ virtual class LevelData const& getLevelData() const;
    /*22*/ virtual struct WorldGenContext const& getContext();
    /*
    inline bool placeStructure(class BlockPos const& a0, class StructureTemplate& a1, class StructureSettings& a2){
        bool (BlockVolumeTarget::*rv)(class BlockPos const&, class StructureTemplate&, class StructureSettings&);
        *((void**)&rv) = dlsym("?placeStructure@BlockVolumeTarget@@UEAA_NAEBVBlockPos@@AEAVStructureTemplate@@AEAVStructureSettings@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0), std::forward<class StructureTemplate&>(a1), std::forward<class StructureSettings&>(a2));
    }
    inline bool shimPlaceForOldFeatures(class Feature const& a0, class BlockPos const& a1, class Random& a2) const{
        bool (BlockVolumeTarget::*rv)(class Feature const&, class BlockPos const&, class Random&) const;
        *((void**)&rv) = dlsym("?shimPlaceForOldFeatures@BlockVolumeTarget@@UEBA_NAEBVFeature@@AEBVBlockPos@@AEAVRandom@@@Z");
        return (this->*rv)(std::forward<class Feature const&>(a0), std::forward<class BlockPos const&>(a1), std::forward<class Random&>(a2));
    }
    inline bool apply() const{
        bool (BlockVolumeTarget::*rv)() const;
        *((void**)&rv) = dlsym("?apply@BlockVolumeTarget@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool canSurvive(class BlockPos const& a0, class Block const& a1) const{
        bool (BlockVolumeTarget::*rv)(class BlockPos const&, class Block const&) const;
        *((void**)&rv) = dlsym("?canSurvive@BlockVolumeTarget@@UEBA_NAEBVBlockPos@@AEBVBlock@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0), std::forward<class Block const&>(a1));
    }
    inline bool mayPlace(class BlockPos const& a0, class Block const& a1) const{
        bool (BlockVolumeTarget::*rv)(class BlockPos const&, class Block const&) const;
        *((void**)&rv) = dlsym("?mayPlace@BlockVolumeTarget@@UEBA_NAEBVBlockPos@@AEBVBlock@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0), std::forward<class Block const&>(a1));
    }
    inline  ~BlockVolumeTarget(){
         (BlockVolumeTarget::*rv)();
        *((void**)&rv) = dlsym("??1BlockVolumeTarget@@UEAA@XZ");
        return (this->*rv)();
    }
    inline class Block const& getBlockNoBoundsCheck(class BlockPos const& a0) const{
        class Block const& (BlockVolumeTarget::*rv)(class BlockPos const&) const;
        *((void**)&rv) = dlsym("?getBlockNoBoundsCheck@BlockVolumeTarget@@UEBAAEBVBlock@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0));
    }
    inline class Block const& getBlock(class BlockPos const& a0) const{
        class Block const& (BlockVolumeTarget::*rv)(class BlockPos const&) const;
        *((void**)&rv) = dlsym("?getBlock@BlockVolumeTarget@@UEBAAEBVBlock@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0));
    }
    */
    MCAPI BlockVolumeTarget(class BlockVolume&, class Level&, class BiomeSource const&, class AutomaticID<class Dimension, int>, struct WorldGenContext const&);

protected:

private:

};