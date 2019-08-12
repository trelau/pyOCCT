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
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <IFSelect_SelectControl.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectControl(py::module &mod){

py::class_<IFSelect_SelectControl, opencascade::handle<IFSelect_SelectControl>, IFSelect_Selection> cls_IFSelect_SelectControl(mod, "IFSelect_SelectControl", "A SelectControl kind Selection works with two input Selections in a dissymmetric way : the Main Input which gives an input list of Entities, to be processed, and the Second Input which gives another list, to be used to filter the main input.");

// Fields

// Methods
cls_IFSelect_SelectControl.def("MainInput", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::MainInput, "Returns the Main Input Selection");
cls_IFSelect_SelectControl.def("HasSecondInput", (Standard_Boolean (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::HasSecondInput, "Returns True if a Control Input is defined Thus, Result can be computed differently if there is a Control Input or if there is none");
cls_IFSelect_SelectControl.def("SecondInput", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::SecondInput, "Returns the Control Input Selection, or a Null Handle");
cls_IFSelect_SelectControl.def("SetMainInput", (void (IFSelect_SelectControl::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectControl::SetMainInput, "Sets a Selection to be the Main Input", py::arg("sel"));
cls_IFSelect_SelectControl.def("SetSecondInput", (void (IFSelect_SelectControl::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectControl::SetSecondInput, "Sets a Selection to be the Control Input", py::arg("sel"));
cls_IFSelect_SelectControl.def("FillIterator", (void (IFSelect_SelectControl::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectControl::FillIterator, "Puts in an Iterator the Selections from which 'me' depends That is to say, the list of Input Selections", py::arg("iter"));
cls_IFSelect_SelectControl.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectControl::get_type_name, "None");
cls_IFSelect_SelectControl.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectControl::get_type_descriptor, "None");
cls_IFSelect_SelectControl.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::DynamicType, "None");

// Enums

}