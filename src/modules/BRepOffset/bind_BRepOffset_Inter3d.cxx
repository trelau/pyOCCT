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
#include <BRepAlgo_AsDes.hxx>
#include <TopAbs_State.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepAlgo_Image.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepOffset_Analyse.hxx>
#include <BRepOffset_DataMapOfShapeOffset.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepOffset_Inter3d.hxx>

void bind_BRepOffset_Inter3d(py::module &mod){

py::class_<BRepOffset_Inter3d, std::unique_ptr<BRepOffset_Inter3d>> cls_BRepOffset_Inter3d(mod, "BRepOffset_Inter3d", "Computes the intersection face face in a set of faces Store the result in a SD as AsDes.");

// Constructors
cls_BRepOffset_Inter3d.def(py::init<const opencascade::handle<BRepAlgo_AsDes> &, const TopAbs_State, const Standard_Real>(), py::arg("AsDes"), py::arg("Side"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepOffset_Inter3d.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_Inter3d::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_Inter3d.def_static("operator delete_", (void (*)(void *)) &BRepOffset_Inter3d::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_Inter3d.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_Inter3d::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_Inter3d.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_Inter3d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_Inter3d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_Inter3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_Inter3d.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_Inter3d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_Inter3d.def("CompletInt", (void (BRepOffset_Inter3d::*)(const TopTools_ListOfShape &, const BRepAlgo_Image &)) &BRepOffset_Inter3d::CompletInt, "None", py::arg("SetOfFaces"), py::arg("InitOffsetFace"));
cls_BRepOffset_Inter3d.def("FaceInter", (void (BRepOffset_Inter3d::*)(const TopoDS_Face &, const TopoDS_Face &, const BRepAlgo_Image &)) &BRepOffset_Inter3d::FaceInter, "None", py::arg("F1"), py::arg("F2"), py::arg("InitOffsetFace"));
cls_BRepOffset_Inter3d.def("ConnexIntByArc", (void (BRepOffset_Inter3d::*)(const TopTools_ListOfShape &, const TopoDS_Shape &, const BRepOffset_Analyse &, const BRepAlgo_Image &)) &BRepOffset_Inter3d::ConnexIntByArc, "None", py::arg("SetOfFaces"), py::arg("ShapeInit"), py::arg("Analyse"), py::arg("InitOffsetFace"));
cls_BRepOffset_Inter3d.def("ConnexIntByInt", [](BRepOffset_Inter3d &self, const TopoDS_Shape & a0, const BRepOffset_DataMapOfShapeOffset & a1, const BRepOffset_Analyse & a2, TopTools_DataMapOfShapeShape & a3, TopTools_DataMapOfShapeShape & a4, TopTools_ListOfShape & a5) -> void { return self.ConnexIntByInt(a0, a1, a2, a3, a4, a5); });
cls_BRepOffset_Inter3d.def("ConnexIntByInt", (void (BRepOffset_Inter3d::*)(const TopoDS_Shape &, const BRepOffset_DataMapOfShapeOffset &, const BRepOffset_Analyse &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &, TopTools_ListOfShape &, const Standard_Boolean)) &BRepOffset_Inter3d::ConnexIntByInt, "None", py::arg("SI"), py::arg("MapSF"), py::arg("A"), py::arg("MES"), py::arg("Build"), py::arg("Failed"), py::arg("bIsPlanar"));
cls_BRepOffset_Inter3d.def("ContextIntByInt", [](BRepOffset_Inter3d &self, const TopTools_IndexedMapOfShape & a0, const Standard_Boolean a1, const BRepOffset_DataMapOfShapeOffset & a2, const BRepOffset_Analyse & a3, TopTools_DataMapOfShapeShape & a4, TopTools_DataMapOfShapeShape & a5, TopTools_ListOfShape & a6) -> void { return self.ContextIntByInt(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffset_Inter3d.def("ContextIntByInt", (void (BRepOffset_Inter3d::*)(const TopTools_IndexedMapOfShape &, const Standard_Boolean, const BRepOffset_DataMapOfShapeOffset &, const BRepOffset_Analyse &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &, TopTools_ListOfShape &, const Standard_Boolean)) &BRepOffset_Inter3d::ContextIntByInt, "None", py::arg("ContextFaces"), py::arg("ExtentContext"), py::arg("MapSF"), py::arg("A"), py::arg("MES"), py::arg("Build"), py::arg("Failed"), py::arg("bIsPlanar"));
cls_BRepOffset_Inter3d.def("ContextIntByArc", (void (BRepOffset_Inter3d::*)(const TopTools_IndexedMapOfShape &, const Standard_Boolean, const BRepOffset_Analyse &, const BRepAlgo_Image &, BRepAlgo_Image &)) &BRepOffset_Inter3d::ContextIntByArc, "None", py::arg("ContextFaces"), py::arg("ExtentContext"), py::arg("Analyse"), py::arg("InitOffsetFace"), py::arg("InitOffsetEdge"));
cls_BRepOffset_Inter3d.def("AddCommonEdges", (void (BRepOffset_Inter3d::*)(const TopTools_ListOfShape &)) &BRepOffset_Inter3d::AddCommonEdges, "None", py::arg("SetOfFaces"));
cls_BRepOffset_Inter3d.def("SetDone", (void (BRepOffset_Inter3d::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepOffset_Inter3d::SetDone, "None", py::arg("F1"), py::arg("F2"));
cls_BRepOffset_Inter3d.def("IsDone", (Standard_Boolean (BRepOffset_Inter3d::*)(const TopoDS_Face &, const TopoDS_Face &) const) &BRepOffset_Inter3d::IsDone, "None", py::arg("F1"), py::arg("F2"));
cls_BRepOffset_Inter3d.def("TouchedFaces", (TopTools_IndexedMapOfShape & (BRepOffset_Inter3d::*)()) &BRepOffset_Inter3d::TouchedFaces, "None");
cls_BRepOffset_Inter3d.def("AsDes", (opencascade::handle<BRepAlgo_AsDes> (BRepOffset_Inter3d::*)() const) &BRepOffset_Inter3d::AsDes, "None");
cls_BRepOffset_Inter3d.def("NewEdges", (TopTools_IndexedMapOfShape & (BRepOffset_Inter3d::*)()) &BRepOffset_Inter3d::NewEdges, "None");

// Enums

}