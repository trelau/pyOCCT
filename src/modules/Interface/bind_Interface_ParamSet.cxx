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
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <Interface_FileParameter.hxx>
#include <Standard_Handle.hxx>
#include <Interface_ParamList.hxx>
#include <Interface_ParamSet.hxx>
#include <Standard_Type.hxx>
#include <Standard_PCharacter.hxx>

void bind_Interface_ParamSet(py::module &mod){

py::class_<Interface_ParamSet, opencascade::handle<Interface_ParamSet>, Standard_Transient> cls_Interface_ParamSet(mod, "Interface_ParamSet", "Defines an ordered set of FileParameters, in a way to be efficient as in memory requirement or in speed");

// Constructors
cls_Interface_ParamSet.def(py::init<const Standard_Integer>(), py::arg("nres"));
cls_Interface_ParamSet.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nres"), py::arg("nst"));

// Fields

// Methods
cls_Interface_ParamSet.def("Append", (Standard_Integer (Interface_ParamSet::*)(const Standard_CString, const Standard_Integer, const Interface_ParamType, const Standard_Integer)) &Interface_ParamSet::Append, "Adds a parameter defined as its Value (CString and length) and Type. Optionnal EntityNumber (for FileReaderData) can be given Allows a better memory management than Appending a complete FileParameter If <lnval> < 0, <val> is assumed to be managed elsewhere : its adress is stored as such. Else, <val> is copied in a locally (quickly) managed Page of Characters Returns new count of recorded Parameters", py::arg("val"), py::arg("lnval"), py::arg("typ"), py::arg("nument"));
cls_Interface_ParamSet.def("Append", (Standard_Integer (Interface_ParamSet::*)(const Interface_FileParameter &)) &Interface_ParamSet::Append, "Adds a parameter at the end of the ParamSet (transparent about reservation and 'Next') Returns new count of recorded Parameters", py::arg("FP"));
cls_Interface_ParamSet.def("NbParams", (Standard_Integer (Interface_ParamSet::*)() const) &Interface_ParamSet::NbParams, "Returns the total count of parameters (including nexts)");
cls_Interface_ParamSet.def("Param", (const Interface_FileParameter & (Interface_ParamSet::*)(const Standard_Integer) const) &Interface_ParamSet::Param, "Returns a parameter identified by its number", py::arg("num"));
cls_Interface_ParamSet.def("ChangeParam", (Interface_FileParameter & (Interface_ParamSet::*)(const Standard_Integer)) &Interface_ParamSet::ChangeParam, "Same as above, but in order to be modified on place", py::arg("num"));
cls_Interface_ParamSet.def("SetParam", (void (Interface_ParamSet::*)(const Standard_Integer, const Interface_FileParameter &)) &Interface_ParamSet::SetParam, "Changes a parameter identified by its number", py::arg("num"), py::arg("FP"));
cls_Interface_ParamSet.def("Params", (opencascade::handle<Interface_ParamList> (Interface_ParamSet::*)(const Standard_Integer, const Standard_Integer) const) &Interface_ParamSet::Params, "Builds and returns the sub-list correspinding to parameters, from 'num' included, with count 'nb' If <num> and <nb> are zero, returns the whole list", py::arg("num"), py::arg("nb"));
cls_Interface_ParamSet.def("Destroy", (void (Interface_ParamSet::*)()) &Interface_ParamSet::Destroy, "Destructor (waiting for transparent memory management)");
cls_Interface_ParamSet.def_static("get_type_name_", (const char * (*)()) &Interface_ParamSet::get_type_name, "None");
cls_Interface_ParamSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ParamSet::get_type_descriptor, "None");
cls_Interface_ParamSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ParamSet::*)() const) &Interface_ParamSet::DynamicType, "None");

// Enums

}