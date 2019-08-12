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
#include <Select3D_SensitivePoly.hxx>
#include <Standard_Handle.hxx>
#include <Select3D_SensitiveCircle.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Geom_Circle.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <Select3D_TypeOfSensitivity.hxx>

void bind_Select3D_SensitiveCircle(py::module &mod){

py::class_<Select3D_SensitiveCircle, opencascade::handle<Select3D_SensitiveCircle>, Select3D_SensitivePoly> cls_Select3D_SensitiveCircle(mod, "Select3D_SensitiveCircle", "A framework to define sensitive 3D arcs and circles. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");

// Constructors
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &>(), py::arg("theOwnerId"), py::arg("theCircle"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theIsFilled"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Boolean, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theIsFilled"), py::arg("theNbPnts"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theU1"), py::arg("theU2"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theU1"), py::arg("theU2"), py::arg("theIsFilled"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theU1"), py::arg("theU2"), py::arg("theIsFilled"), py::arg("theNbPnts"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("theOwnerId"), py::arg("thePnts3d"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePnts3d"), py::arg("theIsFilled"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwnerId"), py::arg("thePnts3d"));
cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePnts3d"), py::arg("theIsFilled"));

// Fields

// Methods
cls_Select3D_SensitiveCircle.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveCircle::get_type_name, "None");
cls_Select3D_SensitiveCircle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveCircle::get_type_descriptor, "None");
cls_Select3D_SensitiveCircle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveCircle::*)() const) &Select3D_SensitiveCircle::DynamicType, "None");
cls_Select3D_SensitiveCircle.def("Matches", (Standard_Boolean (Select3D_SensitiveCircle::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveCircle::Matches, "Checks whether the circle overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveCircle.def("ArrayBounds", [](Select3D_SensitiveCircle &self, Standard_Integer & theLow, Standard_Integer & theUp){ self.ArrayBounds(theLow, theUp); return std::tuple<Standard_Integer &, Standard_Integer &>(theLow, theUp); }, "None", py::arg("theLow"), py::arg("theUp"));
cls_Select3D_SensitiveCircle.def("GetPoint3d", (gp_Pnt (Select3D_SensitiveCircle::*)(const Standard_Integer) const) &Select3D_SensitiveCircle::GetPoint3d, "None", py::arg("thePntIdx"));
cls_Select3D_SensitiveCircle.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveCircle::*)()) &Select3D_SensitiveCircle::GetConnected, "None");
cls_Select3D_SensitiveCircle.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveCircle::*)() const) &Select3D_SensitiveCircle::CenterOfGeometry, "Returns center of the circle. If location transformation is set, it will be applied");
cls_Select3D_SensitiveCircle.def("BVH", (void (Select3D_SensitiveCircle::*)()) &Select3D_SensitiveCircle::BVH, "Builds BVH tree for a circle's edge segments if needed");

// Enums

}