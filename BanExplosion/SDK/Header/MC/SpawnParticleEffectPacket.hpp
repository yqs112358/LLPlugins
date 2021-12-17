// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SpawnParticleEffectPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SPAWNPARTICLEEFFECTPACKET
public:
    class SpawnParticleEffectPacket& operator=(class SpawnParticleEffectPacket const&) = delete;
    SpawnParticleEffectPacket(class SpawnParticleEffectPacket const&) = delete;
#endif

public:
    /*0*/ virtual ~SpawnParticleEffectPacket();
    /*1*/ virtual int /*enum enum MinecraftPacketIds*/ getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual int /*enum enum StreamReadResult*/ _read(class ReadOnlyBinaryStream&);
    /*
    inline  ~SpawnParticleEffectPacket(){
         (SpawnParticleEffectPacket::*rv)();
        *((void**)&rv) = dlsym("??1SpawnParticleEffectPacket@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI SpawnParticleEffectPacket(class Vec3 const&, std::string const&, unsigned char);
    MCAPI SpawnParticleEffectPacket(struct ActorUniqueID, class Vec3 const&, std::string const&, unsigned char);
    MCAPI SpawnParticleEffectPacket();

protected:

private:

};