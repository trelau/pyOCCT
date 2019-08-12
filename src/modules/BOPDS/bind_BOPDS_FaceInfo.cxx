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
#include <Standard_TypeDef.hxx>
#include <BOPDS_IndexedMapOfPaveBlock.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <BOPDS_FaceInfo.hxx>

void bind_BOPDS_FaceInfo(py::module &mod){

py::class_<BOPDS_FaceInfo, std::unique_ptr<BOPDS_FaceInfo, Deleter<BOPDS_FaceInfo>>> cls_BOPDS_FaceInfo(mod, "BOPDS_FaceInfo", "The class BOPDS_FaceInfo is to store handy information about state of face");

// Constructors
cls_BOPDS_FaceInfo.def(py::init<>());
cls_BOPDS_FaceInfo.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_FaceInfo.def_static("operator new_", (void * (*)(size_t)) &BOPDS_FaceInfo::operator new, "None", py::arg("theSize"));
// cls_BOPDS_FaceInfo.def_static("operator delete_", (void (*)(void *)) &BOPDS_FaceInfo::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_FaceInfo.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_FaceInfo::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_FaceInfo.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_FaceInfo::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_FaceInfo.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_FaceInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_FaceInfo.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_FaceInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_FaceInfo.def("Clear", (void (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::Clear, "Clears the contents");
cls_BOPDS_FaceInfo.def("SetIndex", (void (BOPDS_FaceInfo::*)(const Standard_Integer)) &BOPDS_FaceInfo::SetIndex, "Modifier Sets the index of the face <theI>", py::arg("theI"));
cls_BOPDS_FaceInfo.def("Index", (Standard_Integer (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::Index, "Selector Returns the index of the face");
cls_BOPDS_FaceInfo.def("PaveBlocksIn", (const BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::PaveBlocksIn, "Selector Returns the pave blocks of the face that have state In");
cls_BOPDS_FaceInfo.def("ChangePaveBlocksIn", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangePaveBlocksIn, "Selector/Modifier Returns the pave blocks of the face that have state In");
cls_BOPDS_FaceInfo.def("VerticesIn", (const TColStd_MapOfInteger & (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::VerticesIn, "Selector Returns the list of indices for vertices of the face that have state In");
cls_BOPDS_FaceInfo.def("ChangeVerticesIn", (TColStd_MapOfInteger & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangeVerticesIn, "Selector/Modifier Returns the list of indices for vertices of the face that have state In");
cls_BOPDS_FaceInfo.def("PaveBlocksOn", (const BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::PaveBlocksOn, "Selector Returns the pave blocks of the face that have state On");
cls_BOPDS_FaceInfo.def("ChangePaveBlocksOn", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangePaveBlocksOn, "Selector/Modifier Returns the pave blocks of the face that have state On");
cls_BOPDS_FaceInfo.def("VerticesOn", (const TColStd_MapOfInteger & (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::VerticesOn, "Selector Returns the list of indices for vertices of the face that have state On");
cls_BOPDS_FaceInfo.def("ChangeVerticesOn", (TColStd_MapOfInteger & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangeVerticesOn, "Selector/Modifier Returns the list of indices for vertices of the face that have state On");
cls_BOPDS_FaceInfo.def("PaveBlocksSc", (const BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::PaveBlocksSc, "Selector Returns the pave blocks of the face that are pave blocks of section edges");
cls_BOPDS_FaceInfo.def("ChangePaveBlocksSc", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangePaveBlocksSc, "None");
cls_BOPDS_FaceInfo.def("VerticesSc", (const TColStd_MapOfInteger & (BOPDS_FaceInfo::*)() const) &BOPDS_FaceInfo::VerticesSc, "Selector Returns the list of indices for section vertices of the face");
cls_BOPDS_FaceInfo.def("ChangeVerticesSc", (TColStd_MapOfInteger & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangeVerticesSc, "Selector/Modifier Returns the list of indices for section vertices of the face");

// Enums

}