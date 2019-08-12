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
#include <gp_Pnt.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Extrema_POnSurf.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Extrema_FuncPSNorm.hxx>

void bind_Extrema_FuncPSNorm(py::module &mod){

py::class_<Extrema_FuncPSNorm, std::unique_ptr<Extrema_FuncPSNorm, Deleter<Extrema_FuncPSNorm>>, math_FunctionSetWithDerivatives> cls_Extrema_FuncPSNorm(mod, "Extrema_FuncPSNorm", "Functional for search of extremum of the distance between point P and surface S, starting from approximate solution (u0, v0).");

// Constructors
cls_Extrema_FuncPSNorm.def(py::init<>());
cls_Extrema_FuncPSNorm.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &>(), py::arg("P"), py::arg("S"));

// Fields

// Methods
// cls_Extrema_FuncPSNorm.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncPSNorm::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncPSNorm.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncPSNorm::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncPSNorm.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncPSNorm::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncPSNorm.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncPSNorm::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncPSNorm.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncPSNorm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncPSNorm.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncPSNorm::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncPSNorm.def("Initialize", (void (Extrema_FuncPSNorm::*)(const Adaptor3d_Surface &)) &Extrema_FuncPSNorm::Initialize, "sets the field mysurf of the function.", py::arg("S"));
cls_Extrema_FuncPSNorm.def("SetPoint", (void (Extrema_FuncPSNorm::*)(const gp_Pnt &)) &Extrema_FuncPSNorm::SetPoint, "sets the field mysurf of the function.", py::arg("P"));
cls_Extrema_FuncPSNorm.def("NbVariables", (Standard_Integer (Extrema_FuncPSNorm::*)() const) &Extrema_FuncPSNorm::NbVariables, "None");
cls_Extrema_FuncPSNorm.def("NbEquations", (Standard_Integer (Extrema_FuncPSNorm::*)() const) &Extrema_FuncPSNorm::NbEquations, "None");
cls_Extrema_FuncPSNorm.def("Value", (Standard_Boolean (Extrema_FuncPSNorm::*)(const math_Vector &, math_Vector &)) &Extrema_FuncPSNorm::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_FuncPSNorm.def("Derivatives", (Standard_Boolean (Extrema_FuncPSNorm::*)(const math_Vector &, math_Matrix &)) &Extrema_FuncPSNorm::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_FuncPSNorm.def("Values", (Standard_Boolean (Extrema_FuncPSNorm::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_FuncPSNorm::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_FuncPSNorm.def("GetStateNumber", (Standard_Integer (Extrema_FuncPSNorm::*)()) &Extrema_FuncPSNorm::GetStateNumber, "Save the found extremum.");
cls_Extrema_FuncPSNorm.def("NbExt", (Standard_Integer (Extrema_FuncPSNorm::*)() const) &Extrema_FuncPSNorm::NbExt, "Return the number of found extrema.");
cls_Extrema_FuncPSNorm.def("SquareDistance", (Standard_Real (Extrema_FuncPSNorm::*)(const Standard_Integer) const) &Extrema_FuncPSNorm::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_FuncPSNorm.def("Point", (const Extrema_POnSurf & (Extrema_FuncPSNorm::*)(const Standard_Integer) const) &Extrema_FuncPSNorm::Point, "Returns the Nth extremum.", py::arg("N"));

// Enums

}