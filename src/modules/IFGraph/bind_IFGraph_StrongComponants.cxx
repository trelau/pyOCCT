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
#include <IFGraph_SubPartsIterator.hxx>
#include <Standard.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <IFGraph_StrongComponants.hxx>

void bind_IFGraph_StrongComponants(py::module &mod){

py::class_<IFGraph_StrongComponants, std::unique_ptr<IFGraph_StrongComponants>, IFGraph_SubPartsIterator> cls_IFGraph_StrongComponants(mod, "IFGraph_StrongComponants", "determines strong componants of a graph, that is isolated entities (single componants) or loops");

// Constructors
cls_IFGraph_StrongComponants.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));

// Fields

// Methods
// cls_IFGraph_StrongComponants.def_static("operator new_", (void * (*)(size_t)) &IFGraph_StrongComponants::operator new, "None", py::arg("theSize"));
// cls_IFGraph_StrongComponants.def_static("operator delete_", (void (*)(void *)) &IFGraph_StrongComponants::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_StrongComponants.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_StrongComponants::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_StrongComponants.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_StrongComponants::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_StrongComponants.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_StrongComponants::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_StrongComponants.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_StrongComponants::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_StrongComponants.def("Evaluate", (void (IFGraph_StrongComponants::*)()) &IFGraph_StrongComponants::Evaluate, "does the computation");

// Enums

}