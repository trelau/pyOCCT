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
#include <BOPDS_Iterator.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_Context.hxx>
#include <Precision.hxx>
#include <BOPDS_IteratorSI.hxx>

void bind_BOPDS_IteratorSI(py::module &mod){

py::class_<BOPDS_IteratorSI, std::unique_ptr<BOPDS_IteratorSI>, BOPDS_Iterator> cls_BOPDS_IteratorSI(mod, "BOPDS_IteratorSI", "The class BOPDS_IteratorSI is 1.to compute self-intersections between BRep sub-shapes of each argument of an operation (see the class BOPDS_DS) in terms of theirs bounding boxes 2.provides interface to iterare the pairs of intersected sub-shapes of given type");

// Constructors
cls_BOPDS_IteratorSI.def(py::init<>());
cls_BOPDS_IteratorSI.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_IteratorSI.def_static("operator new_", (void * (*)(size_t)) &BOPDS_IteratorSI::operator new, "None", py::arg("theSize"));
// cls_BOPDS_IteratorSI.def_static("operator delete_", (void (*)(void *)) &BOPDS_IteratorSI::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_IteratorSI.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_IteratorSI::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_IteratorSI.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_IteratorSI::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_IteratorSI.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_IteratorSI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_IteratorSI.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_IteratorSI::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_IteratorSI.def("UpdateByLevelOfCheck", (void (BOPDS_IteratorSI::*)(const Standard_Integer)) &BOPDS_IteratorSI::UpdateByLevelOfCheck, "Updates the lists of possible intersections according to the value of <theLevel>. It defines which interferferences will be checked: 0 - only V/V; 1 - V/V and V/E; 2 - V/V, V/E and E/E; 3 - V/V, V/E, E/E and V/F; 4 - V/V, V/E, E/E, V/F and E/F; other - all interferences.", py::arg("theLevel"));

// Enums

}