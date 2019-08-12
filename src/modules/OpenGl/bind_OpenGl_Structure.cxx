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
#include <Graphic3d_CStructure.hxx>
#include <OpenGl_Group.hxx>
#include <Graphic3d_SequenceOfGroup.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_Group.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Structure.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Graphic3d_Mat4.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_Structure(py::module &mod){

/*
py::class_<OpenGl_Structure, opencascade::handle<OpenGl_Structure>, Graphic3d_CStructure> cls_OpenGl_Structure(mod, "OpenGl_Structure", "Implementation of low-level graphic structure.");

// Constructors
cls_OpenGl_Structure.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theManager"));

// Fields

// Methods
cls_OpenGl_Structure.def("OnVisibilityChanged", (void (OpenGl_Structure::*)()) &OpenGl_Structure::OnVisibilityChanged, "Setup structure graphic state");
cls_OpenGl_Structure.def("Clear", (void (OpenGl_Structure::*)()) &OpenGl_Structure::Clear, "Clear graphic data");
cls_OpenGl_Structure.def("Connect", (void (OpenGl_Structure::*)(Graphic3d_CStructure &)) &OpenGl_Structure::Connect, "Connect other structure to this one", py::arg("theStructure"));
cls_OpenGl_Structure.def("Disconnect", (void (OpenGl_Structure::*)(Graphic3d_CStructure &)) &OpenGl_Structure::Disconnect, "Disconnect other structure to this one", py::arg("theStructure"));
cls_OpenGl_Structure.def("SetTransformation", (void (OpenGl_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &OpenGl_Structure::SetTransformation, "Synchronize structure transformation", py::arg("theTrsf"));
cls_OpenGl_Structure.def("SetTransformPersistence", (void (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &OpenGl_Structure::SetTransformPersistence, "Set transformation persistence.", py::arg("theTrsfPers"));
cls_OpenGl_Structure.def("SetZLayer", (void (OpenGl_Structure::*)(const Graphic3d_ZLayerId)) &OpenGl_Structure::SetZLayer, "Set z layer ID to display the structure in specified layer", py::arg("theLayerIndex"));
cls_OpenGl_Structure.def("GraphicHighlight", (void (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &, const opencascade::handle<Graphic3d_Structure> &)) &OpenGl_Structure::GraphicHighlight, "Highlights structure according to the given style and updates corresponding class fields (highlight status and style)", py::arg("theStyle"), py::arg("theStruct"));
cls_OpenGl_Structure.def("GraphicUnhighlight", (void (OpenGl_Structure::*)()) &OpenGl_Structure::GraphicUnhighlight, "Unighlights structure and updates corresponding class fields (highlight status and style)");
cls_OpenGl_Structure.def("ShadowLink", (opencascade::handle<Graphic3d_CStructure> (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_StructureManager> &) const) &OpenGl_Structure::ShadowLink, "Create shadow link to this structure", py::arg("theManager"));
cls_OpenGl_Structure.def("NewGroup", (opencascade::handle<Graphic3d_Group> (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &OpenGl_Structure::NewGroup, "Create new group within this structure", py::arg("theStruct"));
cls_OpenGl_Structure.def("RemoveGroup", (void (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_Group> &)) &OpenGl_Structure::RemoveGroup, "Remove group from this structure", py::arg("theGroup"));
cls_OpenGl_Structure.def("GlDriver", (OpenGl_GraphicDriver * (OpenGl_Structure::*)() const) &OpenGl_Structure::GlDriver, "Access graphic driver");
cls_OpenGl_Structure.def("Clear", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Structure::Clear, "None", py::arg("theGlCtx"));
cls_OpenGl_Structure.def("Render", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Structure::Render, "Renders the structure.", py::arg("theWorkspace"));
cls_OpenGl_Structure.def("Release", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Structure::Release, "Releases structure resources.", py::arg("theGlCtx"));
cls_OpenGl_Structure.def("SetCulled", (void (OpenGl_Structure::*)(Standard_Boolean) const) &OpenGl_Structure::SetCulled, "Marks structure as culled/not culled - note that IsAlwaysRendered() is ignored here!", py::arg("theIsCulled"));
cls_OpenGl_Structure.def("MarkAsNotCulled", (void (OpenGl_Structure::*)() const) &OpenGl_Structure::MarkAsNotCulled, "Marks structure as overlapping the current view volume one. The method is called during traverse of BVH tree.");
cls_OpenGl_Structure.def("IsCulled", (Standard_Boolean (OpenGl_Structure::*)() const) &OpenGl_Structure::IsCulled, "Returns Standard_False if the structure hits the current view volume, otherwise returns Standard_True. The default value for all structures before each traverse of BVH tree is Standard_True.");
cls_OpenGl_Structure.def("IsAlwaysRendered", (Standard_Boolean (OpenGl_Structure::*)() const) &OpenGl_Structure::IsAlwaysRendered, "Checks if the structure should be included into BVH tree or not.");
cls_OpenGl_Structure.def("ReleaseGlResources", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Structure::ReleaseGlResources, "This method releases GL resources without actual elements destruction. As result structure could be correctly destroyed layer without GL context (after last window was closed for example).", py::arg("theGlCtx"));
cls_OpenGl_Structure.def("InstancedStructure", (const OpenGl_Structure * (OpenGl_Structure::*)() const) &OpenGl_Structure::InstancedStructure, "Returns instanced OpenGL structure.");
cls_OpenGl_Structure.def("ModificationState", (Standard_Size (OpenGl_Structure::*)() const) &OpenGl_Structure::ModificationState, "Returns structure modification state (for ray-tracing).");
cls_OpenGl_Structure.def("ResetModificationState", (void (OpenGl_Structure::*)() const) &OpenGl_Structure::ResetModificationState, "Resets structure modification state (for ray-tracing).");
cls_OpenGl_Structure.def("IsRaytracable", (Standard_Boolean (OpenGl_Structure::*)() const) &OpenGl_Structure::IsRaytracable, "Is the structure ray-tracable (contains ray-tracable elements)?");
cls_OpenGl_Structure.def("updateLayerTransformation", (void (OpenGl_Structure::*)()) &OpenGl_Structure::updateLayerTransformation, "Update render transformation matrix.");
cls_OpenGl_Structure.def_static("get_type_name_", (const char * (*)()) &OpenGl_Structure::get_type_name, "None");
cls_OpenGl_Structure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Structure::get_type_descriptor, "None");
cls_OpenGl_Structure.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Structure::*)() const) &OpenGl_Structure::DynamicType, "None");

// Enums
*/

}