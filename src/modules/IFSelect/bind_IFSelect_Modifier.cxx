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
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyTool.hxx>
#include <IFSelect_Modifier.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_IFSelect_Modifier(py::module &mod){

py::class_<IFSelect_Modifier, opencascade::handle<IFSelect_Modifier>, IFSelect_GeneralModifier> cls_IFSelect_Modifier(mod, "IFSelect_Modifier", "This class gives a frame for Actions which can work globally on a File once completely defined (i.e. afterwards)");

// Fields

// Methods
cls_IFSelect_Modifier.def("Perform", (void (IFSelect_Modifier::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IFSelect_Modifier::Perform, "This deferred method defines the action specific to each class of Modifier. It is called by a ModelCopier, once the Model generated and filled. ModelCopier has already checked the criteria (Dispatch, Model Rank, Selection) before calling it.", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IFSelect_Modifier.def_static("get_type_name_", (const char * (*)()) &IFSelect_Modifier::get_type_name, "None");
cls_IFSelect_Modifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Modifier::get_type_descriptor, "None");
cls_IFSelect_Modifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Modifier::*)() const) &IFSelect_Modifier::DynamicType, "None");

// Enums

}