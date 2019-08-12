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
#include <TCollection_AsciiString.hxx>
#include <Interface_ParamType.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_PCharacter.hxx>
#include <Interface_FileParameter.hxx>

void bind_Interface_FileParameter(py::module &mod){

py::class_<Interface_FileParameter, std::unique_ptr<Interface_FileParameter, Deleter<Interface_FileParameter>>> cls_Interface_FileParameter(mod, "Interface_FileParameter", "Auxiliary class to store a litteral parameter in a file intermediate directory or in an UndefinedContent : a reference type Parameter detains an Integer which is used to address a record in the directory. FileParameter is intended to be stored in a ParamSet : hence memory management is performed by ParamSet, which calls Clear to work, while the Destructor (see Destroy) does nothing. Also a FileParameter can be read for consultation only, not to be read from a Structure to be included into another one.");

// Constructors
cls_Interface_FileParameter.def(py::init<>());

// Fields

// Methods
// cls_Interface_FileParameter.def_static("operator new_", (void * (*)(size_t)) &Interface_FileParameter::operator new, "None", py::arg("theSize"));
// cls_Interface_FileParameter.def_static("operator delete_", (void (*)(void *)) &Interface_FileParameter::operator delete, "None", py::arg("theAddress"));
// cls_Interface_FileParameter.def_static("operator new[]_", (void * (*)(size_t)) &Interface_FileParameter::operator new[], "None", py::arg("theSize"));
// cls_Interface_FileParameter.def_static("operator delete[]_", (void (*)(void *)) &Interface_FileParameter::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_FileParameter.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_FileParameter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_FileParameter.def_static("operator delete_", (void (*)(void *, void *)) &Interface_FileParameter::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_FileParameter.def("Init", (void (Interface_FileParameter::*)(const TCollection_AsciiString &, const Interface_ParamType)) &Interface_FileParameter::Init, "Fills fields (with Entity Number set to zero)", py::arg("val"), py::arg("typ"));
cls_Interface_FileParameter.def("Init", (void (Interface_FileParameter::*)(const Standard_CString, const Interface_ParamType)) &Interface_FileParameter::Init, "Same as above, but builds the Value from a CString", py::arg("val"), py::arg("typ"));
cls_Interface_FileParameter.def("CValue", (Standard_CString (Interface_FileParameter::*)() const) &Interface_FileParameter::CValue, "Same as above, but as a CString (for immediate exploitation) was C++ : return const");
cls_Interface_FileParameter.def("ParamType", (Interface_ParamType (Interface_FileParameter::*)() const) &Interface_FileParameter::ParamType, "Returns the type of the parameter");
cls_Interface_FileParameter.def("SetEntityNumber", (void (Interface_FileParameter::*)(const Standard_Integer)) &Interface_FileParameter::SetEntityNumber, "Allows to set a reference to an Entity in a numbered list", py::arg("num"));
cls_Interface_FileParameter.def("EntityNumber", (Standard_Integer (Interface_FileParameter::*)() const) &Interface_FileParameter::EntityNumber, "Returns value set by SetEntityNumber");
cls_Interface_FileParameter.def("Clear", (void (Interface_FileParameter::*)()) &Interface_FileParameter::Clear, "Clears stored data : frees memory taken for the String Value");
cls_Interface_FileParameter.def("Destroy", (void (Interface_FileParameter::*)()) &Interface_FileParameter::Destroy, "Destructor. Does nothing because Memory is managed by ParamSet");

// Enums

}