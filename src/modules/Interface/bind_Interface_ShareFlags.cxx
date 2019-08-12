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
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_GTool.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_BitMap.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_ShareFlags.hxx>

void bind_Interface_ShareFlags(py::module &mod){

py::class_<Interface_ShareFlags, std::unique_ptr<Interface_ShareFlags, Deleter<Interface_ShareFlags>>> cls_Interface_ShareFlags(mod, "Interface_ShareFlags", "This class only says for each Entity of a Model, if it is Shared or not by one or more other(s) of this Model It uses the General Service 'Shared'.");

// Constructors
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_ShareFlags.def(py::init<const Interface_Graph &>(), py::arg("agraph"));

// Fields

// Methods
// cls_Interface_ShareFlags.def_static("operator new_", (void * (*)(size_t)) &Interface_ShareFlags::operator new, "None", py::arg("theSize"));
// cls_Interface_ShareFlags.def_static("operator delete_", (void (*)(void *)) &Interface_ShareFlags::operator delete, "None", py::arg("theAddress"));
// cls_Interface_ShareFlags.def_static("operator new[]_", (void * (*)(size_t)) &Interface_ShareFlags::operator new[], "None", py::arg("theSize"));
// cls_Interface_ShareFlags.def_static("operator delete[]_", (void (*)(void *)) &Interface_ShareFlags::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_ShareFlags.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_ShareFlags::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_ShareFlags.def_static("operator delete_", (void (*)(void *, void *)) &Interface_ShareFlags::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_ShareFlags.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_ShareFlags::*)() const) &Interface_ShareFlags::Model, "Returns the Model used for the evaluation");
cls_Interface_ShareFlags.def("IsShared", (Standard_Boolean (Interface_ShareFlags::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareFlags::IsShared, "Returns True if <ent> is Shared by one or more other Entity(ies) of the Model", py::arg("ent"));
cls_Interface_ShareFlags.def("RootEntities", (Interface_EntityIterator (Interface_ShareFlags::*)() const) &Interface_ShareFlags::RootEntities, "Returns the Entities which are not Shared (see their flags)");
cls_Interface_ShareFlags.def("NbRoots", (Standard_Integer (Interface_ShareFlags::*)() const) &Interface_ShareFlags::NbRoots, "Returns the count of root entities");
cls_Interface_ShareFlags.def("Root", [](Interface_ShareFlags &self) -> opencascade::handle<Standard_Transient> { return self.Root(); });
cls_Interface_ShareFlags.def("Root", (opencascade::handle<Standard_Transient> (Interface_ShareFlags::*)(const Standard_Integer) const) &Interface_ShareFlags::Root, "Returns a root entity according its rank in the list of roots By default, it returns the first one", py::arg("num"));

// Enums

}