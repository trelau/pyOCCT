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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepOffset_Mode.hxx>
#include <GeomAbs_JoinType.hxx>
#include <TopoDS_Face.hxx>
#include <BRepOffset_Analyse.hxx>
#include <BRepOffset_Error.hxx>
#include <BRepAlgo_Image.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepOffset_DataMapOfShapeOffset.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepOffset_Inter3d.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <BRepOffset_MakeLoops.hxx>
#include <BRepOffset_MakeOffset.hxx>

void bind_BRepOffset_MakeOffset(py::module &mod){

py::class_<BRepOffset_MakeOffset, std::unique_ptr<BRepOffset_MakeOffset>> cls_BRepOffset_MakeOffset(mod, "BRepOffset_MakeOffset", "None");

// Constructors
cls_BRepOffset_MakeOffset.def(py::init<>());
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"));
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"));
cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"), py::arg("RemoveIntEdges"));

// Fields

// Methods
// cls_BRepOffset_MakeOffset.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_MakeOffset::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_MakeOffset.def_static("operator delete_", (void (*)(void *)) &BRepOffset_MakeOffset::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_MakeOffset.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_MakeOffset::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_MakeOffset.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_MakeOffset::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_MakeOffset.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_MakeOffset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_MakeOffset.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_MakeOffset::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5); });
cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5, const GeomAbs_JoinType a6) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5, const GeomAbs_JoinType a6, const Standard_Boolean a7) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_BRepOffset_MakeOffset.def("Initialize", (void (BRepOffset_MakeOffset::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean)) &BRepOffset_MakeOffset::Initialize, "None", py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"), py::arg("RemoveIntEdges"));
cls_BRepOffset_MakeOffset.def("Clear", (void (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::Clear, "None");
cls_BRepOffset_MakeOffset.def("AddFace", (void (BRepOffset_MakeOffset::*)(const TopoDS_Face &)) &BRepOffset_MakeOffset::AddFace, "Add Closing Faces, <F> has to be in the initial shape S.", py::arg("F"));
cls_BRepOffset_MakeOffset.def("SetOffsetOnFace", (void (BRepOffset_MakeOffset::*)(const TopoDS_Face &, const Standard_Real)) &BRepOffset_MakeOffset::SetOffsetOnFace, "set the offset <Off> on the Face <F>", py::arg("F"), py::arg("Off"));
cls_BRepOffset_MakeOffset.def("MakeOffsetShape", (void (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::MakeOffsetShape, "None");
cls_BRepOffset_MakeOffset.def("MakeThickSolid", (void (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::MakeThickSolid, "None");
// cls_BRepOffset_MakeOffset.def("GetAnalyse", (const BRepOffset_Analyse & (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::GetAnalyse, "None");
cls_BRepOffset_MakeOffset.def("IsDone", (Standard_Boolean (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::IsDone, "None");
cls_BRepOffset_MakeOffset.def("Shape", (const TopoDS_Shape & (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::Shape, "None");
cls_BRepOffset_MakeOffset.def("Error", (BRepOffset_Error (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::Error, "returns information about offset state.");
cls_BRepOffset_MakeOffset.def("OffsetFacesFromShapes", (const BRepAlgo_Image & (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::OffsetFacesFromShapes, "Returns <Image> containing links between initials shapes and offset faces.");
cls_BRepOffset_MakeOffset.def("GetJoinType", (GeomAbs_JoinType (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::GetJoinType, "Returns myJoin.");
cls_BRepOffset_MakeOffset.def("OffsetEdgesFromShapes", (const BRepAlgo_Image & (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::OffsetEdgesFromShapes, "Returns <Image> containing links between initials shapes and offset edges.");
cls_BRepOffset_MakeOffset.def("ClosingFaces", (const TopTools_IndexedMapOfShape & (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::ClosingFaces, "Returns the list of closing faces stores by AddFace");
cls_BRepOffset_MakeOffset.def("CheckInputData", (Standard_Boolean (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::CheckInputData, "Makes pre analysis of possibility offset perform. Use method Error() to get more information. Finds first error. List of checks: 1) Check for existence object with non-null offset. 2) Check for connectivity in offset shell. 3) Check continuity of input surfaces. 4) Check for normals existence on grid.");
cls_BRepOffset_MakeOffset.def("GetBadShape", (const TopoDS_Shape & (BRepOffset_MakeOffset::*)() const) &BRepOffset_MakeOffset::GetBadShape, "Return bad shape, which obtained in CheckInputData.");

// Enums

}