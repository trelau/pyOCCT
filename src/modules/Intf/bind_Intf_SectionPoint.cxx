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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Intf_PIType.hxx>
#include <Intf_SectionPoint.hxx>
#include <gp_Pnt2d.hxx>

void bind_Intf_SectionPoint(py::module &mod){

py::class_<Intf_SectionPoint> cls_Intf_SectionPoint(mod, "Intf_SectionPoint", "Describes an intersection point between polygons and polyedra.");

// Constructors
cls_Intf_SectionPoint.def(py::init<>());
cls_Intf_SectionPoint.def(py::init<const gp_Pnt &, const Intf_PIType, const Standard_Integer, const Standard_Integer, const Standard_Real, const Intf_PIType, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Where"), py::arg("DimeO"), py::arg("AddrO1"), py::arg("AddrO2"), py::arg("ParamO"), py::arg("DimeT"), py::arg("AddrT1"), py::arg("AddrT2"), py::arg("ParamT"), py::arg("Incid"));
cls_Intf_SectionPoint.def(py::init<const gp_Pnt2d &, const Intf_PIType, const Standard_Integer, const Standard_Real, const Intf_PIType, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Where"), py::arg("DimeO"), py::arg("AddrO1"), py::arg("ParamO"), py::arg("DimeT"), py::arg("AddrT1"), py::arg("ParamT"), py::arg("Incid"));

// Fields

// Methods
// cls_Intf_SectionPoint.def_static("operator new_", (void * (*)(size_t)) &Intf_SectionPoint::operator new, "None", py::arg("theSize"));
// cls_Intf_SectionPoint.def_static("operator delete_", (void (*)(void *)) &Intf_SectionPoint::operator delete, "None", py::arg("theAddress"));
// cls_Intf_SectionPoint.def_static("operator new[]_", (void * (*)(size_t)) &Intf_SectionPoint::operator new[], "None", py::arg("theSize"));
// cls_Intf_SectionPoint.def_static("operator delete[]_", (void (*)(void *)) &Intf_SectionPoint::operator delete[], "None", py::arg("theAddress"));
// cls_Intf_SectionPoint.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_SectionPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf_SectionPoint.def_static("operator delete_", (void (*)(void *, void *)) &Intf_SectionPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf_SectionPoint.def("Pnt", (const gp_Pnt & (Intf_SectionPoint::*)() const) &Intf_SectionPoint::Pnt, "Returns the location of the SectionPoint.");
cls_Intf_SectionPoint.def("ParamOnFirst", (Standard_Real (Intf_SectionPoint::*)() const) &Intf_SectionPoint::ParamOnFirst, "Returns the cumulated Parameter of the SectionPoint on the first element.");
cls_Intf_SectionPoint.def("ParamOnSecond", (Standard_Real (Intf_SectionPoint::*)() const) &Intf_SectionPoint::ParamOnSecond, "Returns the cumulated Parameter of the section point on the second element.");
cls_Intf_SectionPoint.def("TypeOnFirst", (Intf_PIType (Intf_SectionPoint::*)() const) &Intf_SectionPoint::TypeOnFirst, "Returns the type of the section point on the first element.");
cls_Intf_SectionPoint.def("TypeOnSecond", (Intf_PIType (Intf_SectionPoint::*)() const) &Intf_SectionPoint::TypeOnSecond, "Returns the type of the section point on the second element.");
cls_Intf_SectionPoint.def("InfoFirst", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Add1, Standard_Integer & Add2, Standard_Real & Param){ self.InfoFirst(Dim, Add1, Add2, Param); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &>(Add1, Add2, Param); }, "None", py::arg("Dim"), py::arg("Add1"), py::arg("Add2"), py::arg("Param"));
cls_Intf_SectionPoint.def("InfoFirst", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Addr, Standard_Real & Param){ self.InfoFirst(Dim, Addr, Param); return std::tuple<Standard_Integer &, Standard_Real &>(Addr, Param); }, "Gives the datas about the first argument of the Interference.", py::arg("Dim"), py::arg("Addr"), py::arg("Param"));
cls_Intf_SectionPoint.def("InfoSecond", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Add1, Standard_Integer & Add2, Standard_Real & Param){ self.InfoSecond(Dim, Add1, Add2, Param); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &>(Add1, Add2, Param); }, "None", py::arg("Dim"), py::arg("Add1"), py::arg("Add2"), py::arg("Param"));
cls_Intf_SectionPoint.def("InfoSecond", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Addr, Standard_Real & Param){ self.InfoSecond(Dim, Addr, Param); return std::tuple<Standard_Integer &, Standard_Real &>(Addr, Param); }, "Gives the datas about the second argument of the Interference.", py::arg("Dim"), py::arg("Addr"), py::arg("Param"));
cls_Intf_SectionPoint.def("Incidence", (Standard_Real (Intf_SectionPoint::*)() const) &Intf_SectionPoint::Incidence, "Gives the incidence at this section point. The incidence between the two triangles is given by the cosine. The best incidence is 0. (PI/2). The worst is 1. (null angle).");
cls_Intf_SectionPoint.def("IsEqual", (Standard_Boolean (Intf_SectionPoint::*)(const Intf_SectionPoint &) const) &Intf_SectionPoint::IsEqual, "Returns True if the two SectionPoint have the same logical informations.", py::arg("Other"));
cls_Intf_SectionPoint.def("__eq__", (Standard_Boolean (Intf_SectionPoint::*)(const Intf_SectionPoint &) const) &Intf_SectionPoint::operator==, py::is_operator(), "None", py::arg("Other"));
cls_Intf_SectionPoint.def("IsOnSameEdge", (Standard_Boolean (Intf_SectionPoint::*)(const Intf_SectionPoint &) const) &Intf_SectionPoint::IsOnSameEdge, "Returns True if the two SectionPoints are on the same edge of the first or the second element.", py::arg("Other"));
cls_Intf_SectionPoint.def("Merge", (void (Intf_SectionPoint::*)(Intf_SectionPoint &)) &Intf_SectionPoint::Merge, "Merges two SectionPoints.", py::arg("Other"));
cls_Intf_SectionPoint.def("Dump", (void (Intf_SectionPoint::*)(const Standard_Integer) const) &Intf_SectionPoint::Dump, "None", py::arg("Indent"));

// Enums

}