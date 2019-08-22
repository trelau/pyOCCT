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
#include <TopoDS_Shape.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_Projector.hxx>
#include <StdPrs_HLRShape.hxx>

void bind_StdPrs_HLRShape(py::module &mod){

py::class_<StdPrs_HLRShape, Prs3d_Root> cls_StdPrs_HLRShape(mod, "StdPrs_HLRShape", "None");

// Constructors

// Fields

// Methods
// cls_StdPrs_HLRShape.def_static("operator new_", (void * (*)(size_t)) &StdPrs_HLRShape::operator new, "None", py::arg("theSize"));
// cls_StdPrs_HLRShape.def_static("operator delete_", (void (*)(void *)) &StdPrs_HLRShape::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_HLRShape.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_HLRShape::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_HLRShape.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_HLRShape::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_HLRShape.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_HLRShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_HLRShape.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_HLRShape::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_HLRShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<Prs3d_Projector> &)) &StdPrs_HLRShape::Add, "None", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theProjector"));

// Enums

}