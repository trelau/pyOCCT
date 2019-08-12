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
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_Structure.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_TypeOfStructure.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_SequenceOfGroup.hxx>
#include <Graphic3d_Group.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_TypeOfConnection.hxx>
#include <Graphic3d_MapOfStructure.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <gp_Trsf.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_BndBox4f.hxx>
#include <Graphic3d_BndBox3d.hxx>
#include <Graphic3d_IndexedMapOfAddress.hxx>

void bind_Graphic3d_Structure(py::module &mod){

py::class_<Graphic3d_Structure, opencascade::handle<Graphic3d_Structure>, Standard_Transient> cls_Graphic3d_Structure(mod, "Graphic3d_Structure", "This class allows the definition a graphic object. This graphic structure can be displayed, erased, or highlighted. This graphic structure can be connected with another graphic structure. Keywords: Structure, StructureManager, Display, Erase, Highlight, UnHighlight, Visible, Priority, Selectable, Visible, Visual, Connection, Ancestors, Descendants, Transformation");

// Constructors
cls_Graphic3d_Structure.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theManager"));
cls_Graphic3d_Structure.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Graphic3d_Structure> &>(), py::arg("theManager"), py::arg("thePrs"));

// Fields

// Methods
cls_Graphic3d_Structure.def("Clear", [](Graphic3d_Structure &self) -> void { return self.Clear(); });
cls_Graphic3d_Structure.def("Clear", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::Clear, "if WithDestruction == Standard_True then suppress all the groups of primitives in the structure. and it is mandatory to create a new group in <me>. if WithDestruction == Standard_False then clears all the groups of primitives in the structure. and all the groups are conserved and empty. They will be erased at the next screen update. The structure itself is conserved. The transformation and the attributes of <me> are conserved. The childs of <me> are conserved.", py::arg("WithDestruction"));
cls_Graphic3d_Structure.def("Display", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Display, "Displays the structure <me> in all the views of the visualiser.");
cls_Graphic3d_Structure.def("DisplayPriority", (Standard_Integer (Graphic3d_Structure::*)() const) &Graphic3d_Structure::DisplayPriority, "Returns the current display priority for the structure <me>.");
cls_Graphic3d_Structure.def("Erase", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Erase, "Erases the structure <me> in all the views of the visualiser.");
cls_Graphic3d_Structure.def("Highlight", [](Graphic3d_Structure &self, const opencascade::handle<Graphic3d_PresentationAttributes> & a0) -> void { return self.Highlight(a0); });
cls_Graphic3d_Structure.def("Highlight", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &, const Standard_Boolean)) &Graphic3d_Structure::Highlight, "Highlights the structure in all the views with the given style", py::arg("theStyle"), py::arg("theToUpdateMgr"));
cls_Graphic3d_Structure.def("Remove", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Remove, "Suppress the structure <me>. It will be erased at the next screen update. Warning: No more graphic operations in <me> after this call. Category: Methods to modify the class definition");
cls_Graphic3d_Structure.def("CalculateBoundBox", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::CalculateBoundBox, "Computes axis-aligned bounding box of a structure.");
cls_Graphic3d_Structure.def("SetInfiniteState", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetInfiniteState, "If <theToSet> is Standard_True then <me> is infinite and the MinMaxValues method method return : theXMin = theYMin = theZMin = RealFirst(). theXMax = theYMax = theZMax = RealLast(). By default, <me> is not infinite but empty.", py::arg("theToSet"));
cls_Graphic3d_Structure.def("SetDisplayPriority", (void (Graphic3d_Structure::*)(const Standard_Integer)) &Graphic3d_Structure::SetDisplayPriority, "Modifies the order of displaying the structure. Values are between 0 and 10. Structures are drawn according to their display priorities in ascending order. A structure of priority 10 is displayed the last and appears over the others. The default value is 5. Category: Methods to modify the class definition Warning: If <me> is displayed then the SetDisplayPriority method erase <me> and display <me> with the new priority. Raises PriorityDefinitionError if <Priority> is greater than 10 or a negative value.", py::arg("Priority"));
cls_Graphic3d_Structure.def("ResetDisplayPriority", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::ResetDisplayPriority, "Reset the current priority of the structure to the previous priority. Category: Methods to modify the class definition Warning: If <me> is displayed then the SetDisplayPriority method erase <me> and display <me> with the previous priority.");
cls_Graphic3d_Structure.def("SetZLayer", (void (Graphic3d_Structure::*)(const Graphic3d_ZLayerId)) &Graphic3d_Structure::SetZLayer, "Set Z layer ID for the structure. The Z layer mechanism allows to display structures presented in higher layers in overlay of structures in lower layers by switching off z buffer depth test between layers", py::arg("theLayerId"));
cls_Graphic3d_Structure.def("GetZLayer", (Graphic3d_ZLayerId (Graphic3d_Structure::*)() const) &Graphic3d_Structure::GetZLayer, "Get Z layer ID of displayed structure. The method returns -1 if the structure has no ID (deleted from graphic driver).");
cls_Graphic3d_Structure.def("SetClipPlanes", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_Structure::SetClipPlanes, "Changes a sequence of clip planes slicing the structure on rendering.", py::arg("thePlanes"));
cls_Graphic3d_Structure.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::ClipPlanes, "Get clip planes slicing the structure on rendering.");
cls_Graphic3d_Structure.def("SetVisible", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetVisible, "Modifies the visibility indicator to Standard_True or Standard_False for the structure <me>. The default value at the definition of <me> is Standard_True.", py::arg("AValue"));
cls_Graphic3d_Structure.def("SetVisual", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfStructure)) &Graphic3d_Structure::SetVisual, "Modifies the visualisation mode for the structure <me>.", py::arg("AVisual"));
cls_Graphic3d_Structure.def("SetZoomLimit", (void (Graphic3d_Structure::*)(const Standard_Real, const Standard_Real)) &Graphic3d_Structure::SetZoomLimit, "Modifies the minimum and maximum zoom coefficients for the structure <me>. The default value at the definition of <me> is unlimited. Category: Methods to modify the class definition Warning: Raises StructureDefinitionError if <LimitInf> is greater than <LimitSup> or if <LimitInf> or <LimitSup> is a negative value.", py::arg("LimitInf"), py::arg("LimitSup"));
cls_Graphic3d_Structure.def("SetIsForHighlight", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetIsForHighlight, "marks the structure <me> representing wired structure needed for highlight only so it won't be added to BVH tree. Category: Methods to modify the class definition", py::arg("isForHighlight"));
cls_Graphic3d_Structure.def("UnHighlight", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::UnHighlight, "Suppresses the highlight for the structure <me> in all the views of the visualiser.");
cls_Graphic3d_Structure.def("Compute", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Compute, "None");
cls_Graphic3d_Structure.def("Compute", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("aProjector"));
cls_Graphic3d_Structure.def("Compute", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"));
cls_Graphic3d_Structure.def("Compute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("aProjector"), py::arg("aStructure"));
cls_Graphic3d_Structure.def("Compute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
cls_Graphic3d_Structure.def("ReCompute", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::ReCompute, "Forces a new construction of the structure <me> if <me> is displayed and TOS_COMPUTED.");
cls_Graphic3d_Structure.def("ReCompute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_Structure::ReCompute, "Forces a new construction of the structure <me> if <me> is displayed in <aProjetor> and TOS_COMPUTED.", py::arg("aProjector"));
cls_Graphic3d_Structure.def("ContainsFacet", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::ContainsFacet, "Returns Standard_True if the structure <me> contains Polygons, Triangles or Quadrangles.");
cls_Graphic3d_Structure.def("Groups", (const Graphic3d_SequenceOfGroup & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Groups, "Returns the groups sequence included in the structure <me> (internal storage).");
cls_Graphic3d_Structure.def("NumberOfGroups", (Standard_Integer (Graphic3d_Structure::*)() const) &Graphic3d_Structure::NumberOfGroups, "Returns the current number of groups in the structure <me>.");
cls_Graphic3d_Structure.def("NewGroup", (opencascade::handle<Graphic3d_Group> (Graphic3d_Structure::*)()) &Graphic3d_Structure::NewGroup, "Append new group to this structure.");
cls_Graphic3d_Structure.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::HighlightStyle, "Returns the highlight color for the Highlight method with the highlight method TOHM_COLOR or TOHM_BOUNDBOX.");
cls_Graphic3d_Structure.def("IsDeleted", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsDeleted, "Returns Standard_True if the structure <me> is deleted. <me> is deleted after the call Remove (me).");
cls_Graphic3d_Structure.def("IsDisplayed", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsDisplayed, "Returns the display indicator for the structure <me>.");
cls_Graphic3d_Structure.def("IsEmpty", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsEmpty, "Returns Standard_True if the structure <me> is empty. Warning: A structure is empty if : it do not have group or all the groups are empties and it do not have descendant or all the descendants are empties.");
cls_Graphic3d_Structure.def("IsInfinite", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsInfinite, "Returns Standard_True if the structure <me> is infinite.");
cls_Graphic3d_Structure.def("IsHighlighted", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsHighlighted, "Returns the highlight indicator for the structure <me>.");
cls_Graphic3d_Structure.def("IsTransformed", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsTransformed, "Returns Standard_True if the structure <me> is transformed. <=> The transformation != Identity.");
cls_Graphic3d_Structure.def("IsVisible", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsVisible, "Returns the visibility indicator for the structure <me>.");
cls_Graphic3d_Structure.def("MinMaxValues", [](Graphic3d_Structure &self) -> Bnd_Box { return self.MinMaxValues(); });
cls_Graphic3d_Structure.def("MinMaxValues", (Bnd_Box (Graphic3d_Structure::*)(const Standard_Boolean) const) &Graphic3d_Structure::MinMaxValues, "Returns the coordinates of the boundary box of the structure <me>. If <theToIgnoreInfiniteFlag> is TRUE, the method returns actual graphical boundaries of the Graphic3d_Group components. Otherwise, the method returns boundaries taking into account infinite state of the structure. This approach generally used for application specific fit operation (e.g. fitting the model into screen, not taking into accout infinite helper elements). Warning: If the structure <me> is empty then the empty box is returned, If the structure <me> is infinite then the whole box is returned.", py::arg("theToIgnoreInfiniteFlag"));
cls_Graphic3d_Structure.def("Visual", (Graphic3d_TypeOfStructure (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Visual, "Returns the visualisation mode for the structure <me>.");
cls_Graphic3d_Structure.def_static("AcceptConnection_", (Standard_Boolean (*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::AcceptConnection, "Returns Standard_True if the connection is possible between <AStructure1> and <AStructure2> without a creation of a cycle.", py::arg("AStructure1"), py::arg("AStructure2"), py::arg("AType"));
cls_Graphic3d_Structure.def("Ancestors", (void (Graphic3d_Structure::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_Structure::Ancestors, "Returns the group of structures to which <me> is connected.", py::arg("SG"));
cls_Graphic3d_Structure.def("Connect", [](Graphic3d_Structure &self, const opencascade::handle<Graphic3d_Structure> & a0, const Graphic3d_TypeOfConnection a1) -> void { return self.Connect(a0, a1); });
cls_Graphic3d_Structure.def("Connect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection, const Standard_Boolean)) &Graphic3d_Structure::Connect, "If Atype is TOC_DESCENDANT then add <AStructure> as a child structure of <me>. If Atype is TOC_ANCESTOR then add <AStructure> as a parent structure of <me>. The connection propagates Display, Highlight, Erase, Remove, and stacks the transformations. No connection if the graph of the structures contains a cycle and <WithCheck> is Standard_True;", py::arg("AStructure"), py::arg("AType"), py::arg("WithCheck"));
cls_Graphic3d_Structure.def("Descendants", (void (Graphic3d_Structure::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_Structure::Descendants, "Returns the group of structures connected to <me>.", py::arg("SG"));
cls_Graphic3d_Structure.def("Disconnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Disconnect, "Suppress the connection between <AStructure> and <me>.", py::arg("AStructure"));
cls_Graphic3d_Structure.def("DisconnectAll", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::DisconnectAll, "If Atype is TOC_DESCENDANT then suppress all the connections with the child structures of <me>. If Atype is TOC_ANCESTOR then suppress all the connections with the parent structures of <me>.", py::arg("AType"));
cls_Graphic3d_Structure.def_static("Network_", (void (*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection, Graphic3d_MapOfStructure &)) &Graphic3d_Structure::Network, "Returns <ASet> the group of structures : - directly or indirectly connected to <AStructure> if the TypeOfConnection == TOC_DESCENDANT - to which <AStructure> is directly or indirectly connected if the TypeOfConnection == TOC_ANCESTOR", py::arg("AStructure"), py::arg("AType"), py::arg("ASet"));
cls_Graphic3d_Structure.def("SetOwner", (void (Graphic3d_Structure::*)(const Standard_Address)) &Graphic3d_Structure::SetOwner, "None", py::arg("Owner"));
cls_Graphic3d_Structure.def("Owner", (Standard_Address (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Owner, "None");
cls_Graphic3d_Structure.def("SetHLRValidation", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetHLRValidation, "None", py::arg("AFlag"));
cls_Graphic3d_Structure.def("HLRValidation", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::HLRValidation, "None");
cls_Graphic3d_Structure.def("Transformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Transformation, "Return local transformation.");
cls_Graphic3d_Structure.def("SetTransformation", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::SetTransformation, "Modifies the current local transformation", py::arg("theTrsf"));
cls_Graphic3d_Structure.def("Transform", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::Transform, "None", py::arg("theTrsf"));
cls_Graphic3d_Structure.def("SetTransformPersistence", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &Graphic3d_Structure::SetTransformPersistence, "Modifies the current transform persistence (pan, zoom or rotate)", py::arg("theTrsfPers"));
cls_Graphic3d_Structure.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::TransformPersistence, "Returns transform persistence of the presentable object.");
cls_Graphic3d_Structure.def("SetMutable", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetMutable, "Sets if the structure location has mutable nature (content or location will be changed regularly).", py::arg("theIsMutable"));
cls_Graphic3d_Structure.def("IsMutable", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsMutable, "Returns true if structure has mutable nature (content or location are be changed regularly). Mutable structure will be managed in different way than static onces.");
cls_Graphic3d_Structure.def("ComputeVisual", (Graphic3d_TypeOfStructure (Graphic3d_Structure::*)() const) &Graphic3d_Structure::ComputeVisual, "None");
cls_Graphic3d_Structure.def("GraphicClear", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::GraphicClear, "Clears the structure <me>.", py::arg("WithDestruction"));
cls_Graphic3d_Structure.def("GraphicConnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::GraphicConnect, "None", py::arg("ADaughter"));
cls_Graphic3d_Structure.def("GraphicDisconnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::GraphicDisconnect, "None", py::arg("ADaughter"));
cls_Graphic3d_Structure.def("GraphicTransform", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::GraphicTransform, "Internal method which sets new transformation without calling graphic manager callbacks.", py::arg("theTrsf"));
cls_Graphic3d_Structure.def("Identification", (Standard_Integer (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Identification, "Returns the identification number of the structure <me>.");
cls_Graphic3d_Structure.def_static("PrintNetwork_", (void (*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::PrintNetwork, "Prints informations about the network associated with the structure <AStructure>.", py::arg("AStructure"), py::arg("AType"));
cls_Graphic3d_Structure.def("Remove", (void (Graphic3d_Structure::*)(const Standard_Address, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::Remove, "Suppress the adress <APtr> in the list of descendants or in the list of ancestors.", py::arg("APtr"), py::arg("AType"));
cls_Graphic3d_Structure.def("SetComputeVisual", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfStructure)) &Graphic3d_Structure::SetComputeVisual, "None", py::arg("AVisual"));
cls_Graphic3d_Structure.def_static("Transforms_", [](const gp_Trsf & theTrsf, const Standard_Real theX, const Standard_Real theY, const Standard_Real theZ, Standard_Real & theNewX, Standard_Real & theNewY, Standard_Real & theNewZ){ Graphic3d_Structure::Transforms(theTrsf, theX, theY, theZ, theNewX, theNewY, theNewZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theNewX, theNewY, theNewZ); }, "Transforms theX, theY, theZ with the transformation theTrsf.", py::arg("theTrsf"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNewX"), py::arg("theNewY"), py::arg("theNewZ"));
cls_Graphic3d_Structure.def("CStructure", (const opencascade::handle<Graphic3d_CStructure> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::CStructure, "Returns the low-level structure");
cls_Graphic3d_Structure.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Structure::get_type_name, "None");
cls_Graphic3d_Structure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Structure::get_type_descriptor, "None");
cls_Graphic3d_Structure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::DynamicType, "None");

// Enums

}