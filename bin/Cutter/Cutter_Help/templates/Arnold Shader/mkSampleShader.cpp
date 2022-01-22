/*
Based on the shader code given in the Arnold docs.
        https://docs.arnoldrenderer.com/display/A5AFMUG/Creating+an+Arnold+Shader+for+Maya
Malcolm Kesson
Apr 20 2021
*/
#include <ai.h>
#include <cstring>

AI_SHADER_NODE_EXPORT_METHODS(SampleMethods);
 
namespace {
	enum paramIndex { k_base_color, k_pat_color };
	};
 
node_parameters {
    AiParameterRGB("baseColor", 0.7f, 0.7f, 0);
    AiParameterRGB("patternColor", 0.7f, 0, 0);
	}
 
shader_evaluate {
	AtRGB base = AiShaderEvalParamRGB(k_base_color);
	AtRGB pat = AiShaderEvalParamRGB(k_pat_color);
	sg->out.RGB() = (sg->u >= 0.5) ? pat : base;
	}
 
node_loader {
    if (i > 0)
        return false; 
    node->methods        = SampleMethods;
    node->output_type    = AI_TYPE_RGB;
    node->name           = "NAME_OF_YOUR_SHADER";
    node->node_type      = AI_NODE_SHADER;
    strcpy(node->version, AI_VERSION);
    return true;
	}
	
// The remaining macros can be left "empty"
node_initialize { }
node_update { }
node_finish { }
