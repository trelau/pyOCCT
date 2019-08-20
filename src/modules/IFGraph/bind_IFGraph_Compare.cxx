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
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFGraph_Compare.hxx>

void bind_IFGraph_Compare(py::module &mod){

py::class_<IFGraph_Compare, std::unique_ptr<IFGraph_Compare>, Interface_GraphContent> cls_IFGraph_Compare(mod, "IFGraph_Compare", "this class evaluates effect of two compared sub-parts : cumulation (union), common part (intersection-overlapping) part specific to first sub-part or to the second one Results are kept in a Graph, several question can be set Basic Iteration gives Cumulation (union)");

// Constructors
cls_IFGraph_Compare.def(py::init<const Interface_Graph &>(), py::arg("agraph"));

// Fields

// Methods
// cls_IFGraph_Compare.def_static("operator new_", (void * (*)(size_t)) &IFGraph_Compare::operator new, "None", py::arg("theSize"));
// cls_IFGraph_Compare.def_static("operator delete_", (void (*)(void *)) &IFGraph_Compare::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_Compare.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_Compare::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_Compare.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_Compare::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_Compare.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_Compare::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_Compare.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_Compare::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_Compare.def("GetFromEntity", (void (IFGraph_Compare::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFGraph_Compare::GetFromEntity, "adds an entity and its shared ones to the list : first True means adds to the first sub-list, else to the 2nd", py::arg("ent"), py::arg("first"));
cls_IFGraph_Compare.def("GetFromIter", (void (IFGraph_Compare::*)(const Interface_EntityIterator &, const Standard_Boolean)) &IFGraph_Compare::GetFromIter, "adds a list of entities (as an iterator) as such, that is, their shared entities are not considered (use AllShared to have them) first True means adds to the first sub-list, else to the 2nd", py::arg("iter"), py::arg("first"));
cls_IFGraph_Compare.def("Merge", (void (IFGraph_Compare::*)()) &IFGraph_Compare::Merge, "merges the second list into the first one, hence the second list is empty");
cls_IFGraph_Compare.def("RemoveSecond", (void (IFGraph_Compare::*)()) &IFGraph_Compare::RemoveSecond, "Removes the contents of second list");
cls_IFGraph_Compare.def("KeepCommon", (void (IFGraph_Compare::*)()) &IFGraph_Compare::KeepCommon, "Keeps only Common part, sets it as First list and clears second list");
cls_IFGraph_Compare.def("ResetData", (void (IFGraph_Compare::*)()) &IFGraph_Compare::ResetData, "Allows to restart on a new data set");
cls_IFGraph_Compare.def("Evaluate", (void (IFGraph_Compare::*)()) &IFGraph_Compare::Evaluate, "Recomputes result of comparing to sub-parts");
cls_IFGraph_Compare.def("Common", (Interface_EntityIterator (IFGraph_Compare::*)() const) &IFGraph_Compare::Common, "returns entities common to the both parts");
cls_IFGraph_Compare.def("FirstOnly", (Interface_EntityIterator (IFGraph_Compare::*)() const) &IFGraph_Compare::FirstOnly, "returns entities which are exclusively in the first list");
cls_IFGraph_Compare.def("SecondOnly", (Interface_EntityIterator (IFGraph_Compare::*)() const) &IFGraph_Compare::SecondOnly, "returns entities which are exclusively in the second part");

// Enums

}