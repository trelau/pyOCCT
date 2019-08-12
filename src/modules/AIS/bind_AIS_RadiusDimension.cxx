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
#include <gp_Circ.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <AIS_RadiusDimension.hxx>
#include <Standard_Type.hxx>
#include <gp_Pln.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>

void bind_AIS_RadiusDimension(py::module &mod){

py::class_<AIS_RadiusDimension, opencascade::handle<AIS_RadiusDimension>, AIS_Dimension> cls_AIS_RadiusDimension(mod, "AIS_RadiusDimension", "Radius dimension. Can be constructued: - On generic circle. - On generic circle with user-defined anchor point on that circle. - On generic shape containing geometry that can be measured by diameter dimension: circle wire, arc, circular face, etc. The anchor point is the location of left attachement point of dimension on the circle. It can be user-specified, or computed as middle point on the arc. The radius dimension always lies in the plane of the measured circle. The dimension is considered as invalid if the user-specified anchor point is not lying on the circle, if the radius of the circle is less than Precision::Confusion(). In case if the dimension is built on the arbitrary shape, it can be considered as invalid if the shape does not contain circle geometry.");

// Constructors
cls_AIS_RadiusDimension.def(py::init<const gp_Circ &>(), py::arg("theCircle"));
cls_AIS_RadiusDimension.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("theCircle"), py::arg("theAnchorPoint"));
cls_AIS_RadiusDimension.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Fields

// Methods
cls_AIS_RadiusDimension.def("Circle", (const gp_Circ & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::Circle, "Returns measured geometry circle.");
cls_AIS_RadiusDimension.def("AnchorPoint", (const gp_Pnt & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::AnchorPoint, "Returns anchor point on circle for radius dimension.");
cls_AIS_RadiusDimension.def("Shape", (const TopoDS_Shape & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::Shape, "Returns the measured shape.");
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const gp_Circ &)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius of the circle. The dimension will become invalid if the radius of the circle is less than Precision::Confusion().", py::arg("theCircle"));
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", [](AIS_RadiusDimension &self, const gp_Circ & a0, const gp_Pnt & a1) -> void { return self.SetMeasuredGeometry(a0, a1); });
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const gp_Circ &, const gp_Pnt &, const Standard_Boolean)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius of the circle and orient the dimension so the dimension lines attaches to anchor point on the circle. The dimension will become invalid if the radius of the circle is less than Precision::Confusion().", py::arg("theCircle"), py::arg("theAnchorPoint"), py::arg("theHasAnchor"));
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const TopoDS_Shape &)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius on the passed shape, if applicable. The dimension will become invalid if the passed shape is not measurable or if measured diameter value is less than Precision::Confusion().", py::arg("theShape"));
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", [](AIS_RadiusDimension &self, const TopoDS_Shape & a0, const gp_Pnt & a1) -> void { return self.SetMeasuredGeometry(a0, a1); });
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const TopoDS_Shape &, const gp_Pnt &, const Standard_Boolean)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius on the passed shape, if applicable. The dimension will become invalid if the passed shape is not measurable or if measured diameter value is less than Precision::Confusion().", py::arg("theShape"), py::arg("theAnchorPoint"), py::arg("theHasAnchor"));
cls_AIS_RadiusDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_RadiusDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_RadiusDimension.def("SetDisplayUnits", (void (AIS_RadiusDimension::*)(const TCollection_AsciiString &)) &AIS_RadiusDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_RadiusDimension.def("SetModelUnits", (void (AIS_RadiusDimension::*)(const TCollection_AsciiString &)) &AIS_RadiusDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_RadiusDimension.def("SetTextPosition", (void (AIS_RadiusDimension::*)(const gp_Pnt &)) &AIS_RadiusDimension::SetTextPosition, "None", py::arg("theTextPos"));
cls_AIS_RadiusDimension.def("GetTextPosition", (const gp_Pnt (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::GetTextPosition, "None");
cls_AIS_RadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_RadiusDimension::get_type_name, "None");
cls_AIS_RadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_RadiusDimension::get_type_descriptor, "None");
cls_AIS_RadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::DynamicType, "None");

// Enums

}