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
#include <IGESDraw_NetworkSubfigureDef.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <IGESDraw_HArray1OfConnectPoint.hxx>
#include <IGESDraw_ConnectPoint.hxx>
#include <IGESDraw_NetworkSubfigure.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_NetworkSubfigure(py::module &mod){

py::class_<IGESDraw_NetworkSubfigure, opencascade::handle<IGESDraw_NetworkSubfigure>, IGESData_IGESEntity> cls_IGESDraw_NetworkSubfigure(mod, "IGESDraw_NetworkSubfigure", "defines IGES Network Subfigure Instance Entity, Type <420> Form Number <0> in package IGESDraw");

// Constructors
cls_IGESDraw_NetworkSubfigure.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_NetworkSubfigure.def("Init", (void (IGESDraw_NetworkSubfigure::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, const gp_XYZ &, const gp_XYZ &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<IGESDraw_HArray1OfConnectPoint> &)) &IGESDraw_NetworkSubfigure::Init, "This method is used to set the fields of the class NetworkSubfigure - aDefinition : Network Subfigure Definition Entity - aTranslation : Translation data relative to the model space or the definition space - aScaleFactor : Scale factors in the definition space - aTypeFlag : Type flag - aDesignator : Primary reference designator - aTemplate : Primary reference designator Text display Template Entity - allConnectPoints : Associated Connect Point Entities", py::arg("aDefinition"), py::arg("aTranslation"), py::arg("aScaleFactor"), py::arg("aTypeFlag"), py::arg("aDesignator"), py::arg("aTemplate"), py::arg("allConnectPoints"));
cls_IGESDraw_NetworkSubfigure.def("SubfigureDefinition", (opencascade::handle<IGESDraw_NetworkSubfigureDef> (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::SubfigureDefinition, "returns Network Subfigure Definition Entity specified by this entity");
cls_IGESDraw_NetworkSubfigure.def("Translation", (gp_XYZ (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::Translation, "returns Translation Data relative to either model space or to the definition space of a referring entity");
cls_IGESDraw_NetworkSubfigure.def("TransformedTranslation", (gp_XYZ (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::TransformedTranslation, "returns the Transformed Translation Data relative to either model space or to the definition space of a referring entity");
cls_IGESDraw_NetworkSubfigure.def("ScaleFactors", (gp_XYZ (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::ScaleFactors, "returns Scale factor in definition space(x, y, z axes)");
cls_IGESDraw_NetworkSubfigure.def("TypeFlag", (Standard_Integer (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::TypeFlag, "returns Type Flag which implements the distinction between Logical design and Physical design data,and is required if both are present. Type Flag = 0 : Not specified (default) = 1 : Logical = 2 : Physical");
cls_IGESDraw_NetworkSubfigure.def("ReferenceDesignator", (opencascade::handle<TCollection_HAsciiString> (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::ReferenceDesignator, "returns the primary reference designator");
cls_IGESDraw_NetworkSubfigure.def("HasDesignatorTemplate", (Standard_Boolean (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::HasDesignatorTemplate, "returns True if Text Display Template Entity is specified, else False");
cls_IGESDraw_NetworkSubfigure.def("DesignatorTemplate", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::DesignatorTemplate, "returns primary reference designator Text Display Template Entity, or null. If null, no Text Display Template Entity specified");
cls_IGESDraw_NetworkSubfigure.def("NbConnectPoints", (Standard_Integer (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::NbConnectPoints, "returns the number of associated Connect Point Entities");
cls_IGESDraw_NetworkSubfigure.def("ConnectPoint", (opencascade::handle<IGESDraw_ConnectPoint> (IGESDraw_NetworkSubfigure::*)(const Standard_Integer) const) &IGESDraw_NetworkSubfigure::ConnectPoint, "returns the Index'th associated Connect point Entity raises exception if Index <= 0 or Index > NbConnectPoints()", py::arg("Index"));
cls_IGESDraw_NetworkSubfigure.def_static("get_type_name_", (const char * (*)()) &IGESDraw_NetworkSubfigure::get_type_name, "None");
cls_IGESDraw_NetworkSubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_NetworkSubfigure::get_type_descriptor, "None");
cls_IGESDraw_NetworkSubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_NetworkSubfigure::*)() const) &IGESDraw_NetworkSubfigure::DynamicType, "None");

// Enums

}