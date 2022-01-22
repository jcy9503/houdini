/* 
 _CLASSNAME_.cpp
 Generated by Cutter from:
     "_ARGS_SOURCE_PATH_"
 at _DATE_TIME_
*/
#include <RixInterfaces.h>
#include <RixProjection.h>
#include <algorithm>
#include <cmath>

class _CLASSNAME_ : public RixProjection {
public:
    _CLASSNAME_();
    virtual ~_CLASSNAME_() { }
    virtual int Init(RixContext& ctx, char const* pluginPath);	
	virtual void Finalize(RixContext& ctx) { }
	virtual RixSCParamInfo const* GetParamTable();
	virtual void RenderBegin(RixContext& ctx, RixProjectionEnvironment& env, RixParameterList const* params);
	virtual void RenderEnd(RixContext& ctx);
	virtual void Synchronize(RixContext& ctx, RixSCSyncMsg syncMsg, RixParameterList const* params);
	virtual void Project(RixProjectionContext& pCtx);
	private:
		RixMessages *m_msg;
_DECLARE_INPUTS_AS_MEMBERS_
	};

_CLASSNAME_::_CLASSNAME_():
	m_msg(NULL),
_ASSIGN_BY_VALUE_
	{ }

int _CLASSNAME_::Init(RixContext &ctx, char const *pluginpath) {
    m_msg = (RixMessages*)ctx.GetRixInterface(k_RixMessages);
    return (!m_msg) ? 1 : 0;
    }

RixSCParamInfo const *_CLASSNAME_::GetParamTable() {
    static RixSCParamInfo s_ptable[] = {
_FILL_PARAM_TABLE_
        };
    return &s_ptable[0];
    }

enum paramIndex {
_FILL_PARAM_ENUMERATION_
    };

void _CLASSNAME_::RenderBegin(RixContext& ctx, 
							  RixProjectionEnvironment &env, 
							  RixParameterList const *params) {
	Synchronize(ctx, k_RixSCInstanceEdit, params);
	}
	
void _CLASSNAME_::RenderEnd(RixContext &ctx) {
	}

void _CLASSNAME_::Synchronize(RixContext &ctx, 
							  RixSCSyncMsg syncMsg, 
							  RixParameterList const* params) {
	if(syncMsg != k_RixSCInstanceEdit)
		return;
    _EVAL_INPUTS_
	}
void _CLASSNAME_::Project(RixProjectionContext &pCtx) {
    // Refer to RixProjection.h for information about screen, 
    // ray, tint and shutter.
	for(int i = 0; i < pCtx.numRays; i++) {
        //RtPoint2 const &screen(pCtx.screen[i]);
        //RtRayGeometry  &ray(pCtx.rays[i]);
        
		//pCtx.tint[i] = RtColorRGB(1.0f); // your tint
		//pCtx.shutter[i] = ??; // your modification 
		}
	}
RIX_PROJECTIONCREATE {
	return new _CLASSNAME_;
	}
RIX_PROJECTIONDESTROY {
	delete reinterpret_cast<_CLASSNAME_*>(projection);
	}