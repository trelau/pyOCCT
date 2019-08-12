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
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_AutoCorrect.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_AutoCorrect(py::module &mod){

py::class_<IGESSelect_AutoCorrect, opencascade::handle<IGESSelect_AutoCorrect>, IGESSelect_ModelModifier> cls_IGESSelect_AutoCorrect(mod, "IGESSelect_AutoCorrect", "Does the absolutely effective corrections on IGES Entity. That is to say : regarding the norm in details, some values have mandatory values, or set of values with constraints. When such values/constraints are univoque, they can be forced. Also nullifies items of Directory Part, Associativities, and Properties, which are not (or not longer) in <target> Model.");

// Constructors
cls_IGESSelect_AutoCorrect.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_AutoCorrect.def("Performing", (void (IGESSelect_AutoCorrect::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_AutoCorrect::Performing, "Specific action : corrects entities when it is absolutely obvious, i.e. non equivoque (by DirChecker and specific service OwnCorrect) : works with a protocol.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_AutoCorrect.def("Label", (TCollection_AsciiString (IGESSelect_AutoCorrect::*)() const) &IGESSelect_AutoCorrect::Label, "Returns a text which is 'Auto-correction of IGES Entities'");
cls_IGESSelect_AutoCorrect.def_static("get_type_name_", (const char * (*)()) &IGESSelect_AutoCorrect::get_type_name, "None");
cls_IGESSelect_AutoCorrect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_AutoCorrect::get_type_descriptor, "None");
cls_IGESSelect_AutoCorrect.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_AutoCorrect::*)() const) &IGESSelect_AutoCorrect::DynamicType, "None");

// Enums

}