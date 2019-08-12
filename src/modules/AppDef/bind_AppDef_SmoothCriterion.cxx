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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <FEmTool_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <AppDef_SmoothCriterion.hxx>
#include <Standard_Type.hxx>

void bind_AppDef_SmoothCriterion(py::module &mod){

py::class_<AppDef_SmoothCriterion, opencascade::handle<AppDef_SmoothCriterion>, Standard_Transient> cls_AppDef_SmoothCriterion(mod, "AppDef_SmoothCriterion", "defined criterion to smooth points in curve");

// Fields

// Methods
cls_AppDef_SmoothCriterion.def("SetParameters", (void (AppDef_SmoothCriterion::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_SmoothCriterion::SetParameters, "None", py::arg("Parameters"));
cls_AppDef_SmoothCriterion.def("SetCurve", (void (AppDef_SmoothCriterion::*)(const opencascade::handle<FEmTool_Curve> &)) &AppDef_SmoothCriterion::SetCurve, "None", py::arg("C"));
cls_AppDef_SmoothCriterion.def("GetCurve", (void (AppDef_SmoothCriterion::*)(opencascade::handle<FEmTool_Curve> &) const) &AppDef_SmoothCriterion::GetCurve, "None", py::arg("C"));
cls_AppDef_SmoothCriterion.def("SetEstimation", (void (AppDef_SmoothCriterion::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_SmoothCriterion::SetEstimation, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_SmoothCriterion.def("EstLength", (Standard_Real & (AppDef_SmoothCriterion::*)()) &AppDef_SmoothCriterion::EstLength, "None");
cls_AppDef_SmoothCriterion.def("GetEstimation", [](AppDef_SmoothCriterion &self, Standard_Real & E1, Standard_Real & E2, Standard_Real & E3){ self.GetEstimation(E1, E2, E3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(E1, E2, E3); }, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_SmoothCriterion.def("AssemblyTable", (opencascade::handle<FEmTool_HAssemblyTable> (AppDef_SmoothCriterion::*)() const) &AppDef_SmoothCriterion::AssemblyTable, "None");
cls_AppDef_SmoothCriterion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (AppDef_SmoothCriterion::*)() const) &AppDef_SmoothCriterion::DependenceTable, "None");
cls_AppDef_SmoothCriterion.def("QualityValues", [](AppDef_SmoothCriterion &self, const Standard_Real J1min, const Standard_Real J2min, const Standard_Real J3min, Standard_Real & J1, Standard_Real & J2, Standard_Real & J3){ Standard_Integer rv = self.QualityValues(J1min, J2min, J3min, J1, J2, J3); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, J1, J2, J3); }, "None", py::arg("J1min"), py::arg("J2min"), py::arg("J3min"), py::arg("J1"), py::arg("J2"), py::arg("J3"));
cls_AppDef_SmoothCriterion.def("ErrorValues", [](AppDef_SmoothCriterion &self, Standard_Real & MaxError, Standard_Real & QuadraticError, Standard_Real & AverageError){ self.ErrorValues(MaxError, QuadraticError, AverageError); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(MaxError, QuadraticError, AverageError); }, "None", py::arg("MaxError"), py::arg("QuadraticError"), py::arg("AverageError"));
cls_AppDef_SmoothCriterion.def("Hessian", (void (AppDef_SmoothCriterion::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, math_Matrix &)) &AppDef_SmoothCriterion::Hessian, "None", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_AppDef_SmoothCriterion.def("Gradient", (void (AppDef_SmoothCriterion::*)(const Standard_Integer, const Standard_Integer, math_Vector &)) &AppDef_SmoothCriterion::Gradient, "None", py::arg("Element"), py::arg("Dimension"), py::arg("G"));
cls_AppDef_SmoothCriterion.def("InputVector", (void (AppDef_SmoothCriterion::*)(const math_Vector &, const opencascade::handle<FEmTool_HAssemblyTable> &)) &AppDef_SmoothCriterion::InputVector, "Convert the assembly Vector in an Curve;", py::arg("X"), py::arg("AssTable"));
cls_AppDef_SmoothCriterion.def("SetWeight", (void (AppDef_SmoothCriterion::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_SmoothCriterion::SetWeight, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"), py::arg("percentJ1"), py::arg("percentJ2"), py::arg("percentJ3"));
cls_AppDef_SmoothCriterion.def("GetWeight", [](AppDef_SmoothCriterion &self, Standard_Real & QuadraticWeight, Standard_Real & QualityWeight){ self.GetWeight(QuadraticWeight, QualityWeight); return std::tuple<Standard_Real &, Standard_Real &>(QuadraticWeight, QualityWeight); }, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"));
cls_AppDef_SmoothCriterion.def("SetWeight", (void (AppDef_SmoothCriterion::*)(const TColStd_Array1OfReal &)) &AppDef_SmoothCriterion::SetWeight, "None", py::arg("Weight"));
cls_AppDef_SmoothCriterion.def_static("get_type_name_", (const char * (*)()) &AppDef_SmoothCriterion::get_type_name, "None");
cls_AppDef_SmoothCriterion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppDef_SmoothCriterion::get_type_descriptor, "None");
cls_AppDef_SmoothCriterion.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppDef_SmoothCriterion::*)() const) &AppDef_SmoothCriterion::DynamicType, "None");

// Enums

}