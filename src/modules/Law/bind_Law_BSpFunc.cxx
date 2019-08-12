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
#include <Law_Function.hxx>
#include <Standard_Handle.hxx>
#include <Law_BSpline.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Law_BSpFunc.hxx>
#include <Standard_Type.hxx>

void bind_Law_BSpFunc(py::module &mod){

py::class_<Law_BSpFunc, opencascade::handle<Law_BSpFunc>, Law_Function> cls_Law_BSpFunc(mod, "Law_BSpFunc", "Law Function based on a BSpline curve 1d. Package methods and classes are implemented in package Law to construct the basis curve with several constraints.");

// Constructors
cls_Law_BSpFunc.def(py::init<>());
cls_Law_BSpFunc.def(py::init<const opencascade::handle<Law_BSpline> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("First"), py::arg("Last"));

// Fields

// Methods
cls_Law_BSpFunc.def("Continuity", (GeomAbs_Shape (Law_BSpFunc::*)() const) &Law_BSpFunc::Continuity, "None");
cls_Law_BSpFunc.def("NbIntervals", (Standard_Integer (Law_BSpFunc::*)(const GeomAbs_Shape) const) &Law_BSpFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Law_BSpFunc.def("Intervals", (void (Law_BSpFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Law_BSpFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Law_BSpFunc.def("Value", (Standard_Real (Law_BSpFunc::*)(const Standard_Real)) &Law_BSpFunc::Value, "None", py::arg("X"));
cls_Law_BSpFunc.def("D1", [](Law_BSpFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ self.D1(X, F, D); return std::tuple<Standard_Real &, Standard_Real &>(F, D); }, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Law_BSpFunc.def("D2", [](Law_BSpFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D, Standard_Real & D2){ self.D2(X, F, D, D2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, D, D2); }, "None", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
cls_Law_BSpFunc.def("Trim", (opencascade::handle<Law_Function> (Law_BSpFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Law_BSpFunc::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
cls_Law_BSpFunc.def("Bounds", [](Law_BSpFunc &self, Standard_Real & PFirst, Standard_Real & PLast){ self.Bounds(PFirst, PLast); return std::tuple<Standard_Real &, Standard_Real &>(PFirst, PLast); }, "None", py::arg("PFirst"), py::arg("PLast"));
cls_Law_BSpFunc.def("Curve", (opencascade::handle<Law_BSpline> (Law_BSpFunc::*)() const) &Law_BSpFunc::Curve, "None");
cls_Law_BSpFunc.def("SetCurve", (void (Law_BSpFunc::*)(const opencascade::handle<Law_BSpline> &)) &Law_BSpFunc::SetCurve, "None", py::arg("C"));
cls_Law_BSpFunc.def_static("get_type_name_", (const char * (*)()) &Law_BSpFunc::get_type_name, "None");
cls_Law_BSpFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_BSpFunc::get_type_descriptor, "None");
cls_Law_BSpFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_BSpFunc::*)() const) &Law_BSpFunc::DynamicType, "None");

// Enums

}