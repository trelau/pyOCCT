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
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <IGESGeom_Flash.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_Flash(py::module &mod){

py::class_<IGESGeom_Flash, opencascade::handle<IGESGeom_Flash>, IGESData_IGESEntity> cls_IGESGeom_Flash(mod, "IGESGeom_Flash", "defines IGESFlash, Type <125> Form <0 - 4> in package IGESGeom A flash entity is a point in the ZT=0 plane that locates a particular closed area. That closed area can be defined in one of two ways. First, it can be an arbitrary closed area defined by any entity capable of defining a closed area. The points of this entity must all lie in the ZT=0 plane. Second, it can be a member of a predefined set of flash shapes.");

// Constructors
cls_IGESGeom_Flash.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_Flash.def("Init", (void (IGESGeom_Flash::*)(const gp_XY &, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<IGESData_IGESEntity> &)) &IGESGeom_Flash::Init, "This method is used to set the fields of the class Flash - aPoint : Reference of flash - aDim : First flash sizing parameter - anotherDim : Second flash sizing parameter - aRotation : Rotation of flash about reference point in radians - aReference : Pointer to the referenced entity or Null", py::arg("aPoint"), py::arg("aDim"), py::arg("anotherDim"), py::arg("aRotation"), py::arg("aReference"));
cls_IGESGeom_Flash.def("SetFormNumber", (void (IGESGeom_Flash::*)(const Standard_Integer)) &IGESGeom_Flash::SetFormNumber, "Changes FormNumber (indicates the Nature of the Flash : 0 Unspecified, then given by Reference, 1->4 various Specialisations (Circle,Rectangle, etc...) ) Error if not in range [0-4]", py::arg("form"));
cls_IGESGeom_Flash.def("ReferencePoint", (gp_Pnt2d (IGESGeom_Flash::*)() const) &IGESGeom_Flash::ReferencePoint, "returns the referenced point, Z = 0 always");
cls_IGESGeom_Flash.def("TransformedReferencePoint", (gp_Pnt (IGESGeom_Flash::*)() const) &IGESGeom_Flash::TransformedReferencePoint, "returns the referenced point after applying Transf. Matrix");
cls_IGESGeom_Flash.def("Dimension1", (Standard_Real (IGESGeom_Flash::*)() const) &IGESGeom_Flash::Dimension1, "returns first flash sizing parameter");
cls_IGESGeom_Flash.def("Dimension2", (Standard_Real (IGESGeom_Flash::*)() const) &IGESGeom_Flash::Dimension2, "returns second flash sizing parameter");
cls_IGESGeom_Flash.def("Rotation", (Standard_Real (IGESGeom_Flash::*)() const) &IGESGeom_Flash::Rotation, "returns the angle in radians of the rotation of flash about the reference point");
cls_IGESGeom_Flash.def("ReferenceEntity", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_Flash::*)() const) &IGESGeom_Flash::ReferenceEntity, "returns the referenced entity or Null handle.");
cls_IGESGeom_Flash.def("HasReferenceEntity", (Standard_Boolean (IGESGeom_Flash::*)() const) &IGESGeom_Flash::HasReferenceEntity, "returns True if referenced entity is present.");
cls_IGESGeom_Flash.def_static("get_type_name_", (const char * (*)()) &IGESGeom_Flash::get_type_name, "None");
cls_IGESGeom_Flash.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_Flash::get_type_descriptor, "None");
cls_IGESGeom_Flash.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_Flash::*)() const) &IGESGeom_Flash::DynamicType, "None");

// Enums

}