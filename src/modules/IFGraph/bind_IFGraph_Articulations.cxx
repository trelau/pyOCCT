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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <IFGraph_Articulations.hxx>

void bind_IFGraph_Articulations(py::module &mod){

py::class_<IFGraph_Articulations, std::unique_ptr<IFGraph_Articulations>, Interface_GraphContent> cls_IFGraph_Articulations(mod, "IFGraph_Articulations", "this class gives entities which are Articulation points in a whole Model or in a sub-part An Articulation Point divides the graph in two (or more) disconnected sub-graphs Identifying Articulation Points allows improving efficiency of spliting a set of Entities into sub-sets");

// Constructors
cls_IFGraph_Articulations.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));

// Fields

// Methods
// cls_IFGraph_Articulations.def_static("operator new_", (void * (*)(size_t)) &IFGraph_Articulations::operator new, "None", py::arg("theSize"));
// cls_IFGraph_Articulations.def_static("operator delete_", (void (*)(void *)) &IFGraph_Articulations::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_Articulations.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_Articulations::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_Articulations.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_Articulations::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_Articulations.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_Articulations::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_Articulations.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_Articulations::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_Articulations.def("GetFromEntity", (void (IFGraph_Articulations::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_Articulations::GetFromEntity, "adds an entity and its shared ones to the list", py::arg("ent"));
cls_IFGraph_Articulations.def("GetFromIter", (void (IFGraph_Articulations::*)(const Interface_EntityIterator &)) &IFGraph_Articulations::GetFromIter, "adds a list of entities (as an iterator)", py::arg("iter"));
cls_IFGraph_Articulations.def("ResetData", (void (IFGraph_Articulations::*)()) &IFGraph_Articulations::ResetData, "Allows to restart on a new data set");
cls_IFGraph_Articulations.def("Evaluate", (void (IFGraph_Articulations::*)()) &IFGraph_Articulations::Evaluate, "Evaluates the list of Articulation points");

// Enums

}