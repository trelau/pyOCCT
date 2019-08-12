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
#include <Select3D_SensitiveCurve.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_SensitiveEntity.hxx>

void bind_Select3D_SensitiveCurve(py::module &mod){

py::class_<Select3D_SensitiveCurve, opencascade::handle<Select3D_SensitiveCurve>, Select3D_SensitivePoly> cls_Select3D_SensitiveCurve(mod, "Select3D_SensitiveCurve", "A framework to define a sensitive 3D curve. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");

// Constructors
cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Curve> &>(), py::arg("theOwnerId"), py::arg("theCurve"));
cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Curve> &, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theCurve"), py::arg("theNbPnts"));
cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("theOwnerId"), py::arg("thePoints"));
cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwnerId"), py::arg("thePoints"));

// Fields

// Methods
cls_Select3D_SensitiveCurve.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveCurve::get_type_name, "None");
cls_Select3D_SensitiveCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveCurve::get_type_descriptor, "None");
cls_Select3D_SensitiveCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveCurve::*)() const) &Select3D_SensitiveCurve::DynamicType, "None");
cls_Select3D_SensitiveCurve.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveCurve::*)()) &Select3D_SensitiveCurve::GetConnected, "Returns the copy of this");

// Enums

}