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
#include <gp_Pln.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <AIS_DiameterDimension.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_EntityOwner.hxx>

void bind_AIS_DiameterDimension(py::module &mod){

py::class_<AIS_DiameterDimension, opencascade::handle<AIS_DiameterDimension>, AIS_Dimension> cls_AIS_DiameterDimension(mod, "AIS_DiameterDimension", "Diameter dimension. Can be constructued: - On generic circle. - On generic circle with user-defined anchor point on that circle (dimension plane is oriented to follow the anchor point). - On generic circle in the specified plane. - On generic shape containing geometry that can be measured by diameter dimension: circle wire, circular face, etc. The anchor point is the location of the left attachement point of dimension on the circle. The anchor point computation is processed after dimension plane setting so that positive flyout direction stands with normal of the circle and the normal of the plane. If the plane is user-defined the anchor point was computed as intersection of the plane and the basis circle. Among two intersection points the one is selected so that positive flyout direction vector and the circle normal on the one side form the circle plane. (corner between positive flyout directio nand the circle normal is acute.) If the plane is computed automatically (by default it is the circle plane), the anchor point is the zero parameter point of the circle.");

// Constructors
cls_AIS_DiameterDimension.def(py::init<const gp_Circ &>(), py::arg("theCircle"));
cls_AIS_DiameterDimension.def(py::init<const gp_Circ &, const gp_Pln &>(), py::arg("theCircle"), py::arg("thePlane"));
cls_AIS_DiameterDimension.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_AIS_DiameterDimension.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("theShape"), py::arg("thePlane"));

// Fields

// Methods
cls_AIS_DiameterDimension.def("Circle", (const gp_Circ & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::Circle, "Returns measured geometry circle.");
cls_AIS_DiameterDimension.def("AnchorPoint", (gp_Pnt (AIS_DiameterDimension::*)()) &AIS_DiameterDimension::AnchorPoint, "Returns anchor point on circle for diameter dimension.");
cls_AIS_DiameterDimension.def("Shape", (const TopoDS_Shape & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::Shape, "Returns the measured shape.");
cls_AIS_DiameterDimension.def("SetMeasuredGeometry", (void (AIS_DiameterDimension::*)(const gp_Circ &)) &AIS_DiameterDimension::SetMeasuredGeometry, "Measure diameter of the circle. The actual dimension plane is used for determining anchor points on the circle to attach the dimension lines to. The dimension will become invalid if the diameter of the circle is less than Precision::Confusion().", py::arg("theCircle"));
cls_AIS_DiameterDimension.def("SetMeasuredGeometry", (void (AIS_DiameterDimension::*)(const TopoDS_Shape &)) &AIS_DiameterDimension::SetMeasuredGeometry, "Measure diameter on the passed shape, if applicable. The dimension will become invalid if the passed shape is not measurable or if measured diameter value is less than Precision::Confusion().", py::arg("theShape"));
cls_AIS_DiameterDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_DiameterDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_DiameterDimension.def("SetDisplayUnits", (void (AIS_DiameterDimension::*)(const TCollection_AsciiString &)) &AIS_DiameterDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_DiameterDimension.def("SetModelUnits", (void (AIS_DiameterDimension::*)(const TCollection_AsciiString &)) &AIS_DiameterDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_DiameterDimension.def("SetTextPosition", (void (AIS_DiameterDimension::*)(const gp_Pnt &)) &AIS_DiameterDimension::SetTextPosition, "None", py::arg("theTextPos"));
cls_AIS_DiameterDimension.def("GetTextPosition", (const gp_Pnt (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::GetTextPosition, "None");
cls_AIS_DiameterDimension.def_static("get_type_name_", (const char * (*)()) &AIS_DiameterDimension::get_type_name, "None");
cls_AIS_DiameterDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_DiameterDimension::get_type_descriptor, "None");
cls_AIS_DiameterDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::DynamicType, "None");

// Enums

}