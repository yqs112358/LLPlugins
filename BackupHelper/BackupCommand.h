#pragma once
//#define LEGACY_COMMAND

#ifdef LEGACY_COMMAND
#include "MC/CommandRegistry.hpp"
#include "MC/CommandParameterData.hpp"

#else
#include "RegCommandAPI.h"

void RecoverWorld();

class BackupCommand : public Command {
    enum class BackupOP :int {
        reload,
        cancel,
        recover,
        list,
    } op;
    int recover_Num = 0;
    bool op_isSet = false;
    bool num_isSet = false;
    

    virtual void execute(CommandOrigin const& ori, CommandOutput& outp) const;
public:
    static void setup(CommandRegistry* registry);
};

#endif // LEGACY_COMMAND