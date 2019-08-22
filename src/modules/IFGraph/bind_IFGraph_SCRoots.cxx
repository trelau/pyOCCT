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
#include <IFGraph_StrongComponants.hxx>
#include <Standard.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <IFGraph_SCRoots.hxx>

void bind_IFGraph_SCRoots(py::module &mod){

py::class_<IFGraph_SCRoots, IFGraph_StrongComponants> cls_IFGraph_SCRoots(mod, "IFGraph_SCRoots", "determines strong componants in a graph which are Roots");

// Constructors
cls_IFGraph_SCRoots.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
cls_IFGraph_SCRoots.def(py::init<IFGraph_StrongComponants &>(), py::arg("subparts"));

// Fields

// Methods
// cls_IFGraph_SCRoots.def_static("operator new_", (void * (*)(size_t)) &IFGraph_SCRoots::operator new, "None", py::arg("theSize"));
// cls_IFGraph_SCRoots.def_static("operator delete_", (void (*)(void *)) &IFGraph_SCRoots::operator delete, "None", py::arg("theAddress"));
// cls_IFGraph_SCRoots.def_static("operator new[]_", (void * (*)(size_t)) &IFGraph_SCRoots::operator new[], "None", py::arg("theSize"));
// cls_IFGraph_SCRoots.def_static("operator delete[]_", (void (*)(void *)) &IFGraph_SCRoots::operator delete[], "None", py::arg("theAddress"));
// cls_IFGraph_SCRoots.def_static("operator new_", (void * (*)(size_t, void *)) &IFGraph_SCRoots::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFGraph_SCRoots.def_static("operator delete_", (void (*)(void *, void *)) &IFGraph_SCRoots::operator delete, "None", py::arg(""), py::arg(""));
cls_IFGraph_SCRoots.def("Evaluate", (void (IFGraph_SCRoots::*)()) &IFGraph_SCRoots::Evaluate, "does the computation");

// Enums

}