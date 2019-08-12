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
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_SequenceOfGroup.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_BndBox3d.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_ViewAffinity.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_CStructure(py::module &mod){

py::class_<Graphic3d_CStructure, opencascade::handle<Graphic3d_CStructure>, Standard_Transient> cls_Graphic3d_CStructure(mod, "Graphic3d_CStructure", "Low-level graphic structure interface");

// Fields
cls_Graphic3d_CStructure.def_readwrite("Id", &Graphic3d_CStructure::Id, "None");
cls_Graphic3d_CStructure.def_readwrite("myZLayer", &Graphic3d_CStructure::myZLayer, "None");
cls_Graphic3d_CStructure.def_readwrite("Priority", &Graphic3d_CStructure::Priority, "None");
cls_Graphic3d_CStructure.def_readwrite("PreviousPriority", &Graphic3d_CStructure::PreviousPriority, "None");
cls_Graphic3d_CStructure.def_readwrite("ContainsFacet", &Graphic3d_CStructure::ContainsFacet, "None");
cls_Graphic3d_CStructure.def_readwrite("ViewAffinity", &Graphic3d_CStructure::ViewAffinity, "view affinity mask");
// cls_Graphic3d_CStructure.def_readwrite("IsInfinite", &Graphic3d_CStructure::IsInfinite, "None");
// cls_Graphic3d_CStructure.def_readwrite("stick", &Graphic3d_CStructure::stick, "displaying state - should be set when structure has been added to scene graph (but can be in hidden state)");
// cls_Graphic3d_CStructure.def_readwrite("highlight", &Graphic3d_CStructure::highlight, "None");
// cls_Graphic3d_CStructure.def_readwrite("visible", &Graphic3d_CStructure::visible, "visibility flag - can be used to suppress structure while leaving it in the scene graph");
// cls_Graphic3d_CStructure.def_readwrite("HLRValidation", &Graphic3d_CStructure::HLRValidation, "None");
// cls_Graphic3d_CStructure.def_readwrite("IsForHighlight", &Graphic3d_CStructure::IsForHighlight, "None");
// cls_Graphic3d_CStructure.def_readwrite("IsMutable", &Graphic3d_CStructure::IsMutable, "None");
// cls_Graphic3d_CStructure.def_readwrite("Is2dText", &Graphic3d_CStructure::Is2dText, "None");

// Methods
cls_Graphic3d_CStructure.def("GraphicDriver", (const opencascade::handle<Graphic3d_GraphicDriver> & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::GraphicDriver, "Returns graphic driver created this structure");
cls_Graphic3d_CStructure.def("Groups", (const Graphic3d_SequenceOfGroup & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::Groups, "Returns graphic groups");
cls_Graphic3d_CStructure.def("Transformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::Transformation, "Return transformation.");
cls_Graphic3d_CStructure.def("SetTransformation", (void (Graphic3d_CStructure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_CStructure::SetTransformation, "Assign transformation.", py::arg("theTrsf"));
cls_Graphic3d_CStructure.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::TransformPersistence, "Return transformation persistence.");
cls_Graphic3d_CStructure.def("SetTransformPersistence", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &Graphic3d_CStructure::SetTransformPersistence, "Set transformation persistence.", py::arg("theTrsfPers"));
cls_Graphic3d_CStructure.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::ClipPlanes, "Returns associated clip planes");
cls_Graphic3d_CStructure.def("SetClipPlanes", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_CStructure::SetClipPlanes, "Pass clip planes to the associated graphic driver structure", py::arg("thePlanes"));
cls_Graphic3d_CStructure.def("BoundingBox", (const Graphic3d_BndBox3d & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::BoundingBox, "Returns bounding box of this presentation");
cls_Graphic3d_CStructure.def("ChangeBoundingBox", (Graphic3d_BndBox3d & (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::ChangeBoundingBox, "Returns bounding box of this presentation without transformation matrix applied");
cls_Graphic3d_CStructure.def("IsVisible", (bool (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::IsVisible, "Return structure visibility flag");
cls_Graphic3d_CStructure.def("IsVisible", (bool (Graphic3d_CStructure::*)(const Standard_Integer) const) &Graphic3d_CStructure::IsVisible, "Return structure visibility considering both View Affinity and global visibility state.", py::arg("theViewId"));
cls_Graphic3d_CStructure.def("SetZLayer", (void (Graphic3d_CStructure::*)(const Graphic3d_ZLayerId)) &Graphic3d_CStructure::SetZLayer, "Set z layer ID to display the structure in specified layer", py::arg("theLayerIndex"));
cls_Graphic3d_CStructure.def("ZLayer", (Graphic3d_ZLayerId (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::ZLayer, "Get z layer ID");
cls_Graphic3d_CStructure.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::HighlightStyle, "Returns valid handle to highlight style of the structure in case if highlight flag is set to true");
cls_Graphic3d_CStructure.def("OnVisibilityChanged", (void (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::OnVisibilityChanged, "Update structure visibility state");
cls_Graphic3d_CStructure.def("Clear", (void (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::Clear, "Clear graphic data");
cls_Graphic3d_CStructure.def("Connect", (void (Graphic3d_CStructure::*)(Graphic3d_CStructure &)) &Graphic3d_CStructure::Connect, "Connect other structure to this one", py::arg("theStructure"));
cls_Graphic3d_CStructure.def("Disconnect", (void (Graphic3d_CStructure::*)(Graphic3d_CStructure &)) &Graphic3d_CStructure::Disconnect, "Disconnect other structure to this one", py::arg("theStructure"));
cls_Graphic3d_CStructure.def("GraphicHighlight", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &, const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_CStructure::GraphicHighlight, "Highlights structure with the given style", py::arg("theStyle"), py::arg("theStruct"));
cls_Graphic3d_CStructure.def("GraphicUnhighlight", (void (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::GraphicUnhighlight, "Unhighlights the structure and invalidates pointer to structure's highlight style");
cls_Graphic3d_CStructure.def("ShadowLink", (opencascade::handle<Graphic3d_CStructure> (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_StructureManager> &) const) &Graphic3d_CStructure::ShadowLink, "Create shadow link to this structure", py::arg("theManager"));
cls_Graphic3d_CStructure.def("NewGroup", (opencascade::handle<Graphic3d_Group> (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_CStructure::NewGroup, "Create new group within this structure", py::arg("theStruct"));
cls_Graphic3d_CStructure.def("RemoveGroup", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_Group> &)) &Graphic3d_CStructure::RemoveGroup, "Remove group from this structure", py::arg("theGroup"));
cls_Graphic3d_CStructure.def_static("get_type_name_", (const char * (*)()) &Graphic3d_CStructure::get_type_name, "None");
cls_Graphic3d_CStructure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_CStructure::get_type_descriptor, "None");
cls_Graphic3d_CStructure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_CStructure::*)() const) &Graphic3d_CStructure::DynamicType, "None");

// Enums

}