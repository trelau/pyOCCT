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
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_GTool.hxx>
#include <Interface_HGraph.hxx>
#include <Standard_Type.hxx>

void bind_Interface_HGraph(py::module &mod){

py::class_<Interface_HGraph, opencascade::handle<Interface_HGraph>, Standard_Transient> cls_Interface_HGraph(mod, "Interface_HGraph", "This class allows to store a redefinable Graph, via a Handle (usefull for an Object which can work on several successive Models, with the same general conditions)");

// Constructors
cls_Interface_HGraph.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &, const Standard_Boolean>(), py::arg("amodel"), py::arg("lib"), py::arg("theModeStats"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("protocol"), py::arg("theModeStats"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("gtool"), py::arg("theModeStats"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("theModeStats"));

// Fields

// Methods
cls_Interface_HGraph.def("Graph", (const Interface_Graph & (Interface_HGraph::*)() const) &Interface_HGraph::Graph, "Returns the Graph contained in <me>, for Read Only Operations Remark that it is returns as 'const &' Getting it in a new variable instead of a reference would be a pitty, because all the graph's content would be duplicated");
cls_Interface_HGraph.def("CGraph", (Interface_Graph & (Interface_HGraph::*)()) &Interface_HGraph::CGraph, "Same as above, but for Read-Write Operations Then, The Graph will be modified in the HGraph itself");
cls_Interface_HGraph.def_static("get_type_name_", (const char * (*)()) &Interface_HGraph::get_type_name, "None");
cls_Interface_HGraph.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_HGraph::get_type_descriptor, "None");
cls_Interface_HGraph.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_HGraph::*)() const) &Interface_HGraph::DynamicType, "None");

// Enums

}