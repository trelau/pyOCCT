/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_Window.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_Resource.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Caps.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_RenderingContext.hxx>
#include <OpenGl_GlFunctions.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <OpenGl_Clipping.hxx>
#include <OpenGl_ShaderManager.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Message_Messenger.hxx>
#include <Message.hxx>
#include <TCollection_ExtendedString.hxx>
#include <OpenGl_FrameStats.hxx>
#include <OpenGl_TextureSet.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_AspectFace.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <OpenGl_Vec.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <OpenGl_FrameBuffer.hxx>
#include <OpenGl_GlCore11.hxx>
#include <OpenGl_GlCore11Fwd.hxx>
#include <OpenGl_ArbSamplerObject.hxx>
#include <OpenGl_ArbTexBindless.hxx>
#include <OpenGl_ArbTBO.hxx>
#include <OpenGl_ArbIns.hxx>
#include <OpenGl_ArbDbg.hxx>
#include <OpenGl_ArbFBO.hxx>
#include <OpenGl_ExtGS.hxx>
#include <OpenGl_MatrixState.hxx>
#include <NCollection_List.hxx>
#include <NCollection_SparseArray.hxx>
#include <NCollection_Handle.hxx>
#include <OpenGl_LineAttributes.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <OpenGl_Material.hxx>

