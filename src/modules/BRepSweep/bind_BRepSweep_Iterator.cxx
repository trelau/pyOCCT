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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Iterator.hxx>
#include <BRepSweep_Iterator.hxx>

void bind_BRepSweep_Iterator(py::module &mod){

py::class_<BRepSweep_Iterator> cls_BRepSweep_Iterator(mod, "BRepSweep_Iterator", "This class provides iteration services required by the Generating Line (TopoDS Shape) of a BRepSweep. This tool is used to iterate on the direct sub-shapes of a Shape.");

// Constructors
cls_BRepSweep_Iterator.def(py::init<>());

// Fields

// Methods
// cls_BRepSweep_Iterator.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Iterator::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Iterator.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Iterator::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Iterator.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Iterator.def("Init", (void (BRepSweep_Iterator::*)(const TopoDS_Shape &)) &BRepSweep_Iterator::Init, "Resest the Iterator on sub-shapes of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Iterator.def("More", (Standard_Boolean (BRepSweep_Iterator::*)() const) &BRepSweep_Iterator::More, "Returns True if there is a current sub-shape.");
cls_BRepSweep_Iterator.def("Next", (void (BRepSweep_Iterator::*)()) &BRepSweep_Iterator::Next, "Moves to the next sub-shape.");
cls_BRepSweep_Iterator.def("Value", (const TopoDS_Shape & (BRepSweep_Iterator::*)() const) &BRepSweep_Iterator::Value, "Returns the current sub-shape.");
cls_BRepSweep_Iterator.def("Orientation", (TopAbs_Orientation (BRepSweep_Iterator::*)() const) &BRepSweep_Iterator::Orientation, "Returns the orientation of the current sub-shape.");

// Enums

}