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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_IntParam.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SelectLevelNumber.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectLevelNumber(py::module &mod){

py::class_<IGESSelect_SelectLevelNumber, opencascade::handle<IGESSelect_SelectLevelNumber>, IFSelect_SelectExtract> cls_IGESSelect_SelectLevelNumber(mod, "IGESSelect_SelectLevelNumber", "This selection looks at Level Number of IGES Entities : it considers items attached, either to a single level with a given value, or to a level list which contains this value");

// Constructors
cls_IGESSelect_SelectLevelNumber.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectLevelNumber.def("SetLevelNumber", (void (IGESSelect_SelectLevelNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_SelectLevelNumber::SetLevelNumber, "Sets a Parameter as Level criterium", py::arg("levnum"));
cls_IGESSelect_SelectLevelNumber.def("LevelNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_SelectLevelNumber::*)() const) &IGESSelect_SelectLevelNumber::LevelNumber, "Returns the Level criterium. NullHandle if not yet set (interpreted as Level = 0 : no level number attached)");
cls_IGESSelect_SelectLevelNumber.def("Sort", (Standard_Boolean (IGESSelect_SelectLevelNumber::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectLevelNumber::Sort, "Returns True if <ent> is an IGES Entity with Level Number admits the criterium (= value if single level, or one of the attached level numbers = value if level list)", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectLevelNumber.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectLevelNumber::*)() const) &IGESSelect_SelectLevelNumber::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Level Number admits <nn>' (if nn > 0) or 'IGES Entity attached to no Level' (if nn = 0)");
cls_IGESSelect_SelectLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectLevelNumber::get_type_name, "None");
cls_IGESSelect_SelectLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_SelectLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectLevelNumber::*)() const) &IGESSelect_SelectLevelNumber::DynamicType, "None");

// Enums

}