void bind_OpenGl_Context(py::module &mod){

py::class_<OpenGl_Context, opencascade::handle<OpenGl_Context>, Standard_Transient> cls_OpenGl_Context(mod, "OpenGl_Context", "This class generalize access to the GL context and available extensions.");

// Constructors
cls_OpenGl_Context.def(py::init<>());
cls_OpenGl_Context.def(py::init<const opencascade::handle<OpenGl_Caps> &>(), py::arg("theCaps"));

// Fields
// cls_OpenGl_Context.def_readwrite("core11", &OpenGl_Context::core11, "OpenGL 1.1 core functionality");
// cls_OpenGl_Context.def_readwrite("core11fwd", &OpenGl_Context::core11fwd, "OpenGL 1.1 without deprecated entry points");
// cls_OpenGl_Context.def_readwrite("core15", &OpenGl_Context::core15, "OpenGL 1.5 core functionality");
// cls_OpenGl_Context.def_readwrite("core15fwd", &OpenGl_Context::core15fwd, "OpenGL 1.5 without deprecated entry points");
// cls_OpenGl_Context.def_readwrite("core20", &OpenGl_Context::core20, "OpenGL 2.0 core functionality (includes 1.5)");
// cls_OpenGl_Context.def_readwrite("core20fwd", &OpenGl_Context::core20fwd, "OpenGL 2.0 without deprecated entry points");
// cls_OpenGl_Context.def_readwrite("core32", &OpenGl_Context::core32, "OpenGL 3.2 core profile");
// cls_OpenGl_Context.def_readwrite("core32back", &OpenGl_Context::core32back, "OpenGL 3.2 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core33", &OpenGl_Context::core33, "OpenGL 3.3 core profile");
// cls_OpenGl_Context.def_readwrite("core33back", &OpenGl_Context::core33back, "OpenGL 3.3 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core41", &OpenGl_Context::core41, "OpenGL 4.1 core profile");
// cls_OpenGl_Context.def_readwrite("core41back", &OpenGl_Context::core41back, "OpenGL 4.1 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core42", &OpenGl_Context::core42, "OpenGL 4.2 core profile");
// cls_OpenGl_Context.def_readwrite("core42back", &OpenGl_Context::core42back, "OpenGL 4.2 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core43", &OpenGl_Context::core43, "OpenGL 4.3 core profile");
// cls_OpenGl_Context.def_readwrite("core43back", &OpenGl_Context::core43back, "OpenGL 4.3 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core44", &OpenGl_Context::core44, "OpenGL 4.4 core profile");
// cls_OpenGl_Context.def_readwrite("core44back", &OpenGl_Context::core44back, "OpenGL 4.4 backward compatibility profile");
cls_OpenGl_Context.def_readwrite("caps", &OpenGl_Context::caps, "context options");
cls_OpenGl_Context.def_readwrite("hasHighp", &OpenGl_Context::hasHighp, "highp in GLSL ES fragment shader is supported");
cls_OpenGl_Context.def_readwrite("hasUintIndex", &OpenGl_Context::hasUintIndex, "GLuint for index buffer is supported (always available on desktop; on OpenGL ES - since 3.0 or as extension GL_OES_element_index_uint)");
cls_OpenGl_Context.def_readwrite("hasTexRGBA8", &OpenGl_Context::hasTexRGBA8, "always available on desktop; on OpenGL ES - since 3.0 or as extension GL_OES_rgb8_rgba8");
cls_OpenGl_Context.def_readwrite("hasDrawBuffers", &OpenGl_Context::hasDrawBuffers, "Complex flag indicating support of multiple draw buffers (desktop OpenGL 2.0, OpenGL ES 3.0, GL_ARB_draw_buffers, GL_EXT_draw_buffers)");
cls_OpenGl_Context.def_readwrite("hasFloatBuffer", &OpenGl_Context::hasFloatBuffer, "Complex flag indicating support of float color buffer format (desktop OpenGL 3.0, GL_ARB_color_buffer_float, GL_EXT_color_buffer_float)");
cls_OpenGl_Context.def_readwrite("hasHalfFloatBuffer", &OpenGl_Context::hasHalfFloatBuffer, "Complex flag indicating support of half-float color buffer format (desktop OpenGL 3.0, GL_ARB_color_buffer_float, GL_EXT_color_buffer_half_float)");
cls_OpenGl_Context.def_readwrite("hasSampleVariables", &OpenGl_Context::hasSampleVariables, "Complex flag indicating support of MSAA variables in GLSL shader (desktop OpenGL 4.0, GL_ARB_sample_shading)");
cls_OpenGl_Context.def_readwrite("arbDrawBuffers", &OpenGl_Context::arbDrawBuffers, "GL_ARB_draw_buffers");
cls_OpenGl_Context.def_readwrite("arbNPTW", &OpenGl_Context::arbNPTW, "GL_ARB_texture_non_power_of_two");
cls_OpenGl_Context.def_readwrite("arbTexRG", &OpenGl_Context::arbTexRG, "GL_ARB_texture_rg");
cls_OpenGl_Context.def_readwrite("arbTexFloat", &OpenGl_Context::arbTexFloat, "GL_ARB_texture_float (on desktop OpenGL - since 3.0 or as extension GL_ARB_texture_float; on OpenGL ES - since 3.0)");
cls_OpenGl_Context.def_readwrite("arbSamplerObject", &OpenGl_Context::arbSamplerObject, "GL_ARB_sampler_objects (on desktop OpenGL - since 3.3 or as extension GL_ARB_sampler_objects; on OpenGL ES - since 3.0)");
cls_OpenGl_Context.def_readwrite("arbTexBindless", &OpenGl_Context::arbTexBindless, "GL_ARB_bindless_texture");
cls_OpenGl_Context.def_readwrite("arbTBO", &OpenGl_Context::arbTBO, "GL_ARB_texture_buffer_object");
cls_OpenGl_Context.def_readwrite("arbTboRGB32", &OpenGl_Context::arbTboRGB32, "GL_ARB_texture_buffer_object_rgb32 (3-component TBO), in core since 4.0");
cls_OpenGl_Context.def_readwrite("arbIns", &OpenGl_Context::arbIns, "GL_ARB_draw_instanced");
cls_OpenGl_Context.def_readwrite("arbDbg", &OpenGl_Context::arbDbg, "GL_ARB_debug_output");
cls_OpenGl_Context.def_readwrite("arbFBO", &OpenGl_Context::arbFBO, "GL_ARB_framebuffer_object");
cls_OpenGl_Context.def_readwrite("arbFBOBlit", &OpenGl_Context::arbFBOBlit, "glBlitFramebuffer function, moved out from OpenGl_ArbFBO structure for compatibility with OpenGL ES 2.0");
cls_OpenGl_Context.def_readwrite("arbSampleShading", &OpenGl_Context::arbSampleShading, "GL_ARB_sample_shading");
cls_OpenGl_Context.def_readwrite("extFragDepth", &OpenGl_Context::extFragDepth, "GL_EXT_frag_depth on OpenGL ES 2.0 (gl_FragDepthEXT built-in variable, before OpenGL ES 3.0)");
cls_OpenGl_Context.def_readwrite("extDrawBuffers", &OpenGl_Context::extDrawBuffers, "GL_EXT_draw_buffers");
cls_OpenGl_Context.def_readwrite("extGS", &OpenGl_Context::extGS, "GL_EXT_geometry_shader4");
cls_OpenGl_Context.def_readwrite("extBgra", &OpenGl_Context::extBgra, "GL_EXT_bgra or GL_EXT_texture_format_BGRA8888 on OpenGL ES");
cls_OpenGl_Context.def_readwrite("extAnis", &OpenGl_Context::extAnis, "GL_EXT_texture_filter_anisotropic");
cls_OpenGl_Context.def_readwrite("extPDS", &OpenGl_Context::extPDS, "GL_EXT_packed_depth_stencil");
cls_OpenGl_Context.def_readwrite("atiMem", &OpenGl_Context::atiMem, "GL_ATI_meminfo");
cls_OpenGl_Context.def_readwrite("nvxMem", &OpenGl_Context::nvxMem, "GL_NVX_gpu_memory_info");
cls_OpenGl_Context.def_readwrite("oesSampleVariables", &OpenGl_Context::oesSampleVariables, "GL_OES_sample_variables");
cls_OpenGl_Context.def_readwrite("oesStdDerivatives", &OpenGl_Context::oesStdDerivatives, "GL_OES_standard_derivatives");
cls_OpenGl_Context.def_readwrite("ModelWorldState", &OpenGl_Context::ModelWorldState, "state of orientation matrix");
cls_OpenGl_Context.def_readwrite("WorldViewState", &OpenGl_Context::WorldViewState, "state of orientation matrix");
cls_OpenGl_Context.def_readwrite("ProjectionState", &OpenGl_Context::ProjectionState, "state of projection matrix");

// Methods
cls_OpenGl_Context.def_static("get_type_name_", (const char * (*)()) &OpenGl_Context::get_type_name, "None");
cls_OpenGl_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Context::get_type_descriptor, "None");
cls_OpenGl_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Context::*)() const) &OpenGl_Context::DynamicType, "None");
cls_OpenGl_Context.def_static("GetPowerOfTwo_", (Standard_Integer (*)(const Standard_Integer, const Standard_Integer)) &OpenGl_Context::GetPowerOfTwo, "Function for getting power of to number larger or equal to input number.", py::arg("theNumber"), py::arg("theThreshold"));
cls_OpenGl_Context.def("forcedRelease", (void (OpenGl_Context::*)()) &OpenGl_Context::forcedRelease, "Release all resources, including shared ones");
cls_OpenGl_Context.def("Share", (void (OpenGl_Context::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Context::Share, "Share GL context resources. theShareCtx - handle to context to retrieve handles to shared resources.", py::arg("theShareCtx"));
cls_OpenGl_Context.def("Init", [](OpenGl_Context &self) -> Standard_Boolean { return self.Init(); });
cls_OpenGl_Context.def("Init", (Standard_Boolean (OpenGl_Context::*)(const Standard_Boolean)) &OpenGl_Context::Init, "Initialize class from currently bound OpenGL context. Method should be called only once.", py::arg("theIsCoreProfile"));
cls_OpenGl_Context.def("IsValid", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsValid, "Returns true if this context is valid (has been initialized)");
cls_OpenGl_Context.def("Init", [](OpenGl_Context &self, const Aspect_Handle a0, const Aspect_Handle a1, const Aspect_RenderingContext a2) -> Standard_Boolean { return self.Init(a0, a1, a2); });
cls_OpenGl_Context.def("Init", (Standard_Boolean (OpenGl_Context::*)(const Aspect_Handle, const Aspect_Handle, const Aspect_RenderingContext, const Standard_Boolean)) &OpenGl_Context::Init, "Initialize class from specified window and rendering context. Method should be called only once.", py::arg("theWindow"), py::arg("theWindowDC"), py::arg("theGContext"), py::arg("theIsCoreProfile"));
cls_OpenGl_Context.def("Window", (Aspect_Handle (OpenGl_Context::*)() const) &OpenGl_Context::Window, "Returns the window handle (HWND) currently bound to this OpenGL context");
cls_OpenGl_Context.def_static("ReadGlVersion_", [](Standard_Integer & theGlVerMajor, Standard_Integer & theGlVerMinor){ OpenGl_Context::ReadGlVersion(theGlVerMajor, theGlVerMinor); return std::tuple<Standard_Integer &, Standard_Integer &>(theGlVerMajor, theGlVerMinor); }, "Read OpenGL version information from active context.", py::arg("theGlVerMajor"), py::arg("theGlVerMinor"));
cls_OpenGl_Context.def("CheckExtension", (Standard_Boolean (OpenGl_Context::*)(const char *) const) &OpenGl_Context::CheckExtension, "Check if theExtName extension is supported by active GL context.", py::arg("theExtName"));
cls_OpenGl_Context.def_static("CheckExtension_", (Standard_Boolean (*)(const char *, const char *)) &OpenGl_Context::CheckExtension, "Check if theExtName extension is in extensions string.", py::arg("theExtString"), py::arg("theExtName"));
cls_OpenGl_Context.def("IsGlGreaterEqual", (Standard_Boolean (OpenGl_Context::*)(const Standard_Integer, const Standard_Integer) const) &OpenGl_Context::IsGlGreaterEqual, "Returns true if detected GL version is greater or equal to requested one.", py::arg("theVerMajor"), py::arg("theVerMinor"));
cls_OpenGl_Context.def("VersionMajor", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::VersionMajor, "Return cached GL version major number.");
cls_OpenGl_Context.def("VersionMinor", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::VersionMinor, "Return cached GL version minor number.");
cls_OpenGl_Context.def("Functions", (const OpenGl_GlFunctions * (OpenGl_Context::*)() const) &OpenGl_Context::Functions, "Access entire map of loaded OpenGL functions.");
cls_OpenGl_Context.def("ResetErrors", [](OpenGl_Context &self) -> bool { return self.ResetErrors(); });
cls_OpenGl_Context.def("ResetErrors", (bool (OpenGl_Context::*)(const bool)) &OpenGl_Context::ResetErrors, "Clean up errors stack for this GL context (glGetError() in loop).", py::arg("theToPrintErrors"));
cls_OpenGl_Context.def("IsCurrent", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsCurrent, "This method uses system-dependent API to retrieve information about GL context bound to the current thread.");
cls_OpenGl_Context.def("MakeCurrent", (Standard_Boolean (OpenGl_Context::*)()) &OpenGl_Context::MakeCurrent, "Activates current context. Class should be initialized with appropriate info.");
cls_OpenGl_Context.def("SwapBuffers", (void (OpenGl_Context::*)()) &OpenGl_Context::SwapBuffers, "Swap front/back buffers for this GL context (should be activated before!).");
cls_OpenGl_Context.def("SetSwapInterval", (Standard_Boolean (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetSwapInterval, "Setup swap interval (VSync).", py::arg("theInterval"));
cls_OpenGl_Context.def("IsRender", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsRender, "Return true if active mode is GL_RENDER (cached state)");
cls_OpenGl_Context.def("IsFeedback", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsFeedback, "Return true if active mode is GL_FEEDBACK (cached state)");
cls_OpenGl_Context.def("AvailableMemory", (Standard_Size (OpenGl_Context::*)() const) &OpenGl_Context::AvailableMemory, "This function retrieves information from GL about free GPU memory that is: - OS-dependent. On some OS it is per-process and on others - for entire system. - Vendor-dependent. Currently available only on NVIDIA and AMD/ATi drivers only. - Numbers meaning may vary. You should use this info only for diagnostics purposes.");
cls_OpenGl_Context.def("MemoryInfo", (TCollection_AsciiString (OpenGl_Context::*)() const) &OpenGl_Context::MemoryInfo, "This function retrieves information from GL about GPU memory and contains more vendor-specific values than AvailableMemory().");
cls_OpenGl_Context.def("MemoryInfo", (void (OpenGl_Context::*)(TColStd_IndexedDataMapOfStringString &) const) &OpenGl_Context::MemoryInfo, "This function retrieves information from GL about GPU memory.", py::arg("theDict"));
cls_OpenGl_Context.def("DiagnosticInformation", (void (OpenGl_Context::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &OpenGl_Context::DiagnosticInformation, "Fill in the dictionary with OpenGL info. Should be called with bound context.", py::arg("theDict"), py::arg("theFlags"));
cls_OpenGl_Context.def("GetResource", (const opencascade::handle<OpenGl_Resource> & (OpenGl_Context::*)(const TCollection_AsciiString &) const) &OpenGl_Context::GetResource, "Access shared resource by its name.", py::arg("theKey"));
cls_OpenGl_Context.def("ShareResource", (Standard_Boolean (OpenGl_Context::*)(const TCollection_AsciiString &, const opencascade::handle<OpenGl_Resource> &)) &OpenGl_Context::ShareResource, "Register shared resource. Notice that after registration caller shouldn't release it by himself - it will be automatically released on context destruction.", py::arg("theKey"), py::arg("theResource"));
cls_OpenGl_Context.def("ReleaseResource", [](OpenGl_Context &self, const TCollection_AsciiString & a0) -> void { return self.ReleaseResource(a0); });
cls_OpenGl_Context.def("ReleaseResource", (void (OpenGl_Context::*)(const TCollection_AsciiString &, const Standard_Boolean)) &OpenGl_Context::ReleaseResource, "Release shared resource. If there are more than one reference to this resource (also used by some other existing object) then call will be ignored. This means that current object itself should nullify handle before this call. Notice that this is unrecommended operation at all and should be used only in case of fat resources to release memory for other needs.", py::arg("theKey"), py::arg("theToDelay"));
cls_OpenGl_Context.def("ReleaseDelayed", (void (OpenGl_Context::*)()) &OpenGl_Context::ReleaseDelayed, "Clean up the delayed release queue.");
cls_OpenGl_Context.def("SharedResources", (const OpenGl_Context::OpenGl_ResourcesMap & (OpenGl_Context::*)() const) &OpenGl_Context::SharedResources, "Return map of shared resources.");
cls_OpenGl_Context.def("ChangeClipping", (OpenGl_Clipping & (OpenGl_Context::*)()) &OpenGl_Context::ChangeClipping, "Returns tool for management of clippings within this context.");
cls_OpenGl_Context.def("Clipping", (const OpenGl_Clipping & (OpenGl_Context::*)() const) &OpenGl_Context::Clipping, "Returns tool for management of clippings within this context.");
cls_OpenGl_Context.def("ShaderManager", (const opencascade::handle<OpenGl_ShaderManager> & (OpenGl_Context::*)() const) &OpenGl_Context::ShaderManager, "Returns tool for management of shader programs within this context.");
cls_OpenGl_Context.def("TextureWrapClamp", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::TextureWrapClamp, "Either GL_CLAMP_TO_EDGE (1.2+) or GL_CLAMP (1.1).");
cls_OpenGl_Context.def("MaxDegreeOfAnisotropy", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxDegreeOfAnisotropy, "Returns maximum degree of anisotropy texture filter");
cls_OpenGl_Context.def("MaxTextureSize", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxTextureSize, "Returns value for GL_MAX_TEXTURE_SIZE");
cls_OpenGl_Context.def("MaxCombinedTextureUnits", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxCombinedTextureUnits, "Returns value for GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS");
cls_OpenGl_Context.def("MaxMsaaSamples", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxMsaaSamples, "Returns value for GL_MAX_SAMPLES");
cls_OpenGl_Context.def("MaxDrawBuffers", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxDrawBuffers, "Returns value for GL_MAX_DRAW_BUFFERS");
cls_OpenGl_Context.def("MaxColorAttachments", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxColorAttachments, "Returns value for GL_MAX_COLOR_ATTACHMENTS");
cls_OpenGl_Context.def("MaxClipPlanes", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxClipPlanes, "Get maximum number of clip planes supported by OpenGl. This value is implementation dependent. At least 6 planes should be supported by OpenGl (see specs).");
cls_OpenGl_Context.def("HasRayTracing", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracing, "Returns TRUE if ray tracing mode is supported");
cls_OpenGl_Context.def("HasRayTracingTextures", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracingTextures, "Returns TRUE if textures in ray tracing mode are supported");
cls_OpenGl_Context.def("HasRayTracingAdaptiveSampling", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracingAdaptiveSampling, "Returns TRUE if adaptive screen sampling in ray tracing mode is supported");
cls_OpenGl_Context.def("ToUseVbo", (bool (OpenGl_Context::*)() const) &OpenGl_Context::ToUseVbo, "Returns true if VBO is supported and permitted.");
cls_OpenGl_Context.def("IsGlNormalizeEnabled", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsGlNormalizeEnabled, "Returns cached state of GL_NORMALIZE.");
cls_OpenGl_Context.def("SetGlNormalizeEnabled", (Standard_Boolean (OpenGl_Context::*)(Standard_Boolean)) &OpenGl_Context::SetGlNormalizeEnabled, "Sets GL_NORMALIZE enabled or disabled.", py::arg("isEnabled"));
cls_OpenGl_Context.def("PolygonMode", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::PolygonMode, "Returns cached state of polygon rasterization mode (glPolygonMode()).");
cls_OpenGl_Context.def("SetPolygonMode", (Standard_Integer (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetPolygonMode, "Sets polygon rasterization mode (glPolygonMode() function).", py::arg("theMode"));
cls_OpenGl_Context.def("IsPolygonHatchEnabled", (bool (OpenGl_Context::*)() const) &OpenGl_Context::IsPolygonHatchEnabled, "Returns cached enabled state of polygon hatching rasterization.");
cls_OpenGl_Context.def("SetPolygonHatchEnabled", (bool (OpenGl_Context::*)(const bool)) &OpenGl_Context::SetPolygonHatchEnabled, "Sets enabled state of polygon hatching rasterization without affecting currently selected hatching pattern.", py::arg("theIsEnabled"));
cls_OpenGl_Context.def("PolygonHatchStyle", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::PolygonHatchStyle, "Returns cached state of polygon hatch type.");
cls_OpenGl_Context.def("SetPolygonHatchStyle", (Standard_Integer (OpenGl_Context::*)(const opencascade::handle<Graphic3d_HatchStyle> &)) &OpenGl_Context::SetPolygonHatchStyle, "Sets polygon hatch pattern. Zero-index value is a default alias for solid filling.", py::arg("theStyle"));
cls_OpenGl_Context.def("SetPolygonOffset", (void (OpenGl_Context::*)(const Graphic3d_PolygonOffset &)) &OpenGl_Context::SetPolygonOffset, "Sets and applies current polygon offset.", py::arg("theOffset"));
cls_OpenGl_Context.def("PolygonOffset", (const Graphic3d_PolygonOffset & (OpenGl_Context::*)() const) &OpenGl_Context::PolygonOffset, "Returns currently applied polygon offset parameters.");
cls_OpenGl_Context.def("ApplyModelWorldMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyModelWorldMatrix, "Applies matrix stored in ModelWorldState to OpenGl.");
cls_OpenGl_Context.def("ApplyWorldViewMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyWorldViewMatrix, "Applies matrix stored in WorldViewState to OpenGl.");
cls_OpenGl_Context.def("ApplyModelViewMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyModelViewMatrix, "Applies combination of matrices stored in ModelWorldState and WorldViewState to OpenGl.");
cls_OpenGl_Context.def("ApplyProjectionMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyProjectionMatrix, "Applies matrix stored in ProjectionState to OpenGl.");
cls_OpenGl_Context.def("Messenger", (const opencascade::handle<Message_Messenger> & (OpenGl_Context::*)() const) &OpenGl_Context::Messenger, "Returns messenger instance");
cls_OpenGl_Context.def("PushMessage", (void (OpenGl_Context::*)(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const TCollection_ExtendedString &)) &OpenGl_Context::PushMessage, "Callback for GL_ARB_debug_output extension", py::arg("theSource"), py::arg("theType"), py::arg("theId"), py::arg("theSeverity"), py::arg("theMessage"));
cls_OpenGl_Context.def("ExcludeMessage", (Standard_Boolean (OpenGl_Context::*)(const unsigned int, const unsigned int)) &OpenGl_Context::ExcludeMessage, "Adds a filter for messages with theId and theSource (GL_DEBUG_SOURCE_)", py::arg("theSource"), py::arg("theId"));
cls_OpenGl_Context.def("IncludeMessage", (Standard_Boolean (OpenGl_Context::*)(const unsigned int, const unsigned int)) &OpenGl_Context::IncludeMessage, "Removes a filter for messages with theId and theSource (GL_DEBUG_SOURCE_)", py::arg("theSource"), py::arg("theId"));
cls_OpenGl_Context.def("HasStereoBuffers", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasStereoBuffers, "Returns true if OpenGl context supports left and right rendering buffers.");
cls_OpenGl_Context.def("FrameStats", (const opencascade::handle<OpenGl_FrameStats> & (OpenGl_Context::*)() const) &OpenGl_Context::FrameStats, "Return structure holding frame statistics.");
cls_OpenGl_Context.def("Viewport", (const Standard_Integer * (OpenGl_Context::*)() const) &OpenGl_Context::Viewport, "Return cached viewport definition (x, y, width, height).");
// cls_OpenGl_Context.def("ResizeViewport", (void (OpenGl_Context::*)(const Standard_Integer [4])) &OpenGl_Context::ResizeViewport, "Resize the viewport (alias for glViewport).", py::arg("theRect"));
cls_OpenGl_Context.def("VirtualViewport", (const Standard_Integer * (OpenGl_Context::*)() const) &OpenGl_Context::VirtualViewport, "Return virtual viewport definition (x, y, width, height).");
cls_OpenGl_Context.def("ReadBuffer", (Standard_Integer (OpenGl_Context::*)()) &OpenGl_Context::ReadBuffer, "Return active read buffer.");
cls_OpenGl_Context.def("SetReadBuffer", (void (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetReadBuffer, "Switch read buffer, wrapper for ::glReadBuffer().", py::arg("theReadBuffer"));
cls_OpenGl_Context.def("DrawBuffer", [](OpenGl_Context &self) -> Standard_Integer { return self.DrawBuffer(); });
cls_OpenGl_Context.def("DrawBuffer", (Standard_Integer (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::DrawBuffer, "Return active draw buffer attached to a render target referred by index (layout location).", py::arg("theIndex"));
cls_OpenGl_Context.def("SetDrawBuffer", (void (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetDrawBuffer, "Switch draw buffer, wrapper for ::glDrawBuffer().", py::arg("theDrawBuffer"));
cls_OpenGl_Context.def("SetDrawBuffers", (void (OpenGl_Context::*)(const Standard_Integer, const Standard_Integer *)) &OpenGl_Context::SetDrawBuffers, "Switch draw buffer, wrapper for ::glDrawBuffers (GLsizei, const GLenum*).", py::arg("theNb"), py::arg("theDrawBuffers"));
cls_OpenGl_Context.def("SetReadDrawBuffer", (void (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetReadDrawBuffer, "Switch read/draw buffers.", py::arg("theBuffer"));
cls_OpenGl_Context.def("ColorMask", (bool (OpenGl_Context::*)() const) &OpenGl_Context::ColorMask, "Return cached flag indicating writing into color buffer is enabled or disabled (glColorMask).");
cls_OpenGl_Context.def("SetColorMask", (bool (OpenGl_Context::*)(bool)) &OpenGl_Context::SetColorMask, "Enable/disable writing into color buffer (wrapper for glColorMask).", py::arg("theToWriteColor"));
cls_OpenGl_Context.def("SampleAlphaToCoverage", (bool (OpenGl_Context::*)() const) &OpenGl_Context::SampleAlphaToCoverage, "Return GL_SAMPLE_ALPHA_TO_COVERAGE state.");
cls_OpenGl_Context.def("SetSampleAlphaToCoverage", (bool (OpenGl_Context::*)(bool)) &OpenGl_Context::SetSampleAlphaToCoverage, "Enable/disable GL_SAMPLE_ALPHA_TO_COVERAGE.", py::arg("theToEnable"));
cls_OpenGl_Context.def("ToCullBackFaces", (bool (OpenGl_Context::*)() const) &OpenGl_Context::ToCullBackFaces, "Return back face culling state.");
cls_OpenGl_Context.def("SetCullBackFaces", (void (OpenGl_Context::*)(bool)) &OpenGl_Context::SetCullBackFaces, "Enable or disable back face culling (glEnable (GL_CULL_FACE)).", py::arg("theToEnable"));
cls_OpenGl_Context.def("FetchState", (void (OpenGl_Context::*)()) &OpenGl_Context::FetchState, "Fetch OpenGl context state. This class tracks value of several OpenGl state variables. Consulting the cached values is quicker than doing the same via OpenGl API. Call this method if any of the controlled OpenGl state variables has a possibility of being out-of-date.");
cls_OpenGl_Context.def("ActiveTextures", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_Context::*)() const) &OpenGl_Context::ActiveTextures, "Returns active textures");
cls_OpenGl_Context.def("BindTextures", (opencascade::handle<OpenGl_TextureSet> (OpenGl_Context::*)(const opencascade::handle<OpenGl_TextureSet> &)) &OpenGl_Context::BindTextures, "Bind specified texture set to current context, or unbind previous one when NULL specified.", py::arg("theTextures"));
cls_OpenGl_Context.def("ActiveProgram", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_Context::*)() const) &OpenGl_Context::ActiveProgram, "Returns active GLSL program");
cls_OpenGl_Context.def("BindProgram", (Standard_Boolean (OpenGl_Context::*)(const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_Context::BindProgram, "Bind specified program to current context, or unbind previous one when NULL specified.", py::arg("theProgram"));
cls_OpenGl_Context.def("SetShadingMaterial", (void (OpenGl_Context::*)(const OpenGl_AspectFace *, const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Context::SetShadingMaterial, "Setup current shading material.", py::arg("theAspect"), py::arg("theHighlight"));
cls_OpenGl_Context.def_static("CheckIsTransparent_", (Standard_Boolean (*)(const OpenGl_AspectFace *, const opencascade::handle<Graphic3d_PresentationAttributes> &, Standard_ShortReal &, Standard_ShortReal &)) &OpenGl_Context::CheckIsTransparent, "Checks if transparency is required for the given aspect and highlight style.", py::arg("theAspect"), py::arg("theHighlight"), py::arg("theAlphaFront"), py::arg("theAlphaBack"));
cls_OpenGl_Context.def_static("CheckIsTransparent_", (Standard_Boolean (*)(const OpenGl_AspectFace *, const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Context::CheckIsTransparent, "Checks if transparency is required for the given aspect and highlight style.", py::arg("theAspect"), py::arg("theHighlight"));
cls_OpenGl_Context.def("SetColor4fv", (void (OpenGl_Context::*)(const OpenGl_Vec4 &)) &OpenGl_Context::SetColor4fv, "Setup current color.", py::arg("theColor"));
cls_OpenGl_Context.def("SetTypeOfLine", [](OpenGl_Context &self, const Aspect_TypeOfLine a0) -> void { return self.SetTypeOfLine(a0); });
cls_OpenGl_Context.def("SetTypeOfLine", (void (OpenGl_Context::*)(const Aspect_TypeOfLine, const Standard_ShortReal)) &OpenGl_Context::SetTypeOfLine, "Setup type of line.", py::arg("theType"), py::arg("theFactor"));
cls_OpenGl_Context.def("SetLineWidth", (void (OpenGl_Context::*)(const Standard_ShortReal)) &OpenGl_Context::SetLineWidth, "Setup width of line.", py::arg("theWidth"));
cls_OpenGl_Context.def("SetPointSize", (void (OpenGl_Context::*)(const Standard_ShortReal)) &OpenGl_Context::SetPointSize, "Setup point size.", py::arg("theSize"));
cls_OpenGl_Context.def("SetPointSpriteOrigin", (void (OpenGl_Context::*)()) &OpenGl_Context::SetPointSpriteOrigin, "Setup point sprite origin using GL_POINT_SPRITE_COORD_ORIGIN state: - GL_UPPER_LEFT when GLSL program is active; flipping should be handled in GLSL program for compatibility with OpenGL ES - GL_LOWER_LEFT for FFP");
cls_OpenGl_Context.def("SetTextureMatrix", (void (OpenGl_Context::*)(const opencascade::handle<Graphic3d_TextureParams> &)) &OpenGl_Context::SetTextureMatrix, "Setup texture matrix to active GLSL program or to FFP global state using glMatrixMode (GL_TEXTURE).", py::arg("theParams"));
cls_OpenGl_Context.def("BindDefaultVao", (void (OpenGl_Context::*)()) &OpenGl_Context::BindDefaultVao, "Bind default Vertex Array Object");
cls_OpenGl_Context.def("DefaultFrameBuffer", (const opencascade::handle<OpenGl_FrameBuffer> & (OpenGl_Context::*)() const) &OpenGl_Context::DefaultFrameBuffer, "Default Frame Buffer Object.");
cls_OpenGl_Context.def("SetDefaultFrameBuffer", (opencascade::handle<OpenGl_FrameBuffer> (OpenGl_Context::*)(const opencascade::handle<OpenGl_FrameBuffer> &)) &OpenGl_Context::SetDefaultFrameBuffer, "Setup new Default Frame Buffer Object and return previously set. This call doesn't change Active FBO!", py::arg("theFbo"));
cls_OpenGl_Context.def("IsDebugContext", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsDebugContext, "Return debug context initialization state.");
cls_OpenGl_Context.def("EnableFeatures", (void (OpenGl_Context::*)() const) &OpenGl_Context::EnableFeatures, "None");
cls_OpenGl_Context.def("DisableFeatures", (void (OpenGl_Context::*)() const) &OpenGl_Context::DisableFeatures, "None");
cls_OpenGl_Context.def("Resolution", (unsigned int (OpenGl_Context::*)() const) &OpenGl_Context::Resolution, "Return resolution for rendering text.");
cls_OpenGl_Context.def("ResolutionRatio", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::ResolutionRatio, "Resolution scale factor (rendered resolution to standard resolution). This scaling factor for parameters like text size to be properly displayed on device (screen / printer).");
cls_OpenGl_Context.def("RenderScale", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::RenderScale, "Rendering scale factor (rendering viewport height to real window buffer height).");
cls_OpenGl_Context.def("HasRenderScale", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRenderScale, "Return TRUE if rendering scale factor is not 1.");
cls_OpenGl_Context.def("RenderScaleInv", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::RenderScaleInv, "Rendering scale factor (inverted value).");
cls_OpenGl_Context.def("SetResolution", (void (OpenGl_Context::*)(unsigned int, Standard_ShortReal, Standard_ShortReal)) &OpenGl_Context::SetResolution, "Set resolution ratio. Note that this method rounds to nearest integer.", py::arg("theResolution"), py::arg("theRatio"), py::arg("theScale"));
cls_OpenGl_Context.def("SetResolutionRatio", (void (OpenGl_Context::*)(const Standard_ShortReal)) &OpenGl_Context::SetResolutionRatio, "Set resolution ratio. Note that this method rounds to nearest integer.", py::arg("theRatio"));

// Enums

}