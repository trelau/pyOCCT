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
#include <Select3D_SensitiveSet.hxx>
#include <Standard_Handle.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Buffer.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <TopLoc_Location.hxx>
#include <Select3D_BndBox3d.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <Select3D_SensitivePrimitiveArray.hxx>
#include <NCollection_Array1.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <gp_Pnt.hxx>
#include <gp_GTrsf.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Select3D_BVHIndexBuffer.hxx>
#include <Standard_Type.hxx>

void bind_Select3D_SensitivePrimitiveArray(py::module &mod){

py::class_<Select3D_SensitivePrimitiveArray, opencascade::handle<Select3D_SensitivePrimitiveArray>, Select3D_SensitiveSet> cls_Select3D_SensitivePrimitiveArray(mod, "Select3D_SensitivePrimitiveArray", "Sensitive for triangulation or point set defined by Primitive Array. The primitives can be optionally combined into patches within BVH tree to reduce its building time in expense of extra traverse time.");

// Constructors
cls_Select3D_SensitivePrimitiveArray.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));

// Fields

// Methods
cls_Select3D_SensitivePrimitiveArray.def("PatchSizeMax", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::PatchSizeMax, "Return patch size limit (1 by default).");
cls_Select3D_SensitivePrimitiveArray.def("SetPatchSizeMax", (void (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer)) &Select3D_SensitivePrimitiveArray::SetPatchSizeMax, "Assign patch size limit. Should be set before initialization.", py::arg("thePatchSizeMax"));
cls_Select3D_SensitivePrimitiveArray.def("PatchDistance", (float (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::PatchDistance, "Maximum allowed distance between consequential elements in patch (ShortRealLast() by default). Has no effect on indexed triangulation.");
cls_Select3D_SensitivePrimitiveArray.def("SetPatchDistance", (void (Select3D_SensitivePrimitiveArray::*)(const float)) &Select3D_SensitivePrimitiveArray::SetPatchDistance, "Assign patch distance limit. Should be set before initialization.", py::arg("thePatchDistMax"));
cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4) -> bool { return self.InitTriangulation(a0, a1, a2, a3, a4); });
cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4, const bool a5) -> bool { return self.InitTriangulation(a0, a1, a2, a3, a4, a5); });
cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const Standard_Integer, const Standard_Integer, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitTriangulation, "Initialize the sensitive object from triangualtion. The sub-triangulation can be specified by arguments theIndexLower and theIndexUpper (these are for iterating theIndices, not to restrict the actual index values!).", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2) -> bool { return self.InitTriangulation(a0, a1, a2); });
cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const bool a3) -> bool { return self.InitTriangulation(a0, a1, a2, a3); });
cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitTriangulation, "Initialize the sensitive object from triangualtion.", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4) -> bool { return self.InitPoints(a0, a1, a2, a3, a4); });
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4, const bool a5) -> bool { return self.InitPoints(a0, a1, a2, a3, a4, a5); });
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const Standard_Integer, const Standard_Integer, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitPoints, "Initialize the sensitive object from point set. The sub-set of points can be specified by arguments theIndexLower and theIndexUpper (these are for iterating theIndices, not to restrict the actual index values!).", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2) -> bool { return self.InitPoints(a0, a1, a2); });
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const bool a3) -> bool { return self.InitPoints(a0, a1, a2, a3); });
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitPoints, "Initialize the sensitive object from point set.", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const TopLoc_Location & a1) -> bool { return self.InitPoints(a0, a1); });
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const TopLoc_Location & a1, const bool a2) -> bool { return self.InitPoints(a0, a1, a2); });
cls_Select3D_SensitivePrimitiveArray.def("InitPoints", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const TopLoc_Location &, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitPoints, "Initialize the sensitive object from point set.", py::arg("theVerts"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
cls_Select3D_SensitivePrimitiveArray.def("SetMinMax", (void (Select3D_SensitivePrimitiveArray::*)(double, double, double, double, double, double)) &Select3D_SensitivePrimitiveArray::SetMinMax, "Assign new not transformed bounding box.", py::arg("theMinX"), py::arg("theMinY"), py::arg("theMinZ"), py::arg("theMaxX"), py::arg("theMaxY"), py::arg("theMaxZ"));
cls_Select3D_SensitivePrimitiveArray.def("ToDetectElements", (bool (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::ToDetectElements, "Return flag to keep index of last topmost detected element, TRUE by default.");
cls_Select3D_SensitivePrimitiveArray.def("SetDetectElements", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectElements, "Setup keeping of the index of last topmost detected element (axis picking).", py::arg("theToDetect"));
cls_Select3D_SensitivePrimitiveArray.def("ToDetectElementMap", (bool (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::ToDetectElementMap, "Return flag to keep index map of last detected elements, FALSE by default (rectangle selection).");
cls_Select3D_SensitivePrimitiveArray.def("SetDetectElementMap", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectElementMap, "Setup keeping of the index map of last detected elements (rectangle selection).", py::arg("theToDetect"));
cls_Select3D_SensitivePrimitiveArray.def("ToDetectNodes", (bool (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::ToDetectNodes, "Return flag to keep index of last topmost detected node, FALSE by default.");
cls_Select3D_SensitivePrimitiveArray.def("SetDetectNodes", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectNodes, "Setup keeping of the index of last topmost detected node (for axis picking).", py::arg("theToDetect"));
cls_Select3D_SensitivePrimitiveArray.def("ToDetectNodeMap", (bool (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::ToDetectNodeMap, "Return flag to keep index map of last detected nodes, FALSE by default (rectangle selection).");
cls_Select3D_SensitivePrimitiveArray.def("SetDetectNodeMap", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectNodeMap, "Setup keeping of the index map of last detected nodes (rectangle selection).", py::arg("theToDetect"));
cls_Select3D_SensitivePrimitiveArray.def("ToDetectEdges", (bool (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::ToDetectEdges, "Return flag to keep index of last topmost detected edge, FALSE by default.");
cls_Select3D_SensitivePrimitiveArray.def("SetDetectEdges", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectEdges, "Setup keeping of the index of last topmost detected edge (axis picking).", py::arg("theToDetect"));
cls_Select3D_SensitivePrimitiveArray.def("LastDetectedElement", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::LastDetectedElement, "Return last topmost detected element or -1 if undefined (axis picking).");
cls_Select3D_SensitivePrimitiveArray.def("LastDetectedElementMap", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::LastDetectedElementMap, "Return the index map of last detected elements (rectangle selection).");
cls_Select3D_SensitivePrimitiveArray.def("LastDetectedNode", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::LastDetectedNode, "Return last topmost detected node or -1 if undefined (axis picking).");
cls_Select3D_SensitivePrimitiveArray.def("LastDetectedNodeMap", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::LastDetectedNodeMap, "Return the index map of last detected nodes (rectangle selection).");
cls_Select3D_SensitivePrimitiveArray.def("LastDetectedEdgeNode1", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::LastDetectedEdgeNode1, "Return the first node of last topmost detected edge or -1 if undefined (axis picking).");
cls_Select3D_SensitivePrimitiveArray.def("LastDetectedEdgeNode2", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::LastDetectedEdgeNode2, "Return the second node of last topmost detected edge or -1 if undefined (axis picking).");
cls_Select3D_SensitivePrimitiveArray.def("Matches", (Standard_Boolean (Select3D_SensitivePrimitiveArray::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitivePrimitiveArray::Matches, "Checks whether the sensitive entity is overlapped by current selecting volume.", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitivePrimitiveArray.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::GetConnected, "None");
cls_Select3D_SensitivePrimitiveArray.def("Size", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::Size, "Returns the length of array of triangles or edges");
cls_Select3D_SensitivePrimitiveArray.def("NbSubElements", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::NbSubElements, "Returns the amount of nodes in triangulation");
cls_Select3D_SensitivePrimitiveArray.def("Box", (Select3D_BndBox3d (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer) const) &Select3D_SensitivePrimitiveArray::Box, "Returns bounding box of triangle/edge with index theIdx", py::arg("theIdx"));
cls_Select3D_SensitivePrimitiveArray.def("Center", (Standard_Real (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_SensitivePrimitiveArray::Center, "Returns geometry center of triangle/edge with index theIdx in array along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_SensitivePrimitiveArray.def("Swap", (void (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::Swap, "Swaps items with indexes theIdx1 and theIdx2 in array", py::arg("theIdx1"), py::arg("theIdx2"));
cls_Select3D_SensitivePrimitiveArray.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
cls_Select3D_SensitivePrimitiveArray.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::CenterOfGeometry, "Returns center of triangulation. If location transformation is set, it will be applied");
cls_Select3D_SensitivePrimitiveArray.def("HasInitLocation", (Standard_Boolean (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
cls_Select3D_SensitivePrimitiveArray.def("InvInitLocation", (gp_GTrsf (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");
cls_Select3D_SensitivePrimitiveArray.def("Set", (void (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &Select3D_SensitivePrimitiveArray::Set, "Sets the owner for all entities in group", py::arg("theOwnerId"));
cls_Select3D_SensitivePrimitiveArray.def("BVH", (void (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::BVH, "Builds BVH tree for sensitive set.");
cls_Select3D_SensitivePrimitiveArray.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitivePrimitiveArray::get_type_name, "None");
cls_Select3D_SensitivePrimitiveArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitivePrimitiveArray::get_type_descriptor, "None");
cls_Select3D_SensitivePrimitiveArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitivePrimitiveArray::*)() const) &Select3D_SensitivePrimitiveArray::DynamicType, "None");

// Enums

}