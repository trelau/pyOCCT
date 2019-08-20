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
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Extrema_POnSurf.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Extrema_FuncExtSS.hxx>

void bind_Extrema_FuncExtSS(py::module &mod){

py::class_<Extrema_FuncExtSS, std::unique_ptr<Extrema_FuncExtSS>, math_FunctionSetWithDerivatives> cls_Extrema_FuncExtSS(mod, "Extrema_FuncExtSS", "Function to find extrema of the distance between two surfaces.");

// Constructors
cls_Extrema_FuncExtSS.def(py::init<>());
cls_Extrema_FuncExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &>(), py::arg("S1"), py::arg("S2"));

// Fields

// Methods
// cls_Extrema_FuncExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncExtSS.def("Initialize", (void (Extrema_FuncExtSS::*)(const Adaptor3d_Surface &, const Adaptor3d_Surface &)) &Extrema_FuncExtSS::Initialize, "sets the field mysurf of the function.", py::arg("S1"), py::arg("S2"));
cls_Extrema_FuncExtSS.def("NbVariables", (Standard_Integer (Extrema_FuncExtSS::*)() const) &Extrema_FuncExtSS::NbVariables, "None");
cls_Extrema_FuncExtSS.def("NbEquations", (Standard_Integer (Extrema_FuncExtSS::*)() const) &Extrema_FuncExtSS::NbEquations, "None");
cls_Extrema_FuncExtSS.def("Value", (Standard_Boolean (Extrema_FuncExtSS::*)(const math_Vector &, math_Vector &)) &Extrema_FuncExtSS::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_FuncExtSS.def("Derivatives", (Standard_Boolean (Extrema_FuncExtSS::*)(const math_Vector &, math_Matrix &)) &Extrema_FuncExtSS::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_FuncExtSS.def("Values", (Standard_Boolean (Extrema_FuncExtSS::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_FuncExtSS::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_FuncExtSS.def("GetStateNumber", (Standard_Integer (Extrema_FuncExtSS::*)()) &Extrema_FuncExtSS::GetStateNumber, "Save the found extremum.");
cls_Extrema_FuncExtSS.def("NbExt", (Standard_Integer (Extrema_FuncExtSS::*)() const) &Extrema_FuncExtSS::NbExt, "Return the number of found extrema.");
cls_Extrema_FuncExtSS.def("SquareDistance", (Standard_Real (Extrema_FuncExtSS::*)(const Standard_Integer) const) &Extrema_FuncExtSS::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_FuncExtSS.def("PointOnS1", (const Extrema_POnSurf & (Extrema_FuncExtSS::*)(const Standard_Integer) const) &Extrema_FuncExtSS::PointOnS1, "Return the Nth extremum on S1.", py::arg("N"));
cls_Extrema_FuncExtSS.def("PointOnS2", (const Extrema_POnSurf & (Extrema_FuncExtSS::*)(const Standard_Integer) const) &Extrema_FuncExtSS::PointOnS2, "Renvoie le Nieme extremum sur S2.", py::arg("N"));

// Enums

}