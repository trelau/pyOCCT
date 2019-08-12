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
#include <Standard.hxx>
#include <gp_Dir.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <gp.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Group.hxx>
#include <Standard_TypeDef.hxx>
#include <V3d_View.hxx>
#include <V3d.hxx>

void bind_V3d(py::module &mod){

py::class_<V3d, std::unique_ptr<V3d, Deleter<V3d>>> cls_V3d(mod, "V3d", "This package contains the set of commands and services of the 3D Viewer. It provides a set of high level commands to control the views and viewing modes.");

// Constructors

// Fields

// Methods
// cls_V3d.def_static("operator new_", (void * (*)(size_t)) &V3d::operator new, "None", py::arg("theSize"));
// cls_V3d.def_static("operator delete_", (void (*)(void *)) &V3d::operator delete, "None", py::arg("theAddress"));
// cls_V3d.def_static("operator new[]_", (void * (*)(size_t)) &V3d::operator new[], "None", py::arg("theSize"));
// cls_V3d.def_static("operator delete[]_", (void (*)(void *)) &V3d::operator delete[], "None", py::arg("theAddress"));
// cls_V3d.def_static("operator new_", (void * (*)(size_t, void *)) &V3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_V3d.def_static("operator delete_", (void (*)(void *, void *)) &V3d::operator delete, "None", py::arg(""), py::arg(""));
cls_V3d.def_static("GetProjAxis_", (gp_Dir (*)(const V3d_TypeOfOrientation)) &V3d::GetProjAxis, "Determines the orientation vector corresponding to the predefined orientation type.", py::arg("theOrientation"));
cls_V3d.def_static("ArrowOfRadius_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d::ArrowOfRadius, "Compute the graphic structure of arrow. X0,Y0,Z0 : coordinate of the arrow. DX,DY,DZ : Direction of the arrow. Alpha : Angle of arrow. Lng : Length of arrow.", py::arg("garrow"), py::arg("X0"), py::arg("Y0"), py::arg("Z0"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("Alpha"), py::arg("Lng"));
cls_V3d.def_static("CircleInPlane_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d::CircleInPlane, "Compute the graphic structure of circle. X0,Y0,Z0 : Center of circle. VX,VY,VZ : Axis of circle. Radius : Radius of circle.", py::arg("gcircle"), py::arg("X0"), py::arg("Y0"), py::arg("Z0"), py::arg("VX"), py::arg("VY"), py::arg("VZ"), py::arg("Radius"));
cls_V3d.def_static("SwitchViewsinWindow_", (void (*)(const opencascade::handle<V3d_View> &, const opencascade::handle<V3d_View> &)) &V3d::SwitchViewsinWindow, "None", py::arg("aPreviousView"), py::arg("aNextView"));
cls_V3d.def_static("TypeOfOrientationToString_", (Standard_CString (*)(V3d_TypeOfOrientation)) &V3d::TypeOfOrientationToString, "Returns the string name for a given orientation type.", py::arg("theType"));
cls_V3d.def_static("TypeOfOrientationFromString_", (V3d_TypeOfOrientation (*)(Standard_CString)) &V3d::TypeOfOrientationFromString, "Returns the orientation type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"));
cls_V3d.def_static("TypeOfOrientationFromString_", (Standard_Boolean (*)(const Standard_CString, V3d_TypeOfOrientation &)) &V3d::TypeOfOrientationFromString, "Determines the shape type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"), py::arg("theType"));

// Enums

}