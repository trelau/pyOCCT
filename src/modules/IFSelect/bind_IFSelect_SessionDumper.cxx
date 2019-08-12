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
#include <IFSelect_SessionDumper.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_SessionFile.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SessionDumper(py::module &mod){

py::class_<IFSelect_SessionDumper, opencascade::handle<IFSelect_SessionDumper>, Standard_Transient> cls_IFSelect_SessionDumper(mod, "IFSelect_SessionDumper", "A SessionDumper is called by SessionFile. It takes into account a set of classes (such as Selections, Dispatches ...). SessionFile writes the Type (as defined by cdl) of each Item and its general Parameters. It manages the names of the Items.");

// Fields

// Methods
cls_IFSelect_SessionDumper.def_static("First_", (opencascade::handle<IFSelect_SessionDumper> (*)()) &IFSelect_SessionDumper::First, "Returns the First item of the Library of Dumper. The Next ones are then obtained by Next on the returned items");
cls_IFSelect_SessionDumper.def("Next", (opencascade::handle<IFSelect_SessionDumper> (IFSelect_SessionDumper::*)() const) &IFSelect_SessionDumper::Next, "Returns the Next SesionDumper in the Library. Returns a Null Handle at the End.");
cls_IFSelect_SessionDumper.def("WriteOwn", (Standard_Boolean (IFSelect_SessionDumper::*)(IFSelect_SessionFile &, const opencascade::handle<Standard_Transient> &) const) &IFSelect_SessionDumper::WriteOwn, "Writes the Own Parameters of a given Item, if it forecast to manage its Type. Returns True if it has recognized the Type of the Item (in this case, it is assumed to have written the Own Parameters if there are some), False else : in that case, SessionFile will try another SessionDumper in the Library. WriteOwn can use these methods from SessionFile : SendVoid, SendItem, SendText, and if necessary, WorkSession.", py::arg("file"), py::arg("item"));
cls_IFSelect_SessionDumper.def("ReadOwn", (Standard_Boolean (IFSelect_SessionDumper::*)(IFSelect_SessionFile &, const TCollection_AsciiString &, opencascade::handle<Standard_Transient> &) const) &IFSelect_SessionDumper::ReadOwn, "Recognizes a Type (given as <type>) then Creates an Item of this Type with the Own Parameter, as required. Returns True if it has recognized the Type (in this case, it is assumed to have created the Item, returned as <item>), False else : in that case, SessionFile will try another SessionDumper in the Library. ReadOwn can use these methods from SessionFile to access Own Parameters : NbOwnParams, IsVoid, IsText, TextValue, ItemValue", py::arg("file"), py::arg("type"), py::arg("item"));
cls_IFSelect_SessionDumper.def_static("get_type_name_", (const char * (*)()) &IFSelect_SessionDumper::get_type_name, "None");
cls_IFSelect_SessionDumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SessionDumper::get_type_descriptor, "None");
cls_IFSelect_SessionDumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SessionDumper::*)() const) &IFSelect_SessionDumper::DynamicType, "None");

// Enums

}