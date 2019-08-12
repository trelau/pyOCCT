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
#include <AIS_Axis.hxx>
#include <Standard_Type.hxx>
#include <Geom_Line.hxx>
#include <Geom_Axis2Placement.hxx>
#include <AIS_TypeOfAxis.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Quantity_Color.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Prs3d_LineAspect.hxx>

void bind_AIS_Axis(py::module &mod){

py::class_<AIS_Axis, opencascade::handle<AIS_Axis>, AIS_InteractiveObject> cls_AIS_Axis(mod, "AIS_Axis", "Locates the x, y and z axes in an Interactive Object. These are used to orient it correctly in presentations from different viewpoints, or to construct a revolved shape, for example, from one of the axes. Conversely, an axis can be created to build a revolved shape and then situated relative to one of the axes of the view.");

// Constructors
cls_AIS_Axis.def(py::init<const opencascade::handle<Geom_Line> &>(), py::arg("aComponent"));
cls_AIS_Axis.def(py::init<const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfAxis>(), py::arg("aComponent"), py::arg("anAxisType"));
cls_AIS_Axis.def(py::init<const opencascade::handle<Geom_Axis1Placement> &>(), py::arg("anAxis"));

// Fields

// Methods
cls_AIS_Axis.def_static("get_type_name_", (const char * (*)()) &AIS_Axis::get_type_name, "None");
cls_AIS_Axis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Axis::get_type_descriptor, "None");
cls_AIS_Axis.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Axis::*)() const) &AIS_Axis::DynamicType, "None");
cls_AIS_Axis.def("Component", (const opencascade::handle<Geom_Line> & (AIS_Axis::*)() const) &AIS_Axis::Component, "Returns the axis entity aComponent and identifies it as a component of a shape.");
cls_AIS_Axis.def("SetComponent", (void (AIS_Axis::*)(const opencascade::handle<Geom_Line> &)) &AIS_Axis::SetComponent, "Sets the coordinates of the lin aComponent.", py::arg("aComponent"));
cls_AIS_Axis.def("Axis2Placement", (const opencascade::handle<Geom_Axis2Placement> & (AIS_Axis::*)() const) &AIS_Axis::Axis2Placement, "Returns the position of axis2 and positions it by identifying it as the x, y, or z axis and giving its direction in 3D space. The coordinate system used is right-handed.");
cls_AIS_Axis.def("SetAxis2Placement", (void (AIS_Axis::*)(const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfAxis)) &AIS_Axis::SetAxis2Placement, "Allows you to provide settings for aComponent:the position and direction of an axis in 3D space. The coordinate system used is right-handed.", py::arg("aComponent"), py::arg("anAxisType"));
cls_AIS_Axis.def("SetAxis1Placement", (void (AIS_Axis::*)(const opencascade::handle<Geom_Axis1Placement> &)) &AIS_Axis::SetAxis1Placement, "Constructs a new line to serve as the axis anAxis in 3D space.", py::arg("anAxis"));
cls_AIS_Axis.def("TypeOfAxis", (AIS_TypeOfAxis (AIS_Axis::*)() const) &AIS_Axis::TypeOfAxis, "Returns the type of axis.");
cls_AIS_Axis.def("SetTypeOfAxis", (void (AIS_Axis::*)(const AIS_TypeOfAxis)) &AIS_Axis::SetTypeOfAxis, "Constructs the entity theTypeAxis to stock information concerning type of axis.", py::arg("theTypeAxis"));
cls_AIS_Axis.def("IsXYZAxis", (Standard_Boolean (AIS_Axis::*)() const) &AIS_Axis::IsXYZAxis, "Returns a signature of 2 for axis datums. When you activate mode 2 by a signature, you pick AIS objects of type AIS_Axis.");
cls_AIS_Axis.def("AcceptDisplayMode", (Standard_Boolean (AIS_Axis::*)(const Standard_Integer) const) &AIS_Axis::AcceptDisplayMode, "Returns true if the interactive object accepts the display mode aMode.", py::arg("aMode"));
cls_AIS_Axis.def("Compute", (void (AIS_Axis::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Axis::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Axis.def("Signature", (Standard_Integer (AIS_Axis::*)() const) &AIS_Axis::Signature, "None");
cls_AIS_Axis.def("Type", (AIS_KindOfInteractive (AIS_Axis::*)() const) &AIS_Axis::Type, "None");
cls_AIS_Axis.def("SetColor", (void (AIS_Axis::*)(const Quantity_Color &)) &AIS_Axis::SetColor, "None", py::arg("aColor"));
cls_AIS_Axis.def("SetWidth", (void (AIS_Axis::*)(const Standard_Real)) &AIS_Axis::SetWidth, "None", py::arg("aValue"));
cls_AIS_Axis.def("UnsetColor", (void (AIS_Axis::*)()) &AIS_Axis::UnsetColor, "None");
cls_AIS_Axis.def("UnsetWidth", (void (AIS_Axis::*)()) &AIS_Axis::UnsetWidth, "None");

// Enums

}