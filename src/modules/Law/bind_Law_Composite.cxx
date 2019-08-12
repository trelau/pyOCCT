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
#include <Law_Laws.hxx>
#include <Law_Composite.hxx>
#include <Standard_Type.hxx>

void bind_Law_Composite(py::module &mod){

py::class_<Law_Composite, opencascade::handle<Law_Composite>, Law_Function> cls_Law_Composite(mod, "Law_Composite", "Loi composite constituee d une liste de lois de ranges consecutifs. Cette implementation un peu lourde permet de reunir en une seule loi des portions de loi construites de facon independantes (par exemple en interactif) et de lancer le walking d un coup a l echelle d une ElSpine. CET OBJET REPOND DONC A UN PROBLEME D IMPLEMENTATION SPECIFIQUE AUX CONGES!!!");

// Constructors
cls_Law_Composite.def(py::init<>());
cls_Law_Composite.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("First"), py::arg("Last"), py::arg("Tol"));

// Fields

// Methods
cls_Law_Composite.def("Continuity", (GeomAbs_Shape (Law_Composite::*)() const) &Law_Composite::Continuity, "None");
cls_Law_Composite.def("NbIntervals", (Standard_Integer (Law_Composite::*)(const GeomAbs_Shape) const) &Law_Composite::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Law_Composite.def("Intervals", (void (Law_Composite::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Law_Composite::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Law_Composite.def("Value", (Standard_Real (Law_Composite::*)(const Standard_Real)) &Law_Composite::Value, "Returns the value at parameter X.", py::arg("X"));
cls_Law_Composite.def("D1", [](Law_Composite &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ self.D1(X, F, D); return std::tuple<Standard_Real &, Standard_Real &>(F, D); }, "Returns the value and the first derivative at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Law_Composite.def("D2", [](Law_Composite &self, const Standard_Real X, Standard_Real & F, Standard_Real & D, Standard_Real & D2){ self.D2(X, F, D, D2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, D, D2); }, "Returns the value, first and second derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
cls_Law_Composite.def("Trim", (opencascade::handle<Law_Function> (Law_Composite::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Law_Composite::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
cls_Law_Composite.def("Bounds", [](Law_Composite &self, Standard_Real & PFirst, Standard_Real & PLast){ self.Bounds(PFirst, PLast); return std::tuple<Standard_Real &, Standard_Real &>(PFirst, PLast); }, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
cls_Law_Composite.def("ChangeElementaryLaw", (opencascade::handle<Law_Function> & (Law_Composite::*)(const Standard_Real)) &Law_Composite::ChangeElementaryLaw, "Returns the elementary function of the composite used to compute at parameter W.", py::arg("W"));
cls_Law_Composite.def("ChangeLaws", (Law_Laws & (Law_Composite::*)()) &Law_Composite::ChangeLaws, "None");
cls_Law_Composite.def("IsPeriodic", (Standard_Boolean (Law_Composite::*)() const) &Law_Composite::IsPeriodic, "None");
cls_Law_Composite.def("SetPeriodic", (void (Law_Composite::*)()) &Law_Composite::SetPeriodic, "None");
cls_Law_Composite.def_static("get_type_name_", (const char * (*)()) &Law_Composite::get_type_name, "None");
cls_Law_Composite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Composite::get_type_descriptor, "None");
cls_Law_Composite.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Composite::*)() const) &Law_Composite::DynamicType, "None");

// Enums

}