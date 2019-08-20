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
#include <Poly_CoherentLink.hxx>
#include <Poly_CoherentTriangulation.hxx>

void bind_Poly_BaseIteratorOfCoherentLink(py::module &mod){

py::class_<NCollection_Vector<Poly_CoherentLink>::Iterator, std::unique_ptr<NCollection_Vector<Poly_CoherentLink>::Iterator>> cls_Poly_BaseIteratorOfCoherentLink(mod, "Poly_BaseIteratorOfCoherentLink", "Nested class Iterator");

// Constructors
cls_Poly_BaseIteratorOfCoherentLink.def(py::init<>());
cls_Poly_BaseIteratorOfCoherentLink.def(py::init<const NCollection_Vector<Poly_CoherentLink> &>(), py::arg("theVector"));
cls_Poly_BaseIteratorOfCoherentLink.def(py::init<const NCollection_Vector<Poly_CoherentLink> &, Standard_Boolean>(), py::arg("theVector"), py::arg("theToEnd"));
cls_Poly_BaseIteratorOfCoherentLink.def(py::init<const NCollection_Vector<Poly_CoherentLink>::Iterator &>(), py::arg("theOther"));

// Fields

// Methods
cls_Poly_BaseIteratorOfCoherentLink.def("Init", (void (NCollection_Vector<Poly_CoherentLink>::Iterator::*)(const NCollection_Vector<Poly_CoherentLink> &)) &NCollection_Vector<Poly_CoherentLink>::Iterator::Init, "Initialisation", py::arg("theVector"));
// cls_Poly_BaseIteratorOfCoherentLink.def("operator=", (NCollection_Vector<Poly_CoherentLink>::Iterator & (NCollection_Vector<Poly_CoherentLink>::Iterator::*)(const NCollection_Vector<Poly_CoherentLink>::Iterator &)) &NCollection_Vector<Poly_CoherentLink>::Iterator::operator=, "Assignment", py::arg("theOther"));
cls_Poly_BaseIteratorOfCoherentLink.def("More", (Standard_Boolean (NCollection_Vector<Poly_CoherentLink>::Iterator::*)() const) &NCollection_Vector<Poly_CoherentLink>::Iterator::More, "Check end");
cls_Poly_BaseIteratorOfCoherentLink.def("Next", (void (NCollection_Vector<Poly_CoherentLink>::Iterator::*)()) &NCollection_Vector<Poly_CoherentLink>::Iterator::Next, "Increment operator.");
cls_Poly_BaseIteratorOfCoherentLink.def("Previous", (void (NCollection_Vector<Poly_CoherentLink>::Iterator::*)()) &NCollection_Vector<Poly_CoherentLink>::Iterator::Previous, "Decrement operator.");
cls_Poly_BaseIteratorOfCoherentLink.def("Offset", (void (NCollection_Vector<Poly_CoherentLink>::Iterator::*)(ptrdiff_t)) &NCollection_Vector<Poly_CoherentLink>::Iterator::Offset, "Offset operator.", py::arg("theOffset"));
cls_Poly_BaseIteratorOfCoherentLink.def("Differ", (ptrdiff_t (NCollection_Vector<Poly_CoherentLink>::Iterator::*)(const NCollection_Vector<Poly_CoherentLink>::Iterator &) const) &NCollection_Vector<Poly_CoherentLink>::Iterator::Differ, "Difference operator.", py::arg("theOther"));
cls_Poly_BaseIteratorOfCoherentLink.def("Value", (const Poly_CoherentLink & (NCollection_Vector<Poly_CoherentLink>::Iterator::*)() const) &NCollection_Vector<Poly_CoherentLink>::Iterator::Value, "Constant value access");
cls_Poly_BaseIteratorOfCoherentLink.def("ChangeValue", (Poly_CoherentLink & (NCollection_Vector<Poly_CoherentLink>::Iterator::*)() const) &NCollection_Vector<Poly_CoherentLink>::Iterator::ChangeValue, "Variable value access");
cls_Poly_BaseIteratorOfCoherentLink.def("IsEqual", (Standard_Boolean (NCollection_Vector<Poly_CoherentLink>::Iterator::*)(const NCollection_Vector<Poly_CoherentLink>::Iterator &) const) &NCollection_Vector<Poly_CoherentLink>::Iterator::IsEqual, "Performs comparison of two iterators.", py::arg("theOther"));

// Enums

}