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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESBasic_SingularSubfigure.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_SingularSubfigure(py::module &mod){

py::class_<IGESBasic_SingularSubfigure, opencascade::handle<IGESBasic_SingularSubfigure>, IGESData_IGESEntity> cls_IGESBasic_SingularSubfigure(mod, "IGESBasic_SingularSubfigure", "defines SingularSubfigure, Type <408> Form <0> in package IGESBasic Defines the occurrence of a single instance of the defined Subfigure.");

// Constructors
cls_IGESBasic_SingularSubfigure.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_SingularSubfigure.def("Init", (void (IGESBasic_SingularSubfigure::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, const gp_XYZ &, const Standard_Boolean, const Standard_Real)) &IGESBasic_SingularSubfigure::Init, "This method is used to set the fields of the class SingularSubfigure - aSubfigureDef : the Subfigure Definition entity - aTranslation : used to store the X,Y,Z coord - hasScale : Indicates the presence of scale factor - aScale : Used to store the scale factor", py::arg("aSubfigureDef"), py::arg("aTranslation"), py::arg("hasScale"), py::arg("aScale"));
cls_IGESBasic_SingularSubfigure.def("Subfigure", (opencascade::handle<IGESBasic_SubfigureDef> (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::Subfigure, "returns the subfigure definition entity");
cls_IGESBasic_SingularSubfigure.def("Translation", (gp_XYZ (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::Translation, "returns the X, Y, Z coordinates");
cls_IGESBasic_SingularSubfigure.def("ScaleFactor", (Standard_Real (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::ScaleFactor, "returns the scale factor if hasScaleFactor is False, returns 1.0 (default)");
cls_IGESBasic_SingularSubfigure.def("HasScaleFactor", (Standard_Boolean (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::HasScaleFactor, "returns a boolean indicating whether scale factor is present or not");
cls_IGESBasic_SingularSubfigure.def("TransformedTranslation", (gp_XYZ (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::TransformedTranslation, "returns the Translation after transformation");
cls_IGESBasic_SingularSubfigure.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SingularSubfigure::get_type_name, "None");
cls_IGESBasic_SingularSubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SingularSubfigure::get_type_descriptor, "None");
cls_IGESBasic_SingularSubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::DynamicType, "None");

// Enums

}