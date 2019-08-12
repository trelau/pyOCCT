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
#include <IntPolyh_StartPoint.hxx>
#include <IntPolyh_SectionLine.hxx>
#include <IntPolyh_SeqOfStartPoints.hxx>

void bind_IntPolyh_SectionLine(py::module &mod){

py::class_<IntPolyh_SectionLine, std::unique_ptr<IntPolyh_SectionLine, Deleter<IntPolyh_SectionLine>>> cls_IntPolyh_SectionLine(mod, "IntPolyh_SectionLine", "None");

// Constructors
cls_IntPolyh_SectionLine.def(py::init<>());
cls_IntPolyh_SectionLine.def(py::init<const Standard_Integer>(), py::arg("nn"));

// Fields

// Methods
// cls_IntPolyh_SectionLine.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_SectionLine::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_SectionLine.def_static("operator delete_", (void (*)(void *)) &IntPolyh_SectionLine::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_SectionLine.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_SectionLine::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_SectionLine.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_SectionLine::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_SectionLine.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_SectionLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_SectionLine.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_SectionLine::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_SectionLine.def("Init", (void (IntPolyh_SectionLine::*)(const Standard_Integer)) &IntPolyh_SectionLine::Init, "None", py::arg("nn"));
cls_IntPolyh_SectionLine.def("Value", (const IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer) const) &IntPolyh_SectionLine::Value, "None", py::arg("nn"));
cls_IntPolyh_SectionLine.def("__getitem__", (const IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer) const) &IntPolyh_SectionLine::operator[], py::is_operator(), "None", py::arg("nn"));
cls_IntPolyh_SectionLine.def("ChangeValue", (IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer)) &IntPolyh_SectionLine::ChangeValue, "None", py::arg("nn"));
cls_IntPolyh_SectionLine.def("__getitem__", (IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer)) &IntPolyh_SectionLine::operator[], py::is_operator(), "None", py::arg("nn"));
cls_IntPolyh_SectionLine.def("Copy", (IntPolyh_SectionLine & (IntPolyh_SectionLine::*)(const IntPolyh_SectionLine &)) &IntPolyh_SectionLine::Copy, "None", py::arg("Other"));
// cls_IntPolyh_SectionLine.def("operator=", (IntPolyh_SectionLine & (IntPolyh_SectionLine::*)(const IntPolyh_SectionLine &)) &IntPolyh_SectionLine::operator=, "None", py::arg("Other"));
cls_IntPolyh_SectionLine.def("GetN", (Standard_Integer (IntPolyh_SectionLine::*)() const) &IntPolyh_SectionLine::GetN, "None");
cls_IntPolyh_SectionLine.def("NbStartPoints", (Standard_Integer (IntPolyh_SectionLine::*)() const) &IntPolyh_SectionLine::NbStartPoints, "None");
cls_IntPolyh_SectionLine.def("IncrementNbStartPoints", (void (IntPolyh_SectionLine::*)()) &IntPolyh_SectionLine::IncrementNbStartPoints, "None");
cls_IntPolyh_SectionLine.def("Destroy", (void (IntPolyh_SectionLine::*)()) &IntPolyh_SectionLine::Destroy, "None");
cls_IntPolyh_SectionLine.def("Dump", (void (IntPolyh_SectionLine::*)() const) &IntPolyh_SectionLine::Dump, "None");
cls_IntPolyh_SectionLine.def("Prepend", (void (IntPolyh_SectionLine::*)(const IntPolyh_StartPoint &)) &IntPolyh_SectionLine::Prepend, "None", py::arg("SP"));

// Enums

}