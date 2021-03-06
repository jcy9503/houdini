/* 
 _CLASSNAME_.cpp
 Generated by Cutter from:
     "_ARGS_SOURCE_PATH_"
 at _DATE_TIME_
 Basic code for use with RPS 21.
*/
#include <RixPattern.h> 
#include <RixShadingUtils.h>
#include <RixShading.h>
//#include <RixInterfaces.h>
#include <cstring>
//#include <cstdio>
//#include <sstream>
//#include <cmath>

class _CLASSNAME_ : public RixPattern {
public:

    _CLASSNAME_();
    virtual ~_CLASSNAME_() { }
    virtual int Init(RixContext &, char const *pluginpath);
    virtual RixSCParamInfo const *GetParamTable();
    virtual void Finalize(RixContext &) { }
    virtual int ComputeOutputParams(RixShadingContext const *ctx,
                                    RtInt *noutputs, 
                                    OutputSpec **outputs,
                                    RtConstPointer instanceData,
                                    RixSCParamInfo const *ignored);
	private:
		RixMessages *m_msg;
		RixShadeFunctions *m_shd;  // Shading functions in RixInterfaces.h
_DECLARE_INPUTS_AS_MEMBERS_
	};

_CLASSNAME_::_CLASSNAME_():
	m_msg(NULL),
	m_shd(NULL),
_ASSIGN_BY_VALUE_
	{ }

int _CLASSNAME_::Init(RixContext &ctx, char const *pluginpath) {
    m_msg = (RixMessages*)ctx.GetRixInterface(k_RixMessages);
    m_shd = (RixShadeFunctions*)ctx.GetRixInterface(k_RixShadeFunctions);

    // Uncomment the next three lines if a rib Option will be queried.
    //RixRenderState *rstate = (RixRenderState*)ctx.GetRixInterface(k_RixRenderState);
    //RixRenderState::Type optType;
    //RtInt optNumValues, err;
    // Example of using messaging,
    //    m_msg->Info("%f\n", a_float_value);
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
	
int _CLASSNAME_::ComputeOutputParams(RixShadingContext const *ctx,
								RtInt *noutputs, 
								OutputSpec **outputs,
								RtConstPointer instanceData,
								RixSCParamInfo const *ignored) {

	// Uncomment the next three lines if a rib Attribute will be queried. Note
	// that Rib Options should be queried in the init() method - not here!
	//RixRenderState *rstate = (RixRenderState*)ctx->GetRixInterface(k_RixRenderState);
	//RixRenderState::Type attrType;
	//RtInt attrNumValues, err;

	// OUTPUTS BEGIN____________________________________
	// Allocate memory for the OutputSpec data structure.
	RixShadingContext::Allocator pool(ctx);
_ALLOCATE_OUTSPEC_MEMORY_
	// Allocate memory for each output.
_DECLARE_OUTPUTS_MEMORY_
	// Connect the output(s) to the OutputSpec.
	*noutputs = _NUM_OUTPUTS_;
_PREPARE_OUTSPEC_FIELDS_
	// INPUTS BEGIN____________________________________
	bool varying = true;
	bool uniform = false;
	// Declare a pointer for each input then obtain their values
	// using EvalParam().
_DECLARE_COMPUTE_OUTPUT_PARAMS_POINTERS_
_EVAL_INPUTS_
_MANIFOLD_ST_PRIMVAR_DECLARATIONS_
_ST_EVAL_PRIMVAR_
	// Assign values to the output(s).
	for(int i = 0; i < ctx->numPts; i++) {
_MANIFOLD_USE_ _ST_USE_
_ASSIGN_INPUT_TO_OUTPUT_
			}
		}
	return 0;
	}
RIX_PATTERNCREATE {
	return new _CLASSNAME_();
	}
RIX_PATTERNDESTROY {
	delete((_CLASSNAME_*)pattern);
	}
