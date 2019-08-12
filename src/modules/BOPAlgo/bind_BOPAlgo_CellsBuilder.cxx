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
#include <BOPAlgo_Builder.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BOPAlgo_CellsBuilder.hxx>

void bind_BOPAlgo_CellsBuilder(py::module &mod){

py::class_<BOPAlgo_CellsBuilder, std::unique_ptr<BOPAlgo_CellsBuilder, Deleter<BOPAlgo_CellsBuilder>>, BOPAlgo_Builder> cls_BOPAlgo_CellsBuilder(mod, "BOPAlgo_CellsBuilder", "The algorithm is based on the General Fuse algorithm (GFA). The result of GFA is all split parts of the Arguments.");

// Constructors
cls_BOPAlgo_CellsBuilder.def(py::init<>());
cls_BOPAlgo_CellsBuilder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_CellsBuilder.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_CellsBuilder::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_CellsBuilder.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_CellsBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_CellsBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_CellsBuilder::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_CellsBuilder.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_CellsBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_CellsBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_CellsBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_CellsBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_CellsBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_CellsBuilder.def("Clear", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::Clear, "Redefined method Clear - clears the contents.");
cls_BOPAlgo_CellsBuilder.def("AddToResult", [](BOPAlgo_CellsBuilder &self, const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1) -> void { return self.AddToResult(a0, a1); });
cls_BOPAlgo_CellsBuilder.def("AddToResult", [](BOPAlgo_CellsBuilder &self, const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1, const Standard_Integer a2) -> void { return self.AddToResult(a0, a1, a2); });
cls_BOPAlgo_CellsBuilder.def("AddToResult", (void (BOPAlgo_CellsBuilder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Integer, const Standard_Boolean)) &BOPAlgo_CellsBuilder::AddToResult, "Adding the parts to result. The parts are defined by two lists of shapes: <theLSToTake> defines the arguments which parts should be taken into result; <theLSToAvoid> defines the arguments which parts should not be taken into result; To be taken into result the part must be IN for all shapes from the list <theLSToTake> and must be OUT of all shapes from the list <theLSToAvoid>.", py::arg("theLSToTake"), py::arg("theLSToAvoid"), py::arg("theMaterial"), py::arg("theUpdate"));
cls_BOPAlgo_CellsBuilder.def("AddAllToResult", [](BOPAlgo_CellsBuilder &self) -> void { return self.AddAllToResult(); });
cls_BOPAlgo_CellsBuilder.def("AddAllToResult", [](BOPAlgo_CellsBuilder &self, const Standard_Integer a0) -> void { return self.AddAllToResult(a0); });
cls_BOPAlgo_CellsBuilder.def("AddAllToResult", (void (BOPAlgo_CellsBuilder::*)(const Standard_Integer, const Standard_Boolean)) &BOPAlgo_CellsBuilder::AddAllToResult, "Add all split parts to result. <theMaterial> defines the removal of internal boundaries; <theUpdate> parameter defines whether to remove boundaries now or not.", py::arg("theMaterial"), py::arg("theUpdate"));
cls_BOPAlgo_CellsBuilder.def("RemoveFromResult", (void (BOPAlgo_CellsBuilder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &)) &BOPAlgo_CellsBuilder::RemoveFromResult, "Removing the parts from result. The parts are defined by two lists of shapes: <theLSToTake> defines the arguments which parts should be removed from result; <theLSToAvoid> defines the arguments which parts should not be removed from result. To be removed from the result the part must be IN for all shapes from the list <theLSToTake> and must be OUT of all shapes from the list <theLSToAvoid>.", py::arg("theLSToTake"), py::arg("theLSToAvoid"));
cls_BOPAlgo_CellsBuilder.def("RemoveAllFromResult", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::RemoveAllFromResult, "Remove all parts from result.");
cls_BOPAlgo_CellsBuilder.def("RemoveInternalBoundaries", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::RemoveInternalBoundaries, "Removes internal boundaries between cells with the same material. If the result contains the cells with same material but of different dimension the removal of internal boundaries between these cells will not be performed. In case of some errors during the removal the method will set the appropriate warning status - use GetReport() to access them.");
cls_BOPAlgo_CellsBuilder.def("GetAllParts", (const TopoDS_Shape & (BOPAlgo_CellsBuilder::*)() const) &BOPAlgo_CellsBuilder::GetAllParts, "Get all split parts.");
cls_BOPAlgo_CellsBuilder.def("MakeContainers", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::MakeContainers, "Makes the Containers of proper type from the parts added to result.");

// Enums

}