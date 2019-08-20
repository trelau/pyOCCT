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
#include <Standard.hxx>
#include <Geom2dHatch_Elements.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dHatch_Element.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TopAbs_Orientation.hxx>
#include <Geom2dHatch_MapOfElements.hxx>

void bind_Geom2dHatch_Elements(py::module &mod){

py::class_<Geom2dHatch_Elements, std::unique_ptr<Geom2dHatch_Elements>> cls_Geom2dHatch_Elements(mod, "Geom2dHatch_Elements", "None");

// Constructors
cls_Geom2dHatch_Elements.def(py::init<>());
cls_Geom2dHatch_Elements.def(py::init<const Geom2dHatch_Elements &>(), py::arg("Other"));

// Fields

// Methods
// cls_Geom2dHatch_Elements.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_Elements::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_Elements.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_Elements::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_Elements.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_Elements::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_Elements.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_Elements::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_Elements.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_Elements::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_Elements.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_Elements::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_Elements.def("Clear", (void (Geom2dHatch_Elements::*)()) &Geom2dHatch_Elements::Clear, "None");
cls_Geom2dHatch_Elements.def("Bind", (Standard_Boolean (Geom2dHatch_Elements::*)(const Standard_Integer, const Geom2dHatch_Element &)) &Geom2dHatch_Elements::Bind, "None", py::arg("K"), py::arg("I"));
cls_Geom2dHatch_Elements.def("IsBound", (Standard_Boolean (Geom2dHatch_Elements::*)(const Standard_Integer) const) &Geom2dHatch_Elements::IsBound, "None", py::arg("K"));
cls_Geom2dHatch_Elements.def("UnBind", (Standard_Boolean (Geom2dHatch_Elements::*)(const Standard_Integer)) &Geom2dHatch_Elements::UnBind, "None", py::arg("K"));
cls_Geom2dHatch_Elements.def("Find", (const Geom2dHatch_Element & (Geom2dHatch_Elements::*)(const Standard_Integer) const) &Geom2dHatch_Elements::Find, "None", py::arg("K"));
cls_Geom2dHatch_Elements.def("__call__", (const Geom2dHatch_Element & (Geom2dHatch_Elements::*)(const Standard_Integer) const) &Geom2dHatch_Elements::operator(), py::is_operator(), "None", py::arg("K"));
cls_Geom2dHatch_Elements.def("ChangeFind", (Geom2dHatch_Element & (Geom2dHatch_Elements::*)(const Standard_Integer)) &Geom2dHatch_Elements::ChangeFind, "None", py::arg("K"));
cls_Geom2dHatch_Elements.def("__call__", (Geom2dHatch_Element & (Geom2dHatch_Elements::*)(const Standard_Integer)) &Geom2dHatch_Elements::operator(), py::is_operator(), "None", py::arg("K"));
cls_Geom2dHatch_Elements.def("CheckPoint", (Standard_Boolean (Geom2dHatch_Elements::*)(gp_Pnt2d &)) &Geom2dHatch_Elements::CheckPoint, "None", py::arg("P"));
cls_Geom2dHatch_Elements.def("Reject", (Standard_Boolean (Geom2dHatch_Elements::*)(const gp_Pnt2d &) const) &Geom2dHatch_Elements::Reject, "None", py::arg("P"));
cls_Geom2dHatch_Elements.def("Segment", [](Geom2dHatch_Elements &self, const gp_Pnt2d & P, gp_Lin2d & L, Standard_Real & Par){ Standard_Boolean rv = self.Segment(P, L, Par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Par); }, "None", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_Geom2dHatch_Elements.def("OtherSegment", [](Geom2dHatch_Elements &self, const gp_Pnt2d & P, gp_Lin2d & L, Standard_Real & Par){ Standard_Boolean rv = self.OtherSegment(P, L, Par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Par); }, "None", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_Geom2dHatch_Elements.def("InitWires", (void (Geom2dHatch_Elements::*)()) &Geom2dHatch_Elements::InitWires, "None");
cls_Geom2dHatch_Elements.def("MoreWires", (Standard_Boolean (Geom2dHatch_Elements::*)() const) &Geom2dHatch_Elements::MoreWires, "None");
cls_Geom2dHatch_Elements.def("NextWire", (void (Geom2dHatch_Elements::*)()) &Geom2dHatch_Elements::NextWire, "None");
cls_Geom2dHatch_Elements.def("RejectWire", (Standard_Boolean (Geom2dHatch_Elements::*)(const gp_Lin2d &, const Standard_Real) const) &Geom2dHatch_Elements::RejectWire, "None", py::arg("L"), py::arg("Par"));
cls_Geom2dHatch_Elements.def("InitEdges", (void (Geom2dHatch_Elements::*)()) &Geom2dHatch_Elements::InitEdges, "None");
cls_Geom2dHatch_Elements.def("MoreEdges", (Standard_Boolean (Geom2dHatch_Elements::*)() const) &Geom2dHatch_Elements::MoreEdges, "None");
cls_Geom2dHatch_Elements.def("NextEdge", (void (Geom2dHatch_Elements::*)()) &Geom2dHatch_Elements::NextEdge, "None");
cls_Geom2dHatch_Elements.def("RejectEdge", (Standard_Boolean (Geom2dHatch_Elements::*)(const gp_Lin2d &, const Standard_Real) const) &Geom2dHatch_Elements::RejectEdge, "None", py::arg("L"), py::arg("Par"));
cls_Geom2dHatch_Elements.def("CurrentEdge", (void (Geom2dHatch_Elements::*)(Geom2dAdaptor_Curve &, TopAbs_Orientation &) const) &Geom2dHatch_Elements::CurrentEdge, "None", py::arg("E"), py::arg("Or"));

// Enums

}