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
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_FrustumBuilder.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Vec4.hxx>

void bind_SelectMgr_FrustumBuilder(py::module &mod){

py::class_<SelectMgr_FrustumBuilder, opencascade::handle<SelectMgr_FrustumBuilder>, Standard_Transient> cls_SelectMgr_FrustumBuilder(mod, "SelectMgr_FrustumBuilder", "The purpose of this class is to provide unified interface for building selecting frustum depending on current camera projection and orientation matrices, window size and viewport parameters.");

// Constructors
cls_SelectMgr_FrustumBuilder.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_FrustumBuilder.def("SetWorldViewMatrix", (void (SelectMgr_FrustumBuilder::*)(const Graphic3d_Mat4d &)) &SelectMgr_FrustumBuilder::SetWorldViewMatrix, "Stores current world view transformation matrix", py::arg("theWorldViewMatrix"));
cls_SelectMgr_FrustumBuilder.def("WorldViewMatrix", (const Graphic3d_Mat4d & (SelectMgr_FrustumBuilder::*)() const) &SelectMgr_FrustumBuilder::WorldViewMatrix, "Returns current world view transformation matrix");
cls_SelectMgr_FrustumBuilder.def("SetProjectionMatrix", (void (SelectMgr_FrustumBuilder::*)(const Graphic3d_Mat4d &)) &SelectMgr_FrustumBuilder::SetProjectionMatrix, "Stores current projection matrix", py::arg("theProjection"));
cls_SelectMgr_FrustumBuilder.def("ProjectionMatrix", (const Graphic3d_Mat4d & (SelectMgr_FrustumBuilder::*)() const) &SelectMgr_FrustumBuilder::ProjectionMatrix, "Returns current projection matrix");
cls_SelectMgr_FrustumBuilder.def("SetWorldViewProjState", (void (SelectMgr_FrustumBuilder::*)(const Graphic3d_WorldViewProjState &)) &SelectMgr_FrustumBuilder::SetWorldViewProjState, "Stores current world view projection matrix state for the orientation and projection matrices", py::arg("theState"));
cls_SelectMgr_FrustumBuilder.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (SelectMgr_FrustumBuilder::*)() const) &SelectMgr_FrustumBuilder::WorldViewProjState, "Returns current world view projection state");
cls_SelectMgr_FrustumBuilder.def("SetWindowSize", (void (SelectMgr_FrustumBuilder::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_FrustumBuilder::SetWindowSize, "Stores current window width and height", py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_FrustumBuilder.def("SetViewport", (void (SelectMgr_FrustumBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &SelectMgr_FrustumBuilder::SetViewport, "Stores current viewport coordinates", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_FrustumBuilder.def("InvalidateViewport", (void (SelectMgr_FrustumBuilder::*)()) &SelectMgr_FrustumBuilder::InvalidateViewport, "None");
cls_SelectMgr_FrustumBuilder.def("WindowSize", [](SelectMgr_FrustumBuilder &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.WindowSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "None", py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_FrustumBuilder.def("SignedPlanePntDist", (Standard_Real (SelectMgr_FrustumBuilder::*)(const SelectMgr_Vec3 &, const SelectMgr_Vec3 &) const) &SelectMgr_FrustumBuilder::SignedPlanePntDist, "Calculates signed distance between plane with equation theEq and point thePnt", py::arg("theEq"), py::arg("thePnt"));
cls_SelectMgr_FrustumBuilder.def("ProjectPntOnViewPlane", (gp_Pnt (SelectMgr_FrustumBuilder::*)(const Standard_Real &, const Standard_Real &, const Standard_Real &) const) &SelectMgr_FrustumBuilder::ProjectPntOnViewPlane, "Projects 2d screen point onto view frustum plane: theZ = 0 - near plane, theZ = 1 - far plane", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_SelectMgr_FrustumBuilder.def_static("get_type_name_", (const char * (*)()) &SelectMgr_FrustumBuilder::get_type_name, "None");
cls_SelectMgr_FrustumBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_FrustumBuilder::get_type_descriptor, "None");
cls_SelectMgr_FrustumBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_FrustumBuilder::*)() const) &SelectMgr_FrustumBuilder::DynamicType, "None");

// Enums

}