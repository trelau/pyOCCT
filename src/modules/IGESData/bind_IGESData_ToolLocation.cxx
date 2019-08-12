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
#include <IGESData_IGESModel.hxx>
#include <IGESData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <gp_GTrsf.hxx>
#include <gp_Trsf.hxx>
#include <IGESData_ToolLocation.hxx>
#include <Standard_Type.hxx>
#include <Interface_GeneralLib.hxx>
#include <TColStd_Array1OfInteger.hxx>

void bind_IGESData_ToolLocation(py::module &mod){

py::class_<IGESData_ToolLocation, opencascade::handle<IGESData_ToolLocation>, Standard_Transient> cls_IGESData_ToolLocation(mod, "IGESData_ToolLocation", "This Tool determines and gives access to effective Locations of IGES Entities as defined by the IGES Norm. These Locations can be for each Entity : - on one part, explicitly defined by a Transf in Directory Part (this Transf can be itself compound); if not defined, no proper Transformation is defined - on the other part, implicitly defined by a reference from another Entity : its Parent Both implicit and explicit locations are combinable.");

// Constructors
cls_IGESData_ToolLocation.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));

// Fields

// Methods
cls_IGESData_ToolLocation.def("Load", (void (IGESData_ToolLocation::*)()) &IGESData_ToolLocation::Load, "Does the effective work of determining Locations of Entities");
cls_IGESData_ToolLocation.def("SetPrecision", (void (IGESData_ToolLocation::*)(const Standard_Real)) &IGESData_ToolLocation::SetPrecision, "Sets a precision for the Analysis of Locations (default by constructor is 1.E-05)", py::arg("prec"));
cls_IGESData_ToolLocation.def("SetReference", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::SetReference, "Sets the 'Reference' information for <child> as being <parent> Sets an Error Status if already set (see method IsAmbiguous)", py::arg("parent"), py::arg("child"));
cls_IGESData_ToolLocation.def("SetParentAssoc", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::SetParentAssoc, "Sets the 'Associativity' information for <child> as being <parent> (it must be the Parent itself, not the Associativity)", py::arg("parent"), py::arg("child"));
cls_IGESData_ToolLocation.def("ResetDependences", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::ResetDependences, "Resets all informations about dependences for <child>", py::arg("child"));
cls_IGESData_ToolLocation.def("SetOwnAsDependent", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::SetOwnAsDependent, "Unitary action which defines Entities referenced by <ent> (except those in Directory Part and Associativities List) as Dependent (their Locations are related to that of <ent>)", py::arg("ent"));
cls_IGESData_ToolLocation.def("IsTransf", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::IsTransf, "Returns True if <ent> is kind of TransfEntity. Then, it has no location, while it can be used to define a Location)", py::arg("ent"));
cls_IGESData_ToolLocation.def("IsAssociativity", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::IsAssociativity, "Returns True if <ent> is an Associativity (IGES Type 402). Then, Location does not apply.", py::arg("ent"));
cls_IGESData_ToolLocation.def("HasTransf", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::HasTransf, "Returns True if <ent> has a Transformation Matrix in proper (referenced from its Directory Part)", py::arg("ent"));
cls_IGESData_ToolLocation.def("ExplicitLocation", (gp_GTrsf (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::ExplicitLocation, "Returns the Explicit Location defined by the Transformation Matrix of <ent>. Identity if there is none", py::arg("ent"));
cls_IGESData_ToolLocation.def("IsAmbiguous", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::IsAmbiguous, "Returns True if more than one Parent has been determined for <ent>, by adding direct References and Associativities", py::arg("ent"));
cls_IGESData_ToolLocation.def("HasParent", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::HasParent, "Returns True if <ent> is dependent from one and only one other Entity, either by Reference or by Associativity", py::arg("ent"));
cls_IGESData_ToolLocation.def("Parent", (opencascade::handle<IGESData_IGESEntity> (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::Parent, "Returns the unique Parent recorded for <ent>. Returns a Null Handle if there is none", py::arg("ent"));
cls_IGESData_ToolLocation.def("HasParentByAssociativity", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::HasParentByAssociativity, "Returns True if the Parent, if there is one, is defined by a SingleParentEntity Associativity Else, if HasParent is True, it is by Reference", py::arg("ent"));
cls_IGESData_ToolLocation.def("ParentLocation", (gp_GTrsf (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::ParentLocation, "Returns the effective Location of the Parent of <ent>, if there is one : this Location is itself given as compound according dependences on the Parent, if there are some. Returns an Identity Transformation if no Parent is recorded.", py::arg("ent"));
cls_IGESData_ToolLocation.def("EffectiveLocation", (gp_GTrsf (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::EffectiveLocation, "Returns the effective Location of an Entity, i.e. the composition of its proper Transformation Matrix (returned by Transf) and its Parent's Location (returned by ParentLocation)", py::arg("ent"));
cls_IGESData_ToolLocation.def("AnalyseLocation", (Standard_Boolean (IGESData_ToolLocation::*)(const gp_GTrsf &, gp_Trsf &) const) &IGESData_ToolLocation::AnalyseLocation, "Analysis a Location given as a GTrsf, by trying to convert it to a Trsf (i.e. to a True Location of which effect is described by an Isometry or a Similarity) Works with the Precision given by default or by SetPrecision Calls ConvertLocation (see below)", py::arg("loc"), py::arg("result"));
cls_IGESData_ToolLocation.def_static("ConvertLocation_", [](const Standard_Real a0, const gp_GTrsf & a1, gp_Trsf & a2) -> Standard_Boolean { return IGESData_ToolLocation::ConvertLocation(a0, a1, a2); });
cls_IGESData_ToolLocation.def_static("ConvertLocation_", (Standard_Boolean (*)(const Standard_Real, const gp_GTrsf &, gp_Trsf &, const Standard_Real)) &IGESData_ToolLocation::ConvertLocation, "Convertion of a Location, from GTrsf form to Trsf form Works with a precision given as argument. Returns True if the Conversion is possible, (hence, <result> contains the converted location), False else <unit>, if given, indicates the unit in which <loc> is defined in meters. It concerns the translation part (to be converted.", py::arg("prec"), py::arg("loc"), py::arg("result"), py::arg("uni"));
cls_IGESData_ToolLocation.def_static("get_type_name_", (const char * (*)()) &IGESData_ToolLocation::get_type_name, "None");
cls_IGESData_ToolLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ToolLocation::get_type_descriptor, "None");
cls_IGESData_ToolLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ToolLocation::*)() const) &IGESData_ToolLocation::DynamicType, "None");

// Enums

}