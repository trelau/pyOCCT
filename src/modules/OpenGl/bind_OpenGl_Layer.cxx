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
#include <OpenGl_Layer.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <OpenGl_Structure.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_Camera.hxx>
#include <OpenGl_BVHTreeSelector.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_BVHClipPrimitiveSet.hxx>
#include <OpenGl_BVHClipPrimitiveTrsfPersSet.hxx>
#include <NCollection_IndexedMap.hxx>

void bind_OpenGl_Layer(py::module &mod){

/*
py::class_<OpenGl_Layer, opencascade::handle<OpenGl_Layer>, Standard_Transient> cls_OpenGl_Layer(mod, "OpenGl_Layer", "Presentations list sorted within priorities.");

// Constructors
cls_OpenGl_Layer.def(py::init<const Standard_Integer, const opencascade::handle<Select3D_BVHBuilder3d> &>(), py::arg("theNbPriorities"), py::arg("theBuilder"));

// Fields

// Methods
cls_OpenGl_Layer.def_static("get_type_name_", (const char * (*)()) &OpenGl_Layer::get_type_name, "None");
cls_OpenGl_Layer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Layer::get_type_descriptor, "None");
cls_OpenGl_Layer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Layer::*)() const) &OpenGl_Layer::DynamicType, "None");
cls_OpenGl_Layer.def("FrustumCullingBVHBuilder", (const opencascade::handle<Select3D_BVHBuilder3d> & (OpenGl_Layer::*)() const) &OpenGl_Layer::FrustumCullingBVHBuilder, "Returns BVH tree builder for frustom culling.");
cls_OpenGl_Layer.def("SetFrustumCullingBVHBuilder", (void (OpenGl_Layer::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &OpenGl_Layer::SetFrustumCullingBVHBuilder, "Assigns BVH tree builder for frustom culling.", py::arg("theBuilder"));
cls_OpenGl_Layer.def("IsImmediate", (Standard_Boolean (OpenGl_Layer::*)() const) &OpenGl_Layer::IsImmediate, "Return true if layer was marked with immediate flag.");
cls_OpenGl_Layer.def("LayerSettings", (const Graphic3d_ZLayerSettings & (OpenGl_Layer::*)() const) &OpenGl_Layer::LayerSettings, "Returns settings of the layer object.");
cls_OpenGl_Layer.def("SetLayerSettings", (void (OpenGl_Layer::*)(const Graphic3d_ZLayerSettings &)) &OpenGl_Layer::SetLayerSettings, "Sets settings of the layer object.", py::arg("theSettings"));
cls_OpenGl_Layer.def("Add", [](OpenGl_Layer &self, const OpenGl_Structure * a0, const Standard_Integer a1) -> void { return self.Add(a0, a1); });
cls_OpenGl_Layer.def("Add", (void (OpenGl_Layer::*)(const OpenGl_Structure *, const Standard_Integer, Standard_Boolean)) &OpenGl_Layer::Add, "None", py::arg("theStruct"), py::arg("thePriority"), py::arg("isForChangePriority"));
cls_OpenGl_Layer.def("Remove", [](OpenGl_Layer &self, const OpenGl_Structure * theStruct, Standard_Integer & thePriority, Standard_Boolean isForChangePriority){ bool rv = self.Remove(theStruct, thePriority, isForChangePriority); return std::tuple<bool, Standard_Integer &>(rv, thePriority); }, "Remove structure and returns its priority, if the structure is not found, method returns negative value", py::arg("theStruct"), py::arg("thePriority"), py::arg("isForChangePriority"));
cls_OpenGl_Layer.def("NbStructures", (Standard_Integer (OpenGl_Layer::*)() const) &OpenGl_Layer::NbStructures, "Returns the number of structures");
cls_OpenGl_Layer.def("NbStructuresNotCulled", (Standard_Integer (OpenGl_Layer::*)() const) &OpenGl_Layer::NbStructuresNotCulled, "Number of NOT culled structures in the layer.");
cls_OpenGl_Layer.def("NbPriorities", (Standard_Integer (OpenGl_Layer::*)() const) &OpenGl_Layer::NbPriorities, "Returns the number of available priority levels");
cls_OpenGl_Layer.def("Append", (Standard_Boolean (OpenGl_Layer::*)(const OpenGl_Layer &)) &OpenGl_Layer::Append, "Append layer of acceptable type (with similar number of priorities or less). Returns Standard_False if the list can not be accepted.", py::arg("theOther"));
cls_OpenGl_Layer.def("ArrayOfStructures", (const OpenGl_ArrayOfIndexedMapOfStructure & (OpenGl_Layer::*)() const) &OpenGl_Layer::ArrayOfStructures, "Returns array of OpenGL structures.");
cls_OpenGl_Layer.def("InvalidateBVHData", (void (OpenGl_Layer::*)()) &OpenGl_Layer::InvalidateBVHData, "Marks BVH tree for given priority list as dirty and marks primitive set for rebuild.");
cls_OpenGl_Layer.def("InvalidateBoundingBox", (void (OpenGl_Layer::*)() const) &OpenGl_Layer::InvalidateBoundingBox, "Marks cached bounding box as obsolete.");
cls_OpenGl_Layer.def("BoundingBox", (Bnd_Box (OpenGl_Layer::*)(const Standard_Integer, const opencascade::handle<Graphic3d_Camera> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean) const) &OpenGl_Layer::BoundingBox, "Returns layer bounding box.", py::arg("theViewId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"), py::arg("theToIncludeAuxiliary"));
cls_OpenGl_Layer.def("considerZoomPersistenceObjects", (Standard_Real (OpenGl_Layer::*)(const Standard_Integer, const opencascade::handle<Graphic3d_Camera> &, const Standard_Integer, const Standard_Integer) const) &OpenGl_Layer::considerZoomPersistenceObjects, "Returns zoom-scale factor.", py::arg("theViewId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"));
cls_OpenGl_Layer.def("UpdateCulling", (void (OpenGl_Layer::*)(const Standard_Integer, const OpenGl_BVHTreeSelector &, const Standard_Boolean)) &OpenGl_Layer::UpdateCulling, "Update culling state - should be called before rendering. Traverses through BVH tree to determine which structures are in view volume.", py::arg("theViewId"), py::arg("theSelector"), py::arg("theToTraverse"));
cls_OpenGl_Layer.def("IsCulled", (bool (OpenGl_Layer::*)() const) &OpenGl_Layer::IsCulled, "Returns TRUE if layer is empty or has been discarded entirely by culling test.");
cls_OpenGl_Layer.def("Render", (void (OpenGl_Layer::*)(const opencascade::handle<OpenGl_Workspace> &, const OpenGl_GlobalLayerSettings &) const) &OpenGl_Layer::Render, "None", py::arg("theWorkspace"), py::arg("theDefaultSettings"));
cls_OpenGl_Layer.def("NbOfTransformPersistenceObjects", (Standard_Integer (OpenGl_Layer::*)() const) &OpenGl_Layer::NbOfTransformPersistenceObjects, "Returns number of transform persistence objects.");
cls_OpenGl_Layer.def("CullableStructuresBVH", (const OpenGl_BVHClipPrimitiveSet & (OpenGl_Layer::*)() const) &OpenGl_Layer::CullableStructuresBVH, "Returns set of OpenGl_Structures structures for building BVH tree.");
cls_OpenGl_Layer.def("CullableTrsfPersStructuresBVH", (const OpenGl_BVHClipPrimitiveTrsfPersSet & (OpenGl_Layer::*)() const) &OpenGl_Layer::CullableTrsfPersStructuresBVH, "Returns set of transform persistent OpenGl_Structures for building BVH tree.");
cls_OpenGl_Layer.def("NonCullableStructures", (const NCollection_IndexedMap<const OpenGl_Structure *> & (OpenGl_Layer::*)() const) &OpenGl_Layer::NonCullableStructures, "Returns indexed map of always rendered structures.");

// Enums
*/

}