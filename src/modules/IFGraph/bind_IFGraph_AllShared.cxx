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
#include <Interface_GraphContent.hxx>
#include <Standard.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFGraph_AllShared.hxx>

void bind_IFGraph_AllShared(py::module &mod){

py::class_<IFGraph_AllShared, std::unique_ptr<IFGraph_AllShared>, Interface_GraphContent> cls_IFGraph_AllShared(mod, "IFGraph_AllShared", "this class determines all Entities shared by some specific ones, at any level (those which will be lead in a Transfer for instance)");

// Constructors
cls_IFGraph_AllShared.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_IFGraph_AllShared.def(py::init<const Interface_Graph &, const opencascade::handle<Standard_Transient> &>(), py::arg("agraph"), py::arg("ent"));

// Fields

// Methods
// cls_IFGraph_AllShared.def_static("operator new_", (void * (*)(size_t)) &IFGraph_AllShared::operator new, "None", py::arg("theSize"));
// cls_IFGraph_AllShared.def_static("operator delete_", (void (*)(void *)) &IFGraph_AllShared::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_AllShared.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_AllShared::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_AllShared.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_AllShared::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_AllShared.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_AllShared::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_AllShared.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_AllShared::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_AllShared.def("GetFromEntity", (void (IFGraph_AllShared::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_AllShared::GetFromEntity, "adds an entity and its shared ones to the list (allows to cumulate all Entities shared by some ones)", py::arg("ent"));
cls_IFGraph_AllShared.def("GetFromIter", (void (IFGraph_AllShared::*)(const Interface_EntityIterator &)) &IFGraph_AllShared::GetFromIter, "Adds Entities from an EntityIterator and all their shared ones at any level", py::arg("iter"));
cls_IFGraph_AllShared.def("ResetData", (void (IFGraph_AllShared::*)()) &IFGraph_AllShared::ResetData, "Allows to restart on a new data set");
cls_IFGraph_AllShared.def("Evaluate", (void (IFGraph_AllShared::*)()) &IFGraph_AllShared::Evaluate, "does the specific evaluation (shared entities atall levels)");

// Enums

}