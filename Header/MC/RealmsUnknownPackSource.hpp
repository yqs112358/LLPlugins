// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RealmsUnknownPackSource {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_REALMSUNKNOWNPACKSOURCE
public:
    class RealmsUnknownPackSource& operator=(class RealmsUnknownPackSource const&) = delete;
    RealmsUnknownPackSource(class RealmsUnknownPackSource const&) = delete;
    RealmsUnknownPackSource() = delete;
#endif

public:
    /*0*/ virtual ~RealmsUnknownPackSource();
    /*1*/ virtual void __unk_vfn_0();
    /*2*/ virtual void __unk_vfn_1();
    /*3*/ virtual enum PackOrigin getPackOrigin() const;
    /*4*/ virtual enum PackType getPackType() const;
    /*5*/ virtual class PackSourceReport load(class IPackManifestFactory&, class IContentKeyProvider const&);
    /*
    inline void forEachPack(class std::function<void (class Pack& )> a0){
        void (RealmsUnknownPackSource::*rv)(class std::function<void (class Pack& )>);
        *((void**)&rv) = dlsym("?forEachPack@RealmsUnknownPackSource@@UEAAXV?$function@$$A6AXAEAVPack@@@Z@std@@@Z");
        return (this->*rv)(std::forward<class std::function<void (class Pack& )>>(a0));
    }
    inline void forEachPackConst(class std::function<void (class Pack const& )> a0) const{
        void (RealmsUnknownPackSource::*rv)(class std::function<void (class Pack const& )>) const;
        *((void**)&rv) = dlsym("?forEachPackConst@RealmsUnknownPackSource@@UEBAXV?$function@$$A6AXAEBVPack@@@Z@std@@@Z");
        return (this->*rv)(std::forward<class std::function<void (class Pack const& )>>(a0));
    }
    */

protected:

private:

};