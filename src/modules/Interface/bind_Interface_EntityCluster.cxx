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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Interface_EntityCluster.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_EntityList.hxx>
#include <Standard_Type.hxx>

void bind_Interface_EntityCluster(py::module &mod){

py::class_<Interface_EntityCluster, opencascade::handle<Interface_EntityCluster>, Standard_Transient> cls_Interface_EntityCluster(mod, "Interface_EntityCluster", "Auxiliary class for EntityList. An EntityList designates an EntityCluster, which brings itself an fixed maximum count of Entities. If it is full, it gives access to another cluster ('Next'). This class is intended to give a good compromise between access time (faster than a Sequence, good for little count) and memory use (better than a Sequence in any case, overall for little count, better than an Array for a very little count. It is designed for a light management. Remark that a new Item may not be Null, because this is the criterium used for 'End of List'");

// Constructors
cls_Interface_EntityCluster.def(py::init<>());
cls_Interface_EntityCluster.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("ent"));
cls_Interface_EntityCluster.def(py::init<const opencascade::handle<Interface_EntityCluster> &>(), py::arg("ec"));
cls_Interface_EntityCluster.def(py::init<const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_EntityCluster> &>(), py::arg("ant"), py::arg("ec"));

// Fields

// Methods
cls_Interface_EntityCluster.def("Append", (void (Interface_EntityCluster::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityCluster::Append, "Appends an Entity to the Cluster. If it is not full, adds the entity directly inside itself. Else, transmits to its Next and Creates it if it does not yet exist", py::arg("ent"));
cls_Interface_EntityCluster.def("Remove", (Standard_Boolean (Interface_EntityCluster::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityCluster::Remove, "Removes an Entity from the Cluster. If it is not found, calls its Next one to do so. Returns True if it becomes itself empty, False else (thus, a Cluster which becomes empty is deleted from the list)", py::arg("ent"));
cls_Interface_EntityCluster.def("Remove", (Standard_Boolean (Interface_EntityCluster::*)(const Standard_Integer)) &Interface_EntityCluster::Remove, "Removes an Entity from the Cluster, given its rank. If <num> is greater than NbLocal, calls its Next with (num - NbLocal), Returns True if it becomes itself empty, False else", py::arg("num"));
cls_Interface_EntityCluster.def("NbEntities", (Standard_Integer (Interface_EntityCluster::*)() const) &Interface_EntityCluster::NbEntities, "Returns total count of Entities (including Next)");
cls_Interface_EntityCluster.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_EntityCluster::*)(const Standard_Integer) const) &Interface_EntityCluster::Value, "Returns the Entity identified by its rank in the list (including Next)", py::arg("num"));
cls_Interface_EntityCluster.def("SetValue", (void (Interface_EntityCluster::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_EntityCluster::SetValue, "Changes an Entity given its rank.", py::arg("num"), py::arg("ent"));
cls_Interface_EntityCluster.def("FillIterator", (void (Interface_EntityCluster::*)(Interface_EntityIterator &) const) &Interface_EntityCluster::FillIterator, "Fills an Iterator with designated Entities (includes Next)", py::arg("iter"));
cls_Interface_EntityCluster.def_static("get_type_name_", (const char * (*)()) &Interface_EntityCluster::get_type_name, "None");
cls_Interface_EntityCluster.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_EntityCluster::get_type_descriptor, "None");
cls_Interface_EntityCluster.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_EntityCluster::*)() const) &Interface_EntityCluster::DynamicType, "None");

// Enums

}