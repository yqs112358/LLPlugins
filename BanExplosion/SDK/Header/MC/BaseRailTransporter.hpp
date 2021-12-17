// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BaseCircuitComponent.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BaseRailTransporter : public BaseCircuitComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BASERAILTRANSPORTER
public:
    class BaseRailTransporter& operator=(class BaseRailTransporter const&) = delete;
    BaseRailTransporter(class BaseRailTransporter const&) = delete;
    BaseRailTransporter() = delete;
#endif

public:
    /*0*/ virtual ~BaseRailTransporter();
    /*1*/ virtual int getStrength() const;
    /*2*/ virtual int getDirection() const;
    /*3*/ virtual void setStrength(int);
    /*4*/ virtual void setDirection(unsigned char);
    /*5*/ virtual void __unk_vfn_0();
    /*6*/ virtual bool canStopPower() const;
    /*7*/ virtual void setStopPower(bool);
    /*8*/ virtual bool addSource(class CircuitSceneGraph&, class CircuitTrackingInfo const&, int&, bool&);
    /*9*/ virtual bool allowConnection(class CircuitSceneGraph&, class CircuitTrackingInfo const&, bool&);
    /*10*/ virtual void checkLock(class CircuitSystem&, class BlockPos const&);
    /*11*/ virtual bool evaluate(class CircuitSystem&, class BlockPos const&);
    /*12*/ virtual void cacheValues(class CircuitSystem&, class BlockPos const&);
    /*13*/ virtual void updateDependencies(class CircuitSceneGraph&, class BlockPos const&);
    /*14*/ virtual void __unk_vfn_1();
    /*15*/ virtual bool isHalfPulse() const;
    /*16*/ virtual void __unk_vfn_2();
    /*17*/ virtual bool isSecondaryPowered() const;
    /*18*/ virtual int /*enum enum CircuitComponentType*/ getCircuitComponentType() const;

protected:

private:

};