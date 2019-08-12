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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_Selection.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopoDS_Face.hxx>
#include <Select3D_EntitySequence.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <StdSelect_BRepSelectionTool.hxx>

void bind_StdSelect_BRepSelectionTool(py::module &mod){

py::class_<StdSelect_BRepSelectionTool, std::unique_ptr<StdSelect_BRepSelectionTool, Deleter<StdSelect_BRepSelectionTool>>> cls_StdSelect_BRepSelectionTool(mod, "StdSelect_BRepSelectionTool", "Tool to create specific selections (sets of primitives) for Shapes from Topology. These Selections may be used in dynamic selection Mechanism Given a Shape and a mode of selection (selection of vertices, edges,faces ...) , This Tool Computes corresponding sensitive primitives, puts them in an entity called Selection (see package SelectMgr) and returns it.");

// Constructors

// Fields

// Methods
// cls_StdSelect_BRepSelectionTool.def_static("operator new_", (void * (*)(size_t)) &StdSelect_BRepSelectionTool::operator new, "None", py::arg("theSize"));
// cls_StdSelect_BRepSelectionTool.def_static("operator delete_", (void (*)(void *)) &StdSelect_BRepSelectionTool::operator delete, "None", py::arg("theAddress"));
// cls_StdSelect_BRepSelectionTool.def_static("operator new[]_", (void * (*)(size_t)) &StdSelect_BRepSelectionTool::operator new[], "None", py::arg("theSize"));
// cls_StdSelect_BRepSelectionTool.def_static("operator delete[]_", (void (*)(void *)) &StdSelect_BRepSelectionTool::operator delete[], "None", py::arg("theAddress"));
// cls_StdSelect_BRepSelectionTool.def_static("operator new_", (void * (*)(size_t, void *)) &StdSelect_BRepSelectionTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdSelect_BRepSelectionTool.def_static("operator delete_", (void (*)(void *, void *)) &StdSelect_BRepSelectionTool::operator delete, "None", py::arg(""), py::arg(""));
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4, const Standard_Boolean a5) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4, const Standard_Boolean a5, const Standard_Integer a6) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4, const Standard_Boolean a5, const Standard_Integer a6, const Standard_Integer a7) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", (void (*)(const opencascade::handle<SelectMgr_Selection> &, const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Real)) &StdSelect_BRepSelectionTool::Load, "Decomposition of <aShape> into sensitive entities following a mode of decomposition <aType>. These entities are stored in <aSelection>. BrepOwners are created to store the identity of the picked shapes during the selection process. In those BRepOwners is also stored the original shape. But One can't get the selectable object which was decomposed to give the sensitive entities. maximal parameter is used for infinite objects, to limit the sensitive Domain.... If AutoTriangulation = True, a Triangulation will be computed for faces which have no existing one. if AutoTriangulation = False the old algorithm will be called to compute sensitive entities on faces.", py::arg("aSelection"), py::arg("aShape"), py::arg("aType"), py::arg("theDeflection"), py::arg("theDeviationAngle"), py::arg("AutoTriangulation"), py::arg("aPriority"), py::arg("NbPOnEdge"), py::arg("MaximalParameter"));
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6, const Standard_Integer a7) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6, const Standard_Integer a7, const Standard_Integer a8) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", (void (*)(const opencascade::handle<SelectMgr_Selection> &, const opencascade::handle<SelectMgr_SelectableObject> &, const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Real)) &StdSelect_BRepSelectionTool::Load, "Same functionnalities ; the only difference is that the selectable object from which the selection comes is stored in each Sensitive EntityOwner; decomposition of <aShape> into sensitive entities following a mode of decomposition <aType>. These entities are stored in <aSelection> The Major difference is that the known users are first inserted in the BRepOwners. the original shape is the last user... (see EntityOwner from SelectBasics and BrepOwner)...", py::arg("aSelection"), py::arg("Origin"), py::arg("aShape"), py::arg("aType"), py::arg("theDeflection"), py::arg("theDeviationAngle"), py::arg("AutoTriangulation"), py::arg("aPriority"), py::arg("NbPOnEdge"), py::arg("MaximalParameter"));
cls_StdSelect_BRepSelectionTool.def_static("GetStandardPriority_", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &StdSelect_BRepSelectionTool::GetStandardPriority, "Returns the standard priority of the shape aShap having the type aType. This priority is passed to a StdSelect_BRepOwner object. You can use the function Load to modify the selection priority of an owner to make one entity more selectable than another one.", py::arg("theShape"), py::arg("theType"));
cls_StdSelect_BRepSelectionTool.def_static("ComputeSensitive_", [](const TopoDS_Shape & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, const opencascade::handle<SelectMgr_Selection> & a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Real a6) -> void { return StdSelect_BRepSelectionTool::ComputeSensitive(a0, a1, a2, a3, a4, a5, a6); });
cls_StdSelect_BRepSelectionTool.def_static("ComputeSensitive_", (void (*)(const TopoDS_Shape &, const opencascade::handle<SelectMgr_EntityOwner> &, const opencascade::handle<SelectMgr_Selection> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &StdSelect_BRepSelectionTool::ComputeSensitive, "Computes the sensitive primitives, stores them in the SelectMgr_Selection object, and returns this object.", py::arg("theShape"), py::arg("theOwner"), py::arg("theSelection"), py::arg("theDeflection"), py::arg("theDeflAngle"), py::arg("theNbPOnEdge"), py::arg("theMaxiParam"), py::arg("theAutoTriang"));
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2, const Standard_Boolean a3) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2, a3); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2, const Standard_Boolean a3, const Standard_Integer a4) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2, a3, a4); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2, const Standard_Boolean a3, const Standard_Integer a4, const Standard_Real a5) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2, a3, a4, a5); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", (Standard_Boolean (*)(const TopoDS_Face &, const opencascade::handle<SelectMgr_EntityOwner> &, Select3D_EntitySequence &, const Standard_Boolean, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &StdSelect_BRepSelectionTool::GetSensitiveForFace, "Creates the 3D sensitive entities for Face selection.", py::arg("theFace"), py::arg("theOwner"), py::arg("theOutList"), py::arg("theAutoTriang"), py::arg("theNbPOnEdge"), py::arg("theMaxiParam"), py::arg("theInteriorFlag"));
cls_StdSelect_BRepSelectionTool.def_static("GetEdgeSensitive_", (void (*)(const TopoDS_Shape &, const opencascade::handle<SelectMgr_EntityOwner> &, const opencascade::handle<SelectMgr_Selection> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, opencascade::handle<Select3D_SensitiveEntity> &)) &StdSelect_BRepSelectionTool::GetEdgeSensitive, "Create a sensitive edge or sensitive wire.", py::arg("theShape"), py::arg("theOwner"), py::arg("theSelection"), py::arg("theDeflection"), py::arg("theDeviationAngle"), py::arg("theNbPOnEdge"), py::arg("theMaxiParam"), py::arg("theSensitive"));
cls_StdSelect_BRepSelectionTool.def_static("PreBuildBVH_", (void (*)(const opencascade::handle<SelectMgr_Selection> &)) &StdSelect_BRepSelectionTool::PreBuildBVH, "Traverses the selection given and pre-builds BVH trees for heavyweight sensitive entities containing more than BVH_PRIMITIVE_LIMIT (defined in .cxx file) sub-elements.", py::arg("theSelection"));

// Enums

}