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
#include <TopTools_SequenceOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFill_CompatibleWires.hxx>

void bind_BRepFill_CompatibleWires(py::module &mod){

py::class_<BRepFill_CompatibleWires, std::unique_ptr<BRepFill_CompatibleWires, Deleter<BRepFill_CompatibleWires>>> cls_BRepFill_CompatibleWires(mod, "BRepFill_CompatibleWires", "Constructs a sequence of Wires (with good orientation and origin) agreed each other so that the surface passing through these sections is not twisted");

// Constructors
cls_BRepFill_CompatibleWires.def(py::init<>());
cls_BRepFill_CompatibleWires.def(py::init<const TopTools_SequenceOfShape &>(), py::arg("Sections"));

// Fields

// Methods
// cls_BRepFill_CompatibleWires.def_static("operator new_", (void * (*)(size_t)) &BRepFill_CompatibleWires::operator new, "None", py::arg("theSize"));
// cls_BRepFill_CompatibleWires.def_static("operator delete_", (void (*)(void *)) &BRepFill_CompatibleWires::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_CompatibleWires.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_CompatibleWires::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_CompatibleWires.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_CompatibleWires::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_CompatibleWires.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_CompatibleWires::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_CompatibleWires.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_CompatibleWires::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_CompatibleWires.def("Init", (void (BRepFill_CompatibleWires::*)(const TopTools_SequenceOfShape &)) &BRepFill_CompatibleWires::Init, "None", py::arg("Sections"));
cls_BRepFill_CompatibleWires.def("SetPercent", [](BRepFill_CompatibleWires &self) -> void { return self.SetPercent(); });
cls_BRepFill_CompatibleWires.def("SetPercent", (void (BRepFill_CompatibleWires::*)(const Standard_Real)) &BRepFill_CompatibleWires::SetPercent, "None", py::arg("percent"));
cls_BRepFill_CompatibleWires.def("Perform", [](BRepFill_CompatibleWires &self) -> void { return self.Perform(); });
cls_BRepFill_CompatibleWires.def("Perform", (void (BRepFill_CompatibleWires::*)(const Standard_Boolean)) &BRepFill_CompatibleWires::Perform, "Performs CompatibleWires According to the orientation and the origin of each other", py::arg("WithRotation"));
cls_BRepFill_CompatibleWires.def("IsDone", (Standard_Boolean (BRepFill_CompatibleWires::*)() const) &BRepFill_CompatibleWires::IsDone, "None");
cls_BRepFill_CompatibleWires.def("Shape", (const TopTools_SequenceOfShape & (BRepFill_CompatibleWires::*)() const) &BRepFill_CompatibleWires::Shape, "returns the generated sequence.");
cls_BRepFill_CompatibleWires.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_CompatibleWires::*)(const TopoDS_Edge &) const) &BRepFill_CompatibleWires::GeneratedShapes, "Returns the shapes created from a subshape <SubSection> of a section.", py::arg("SubSection"));
cls_BRepFill_CompatibleWires.def("Generated", (const TopTools_DataMapOfShapeListOfShape & (BRepFill_CompatibleWires::*)() const) &BRepFill_CompatibleWires::Generated, "None");
cls_BRepFill_CompatibleWires.def("IsDegeneratedFirstSection", (Standard_Boolean (BRepFill_CompatibleWires::*)() const) &BRepFill_CompatibleWires::IsDegeneratedFirstSection, "None");
cls_BRepFill_CompatibleWires.def("IsDegeneratedLastSection", (Standard_Boolean (BRepFill_CompatibleWires::*)() const) &BRepFill_CompatibleWires::IsDegeneratedLastSection, "None");

// Enums

}