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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <BRepFill_Generator.hxx>

void bind_BRepFill_Generator(py::module &mod){

py::class_<BRepFill_Generator> cls_BRepFill_Generator(mod, "BRepFill_Generator", "Compute a topological surface ( a shell) using generating wires. The face of the shell will be ruled surfaces passing by the wires. The wires must have the same number of edges.");

// Constructors
cls_BRepFill_Generator.def(py::init<>());

// Fields

// Methods
// cls_BRepFill_Generator.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Generator::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Generator.def_static("operator delete_", (void (*)(void *)) &BRepFill_Generator::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Generator.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Generator::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Generator.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Generator::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Generator.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Generator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Generator.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Generator::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Generator.def("AddWire", (void (BRepFill_Generator::*)(const TopoDS_Wire &)) &BRepFill_Generator::AddWire, "None", py::arg("Wire"));
cls_BRepFill_Generator.def("Perform", (void (BRepFill_Generator::*)()) &BRepFill_Generator::Perform, "Compute the shell.");
cls_BRepFill_Generator.def("Shell", (const TopoDS_Shell & (BRepFill_Generator::*)() const) &BRepFill_Generator::Shell, "None");
cls_BRepFill_Generator.def("Generated", (const TopTools_DataMapOfShapeListOfShape & (BRepFill_Generator::*)() const) &BRepFill_Generator::Generated, "Returns all the shapes created");
cls_BRepFill_Generator.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_Generator::*)(const TopoDS_Shape &) const) &BRepFill_Generator::GeneratedShapes, "Returns the shapes created from a subshape <SSection> of a section.", py::arg("SSection"));

// Enums

}