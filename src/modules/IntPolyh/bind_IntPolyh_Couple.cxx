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
#include <IntPolyh_Couple.hxx>

void bind_IntPolyh_Couple(py::module &mod){

py::class_<IntPolyh_Couple> cls_IntPolyh_Couple(mod, "IntPolyh_Couple", "The class represents the couple of indices with additional characteristics such as analyzed flag and an angle. In IntPolyh_MaillageAffinage algorithm the class is used as a couple of interfering triangles with the intersection angle.");

// Constructors
cls_IntPolyh_Couple.def(py::init<>());
cls_IntPolyh_Couple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theTriangle1"), py::arg("theTriangle2"));
cls_IntPolyh_Couple.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("theTriangle1"), py::arg("theTriangle2"), py::arg("theAngle"));

// Fields

// Methods
// cls_IntPolyh_Couple.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_Couple::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_Couple.def_static("operator delete_", (void (*)(void *)) &IntPolyh_Couple::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_Couple.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_Couple::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_Couple.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_Couple::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_Couple.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_Couple::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_Couple.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_Couple::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_Couple.def("FirstValue", (Standard_Integer (IntPolyh_Couple::*)() const) &IntPolyh_Couple::FirstValue, "Returns the first index");
cls_IntPolyh_Couple.def("SecondValue", (Standard_Integer (IntPolyh_Couple::*)() const) &IntPolyh_Couple::SecondValue, "Returns the second index");
cls_IntPolyh_Couple.def("IsAnalyzed", (Standard_Boolean (IntPolyh_Couple::*)() const) &IntPolyh_Couple::IsAnalyzed, "Returns TRUE if the couple has been analyzed");
cls_IntPolyh_Couple.def("Angle", (Standard_Real (IntPolyh_Couple::*)() const) &IntPolyh_Couple::Angle, "Returns the angle");
cls_IntPolyh_Couple.def("SetCoupleValue", (void (IntPolyh_Couple::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Couple::SetCoupleValue, "Sets the triangles", py::arg("theInd1"), py::arg("theInd2"));
cls_IntPolyh_Couple.def("SetAnalyzed", (void (IntPolyh_Couple::*)(const Standard_Boolean)) &IntPolyh_Couple::SetAnalyzed, "Sets the analyzed flag", py::arg("theAnalyzed"));
cls_IntPolyh_Couple.def("SetAngle", (void (IntPolyh_Couple::*)(const Standard_Real)) &IntPolyh_Couple::SetAngle, "Sets the angle", py::arg("theAngle"));
cls_IntPolyh_Couple.def("IsEqual", (Standard_Boolean (IntPolyh_Couple::*)(const IntPolyh_Couple &) const) &IntPolyh_Couple::IsEqual, "Returns true if the Couple is equal to <theOther>", py::arg("theOther"));
cls_IntPolyh_Couple.def("HashCode", (Standard_Integer (IntPolyh_Couple::*)(const Standard_Integer) const) &IntPolyh_Couple::HashCode, "Returns hash code", py::arg("theUpper"));
cls_IntPolyh_Couple.def("Dump", (void (IntPolyh_Couple::*)(const Standard_Integer) const) &IntPolyh_Couple::Dump, "None", py::arg("v"));

// Enums

}