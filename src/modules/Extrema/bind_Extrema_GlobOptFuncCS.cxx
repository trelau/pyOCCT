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
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Extrema_GlobOptFuncCS.hxx>

void bind_Extrema_GlobOptFuncCS(py::module &mod){

py::class_<Extrema_GlobOptFuncCS, math_MultipleVarFunctionWithHessian> cls_Extrema_GlobOptFuncCS(mod, "Extrema_GlobOptFuncCS", "This class implements function which calculate square Eucluidean distance between point on curve and point on surface in case of continuity is C2.");

// Constructors
cls_Extrema_GlobOptFuncCS.def(py::init<const Adaptor3d_Curve *, const Adaptor3d_Surface *>(), py::arg("C"), py::arg("S"));

// Fields

// Methods
cls_Extrema_GlobOptFuncCS.def("NbVariables", (Standard_Integer (Extrema_GlobOptFuncCS::*)() const) &Extrema_GlobOptFuncCS::NbVariables, "None");
cls_Extrema_GlobOptFuncCS.def("Value", [](Extrema_GlobOptFuncCS &self, const math_Vector & theX, Standard_Real & theF){ Standard_Boolean rv = self.Value(theX, theF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theF); }, "None", py::arg("theX"), py::arg("theF"));
cls_Extrema_GlobOptFuncCS.def("Gradient", (Standard_Boolean (Extrema_GlobOptFuncCS::*)(const math_Vector &, math_Vector &)) &Extrema_GlobOptFuncCS::Gradient, "None", py::arg("theX"), py::arg("theG"));
cls_Extrema_GlobOptFuncCS.def("Values", [](Extrema_GlobOptFuncCS &self, const math_Vector & theX, Standard_Real & theF, math_Vector & theG){ Standard_Boolean rv = self.Values(theX, theF, theG); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theF); }, "None", py::arg("theX"), py::arg("theF"), py::arg("theG"));
cls_Extrema_GlobOptFuncCS.def("Values", [](Extrema_GlobOptFuncCS &self, const math_Vector & theX, Standard_Real & theF, math_Vector & theG, math_Matrix & theH){ Standard_Boolean rv = self.Values(theX, theF, theG, theH); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theF); }, "None", py::arg("theX"), py::arg("theF"), py::arg("theG"), py::arg("theH"));

// Enums

}