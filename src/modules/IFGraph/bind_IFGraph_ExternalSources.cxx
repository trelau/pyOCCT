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
#include <Standard_TypeDef.hxx>
#include <IFGraph_ExternalSources.hxx>

void bind_IFGraph_ExternalSources(py::module &mod){

py::class_<IFGraph_ExternalSources, std::unique_ptr<IFGraph_ExternalSources>, Interface_GraphContent> cls_IFGraph_ExternalSources(mod, "IFGraph_ExternalSources", "this class gives entities which are Source of entities of a sub-part, but are not contained by this sub-part");

// Constructors
cls_IFGraph_ExternalSources.def(py::init<const Interface_Graph &>(), py::arg("agraph"));

// Fields

// Methods
// cls_IFGraph_ExternalSources.def_static("operator new_", (void * (*)(size_t)) &IFGraph_ExternalSources::operator new, "None", py::arg("theSize"));
// cls_IFGraph_ExternalSources.def_static("operator delete_", (void (*)(void *)) &IFGraph_ExternalSources::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_ExternalSources.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_ExternalSources::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_ExternalSources.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_ExternalSources::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_ExternalSources.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_ExternalSources::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_ExternalSources.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_ExternalSources::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_ExternalSources.def("GetFromEntity", (void (IFGraph_ExternalSources::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_ExternalSources::GetFromEntity, "adds an entity and its shared ones to the list", py::arg("ent"));
cls_IFGraph_ExternalSources.def("GetFromIter", (void (IFGraph_ExternalSources::*)(const Interface_EntityIterator &)) &IFGraph_ExternalSources::GetFromIter, "adds a list of entities (as an iterator) with shared ones", py::arg("iter"));
cls_IFGraph_ExternalSources.def("ResetData", (void (IFGraph_ExternalSources::*)()) &IFGraph_ExternalSources::ResetData, "Allows to restart on a new data set");
cls_IFGraph_ExternalSources.def("Evaluate", (void (IFGraph_ExternalSources::*)()) &IFGraph_ExternalSources::Evaluate, "Evaluates external sources of a set of entities");
cls_IFGraph_ExternalSources.def("IsEmpty", (Standard_Boolean (IFGraph_ExternalSources::*)()) &IFGraph_ExternalSources::IsEmpty, "Returns True if no External Source are found It means that we have a 'root' set (performs an Evaluation as necessary)");

// Enums

}