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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopExp_Explorer.hxx>
#include <BRepGProp_Domain.hxx>

void bind_BRepGProp_Domain(py::module &mod){

py::class_<BRepGProp_Domain, std::unique_ptr<BRepGProp_Domain, Deleter<BRepGProp_Domain>>> cls_BRepGProp_Domain(mod, "BRepGProp_Domain", "Arc iterator. Returns only Forward and Reversed edges from the face in an undigested order.");

// Constructors
cls_BRepGProp_Domain.def(py::init<>());
cls_BRepGProp_Domain.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
// cls_BRepGProp_Domain.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_Domain::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_Domain.def_static("operator delete_", (void (*)(void *)) &BRepGProp_Domain::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_Domain.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_Domain::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_Domain.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_Domain::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_Domain.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_Domain::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_Domain.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_Domain::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_Domain.def("Init", (void (BRepGProp_Domain::*)(const TopoDS_Face &)) &BRepGProp_Domain::Init, "Initializes the domain with the face.", py::arg("F"));
cls_BRepGProp_Domain.def("More", (Standard_Boolean (BRepGProp_Domain::*)()) &BRepGProp_Domain::More, "Returns True if there is another arc of curve in the list.");
cls_BRepGProp_Domain.def("Init", (void (BRepGProp_Domain::*)()) &BRepGProp_Domain::Init, "Initializes the exploration with the face already set.");
cls_BRepGProp_Domain.def("Value", (const TopoDS_Edge & (BRepGProp_Domain::*)()) &BRepGProp_Domain::Value, "Returns the current edge.");
cls_BRepGProp_Domain.def("Next", (void (BRepGProp_Domain::*)()) &BRepGProp_Domain::Next, "Sets the index of the arc iterator to the next arc of curve.");

// Enums

}