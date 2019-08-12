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
#include <IFSelect_Selection.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <IFSelect_SelectCombine.hxx>
#include <Standard_Type.hxx>
#include <IFSelect_TSeqOfSelection.hxx>

void bind_IFSelect_SelectCombine(py::module &mod){

py::class_<IFSelect_SelectCombine, opencascade::handle<IFSelect_SelectCombine>, IFSelect_Selection> cls_IFSelect_SelectCombine(mod, "IFSelect_SelectCombine", "A SelectCombine type Selection defines algebraic operations between results of several Selections It is a deferred class : sub-classes will have to define precise what operator is to be applied");

// Fields

// Methods
cls_IFSelect_SelectCombine.def("NbInputs", (Standard_Integer (IFSelect_SelectCombine::*)() const) &IFSelect_SelectCombine::NbInputs, "Returns the count of Input Selections");
cls_IFSelect_SelectCombine.def("Input", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectCombine::*)(const Standard_Integer) const) &IFSelect_SelectCombine::Input, "Returns an Input Selection, given its rank in the list", py::arg("num"));
cls_IFSelect_SelectCombine.def("InputRank", (Standard_Integer (IFSelect_SelectCombine::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_SelectCombine::InputRank, "Returns the rank of an input Selection, 0 if not in the list. Most generally, its value is meaningless, except for testing the presence of an input Selection : - == 0 if <sel> is not an input for <me> - > 0 if <sel> is an input for <me>", py::arg("sel"));
cls_IFSelect_SelectCombine.def("Add", [](IFSelect_SelectCombine &self, const opencascade::handle<IFSelect_Selection> & a0) -> void { return self.Add(a0); });
cls_IFSelect_SelectCombine.def("Add", (void (IFSelect_SelectCombine::*)(const opencascade::handle<IFSelect_Selection> &, const Standard_Integer)) &IFSelect_SelectCombine::Add, "Adds a Selection to the filling list By default, adds it to the end of the list A Positive rank less then NbInputs gives an insertion rank (InsertBefore : the new <atnum>th item of the list is <sel>)", py::arg("sel"), py::arg("atnum"));
cls_IFSelect_SelectCombine.def("Remove", (Standard_Boolean (IFSelect_SelectCombine::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectCombine::Remove, "Removes an input Selection. Returns True if Done, False, if <sel> is not an input for <me>", py::arg("sel"));
cls_IFSelect_SelectCombine.def("Remove", (Standard_Boolean (IFSelect_SelectCombine::*)(const Standard_Integer)) &IFSelect_SelectCombine::Remove, "Removes an input Selection, given its rank in the list Returns True if Done, False if <num> is out of range", py::arg("num"));
cls_IFSelect_SelectCombine.def("FillIterator", (void (IFSelect_SelectCombine::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectCombine::FillIterator, "Puts in an Iterator the Selections from which 'me' depends That is to say, the list of Input Selections", py::arg("iter"));
cls_IFSelect_SelectCombine.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectCombine::get_type_name, "None");
cls_IFSelect_SelectCombine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectCombine::get_type_descriptor, "None");
cls_IFSelect_SelectCombine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectCombine::*)() const) &IFSelect_SelectCombine::DynamicType, "None");

// Enums

}