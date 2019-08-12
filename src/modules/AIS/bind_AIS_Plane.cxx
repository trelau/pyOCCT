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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <AIS_Plane.hxx>
#include <Standard_Type.hxx>
#include <Geom_Plane.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Axis2Placement.hxx>
#include <AIS_TypeOfPlane.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <AIS_InteractiveContext.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <Quantity_Color.hxx>
#include <PrsMgr_PresentationManager3d.hxx>

void bind_AIS_Plane(py::module &mod){

py::class_<AIS_Plane, opencascade::handle<AIS_Plane>, AIS_InteractiveObject> cls_AIS_Plane(mod, "AIS_Plane", "Constructs plane datums to be used in construction of composite shapes.");

// Constructors
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &>(), py::arg("aComponent"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aCurrentMode"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &>(), py::arg("aComponent"), py::arg("aCenter"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aCenter"), py::arg("aCurrentMode"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"), py::arg("aCurrentMode"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfPlane>(), py::arg("aComponent"), py::arg("aPlaneType"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfPlane, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aPlaneType"), py::arg("aCurrentMode"));

// Fields

// Methods
cls_AIS_Plane.def_static("get_type_name_", (const char * (*)()) &AIS_Plane::get_type_name, "None");
cls_AIS_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Plane::get_type_descriptor, "None");
cls_AIS_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Plane::*)() const) &AIS_Plane::DynamicType, "None");
cls_AIS_Plane.def("SetSize", (void (AIS_Plane::*)(const Standard_Real)) &AIS_Plane::SetSize, "Same value for x and y directions", py::arg("aValue"));
cls_AIS_Plane.def("SetSize", (void (AIS_Plane::*)(const Standard_Real, const Standard_Real)) &AIS_Plane::SetSize, "Sets the size defined by the length along the X axis XVal and the length along the Y axis YVal.", py::arg("Xval"), py::arg("YVal"));
cls_AIS_Plane.def("UnsetSize", (void (AIS_Plane::*)()) &AIS_Plane::UnsetSize, "None");
cls_AIS_Plane.def("Size", [](AIS_Plane &self, Standard_Real & X, Standard_Real & Y){ Standard_Boolean rv = self.Size(X, Y); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, X, Y); }, "None", py::arg("X"), py::arg("Y"));
cls_AIS_Plane.def("HasOwnSize", (Standard_Boolean (AIS_Plane::*)() const) &AIS_Plane::HasOwnSize, "None");
cls_AIS_Plane.def("Signature", (Standard_Integer (AIS_Plane::*)() const) &AIS_Plane::Signature, "None");
cls_AIS_Plane.def("Type", (AIS_KindOfInteractive (AIS_Plane::*)() const) &AIS_Plane::Type, "None");
cls_AIS_Plane.def("Component", (const opencascade::handle<Geom_Plane> & (AIS_Plane::*)()) &AIS_Plane::Component, "Returns the component specified in SetComponent.");
cls_AIS_Plane.def("SetComponent", (void (AIS_Plane::*)(const opencascade::handle<Geom_Plane> &)) &AIS_Plane::SetComponent, "Creates an instance of the plane aComponent.", py::arg("aComponent"));
cls_AIS_Plane.def("PlaneAttributes", (Standard_Boolean (AIS_Plane::*)(opencascade::handle<Geom_Plane> &, gp_Pnt &, gp_Pnt &, gp_Pnt &)) &AIS_Plane::PlaneAttributes, "Returns the settings for the selected plane aComponent, provided in SetPlaneAttributes. These include the points aCenter, aPmin, and aPmax", py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"));
cls_AIS_Plane.def("SetPlaneAttributes", (void (AIS_Plane::*)(const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &AIS_Plane::SetPlaneAttributes, "Allows you to provide settings other than default ones for the selected plane. These include: center point aCenter, maximum aPmax and minimum aPmin.", py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"));
cls_AIS_Plane.def("Center", (const gp_Pnt & (AIS_Plane::*)() const) &AIS_Plane::Center, "Returns the coordinates of the center point.");
cls_AIS_Plane.def("SetCenter", (void (AIS_Plane::*)(const gp_Pnt &)) &AIS_Plane::SetCenter, "Provides settings for the center theCenter other than (0, 0, 0).", py::arg("theCenter"));
cls_AIS_Plane.def("SetAxis2Placement", (void (AIS_Plane::*)(const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfPlane)) &AIS_Plane::SetAxis2Placement, "Allows you to provide settings for the position and direction of one of the plane's axes, aComponent, in 3D space. The coordinate system used is right-handed, and the type of plane aPlaneType is one of: - AIS_ TOPL_Unknown - AIS_ TOPL_XYPlane - AIS_ TOPL_XZPlane - AIS_ TOPL_YZPlane}.", py::arg("aComponent"), py::arg("aPlaneType"));
cls_AIS_Plane.def("Axis2Placement", (opencascade::handle<Geom_Axis2Placement> (AIS_Plane::*)()) &AIS_Plane::Axis2Placement, "Returns the position of the plane's axis2 system identifying the x, y, or z axis and giving the plane a direction in 3D space. An axis2 system is a right-handed coordinate system.");
cls_AIS_Plane.def("TypeOfPlane", (AIS_TypeOfPlane (AIS_Plane::*)()) &AIS_Plane::TypeOfPlane, "Returns the type of plane - xy, yz, xz or unknown.");
cls_AIS_Plane.def("IsXYZPlane", (Standard_Boolean (AIS_Plane::*)()) &AIS_Plane::IsXYZPlane, "Returns the type of plane - xy, yz, or xz.");
cls_AIS_Plane.def("CurrentMode", (Standard_Boolean (AIS_Plane::*)()) &AIS_Plane::CurrentMode, "Returns the non-default current display mode set by SetCurrentMode.");
cls_AIS_Plane.def("SetCurrentMode", (void (AIS_Plane::*)(const Standard_Boolean)) &AIS_Plane::SetCurrentMode, "Allows you to provide settings for a non-default current display mode.", py::arg("theCurrentMode"));
cls_AIS_Plane.def("AcceptDisplayMode", (Standard_Boolean (AIS_Plane::*)(const Standard_Integer) const) &AIS_Plane::AcceptDisplayMode, "Returns true if the display mode selected, aMode, is valid for planes.", py::arg("aMode"));
cls_AIS_Plane.def("SetContext", (void (AIS_Plane::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_Plane::SetContext, "connection to <aCtx> default drawer implies a recomputation of Frame values.", py::arg("aCtx"));
cls_AIS_Plane.def("TypeOfSensitivity", (Select3D_TypeOfSensitivity (AIS_Plane::*)() const) &AIS_Plane::TypeOfSensitivity, "Returns the type of sensitivity for the plane;");
cls_AIS_Plane.def("SetTypeOfSensitivity", (void (AIS_Plane::*)(Select3D_TypeOfSensitivity)) &AIS_Plane::SetTypeOfSensitivity, "Sets the type of sensitivity for the plane.", py::arg("theTypeOfSensitivity"));
cls_AIS_Plane.def("Compute", (void (AIS_Plane::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Plane::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Plane.def("ComputeSelection", (void (AIS_Plane::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_Plane::ComputeSelection, "None", py::arg("theSelection"), py::arg("theMode"));
cls_AIS_Plane.def("SetColor", (void (AIS_Plane::*)(const Quantity_Color &)) &AIS_Plane::SetColor, "None", py::arg("aColor"));
cls_AIS_Plane.def("UnsetColor", (void (AIS_Plane::*)()) &AIS_Plane::UnsetColor, "None");

// Enums

}