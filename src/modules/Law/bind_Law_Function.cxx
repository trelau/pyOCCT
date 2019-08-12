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
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <Standard_Type.hxx>

void bind_Law_Function(py::module &mod){

py::class_<Law_Function, opencascade::handle<Law_Function>, Standard_Transient> cls_Law_Function(mod, "Law_Function", "Root class for evolution laws.");

// Fields

// Methods
cls_Law_Function.def("Continuity", (GeomAbs_Shape (Law_Function::*)() const) &Law_Function::Continuity, "None");
cls_Law_Function.def("NbIntervals", (Standard_Integer (Law_Function::*)(const GeomAbs_Shape) const) &Law_Function::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Law_Function.def("Intervals", (void (Law_Function::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Law_Function::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Law_Function.def("Value", (Standard_Real (Law_Function::*)(const Standard_Real)) &Law_Function::Value, "Returns the value of the function at the point of parameter X.", py::arg("X"));
cls_Law_Function.def("D1", [](Law_Function &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ self.D1(X, F, D); return std::tuple<Standard_Real &, Standard_Real &>(F, D); }, "Returns the value F and the first derivative D of the function at the point of parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Law_Function.def("D2", [](Law_Function &self, const Standard_Real X, Standard_Real & F, Standard_Real & D, Standard_Real & D2){ self.D2(X, F, D, D2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, D, D2); }, "Returns the value, first and seconde derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
cls_Law_Function.def("Trim", (opencascade::handle<Law_Function> (Law_Function::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Law_Function::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
cls_Law_Function.def("Bounds", [](Law_Function &self, Standard_Real & PFirst, Standard_Real & PLast){ self.Bounds(PFirst, PLast); return std::tuple<Standard_Real &, Standard_Real &>(PFirst, PLast); }, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
cls_Law_Function.def_static("get_type_name_", (const char * (*)()) &Law_Function::get_type_name, "None");
cls_Law_Function.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Function::get_type_descriptor, "None");
cls_Law_Function.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Function::*)() const) &Law_Function::DynamicType, "None");

// Enums

}