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
#include <IFGraph_AllConnected.hxx>

void bind_IFGraph_AllConnected(py::module &mod){

py::class_<IFGraph_AllConnected, std::unique_ptr<IFGraph_AllConnected, Deleter<IFGraph_AllConnected>>, Interface_GraphContent> cls_IFGraph_AllConnected(mod, "IFGraph_AllConnected", "this class gives content of the CONNECTED COMPONANT(S) which include specific Entity(ies)");

// Constructors
cls_IFGraph_AllConnected.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_IFGraph_AllConnected.def(py::init<const Interface_Graph &, const opencascade::handle<Standard_Transient> &>(), py::arg("agraph"), py::arg("ent"));

// Fields

// Methods
// cls_IFGraph_AllConnected.def_static("operator new_", (void * (*)(size_t)) &IFGraph_AllConnected::operator new, "None", py::arg("theSize"));
// cls_IFGraph_AllConnected.def_static("operator delete_", (void (*)(void *)) &IFGraph_AllConnected::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_AllConnected.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_AllConnected::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_AllConnected.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_AllConnected::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_AllConnected.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_AllConnected::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_AllConnected.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_AllConnected::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_AllConnected.def("GetFromEntity", (void (IFGraph_AllConnected::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_AllConnected::GetFromEntity, "adds an entity and its Connected ones to the list (allows to cumulate all Entities Connected by some ones) Note that if 'ent' is in the already computed list,, no entity will be added, but if 'ent' is not already in the list, a new Connected Componant will be cumulated", py::arg("ent"));
cls_IFGraph_AllConnected.def("ResetData", (void (IFGraph_AllConnected::*)()) &IFGraph_AllConnected::ResetData, "Allows to restart on a new data set");
cls_IFGraph_AllConnected.def("Evaluate", (void (IFGraph_AllConnected::*)()) &IFGraph_AllConnected::Evaluate, "does the specific evaluation (Connected entities atall levels)");

// Enums

}