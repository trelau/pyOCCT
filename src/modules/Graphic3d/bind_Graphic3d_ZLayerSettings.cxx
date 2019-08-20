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
#include <Precision.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_LightSet.hxx>
#include <gp_XYZ.hxx>
#include <Geom_Transformation.hxx>
#include <gp.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Graphic3d_ZLayerSettings.hxx>

void bind_Graphic3d_ZLayerSettings(py::module &mod){

py::class_<Graphic3d_ZLayerSettings, std::unique_ptr<Graphic3d_ZLayerSettings>> cls_Graphic3d_ZLayerSettings(mod, "Graphic3d_ZLayerSettings", "Structure defines list of ZLayer properties.");

// Constructors
cls_Graphic3d_ZLayerSettings.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_ZLayerSettings.def("Name", (const TCollection_AsciiString & (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::Name, "Return user-provided name.");
cls_Graphic3d_ZLayerSettings.def("SetName", (void (Graphic3d_ZLayerSettings::*)(const TCollection_AsciiString &)) &Graphic3d_ZLayerSettings::SetName, "Set custom name.", py::arg("theName"));
cls_Graphic3d_ZLayerSettings.def("Lights", (const opencascade::handle<Graphic3d_LightSet> & (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::Lights, "Return lights list to be used for rendering presentations within this Z-Layer; NULL by default. NULL list (but not empty list!) means that default lights assigned to the View should be used instead of per-layer lights.");
cls_Graphic3d_ZLayerSettings.def("SetLights", (void (Graphic3d_ZLayerSettings::*)(const opencascade::handle<Graphic3d_LightSet> &)) &Graphic3d_ZLayerSettings::SetLights, "Assign lights list to be used.", py::arg("theLights"));
cls_Graphic3d_ZLayerSettings.def("Origin", (const gp_XYZ & (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::Origin, "Return the origin of all objects within the layer.");
cls_Graphic3d_ZLayerSettings.def("OriginTransformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::OriginTransformation, "Return the transformation to the origin.");
cls_Graphic3d_ZLayerSettings.def("SetOrigin", (void (Graphic3d_ZLayerSettings::*)(const gp_XYZ &)) &Graphic3d_ZLayerSettings::SetOrigin, "Set the origin of all objects within the layer.", py::arg("theOrigin"));
cls_Graphic3d_ZLayerSettings.def("HasCullingDistance", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::HasCullingDistance, "Return TRUE, if culling of distant objects (distance culling) should be performed; FALSE by default.");
cls_Graphic3d_ZLayerSettings.def("CullingDistance", (Standard_Real (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::CullingDistance, "Return the distance to discard drawing of distant objects (distance from camera Eye point); by default it is Infinite (distance culling is disabled). Since camera eye definition has no strong meaning within orthographic projection, option is considered only within perspective projection. Note also that this option has effect only when frustum culling is enabled.");
cls_Graphic3d_ZLayerSettings.def("SetCullingDistance", (void (Graphic3d_ZLayerSettings::*)(Standard_Real)) &Graphic3d_ZLayerSettings::SetCullingDistance, "Set the distance to discard drawing objects.", py::arg("theDistance"));
cls_Graphic3d_ZLayerSettings.def("HasCullingSize", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::HasCullingSize, "Return TRUE, if culling of small objects (size culling) should be performed; FALSE by default.");
cls_Graphic3d_ZLayerSettings.def("CullingSize", (Standard_Real (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::CullingSize, "Return the size to discard drawing of small objects; by default it is Infinite (size culling is disabled). Current implementation checks the length of projected diagonal of bounding box in pixels for discarding. Note that this option has effect only when frustum culling is enabled.");
cls_Graphic3d_ZLayerSettings.def("SetCullingSize", (void (Graphic3d_ZLayerSettings::*)(Standard_Real)) &Graphic3d_ZLayerSettings::SetCullingSize, "Set the distance to discard drawing objects.", py::arg("theSize"));
cls_Graphic3d_ZLayerSettings.def("IsImmediate", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::IsImmediate, "Return true if this layer should be drawn after all normal (non-immediate) layers.");
cls_Graphic3d_ZLayerSettings.def("SetImmediate", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetImmediate, "Set the flag indicating the immediate layer, which should be drawn after all normal (non-immediate) layers.", py::arg("theValue"));
cls_Graphic3d_ZLayerSettings.def("UseEnvironmentTexture", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::UseEnvironmentTexture, "Return flag to allow/prevent environment texture mapping usage for specific layer.");
cls_Graphic3d_ZLayerSettings.def("SetEnvironmentTexture", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetEnvironmentTexture, "Set the flag to allow/prevent environment texture mapping usage for specific layer.", py::arg("theValue"));
cls_Graphic3d_ZLayerSettings.def("ToEnableDepthTest", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::ToEnableDepthTest, "Return true if depth test should be enabled.");
cls_Graphic3d_ZLayerSettings.def("SetEnableDepthTest", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetEnableDepthTest, "Set if depth test should be enabled.", py::arg("theValue"));
cls_Graphic3d_ZLayerSettings.def("ToEnableDepthWrite", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::ToEnableDepthWrite, "Return true depth values should be written during rendering.");
cls_Graphic3d_ZLayerSettings.def("SetEnableDepthWrite", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetEnableDepthWrite, "Set if depth values should be written during rendering.", py::arg("theValue"));
cls_Graphic3d_ZLayerSettings.def("ToClearDepth", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::ToClearDepth, "Return true if depth values should be cleared before drawing the layer.");
cls_Graphic3d_ZLayerSettings.def("SetClearDepth", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetClearDepth, "Set if depth values should be cleared before drawing the layer.", py::arg("theValue"));
cls_Graphic3d_ZLayerSettings.def("ToRenderInDepthPrepass", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::ToRenderInDepthPrepass, "Return TRUE if layer should be rendered within depth pre-pass; TRUE by default.");
cls_Graphic3d_ZLayerSettings.def("SetRenderInDepthPrepass", (void (Graphic3d_ZLayerSettings::*)(Standard_Boolean)) &Graphic3d_ZLayerSettings::SetRenderInDepthPrepass, "Set if layer should be rendered within depth pre-pass.", py::arg("theToRender"));
cls_Graphic3d_ZLayerSettings.def("PolygonOffset", (const Graphic3d_PolygonOffset & (Graphic3d_ZLayerSettings::*)() const) &Graphic3d_ZLayerSettings::PolygonOffset, "Return glPolygonOffset() arguments.");
cls_Graphic3d_ZLayerSettings.def("SetPolygonOffset", (void (Graphic3d_ZLayerSettings::*)(const Graphic3d_PolygonOffset &)) &Graphic3d_ZLayerSettings::SetPolygonOffset, "Setup glPolygonOffset() arguments.", py::arg("theParams"));
cls_Graphic3d_ZLayerSettings.def("ChangePolygonOffset", (Graphic3d_PolygonOffset & (Graphic3d_ZLayerSettings::*)()) &Graphic3d_ZLayerSettings::ChangePolygonOffset, "Modify glPolygonOffset() arguments.");
cls_Graphic3d_ZLayerSettings.def("IsSettingEnabled", (Standard_Boolean (Graphic3d_ZLayerSettings::*)(const Graphic3d_ZLayerSetting) const) &Graphic3d_ZLayerSettings::IsSettingEnabled, "Returns true if theSetting is enabled.", py::arg("theSetting"));
cls_Graphic3d_ZLayerSettings.def("EnableSetting", (void (Graphic3d_ZLayerSettings::*)(const Graphic3d_ZLayerSetting)) &Graphic3d_ZLayerSettings::EnableSetting, "Enables theSetting", py::arg("theSetting"));
cls_Graphic3d_ZLayerSettings.def("DisableSetting", (void (Graphic3d_ZLayerSettings::*)(const Graphic3d_ZLayerSetting)) &Graphic3d_ZLayerSettings::DisableSetting, "Disables theSetting", py::arg("theSetting"));
cls_Graphic3d_ZLayerSettings.def("SetDepthOffsetPositive", (void (Graphic3d_ZLayerSettings::*)()) &Graphic3d_ZLayerSettings::SetDepthOffsetPositive, "Sets minimal possible positive depth offset.");
cls_Graphic3d_ZLayerSettings.def("SetDepthOffsetNegative", (void (Graphic3d_ZLayerSettings::*)()) &Graphic3d_ZLayerSettings::SetDepthOffsetNegative, "Sets minimal possible negative depth offset.");

// Enums

}