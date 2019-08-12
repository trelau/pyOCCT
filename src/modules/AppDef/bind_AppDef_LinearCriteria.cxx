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
#include <AppDef_SmoothCriterion.hxx>
#include <AppDef_MultiLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <FEmTool_Curve.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <AppDef_LinearCriteria.hxx>
#include <Standard_Type.hxx>
#include <FEmTool_ElementaryCriterion.hxx>

void bind_AppDef_LinearCriteria(py::module &mod){

py::class_<AppDef_LinearCriteria, opencascade::handle<AppDef_LinearCriteria>, AppDef_SmoothCriterion> cls_AppDef_LinearCriteria(mod, "AppDef_LinearCriteria", "defined an Linear Criteria to used in variational Smoothing of points.");

// Constructors
cls_AppDef_LinearCriteria.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"));

// Fields

// Methods
cls_AppDef_LinearCriteria.def("SetParameters", (void (AppDef_LinearCriteria::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_LinearCriteria::SetParameters, "None", py::arg("Parameters"));
cls_AppDef_LinearCriteria.def("SetCurve", (void (AppDef_LinearCriteria::*)(const opencascade::handle<FEmTool_Curve> &)) &AppDef_LinearCriteria::SetCurve, "None", py::arg("C"));
cls_AppDef_LinearCriteria.def("GetCurve", (void (AppDef_LinearCriteria::*)(opencascade::handle<FEmTool_Curve> &) const) &AppDef_LinearCriteria::GetCurve, "None", py::arg("C"));
cls_AppDef_LinearCriteria.def("SetEstimation", (void (AppDef_LinearCriteria::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_LinearCriteria::SetEstimation, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_LinearCriteria.def("EstLength", (Standard_Real & (AppDef_LinearCriteria::*)()) &AppDef_LinearCriteria::EstLength, "None");
cls_AppDef_LinearCriteria.def("GetEstimation", [](AppDef_LinearCriteria &self, Standard_Real & E1, Standard_Real & E2, Standard_Real & E3){ self.GetEstimation(E1, E2, E3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(E1, E2, E3); }, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_LinearCriteria.def("AssemblyTable", (opencascade::handle<FEmTool_HAssemblyTable> (AppDef_LinearCriteria::*)() const) &AppDef_LinearCriteria::AssemblyTable, "None");
cls_AppDef_LinearCriteria.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (AppDef_LinearCriteria::*)() const) &AppDef_LinearCriteria::DependenceTable, "None");
cls_AppDef_LinearCriteria.def("QualityValues", [](AppDef_LinearCriteria &self, const Standard_Real J1min, const Standard_Real J2min, const Standard_Real J3min, Standard_Real & J1, Standard_Real & J2, Standard_Real & J3){ Standard_Integer rv = self.QualityValues(J1min, J2min, J3min, J1, J2, J3); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, J1, J2, J3); }, "None", py::arg("J1min"), py::arg("J2min"), py::arg("J3min"), py::arg("J1"), py::arg("J2"), py::arg("J3"));
cls_AppDef_LinearCriteria.def("ErrorValues", [](AppDef_LinearCriteria &self, Standard_Real & MaxError, Standard_Real & QuadraticError, Standard_Real & AverageError){ self.ErrorValues(MaxError, QuadraticError, AverageError); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(MaxError, QuadraticError, AverageError); }, "None", py::arg("MaxError"), py::arg("QuadraticError"), py::arg("AverageError"));
cls_AppDef_LinearCriteria.def("Hessian", (void (AppDef_LinearCriteria::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, math_Matrix &)) &AppDef_LinearCriteria::Hessian, "None", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_AppDef_LinearCriteria.def("Gradient", (void (AppDef_LinearCriteria::*)(const Standard_Integer, const Standard_Integer, math_Vector &)) &AppDef_LinearCriteria::Gradient, "None", py::arg("Element"), py::arg("Dimension"), py::arg("G"));
cls_AppDef_LinearCriteria.def("InputVector", (void (AppDef_LinearCriteria::*)(const math_Vector &, const opencascade::handle<FEmTool_HAssemblyTable> &)) &AppDef_LinearCriteria::InputVector, "Convert the assembly Vector in an Curve;", py::arg("X"), py::arg("AssTable"));
cls_AppDef_LinearCriteria.def("SetWeight", (void (AppDef_LinearCriteria::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_LinearCriteria::SetWeight, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"), py::arg("percentJ1"), py::arg("percentJ2"), py::arg("percentJ3"));
cls_AppDef_LinearCriteria.def("GetWeight", [](AppDef_LinearCriteria &self, Standard_Real & QuadraticWeight, Standard_Real & QualityWeight){ self.GetWeight(QuadraticWeight, QualityWeight); return std::tuple<Standard_Real &, Standard_Real &>(QuadraticWeight, QualityWeight); }, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"));
cls_AppDef_LinearCriteria.def("SetWeight", (void (AppDef_LinearCriteria::*)(const TColStd_Array1OfReal &)) &AppDef_LinearCriteria::SetWeight, "None", py::arg("Weight"));
cls_AppDef_LinearCriteria.def_static("get_type_name_", (const char * (*)()) &AppDef_LinearCriteria::get_type_name, "None");
cls_AppDef_LinearCriteria.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppDef_LinearCriteria::get_type_descriptor, "None");
cls_AppDef_LinearCriteria.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppDef_LinearCriteria::*)() const) &AppDef_LinearCriteria::DynamicType, "None");

// Enums

}