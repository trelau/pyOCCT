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
#include <Graphic3d_Structure.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_MapOfStructure.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_CView.hxx>
#include <Graphic3d_ViewAffinity.hxx>
#include <Aspect_GenId.hxx>
#include <Graphic3d_MapOfObject.hxx>

void bind_Graphic3d_StructureManager(py::module &mod){

py::class_<Graphic3d_StructureManager, opencascade::handle<Graphic3d_StructureManager>, Standard_Transient> cls_Graphic3d_StructureManager(mod, "Graphic3d_StructureManager", "This class allows the definition of a manager to which the graphic objects are associated. It allows them to be globally manipulated. It defines the global attributes. Keywords: Structure, Structure Manager, Update Mode, Destroy, Highlight, Visible");

// Constructors
cls_Graphic3d_StructureManager.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &>(), py::arg("theDriver"));

// Fields

// Methods
cls_Graphic3d_StructureManager.def_static("get_type_name_", (const char * (*)()) &Graphic3d_StructureManager::get_type_name, "None");
cls_Graphic3d_StructureManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_StructureManager::get_type_descriptor, "None");
cls_Graphic3d_StructureManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_StructureManager::*)() const) &Graphic3d_StructureManager::DynamicType, "None");
cls_Graphic3d_StructureManager.def("Update", [](Graphic3d_StructureManager &self) -> void { return self.Update(); });
cls_Graphic3d_StructureManager.def("Update", (void (Graphic3d_StructureManager::*)(const Graphic3d_ZLayerId) const) &Graphic3d_StructureManager::Update, "Invalidates bounding box of specified ZLayerId.", py::arg("theLayerId"));
cls_Graphic3d_StructureManager.def("Remove", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::Remove, "Deletes and erases the 3D structure manager.");
cls_Graphic3d_StructureManager.def("Erase", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::Erase, "Erases all the structures.");
cls_Graphic3d_StructureManager.def("DisplayedStructures", (void (Graphic3d_StructureManager::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_StructureManager::DisplayedStructures, "Returns the set of structures displayed in visualiser <me>.", py::arg("SG"));
cls_Graphic3d_StructureManager.def("HighlightedStructures", (void (Graphic3d_StructureManager::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_StructureManager::HighlightedStructures, "Returns the set of highlighted structures in a visualiser <me>.", py::arg("SG"));
cls_Graphic3d_StructureManager.def("ReCompute", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::ReCompute, "Forces a new construction of the structure. if <theStructure> is displayed and TOS_COMPUTED.", py::arg("theStructure"));
cls_Graphic3d_StructureManager.def("ReCompute", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_StructureManager::ReCompute, "Forces a new construction of the structure. if <theStructure> is displayed in <theProjector> and TOS_COMPUTED.", py::arg("theStructure"), py::arg("theProjector"));
cls_Graphic3d_StructureManager.def("Clear", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const Standard_Boolean)) &Graphic3d_StructureManager::Clear, "Clears the structure.", py::arg("theStructure"), py::arg("theWithDestruction"));
cls_Graphic3d_StructureManager.def("Connect", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Connect, "Connects the structures.", py::arg("theMother"), py::arg("theDaughter"));
cls_Graphic3d_StructureManager.def("Disconnect", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Disconnect, "Disconnects the structures.", py::arg("theMother"), py::arg("theDaughter"));
cls_Graphic3d_StructureManager.def("Display", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Display, "Display the structure.", py::arg("theStructure"));
cls_Graphic3d_StructureManager.def("Erase", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Erase, "Erases the structure.", py::arg("theStructure"));
cls_Graphic3d_StructureManager.def("Highlight", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Highlight, "Highlights the structure.", py::arg("theStructure"));
cls_Graphic3d_StructureManager.def("SetTransform", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Geom_Transformation> &)) &Graphic3d_StructureManager::SetTransform, "Transforms the structure.", py::arg("theStructure"), py::arg("theTrsf"));
cls_Graphic3d_StructureManager.def("ChangeDisplayPriority", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const Standard_Integer, const Standard_Integer)) &Graphic3d_StructureManager::ChangeDisplayPriority, "Changes the display priority of the structure <AStructure>.", py::arg("theStructure"), py::arg("theOldPriority"), py::arg("theNewPriority"));
cls_Graphic3d_StructureManager.def("ChangeZLayer", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_ZLayerId)) &Graphic3d_StructureManager::ChangeZLayer, "Change Z layer for structure. The Z layer mechanism allows to display structures in higher layers in overlay of structures in lower layers.", py::arg("theStructure"), py::arg("theLayerId"));
cls_Graphic3d_StructureManager.def("GraphicDriver", (const opencascade::handle<Graphic3d_GraphicDriver> & (Graphic3d_StructureManager::*)() const) &Graphic3d_StructureManager::GraphicDriver, "Returns the graphic driver of <me>.");
cls_Graphic3d_StructureManager.def("Identification", (Standard_Integer (Graphic3d_StructureManager::*)(Graphic3d_CView *)) &Graphic3d_StructureManager::Identification, "Attaches the view to this structure manager and sets its identification number within the manager.", py::arg("theView"));
cls_Graphic3d_StructureManager.def("UnIdentification", (void (Graphic3d_StructureManager::*)(Graphic3d_CView *)) &Graphic3d_StructureManager::UnIdentification, "Detach the view from this structure manager and release its identification.", py::arg("theView"));
cls_Graphic3d_StructureManager.def("DefinedViews", (const Graphic3d_IndexedMapOfView & (Graphic3d_StructureManager::*)() const) &Graphic3d_StructureManager::DefinedViews, "Returns the group of views defined in the structure manager.");
cls_Graphic3d_StructureManager.def("MaxNumOfViews", (Standard_Integer (Graphic3d_StructureManager::*)() const) &Graphic3d_StructureManager::MaxNumOfViews, "Returns the theoretical maximum number of definable views in the manager. Warning: It's not possible to accept an infinite number of definable views because each view must have an identification and we have different managers.");
cls_Graphic3d_StructureManager.def("Identification", (opencascade::handle<Graphic3d_Structure> (Graphic3d_StructureManager::*)(const Standard_Integer) const) &Graphic3d_StructureManager::Identification, "Returns the structure with the identification number <AId>.", py::arg("AId"));
cls_Graphic3d_StructureManager.def("UnHighlight", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::UnHighlight, "Suppress the highlighting on the structure <AStructure>.", py::arg("AStructure"));
cls_Graphic3d_StructureManager.def("UnHighlight", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::UnHighlight, "Suppresses the highlighting on all the structures in <me>.");
cls_Graphic3d_StructureManager.def("RecomputeStructures", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::RecomputeStructures, "Recomputes all structures in the manager. Resets Device Lost flag.");
cls_Graphic3d_StructureManager.def("RecomputeStructures", (void (Graphic3d_StructureManager::*)(const Graphic3d_MapOfStructure &)) &Graphic3d_StructureManager::RecomputeStructures, "Recomputes all structures from theStructures.", py::arg("theStructures"));
cls_Graphic3d_StructureManager.def("RegisterObject", (opencascade::handle<Graphic3d_ViewAffinity> (Graphic3d_StructureManager::*)(const opencascade::handle<Standard_Transient> &)) &Graphic3d_StructureManager::RegisterObject, "None", py::arg("theObject"));
cls_Graphic3d_StructureManager.def("UnregisterObject", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Standard_Transient> &)) &Graphic3d_StructureManager::UnregisterObject, "None", py::arg("theObject"));
cls_Graphic3d_StructureManager.def("ObjectAffinity", (opencascade::handle<Graphic3d_ViewAffinity> (Graphic3d_StructureManager::*)(const opencascade::handle<Standard_Transient> &) const) &Graphic3d_StructureManager::ObjectAffinity, "None", py::arg("theObject"));
cls_Graphic3d_StructureManager.def("IsDeviceLost", (Standard_Boolean (Graphic3d_StructureManager::*)() const) &Graphic3d_StructureManager::IsDeviceLost, "Returns TRUE if Device Lost flag has been set and presentation data should be reuploaded onto graphics driver.");
cls_Graphic3d_StructureManager.def("SetDeviceLost", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::SetDeviceLost, "Sets Device Lost flag.");

// Enums

}