// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Scripting.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptWorldEvents {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTWORLDEVENTS
public:
    class ScriptWorldEvents& operator=(class ScriptWorldEvents const&) = delete;
    ScriptWorldEvents(class ScriptWorldEvents const&) = delete;
    ScriptWorldEvents() = delete;
#endif

public:
    MCAPI ScriptWorldEvents(class Scripting::WeakLifetimeScope const&, class gsl::not_null<class Level* >);
    MCAPI ScriptWorldEvents(class ScriptWorldEvents&&);
    MCAPI class Level& getLevel() const;
    MCAPI void onActorAddEffect(struct ScriptActorAddEffectEvent&);
    MCAPI void onActorCreated(struct ScriptActorEvent&);
    MCAPI void onBeforeChat(struct ScriptBeforeChatEvent&);
    MCAPI void onChat(struct ScriptChatEvent&);
    MCAPI void onLevelTick(struct ScriptTickEvent&);
    MCAPI void onWeatherChanged(struct ScriptWeatherChangedEvent&);
    MCAPI class ScriptWorldEvents& operator=(class ScriptWorldEvents&&);
    MCAPI void registerListener(struct Scripting::TypedObjectHandle<class ScriptWorldEvents>);
    MCAPI ~ScriptWorldEvents();
    MCAPI static class Scripting::ClassBindingBuilder<class ScriptWorldEvents> bind(struct Scripting::Version);

protected:

private:

};