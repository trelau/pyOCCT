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
#include <BOPDS_DS.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <BOPAlgo_Tools.hxx>
#include <NCollection_List.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.hxx>
#include <BOPDS_PDS.hxx>
#include <BOPDS_CommonBlock.hxx>
#include <IntTools_Context.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_IndexedDataMapOfShapeReal.hxx>
#include <TopTools_ListOfListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeBox.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>

void bind_BOPAlgo_Tools(py::module &mod){

py::class_<BOPAlgo_Tools> cls_BOPAlgo_Tools(mod, "BOPAlgo_Tools", "Provides tools used in the intersection part of Boolean operations");

// Constructors

// Fields

// Methods
cls_BOPAlgo_Tools.def_static("FillMap_", (void (*)(const opencascade::handle<BOPDS_PaveBlock> &, const Standard_Integer, BOPDS_IndexedDataMapOfPaveBlockListOfInteger &, const opencascade::handle<NCollection_BaseAllocator> &)) &BOPAlgo_Tools::FillMap, "None", py::arg("thePB1"), py::arg("theF"), py::arg("theMILI"), py::arg("theAllocator"));
// cls_BOPAlgo_Tools.def_static("PerformCommonBlocks_", (void (*)(BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &, const opencascade::handle<NCollection_BaseAllocator> &, BOPDS_PDS &)) &BOPAlgo_Tools::PerformCommonBlocks, "None", py::arg("theMBlocks"), py::arg("theAllocator"), py::arg("theDS"));
// cls_BOPAlgo_Tools.def_static("PerformCommonBlocks_", (void (*)(const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &, const opencascade::handle<NCollection_BaseAllocator> &, BOPDS_PDS &)) &BOPAlgo_Tools::PerformCommonBlocks, "None", py::arg("theMBlocks"), py::arg("theAllocator"), py::arg("pDS"));
cls_BOPAlgo_Tools.def_static("ComputeToleranceOfCB_", (Standard_Real (*)(const opencascade::handle<BOPDS_CommonBlock> &, const BOPDS_PDS, const opencascade::handle<IntTools_Context> &)) &BOPAlgo_Tools::ComputeToleranceOfCB, "None", py::arg("theCB"), py::arg("theDS"), py::arg("theContext"));
cls_BOPAlgo_Tools.def_static("EdgesToWires_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return BOPAlgo_Tools::EdgesToWires(a0, a1); });
cls_BOPAlgo_Tools.def_static("EdgesToWires_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Integer { return BOPAlgo_Tools::EdgesToWires(a0, a1, a2); });
cls_BOPAlgo_Tools.def_static("EdgesToWires_", (Standard_Integer (*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean, const Standard_Real)) &BOPAlgo_Tools::EdgesToWires, "Creates planar wires from the given edges. The input edges are expected to be planar. And for the performance sake the method does not check if the edges are really planar. Thus, the result wires will also be not planar if the input edges are not planar. The edges may be not shared, but the resulting wires will be sharing the coinciding parts and intersecting parts. The output wires may be non-manifold and contain free and multi-connected vertices. Parameters: <theEdges> - input edges; <theWires> - output wires; <theShared> - boolean flag which defines whether the input edges are already shared or have to be intersected; <theAngTol> - the angular tolerance which will be used for distinguishing the planes in which the edges are located. Default value is 1.e-8 which is used for intersection of planes in IntTools_FaceFace. Method returns the following error statuses: 0 - in case of success (at least one wire has been built); 1 - in case there are no edges in the given shape; 2 - sharing of the edges has failed.", py::arg("theEdges"), py::arg("theWires"), py::arg("theShared"), py::arg("theAngTol"));
cls_BOPAlgo_Tools.def_static("WiresToFaces_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Boolean { return BOPAlgo_Tools::WiresToFaces(a0, a1); });
cls_BOPAlgo_Tools.def_static("WiresToFaces_", (Standard_Boolean (*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Real)) &BOPAlgo_Tools::WiresToFaces, "Creates planar faces from given planar wires. The method does not check if the wires are really planar. The input wires may be non-manifold but should be shared. The wires located in the same planes and included into other wires will create holes in the faces built from outer wires. The tolerance values of the input shapes may be modified during the operation due to projection of the edges on the planes for creation of 2D curves. Parameters: <theWires> - the given wires; <theFaces> - the output faces; <theAngTol> - the angular tolerance for distinguishing the planes in which the wires are located. Default value is 1.e-8 which is used for intersection of planes in IntTools_FaceFace. Method returns TRUE in case of success, i.e. at least one face has been built.", py::arg("theWires"), py::arg("theFaces"), py::arg("theAngTol"));
cls_BOPAlgo_Tools.def_static("IntersectVertices_", (void (*)(const TopTools_IndexedDataMapOfShapeReal &, const Standard_Boolean, const Standard_Real, TopTools_ListOfListOfShape &)) &BOPAlgo_Tools::IntersectVertices, "Finds chains of intersecting vertices", py::arg("theVertices"), py::arg("theRunParallel"), py::arg("theFuzzyValue"), py::arg("theChains"));
cls_BOPAlgo_Tools.def_static("TreatCompound_", (void (*)(const TopoDS_Shape &, TopTools_MapOfShape &, TopTools_ListOfShape &)) &BOPAlgo_Tools::TreatCompound, "Collect in the output list recursively all non-compound subshapes of the first level of the given shape theS. If a shape presents in the map theMFence it is skipped. All shapes put in the output are also added into theMFence.", py::arg("theS"), py::arg("theMFence"), py::arg("theLS"));
cls_BOPAlgo_Tools.def_static("ClassifyFaces_", [](const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1, const Standard_Boolean a2, opencascade::handle<IntTools_Context> & a3, TopTools_IndexedDataMapOfShapeListOfShape & a4) -> void { return BOPAlgo_Tools::ClassifyFaces(a0, a1, a2, a3, a4); });
cls_BOPAlgo_Tools.def_static("ClassifyFaces_", [](const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1, const Standard_Boolean a2, opencascade::handle<IntTools_Context> & a3, TopTools_IndexedDataMapOfShapeListOfShape & a4, const TopTools_DataMapOfShapeBox & a5) -> void { return BOPAlgo_Tools::ClassifyFaces(a0, a1, a2, a3, a4, a5); });
cls_BOPAlgo_Tools.def_static("ClassifyFaces_", (void (*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Boolean, opencascade::handle<IntTools_Context> &, TopTools_IndexedDataMapOfShapeListOfShape &, const TopTools_DataMapOfShapeBox &, const TopTools_DataMapOfShapeListOfShape &)) &BOPAlgo_Tools::ClassifyFaces, "Classifies the faces <theFaces> relatively solids <theSolids>. The IN faces for solids are stored into output data map <theInParts>.", py::arg("theFaces"), py::arg("theSolids"), py::arg("theRunParallel"), py::arg("theContext"), py::arg("theInParts"), py::arg("theShapeBoxMap"), py::arg("theSolidsIF"));

// Enums

}