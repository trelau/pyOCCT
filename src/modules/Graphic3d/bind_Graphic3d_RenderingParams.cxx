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
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_Vec4.hxx>
#include <Graphic3d_RenderingMode.hxx>
#include <Graphic3d_RenderTransparentMethod.hxx>
#include <Graphic3d_ToneMappingMethod.hxx>
#include <Graphic3d_StereoMode.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <Graphic3d_Mat4.hxx>
#include <Standard_Handle.hxx>

void bind_Graphic3d_RenderingParams(py::module &mod){

py::class_<Graphic3d_RenderingParams, std::unique_ptr<Graphic3d_RenderingParams, Deleter<Graphic3d_RenderingParams>>> cls_Graphic3d_RenderingParams(mod, "Graphic3d_RenderingParams", "Helper class to store rendering parameters.");

// Constructors
cls_Graphic3d_RenderingParams.def(py::init<>());

// Fields
cls_Graphic3d_RenderingParams.def_readwrite("Method", &Graphic3d_RenderingParams::Method, "specifies rendering mode, Graphic3d_RM_RASTERIZATION by default");
cls_Graphic3d_RenderingParams.def_readwrite("TransparencyMethod", &Graphic3d_RenderingParams::TransparencyMethod, "specifies rendering method for transparent graphics");
cls_Graphic3d_RenderingParams.def_readwrite("OitDepthFactor", &Graphic3d_RenderingParams::OitDepthFactor, "scalar factor [0-1] controlling influence of depth of a fragment to its final coverage");
cls_Graphic3d_RenderingParams.def_readwrite("NbMsaaSamples", &Graphic3d_RenderingParams::NbMsaaSamples, "number of MSAA samples (should be within 0..GL_MAX_SAMPLES, power-of-two number), 0 by default");
cls_Graphic3d_RenderingParams.def_readwrite("RenderResolutionScale", &Graphic3d_RenderingParams::RenderResolutionScale, "rendering resolution scale factor, 1 by default;");
cls_Graphic3d_RenderingParams.def_readwrite("ToEnableDepthPrepass", &Graphic3d_RenderingParams::ToEnableDepthPrepass, "enables/disables depth pre-pass, False by default");
cls_Graphic3d_RenderingParams.def_readwrite("ToEnableAlphaToCoverage", &Graphic3d_RenderingParams::ToEnableAlphaToCoverage, "enables/disables alpha to coverage, False by default");
cls_Graphic3d_RenderingParams.def_readwrite("IsGlobalIlluminationEnabled", &Graphic3d_RenderingParams::IsGlobalIlluminationEnabled, "enables/disables global illumination effects (path tracing)");
cls_Graphic3d_RenderingParams.def_readwrite("SamplesPerPixel", &Graphic3d_RenderingParams::SamplesPerPixel, "number of samples per pixel (SPP)");
cls_Graphic3d_RenderingParams.def_readwrite("RaytracingDepth", &Graphic3d_RenderingParams::RaytracingDepth, "maximum ray-tracing depth, 3 by default");
cls_Graphic3d_RenderingParams.def_readwrite("IsShadowEnabled", &Graphic3d_RenderingParams::IsShadowEnabled, "enables/disables shadows rendering, True by default");
cls_Graphic3d_RenderingParams.def_readwrite("IsReflectionEnabled", &Graphic3d_RenderingParams::IsReflectionEnabled, "enables/disables specular reflections, False by default");
cls_Graphic3d_RenderingParams.def_readwrite("IsAntialiasingEnabled", &Graphic3d_RenderingParams::IsAntialiasingEnabled, "enables/disables adaptive anti-aliasing, False by default");
cls_Graphic3d_RenderingParams.def_readwrite("IsTransparentShadowEnabled", &Graphic3d_RenderingParams::IsTransparentShadowEnabled, "enables/disables light propagation through transparent media, False by default");
cls_Graphic3d_RenderingParams.def_readwrite("UseEnvironmentMapBackground", &Graphic3d_RenderingParams::UseEnvironmentMapBackground, "enables/disables environment map background");
cls_Graphic3d_RenderingParams.def_readwrite("CoherentPathTracingMode", &Graphic3d_RenderingParams::CoherentPathTracingMode, "enables/disables 'coherent' tracing mode (single RNG seed within 16x16 image blocks)");
cls_Graphic3d_RenderingParams.def_readwrite("AdaptiveScreenSampling", &Graphic3d_RenderingParams::AdaptiveScreenSampling, "enables/disables adaptive screen sampling mode for path tracing, FALSE by default");
cls_Graphic3d_RenderingParams.def_readwrite("ShowSamplingTiles", &Graphic3d_RenderingParams::ShowSamplingTiles, "enables/disables debug mode for adaptive screen sampling, FALSE by default");
cls_Graphic3d_RenderingParams.def_readwrite("TwoSidedBsdfModels", &Graphic3d_RenderingParams::TwoSidedBsdfModels, "forces path tracing to use two-sided versions of original one-sided scattering models");
cls_Graphic3d_RenderingParams.def_readwrite("RadianceClampingValue", &Graphic3d_RenderingParams::RadianceClampingValue, "maximum radiance value used for clamping radiance estimation.");
cls_Graphic3d_RenderingParams.def_readwrite("RebuildRayTracingShaders", &Graphic3d_RenderingParams::RebuildRayTracingShaders, "forces rebuilding ray tracing shaders at the next frame");
cls_Graphic3d_RenderingParams.def_readwrite("NbRayTracingTiles", &Graphic3d_RenderingParams::NbRayTracingTiles, "total number of screen tiles used in adaptive sampling mode (PT only)");
cls_Graphic3d_RenderingParams.def_readwrite("CameraApertureRadius", &Graphic3d_RenderingParams::CameraApertureRadius, "aperture radius of perspective camera used for depth-of-field, 0.0 by default (no DOF) (path tracing only)");
cls_Graphic3d_RenderingParams.def_readwrite("CameraFocalPlaneDist", &Graphic3d_RenderingParams::CameraFocalPlaneDist, "focal distance of perspective camera used for depth-of field, 1.0 by default (path tracing only)");
cls_Graphic3d_RenderingParams.def_readwrite("ToneMappingMethod", &Graphic3d_RenderingParams::ToneMappingMethod, "specifies tone mapping method for path tracing, Graphic3d_ToneMappingMethod_Disabled by default");
cls_Graphic3d_RenderingParams.def_readwrite("Exposure", &Graphic3d_RenderingParams::Exposure, "exposure value used for tone mapping (path tracing), 0.0 by default");
cls_Graphic3d_RenderingParams.def_readwrite("WhitePoint", &Graphic3d_RenderingParams::WhitePoint, "white point value used in filmic tone mapping (path tracing), 1.0 by default");
cls_Graphic3d_RenderingParams.def_readwrite("StereoMode", &Graphic3d_RenderingParams::StereoMode, "stereoscopic output mode, Graphic3d_StereoMode_QuadBuffer by default");
cls_Graphic3d_RenderingParams.def_readwrite("AnaglyphFilter", &Graphic3d_RenderingParams::AnaglyphFilter, "filter for anaglyph output, Anaglyph_RedCyan_Optimized by default");
cls_Graphic3d_RenderingParams.def_readwrite("AnaglyphLeft", &Graphic3d_RenderingParams::AnaglyphLeft, "left anaglyph filter (in normalized colorspace), Color = AnaglyphRight * theColorRight + AnaglyphLeft * theColorLeft;");
cls_Graphic3d_RenderingParams.def_readwrite("AnaglyphRight", &Graphic3d_RenderingParams::AnaglyphRight, "right anaglyph filter (in normalized colorspace), Color = AnaglyphRight * theColorRight + AnaglyphLeft * theColorLeft;");
cls_Graphic3d_RenderingParams.def_readwrite("ToReverseStereo", &Graphic3d_RenderingParams::ToReverseStereo, "flag to reverse stereo pair, FALSE by default");
cls_Graphic3d_RenderingParams.def_readwrite("StatsPosition", &Graphic3d_RenderingParams::StatsPosition, "location of stats, upper-left position by default");
cls_Graphic3d_RenderingParams.def_readwrite("StatsTextAspect", &Graphic3d_RenderingParams::StatsTextAspect, "stats text aspect");
cls_Graphic3d_RenderingParams.def_readwrite("StatsUpdateInterval", &Graphic3d_RenderingParams::StatsUpdateInterval, "time interval between stats updates in seconds, 1.0 second by default;");
cls_Graphic3d_RenderingParams.def_readwrite("StatsTextHeight", &Graphic3d_RenderingParams::StatsTextHeight, "stats text size; 16 by default");
cls_Graphic3d_RenderingParams.def_readwrite("CollectedStats", &Graphic3d_RenderingParams::CollectedStats, "performance counters to collect, PerfCounters_Basic by default;");
cls_Graphic3d_RenderingParams.def_readwrite("ToShowStats", &Graphic3d_RenderingParams::ToShowStats, "display performance statistics, FALSE by default;");
cls_Graphic3d_RenderingParams.def_readwrite("Resolution", &Graphic3d_RenderingParams::Resolution, "Pixels density (PPI), defines scaling factor for parameters like text size");

// Methods
cls_Graphic3d_RenderingParams.def("ResolutionRatio", (Standard_ShortReal (Graphic3d_RenderingParams::*)() const) &Graphic3d_RenderingParams::ResolutionRatio, "Returns resolution ratio.");

// Enums
py::enum_<Graphic3d_RenderingParams::Anaglyph>(cls_Graphic3d_RenderingParams, "Anaglyph", "Anaglyph filter presets.")
	.value("Anaglyph_RedCyan_Simple", Graphic3d_RenderingParams::Anaglyph::Anaglyph_RedCyan_Simple)
	.value("Anaglyph_RedCyan_Optimized", Graphic3d_RenderingParams::Anaglyph::Anaglyph_RedCyan_Optimized)
	.value("Anaglyph_YellowBlue_Simple", Graphic3d_RenderingParams::Anaglyph::Anaglyph_YellowBlue_Simple)
	.value("Anaglyph_YellowBlue_Optimized", Graphic3d_RenderingParams::Anaglyph::Anaglyph_YellowBlue_Optimized)
	.value("Anaglyph_GreenMagenta_Simple", Graphic3d_RenderingParams::Anaglyph::Anaglyph_GreenMagenta_Simple)
	.value("Anaglyph_UserDefined", Graphic3d_RenderingParams::Anaglyph::Anaglyph_UserDefined)
	.export_values();
py::enum_<Graphic3d_RenderingParams::PerfCounters>(cls_Graphic3d_RenderingParams, "PerfCounters", "Statistics display flags.")
	.value("PerfCounters_NONE", Graphic3d_RenderingParams::PerfCounters::PerfCounters_NONE)
	.value("PerfCounters_FrameRate", Graphic3d_RenderingParams::PerfCounters::PerfCounters_FrameRate)
	.value("PerfCounters_CPU", Graphic3d_RenderingParams::PerfCounters::PerfCounters_CPU)
	.value("PerfCounters_Layers", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Layers)
	.value("PerfCounters_Structures", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Structures)
	.value("PerfCounters_Groups", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Groups)
	.value("PerfCounters_GroupArrays", Graphic3d_RenderingParams::PerfCounters::PerfCounters_GroupArrays)
	.value("PerfCounters_Triangles", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Triangles)
	.value("PerfCounters_Points", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Points)
	.value("PerfCounters_EstimMem", Graphic3d_RenderingParams::PerfCounters::PerfCounters_EstimMem)
	.value("PerfCounters_Basic", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Basic)
	.value("PerfCounters_Extended", Graphic3d_RenderingParams::PerfCounters::PerfCounters_Extended)
	.export_values();

}