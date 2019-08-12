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
#include <BOPAlgo_BOP.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BRepFeat_Builder.hxx>

void bind_BRepFeat_Builder(py::module &mod){

py::class_<BRepFeat_Builder, std::unique_ptr<BRepFeat_Builder, Deleter<BRepFeat_Builder>>, BOPAlgo_BOP> cls_BRepFeat_Builder(mod, "BRepFeat_Builder", "Provides a basic tool to implement features topological operations. The main goal of the algorithm is to perform the result of the operation according to the kept parts of the tool. Input data: a) DS; b) The kept parts of the tool; If the map of the kept parts of the tool is not filled boolean operation of the given type will be performed; c) Operation required. Steps: a) Fill myShapes, myRemoved maps; b) Rebuild edges and faces; c) Build images of the object; d) Build the result of the operation. Result: Result shape of the operation required.");

// Constructors
cls_BRepFeat_Builder.def(py::init<>());

// Fields

// Methods
// cls_BRepFeat_Builder.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_Builder::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_Builder.def_static("operator delete_", (void (*)(void *)) &BRepFeat_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_Builder::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_Builder.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_Builder.def("Clear", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::Clear, "Clears internal fields and arguments.");
cls_BRepFeat_Builder.def("Init", (void (BRepFeat_Builder::*)(const TopoDS_Shape &)) &BRepFeat_Builder::Init, "Initialyzes the object of local boolean operation.", py::arg("theShape"));
cls_BRepFeat_Builder.def("Init", (void (BRepFeat_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_Builder::Init, "Initialyzes the arguments of local boolean operation.", py::arg("theShape"), py::arg("theTool"));
cls_BRepFeat_Builder.def("SetOperation", (void (BRepFeat_Builder::*)(const Standard_Integer)) &BRepFeat_Builder::SetOperation, "Sets the operation of local boolean operation. If theFuse = 0 than the operation is CUT, otherwise FUSE.", py::arg("theFuse"));
cls_BRepFeat_Builder.def("SetOperation", (void (BRepFeat_Builder::*)(const Standard_Integer, const Standard_Boolean)) &BRepFeat_Builder::SetOperation, "Sets the operation of local boolean operation. If theFlag = TRUE it means that no selection of parts of the tool is needed, t.e. no second part. In that case if theFuse = 0 than operation is COMMON, otherwise CUT21. If theFlag = FALSE SetOperation(theFuse) function is called.", py::arg("theFuse"), py::arg("theFlag"));
cls_BRepFeat_Builder.def("PartsOfTool", (void (BRepFeat_Builder::*)(TopTools_ListOfShape &)) &BRepFeat_Builder::PartsOfTool, "Collects parts of the tool.", py::arg("theLT"));
cls_BRepFeat_Builder.def("KeepParts", (void (BRepFeat_Builder::*)(const TopTools_ListOfShape &)) &BRepFeat_Builder::KeepParts, "Initialyzes parts of the tool for second step of algorithm. Collects shapes and all sub-shapes into myShapes map.", py::arg("theIm"));
cls_BRepFeat_Builder.def("KeepPart", (void (BRepFeat_Builder::*)(const TopoDS_Shape &)) &BRepFeat_Builder::KeepPart, "Adds shape theS and all its sub-shapes into myShapes map.", py::arg("theS"));
cls_BRepFeat_Builder.def("PerformResult", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::PerformResult, "Main function to build the result of the local operation required.");
cls_BRepFeat_Builder.def("RebuildFaces", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::RebuildFaces, "Rebuilds faces in accordance with the kept parts of the tool.");
cls_BRepFeat_Builder.def("RebuildEdge", (void (BRepFeat_Builder::*)(const TopoDS_Shape &, const TopoDS_Face &, const TopTools_MapOfShape &, TopTools_ListOfShape &)) &BRepFeat_Builder::RebuildEdge, "Rebuilds edges in accordance with the kept parts of the tool.", py::arg("theE"), py::arg("theF"), py::arg("theME"), py::arg("aLEIm"));
cls_BRepFeat_Builder.def("CheckSolidImages", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::CheckSolidImages, "Collects the images of the object, that contains in the images of the tool.");
cls_BRepFeat_Builder.def("FillRemoved", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::FillRemoved, "Collects the removed parts of the tool into myRemoved map.");
cls_BRepFeat_Builder.def("FillRemoved", (void (BRepFeat_Builder::*)(const TopoDS_Shape &, TopTools_MapOfShape &)) &BRepFeat_Builder::FillRemoved, "Adds the shape S and its sub-shapes into myRemoved map.", py::arg("theS"), py::arg("theM"));

// Enums

}