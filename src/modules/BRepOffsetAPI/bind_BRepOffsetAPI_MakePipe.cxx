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
#include <BRepPrimAPI_MakeSweep.hxx>
#include <Standard.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <GeomFill_Trihedron.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepFill_Pipe.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>

void bind_BRepOffsetAPI_MakePipe(py::module &mod){

py::class_<BRepOffsetAPI_MakePipe, std::unique_ptr<BRepOffsetAPI_MakePipe, Deleter<BRepOffsetAPI_MakePipe>>, BRepPrimAPI_MakeSweep> cls_BRepOffsetAPI_MakePipe(mod, "BRepOffsetAPI_MakePipe", "Describes functions to build pipes. A pipe is built a basis shape (called the profile) along a wire (called the spine) by sweeping. The profile must not contain solids. A MakePipe object provides a framework for: - defining the construction of a pipe, - implementing the construction algorithm, and - consulting the result. Warning The MakePipe class implements pipe constructions with G1 continuous spines only.");

// Constructors
cls_BRepOffsetAPI_MakePipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));
cls_BRepOffsetAPI_MakePipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"));
cls_BRepOffsetAPI_MakePipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"), py::arg("ForceApproxC1"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakePipe.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipe::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakePipe::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipe::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakePipe::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakePipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakePipe::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakePipe.def("Pipe", (const BRepFill_Pipe & (BRepOffsetAPI_MakePipe::*)() const) &BRepOffsetAPI_MakePipe::Pipe, "None");
cls_BRepOffsetAPI_MakePipe.def("Build", (void (BRepOffsetAPI_MakePipe::*)()) &BRepOffsetAPI_MakePipe::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakePipe.def("FirstShape", (TopoDS_Shape (BRepOffsetAPI_MakePipe::*)()) &BRepOffsetAPI_MakePipe::FirstShape, "Returns the TopoDS Shape of the bottom of the prism.");
cls_BRepOffsetAPI_MakePipe.def("LastShape", (TopoDS_Shape (BRepOffsetAPI_MakePipe::*)()) &BRepOffsetAPI_MakePipe::LastShape, "Returns the TopoDS Shape of the top of the prism.");
cls_BRepOffsetAPI_MakePipe.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakePipe::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipe::Generated, "None", py::arg("S"));
cls_BRepOffsetAPI_MakePipe.def("Generated", (TopoDS_Shape (BRepOffsetAPI_MakePipe::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepOffsetAPI_MakePipe::Generated, "None", py::arg("SSpine"), py::arg("SProfile"));
cls_BRepOffsetAPI_MakePipe.def("ErrorOnSurface", (Standard_Real (BRepOffsetAPI_MakePipe::*)() const) &BRepOffsetAPI_MakePipe::ErrorOnSurface, "None");

// Enums

}