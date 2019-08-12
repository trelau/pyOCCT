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
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_Interference(py::module &mod){

py::class_<TopOpeBRepDS_Interference, opencascade::handle<TopOpeBRepDS_Interference>, Standard_Transient> cls_TopOpeBRepDS_Interference(mod, "TopOpeBRepDS_Interference", "An interference is the description of the attachment of a new geometry on a geometry. For example an intersection point on an Edge or on a Curve.");

// Constructors
cls_TopOpeBRepDS_Interference.def(py::init<>());
cls_TopOpeBRepDS_Interference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"));
cls_TopOpeBRepDS_Interference.def(py::init<const opencascade::handle<TopOpeBRepDS_Interference> &>(), py::arg("I"));

// Fields

// Methods
cls_TopOpeBRepDS_Interference.def("Transition", (const TopOpeBRepDS_Transition & (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::Transition, "None");
cls_TopOpeBRepDS_Interference.def("ChangeTransition", (TopOpeBRepDS_Transition & (TopOpeBRepDS_Interference::*)()) &TopOpeBRepDS_Interference::ChangeTransition, "None");
cls_TopOpeBRepDS_Interference.def("Transition", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Transition &)) &TopOpeBRepDS_Interference::Transition, "None", py::arg("T"));
cls_TopOpeBRepDS_Interference.def("GKGSKS", [](TopOpeBRepDS_Interference &self, TopOpeBRepDS_Kind & GK, Standard_Integer & G, TopOpeBRepDS_Kind & SK, Standard_Integer & S){ self.GKGSKS(GK, G, SK, S); return std::tuple<Standard_Integer &, Standard_Integer &>(G, S); }, "return GeometryType + Geometry + SupportType + Support", py::arg("GK"), py::arg("G"), py::arg("SK"), py::arg("S"));
cls_TopOpeBRepDS_Interference.def("SupportType", (TopOpeBRepDS_Kind (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::SupportType, "None");
cls_TopOpeBRepDS_Interference.def("Support", (Standard_Integer (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::Support, "None");
cls_TopOpeBRepDS_Interference.def("GeometryType", (TopOpeBRepDS_Kind (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::GeometryType, "None");
cls_TopOpeBRepDS_Interference.def("Geometry", (Standard_Integer (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::Geometry, "None");
cls_TopOpeBRepDS_Interference.def("SetGeometry", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::SetGeometry, "None", py::arg("GI"));
cls_TopOpeBRepDS_Interference.def("SupportType", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Interference::SupportType, "None", py::arg("ST"));
cls_TopOpeBRepDS_Interference.def("Support", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::Support, "None", py::arg("S"));
cls_TopOpeBRepDS_Interference.def("GeometryType", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Interference::GeometryType, "None", py::arg("GT"));
cls_TopOpeBRepDS_Interference.def("Geometry", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::Geometry, "None", py::arg("G"));
cls_TopOpeBRepDS_Interference.def("HasSameSupport", (Standard_Boolean (TopOpeBRepDS_Interference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Interference::HasSameSupport, "None", py::arg("Other"));
cls_TopOpeBRepDS_Interference.def("HasSameGeometry", (Standard_Boolean (TopOpeBRepDS_Interference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Interference::HasSameGeometry, "None", py::arg("Other"));
cls_TopOpeBRepDS_Interference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Interference::get_type_name, "None");
cls_TopOpeBRepDS_Interference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Interference::get_type_descriptor, "None");
cls_TopOpeBRepDS_Interference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::DynamicType, "None");

// Enums

}