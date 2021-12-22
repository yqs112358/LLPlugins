// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Scripting.hpp"
#include "ScriptObject.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptItemComponent : public ScriptObject {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTITEMCOMPONENT
public:
    class ScriptItemComponent& operator=(class ScriptItemComponent const&) = delete;
    ScriptItemComponent(class ScriptItemComponent const&) = delete;
    ScriptItemComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptItemComponent();
    /*
    inline  ~ScriptItemComponent(){
         (ScriptItemComponent::*rv)();
        *((void**)&rv) = dlsym("??1ScriptItemComponent@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI ScriptItemComponent(class Scripting::WeakTypedObjectHandle<class ScriptItemStack>, class Scripting::WeakLifetimeScope const&, std::string const&);
    MCAPI std::string const& getId() const;
    MCAPI bool valid() const;

protected:

private:

};