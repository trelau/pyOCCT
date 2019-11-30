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
#include <PrsMgr_Presentation.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <NCollection_List.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <PrsMgr_ListOfPresentations.hxx>
#include <Graphic3d_Structure.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <V3d_Viewer.hxx>
#include <Prs3d_Drawer.hxx>
#include <Geom_Transformation.hxx>
#include <PrsMgr_ListOfPresentableObjects.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Prs3d_Projector.hxx>
#include <NCollection_Sequence.hxx>
#include <PrsMgr_Presentations.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_MapOfAspectsToAspects.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <gp_Pnt.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <PrsMgr_Presentation3d.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(PrsMgr, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.V3d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TColStd");

// ENUM: PRSMGR_TYPEOFPRESENTATION3D
py::enum_<PrsMgr_TypeOfPresentation3d>(mod, "PrsMgr_TypeOfPresentation3d", "To declare the type of presentation as follows - AllView for display involving no recalculation for new projectors (points of view)in hidden line removal mode - ProjectorDependant for display in hidden line removal mode, where every new point of view entails recalculation of the display.")
	.value("PrsMgr_TOP_AllView", PrsMgr_TypeOfPresentation3d::PrsMgr_TOP_AllView)
	.value("PrsMgr_TOP_ProjectorDependant", PrsMgr_TypeOfPresentation3d::PrsMgr_TOP_ProjectorDependant)
	.export_values();


// TYPEDEF: PRSMGR_LISTOFPRESENTATIONS
bind_NCollection_List<opencascade::handle<Graphic3d_Structure> >(mod, "PrsMgr_ListOfPresentations", py::module_local(false));

// TYPEDEF: PRS3D_PRESENTATION
py::class_<Graphic3d_Structure, opencascade::handle<Graphic3d_Structure>, Standard_Transient> cls_Prs3d_Presentation(mod, "Prs3d_Presentation", "This class allows the definition a graphic object. This graphic structure can be displayed, erased, or highlighted. This graphic structure can be connected with another graphic structure.", py::module_local());

// Constructors
cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theManager"));
cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Graphic3d_Structure> &>(), py::arg("theManager"), py::arg("theLinkPrs"));

