// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ItemStackNetResultMap {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKNETRESULTMAP
public:
    class ItemStackNetResultMap& operator=(class ItemStackNetResultMap const&) = delete;
    ItemStackNetResultMap(class ItemStackNetResultMap const&) = delete;
    ItemStackNetResultMap() = delete;
#endif

public:
    MCAPI static std::string const& getItemStackNetResultName(enum ItemStackNetResult);

protected:

private:
    MCAPI static class BidirectionalUnorderedMap<enum ItemStackNetResult, std::string > const mMap;

};