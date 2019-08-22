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
#include <AppDef_Array1OfMultiPointConstraint.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <AppDef_MultiPointConstraint.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <AppDef_HArray1OfMultiPointConstraint.hxx>
#include <AppDef_MultiLine.hxx>

void bind_AppDef_MultiLine(py::module &mod){

py::class_<AppDef_MultiLine> cls_AppDef_MultiLine(mod, "AppDef_MultiLine", "This class describes the organized set of points used in the approximations. A MultiLine is composed of n MultiPointConstraints. The approximation of the MultiLine will be done in the order of the given n MultiPointConstraints.");

// Constructors
cls_AppDef_MultiLine.def(py::init<>());
cls_AppDef_MultiLine.def(py::init<const Standard_Integer>(), py::arg("NbMult"));
cls_AppDef_MultiLine.def(py::init<const AppDef_Array1OfMultiPointConstraint &>(), py::arg("tabMultiP"));
cls_AppDef_MultiLine.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP3d"));
cls_AppDef_MultiLine.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP2d"));

// Fields

// Methods
// cls_AppDef_MultiLine.def_static("operator new_", (void * (*)(size_t)) &AppDef_MultiLine::operator new, "None", py::arg("theSize"));
// cls_AppDef_MultiLine.def_static("operator delete_", (void (*)(void *)) &AppDef_MultiLine::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MultiLine.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MultiLine::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MultiLine.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MultiLine::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MultiLine.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MultiLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MultiLine.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MultiLine::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MultiLine.def("NbMultiPoints", (Standard_Integer (AppDef_MultiLine::*)() const) &AppDef_MultiLine::NbMultiPoints, "returns the number of MultiPointConstraints of the MultiLine.");
cls_AppDef_MultiLine.def("NbPoints", (Standard_Integer (AppDef_MultiLine::*)() const) &AppDef_MultiLine::NbPoints, "returns the number of Points from MultiPoints composing the MultiLine.");
// cls_AppDef_MultiLine.def("SetParameter", (void (AppDef_MultiLine::*)(const Standard_Integer, const Standard_Real)) &AppDef_MultiLine::SetParameter, "Sets the value of the parameter for the MultiPointConstraint at position Index. Exceptions - Standard_OutOfRange if Index is less than 0 or Index is greater than the number of Multipoint constraints in the MultiLine.", py::arg("Index"), py::arg("U"));
cls_AppDef_MultiLine.def("SetValue", (void (AppDef_MultiLine::*)(const Standard_Integer, const AppDef_MultiPointConstraint &)) &AppDef_MultiLine::SetValue, "It sets the MultiPointConstraint of range Index to the value MPoint. An exception is raised if Index < 0 or Index> MPoint. An exception is raised if the dimensions of the MultiPoints are different.", py::arg("Index"), py::arg("MPoint"));
cls_AppDef_MultiLine.def("Value", (AppDef_MultiPointConstraint (AppDef_MultiLine::*)(const Standard_Integer) const) &AppDef_MultiLine::Value, "returns the MultiPointConstraint of range Index An exception is raised if Index<0 or Index>MPoint.", py::arg("Index"));
cls_AppDef_MultiLine.def("Dump", (void (AppDef_MultiLine::*)(Standard_OStream &) const) &AppDef_MultiLine::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}