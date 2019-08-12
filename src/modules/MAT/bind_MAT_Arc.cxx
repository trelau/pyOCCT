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
#include <MAT_BasicElt.hxx>
#include <MAT_Node.hxx>
#include <MAT_Side.hxx>
#include <MAT_Arc.hxx>
#include <Standard_Type.hxx>

void bind_MAT_Arc(py::module &mod){

py::class_<MAT_Arc, opencascade::handle<MAT_Arc>, Standard_Transient> cls_MAT_Arc(mod, "MAT_Arc", "An Arc is associated to each Bisecting of the mat.");

// Constructors
cls_MAT_Arc.def(py::init<const Standard_Integer, const Standard_Integer, const opencascade::handle<MAT_BasicElt> &, const opencascade::handle<MAT_BasicElt> &>(), py::arg("ArcIndex"), py::arg("GeomIndex"), py::arg("FirstElement"), py::arg("SecondElement"));

// Fields

// Methods
cls_MAT_Arc.def("Index", (Standard_Integer (MAT_Arc::*)() const) &MAT_Arc::Index, "Returns the index of <me> in Graph.theArcs.");
cls_MAT_Arc.def("GeomIndex", (Standard_Integer (MAT_Arc::*)() const) &MAT_Arc::GeomIndex, "Returns the index associated of the geometric representation of <me>.");
cls_MAT_Arc.def("FirstElement", (opencascade::handle<MAT_BasicElt> (MAT_Arc::*)() const) &MAT_Arc::FirstElement, "Returns one of the BasicElt equidistant from <me>.");
cls_MAT_Arc.def("SecondElement", (opencascade::handle<MAT_BasicElt> (MAT_Arc::*)() const) &MAT_Arc::SecondElement, "Returns the other BasicElt equidistant from <me>.");
cls_MAT_Arc.def("FirstNode", (opencascade::handle<MAT_Node> (MAT_Arc::*)() const) &MAT_Arc::FirstNode, "Returns one Node extremity of <me>.");
cls_MAT_Arc.def("SecondNode", (opencascade::handle<MAT_Node> (MAT_Arc::*)() const) &MAT_Arc::SecondNode, "Returns the other Node extremity of <me>.");
cls_MAT_Arc.def("TheOtherNode", (opencascade::handle<MAT_Node> (MAT_Arc::*)(const opencascade::handle<MAT_Node> &) const) &MAT_Arc::TheOtherNode, "an Arc has two Node, if <aNode> egal one Returns the other.", py::arg("aNode"));
cls_MAT_Arc.def("HasNeighbour", (Standard_Boolean (MAT_Arc::*)(const opencascade::handle<MAT_Node> &, const MAT_Side) const) &MAT_Arc::HasNeighbour, "Returnst True is there is an arc linked to the Node <aNode> located on the side <aSide> of <me>; if <aNode> is not on <me>", py::arg("aNode"), py::arg("aSide"));
cls_MAT_Arc.def("Neighbour", (opencascade::handle<MAT_Arc> (MAT_Arc::*)(const opencascade::handle<MAT_Node> &, const MAT_Side) const) &MAT_Arc::Neighbour, "Returns the first arc linked to the Node <aNode> located on the side <aSide> of <me>; if HasNeighbour() returns FALSE.", py::arg("aNode"), py::arg("aSide"));
cls_MAT_Arc.def("SetIndex", (void (MAT_Arc::*)(const Standard_Integer)) &MAT_Arc::SetIndex, "None", py::arg("anInteger"));
cls_MAT_Arc.def("SetGeomIndex", (void (MAT_Arc::*)(const Standard_Integer)) &MAT_Arc::SetGeomIndex, "None", py::arg("anInteger"));
cls_MAT_Arc.def("SetFirstElement", (void (MAT_Arc::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_Arc::SetFirstElement, "None", py::arg("aBasicElt"));
cls_MAT_Arc.def("SetSecondElement", (void (MAT_Arc::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_Arc::SetSecondElement, "None", py::arg("aBasicElt"));
cls_MAT_Arc.def("SetFirstNode", (void (MAT_Arc::*)(const opencascade::handle<MAT_Node> &)) &MAT_Arc::SetFirstNode, "None", py::arg("aNode"));
cls_MAT_Arc.def("SetSecondNode", (void (MAT_Arc::*)(const opencascade::handle<MAT_Node> &)) &MAT_Arc::SetSecondNode, "None", py::arg("aNode"));
cls_MAT_Arc.def("SetFirstArc", (void (MAT_Arc::*)(const MAT_Side, const opencascade::handle<MAT_Arc> &)) &MAT_Arc::SetFirstArc, "None", py::arg("aSide"), py::arg("anArc"));
cls_MAT_Arc.def("SetSecondArc", (void (MAT_Arc::*)(const MAT_Side, const opencascade::handle<MAT_Arc> &)) &MAT_Arc::SetSecondArc, "None", py::arg("aSide"), py::arg("anArc"));
cls_MAT_Arc.def("SetNeighbour", (void (MAT_Arc::*)(const MAT_Side, const opencascade::handle<MAT_Node> &, const opencascade::handle<MAT_Arc> &)) &MAT_Arc::SetNeighbour, "None", py::arg("aSide"), py::arg("aNode"), py::arg("anArc"));
cls_MAT_Arc.def_static("get_type_name_", (const char * (*)()) &MAT_Arc::get_type_name, "None");
cls_MAT_Arc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Arc::get_type_descriptor, "None");
cls_MAT_Arc.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Arc::*)() const) &MAT_Arc::DynamicType, "None");

// Enums

}