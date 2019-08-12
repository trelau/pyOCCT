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
#include <IFSelect_SelectBase.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_IntParam.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectEntityNumber.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectEntityNumber(py::module &mod){

py::class_<IFSelect_SelectEntityNumber, opencascade::handle<IFSelect_SelectEntityNumber>, IFSelect_SelectBase> cls_IFSelect_SelectEntityNumber(mod, "IFSelect_SelectEntityNumber", "A SelectEntityNumber gets in an InterfaceModel (through a Graph), the Entity which has a specified Number (its rank of adding into the Model) : there can be zero (if none) or one. The Number is not directly defined as an Integer, but as a Parameter, which can be externally controled");

// Constructors
cls_IFSelect_SelectEntityNumber.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectEntityNumber.def("SetNumber", (void (IFSelect_SelectEntityNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectEntityNumber::SetNumber, "Sets Entity Number to be taken (initially, none is set : 0)", py::arg("num"));
cls_IFSelect_SelectEntityNumber.def("Number", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectEntityNumber::*)() const) &IFSelect_SelectEntityNumber::Number, "Returns specified Number (as a Parameter)");
cls_IFSelect_SelectEntityNumber.def("RootResult", (Interface_EntityIterator (IFSelect_SelectEntityNumber::*)(const Interface_Graph &) const) &IFSelect_SelectEntityNumber::RootResult, "Returns the list of selected entities : the Entity having the specified Number (this result assures naturally uniqueness)", py::arg("G"));
cls_IFSelect_SelectEntityNumber.def("Label", (TCollection_AsciiString (IFSelect_SelectEntityNumber::*)() const) &IFSelect_SelectEntityNumber::Label, "Returns a text defining the criterium : 'Entity Number ...'");
cls_IFSelect_SelectEntityNumber.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectEntityNumber::get_type_name, "None");
cls_IFSelect_SelectEntityNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectEntityNumber::get_type_descriptor, "None");
cls_IFSelect_SelectEntityNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectEntityNumber::*)() const) &IFSelect_SelectEntityNumber::DynamicType, "None");

// Enums

}