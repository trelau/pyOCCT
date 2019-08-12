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
#include <Select3D_SensitiveSet.hxx>
#include <Standard_Handle.hxx>
#include <Select3D_SensitivePoly.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <Select3D_PointData.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_Select3D_SensitivePoly(py::module &mod){

py::class_<Select3D_SensitivePoly, opencascade::handle<Select3D_SensitivePoly>, Select3D_SensitiveSet> cls_Select3D_SensitivePoly(mod, "Select3D_SensitivePoly", "Sensitive Entity to make a face selectable. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions from its member Select3D_PointData myPolyg.");

// Constructors
cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theIsBVHEnabled"));
cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theIsBVHEnabled"));
cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theIsBVHEnabled"));
cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Boolean, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theIsBVHEnabled"), py::arg("theNbPnts"));

// Fields

// Methods
cls_Select3D_SensitivePoly.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitivePoly::get_type_name, "None");
cls_Select3D_SensitivePoly.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitivePoly::get_type_descriptor, "None");
cls_Select3D_SensitivePoly.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitivePoly::*)() const) &Select3D_SensitivePoly::DynamicType, "None");
cls_Select3D_SensitivePoly.def("NbSubElements", (Standard_Integer (Select3D_SensitivePoly::*)()) &Select3D_SensitivePoly::NbSubElements, "Returns the amount of segments in poly");
cls_Select3D_SensitivePoly.def("Points3D", (void (Select3D_SensitivePoly::*)(opencascade::handle<TColgp_HArray1OfPnt> &)) &Select3D_SensitivePoly::Points3D, "Returns the 3D points of the array used at construction time.", py::arg("theHArrayOfPnt"));
cls_Select3D_SensitivePoly.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitivePoly::*)()) &Select3D_SensitivePoly::BoundingBox, "Returns bounding box of a polygon. If location transformation is set, it will be applied");
cls_Select3D_SensitivePoly.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitivePoly::*)() const) &Select3D_SensitivePoly::CenterOfGeometry, "Returns center of the point set. If location transformation is set, it will be applied");
cls_Select3D_SensitivePoly.def("Size", (Standard_Integer (Select3D_SensitivePoly::*)() const) &Select3D_SensitivePoly::Size, "Returns the amount of segments of the poly");
cls_Select3D_SensitivePoly.def("Box", (Select3D_BndBox3d (Select3D_SensitivePoly::*)(const Standard_Integer) const) &Select3D_SensitivePoly::Box, "Returns bounding box of segment with index theIdx", py::arg("theIdx"));
cls_Select3D_SensitivePoly.def("Center", (Standard_Real (Select3D_SensitivePoly::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_SensitivePoly::Center, "Returns geometry center of sensitive entity index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_SensitivePoly.def("Swap", (void (Select3D_SensitivePoly::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitivePoly::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));

// Enums

}