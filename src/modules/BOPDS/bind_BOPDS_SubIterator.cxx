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
#include <TColStd_ListOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_VectorOfPair.hxx>
#include <NCollection_Vector.hxx>
#include <BOPDS_SubIterator.hxx>

void bind_BOPDS_SubIterator(py::module &mod){

py::class_<BOPDS_SubIterator> cls_BOPDS_SubIterator(mod, "BOPDS_SubIterator", "The class BOPDS_SubIterator is used to compute intersections between bounding boxes of two sub-sets of BRep sub-shapes of arguments of an operation (see the class BOPDS_DS). The class provides interface to iterate the pairs of intersected sub-shapes.");

// Constructors
cls_BOPDS_SubIterator.def(py::init<>());
cls_BOPDS_SubIterator.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_SubIterator.def_static("operator new_", (void * (*)(size_t)) &BOPDS_SubIterator::operator new, "None", py::arg("theSize"));
// cls_BOPDS_SubIterator.def_static("operator delete_", (void (*)(void *)) &BOPDS_SubIterator::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_SubIterator.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_SubIterator::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_SubIterator.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_SubIterator::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_SubIterator.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_SubIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_SubIterator.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_SubIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_SubIterator.def("SetDS", (void (BOPDS_SubIterator::*)(const BOPDS_PDS &)) &BOPDS_SubIterator::SetDS, "Sets the data structure <pDS> to process. It is used to access the shapes and their bounding boxes.", py::arg("pDS"));
cls_BOPDS_SubIterator.def("DS", (const BOPDS_DS & (BOPDS_SubIterator::*)() const) &BOPDS_SubIterator::DS, "Returns the data structure");
cls_BOPDS_SubIterator.def("SetSubSet1", (void (BOPDS_SubIterator::*)(const TColStd_ListOfInteger &)) &BOPDS_SubIterator::SetSubSet1, "Sets the first set of indices <theLI> to process", py::arg("theLI"));
cls_BOPDS_SubIterator.def("SubSet1", (const TColStd_ListOfInteger & (BOPDS_SubIterator::*)() const) &BOPDS_SubIterator::SubSet1, "Returns the first set of indices to process");
cls_BOPDS_SubIterator.def("SetSubSet2", (void (BOPDS_SubIterator::*)(const TColStd_ListOfInteger &)) &BOPDS_SubIterator::SetSubSet2, "Sets the second set of indices <theLI> to process", py::arg("theLI"));
cls_BOPDS_SubIterator.def("SubSet2", (const TColStd_ListOfInteger & (BOPDS_SubIterator::*)() const) &BOPDS_SubIterator::SubSet2, "Returns the second set of indices to process");
cls_BOPDS_SubIterator.def("Initialize", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Initialize, "Initializes the iterator");
cls_BOPDS_SubIterator.def("More", (Standard_Boolean (BOPDS_SubIterator::*)() const) &BOPDS_SubIterator::More, "Returns true if there are more pairs of intersected shapes");
cls_BOPDS_SubIterator.def("Next", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Next, "Moves iterations ahead");
cls_BOPDS_SubIterator.def("Value", [](BOPDS_SubIterator &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Value(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Returns indices (DS) of intersected shapes theIndex1 - the index of the first shape theIndex2 - the index of the second shape", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_SubIterator.def("Prepare", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Prepare, "Perform the intersection algorithm and prepare the results to be used");
cls_BOPDS_SubIterator.def("ExpectedLength", (Standard_Integer (BOPDS_SubIterator::*)() const) &BOPDS_SubIterator::ExpectedLength, "Returns the number of interfering pairs");

// Enums

}