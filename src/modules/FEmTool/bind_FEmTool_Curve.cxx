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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <PLib_Base.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <FEmTool_Curve.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>

void bind_FEmTool_Curve(py::module &mod){

py::class_<FEmTool_Curve, opencascade::handle<FEmTool_Curve>, Standard_Transient> cls_FEmTool_Curve(mod, "FEmTool_Curve", "Curve defined by Polynomial Elements.");

// Constructors
cls_FEmTool_Curve.def(py::init<const Standard_Integer, const Standard_Integer, const opencascade::handle<PLib_Base> &, const Standard_Real>(), py::arg("Dimension"), py::arg("NbElements"), py::arg("TheBase"), py::arg("Tolerance"));

// Fields

// Methods
cls_FEmTool_Curve.def("Knots", (TColStd_Array1OfReal & (FEmTool_Curve::*)() const) &FEmTool_Curve::Knots, "None");
cls_FEmTool_Curve.def("SetElement", (void (FEmTool_Curve::*)(const Standard_Integer, const TColStd_Array2OfReal &)) &FEmTool_Curve::SetElement, "None", py::arg("IndexOfElement"), py::arg("Coeffs"));
cls_FEmTool_Curve.def("D0", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D0, "None", py::arg("U"), py::arg("Pnt"));
cls_FEmTool_Curve.def("D1", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D1, "None", py::arg("U"), py::arg("Vec"));
cls_FEmTool_Curve.def("D2", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D2, "None", py::arg("U"), py::arg("Vec"));
cls_FEmTool_Curve.def("Length", [](FEmTool_Curve &self, const Standard_Real FirstU, const Standard_Real LastU, Standard_Real & Length){ self.Length(FirstU, LastU, Length); return Length; }, "None", py::arg("FirstU"), py::arg("LastU"), py::arg("Length"));
cls_FEmTool_Curve.def("GetElement", (void (FEmTool_Curve::*)(const Standard_Integer, TColStd_Array2OfReal &)) &FEmTool_Curve::GetElement, "None", py::arg("IndexOfElement"), py::arg("Coeffs"));
cls_FEmTool_Curve.def("GetPolynom", (void (FEmTool_Curve::*)(TColStd_Array1OfReal &)) &FEmTool_Curve::GetPolynom, "returns coefficients of all elements in canonical base.", py::arg("Coeffs"));
cls_FEmTool_Curve.def("NbElements", (Standard_Integer (FEmTool_Curve::*)() const) &FEmTool_Curve::NbElements, "None");
cls_FEmTool_Curve.def("Dimension", (Standard_Integer (FEmTool_Curve::*)() const) &FEmTool_Curve::Dimension, "None");
cls_FEmTool_Curve.def("Base", (opencascade::handle<PLib_Base> (FEmTool_Curve::*)() const) &FEmTool_Curve::Base, "None");
cls_FEmTool_Curve.def("Degree", (Standard_Integer (FEmTool_Curve::*)(const Standard_Integer) const) &FEmTool_Curve::Degree, "None", py::arg("IndexOfElement"));
cls_FEmTool_Curve.def("SetDegree", (void (FEmTool_Curve::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_Curve::SetDegree, "None", py::arg("IndexOfElement"), py::arg("Degree"));
cls_FEmTool_Curve.def("ReduceDegree", [](FEmTool_Curve &self, const Standard_Integer IndexOfElement, const Standard_Real Tol, Standard_Integer & NewDegree, Standard_Real & MaxError){ self.ReduceDegree(IndexOfElement, Tol, NewDegree, MaxError); return std::tuple<Standard_Integer &, Standard_Real &>(NewDegree, MaxError); }, "None", py::arg("IndexOfElement"), py::arg("Tol"), py::arg("NewDegree"), py::arg("MaxError"));
cls_FEmTool_Curve.def_static("get_type_name_", (const char * (*)()) &FEmTool_Curve::get_type_name, "None");
cls_FEmTool_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_Curve::get_type_descriptor, "None");
cls_FEmTool_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_Curve::*)() const) &FEmTool_Curve::DynamicType, "None");

// Enums

}