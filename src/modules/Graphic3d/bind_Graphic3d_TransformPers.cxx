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
#include <Graphic3d_TransformPers.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <gp_Pnt.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Standard_ProgramError.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Graphic3d_Camera.hxx>
#include <NCollection_Mat4.hxx>
#include <Bnd_Box.hxx>
#include <BVH_Box.hxx>

void bind_Graphic3d_TransformPers(py::module &mod){

py::class_<Graphic3d_TransformPers, opencascade::handle<Graphic3d_TransformPers>, Standard_Transient> cls_Graphic3d_TransformPers(mod, "Graphic3d_TransformPers", "Transformation Persistence definition.");

// Constructors
cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags>(), py::arg("theMode"));
cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags, const gp_Pnt &>(), py::arg("theMode"), py::arg("thePnt"));
cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags, const Aspect_TypeOfTriedronPosition>(), py::arg("theMode"), py::arg("theCorner"));
cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags, const Aspect_TypeOfTriedronPosition, const Graphic3d_Vec2i &>(), py::arg("theMode"), py::arg("theCorner"), py::arg("theOffset"));

// Fields

// Methods
cls_Graphic3d_TransformPers.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TransformPers::get_type_name, "None");
cls_Graphic3d_TransformPers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TransformPers::get_type_descriptor, "None");
cls_Graphic3d_TransformPers.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::DynamicType, "None");
cls_Graphic3d_TransformPers.def_static("IsZoomOrRotate_", (Standard_Boolean (*)(Graphic3d_TransModeFlags)) &Graphic3d_TransformPers::IsZoomOrRotate, "Return true if specified mode is zoom/rotate transformation persistence.", py::arg("theMode"));
cls_Graphic3d_TransformPers.def_static("IsTrihedronOr2d_", (Standard_Boolean (*)(Graphic3d_TransModeFlags)) &Graphic3d_TransformPers::IsTrihedronOr2d, "Return true if specified mode is 2d/trihedron transformation persistence.", py::arg("theMode"));
cls_Graphic3d_TransformPers.def_static("FromDeprecatedParams_", (opencascade::handle<Graphic3d_TransformPers> (*)(Graphic3d_TransModeFlags, const gp_Pnt &)) &Graphic3d_TransformPers::FromDeprecatedParams, "Create Graphic3d_TransformPers instance from deprecated parameters set decoding 2D corner + offset parameters from 3D point.", py::arg("theFlag"), py::arg("thePoint"));
cls_Graphic3d_TransformPers.def("IsZoomOrRotate", (Standard_Boolean (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::IsZoomOrRotate, "Return true for Graphic3d_TMF_ZoomPers, Graphic3d_TMF_ZoomRotatePers or Graphic3d_TMF_RotatePers modes.");
cls_Graphic3d_TransformPers.def("IsTrihedronOr2d", (Standard_Boolean (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::IsTrihedronOr2d, "Return true for Graphic3d_TMF_TriedronPers and Graphic3d_TMF_2d modes.");
cls_Graphic3d_TransformPers.def("Mode", (Graphic3d_TransModeFlags (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::Mode, "Transformation persistence mode flags.");
cls_Graphic3d_TransformPers.def("Flags", (Graphic3d_TransModeFlags (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::Flags, "Transformation persistence mode flags.");
cls_Graphic3d_TransformPers.def("SetPersistence", (void (Graphic3d_TransformPers::*)(const Graphic3d_TransModeFlags, const gp_Pnt &)) &Graphic3d_TransformPers::SetPersistence, "Set Zoom/Rotate transformation persistence with an anchor 3D point. Throws an exception if persistence mode is not Graphic3d_TMF_ZoomPers, Graphic3d_TMF_ZoomRotatePers or Graphic3d_TMF_RotatePers.", py::arg("theMode"), py::arg("thePnt"));
cls_Graphic3d_TransformPers.def("SetPersistence", (void (Graphic3d_TransformPers::*)(const Graphic3d_TransModeFlags, const Aspect_TypeOfTriedronPosition, const Graphic3d_Vec2i &)) &Graphic3d_TransformPers::SetPersistence, "Set 2d/trihedron transformation persistence with a corner and 2D offset. Throws an exception if persistence mode is not Graphic3d_TMF_TriedronPers or Graphic3d_TMF_2d.", py::arg("theMode"), py::arg("theCorner"), py::arg("theOffset"));
cls_Graphic3d_TransformPers.def("AnchorPoint", (gp_Pnt (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::AnchorPoint, "Return the anchor point for zoom/rotate transformation persistence.");
cls_Graphic3d_TransformPers.def("SetAnchorPoint", (void (Graphic3d_TransformPers::*)(const gp_Pnt &)) &Graphic3d_TransformPers::SetAnchorPoint, "Set the anchor point for zoom/rotate transformation persistence.", py::arg("thePnt"));
cls_Graphic3d_TransformPers.def("Corner2d", (Aspect_TypeOfTriedronPosition (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::Corner2d, "Return the corner for 2d/trihedron transformation persistence.");
cls_Graphic3d_TransformPers.def("SetCorner2d", (void (Graphic3d_TransformPers::*)(const Aspect_TypeOfTriedronPosition)) &Graphic3d_TransformPers::SetCorner2d, "Set the corner for 2d/trihedron transformation persistence.", py::arg("thePos"));
cls_Graphic3d_TransformPers.def("Offset2d", (Graphic3d_Vec2i (Graphic3d_TransformPers::*)() const) &Graphic3d_TransformPers::Offset2d, "Return the offset from the corner for 2d/trihedron transformation persistence.");
cls_Graphic3d_TransformPers.def("SetOffset2d", (void (Graphic3d_TransformPers::*)(const Graphic3d_Vec2i &)) &Graphic3d_TransformPers::SetOffset2d, "Set the offset from the corner for 2d/trihedron transformation persistence.", py::arg("theOffset"));

// Enums

}