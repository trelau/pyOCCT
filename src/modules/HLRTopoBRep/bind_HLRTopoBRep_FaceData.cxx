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
#include <TopTools_ListOfShape.hxx>
#include <HLRTopoBRep_FaceData.hxx>

void bind_HLRTopoBRep_FaceData(py::module &mod){

py::class_<HLRTopoBRep_FaceData, std::unique_ptr<HLRTopoBRep_FaceData>> cls_HLRTopoBRep_FaceData(mod, "HLRTopoBRep_FaceData", "Contains the 3 ListOfShape of a Face ( Internal OutLines, OutLines on restriction and IsoLines ).");

// Constructors
cls_HLRTopoBRep_FaceData.def(py::init<>());

// Fields

// Methods
// cls_HLRTopoBRep_FaceData.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_FaceData::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceData.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_FaceData::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceData.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_FaceData::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceData.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_FaceData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_FaceData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_FaceData.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_FaceData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_FaceData.def("FaceIntL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const) &HLRTopoBRep_FaceData::FaceIntL, "None");
cls_HLRTopoBRep_FaceData.def("FaceOutL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const) &HLRTopoBRep_FaceData::FaceOutL, "None");
cls_HLRTopoBRep_FaceData.def("FaceIsoL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const) &HLRTopoBRep_FaceData::FaceIsoL, "None");
cls_HLRTopoBRep_FaceData.def("AddIntL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddIntL, "None");
cls_HLRTopoBRep_FaceData.def("AddOutL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddOutL, "None");
cls_HLRTopoBRep_FaceData.def("AddIsoL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddIsoL, "None");

// Enums

}