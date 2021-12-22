// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Scripting.hpp"
#include "ScriptActorComponent.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptAgeableComponent : public ScriptActorComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTAGEABLECOMPONENT
public:
    class ScriptAgeableComponent& operator=(class ScriptAgeableComponent const&) = delete;
    ScriptAgeableComponent(class ScriptAgeableComponent const&) = delete;
    ScriptAgeableComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptAgeableComponent();
    /*
    inline  ~ScriptAgeableComponent(){
         (ScriptAgeableComponent::*rv)();
        *((void**)&rv) = dlsym("??1ScriptAgeableComponent@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI ScriptAgeableComponent(class WeakEntityRef const&, class Scripting::WeakLifetimeScope const&, std::string const&);
    MCAPI class Scripting::Result<std::vector<std::string> > getDropItems() const;
    MCAPI class Scripting::Result<float> getDuration() const;
    MCAPI class Scripting::Result<std::vector<struct ActorDefinitionFeedItem> > getFeedItems() const;
    MCAPI class Scripting::Result<class Scripting::StrongTypedObjectHandle<class ScriptDefinitionTrigger> > getGrowUp() const;
    MCAPI static class Scripting::ClassBindingBuilder<class ScriptAgeableComponent> bind(struct Scripting::Version);

protected:

private:

};