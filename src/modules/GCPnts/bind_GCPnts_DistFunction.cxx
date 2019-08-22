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
#include <math_Function.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GCPnts_DistFunction.hxx>
#include <gp_Lin.hxx>

void bind_GCPnts_DistFunction(py::module &mod){

py::class_<GCPnts_DistFunction, math_Function> cls_GCPnts_DistFunction(mod, "GCPnts_DistFunction", "Class to define function, which calculates square distance between point on curve C(u), U1 <= u <= U2 and line passing through points C(U1) and C(U2) This function is used in any minimisation algorithm to define maximal deviation between curve and line, which required one variable function without derivative (for ex. math_BrentMinimum)");

// Constructors
cls_GCPnts_DistFunction.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("U1"), py::arg("U2"));
// cls_GCPnts_DistFunction.def(py::init<const GCPnts_DistFunction &>(), py::arg("theOther"));

// Fields

// Methods
cls_GCPnts_DistFunction.def("Value", [](GCPnts_DistFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));

// Enums

}