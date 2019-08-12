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
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_GapTool.hxx>
#include <Standard_Type.hxx>
#include <TopOpeBRepDS_DataMapOfIntegerListOfInterference.hxx>
#include <TopOpeBRepDS_DataMapOfInterferenceShape.hxx>

void bind_TopOpeBRepDS_GapTool(py::module &mod){

py::class_<TopOpeBRepDS_GapTool, opencascade::handle<TopOpeBRepDS_GapTool>, Standard_Transient> cls_TopOpeBRepDS_GapTool(mod, "TopOpeBRepDS_GapTool", "None");

// Constructors
cls_TopOpeBRepDS_GapTool.def(py::init<>());
cls_TopOpeBRepDS_GapTool.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Fields

// Methods
cls_TopOpeBRepDS_GapTool.def("Init", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepDS_GapTool::Init, "None", py::arg("HDS"));
cls_TopOpeBRepDS_GapTool.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const Standard_Integer) const) &TopOpeBRepDS_GapTool::Interferences, "None", py::arg("IndexPoint"));
cls_TopOpeBRepDS_GapTool.def("SameInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_GapTool::SameInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_GapTool.def("ChangeSameInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_GapTool::ChangeSameInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_GapTool.def("Curve", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_Curve &) const) &TopOpeBRepDS_GapTool::Curve, "None", py::arg("I"), py::arg("C"));
cls_TopOpeBRepDS_GapTool.def("EdgeSupport", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &) const) &TopOpeBRepDS_GapTool::EdgeSupport, "None", py::arg("I"), py::arg("E"));
cls_TopOpeBRepDS_GapTool.def("FacesSupport", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_GapTool::FacesSupport, "Return les faces qui ont genere la section origine de I", py::arg("I"), py::arg("F1"), py::arg("F2"));
cls_TopOpeBRepDS_GapTool.def("ParameterOnEdge", [](TopOpeBRepDS_GapTool &self, const opencascade::handle<TopOpeBRepDS_Interference> & I, const TopoDS_Shape & E, Standard_Real & U){ Standard_Boolean rv = self.ParameterOnEdge(I, E, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "None", py::arg("I"), py::arg("E"), py::arg("U"));
cls_TopOpeBRepDS_GapTool.def("SetPoint", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Integer)) &TopOpeBRepDS_GapTool::SetPoint, "None", py::arg("I"), py::arg("IndexPoint"));
cls_TopOpeBRepDS_GapTool.def("SetParameterOnEdge", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepDS_GapTool::SetParameterOnEdge, "None", py::arg("I"), py::arg("E"), py::arg("U"));
cls_TopOpeBRepDS_GapTool.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_GapTool::get_type_name, "None");
cls_TopOpeBRepDS_GapTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_GapTool::get_type_descriptor, "None");
cls_TopOpeBRepDS_GapTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_GapTool::*)() const) &TopOpeBRepDS_GapTool::DynamicType, "None");

// Enums

}