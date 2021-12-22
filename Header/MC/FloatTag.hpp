// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Tag.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FloatTag : public Tag {

#define AFTER_EXTRA
// Add Member There
float val;

public:
    LIAPI float& value();
    LIAPI FloatTag& operator=(float val);
    LIAPI static std::unique_ptr<FloatTag> create(float val = 0.0f);
    LIAPI bool set(float val);
    LIAPI float get();

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FLOATTAG
public:
    class FloatTag& operator=(class FloatTag const&) = delete;
    FloatTag(class FloatTag const&) = delete;
#endif

public:
    /*0*/ virtual ~FloatTag();
    /*1*/ virtual void deleteChildren();
    /*2*/ virtual void write(class IDataOutput&) const;
    /*3*/ virtual void load(class IDataInput&);
    /*4*/ virtual std::string toString() const;
    /*5*/ virtual enum Tag::Type getId() const;
    /*6*/ virtual bool equals(class Tag const&) const;
    /*7*/ virtual std::unique_ptr<class Tag> copy() const;
    /*8*/ virtual unsigned __int64 hash() const;
    /*
    inline  ~FloatTag(){
         (FloatTag::*rv)();
        *((void**)&rv) = dlsym("??1FloatTag@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI FloatTag(float);
    MCAPI FloatTag();

protected:

private:

};