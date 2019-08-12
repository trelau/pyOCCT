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
#include <TopoDS_Edge.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_TypeOfAngle.hxx>
#include <AIS_TypeOfAngleArrowVisibility.hxx>
#include <Standard_Handle.hxx>
#include <AIS_AngleDimension.hxx>
#include <Standard_Type.hxx>
#include <gp_Dir.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Prs3d_DimensionTextHorizontalPosition.hxx>
#include <gp_Pln.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_EntityOwner.hxx>

void bind_AIS_AngleDimension(py::module &mod){

py::class_<AIS_AngleDimension, opencascade::handle<AIS_AngleDimension>, AIS_Dimension> cls_AIS_AngleDimension(mod, "AIS_AngleDimension", "Angle dimension. Can be constructed: - on two intersected edges. - on three points or vertices. - on conical face. - between two intersected faces.");

// Constructors
cls_AIS_AngleDimension.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theFirstEdge"), py::arg("theSecondEdge"));
cls_AIS_AngleDimension.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("theThirdPoint"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("theFirstVertex"), py::arg("theSecondVertex"), py::arg("theThirdVertex"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Face &>(), py::arg("theCone"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Face &, const TopoDS_Face &>(), py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Face &, const TopoDS_Face &, const gp_Pnt &>(), py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("thePoint"));

// Fields

// Methods
cls_AIS_AngleDimension.def("FirstPoint", (const gp_Pnt & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::FirstPoint, "Returns first point forming the angle.");
cls_AIS_AngleDimension.def("SecondPoint", (const gp_Pnt & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::SecondPoint, "Returns second point forming the angle.");
cls_AIS_AngleDimension.def("CenterPoint", (const gp_Pnt & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::CenterPoint, "Returns center point forming the angle.");
cls_AIS_AngleDimension.def("FirstShape", (const TopoDS_Shape & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::FirstShape, "Returns first argument shape.");
cls_AIS_AngleDimension.def("SecondShape", (const TopoDS_Shape & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::SecondShape, "Returns second argument shape.");
cls_AIS_AngleDimension.def("ThirdShape", (const TopoDS_Shape & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::ThirdShape, "Returns third argument shape.");
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures minimum angle dimension between two linear edges. These two edges should be intersected by each other. Otherwise the geometry is not valid.", py::arg("theFirstEdge"), py::arg("theSecondEdge"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle defined by three points.", py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("theThridPoint"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle defined by three vertices.", py::arg("theFirstVertex"), py::arg("theSecondVertex"), py::arg("theThirdVertex"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Face &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle of conical face.", py::arg("theCone"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Face &, const TopoDS_Face &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle between two planar faces.", py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Face &, const TopoDS_Face &, const gp_Pnt &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle between two planar faces.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("thePoint"));
cls_AIS_AngleDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_AngleDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_AngleDimension.def("SetDisplayUnits", (void (AIS_AngleDimension::*)(const TCollection_AsciiString &)) &AIS_AngleDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_AngleDimension.def("SetModelUnits", (void (AIS_AngleDimension::*)(const TCollection_AsciiString &)) &AIS_AngleDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_AngleDimension.def("SetTextPosition", (void (AIS_AngleDimension::*)(const gp_Pnt &)) &AIS_AngleDimension::SetTextPosition, "Principle of horizontal text alignment settings: - divide circle into two halves according to attachment points - if aTextPos is between attach points -> Center + positive flyout - if aTextPos is not between attach points but in this half -> Left or Right + positive flyout - if aTextPos is between reflections of attach points -> Center + negative flyout - if aTextPos is not between reflections of attach points -> Left or Right + negative flyout", py::arg("theTextPos"));
cls_AIS_AngleDimension.def("GetTextPosition", (const gp_Pnt (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetTextPosition, "None");
cls_AIS_AngleDimension.def("SetType", (void (AIS_AngleDimension::*)(const AIS_TypeOfAngle)) &AIS_AngleDimension::SetType, "Sets angle type.", py::arg("theType"));
cls_AIS_AngleDimension.def("GetType", (AIS_TypeOfAngle (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetType, "Returns the current angle type.");
cls_AIS_AngleDimension.def("SetArrowsVisibility", (void (AIS_AngleDimension::*)(const AIS_TypeOfAngleArrowVisibility &)) &AIS_AngleDimension::SetArrowsVisibility, "Sets visible arrows type", py::arg("theType"));
cls_AIS_AngleDimension.def("GetArrowsVisibility", (AIS_TypeOfAngleArrowVisibility (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetArrowsVisibility, "Returns the type of visibility of arrows.");
cls_AIS_AngleDimension.def_static("get_type_name_", (const char * (*)()) &AIS_AngleDimension::get_type_name, "None");
cls_AIS_AngleDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AngleDimension::get_type_descriptor, "None");
cls_AIS_AngleDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::DynamicType, "None");

// Enums

}