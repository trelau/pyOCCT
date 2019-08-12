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
#include <IFSelect_SignCounter.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SelectDeduct.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_GraphCounter.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_GraphCounter(py::module &mod){

py::class_<IFSelect_GraphCounter, opencascade::handle<IFSelect_GraphCounter>, IFSelect_SignCounter> cls_IFSelect_GraphCounter(mod, "IFSelect_GraphCounter", "A GraphCounter computes values to be sorted with the help of a Graph. I.E. not from a Signature");

// Constructors
cls_IFSelect_GraphCounter.def(py::init<>());
cls_IFSelect_GraphCounter.def(py::init<const Standard_Boolean>(), py::arg("withmap"));
cls_IFSelect_GraphCounter.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("withmap"), py::arg("withlist"));

// Fields

// Methods
cls_IFSelect_GraphCounter.def("Applied", (opencascade::handle<IFSelect_SelectDeduct> (IFSelect_GraphCounter::*)() const) &IFSelect_GraphCounter::Applied, "Returns the applied selection");
cls_IFSelect_GraphCounter.def("SetApplied", (void (IFSelect_GraphCounter::*)(const opencascade::handle<IFSelect_SelectDeduct> &)) &IFSelect_GraphCounter::SetApplied, "Sets a new applied selection", py::arg("sel"));
cls_IFSelect_GraphCounter.def("AddWithGraph", (void (IFSelect_GraphCounter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Interface_Graph &)) &IFSelect_GraphCounter::AddWithGraph, "Adds a list of entities in the context given by the graph Default takes the count of entities selected by the applied selection, when it is given each entity of the list Can be redefined", py::arg("list"), py::arg("graph"));
cls_IFSelect_GraphCounter.def_static("get_type_name_", (const char * (*)()) &IFSelect_GraphCounter::get_type_name, "None");
cls_IFSelect_GraphCounter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_GraphCounter::get_type_descriptor, "None");
cls_IFSelect_GraphCounter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_GraphCounter::*)() const) &IFSelect_GraphCounter::DynamicType, "None");

// Enums

}