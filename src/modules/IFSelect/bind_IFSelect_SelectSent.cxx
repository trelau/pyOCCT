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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectSent.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectSent(py::module &mod){

py::class_<IFSelect_SelectSent, opencascade::handle<IFSelect_SelectSent>, IFSelect_SelectExtract> cls_IFSelect_SelectSent(mod, "IFSelect_SelectSent", "This class returns entities according sending to a file Once a model has been loaded, further sendings are recorded as status in the graph (for each value, a count of sendings)");

// Constructors
cls_IFSelect_SelectSent.def(py::init<>());
cls_IFSelect_SelectSent.def(py::init<const Standard_Integer>(), py::arg("sentcount"));
cls_IFSelect_SelectSent.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("sentcount"), py::arg("atleast"));

// Fields

// Methods
cls_IFSelect_SelectSent.def("SentCount", (Standard_Integer (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::SentCount, "Returns the queried count of sending");
cls_IFSelect_SelectSent.def("AtLeast", (Standard_Boolean (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::AtLeast, "Returns the <atleast> status, True for sending at least the sending count, False for sending exactly the sending count Remark : if SentCount is 0, AtLeast is ignored");
cls_IFSelect_SelectSent.def("RootResult", (Interface_EntityIterator (IFSelect_SelectSent::*)(const Interface_Graph &) const) &IFSelect_SelectSent::RootResult, "Returns the list of selected entities. It is redefined to work on the graph itself (not queried by sort)", py::arg("G"));
cls_IFSelect_SelectSent.def("Sort", (Standard_Boolean (IFSelect_SelectSent::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectSent::Sort, "Returns always False because RootResult has done the work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectSent.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::ExtractLabel, "Returns a text defining the criterium : query : SentCount = 0 -> 'Remaining (non-sent) entities' SentCount = 1, AtLeast = True -> 'Sent entities' SentCount = 1, AtLeast = False -> 'Sent once (no duplicated)' SentCount = 2, AtLeast = True -> 'Sent several times entities' SentCount = 2, AtLeast = False -> 'Sent twice entities' SentCount > 2, AtLeast = True -> 'Sent at least <count> times entities' SentCount > 2, AtLeast = False -> 'Sent <count> times entities'");
cls_IFSelect_SelectSent.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSent::get_type_name, "None");
cls_IFSelect_SelectSent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSent::get_type_descriptor, "None");
cls_IFSelect_SelectSent.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::DynamicType, "None");

// Enums

}