// Methods
cls_Prs3d_Presentation.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Structure::get_type_name, "None");
cls_Prs3d_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Structure::get_type_descriptor, "None");
cls_Prs3d_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::DynamicType, "None");
cls_Prs3d_Presentation.def("Clear", [](Graphic3d_Structure &self) -> void { return self.Clear(); });
cls_Prs3d_Presentation.def("Clear", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::Clear, "if WithDestruction == Standard_True then suppress all the groups of primitives in the structure. and it is mandatory to create a new group in <me>. if WithDestruction == Standard_False then clears all the groups of primitives in the structure. and all the groups are conserved and empty. They will be erased at the next screen update. The structure itself is conserved. The transformation and the attributes of <me> are conserved. The childs of <me> are conserved.", py::arg("WithDestruction"));
cls_Prs3d_Presentation.def("Display", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Display, "Displays the structure <me> in all the views of the visualiser.");
cls_Prs3d_Presentation.def("DisplayPriority", (Standard_Integer (Graphic3d_Structure::*)() const) &Graphic3d_Structure::DisplayPriority, "Returns the current display priority for this structure.");
cls_Prs3d_Presentation.def("Erase", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Erase, "Erases the structure <me> in all the views of the visualiser.");
cls_Prs3d_Presentation.def("Highlight", [](Graphic3d_Structure &self, const opencascade::handle<Graphic3d_PresentationAttributes> & a0) -> void { return self.Highlight(a0); });
cls_Prs3d_Presentation.def("Highlight", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &, const Standard_Boolean)) &Graphic3d_Structure::Highlight, "Highlights the structure in all the views with the given style", py::arg("theStyle"), py::arg("theToUpdateMgr"));
cls_Prs3d_Presentation.def("Remove", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Remove, "Suppress the structure <me>. It will be erased at the next screen update. Warning: No more graphic operations in <me> after this call. Category: Methods to modify the class definition");
cls_Prs3d_Presentation.def("CalculateBoundBox", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::CalculateBoundBox, "Computes axis-aligned bounding box of a structure.");
cls_Prs3d_Presentation.def("SetInfiniteState", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetInfiniteState, "Sets infinite flag. When TRUE, the MinMaxValues method returns: theXMin = theYMin = theZMin = RealFirst(). theXMax = theYMax = theZMax = RealLast(). By default, structure is created not infinite but empty.", py::arg("theToSet"));
cls_Prs3d_Presentation.def("SetDisplayPriority", (void (Graphic3d_Structure::*)(const Standard_Integer)) &Graphic3d_Structure::SetDisplayPriority, "Modifies the order of displaying the structure. Values are between 0 and 10. Structures are drawn according to their display priorities in ascending order. A structure of priority 10 is displayed the last and appears over the others. The default value is 5. Category: Methods to modify the class definition Warning: If <me> is displayed then the SetDisplayPriority method erase <me> and display <me> with the new priority. Raises PriorityDefinitionError if <Priority> is greater than 10 or a negative value.", py::arg("Priority"));
cls_Prs3d_Presentation.def("ResetDisplayPriority", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::ResetDisplayPriority, "Reset the current priority of the structure to the previous priority. Category: Methods to modify the class definition Warning: If <me> is displayed then the SetDisplayPriority method erase <me> and display <me> with the previous priority.");
cls_Prs3d_Presentation.def("SetZLayer", (void (Graphic3d_Structure::*)(const Graphic3d_ZLayerId)) &Graphic3d_Structure::SetZLayer, "Set Z layer ID for the structure. The Z layer mechanism allows to display structures presented in higher layers in overlay of structures in lower layers by switching off z buffer depth test between layers", py::arg("theLayerId"));
cls_Prs3d_Presentation.def("GetZLayer", (Graphic3d_ZLayerId (Graphic3d_Structure::*)() const) &Graphic3d_Structure::GetZLayer, "Get Z layer ID of displayed structure. The method returns -1 if the structure has no ID (deleted from graphic driver).");
cls_Prs3d_Presentation.def("SetClipPlanes", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_Structure::SetClipPlanes, "Changes a sequence of clip planes slicing the structure on rendering.", py::arg("thePlanes"));
cls_Prs3d_Presentation.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::ClipPlanes, "Get clip planes slicing the structure on rendering.");
cls_Prs3d_Presentation.def("SetVisible", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetVisible, "Modifies the visibility indicator to Standard_True or Standard_False for the structure <me>. The default value at the definition of <me> is Standard_True.", py::arg("AValue"));
cls_Prs3d_Presentation.def("SetVisual", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfStructure)) &Graphic3d_Structure::SetVisual, "Modifies the visualisation mode for the structure <me>.", py::arg("AVisual"));
cls_Prs3d_Presentation.def("SetZoomLimit", (void (Graphic3d_Structure::*)(const Standard_Real, const Standard_Real)) &Graphic3d_Structure::SetZoomLimit, "Modifies the minimum and maximum zoom coefficients for the structure <me>. The default value at the definition of <me> is unlimited. Category: Methods to modify the class definition Warning: Raises StructureDefinitionError if <LimitInf> is greater than <LimitSup> or if <LimitInf> or <LimitSup> is a negative value.", py::arg("LimitInf"), py::arg("LimitSup"));
cls_Prs3d_Presentation.def("SetIsForHighlight", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetIsForHighlight, "Marks the structure <me> representing wired structure needed for highlight only so it won't be added to BVH tree.", py::arg("isForHighlight"));
cls_Prs3d_Presentation.def("UnHighlight", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::UnHighlight, "Suppresses the highlight for the structure <me> in all the views of the visualiser.");
cls_Prs3d_Presentation.def("Compute", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Compute, "None");
cls_Prs3d_Presentation.def("Compute", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"));
cls_Prs3d_Presentation.def("Compute", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"));
cls_Prs3d_Presentation.def("Compute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theStructure"));
cls_Prs3d_Presentation.def("Compute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
cls_Prs3d_Presentation.def("ReCompute", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::ReCompute, "Forces a new construction of the structure <me> if <me> is displayed and TOS_COMPUTED.");
cls_Prs3d_Presentation.def("ReCompute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_Structure::ReCompute, "Forces a new construction of the structure <me> if <me> is displayed in <aProjetor> and TOS_COMPUTED.", py::arg("aProjector"));
cls_Prs3d_Presentation.def("ContainsFacet", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::ContainsFacet, "Returns Standard_True if the structure <me> contains Polygons, Triangles or Quadrangles.");
cls_Prs3d_Presentation.def("Groups", (const Graphic3d_SequenceOfGroup & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Groups, "Returns the groups sequence included in this structure.");
cls_Prs3d_Presentation.def("NumberOfGroups", (Standard_Integer (Graphic3d_Structure::*)() const) &Graphic3d_Structure::NumberOfGroups, "Returns the current number of groups in this structure.");
cls_Prs3d_Presentation.def("NewGroup", (opencascade::handle<Graphic3d_Group> (Graphic3d_Structure::*)()) &Graphic3d_Structure::NewGroup, "Append new group to this structure.");
cls_Prs3d_Presentation.def("CurrentGroup", (opencascade::handle<Graphic3d_Group> (Graphic3d_Structure::*)()) &Graphic3d_Structure::CurrentGroup, "Returns the last created group or creates new one if list is empty.");
cls_Prs3d_Presentation.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::HighlightStyle, "Returns the highlight attributes.");
cls_Prs3d_Presentation.def("IsDeleted", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsDeleted, "Returns TRUE if this structure is deleted (after Remove() call).");
cls_Prs3d_Presentation.def("IsDisplayed", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsDisplayed, "Returns the display indicator for this structure.");
cls_Prs3d_Presentation.def("IsEmpty", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsEmpty, "Returns Standard_True if the structure <me> is empty. Warning: A structure is empty if : it do not have group or all the groups are empties and it do not have descendant or all the descendants are empties.");
cls_Prs3d_Presentation.def("IsInfinite", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsInfinite, "Returns Standard_True if the structure <me> is infinite.");
cls_Prs3d_Presentation.def("IsHighlighted", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsHighlighted, "Returns the highlight indicator for this structure.");
cls_Prs3d_Presentation.def("IsTransformed", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsTransformed, "Returns TRUE if the structure is transformed.");
cls_Prs3d_Presentation.def("IsVisible", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsVisible, "Returns the visibility indicator for this structure.");
cls_Prs3d_Presentation.def("MinMaxValues", [](Graphic3d_Structure &self) -> Bnd_Box { return self.MinMaxValues(); });
cls_Prs3d_Presentation.def("MinMaxValues", (Bnd_Box (Graphic3d_Structure::*)(const Standard_Boolean) const) &Graphic3d_Structure::MinMaxValues, "Returns the coordinates of the boundary box of the structure <me>. If <theToIgnoreInfiniteFlag> is TRUE, the method returns actual graphical boundaries of the Graphic3d_Group components. Otherwise, the method returns boundaries taking into account infinite state of the structure. This approach generally used for application specific fit operation (e.g. fitting the model into screen, not taking into accout infinite helper elements). Warning: If the structure <me> is empty then the empty box is returned, If the structure <me> is infinite then the whole box is returned.", py::arg("theToIgnoreInfiniteFlag"));
cls_Prs3d_Presentation.def("Visual", (Graphic3d_TypeOfStructure (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Visual, "Returns the visualisation mode for the structure <me>.");
cls_Prs3d_Presentation.def_static("AcceptConnection_", (Standard_Boolean (*)(Graphic3d_Structure *, Graphic3d_Structure *, Graphic3d_TypeOfConnection)) &Graphic3d_Structure::AcceptConnection, "Returns Standard_True if the connection is possible between <AStructure1> and <AStructure2> without a creation of a cycle.", py::arg("theStructure1"), py::arg("theStructure2"), py::arg("theType"));
cls_Prs3d_Presentation.def("Ancestors", (void (Graphic3d_Structure::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_Structure::Ancestors, "Returns the group of structures to which <me> is connected.", py::arg("SG"));
cls_Prs3d_Presentation.def("Connect", [](Graphic3d_Structure &self, Graphic3d_Structure * a0, Graphic3d_TypeOfConnection a1) -> void { return self.Connect(a0, a1); });
cls_Prs3d_Presentation.def("Connect", (void (Graphic3d_Structure::*)(Graphic3d_Structure *, Graphic3d_TypeOfConnection, Standard_Boolean)) &Graphic3d_Structure::Connect, "If Atype is TOC_DESCENDANT then add <AStructure> as a child structure of <me>. If Atype is TOC_ANCESTOR then add <AStructure> as a parent structure of <me>. The connection propagates Display, Highlight, Erase, Remove, and stacks the transformations. No connection if the graph of the structures contains a cycle and <WithCheck> is Standard_True;", py::arg("theStructure"), py::arg("theType"), py::arg("theWithCheck"));
cls_Prs3d_Presentation.def("Connect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Connect, "None", py::arg("thePrs"));
cls_Prs3d_Presentation.def("Descendants", (void (Graphic3d_Structure::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_Structure::Descendants, "Returns the group of structures connected to <me>.", py::arg("SG"));
cls_Prs3d_Presentation.def("Disconnect", (void (Graphic3d_Structure::*)(Graphic3d_Structure *)) &Graphic3d_Structure::Disconnect, "Suppress the connection between <AStructure> and <me>.", py::arg("theStructure"));
cls_Prs3d_Presentation.def("Remove", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Remove, "None", py::arg("thePrs"));
cls_Prs3d_Presentation.def("DisconnectAll", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::DisconnectAll, "If Atype is TOC_DESCENDANT then suppress all the connections with the child structures of <me>. If Atype is TOC_ANCESTOR then suppress all the connections with the parent structures of <me>.", py::arg("AType"));
cls_Prs3d_Presentation.def("RemoveAll", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::RemoveAll, "None");
cls_Prs3d_Presentation.def_static("Network_", (void (*)(Graphic3d_Structure *, const Graphic3d_TypeOfConnection, NCollection_Map<Graphic3d_Structure *> &)) &Graphic3d_Structure::Network, "Returns <ASet> the group of structures : - directly or indirectly connected to <AStructure> if the TypeOfConnection == TOC_DESCENDANT - to which <AStructure> is directly or indirectly connected if the TypeOfConnection == TOC_ANCESTOR", py::arg("theStructure"), py::arg("theType"), py::arg("theSet"));
cls_Prs3d_Presentation.def("SetOwner", (void (Graphic3d_Structure::*)(const Standard_Address)) &Graphic3d_Structure::SetOwner, "None", py::arg("theOwner"));
cls_Prs3d_Presentation.def("Owner", (Standard_Address (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Owner, "None");
cls_Prs3d_Presentation.def("SetHLRValidation", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetHLRValidation, "None", py::arg("theFlag"));
cls_Prs3d_Presentation.def("HLRValidation", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::HLRValidation, "Hidden parts stored in this structure are valid if: 1) the owner is defined. 2) they are not invalid.");
cls_Prs3d_Presentation.def("Transformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Transformation, "Return local transformation.");
cls_Prs3d_Presentation.def("SetTransformation", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::SetTransformation, "Modifies the current local transformation", py::arg("theTrsf"));
cls_Prs3d_Presentation.def("Transform", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::Transform, "None", py::arg("theTrsf"));
cls_Prs3d_Presentation.def("SetTransformPersistence", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &Graphic3d_Structure::SetTransformPersistence, "Modifies the current transform persistence (pan, zoom or rotate)", py::arg("theTrsfPers"));
cls_Prs3d_Presentation.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::TransformPersistence, "Returns transform persistence of the presentable object.");
cls_Prs3d_Presentation.def("SetMutable", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetMutable, "Sets if the structure location has mutable nature (content or location will be changed regularly).", py::arg("theIsMutable"));
cls_Prs3d_Presentation.def("IsMutable", (Standard_Boolean (Graphic3d_Structure::*)() const) &Graphic3d_Structure::IsMutable, "Returns true if structure has mutable nature (content or location are be changed regularly). Mutable structure will be managed in different way than static onces.");
cls_Prs3d_Presentation.def("ComputeVisual", (Graphic3d_TypeOfStructure (Graphic3d_Structure::*)() const) &Graphic3d_Structure::ComputeVisual, "None");
cls_Prs3d_Presentation.def("GraphicClear", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::GraphicClear, "Clears the structure <me>.", py::arg("WithDestruction"));
cls_Prs3d_Presentation.def("GraphicConnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::GraphicConnect, "None", py::arg("theDaughter"));
cls_Prs3d_Presentation.def("GraphicDisconnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::GraphicDisconnect, "None", py::arg("theDaughter"));
cls_Prs3d_Presentation.def("GraphicTransform", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::GraphicTransform, "Internal method which sets new transformation without calling graphic manager callbacks.", py::arg("theTrsf"));
cls_Prs3d_Presentation.def("Identification", (Standard_Integer (Graphic3d_Structure::*)() const) &Graphic3d_Structure::Identification, "Returns the identification number of this structure.");
cls_Prs3d_Presentation.def_static("PrintNetwork_", (void (*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::PrintNetwork, "Prints informations about the network associated with the structure <AStructure>.", py::arg("AStructure"), py::arg("AType"));
cls_Prs3d_Presentation.def("Remove", (void (Graphic3d_Structure::*)(Graphic3d_Structure *, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::Remove, "Suppress the structure in the list of descendants or in the list of ancestors.", py::arg("thePtr"), py::arg("theType"));
cls_Prs3d_Presentation.def("SetComputeVisual", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfStructure)) &Graphic3d_Structure::SetComputeVisual, "None", py::arg("theVisual"));
cls_Prs3d_Presentation.def_static("Transforms_", [](const gp_Trsf & theTrsf, const Standard_Real theX, const Standard_Real theY, const Standard_Real theZ, Standard_Real & theNewX, Standard_Real & theNewY, Standard_Real & theNewZ){ Graphic3d_Structure::Transforms(theTrsf, theX, theY, theZ, theNewX, theNewY, theNewZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theNewX, theNewY, theNewZ); }, "Transforms theX, theY, theZ with the transformation theTrsf.", py::arg("theTrsf"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNewX"), py::arg("theNewY"), py::arg("theNewZ"));
cls_Prs3d_Presentation.def("CStructure", (const opencascade::handle<Graphic3d_CStructure> & (Graphic3d_Structure::*)() const) &Graphic3d_Structure::CStructure, "Returns the low-level structure");

// CLASS: PRSMGR_PRESENTATIONMANAGER
py::class_<PrsMgr_PresentationManager, opencascade::handle<PrsMgr_PresentationManager>, Standard_Transient> cls_PrsMgr_PresentationManager(mod, "PrsMgr_PresentationManager", "A framework to manage 3D displays, graphic entities and their updates. Used in the AIS package (Application Interactive Services), to enable the advanced user to define the default display mode of a new interactive object which extends the list of signatures and types. Definition of new display types is handled by calling the presentation algorithms provided by the StdPrs package.");

// Constructors
cls_PrsMgr_PresentationManager.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theStructureManager"));

// Methods
cls_PrsMgr_PresentationManager.def_static("get_type_name_", (const char * (*)()) &PrsMgr_PresentationManager::get_type_name, "None");
cls_PrsMgr_PresentationManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_PresentationManager::get_type_descriptor, "None");
cls_PrsMgr_PresentationManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_PresentationManager::*)() const) &PrsMgr_PresentationManager::DynamicType, "None");
cls_PrsMgr_PresentationManager.def("Display", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Display(a0); });
cls_PrsMgr_PresentationManager.def("Display", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Display, "Displays the presentation of the object in the given Presentation manager with the given mode. The mode should be enumerated by the object which inherits PresentableObject.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Erase", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Erase(a0); });
cls_PrsMgr_PresentationManager.def("Erase", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Erase, "erases the presentation of the object in the given Presentation manager with the given mode. If is -1, then erases all presentations of the object.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Clear", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Clear(a0); });
cls_PrsMgr_PresentationManager.def("Clear", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Clear, "Clears the presentation of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("SetVisibility", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Boolean)) &PrsMgr_PresentationManager::SetVisibility, "Sets the visibility of presentable object.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theValue"));
cls_PrsMgr_PresentationManager.def("Unhighlight", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentationManager::Unhighlight, "Removes highlighting from the presentation of the presentable object.", py::arg("thePrsObject"));
cls_PrsMgr_PresentationManager.def("Unhighlight", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Unhighlight, "None", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("SetDisplayPriority", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Integer) const) &PrsMgr_PresentationManager::SetDisplayPriority, "Sets the display priority theNewPrior of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theNewPrior"));
cls_PrsMgr_PresentationManager.def("DisplayPriority", (Standard_Integer (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::DisplayPriority, "Returns the display priority of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("SetZLayer", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Graphic3d_ZLayerId)) &PrsMgr_PresentationManager::SetZLayer, "Set Z layer ID for all presentations of the object.", py::arg("thePrsObject"), py::arg("theLayerId"));
cls_PrsMgr_PresentationManager.def("GetZLayer", (Graphic3d_ZLayerId (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &) const) &PrsMgr_PresentationManager::GetZLayer, "Get Z layer ID assigned to all presentations of the object. Method returns -1 value if object has no presentations and is impossible to get layer index.", py::arg("thePrsObject"));
cls_PrsMgr_PresentationManager.def("IsDisplayed", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.IsDisplayed(a0); });
cls_PrsMgr_PresentationManager.def("IsDisplayed", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::IsDisplayed, "None", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("IsHighlighted", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.IsHighlighted(a0); });
cls_PrsMgr_PresentationManager.def("IsHighlighted", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::IsHighlighted, "Returns true if the presentation of the presentable object thePrsObject in this framework with the display mode theMode is highlighted.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Update", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Update(a0); });
cls_PrsMgr_PresentationManager.def("Update", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::Update, "Updates the presentation of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("BeginImmediateDraw", (void (PrsMgr_PresentationManager::*)()) &PrsMgr_PresentationManager::BeginImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode and begins accumulation of new list by following AddToImmediateList()/Color()/Highlight() calls.");
cls_PrsMgr_PresentationManager.def("ClearImmediateDraw", (void (PrsMgr_PresentationManager::*)()) &PrsMgr_PresentationManager::ClearImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode.");
cls_PrsMgr_PresentationManager.def("AddToImmediateList", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<Prs3d_Presentation> &)) &PrsMgr_PresentationManager::AddToImmediateList, "Stores thePrs in the transient list of presentations to be displayed in immediate mode. Will be taken in account in EndImmediateDraw method.", py::arg("thePrs"));
cls_PrsMgr_PresentationManager.def("EndImmediateDraw", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &)) &PrsMgr_PresentationManager::EndImmediateDraw, "Allows rapid drawing of the each view in theViewer by avoiding an update of the whole background.", py::arg("theViewer"));
cls_PrsMgr_PresentationManager.def("RedrawImmediate", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &)) &PrsMgr_PresentationManager::RedrawImmediate, "Clears and redisplays immediate structures of the viewer taking into account its affinity.", py::arg("theViewer"));
cls_PrsMgr_PresentationManager.def("IsImmediateModeOn", (Standard_Boolean (PrsMgr_PresentationManager::*)() const) &PrsMgr_PresentationManager::IsImmediateModeOn, "Returns true if Presentation Manager is accumulating transient list of presentations to be displayed in immediate mode.");
cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.Color(a0, a1); });
cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const Standard_Integer a2) -> void { return self.Color(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const Standard_Integer a2, const opencascade::handle<PrsMgr_PresentableObject> & a3) -> void { return self.Color(a0, a1, a2, a3); });
cls_PrsMgr_PresentationManager.def("Color", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer, const opencascade::handle<PrsMgr_PresentableObject> &, const Graphic3d_ZLayerId)) &PrsMgr_PresentationManager::Color, "Highlights the graphic object thePrsObject in the color theColor. thePrsObject has the display mode theMode; this has the default value of 0, that is, the wireframe display mode.", py::arg("thePrsObject"), py::arg("theStyle"), py::arg("theMode"), py::arg("theSelObj"), py::arg("theImmediateStructLayerId"));
cls_PrsMgr_PresentationManager.def("Connect", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1) -> void { return self.Connect(a0, a1); });
cls_PrsMgr_PresentationManager.def("Connect", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1, const Standard_Integer a2) -> void { return self.Connect(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("Connect", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Integer)) &PrsMgr_PresentationManager::Connect, "None", py::arg("thePrsObject"), py::arg("theOtherObject"), py::arg("theMode"), py::arg("theOtherMode"));
cls_PrsMgr_PresentationManager.def("Transform", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Geom_Transformation> & a1) -> void { return self.Transform(a0, a1); });
cls_PrsMgr_PresentationManager.def("Transform", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<Geom_Transformation> &, const Standard_Integer)) &PrsMgr_PresentationManager::Transform, "Sets the transformation theTransformation for the presentable object thePrsObject. thePrsObject has the display mode theMode; this has the default value of 0, that is, the wireframe display mode.", py::arg("thePrsObject"), py::arg("theTransformation"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("StructureManager", (const opencascade::handle<Graphic3d_StructureManager> & (PrsMgr_PresentationManager::*)() const) &PrsMgr_PresentationManager::StructureManager, "Returns the structure manager.");
cls_PrsMgr_PresentationManager.def("HasPresentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.HasPresentation(a0); });
cls_PrsMgr_PresentationManager.def("HasPresentation", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::HasPresentation, "Returns true if there is a presentation of the presentable object thePrsObject in this framework, thePrsObject having the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0); });
cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const Standard_Integer a1) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0, a1); });
cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("Presentation", (opencascade::handle<PrsMgr_Presentation> (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Boolean, const opencascade::handle<PrsMgr_PresentableObject> &) const) &PrsMgr_PresentationManager::Presentation, "Returns the presentation Presentation of the presentable object thePrsObject in this framework. When theToCreate is true - automatically creates presentation for specified mode when not exist. Optional argument theSelObj specifies parent decomposed object to inherit its view affinity.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theToCreate"), py::arg("theSelObj"));
cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", [](PrsMgr_PresentationManager &self, const opencascade::handle<V3d_Viewer> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1) -> void { return self.UpdateHighlightTrsf(a0, a1); });
cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", [](PrsMgr_PresentationManager &self, const opencascade::handle<V3d_Viewer> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1, const Standard_Integer a2) -> void { return self.UpdateHighlightTrsf(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentationManager::UpdateHighlightTrsf, "Allows to apply location transformation to shadow highlight presentation immediately.", py::arg("theViewer"), py::arg("theObj"), py::arg("theMode"), py::arg("theSelObj"));

