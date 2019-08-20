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
#include <math_DoubleTab.hxx>

void bind_math_DoubleTab(py::module &mod){

py::class_<math_DoubleTab, std::unique_ptr<math_DoubleTab>> cls_math_DoubleTab(mod, "math_DoubleTab", "None");

// Constructors
cls_math_DoubleTab.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
cls_math_DoubleTab.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Tab"), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
cls_math_DoubleTab.def(py::init<const math_DoubleTab &>(), py::arg("Other"));

// Fields

// Methods
// cls_math_DoubleTab.def_static("operator new_", (void * (*)(size_t)) &math_DoubleTab::operator new, "None", py::arg("theSize"));
// cls_math_DoubleTab.def_static("operator delete_", (void (*)(void *)) &math_DoubleTab::operator delete, "None", py::arg("theAddress"));
// cls_math_DoubleTab.def_static("operator new[]_", (void * (*)(size_t)) &math_DoubleTab::operator new[], "None", py::arg("theSize"));
// cls_math_DoubleTab.def_static("operator delete[]_", (void (*)(void *)) &math_DoubleTab::operator delete[], "None", py::arg("theAddress"));
// cls_math_DoubleTab.def_static("operator new_", (void * (*)(size_t, void *)) &math_DoubleTab::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_DoubleTab.def_static("operator delete_", (void (*)(void *, void *)) &math_DoubleTab::operator delete, "None", py::arg(""), py::arg(""));
cls_math_DoubleTab.def("Init", (void (math_DoubleTab::*)(const Standard_Real)) &math_DoubleTab::Init, "None", py::arg("InitValue"));
cls_math_DoubleTab.def("Copy", (void (math_DoubleTab::*)(math_DoubleTab &) const) &math_DoubleTab::Copy, "None", py::arg("Other"));
cls_math_DoubleTab.def("SetLowerRow", (void (math_DoubleTab::*)(const Standard_Integer)) &math_DoubleTab::SetLowerRow, "None", py::arg("LowerRow"));
cls_math_DoubleTab.def("SetLowerCol", (void (math_DoubleTab::*)(const Standard_Integer)) &math_DoubleTab::SetLowerCol, "None", py::arg("LowerCol"));
cls_math_DoubleTab.def("Value", (Standard_Real & (math_DoubleTab::*)(const Standard_Integer, const Standard_Integer) const) &math_DoubleTab::Value, "None", py::arg("RowIndex"), py::arg("ColIndex"));
cls_math_DoubleTab.def("__call__", (Standard_Real & (math_DoubleTab::*)(const Standard_Integer, const Standard_Integer) const) &math_DoubleTab::operator(), py::is_operator(), "None", py::arg("RowIndex"), py::arg("ColIndex"));
cls_math_DoubleTab.def("Free", (void (math_DoubleTab::*)()) &math_DoubleTab::Free, "None");

// Enums

}