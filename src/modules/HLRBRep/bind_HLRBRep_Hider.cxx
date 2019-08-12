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
#include <HLRBRep_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <HLRBRep_Hider.hxx>

void bind_HLRBRep_Hider(py::module &mod){

py::class_<HLRBRep_Hider, std::unique_ptr<HLRBRep_Hider, Deleter<HLRBRep_Hider>>> cls_HLRBRep_Hider(mod, "HLRBRep_Hider", "None");

// Constructors
cls_HLRBRep_Hider.def(py::init<const opencascade::handle<HLRBRep_Data> &>(), py::arg("DS"));

// Fields

// Methods
// cls_HLRBRep_Hider.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Hider::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Hider.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Hider::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Hider.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Hider::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Hider.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Hider::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Hider.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Hider::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Hider.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Hider::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Hider.def("OwnHiding", (void (HLRBRep_Hider::*)(const Standard_Integer)) &HLRBRep_Hider::OwnHiding, "own hiding the side face number <FI>.", py::arg("FI"));
cls_HLRBRep_Hider.def("Hide", (void (HLRBRep_Hider::*)(const Standard_Integer, BRepTopAdaptor_MapOfShapeTool &)) &HLRBRep_Hider::Hide, "Removes from the edges, the parts hidden by the hiding face number <FI>.", py::arg("FI"), py::arg("MST"));

// Enums

}