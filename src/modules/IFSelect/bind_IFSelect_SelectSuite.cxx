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
#include <IFSelect_SelectDeduct.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_Selection.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectSuite.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>

void bind_IFSelect_SelectSuite(py::module &mod){

py::class_<IFSelect_SelectSuite, opencascade::handle<IFSelect_SelectSuite>, IFSelect_SelectDeduct> cls_IFSelect_SelectSuite(mod, "IFSelect_SelectSuite", "A SelectSuite can describe a suite of SelectDeduct as a unique one : in other words, it can be seen as a 'macro selection'");

// Constructors
cls_IFSelect_SelectSuite.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectSuite.def("AddInput", (Standard_Boolean (IFSelect_SelectSuite::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectSuite::AddInput, "Adds an input selection. I.E. : If <item> is a SelectDeduct, adds it as Previous, not as Input Else, sets it as Input Returns True when done Returns False and refuses to work if Input is already defined", py::arg("item"));
cls_IFSelect_SelectSuite.def("AddPrevious", (void (IFSelect_SelectSuite::*)(const opencascade::handle<IFSelect_SelectDeduct> &)) &IFSelect_SelectSuite::AddPrevious, "Adds a new first item (prepends to the list). The Input is not touched If <item> is null, does nothing", py::arg("item"));
cls_IFSelect_SelectSuite.def("AddNext", (void (IFSelect_SelectSuite::*)(const opencascade::handle<IFSelect_SelectDeduct> &)) &IFSelect_SelectSuite::AddNext, "Adds a new last item (prepends to the list) If <item> is null, does nothing", py::arg("item"));
cls_IFSelect_SelectSuite.def("NbItems", (Standard_Integer (IFSelect_SelectSuite::*)() const) &IFSelect_SelectSuite::NbItems, "Returns the count of Items");
cls_IFSelect_SelectSuite.def("Item", (opencascade::handle<IFSelect_SelectDeduct> (IFSelect_SelectSuite::*)(const Standard_Integer) const) &IFSelect_SelectSuite::Item, "Returns an item from its rank in the list (the Input is always apart)", py::arg("num"));
cls_IFSelect_SelectSuite.def("SetLabel", (void (IFSelect_SelectSuite::*)(const Standard_CString)) &IFSelect_SelectSuite::SetLabel, "Sets a value for the Label", py::arg("lab"));
cls_IFSelect_SelectSuite.def("RootResult", (Interface_EntityIterator (IFSelect_SelectSuite::*)(const Interface_Graph &) const) &IFSelect_SelectSuite::RootResult, "Returns the list of selected entities To do this, once InputResult has been taken (if Input or Alternate has been defined, else the first Item gives it) : this result is set as alternate input for the first item, which computes its result : this result is set as alternate input for the second item, etc...", py::arg("G"));
cls_IFSelect_SelectSuite.def("Label", (TCollection_AsciiString (IFSelect_SelectSuite::*)() const) &IFSelect_SelectSuite::Label, "Returns the Label Either it has been defined by SetLabel, or it will give 'Suite of nn Selections'");
cls_IFSelect_SelectSuite.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSuite::get_type_name, "None");
cls_IFSelect_SelectSuite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSuite::get_type_descriptor, "None");
cls_IFSelect_SelectSuite.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSuite::*)() const) &IFSelect_SelectSuite::DynamicType, "None");

// Enums

}