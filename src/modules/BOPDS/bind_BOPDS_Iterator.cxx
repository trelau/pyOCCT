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
#include <NCollection_BaseAllocator.hxx>
#include <BOPDS_PDS.hxx>
#include <BOPDS_DS.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_Context.hxx>
#include <Precision.hxx>
#include <BOPDS_VectorOfVectorOfPair.hxx>
#include <BOPDS_VectorOfPair.hxx>
#include <NCollection_Vector.hxx>
#include <BOPDS_Iterator.hxx>

void bind_BOPDS_Iterator(py::module &mod){

py::class_<BOPDS_Iterator, std::unique_ptr<BOPDS_Iterator, Deleter<BOPDS_Iterator>>> cls_BOPDS_Iterator(mod, "BOPDS_Iterator", "The class BOPDS_Iterator is 1.to compute intersections between BRep sub-shapes of arguments of an operation (see the class BOPDS_DS) in terms of theirs bounding boxes 2.provides interface to iterare the pairs of intersected sub-shapes of given type");

// Constructors
cls_BOPDS_Iterator.def(py::init<>());
cls_BOPDS_Iterator.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_Iterator.def_static("operator new_", (void * (*)(size_t)) &BOPDS_Iterator::operator new, "None", py::arg("theSize"));
// cls_BOPDS_Iterator.def_static("operator delete_", (void (*)(void *)) &BOPDS_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_Iterator::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_Iterator.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_Iterator.def("SetDS", (void (BOPDS_Iterator::*)(const BOPDS_PDS &)) &BOPDS_Iterator::SetDS, "Modifier Sets the data structure <pDS> to process", py::arg("pDS"));
cls_BOPDS_Iterator.def("DS", (const BOPDS_DS & (BOPDS_Iterator::*)() const) &BOPDS_Iterator::DS, "Selector Returns the data structure");
cls_BOPDS_Iterator.def("Initialize", (void (BOPDS_Iterator::*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &BOPDS_Iterator::Initialize, "Initializes the iterator theType1 - the first type of shape theType2 - the second type of shape", py::arg("theType1"), py::arg("theType2"));
cls_BOPDS_Iterator.def("More", (Standard_Boolean (BOPDS_Iterator::*)() const) &BOPDS_Iterator::More, "Returns true if still there are pairs of intersected shapes");
cls_BOPDS_Iterator.def("Next", (void (BOPDS_Iterator::*)()) &BOPDS_Iterator::Next, "Moves iterations ahead");
cls_BOPDS_Iterator.def("Value", [](BOPDS_Iterator &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Value(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Returns indices (DS) of intersected shapes theIndex1 - the index of the first shape theIndex2 - the index of the second shape", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_Iterator.def("Prepare", [](BOPDS_Iterator &self) -> void { return self.Prepare(); });
cls_BOPDS_Iterator.def("Prepare", [](BOPDS_Iterator &self, const opencascade::handle<IntTools_Context> & a0) -> void { return self.Prepare(a0); });
cls_BOPDS_Iterator.def("Prepare", [](BOPDS_Iterator &self, const opencascade::handle<IntTools_Context> & a0, const Standard_Boolean a1) -> void { return self.Prepare(a0, a1); });
cls_BOPDS_Iterator.def("Prepare", (void (BOPDS_Iterator::*)(const opencascade::handle<IntTools_Context> &, const Standard_Boolean, const Standard_Real)) &BOPDS_Iterator::Prepare, "Perform the intersection algorithm and prepare the results to be used", py::arg("theCtx"), py::arg("theCheckOBB"), py::arg("theFuzzyValue"));
cls_BOPDS_Iterator.def("ExpectedLength", (Standard_Integer (BOPDS_Iterator::*)() const) &BOPDS_Iterator::ExpectedLength, "Returns the number of intersections founded");
cls_BOPDS_Iterator.def("BlockLength", (Standard_Integer (BOPDS_Iterator::*)() const) &BOPDS_Iterator::BlockLength, "Returns the block length");
cls_BOPDS_Iterator.def("SetRunParallel", (void (BOPDS_Iterator::*)(const Standard_Boolean)) &BOPDS_Iterator::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
cls_BOPDS_Iterator.def("RunParallel", (Standard_Boolean (BOPDS_Iterator::*)() const) &BOPDS_Iterator::RunParallel, "Returns the flag of parallel processing");

// Enums

}