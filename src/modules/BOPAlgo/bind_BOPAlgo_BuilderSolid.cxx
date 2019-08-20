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
#include <BOPAlgo_BuilderArea.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopTools_DataMapOfShapeBox.hxx>
#include <BOPAlgo_BuilderSolid.hxx>

void bind_BOPAlgo_BuilderSolid(py::module &mod){

py::class_<BOPAlgo_BuilderSolid, std::unique_ptr<BOPAlgo_BuilderSolid>, BOPAlgo_BuilderArea> cls_BOPAlgo_BuilderSolid(mod, "BOPAlgo_BuilderSolid", "Solid Builder is the algorithm for building solids from set of faces. The given faces should be non-intersecting, i.e. all coinciding parts of the faces should be shared among them.");

// Constructors
cls_BOPAlgo_BuilderSolid.def(py::init<>());
cls_BOPAlgo_BuilderSolid.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_BuilderSolid.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderSolid::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderSolid.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderSolid::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderSolid.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderSolid::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderSolid.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderSolid.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderSolid.def("Perform", (void (BOPAlgo_BuilderSolid::*)()) &BOPAlgo_BuilderSolid::Perform, "Performs the construction of the solids from the given faces");
cls_BOPAlgo_BuilderSolid.def("GetBoxesMap", (const TopTools_DataMapOfShapeBox & (BOPAlgo_BuilderSolid::*)() const) &BOPAlgo_BuilderSolid::GetBoxesMap, "For classification purposes the algorithm builds the bounding boxes for all created solids. This method returns the data map of solid - box pairs.");

// Enums

}