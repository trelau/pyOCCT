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
#include <AIS_Dimension.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pln.hxx>
#include <TopoDS_Shape.hxx>
#include <TCollection_AsciiString.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AIS_LengthDimension.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopoDS_Vertex.hxx>

void bind_AIS_LengthDimension(py::module &mod){

py::class_<AIS_LengthDimension, opencascade::handle<AIS_LengthDimension>, AIS_Dimension> cls_AIS_LengthDimension(mod, "AIS_LengthDimension", "Length dimension. Can be constructued: - Between two generic points. - Between two vertices. - Between two faces. - Between two parallel edges. - Between face and edge.");

// Constructors
cls_AIS_LengthDimension.def(py::init<const TopoDS_Face &, const TopoDS_Edge &>(), py::arg("theFace"), py::arg("theEdge"));
cls_AIS_LengthDimension.def(py::init<const TopoDS_Face &, const TopoDS_Face &>(), py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_LengthDimension.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pln &>(), py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("thePlane"));
cls_AIS_LengthDimension.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const gp_Pln &>(), py::arg("theFirstShape"), py::arg("theSecondShape"), py::arg("thePlane"));
cls_AIS_LengthDimension.def(py::init<const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge"), py::arg("thePlane"));

// Fields

// Methods
cls_AIS_LengthDimension.def("FirstPoint", (const gp_Pnt & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::FirstPoint, "Returns first attachement point.");
cls_AIS_LengthDimension.def("SecondPoint", (const gp_Pnt & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::SecondPoint, "Returns second attachement point.");
cls_AIS_LengthDimension.def("FirstShape", (const TopoDS_Shape & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::FirstShape, "Returns first attachement shape.");
cls_AIS_LengthDimension.def("SecondShape", (const TopoDS_Shape & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::SecondShape, "Returns second attachement shape.");
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const gp_Pnt &, const gp_Pnt &, const gp_Pln &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure distance between two points. The dimension will become invalid if the new distance between attachement points is less than Precision::Confusion().", py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("thePlane"));
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const TopoDS_Edge &, const gp_Pln &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure length of edge. The dimension will become invalid if the new length of edge is less than Precision::Confusion().", py::arg("theEdge"), py::arg("thePlane"));
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const TopoDS_Face &, const TopoDS_Face &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure distance between two faces. The dimension will become invalid if the distance can not be measured or it is less than Precision::Confusion().", py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const TopoDS_Face &, const TopoDS_Edge &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure distance between face and edge. The dimension will become invalid if the distance can not be measured or it is less than Precision::Confusion().", py::arg("theFace"), py::arg("theEdge"));
cls_AIS_LengthDimension.def("SetMeasuredShapes", (void (AIS_LengthDimension::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &AIS_LengthDimension::SetMeasuredShapes, "Measure distance between generic pair of shapes (edges, vertices, length), where measuring is applicable.", py::arg("theFirstShape"), py::arg("theSecondShape"));
cls_AIS_LengthDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_LengthDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_LengthDimension.def("SetDisplayUnits", (void (AIS_LengthDimension::*)(const TCollection_AsciiString &)) &AIS_LengthDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_LengthDimension.def("SetModelUnits", (void (AIS_LengthDimension::*)(const TCollection_AsciiString &)) &AIS_LengthDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_LengthDimension.def("SetTextPosition", (void (AIS_LengthDimension::*)(const gp_Pnt &)) &AIS_LengthDimension::SetTextPosition, "None", py::arg("theTextPos"));
cls_AIS_LengthDimension.def("GetTextPosition", (const gp_Pnt (AIS_LengthDimension::*)() const) &AIS_LengthDimension::GetTextPosition, "None");
cls_AIS_LengthDimension.def("SetDirection", [](AIS_LengthDimension &self, const gp_Dir & a0) -> void { return self.SetDirection(a0); });
cls_AIS_LengthDimension.def("SetDirection", (void (AIS_LengthDimension::*)(const gp_Dir &, const Standard_Boolean)) &AIS_LengthDimension::SetDirection, "Set custom direction for dimension. If it is not set, the direction is obtained from the measured geometry (e.g. line between points of dimension) The direction does not change flyout direction of dimension.", py::arg("theDirection"), py::arg("theUseDirection"));
cls_AIS_LengthDimension.def_static("get_type_name_", (const char * (*)()) &AIS_LengthDimension::get_type_name, "None");
cls_AIS_LengthDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_LengthDimension::get_type_descriptor, "None");
cls_AIS_LengthDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::DynamicType, "None");

// Enums

}