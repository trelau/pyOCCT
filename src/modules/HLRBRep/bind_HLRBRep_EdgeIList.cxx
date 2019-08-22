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
#include <HLRAlgo_InterferenceList.hxx>
#include <HLRAlgo_Interference.hxx>
#include <HLRBRep_EdgeInterferenceTool.hxx>
#include <HLRBRep_EdgeIList.hxx>

void bind_HLRBRep_EdgeIList(py::module &mod){

py::class_<HLRBRep_EdgeIList> cls_HLRBRep_EdgeIList(mod, "HLRBRep_EdgeIList", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_EdgeIList.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeIList::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeIList.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeIList::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeIList.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeIList::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeIList.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeIList::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeIList.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeIList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeIList.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeIList::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeIList.def_static("AddInterference_", (void (*)(HLRAlgo_InterferenceList &, const HLRAlgo_Interference &, const HLRBRep_EdgeInterferenceTool &)) &HLRBRep_EdgeIList::AddInterference, "Add the interference <I> to the list <IL>.", py::arg("IL"), py::arg("I"), py::arg("T"));
cls_HLRBRep_EdgeIList.def_static("ProcessComplex_", (void (*)(HLRAlgo_InterferenceList &, const HLRBRep_EdgeInterferenceTool &)) &HLRBRep_EdgeIList::ProcessComplex, "Process complex transitions on the list IL.", py::arg("IL"), py::arg("T"));

// Enums

}