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
#include <IFGraph_Cumulate.hxx>

void bind_IFGraph_Cumulate(py::module &mod){

py::class_<IFGraph_Cumulate, std::unique_ptr<IFGraph_Cumulate>, Interface_GraphContent> cls_IFGraph_Cumulate(mod, "IFGraph_Cumulate", "this class evaluates effect of cumulated sub-parts : overlapping, forgotten entities Results are kept in a Graph, several question can be set Basic Iteration gives entities which are part of Cumulation");

// Constructors
cls_IFGraph_Cumulate.def(py::init<const Interface_Graph &>(), py::arg("agraph"));

// Fields

// Methods
// cls_IFGraph_Cumulate.def_static("operator new_", (void * (*)(size_t)) &IFGraph_Cumulate::operator new, "None", py::arg("theSize"));
// cls_IFGraph_Cumulate.def_static("operator delete_", (void (*)(void *)) &IFGraph_Cumulate::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_Cumulate.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_Cumulate::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_Cumulate.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_Cumulate::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_Cumulate.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_Cumulate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_Cumulate.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_Cumulate::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_Cumulate.def("GetFromEntity", (void (IFGraph_Cumulate::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_Cumulate::GetFromEntity, "adds an entity and its shared ones to the list", py::arg("ent"));
cls_IFGraph_Cumulate.def("GetFromIter", (void (IFGraph_Cumulate::*)(const Interface_EntityIterator &)) &IFGraph_Cumulate::GetFromIter, "adds a list of entities (as an iterator) as such, that is, without their shared entities (use AllShared to have them)", py::arg("iter"));
cls_IFGraph_Cumulate.def("ResetData", (void (IFGraph_Cumulate::*)()) &IFGraph_Cumulate::ResetData, "Allows to restart on a new data set");
cls_IFGraph_Cumulate.def("Evaluate", (void (IFGraph_Cumulate::*)()) &IFGraph_Cumulate::Evaluate, "Evaluates the result of cumulation");
cls_IFGraph_Cumulate.def("Overlapped", (Interface_EntityIterator (IFGraph_Cumulate::*)() const) &IFGraph_Cumulate::Overlapped, "returns entities which are taken several times");
cls_IFGraph_Cumulate.def("Forgotten", (Interface_EntityIterator (IFGraph_Cumulate::*)() const) &IFGraph_Cumulate::Forgotten, "returns entities which are not taken");
cls_IFGraph_Cumulate.def("PerCount", [](IFGraph_Cumulate &self) -> Interface_EntityIterator { return self.PerCount(); });
cls_IFGraph_Cumulate.def("PerCount", (Interface_EntityIterator (IFGraph_Cumulate::*)(const Standard_Integer) const) &IFGraph_Cumulate::PerCount, "Returns entities taken a given count of times (0 : same as Forgotten, 1 : same as no Overlap : default)", py::arg("count"));
cls_IFGraph_Cumulate.def("NbTimes", (Standard_Integer (IFGraph_Cumulate::*)(const opencascade::handle<Standard_Transient> &) const) &IFGraph_Cumulate::NbTimes, "returns number of times an Entity has been counted (0 means forgotten, more than 1 means overlap, 1 is normal)", py::arg("ent"));
cls_IFGraph_Cumulate.def("HighestNbTimes", (Standard_Integer (IFGraph_Cumulate::*)() const) &IFGraph_Cumulate::HighestNbTimes, "Returns the highest number of times recorded for every Entity (0 means empty, 1 means no overlap)");

// Enums

}