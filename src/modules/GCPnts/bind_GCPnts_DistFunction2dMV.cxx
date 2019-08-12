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
#include <math_MultipleVarFunction.hxx>
#include <GCPnts_DistFunction2d.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>

void bind_GCPnts_DistFunction2dMV(py::module &mod){

py::class_<GCPnts_DistFunction2dMV, std::unique_ptr<GCPnts_DistFunction2dMV, Deleter<GCPnts_DistFunction2dMV>>, math_MultipleVarFunction> cls_GCPnts_DistFunction2dMV(mod, "GCPnts_DistFunction2dMV", "The same as class GCPnts_DistFunction2d, but it can be used in minimization algorithms that requires multi variable function");

// Constructors
cls_GCPnts_DistFunction2dMV.def(py::init<GCPnts_DistFunction2d &>(), py::arg("theCurvLinDist"));

// Fields

// Methods
cls_GCPnts_DistFunction2dMV.def("Value", [](GCPnts_DistFunction2dMV &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_GCPnts_DistFunction2dMV.def("NbVariables", (Standard_Integer (GCPnts_DistFunction2dMV::*)() const) &GCPnts_DistFunction2dMV::NbVariables, "None");

// Enums

}