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
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <OpenGl_Structure.hxx>
#include <OpenGl_Layer.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_LayerFilter.hxx>
#include <OpenGl_FrameBuffer.hxx>
#include <OpenGl_LayerList.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <OpenGl_RenderFilter.hxx>
#include <OpenGl_Element.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Handle.hxx>
#include <Standard.hxx>

void bind_OpenGl_LayerList(py::module &mod){

/*
py::class_<OpenGl_LayerList, std::unique_ptr<OpenGl_LayerList, Deleter<OpenGl_LayerList>>> cls_OpenGl_LayerList(mod, "OpenGl_LayerList", "Class defining the list of layers.");

// Constructors
cls_OpenGl_LayerList.def(py::init<const Standard_Integer>(), py::arg("theNbPriorities"));

// Fields

// Methods
cls_OpenGl_LayerList.def("NbPriorities", (Standard_Integer (OpenGl_LayerList::*)() const) &OpenGl_LayerList::NbPriorities, "Method returns the number of available priorities");
cls_OpenGl_LayerList.def("NbStructures", (Standard_Integer (OpenGl_LayerList::*)() const) &OpenGl_LayerList::NbStructures, "Number of displayed structures");
cls_OpenGl_LayerList.def("NbImmediateStructures", (Standard_Integer (OpenGl_LayerList::*)() const) &OpenGl_LayerList::NbImmediateStructures, "Return number of structures within immediate layers");
cls_OpenGl_LayerList.def("AddLayer", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::AddLayer, "Insert a new layer with id.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("RemoveLayer", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::RemoveLayer, "Remove layer by its id.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("AddStructure", [](OpenGl_LayerList &self, const OpenGl_Structure * a0, const Graphic3d_ZLayerId a1, const Standard_Integer a2) -> void { return self.AddStructure(a0, a1, a2); });
cls_OpenGl_LayerList.def("AddStructure", (void (OpenGl_LayerList::*)(const OpenGl_Structure *, const Graphic3d_ZLayerId, const Standard_Integer, Standard_Boolean)) &OpenGl_LayerList::AddStructure, "Add structure to list with given priority. The structure will be inserted to specified layer. If the layer isn't found, the structure will be put to default bottom-level layer.", py::arg("theStruct"), py::arg("theLayerId"), py::arg("thePriority"), py::arg("isForChangePriority"));
cls_OpenGl_LayerList.def("RemoveStructure", (void (OpenGl_LayerList::*)(const OpenGl_Structure *)) &OpenGl_LayerList::RemoveStructure, "Remove structure from structure list and return its previous priority", py::arg("theStructure"));
cls_OpenGl_LayerList.def("ChangeLayer", (void (OpenGl_LayerList::*)(const OpenGl_Structure *, const Graphic3d_ZLayerId, const Graphic3d_ZLayerId)) &OpenGl_LayerList::ChangeLayer, "Change structure z layer If the new layer is not presented, the structure will be displayed in default z layer", py::arg("theStructure"), py::arg("theOldLayerId"), py::arg("theNewLayerId"));
cls_OpenGl_LayerList.def("ChangePriority", (void (OpenGl_LayerList::*)(const OpenGl_Structure *, const Graphic3d_ZLayerId, const Standard_Integer)) &OpenGl_LayerList::ChangePriority, "Changes structure priority within its ZLayer", py::arg("theStructure"), py::arg("theLayerId"), py::arg("theNewPriority"));
cls_OpenGl_LayerList.def("Layer", (OpenGl_Layer & (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::Layer, "Returns reference to the layer with given ID.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("Layer", (const OpenGl_Layer & (OpenGl_LayerList::*)(const Graphic3d_ZLayerId) const) &OpenGl_LayerList::Layer, "Returns reference to the layer with given ID.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("SetLayerSettings", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &OpenGl_LayerList::SetLayerSettings, "Assign new settings to the layer.", py::arg("theLayerId"), py::arg("theSettings"));
cls_OpenGl_LayerList.def("UpdateCulling", (void (OpenGl_LayerList::*)(const opencascade::handle<OpenGl_Workspace> &, const Standard_Boolean)) &OpenGl_LayerList::UpdateCulling, "Update culling state - should be called before rendering.", py::arg("theWorkspace"), py::arg("theToDrawImmediate"));
cls_OpenGl_LayerList.def("Render", (void (OpenGl_LayerList::*)(const opencascade::handle<OpenGl_Workspace> &, const Standard_Boolean, const OpenGl_LayerFilter, OpenGl_FrameBuffer *, OpenGl_FrameBuffer *) const) &OpenGl_LayerList::Render, "Render this element", py::arg("theWorkspace"), py::arg("theToDrawImmediate"), py::arg("theLayersToProcess"), py::arg("theReadDrawFbo"), py::arg("theOitAccumFbo"));
cls_OpenGl_LayerList.def("Layers", (const OpenGl_SequenceOfLayers & (OpenGl_LayerList::*)() const) &OpenGl_LayerList::Layers, "Returns the set of OpenGL Z-layers.");
cls_OpenGl_LayerList.def("LayerIDs", (const OpenGl_LayerSeqIds & (OpenGl_LayerList::*)() const) &OpenGl_LayerList::LayerIDs, "Returns the map of Z-layer IDs to indexes.");
cls_OpenGl_LayerList.def("InvalidateBVHData", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::InvalidateBVHData, "Marks BVH tree for given priority list as dirty and marks primitive set for rebuild.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("ModificationStateOfRaytracable", (Standard_Size (OpenGl_LayerList::*)() const) &OpenGl_LayerList::ModificationStateOfRaytracable, "Returns structure modification state (for ray-tracing).");
cls_OpenGl_LayerList.def("FrustumCullingBVHBuilder", (const opencascade::handle<Select3D_BVHBuilder3d> & (OpenGl_LayerList::*)() const) &OpenGl_LayerList::FrustumCullingBVHBuilder, "Returns BVH tree builder for frustom culling.");
cls_OpenGl_LayerList.def("SetFrustumCullingBVHBuilder", (void (OpenGl_LayerList::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &OpenGl_LayerList::SetFrustumCullingBVHBuilder, "Assigns BVH tree builder for frustom culling.", py::arg("theBuilder"));
// cls_OpenGl_LayerList.def_static("operator new_", (void * (*)(size_t)) &OpenGl_LayerList::operator new, "None", py::arg("theSize"));
// cls_OpenGl_LayerList.def_static("operator delete_", (void (*)(void *)) &OpenGl_LayerList::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_LayerList.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_LayerList::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_LayerList.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_LayerList::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_LayerList.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_LayerList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_LayerList.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_LayerList::operator delete, "None", py::arg(""), py::arg(""));

// Enums
*/

}