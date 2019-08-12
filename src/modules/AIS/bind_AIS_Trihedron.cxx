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
#include <AIS_Trihedron.hxx>
#include <Standard_Type.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Prs3d_DatumMode.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Quantity_Color.hxx>
#include <Prs3d_DatumParts.hxx>
#include <TCollection_ExtendedString.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Prs3d_Drawer.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Prs3d_DatumAspect.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_PointAspect.hxx>
#include <NCollection_DataMap.hxx>
#include <Graphic3d_Group.hxx>
#include <NCollection_List.hxx>

void bind_AIS_Trihedron(py::module &mod){

py::class_<AIS_Trihedron, opencascade::handle<AIS_Trihedron>, AIS_InteractiveObject> cls_AIS_Trihedron(mod, "AIS_Trihedron", "Create a selectable trihedron The trihedron includes 1 origin, 3 axes and 3 labels. Default text of labels are 'X', 'Y', 'Z'. Color of origin and any axis, color of arrows and labels may be changed. Visual presentation might be shown in two, shaded and wireframe modes, wireframe by default). There are 4 modes of selection: - AIS_TrihedronSelectionMode_EntireObject to select trihedron, priority = 1 - AIS_TrihedronSelectionMode_Origin to select its origin, priority = 5 - AIS_TrihedronSelectionMode_Axes to select its axis, priority = 3 - AIS_TrihedronSelectionMode_MainPlanes to select its planes, priority = 2");

// Constructors
cls_AIS_Trihedron.def(py::init<const opencascade::handle<Geom_Axis2Placement> &>(), py::arg("theComponent"));

// Fields

// Methods
cls_AIS_Trihedron.def_static("get_type_name_", (const char * (*)()) &AIS_Trihedron::get_type_name, "None");
cls_AIS_Trihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Trihedron::get_type_descriptor, "None");
cls_AIS_Trihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Trihedron::*)() const) &AIS_Trihedron::DynamicType, "None");
cls_AIS_Trihedron.def("SetDatumDisplayMode", (void (AIS_Trihedron::*)(Prs3d_DatumMode)) &AIS_Trihedron::SetDatumDisplayMode, "Sets Shading or Wireframe display mode, triangle or segment graphic group is used relatively.", py::arg("theMode"));
cls_AIS_Trihedron.def("DatumDisplayMode", (Prs3d_DatumMode (AIS_Trihedron::*)() const) &AIS_Trihedron::DatumDisplayMode, "Returns datum display mode.");
cls_AIS_Trihedron.def("Component", (const opencascade::handle<Geom_Axis2Placement> & (AIS_Trihedron::*)() const) &AIS_Trihedron::Component, "Returns the right-handed coordinate system set in SetComponent.");
cls_AIS_Trihedron.def("SetComponent", (void (AIS_Trihedron::*)(const opencascade::handle<Geom_Axis2Placement> &)) &AIS_Trihedron::SetComponent, "Constructs the right-handed coordinate system aComponent.", py::arg("theComponent"));
cls_AIS_Trihedron.def("HasOwnSize", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::HasOwnSize, "Returns true if the trihedron object has a size other than the default size of 100 mm. along each axis.");
cls_AIS_Trihedron.def("SetSize", (void (AIS_Trihedron::*)(const Standard_Real)) &AIS_Trihedron::SetSize, "Sets the size aValue for the trihedron object. The default value is 100 mm.", py::arg("theValue"));
cls_AIS_Trihedron.def("UnsetSize", (void (AIS_Trihedron::*)()) &AIS_Trihedron::UnsetSize, "Removes any non-default settings for size of this trihedron object. If the object has 1 color, the default size of the drawer is reproduced, otherwise DatumAspect becomes null.");
cls_AIS_Trihedron.def("Size", (Standard_Real (AIS_Trihedron::*)() const) &AIS_Trihedron::Size, "None");
cls_AIS_Trihedron.def("AcceptDisplayMode", (Standard_Boolean (AIS_Trihedron::*)(const Standard_Integer) const) &AIS_Trihedron::AcceptDisplayMode, "Returns true if the display mode selected, aMode, is valid for trihedron datums.", py::arg("theMode"));
cls_AIS_Trihedron.def("Signature", (Standard_Integer (AIS_Trihedron::*)() const) &AIS_Trihedron::Signature, "Returns index 3, selection of the planes XOY, YOZ, XOZ.");
cls_AIS_Trihedron.def("Type", (AIS_KindOfInteractive (AIS_Trihedron::*)() const) &AIS_Trihedron::Type, "Indicates that the type of Interactive Object is datum.");
cls_AIS_Trihedron.def("SetColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetColor, "Sets the color theColor for this trihedron object, it changes color of axes.", py::arg("theColor"));
cls_AIS_Trihedron.def("SetTextColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetTextColor, "Sets color of label of trihedron axes.", py::arg("theColor"));
cls_AIS_Trihedron.def("HasTextColor", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::HasTextColor, "Returns true if trihedron has own text color");
cls_AIS_Trihedron.def("TextColor", (Quantity_Color (AIS_Trihedron::*)() const) &AIS_Trihedron::TextColor, "Returns trihedron text color");
cls_AIS_Trihedron.def("SetArrowColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetArrowColor, "Sets color of arrow of trihedron axes. Used only in wireframe mode", py::arg("theColor"));
cls_AIS_Trihedron.def("HasArrowColor", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::HasArrowColor, "Returns true if trihedron has own arrow color");
cls_AIS_Trihedron.def("ArrowColor", (Quantity_Color (AIS_Trihedron::*)() const) &AIS_Trihedron::ArrowColor, "Returns trihedron arrow color");
cls_AIS_Trihedron.def("UnsetColor", (void (AIS_Trihedron::*)()) &AIS_Trihedron::UnsetColor, "Removes the settings for color.");
cls_AIS_Trihedron.def("SetDatumPartColor", (void (AIS_Trihedron::*)(const Prs3d_DatumParts, const Quantity_Color &)) &AIS_Trihedron::SetDatumPartColor, "Sets color of datum part: origin or some of trihedron axes. If presentation is shading mode, this color is set for both sides of facing model", py::arg("thePart"), py::arg("theColor"));
cls_AIS_Trihedron.def("DatumPartColor", (Quantity_Color (AIS_Trihedron::*)(Prs3d_DatumParts)) &AIS_Trihedron::DatumPartColor, "Returns color of datum part: origin or some of trihedron axes.", py::arg("thePart"));
cls_AIS_Trihedron.def("SetOriginColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetOriginColor, "Sets color of origin. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("SetXAxisColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetXAxisColor, "Sets color of x-axis. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("SetYAxisColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetYAxisColor, "Sets color of y-axis. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("SetAxisColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetAxisColor, "Sets color of z-axis. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("ToDrawArrows", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::ToDrawArrows, "Returns true if arrows are to be drawn");
cls_AIS_Trihedron.def("SetDrawArrows", (void (AIS_Trihedron::*)(const Standard_Boolean)) &AIS_Trihedron::SetDrawArrows, "Sets whether to draw the arrows in visualization", py::arg("theToDraw"));
cls_AIS_Trihedron.def("SetSelectionPriority", (void (AIS_Trihedron::*)(Prs3d_DatumParts, Standard_Integer)) &AIS_Trihedron::SetSelectionPriority, "Sets priority of selection for owner of the given type", py::arg("thePart"), py::arg("thePriority"));
cls_AIS_Trihedron.def("SelectionPriority", (Standard_Integer (AIS_Trihedron::*)(Prs3d_DatumParts)) &AIS_Trihedron::SelectionPriority, "Sets priority of selection for owner of the given type", py::arg("thePart"));
cls_AIS_Trihedron.def("SetLabel", (void (AIS_Trihedron::*)(const Prs3d_DatumParts, const TCollection_ExtendedString &)) &AIS_Trihedron::SetLabel, "Sets text label for trihedron axis. Parameter thePart should be XAxis, YAxis or ZAxis", py::arg("thePart"), py::arg("thePriority"));
cls_AIS_Trihedron.def("Label", (const TCollection_ExtendedString & (AIS_Trihedron::*)(Prs3d_DatumParts)) &AIS_Trihedron::Label, "Returns text of axis. Parameter thePart should be XAxis, YAxis or ZAxis", py::arg("thePart"));
cls_AIS_Trihedron.def("IsAutoHilight", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::IsAutoHilight, "Disables auto highlighting to use HilightSelected() and HilightOwnerWithColor() overridden methods.");
cls_AIS_Trihedron.def("ClearSelected", (void (AIS_Trihedron::*)()) &AIS_Trihedron::ClearSelected, "Method which clear all selected owners belonging to this selectable object ( for fast presentation draw ).");
cls_AIS_Trihedron.def("HilightSelected", (void (AIS_Trihedron::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &AIS_Trihedron::HilightSelected, "Method which draws selected owners ( for fast presentation draw ).", py::arg("thePM"), py::arg("theOwners"));
cls_AIS_Trihedron.def("HilightOwnerWithColor", (void (AIS_Trihedron::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Trihedron::HilightOwnerWithColor, "Method which hilight an owner belonging to this selectable object ( for fast presentation draw ).", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));

// Enums

}