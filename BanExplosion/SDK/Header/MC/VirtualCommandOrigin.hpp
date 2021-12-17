// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "CommandOrigin.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class VirtualCommandOrigin : public CommandOrigin {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VIRTUALCOMMANDORIGIN
public:
    class VirtualCommandOrigin& operator=(class VirtualCommandOrigin const&) = delete;
    VirtualCommandOrigin(class VirtualCommandOrigin const&) = delete;
    VirtualCommandOrigin() = delete;
#endif

public:
    /*0*/ virtual ~VirtualCommandOrigin();
    /*1*/ virtual std::string const& getRequestId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual class BlockPos getBlockPosition() const;
    /*4*/ virtual class Vec3 getWorldPosition() const;
    /*5*/ virtual class Level* getLevel() const;
    /*6*/ virtual class Dimension* getDimension() const;
    /*7*/ virtual class Actor* getEntity() const;
    /*8*/ virtual int /*enum enum CommandPermissionLevel*/ getPermissionsLevel() const;
    /*9*/ virtual std::unique_ptr<class CommandOrigin> clone() const;
    /*10*/ virtual class std::optional<class BlockPos> getCursorHitBlockPos() const;
    /*11*/ virtual class std::optional<class Vec3> getCursorHitPos() const;
    /*12*/ virtual bool hasChatPerms() const;
    /*13*/ virtual bool hasTellPerms() const;
    /*14*/ virtual bool canUseAbility(int /*enum enum AbilitiesIndex*/) const;
    /*15*/ virtual bool canUseCommandsWithoutCheatsEnabled() const;
    /*16*/ virtual bool isSelectorExpansionAllowed() const;
    /*17*/ virtual class NetworkIdentifier const& getSourceId() const;
    /*18*/ virtual unsigned char getSourceSubId() const;
    /*19*/ virtual class CommandOrigin const& getOutputReceiver() const;
    /*20*/ virtual struct CommandOriginIdentity getIdentity() const;
    /*21*/ virtual int /*enum enum CommandOriginType*/ getOriginType() const;
    /*22*/ virtual class mce::UUID const& getUUID() const;
    /*23*/ virtual void handleCommandOutputCallback(class Json::Value&&) const;
    /*24*/ virtual class CompoundTag serialize() const;
    /*25*/ virtual bool isValid() const;
    MCAPI VirtualCommandOrigin(class CommandOrigin const&, class Actor&, class CommandPositionFloat const&, int);
    MCAPI void updateExecutePosition();
    MCAPI static class Vec3 const getExecutePosition(int, class Actor&, class CommandPositionFloat const&, class CommandOrigin const&);
    MCAPI static std::unique_ptr<class VirtualCommandOrigin> load(class CompoundTag const&, class ServerLevel&);

protected:

private:

};