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
#include <StdPrs_HLRPolyShape.hxx>

void bind_StdPrs_HLRPolyShape(py::module &mod){

py::class_<StdPrs_HLRPolyShape, std::unique_ptr<StdPrs_HLRPolyShape>, Prs3d_Root> cls_StdPrs_HLRPolyShape(mod, "StdPrs_HLRPolyShape", "Instantiates Prs3d_PolyHLRShape to define a display of a shape where hidden and visible lines are identified with respect to a given projection. StdPrs_HLRPolyShape works with a polyhedral simplification of the shape whereas StdPrs_HLRShape takes the shape itself into account. When you use StdPrs_HLRShape, you obtain an exact result, whereas, when you use StdPrs_HLRPolyShape, you reduce computation time but obtain polygonal segments. The polygonal algorithm is used.");

// Constructors

// Fields

// Methods
// cls_StdPrs_HLRPolyShape.def_static("operator new_", (void * (*)(size_t)) &StdPrs_HLRPolyShape::operator new, "None", py::arg("theSize"));
// cls_StdPrs_HLRPolyShape.def_static("operator delete_", (void (*)(void *)) &StdPrs_HLRPolyShape::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_HLRPolyShape.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_HLRPolyShape::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_HLRPolyShape.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_HLRPolyShape::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_HLRPolyShape.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_HLRPolyShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_HLRPolyShape.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_HLRPolyShape::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_HLRPolyShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<Prs3d_Projector> &)) &StdPrs_HLRPolyShape::Add, "Defines the hidden line removal display of the topology aShape in the projection defined by aProjector. The shape and the projection are added to the display aPresentation, and the attributes of the elements present in the aPresentation are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aShape"), py::arg("aDrawer"), py::arg("aProjector"));

// Enums

}