// TYPEDEF: PRSMGR_LISTOFPRESENTABLEOBJECTS
bind_NCollection_List<opencascade::handle<PrsMgr_PresentableObject> >(mod, "PrsMgr_ListOfPresentableObjects", py::module_local(false));

// TYPEDEF: PRSMGR_LISTOFPRESENTABLEOBJECTSITER
bind_NCollection_TListIterator<opencascade::handle<PrsMgr_PresentableObject> >(mod, "PrsMgr_ListOfPresentableObjectsIter", py::module_local(false));

// CLASS: PRSMGR_PRESENTATION
py::class_<PrsMgr_Presentation, opencascade::handle<PrsMgr_Presentation>, Graphic3d_Structure> cls_PrsMgr_Presentation(mod, "PrsMgr_Presentation", "None");

// Methods
cls_PrsMgr_Presentation.def_static("get_type_name_", (const char * (*)()) &PrsMgr_Presentation::get_type_name, "None");
cls_PrsMgr_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_Presentation::get_type_descriptor, "None");
cls_PrsMgr_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::DynamicType, "None");
cls_PrsMgr_Presentation.def("Presentation", (Prs3d_Presentation * (PrsMgr_Presentation::*)()) &PrsMgr_Presentation::Presentation, "None");
cls_PrsMgr_Presentation.def("PresentationManager", (const opencascade::handle<PrsMgr_PresentationManager> & (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::PresentationManager, "returns the PresentationManager in which the presentation has been created.");
cls_PrsMgr_Presentation.def("SetUpdateStatus", (void (PrsMgr_Presentation::*)(const Standard_Boolean)) &PrsMgr_Presentation::SetUpdateStatus, "None", py::arg("theUpdateStatus"));
cls_PrsMgr_Presentation.def("MustBeUpdated", (Standard_Boolean (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::MustBeUpdated, "None");
cls_PrsMgr_Presentation.def("Mode", (Standard_Integer (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::Mode, "Return display mode index.");
cls_PrsMgr_Presentation.def("Display", (void (PrsMgr_Presentation::*)()) &PrsMgr_Presentation::Display, "Display structure.");
cls_PrsMgr_Presentation.def("Erase", (void (PrsMgr_Presentation::*)()) &PrsMgr_Presentation::Erase, "Remove structure.");
cls_PrsMgr_Presentation.def("Highlight", (void (PrsMgr_Presentation::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_Presentation::Highlight, "Highlight structure.", py::arg("theStyle"));
cls_PrsMgr_Presentation.def("Unhighlight", (void (PrsMgr_Presentation::*)()) &PrsMgr_Presentation::Unhighlight, "Unhighlight structure.");
cls_PrsMgr_Presentation.def("IsDisplayed", (Standard_Boolean (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::IsDisplayed, "Return TRUE if structure has been displayed and in no hidden state.");
cls_PrsMgr_Presentation.def("Clear", [](PrsMgr_Presentation &self) -> void { return self.Clear(); });
cls_PrsMgr_Presentation.def("Clear", (void (PrsMgr_Presentation::*)(const Standard_Boolean)) &PrsMgr_Presentation::Clear, "removes the whole content of the presentation. Does not remove the other connected presentations.", py::arg("theWithDestruction"));
cls_PrsMgr_Presentation.def("Compute", (void (PrsMgr_Presentation::*)()) &PrsMgr_Presentation::Compute, "Compute structure using presentation manager.");

// TYPEDEF: PRSMGR_PRESENTATIONS
bind_NCollection_Sequence<opencascade::handle<PrsMgr_Presentation> >(mod, "PrsMgr_Presentations", py::module_local(false));

// TYPEDEF: PRSMGR_PRESENTATIONMANAGER3D
if (py::hasattr(mod, "PrsMgr_PresentationManager")) {
	mod.attr("PrsMgr_PresentationManager3d") = mod.attr("PrsMgr_PresentationManager");
}

// CLASS: PRSMGR_PRESENTABLEOBJECT
py::class_<PrsMgr_PresentableObject, opencascade::handle<PrsMgr_PresentableObject>, Standard_Transient> cls_PrsMgr_PresentableObject(mod, "PrsMgr_PresentableObject", "A framework to supply the Graphic3d structure of the object to be presented. On the first display request, this structure is created by calling the appropriate algorithm and retaining this framework for further display. This abstract framework is inherited in Application Interactive Services (AIS), notably by AIS_InteractiveObject. Consequently, 3D presentation should be handled by the relevant daughter classes and their member functions in AIS. This is particularly true in the creation of new interactive objects.");

// Methods
cls_PrsMgr_PresentableObject.def_static("get_type_name_", (const char * (*)()) &PrsMgr_PresentableObject::get_type_name, "None");
cls_PrsMgr_PresentableObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_PresentableObject::get_type_descriptor, "None");
cls_PrsMgr_PresentableObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::DynamicType, "None");
cls_PrsMgr_PresentableObject.def("Presentations", (PrsMgr_Presentations & (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::Presentations, "Return presentations.");
cls_PrsMgr_PresentableObject.def("ZLayer", (Graphic3d_ZLayerId (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::ZLayer, "Get ID of Z layer for main presentation.");
cls_PrsMgr_PresentableObject.def("SetZLayer", (void (PrsMgr_PresentableObject::*)(const Graphic3d_ZLayerId)) &PrsMgr_PresentableObject::SetZLayer, "Set Z layer ID and update all presentations of the presentable object. The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.", py::arg("theLayerId"));
cls_PrsMgr_PresentableObject.def("IsMutable", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::IsMutable, "Returns true if object has mutable nature (content or location are be changed regularly). Mutable object will be managed in different way than static onces (another optimizations).");
cls_PrsMgr_PresentableObject.def("SetMutable", (void (PrsMgr_PresentableObject::*)(const Standard_Boolean)) &PrsMgr_PresentableObject::SetMutable, "Sets if the object has mutable nature (content or location will be changed regularly). This method should be called before object displaying to take effect.", py::arg("theIsMutable"));
cls_PrsMgr_PresentableObject.def("HasDisplayMode", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasDisplayMode, "Returns true if the Interactive Object has display mode setting overriding global setting (within Interactive Context).");
cls_PrsMgr_PresentableObject.def("DisplayMode", (Standard_Integer (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::DisplayMode, "Returns the display mode setting of the Interactive Object. The range of supported display mode indexes should be specified within object definition and filtered by AccepDisplayMode().");
cls_PrsMgr_PresentableObject.def("SetDisplayMode", (void (PrsMgr_PresentableObject::*)(const Standard_Integer)) &PrsMgr_PresentableObject::SetDisplayMode, "Sets the display mode for the interactive object. An object can have its own temporary display mode, which is different from that proposed by the interactive context.", py::arg("theMode"));
cls_PrsMgr_PresentableObject.def("UnsetDisplayMode", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetDisplayMode, "Removes display mode settings from the interactive object.");
cls_PrsMgr_PresentableObject.def("HasHilightMode", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasHilightMode, "Returns true if the Interactive Object is in highlight mode.");
cls_PrsMgr_PresentableObject.def("HilightMode", (Standard_Integer (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HilightMode, "Returns highlight display mode. This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.");
cls_PrsMgr_PresentableObject.def("SetHilightMode", (void (PrsMgr_PresentableObject::*)(const Standard_Integer)) &PrsMgr_PresentableObject::SetHilightMode, "Sets highlight display mode. This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.", py::arg("theMode"));
cls_PrsMgr_PresentableObject.def("UnsetHilightMode", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetHilightMode, "Unsets highlight display mode.");
cls_PrsMgr_PresentableObject.def("AcceptDisplayMode", (Standard_Boolean (PrsMgr_PresentableObject::*)(const Standard_Integer) const) &PrsMgr_PresentableObject::AcceptDisplayMode, "Returns true if the class of objects accepts specified display mode index. The interactive context can have a default mode of representation for the set of Interactive Objects. This mode may not be accepted by a given class of objects. Consequently, this virtual method allowing us to get information about the class in question must be implemented. At least one display mode index should be accepted by this method. Although subclass can leave default implementation, it is highly desired defining exact list of supported modes instead, which is usually an enumeration for one object or objects class sharing similar list of display modes.", py::arg("theMode"));
cls_PrsMgr_PresentableObject.def("DefaultDisplayMode", (Standard_Integer (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::DefaultDisplayMode, "Returns the default display mode.");
cls_PrsMgr_PresentableObject.def("ToBeUpdated", [](PrsMgr_PresentableObject &self) -> Standard_Boolean { return self.ToBeUpdated(); });
cls_PrsMgr_PresentableObject.def("ToBeUpdated", (Standard_Boolean (PrsMgr_PresentableObject::*)(Standard_Boolean) const) &PrsMgr_PresentableObject::ToBeUpdated, "Returns TRUE if any active presentation has invalidation flag.", py::arg("theToIncludeHidden"));
cls_PrsMgr_PresentableObject.def("SetToUpdate", (void (PrsMgr_PresentableObject::*)(Standard_Integer)) &PrsMgr_PresentableObject::SetToUpdate, "Flags presentation to be updated; UpdatePresentations() will recompute these presentations.", py::arg("theMode"));
cls_PrsMgr_PresentableObject.def("SetToUpdate", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::SetToUpdate, "flags all the Presentations to be Updated.");
cls_PrsMgr_PresentableObject.def("IsInfinite", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::IsInfinite, "Returns true if the interactive object is infinite; FALSE by default. This flag affects various operations operating on bounding box of graphic presentations of this object. For instance, infinite objects are not taken in account for View FitAll. This does not necessarily means that object is actually infinite, auxiliary objects might be also marked with this flag to achieve desired behavior.");
cls_PrsMgr_PresentableObject.def("SetInfiniteState", [](PrsMgr_PresentableObject &self) -> void { return self.SetInfiniteState(); });
cls_PrsMgr_PresentableObject.def("SetInfiniteState", (void (PrsMgr_PresentableObject::*)(const Standard_Boolean)) &PrsMgr_PresentableObject::SetInfiniteState, "Sets if object should be considered as infinite.", py::arg("theFlag"));
cls_PrsMgr_PresentableObject.def("TypeOfPresentation3d", (PrsMgr_TypeOfPresentation3d (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::TypeOfPresentation3d, "Returns information on whether the object accepts display in HLR mode or not.");
cls_PrsMgr_PresentableObject.def("SetTypeOfPresentation", (void (PrsMgr_PresentableObject::*)(const PrsMgr_TypeOfPresentation3d)) &PrsMgr_PresentableObject::SetTypeOfPresentation, "Set type of presentation.", py::arg("theType"));
cls_PrsMgr_PresentableObject.def("Attributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Attributes, "Returns the attributes settings.");
cls_PrsMgr_PresentableObject.def("SetAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetAttributes, "Initializes the drawing tool theDrawer.", py::arg("theDrawer"));
cls_PrsMgr_PresentableObject.def("HilightAttributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HilightAttributes, "Returns the hilight attributes settings. When not NULL, overrides both Prs3d_TypeOfHighlight_LocalSelected and Prs3d_TypeOfHighlight_Selected defined within AIS_InteractiveContext.");
cls_PrsMgr_PresentableObject.def("SetHilightAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetHilightAttributes, "Initializes the hilight drawing tool theDrawer.", py::arg("theDrawer"));
cls_PrsMgr_PresentableObject.def("DynamicHilightAttributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::DynamicHilightAttributes, "Returns the hilight attributes settings. When not NULL, overrides both Prs3d_TypeOfHighlight_LocalDynamic and Prs3d_TypeOfHighlight_Dynamic defined within AIS_InteractiveContext.");
cls_PrsMgr_PresentableObject.def("SetDynamicHilightAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetDynamicHilightAttributes, "Initializes the dynamic hilight drawing tool.", py::arg("theDrawer"));
cls_PrsMgr_PresentableObject.def("UnsetHilightAttributes", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetHilightAttributes, "Clears settings provided by the hilight drawing tool theDrawer.");
cls_PrsMgr_PresentableObject.def("SynchronizeAspects", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::SynchronizeAspects, "Synchronize presentation aspects after their modification.");
cls_PrsMgr_PresentableObject.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::TransformPersistence, "Returns Transformation Persistence defining a special Local Coordinate system where this presentable object is located or NULL handle if not defined. Position of the object having Transformation Persistence is mutable and depends on camera position. The same applies to a bounding box of the object.");
cls_PrsMgr_PresentableObject.def("SetTransformPersistence", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &PrsMgr_PresentableObject::SetTransformPersistence, "Sets up Transform Persistence defining a special Local Coordinate system where this object should be located. Note that management of Transform Persistence object is more expensive than of the normal one, because it requires its position being recomputed basing on camera position within each draw call / traverse.", py::arg("theTrsfPers"));
cls_PrsMgr_PresentableObject.def("LocalTransformationGeom", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::LocalTransformationGeom, "Return the local transformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("SetLocalTransformation", (void (PrsMgr_PresentableObject::*)(const gp_Trsf &)) &PrsMgr_PresentableObject::SetLocalTransformation, "Sets local transformation to theTransformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.", py::arg("theTrsf"));
cls_PrsMgr_PresentableObject.def("SetLocalTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Geom_Transformation> &)) &PrsMgr_PresentableObject::SetLocalTransformation, "Sets local transformation to theTransformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.", py::arg("theTrsf"));
cls_PrsMgr_PresentableObject.def("HasTransformation", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasTransformation, "Returns true if object has a transformation that is different from the identity.");
cls_PrsMgr_PresentableObject.def("TransformationGeom", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::TransformationGeom, "Return the transformation taking into account transformation of parent object(s). Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("LocalTransformation", (const gp_Trsf & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::LocalTransformation, "Return the local transformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("Transformation", (const gp_Trsf & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Transformation, "Return the transformation taking into account transformation of parent object(s). Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("InversedTransformation", (const gp_GTrsf & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::InversedTransformation, "Return inversed transformation.");
cls_PrsMgr_PresentableObject.def("CombinedParentTransformation", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::CombinedParentTransformation, "Return combined parent transformation.");
cls_PrsMgr_PresentableObject.def("ResetTransformation", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::ResetTransformation, "resets local transformation to identity.");
cls_PrsMgr_PresentableObject.def("UpdateTransformation", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UpdateTransformation, "Updates final transformation (parent + local) of presentable object and its presentations.");
cls_PrsMgr_PresentableObject.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::ClipPlanes, "Get clip planes.");
cls_PrsMgr_PresentableObject.def("SetClipPlanes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &PrsMgr_PresentableObject::SetClipPlanes, "Set clip planes for graphical clipping for all display mode presentations. The composition of clip planes truncates the rendering space to convex volume. Please be aware that number of supported clip plane is limited. The planes which exceed the limit are ignored. Besides of this, some planes can be already set in view where the object is shown: the number of these planes should be subtracted from limit to predict the maximum possible number of object clipping planes.", py::arg("thePlanes"));
cls_PrsMgr_PresentableObject.def("AddClipPlane", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &PrsMgr_PresentableObject::AddClipPlane, "Adds clip plane for graphical clipping for all display mode presentations. The composition of clip planes truncates the rendering space to convex volume. Please be aware that number of supported clip plane is limited. The planes which exceed the limit are ignored. Besides of this, some planes can be already set in view where the object is shown: the number of these planes should be subtracted from limit to predict the maximum possible number of object clipping planes.", py::arg("thePlane"));
cls_PrsMgr_PresentableObject.def("RemoveClipPlane", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &PrsMgr_PresentableObject::RemoveClipPlane, "Removes previously added clip plane.", py::arg("thePlane"));
cls_PrsMgr_PresentableObject.def("Parent", (PrsMgr_PresentableObject * (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Parent, "Returns parent of current object in scene hierarchy.");
cls_PrsMgr_PresentableObject.def("Children", (const PrsMgr_ListOfPresentableObjects & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Children, "Returns children of the current object.");
cls_PrsMgr_PresentableObject.def("AddChild", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::AddChild, "Makes theObject child of current object in scene hierarchy.", py::arg("theObject"));
cls_PrsMgr_PresentableObject.def("AddChildWithCurrentTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::AddChildWithCurrentTransformation, "Makes theObject child of current object in scene hierarchy with keeping the current global transformation So the object keeps the same position/orientation in the global CS.", py::arg("theObject"));
cls_PrsMgr_PresentableObject.def("RemoveChild", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::RemoveChild, "Removes theObject from children of current object in scene hierarchy.", py::arg("theObject"));
cls_PrsMgr_PresentableObject.def("RemoveChildWithRestoreTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::RemoveChildWithRestoreTransformation, "Removes theObject from children of current object in scene hierarchy with keeping the current global transformation. So the object keeps the same position/orientation in the global CS.", py::arg("theObject"));
cls_PrsMgr_PresentableObject.def("HasOwnPresentations", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasOwnPresentations, "Returns true if object should have own presentations.");
cls_PrsMgr_PresentableObject.def("BoundingBox", (void (PrsMgr_PresentableObject::*)(Bnd_Box &)) &PrsMgr_PresentableObject::BoundingBox, "Returns bounding box of object correspondingly to its current display mode. This method requires presentation to be already computed, since it relies on bounding box of presentation structures, which are supposed to be same/close amongst different display modes of this object.", py::arg("theBndBox"));
cls_PrsMgr_PresentableObject.def("SetIsoOnTriangulation", (void (PrsMgr_PresentableObject::*)(const Standard_Boolean)) &PrsMgr_PresentableObject::SetIsoOnTriangulation, "Enables or disables on-triangulation build of isolines according to the flag given.", py::arg("theIsEnabled"));
cls_PrsMgr_PresentableObject.def("CurrentFacingModel", (Aspect_TypeOfFacingModel (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::CurrentFacingModel, "Returns the current facing model which is in effect.");
cls_PrsMgr_PresentableObject.def("SetCurrentFacingModel", [](PrsMgr_PresentableObject &self) -> void { return self.SetCurrentFacingModel(); });
cls_PrsMgr_PresentableObject.def("SetCurrentFacingModel", (void (PrsMgr_PresentableObject::*)(const Aspect_TypeOfFacingModel)) &PrsMgr_PresentableObject::SetCurrentFacingModel, "change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE. This mean that attributes is applying both on the front and back face.", py::arg("theModel"));
cls_PrsMgr_PresentableObject.def("HasColor", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasColor, "Returns true if the Interactive Object has color.");
cls_PrsMgr_PresentableObject.def("Color", (void (PrsMgr_PresentableObject::*)(Quantity_Color &) const) &PrsMgr_PresentableObject::Color, "Returns the color setting of the Interactive Object.", py::arg("theColor"));
cls_PrsMgr_PresentableObject.def("SetColor", (void (PrsMgr_PresentableObject::*)(const Quantity_Color &)) &PrsMgr_PresentableObject::SetColor, "Only the interactive object knowns which Drawer attribute is affected by the color, if any (ex: for a wire,it's the wireaspect field of the drawer, but for a vertex, only the point aspect field is affected by the color). WARNING : Do not forget to set the corresponding fields here (hasOwnColor and myDrawer->SetColor())", py::arg("theColor"));
cls_PrsMgr_PresentableObject.def("UnsetColor", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetColor, "Removes color settings. Only the Interactive Object knows which Drawer attribute is affected by the color setting. For a wire, for example, wire aspect is the attribute affected. For a vertex, however, only point aspect is affected by the color setting.");
cls_PrsMgr_PresentableObject.def("HasWidth", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasWidth, "Returns true if the Interactive Object has width.");
cls_PrsMgr_PresentableObject.def("Width", (Standard_Real (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Width, "Returns the width setting of the Interactive Object.");
cls_PrsMgr_PresentableObject.def("SetWidth", (void (PrsMgr_PresentableObject::*)(const Standard_Real)) &PrsMgr_PresentableObject::SetWidth, "Allows you to provide the setting aValue for width. Only the Interactive Object knows which Drawer attribute is affected by the width setting.", py::arg("theWidth"));
cls_PrsMgr_PresentableObject.def("UnsetWidth", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetWidth, "Reset width to default value.");
cls_PrsMgr_PresentableObject.def("HasMaterial", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasMaterial, "Returns true if the Interactive Object has a setting for material.");
cls_PrsMgr_PresentableObject.def("Material", (Graphic3d_NameOfMaterial (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Material, "Returns the current material setting as enumeration value.");
cls_PrsMgr_PresentableObject.def("SetMaterial", (void (PrsMgr_PresentableObject::*)(const Graphic3d_MaterialAspect &)) &PrsMgr_PresentableObject::SetMaterial, "Sets the material aMat defining this display attribute for the interactive object. Material aspect determines shading aspect, color and transparency of visible entities.", py::arg("aName"));
cls_PrsMgr_PresentableObject.def("UnsetMaterial", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetMaterial, "Removes the setting for material.");
cls_PrsMgr_PresentableObject.def("IsTransparent", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::IsTransparent, "Returns true if there is a transparency setting.");
cls_PrsMgr_PresentableObject.def("Transparency", (Standard_Real (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Transparency, "Returns the transparency setting. This will be between 0.0 and 1.0. At 0.0 an object will be totally opaque, and at 1.0, fully transparent.");
cls_PrsMgr_PresentableObject.def("SetTransparency", [](PrsMgr_PresentableObject &self) -> void { return self.SetTransparency(); });
cls_PrsMgr_PresentableObject.def("SetTransparency", (void (PrsMgr_PresentableObject::*)(const Standard_Real)) &PrsMgr_PresentableObject::SetTransparency, "Attributes a setting aValue for transparency. The transparency value should be between 0.0 and 1.0. At 0.0 an object will be totally opaque, and at 1.0, fully transparent. Warning At a value of 1.0, there may be nothing visible.", py::arg("aValue"));
cls_PrsMgr_PresentableObject.def("UnsetTransparency", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetTransparency, "Removes the transparency setting. The object is opaque by default.");
cls_PrsMgr_PresentableObject.def("HasPolygonOffsets", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasPolygonOffsets, "Returns Standard_True if <myDrawer> has non-null shading aspect");
cls_PrsMgr_PresentableObject.def("PolygonOffsets", [](PrsMgr_PresentableObject &self, Standard_Integer & aMode, Standard_ShortReal & aFactor, Standard_ShortReal & aUnits){ self.PolygonOffsets(aMode, aFactor, aUnits); return aMode; }, "Retrieves current polygon offsets settings from <myDrawer>.", py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
cls_PrsMgr_PresentableObject.def("SetPolygonOffsets", [](PrsMgr_PresentableObject &self, const Standard_Integer a0) -> void { return self.SetPolygonOffsets(a0); });
cls_PrsMgr_PresentableObject.def("SetPolygonOffsets", [](PrsMgr_PresentableObject &self, const Standard_Integer a0, const Standard_ShortReal a1) -> void { return self.SetPolygonOffsets(a0, a1); });
cls_PrsMgr_PresentableObject.def("SetPolygonOffsets", (void (PrsMgr_PresentableObject::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal)) &PrsMgr_PresentableObject::SetPolygonOffsets, "Sets up polygon offsets for this object.", py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
cls_PrsMgr_PresentableObject.def("UnsetAttributes", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetAttributes, "Clears settings provided by the drawing tool aDrawer.");
cls_PrsMgr_PresentableObject.def("DumpJson", [](PrsMgr_PresentableObject &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_PrsMgr_PresentableObject.def("DumpJson", (void (PrsMgr_PresentableObject::*)(Standard_OStream &, const Standard_Integer) const) &PrsMgr_PresentableObject::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
cls_PrsMgr_PresentableObject.def("ToBeUpdated", (void (PrsMgr_PresentableObject::*)(TColStd_ListOfInteger &) const) &PrsMgr_PresentableObject::ToBeUpdated, "gives the list of modes which are flagged 'to be updated'.", py::arg("ListOfMode"));
cls_PrsMgr_PresentableObject.def("SetClipPlanes", (void (PrsMgr_PresentableObject::*)(const Graphic3d_SequenceOfHClipPlane &)) &PrsMgr_PresentableObject::SetClipPlanes, "None", py::arg("thePlanes"));
cls_PrsMgr_PresentableObject.def("SetTransformPersistence", [](PrsMgr_PresentableObject &self, const Graphic3d_TransModeFlags a0) -> void { return self.SetTransformPersistence(a0); });
cls_PrsMgr_PresentableObject.def("SetTransformPersistence", (void (PrsMgr_PresentableObject::*)(const Graphic3d_TransModeFlags, const gp_Pnt &)) &PrsMgr_PresentableObject::SetTransformPersistence, "Sets up Transform Persistence Mode for this object. This function used to lock in object position, rotation and / or zooming relative to camera position. Object will be drawn in the origin setted by thePoint parameter (except Graphic3d_TMF_TriedronPers flag - see description later). theMode should be: - Graphic3d_TMF_None - no persistence attributes (reset); - Graphic3d_TMF_ZoomPers - object doesn't resize; - Graphic3d_TMF_RotatePers - object doesn't rotate; - Graphic3d_TMF_ZoomRotatePers - object doesn't resize and rotate; - Graphic3d_TMF_RotatePers - object doesn't rotate; - Graphic3d_TMF_TriedronPers - object behaves like trihedron. If Graphic3d_TMF_TriedronPers or Graphic3d_TMF_2d persistence mode selected thePoint coordinates X and Y means: - X = 0.0, Y = 0.0 - center of view window; - X > 0.0, Y > 0.0 - right upper corner of view window; - X > 0.0, Y < 0.0 - right lower corner of view window; - X < 0.0, Y > 0.0 - left upper corner of view window; - X < 0.0, Y < 0.0 - left lower corner of view window. And Z coordinate defines the gap from border of view window (except center position).", py::arg("theMode"), py::arg("thePoint"));
cls_PrsMgr_PresentableObject.def("GetTransformPersistenceMode", (Graphic3d_TransModeFlags (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::GetTransformPersistenceMode, "Gets Transform Persistence Mode for this object");
cls_PrsMgr_PresentableObject.def("GetTransformPersistencePoint", (gp_Pnt (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::GetTransformPersistencePoint, "Gets point of transform persistence for this object");
cls_PrsMgr_PresentableObject.def("ToPropagateVisualState", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::ToPropagateVisualState, "Get value of the flag 'propagate visual state' It means that the display/erase/color visual state is propagated automatically to all children; by default, the flag is true");
cls_PrsMgr_PresentableObject.def("SetPropagateVisualState", (void (PrsMgr_PresentableObject::*)(const Standard_Boolean)) &PrsMgr_PresentableObject::SetPropagateVisualState, "Change the value of the flag 'propagate visual state'", py::arg("theFlag"));

// TYPEDEF: PRSMGR_PRESENTATIONMANAGER3D
if (py::hasattr(mod, "PrsMgr_PresentationManager")) {
	mod.attr("PrsMgr_PresentationManager3d") = mod.attr("PrsMgr_PresentationManager");
}

// TYPEDEF: PRSMGR_PRESENTATION3D
if (py::hasattr(mod, "PrsMgr_Presentation")) {
	mod.attr("PrsMgr_Presentation3d") = mod.attr("PrsMgr_Presentation");
}


}
