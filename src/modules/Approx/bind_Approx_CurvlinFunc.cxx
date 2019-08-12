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
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Approx_CurvlinFunc.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_Approx_CurvlinFunc(py::module &mod){

py::class_<Approx_CurvlinFunc, opencascade::handle<Approx_CurvlinFunc>, Standard_Transient> cls_Approx_CurvlinFunc(mod, "Approx_CurvlinFunc", "defines an abstract curve with curvilinear parametrization");

// Constructors
cls_Approx_CurvlinFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("C"), py::arg("Tol"));
cls_Approx_CurvlinFunc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
cls_Approx_CurvlinFunc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C2D1"), py::arg("C2D2"), py::arg("S1"), py::arg("S2"), py::arg("Tol"));

// Fields

// Methods
cls_Approx_CurvlinFunc.def("SetTol", (void (Approx_CurvlinFunc::*)(const Standard_Real)) &Approx_CurvlinFunc::SetTol, "---Purpose Update the tolerance to used", py::arg("Tol"));
cls_Approx_CurvlinFunc.def("FirstParameter", (Standard_Real (Approx_CurvlinFunc::*)() const) &Approx_CurvlinFunc::FirstParameter, "None");
cls_Approx_CurvlinFunc.def("LastParameter", (Standard_Real (Approx_CurvlinFunc::*)() const) &Approx_CurvlinFunc::LastParameter, "None");
cls_Approx_CurvlinFunc.def("NbIntervals", (Standard_Integer (Approx_CurvlinFunc::*)(const GeomAbs_Shape) const) &Approx_CurvlinFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Approx_CurvlinFunc.def("Intervals", (void (Approx_CurvlinFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Approx_CurvlinFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Approx_CurvlinFunc.def("Trim", (void (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Approx_CurvlinFunc::Trim, "if First < 0 or Last > 1", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Approx_CurvlinFunc.def("Length", (void (Approx_CurvlinFunc::*)()) &Approx_CurvlinFunc::Length, "Computes length of the curve.");
cls_Approx_CurvlinFunc.def("Length", (Standard_Real (Approx_CurvlinFunc::*)(Adaptor3d_Curve &, const Standard_Real, const Standard_Real) const) &Approx_CurvlinFunc::Length, "Computes length of the curve segment.", py::arg("C"), py::arg("FirstU"), py::arg("LasrU"));
cls_Approx_CurvlinFunc.def("GetLength", (Standard_Real (Approx_CurvlinFunc::*)() const) &Approx_CurvlinFunc::GetLength, "None");
cls_Approx_CurvlinFunc.def("GetUParameter", (Standard_Real (Approx_CurvlinFunc::*)(Adaptor3d_Curve &, const Standard_Real, const Standard_Integer) const) &Approx_CurvlinFunc::GetUParameter, "returns original parameter correponding S. if Case == 1 computation is performed on myC2D1 and mySurf1, otherwise it is done on myC2D2 and mySurf2.", py::arg("C"), py::arg("S"), py::arg("NumberOfCurve"));
cls_Approx_CurvlinFunc.def("GetSParameter", (Standard_Real (Approx_CurvlinFunc::*)(const Standard_Real) const) &Approx_CurvlinFunc::GetSParameter, "returns original parameter correponding S.", py::arg("U"));
cls_Approx_CurvlinFunc.def("EvalCase1", (Standard_Boolean (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &) const) &Approx_CurvlinFunc::EvalCase1, "if myCase != 1", py::arg("S"), py::arg("Order"), py::arg("Result"));
cls_Approx_CurvlinFunc.def("EvalCase2", (Standard_Boolean (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &) const) &Approx_CurvlinFunc::EvalCase2, "if myCase != 2", py::arg("S"), py::arg("Order"), py::arg("Result"));
cls_Approx_CurvlinFunc.def("EvalCase3", (Standard_Boolean (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &)) &Approx_CurvlinFunc::EvalCase3, "if myCase != 3", py::arg("S"), py::arg("Order"), py::arg("Result"));
cls_Approx_CurvlinFunc.def_static("get_type_name_", (const char * (*)()) &Approx_CurvlinFunc::get_type_name, "None");
cls_Approx_CurvlinFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_CurvlinFunc::get_type_descriptor, "None");
cls_Approx_CurvlinFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_CurvlinFunc::*)() const) &Approx_CurvlinFunc::DynamicType, "None");

// Enums

}