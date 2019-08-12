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
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Law_Constant.hxx>
#include <Standard_Type.hxx>

void bind_Law_Constant(py::module &mod){

py::class_<Law_Constant, opencascade::handle<Law_Constant>, Law_Function> cls_Law_Constant(mod, "Law_Constant", "Loi constante");

// Constructors
cls_Law_Constant.def(py::init<>());

// Fields

// Methods
cls_Law_Constant.def("Set", (void (Law_Constant::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Law_Constant::Set, "Set the radius and the range of the constant Law.", py::arg("Radius"), py::arg("PFirst"), py::arg("PLast"));
cls_Law_Constant.def("Continuity", (GeomAbs_Shape (Law_Constant::*)() const) &Law_Constant::Continuity, "Returns GeomAbs_CN");
cls_Law_Constant.def("NbIntervals", (Standard_Integer (Law_Constant::*)(const GeomAbs_Shape) const) &Law_Constant::NbIntervals, "Returns 1", py::arg("S"));
cls_Law_Constant.def("Intervals", (void (Law_Constant::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Law_Constant::Intervals, "None", py::arg("T"), py::arg("S"));
cls_Law_Constant.def("Value", (Standard_Real (Law_Constant::*)(const Standard_Real)) &Law_Constant::Value, "Returns the value at parameter X.", py::arg("X"));
cls_Law_Constant.def("D1", [](Law_Constant &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ self.D1(X, F, D); return std::tuple<Standard_Real &, Standard_Real &>(F, D); }, "Returns the value and the first derivative at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Law_Constant.def("D2", [](Law_Constant &self, const Standard_Real X, Standard_Real & F, Standard_Real & D, Standard_Real & D2){ self.D2(X, F, D, D2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, D, D2); }, "Returns the value, first and second derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
cls_Law_Constant.def("Trim", (opencascade::handle<Law_Function> (Law_Constant::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Law_Constant::Trim, "None", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
cls_Law_Constant.def("Bounds", [](Law_Constant &self, Standard_Real & PFirst, Standard_Real & PLast){ self.Bounds(PFirst, PLast); return std::tuple<Standard_Real &, Standard_Real &>(PFirst, PLast); }, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
cls_Law_Constant.def_static("get_type_name_", (const char * (*)()) &Law_Constant::get_type_name, "None");
cls_Law_Constant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Constant::get_type_descriptor, "None");
cls_Law_Constant.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Constant::*)() const) &Law_Constant::DynamicType, "None");

// Enums

}