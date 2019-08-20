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
#include <Interface_EntityIterator.hxx>
#include <Standard.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_GraphContent.hxx>

void bind_Interface_GraphContent(py::module &mod){

py::class_<Interface_GraphContent, std::unique_ptr<Interface_GraphContent>, Interface_EntityIterator> cls_Interface_GraphContent(mod, "Interface_GraphContent", "Defines general form for classes of graph algorithms on Interfaces, this form is that of EntityIterator Each sub-class fills it according to its own algorithm This also allows to combine any graph result to others, all being given under one unique form");

// Constructors
cls_Interface_GraphContent.def(py::init<>());
cls_Interface_GraphContent.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_GraphContent.def(py::init<const Interface_Graph &, const Standard_Integer>(), py::arg("agraph"), py::arg("stat"));
cls_Interface_GraphContent.def(py::init<const Interface_Graph &, const opencascade::handle<Standard_Transient> &>(), py::arg("agraph"), py::arg("ent"));

// Fields

// Methods
// cls_Interface_GraphContent.def_static("operator new_", (void * (*)(size_t)) &Interface_GraphContent::operator new, "None", py::arg("theSize"));
// cls_Interface_GraphContent.def_static("operator delete_", (void (*)(void *)) &Interface_GraphContent::operator delete, "None", py::arg("theAddress"));
// cls_Interface_GraphContent.def_static("operator new[]_", (void * (*)(size_t)) &Interface_GraphContent::operator new[], "None", py::arg("theSize"));
// cls_Interface_GraphContent.def_static("operator delete[]_", (void (*)(void *)) &Interface_GraphContent::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_GraphContent.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_GraphContent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_GraphContent.def_static("operator delete_", (void (*)(void *, void *)) &Interface_GraphContent::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_GraphContent.def("GetFromGraph", (void (Interface_GraphContent::*)(const Interface_Graph &)) &Interface_GraphContent::GetFromGraph, "Gets all Entities designated by a Graph (once created), adds them to those already recorded", py::arg("agraph"));
cls_Interface_GraphContent.def("GetFromGraph", (void (Interface_GraphContent::*)(const Interface_Graph &, const Standard_Integer)) &Interface_GraphContent::GetFromGraph, "Gets entities from a graph which have a specific Status value (one created), adds them to those already recorded", py::arg("agraph"), py::arg("stat"));
cls_Interface_GraphContent.def("Result", (Interface_EntityIterator (Interface_GraphContent::*)()) &Interface_GraphContent::Result, "Returns Result under the exact form of an EntityIterator : Can be used when EntityIterator itself is required (as a returned value for instance), whitout way for a sub-class");
cls_Interface_GraphContent.def("Begin", (void (Interface_GraphContent::*)()) &Interface_GraphContent::Begin, "Does the Evaluation before starting the iteration itself (in out)");
cls_Interface_GraphContent.def("Evaluate", (void (Interface_GraphContent::*)()) &Interface_GraphContent::Evaluate, "Evaluates list of Entities to be iterated. Called by Start Default is set to doing nothing : intended to be redefined by each sub-class");

// Enums

}