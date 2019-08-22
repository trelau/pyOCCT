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
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_GraphContent.hxx>
#include <TColStd_HSequenceOfInteger.hxx>

void bind_IFGraph_SubPartsIterator(py::module &mod){

py::class_<IFGraph_SubPartsIterator> cls_IFGraph_SubPartsIterator(mod, "IFGraph_SubPartsIterator", "defines general form for graph classes of which result is not a single iteration on Entities, but a nested one : External iteration works on sub-parts, identified by each class (according to its algorithm) Internal Iteration concerns Entities of a sub-part Sub-Parts are assumed to be disjoined; if they are not, the first one has priority");

// Constructors
cls_IFGraph_SubPartsIterator.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
cls_IFGraph_SubPartsIterator.def(py::init<IFGraph_SubPartsIterator &>(), py::arg("other"));

// Fields

// Methods
// cls_IFGraph_SubPartsIterator.def_static("operator new_", (void * (*)(size_t)) &IFGraph_SubPartsIterator::operator new, "None", py::arg("theSize"));
// cls_IFGraph_SubPartsIterator.def_static("operator delete_", (void (*)(void *)) &IFGraph_SubPartsIterator::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_SubPartsIterator.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_SubPartsIterator::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_SubPartsIterator.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_SubPartsIterator::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_SubPartsIterator.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_SubPartsIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_SubPartsIterator.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_SubPartsIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_SubPartsIterator.def("GetParts", (void (IFGraph_SubPartsIterator::*)(IFGraph_SubPartsIterator &)) &IFGraph_SubPartsIterator::GetParts, "Gets Parts from another SubPartsIterator (in addition to the ones already recorded) Error if both SubPartsIterators are not based on the same Model", py::arg("other"));
cls_IFGraph_SubPartsIterator.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::Model, "Returns the Model with which this Iterator was created");
cls_IFGraph_SubPartsIterator.def("AddPart", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::AddPart, "Adds an empty part and sets it to receive entities");
cls_IFGraph_SubPartsIterator.def("NbParts", (Standard_Integer (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::NbParts, "Returns count of registered parts");
cls_IFGraph_SubPartsIterator.def("PartNum", (Standard_Integer (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::PartNum, "Returns numero of part which currently receives entities (0 at load time)");
cls_IFGraph_SubPartsIterator.def("SetLoad", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::SetLoad, "Sets SubPartIterator to get Entities (by GetFromEntity & GetFromIter) into load status, to be analysed later");
cls_IFGraph_SubPartsIterator.def("SetPartNum", (void (IFGraph_SubPartsIterator::*)(const Standard_Integer)) &IFGraph_SubPartsIterator::SetPartNum, "Sets numero of receiving part to a new value Error if not in range (1-NbParts)", py::arg("num"));
cls_IFGraph_SubPartsIterator.def("GetFromEntity", (void (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFGraph_SubPartsIterator::GetFromEntity, "Adds an Entity : into load status if in Load mode, to the current part if there is one. If shared is True, adds also its shared ones (shared at all levels)", py::arg("ent"), py::arg("shared"));
cls_IFGraph_SubPartsIterator.def("GetFromIter", (void (IFGraph_SubPartsIterator::*)(const Interface_EntityIterator &)) &IFGraph_SubPartsIterator::GetFromIter, "Adds a list of Entities (into Load mode or to a Part), given as an Iterator", py::arg("iter"));
cls_IFGraph_SubPartsIterator.def("Reset", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Reset, "Erases data (parts, entities) : 'me' becomes empty and in load status");
cls_IFGraph_SubPartsIterator.def("Evaluate", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Evaluate, "Called by Clear, this method allows evaluation just before iteration; its default is doing nothing, it is designed to be redefined");
cls_IFGraph_SubPartsIterator.def("Loaded", (Interface_GraphContent (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::Loaded, "Returns entities which where loaded (not set into a sub-part)");
cls_IFGraph_SubPartsIterator.def("LoadedGraph", (Interface_Graph (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::LoadedGraph, "Same as above, but under the form of a Graph");
cls_IFGraph_SubPartsIterator.def("IsLoaded", (Standard_Boolean (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &) const) &IFGraph_SubPartsIterator::IsLoaded, "Returns True if an Entity is loaded (either set into a sub-part or not)", py::arg("ent"));
cls_IFGraph_SubPartsIterator.def("IsInPart", (Standard_Boolean (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &) const) &IFGraph_SubPartsIterator::IsInPart, "Returns True if an Entity is Present in a sub-part", py::arg("ent"));
cls_IFGraph_SubPartsIterator.def("EntityPartNum", (Standard_Integer (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &) const) &IFGraph_SubPartsIterator::EntityPartNum, "Returns number of the sub-part in which an Entity has been set if it is not in a sub-part (or not loaded at all), Returns 0", py::arg("ent"));
cls_IFGraph_SubPartsIterator.def("Start", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Start, "Sets iteration to its beginning; calls Evaluate");
cls_IFGraph_SubPartsIterator.def("More", (Standard_Boolean (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::More, "Returns True if there are more sub-parts to iterate on Note : an empty sub-part is not taken in account by Iteration");
cls_IFGraph_SubPartsIterator.def("Next", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Next, "Sets iteration to the next sub-part if there is not, IsSingle-Entities will raises an exception");
cls_IFGraph_SubPartsIterator.def("IsSingle", (Standard_Boolean (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::IsSingle, "Returns True if current sub-part is single (has only one Entity) Error if there is no sub-part to iterate now");
cls_IFGraph_SubPartsIterator.def("FirstEntity", (opencascade::handle<Standard_Transient> (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::FirstEntity, "Returns the first entity of current sub-part, that is for a Single one, the only one it contains Error : same as above (end of iteration)");
cls_IFGraph_SubPartsIterator.def("Entities", (Interface_EntityIterator (IFGraph_SubPartsIterator::*)() const) &IFGraph_SubPartsIterator::Entities, "Returns current sub-part, not as a 'Value', but as an Iterator on Entities it contains Error : same as above (end of iteration)");

// Enums

}