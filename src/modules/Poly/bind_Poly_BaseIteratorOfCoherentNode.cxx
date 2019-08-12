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
#include <NCollection_Vector.hxx>
#include <Poly_CoherentNode.hxx>
#include <Poly_CoherentTriangulation.hxx>

void bind_Poly_BaseIteratorOfCoherentNode(py::module &mod){

py::class_<NCollection_Vector<Poly_CoherentNode>::Iterator, std::unique_ptr<NCollection_Vector<Poly_CoherentNode>::Iterator, Deleter<NCollection_Vector<Poly_CoherentNode>::Iterator>>> cls_Poly_BaseIteratorOfCoherentNode(mod, "Poly_BaseIteratorOfCoherentNode", "Nested class Iterator");

// Constructors
cls_Poly_BaseIteratorOfCoherentNode.def(py::init<>());
cls_Poly_BaseIteratorOfCoherentNode.def(py::init<const NCollection_Vector<Poly_CoherentNode> &>(), py::arg("theVector"));
cls_Poly_BaseIteratorOfCoherentNode.def(py::init<const NCollection_Vector<Poly_CoherentNode> &, Standard_Boolean>(), py::arg("theVector"), py::arg("theToEnd"));
cls_Poly_BaseIteratorOfCoherentNode.def(py::init<const NCollection_Vector<Poly_CoherentNode>::Iterator &>(), py::arg("theOther"));

// Fields

// Methods
cls_Poly_BaseIteratorOfCoherentNode.def("Init", (void (NCollection_Vector<Poly_CoherentNode>::Iterator::*)(const NCollection_Vector<Poly_CoherentNode> &)) &NCollection_Vector<Poly_CoherentNode>::Iterator::Init, "Initialisation", py::arg("theVector"));
// cls_Poly_BaseIteratorOfCoherentNode.def("operator=", (NCollection_Vector<Poly_CoherentNode>::Iterator & (NCollection_Vector<Poly_CoherentNode>::Iterator::*)(const NCollection_Vector<Poly_CoherentNode>::Iterator &)) &NCollection_Vector<Poly_CoherentNode>::Iterator::operator=, "Assignment", py::arg("theOther"));
cls_Poly_BaseIteratorOfCoherentNode.def("More", (Standard_Boolean (NCollection_Vector<Poly_CoherentNode>::Iterator::*)() const) &NCollection_Vector<Poly_CoherentNode>::Iterator::More, "Check end");
cls_Poly_BaseIteratorOfCoherentNode.def("Next", (void (NCollection_Vector<Poly_CoherentNode>::Iterator::*)()) &NCollection_Vector<Poly_CoherentNode>::Iterator::Next, "Increment operator.");
cls_Poly_BaseIteratorOfCoherentNode.def("Previous", (void (NCollection_Vector<Poly_CoherentNode>::Iterator::*)()) &NCollection_Vector<Poly_CoherentNode>::Iterator::Previous, "Decrement operator.");
cls_Poly_BaseIteratorOfCoherentNode.def("Offset", (void (NCollection_Vector<Poly_CoherentNode>::Iterator::*)(ptrdiff_t)) &NCollection_Vector<Poly_CoherentNode>::Iterator::Offset, "Offset operator.", py::arg("theOffset"));
cls_Poly_BaseIteratorOfCoherentNode.def("Differ", (ptrdiff_t (NCollection_Vector<Poly_CoherentNode>::Iterator::*)(const NCollection_Vector<Poly_CoherentNode>::Iterator &) const) &NCollection_Vector<Poly_CoherentNode>::Iterator::Differ, "Difference operator.", py::arg("theOther"));
cls_Poly_BaseIteratorOfCoherentNode.def("Value", (const Poly_CoherentNode & (NCollection_Vector<Poly_CoherentNode>::Iterator::*)() const) &NCollection_Vector<Poly_CoherentNode>::Iterator::Value, "Constant value access");
cls_Poly_BaseIteratorOfCoherentNode.def("ChangeValue", (Poly_CoherentNode & (NCollection_Vector<Poly_CoherentNode>::Iterator::*)() const) &NCollection_Vector<Poly_CoherentNode>::Iterator::ChangeValue, "Variable value access");
cls_Poly_BaseIteratorOfCoherentNode.def("IsEqual", (Standard_Boolean (NCollection_Vector<Poly_CoherentNode>::Iterator::*)(const NCollection_Vector<Poly_CoherentNode>::Iterator &) const) &NCollection_Vector<Poly_CoherentNode>::Iterator::IsEqual, "Performs comparison of two iterators.", py::arg("theOther"));

// Enums

}