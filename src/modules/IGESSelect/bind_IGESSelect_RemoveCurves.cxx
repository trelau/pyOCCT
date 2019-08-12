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
#include <IGESSelect_ModelModifier.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_RemoveCurves.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_RemoveCurves(py::module &mod){

py::class_<IGESSelect_RemoveCurves, opencascade::handle<IGESSelect_RemoveCurves>, IGESSelect_ModelModifier> cls_IGESSelect_RemoveCurves(mod, "IGESSelect_RemoveCurves", "Removes Curves UV or 3D (not both !) from Faces, those designated by the Selection. No Selection means all the file");

// Constructors
cls_IGESSelect_RemoveCurves.def(py::init<const Standard_Boolean>(), py::arg("UV"));

// Fields

// Methods
cls_IGESSelect_RemoveCurves.def("Performing", (void (IGESSelect_RemoveCurves::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_RemoveCurves::Performing, "Specific action : Removes the Curves", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_RemoveCurves.def("Label", (TCollection_AsciiString (IGESSelect_RemoveCurves::*)() const) &IGESSelect_RemoveCurves::Label, "Returns a text which is 'Remove Curves UV on Face' or 'Remove Curves 3D on Face'");
cls_IGESSelect_RemoveCurves.def_static("get_type_name_", (const char * (*)()) &IGESSelect_RemoveCurves::get_type_name, "None");
cls_IGESSelect_RemoveCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_RemoveCurves::get_type_descriptor, "None");
cls_IGESSelect_RemoveCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_RemoveCurves::*)() const) &IGESSelect_RemoveCurves::DynamicType, "None");

// Enums

}