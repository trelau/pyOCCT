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
#include <IFSelect_Modifier.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ModifReorder.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_ModifReorder(py::module &mod){

py::class_<IFSelect_ModifReorder, opencascade::handle<IFSelect_ModifReorder>, IFSelect_Modifier> cls_IFSelect_ModifReorder(mod, "IFSelect_ModifReorder", "This modifier reorders a whole model from its roots, i.e. according to <rootlast> status, it considers each of its roots, then it orders all its shared entities at any level, the result begins by the lower level entities ... ends by the roots.");

// Constructors
cls_IFSelect_ModifReorder.def(py::init<>());
cls_IFSelect_ModifReorder.def(py::init<const Standard_Boolean>(), py::arg("rootlast"));

// Fields

// Methods
cls_IFSelect_ModifReorder.def("Perform", (void (IFSelect_ModifReorder::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IFSelect_ModifReorder::Perform, "Acts by computing orders (by method All from ShareTool) then forcing them in the model. Remark that selection is ignored : ALL the model is processed in once", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IFSelect_ModifReorder.def("Label", (TCollection_AsciiString (IFSelect_ModifReorder::*)() const) &IFSelect_ModifReorder::Label, "Returns Label as 'Reorder, Roots (last or first)'");
cls_IFSelect_ModifReorder.def_static("get_type_name_", (const char * (*)()) &IFSelect_ModifReorder::get_type_name, "None");
cls_IFSelect_ModifReorder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ModifReorder::get_type_descriptor, "None");
cls_IFSelect_ModifReorder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ModifReorder::*)() const) &IFSelect_ModifReorder::DynamicType, "None");

// Enums

}