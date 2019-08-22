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
#include <Standard_TypeDef.hxx>
#include <BOPDS_Pave.hxx>

void bind_BOPDS_Pave(py::module &mod){

py::class_<BOPDS_Pave> cls_BOPDS_Pave(mod, "BOPDS_Pave", "The class BOPDS_Pave is to store information about vertex on an edge");

// Constructors
cls_BOPDS_Pave.def(py::init<>());

// Fields

// Methods
// cls_BOPDS_Pave.def_static("operator new_", (void * (*)(size_t)) &BOPDS_Pave::operator new, "None", py::arg("theSize"));
// cls_BOPDS_Pave.def_static("operator delete_", (void (*)(void *)) &BOPDS_Pave::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_Pave.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_Pave::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_Pave.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_Pave::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_Pave.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_Pave::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_Pave.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_Pave::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_Pave.def("SetIndex", (void (BOPDS_Pave::*)(const Standard_Integer)) &BOPDS_Pave::SetIndex, "Modifier Sets the index of vertex <theIndex>", py::arg("theIndex"));
cls_BOPDS_Pave.def("Index", (Standard_Integer (BOPDS_Pave::*)() const) &BOPDS_Pave::Index, "Selector Returns the index of vertex");
cls_BOPDS_Pave.def("SetParameter", (void (BOPDS_Pave::*)(const Standard_Real)) &BOPDS_Pave::SetParameter, "Modifier Sets the parameter of vertex <theParameter>", py::arg("theParameter"));
cls_BOPDS_Pave.def("Parameter", (Standard_Real (BOPDS_Pave::*)() const) &BOPDS_Pave::Parameter, "Selector Returns the parameter of vertex");
cls_BOPDS_Pave.def("Contents", [](BOPDS_Pave &self, Standard_Integer & theIndex, Standard_Real & theParameter){ self.Contents(theIndex, theParameter); return std::tuple<Standard_Integer &, Standard_Real &>(theIndex, theParameter); }, "Selector Returns the index of vertex <theIndex> Returns the parameter of vertex <theParameter>", py::arg("theIndex"), py::arg("theParameter"));
cls_BOPDS_Pave.def("IsLess", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const) &BOPDS_Pave::IsLess, "Query Returns true if thr parameter od this is less than the parameter of <theOther>", py::arg("theOther"));
cls_BOPDS_Pave.def("__lt__", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const) &BOPDS_Pave::operator<, py::is_operator(), "None", py::arg("theOther"));
cls_BOPDS_Pave.def("IsEqual", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const) &BOPDS_Pave::IsEqual, "Query Returns true if thr parameter od this is equal to the parameter of <theOther>", py::arg("theOther"));
cls_BOPDS_Pave.def("__eq__", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const) &BOPDS_Pave::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_BOPDS_Pave.def("Dump", (void (BOPDS_Pave::*)() const) &BOPDS_Pave::Dump, "None");

// Enums

}