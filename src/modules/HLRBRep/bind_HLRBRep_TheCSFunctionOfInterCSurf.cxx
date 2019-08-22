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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <HLRBRep_TheCSFunctionOfInterCSurf.hxx>

void bind_HLRBRep_TheCSFunctionOfInterCSurf(py::module &mod){

py::class_<HLRBRep_TheCSFunctionOfInterCSurf, math_FunctionSetWithDerivatives> cls_HLRBRep_TheCSFunctionOfInterCSurf(mod, "HLRBRep_TheCSFunctionOfInterCSurf", "None");

// Constructors
cls_HLRBRep_TheCSFunctionOfInterCSurf.def(py::init<const Standard_Address &, const gp_Lin &>(), py::arg("S"), py::arg("C"));

// Fields

// Methods
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheCSFunctionOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheCSFunctionOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("NbVariables", (Standard_Integer (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::NbVariables, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("NbEquations", (Standard_Integer (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::NbEquations, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Value", (Standard_Boolean (HLRBRep_TheCSFunctionOfInterCSurf::*)(const math_Vector &, math_Vector &)) &HLRBRep_TheCSFunctionOfInterCSurf::Value, "None", py::arg("X"), py::arg("F"));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Derivatives", (Standard_Boolean (HLRBRep_TheCSFunctionOfInterCSurf::*)(const math_Vector &, math_Matrix &)) &HLRBRep_TheCSFunctionOfInterCSurf::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Values", (Standard_Boolean (HLRBRep_TheCSFunctionOfInterCSurf::*)(const math_Vector &, math_Vector &, math_Matrix &)) &HLRBRep_TheCSFunctionOfInterCSurf::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Point", (const gp_Pnt & (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::Point, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Root", (Standard_Real (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::Root, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("AuxillarSurface", (const Standard_Address & (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::AuxillarSurface, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("AuxillarCurve", (const gp_Lin & (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::AuxillarCurve, "None");

// Enums

}