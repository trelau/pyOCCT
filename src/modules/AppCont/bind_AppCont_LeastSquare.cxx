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
#include <AppCont_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <NCollection_Array1.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <AppCont_LeastSquare.hxx>

void bind_AppCont_LeastSquare(py::module &mod){

py::class_<AppCont_LeastSquare> cls_AppCont_LeastSquare(mod, "AppCont_LeastSquare", "None");

// Constructors
cls_AppCont_LeastSquare.def(py::init<const AppCont_Function &, const Standard_Real, const Standard_Real, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer, const Standard_Integer>(), py::arg("SSP"), py::arg("U0"), py::arg("U1"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Deg"), py::arg("NbPoints"));

// Fields

// Methods
cls_AppCont_LeastSquare.def("Value", (const AppParCurves_MultiCurve & (AppCont_LeastSquare::*)()) &AppCont_LeastSquare::Value, "None");
cls_AppCont_LeastSquare.def("Error", [](AppCont_LeastSquare &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "None", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppCont_LeastSquare.def("IsDone", (Standard_Boolean (AppCont_LeastSquare::*)() const) &AppCont_LeastSquare::IsDone, "None");

// Enums

}