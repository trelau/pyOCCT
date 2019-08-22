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
#include <Prs3d_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <StdPrs_Plane.hxx>

void bind_StdPrs_Plane(py::module &mod){

py::class_<StdPrs_Plane, Prs3d_Root> cls_StdPrs_Plane(mod, "StdPrs_Plane", "A framework to display infinite planes.");

// Constructors

// Fields

// Methods
// cls_StdPrs_Plane.def_static("operator new_", (void * (*)(size_t)) &StdPrs_Plane::operator new, "None", py::arg("theSize"));
// cls_StdPrs_Plane.def_static("operator delete_", (void (*)(void *)) &StdPrs_Plane::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_Plane.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_Plane::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_Plane.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_Plane::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_Plane.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_Plane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_Plane.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_Plane::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_Plane.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Plane::Add, "Defines display of infinite planes. The infinite plane aPlane is added to the display aPresentation, and the attributes of the display are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aPlane"), py::arg("aDrawer"));
cls_StdPrs_Plane.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Plane::Match, "returns true if the distance between the point (X,Y,Z) and the plane is less than aDistance.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aPlane"), py::arg("aDrawer"));

// Enums

}