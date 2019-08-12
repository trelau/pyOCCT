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
#include <gp_Pnt2d.hxx>
#include <IntAna2d_IntPoint.hxx>

void bind_IntAna2d_IntPoint(py::module &mod){

py::class_<IntAna2d_IntPoint, std::unique_ptr<IntAna2d_IntPoint, Deleter<IntAna2d_IntPoint>>> cls_IntAna2d_IntPoint(mod, "IntAna2d_IntPoint", "Geometrical intersection between two 2d elements.");

// Constructors
cls_IntAna2d_IntPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("U1"), py::arg("U2"));
cls_IntAna2d_IntPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("U1"));
cls_IntAna2d_IntPoint.def(py::init<>());

// Fields

// Methods
// cls_IntAna2d_IntPoint.def_static("operator new_", (void * (*)(size_t)) &IntAna2d_IntPoint::operator new, "None", py::arg("theSize"));
// cls_IntAna2d_IntPoint.def_static("operator delete_", (void (*)(void *)) &IntAna2d_IntPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntAna2d_IntPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntAna2d_IntPoint::operator new[], "None", py::arg("theSize"));
// cls_IntAna2d_IntPoint.def_static("operator delete[]_", (void (*)(void *)) &IntAna2d_IntPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna2d_IntPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna2d_IntPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna2d_IntPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntAna2d_IntPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna2d_IntPoint.def("SetValue", (void (IntAna2d_IntPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna2d_IntPoint::SetValue, "Set the values for a 'non-implicit' point.", py::arg("X"), py::arg("Y"), py::arg("U1"), py::arg("U2"));
cls_IntAna2d_IntPoint.def("SetValue", (void (IntAna2d_IntPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna2d_IntPoint::SetValue, "Set the values for an 'implicit' point.", py::arg("X"), py::arg("Y"), py::arg("U1"));
cls_IntAna2d_IntPoint.def("Value", (const gp_Pnt2d & (IntAna2d_IntPoint::*)() const) &IntAna2d_IntPoint::Value, "Returns the geometric point.");
cls_IntAna2d_IntPoint.def("SecondIsImplicit", (Standard_Boolean (IntAna2d_IntPoint::*)() const) &IntAna2d_IntPoint::SecondIsImplicit, "Returns True if the second curve is implicit.");
cls_IntAna2d_IntPoint.def("ParamOnFirst", (Standard_Real (IntAna2d_IntPoint::*)() const) &IntAna2d_IntPoint::ParamOnFirst, "Returns the parameter on the first element.");
cls_IntAna2d_IntPoint.def("ParamOnSecond", (Standard_Real (IntAna2d_IntPoint::*)() const) &IntAna2d_IntPoint::ParamOnSecond, "Returns the parameter on the second element. If the second element is an implicit curve, an exception is raised.");

// Enums

}