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
#include <LProp_CIType.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <LProp_SequenceOfCIType.hxx>
#include <LProp_CurAndInf.hxx>

void bind_LProp_CurAndInf(py::module &mod){

py::class_<LProp_CurAndInf, std::unique_ptr<LProp_CurAndInf>> cls_LProp_CurAndInf(mod, "LProp_CurAndInf", "Stores the parameters of a curve 2d or 3d corresponding to the curvature's extremas and the Inflection's Points.");

// Constructors
cls_LProp_CurAndInf.def(py::init<>());

// Fields

// Methods
// cls_LProp_CurAndInf.def_static("operator new_", (void * (*)(size_t)) &LProp_CurAndInf::operator new, "None", py::arg("theSize"));
// cls_LProp_CurAndInf.def_static("operator delete_", (void (*)(void *)) &LProp_CurAndInf::operator delete, "None", py::arg("theAddress"));
// cls_LProp_CurAndInf.def_static("operator new[]_", (void * (*)(size_t)) &LProp_CurAndInf::operator new[], "None", py::arg("theSize"));
// cls_LProp_CurAndInf.def_static("operator delete[]_", (void (*)(void *)) &LProp_CurAndInf::operator delete[], "None", py::arg("theAddress"));
// cls_LProp_CurAndInf.def_static("operator new_", (void * (*)(size_t, void *)) &LProp_CurAndInf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LProp_CurAndInf.def_static("operator delete_", (void (*)(void *, void *)) &LProp_CurAndInf::operator delete, "None", py::arg(""), py::arg(""));
cls_LProp_CurAndInf.def("AddInflection", (void (LProp_CurAndInf::*)(const Standard_Real)) &LProp_CurAndInf::AddInflection, "None", py::arg("Param"));
cls_LProp_CurAndInf.def("AddExtCur", (void (LProp_CurAndInf::*)(const Standard_Real, const Standard_Boolean)) &LProp_CurAndInf::AddExtCur, "None", py::arg("Param"), py::arg("IsMin"));
cls_LProp_CurAndInf.def("Clear", (void (LProp_CurAndInf::*)()) &LProp_CurAndInf::Clear, "None");
cls_LProp_CurAndInf.def("IsEmpty", (Standard_Boolean (LProp_CurAndInf::*)() const) &LProp_CurAndInf::IsEmpty, "None");
cls_LProp_CurAndInf.def("NbPoints", (Standard_Integer (LProp_CurAndInf::*)() const) &LProp_CurAndInf::NbPoints, "Returns the number of points. The Points are stored to increasing parameter.");
cls_LProp_CurAndInf.def("Parameter", (Standard_Real (LProp_CurAndInf::*)(const Standard_Integer) const) &LProp_CurAndInf::Parameter, "Returns the parameter of the Nth point. raises if N not in the range [1,NbPoints()]", py::arg("N"));
cls_LProp_CurAndInf.def("Type", (LProp_CIType (LProp_CurAndInf::*)(const Standard_Integer) const) &LProp_CurAndInf::Type, "Returns - MinCur if the Nth parameter corresponds to a minimum of the radius of curvature. - MaxCur if the Nth parameter corresponds to a maximum of the radius of curvature. - Inflection if the parameter corresponds to a point of inflection. raises if N not in the range [1,NbPoints()]", py::arg("N"));

// Enums

}