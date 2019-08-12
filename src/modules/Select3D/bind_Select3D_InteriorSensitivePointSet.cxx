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
#include <SelectBasics_EntityOwner.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_InteriorSensitivePointSet.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_Select3D_InteriorSensitivePointSet(py::module &mod){

py::class_<Select3D_InteriorSensitivePointSet, opencascade::handle<Select3D_InteriorSensitivePointSet>, Select3D_SensitiveSet> cls_Select3D_InteriorSensitivePointSet(mod, "Select3D_InteriorSensitivePointSet", "This class handles the selection of arbitrary point set with internal type of sensitivity. The main principle is to split the point set given onto planar convex polygons and search for the overlap with one or more of them through traverse of BVH tree.");

// Constructors
cls_Select3D_InteriorSensitivePointSet.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwnerId"), py::arg("thePoints"));

// Fields

// Methods
cls_Select3D_InteriorSensitivePointSet.def("GetPoints", (void (Select3D_InteriorSensitivePointSet::*)(opencascade::handle<TColgp_HArray1OfPnt> &)) &Select3D_InteriorSensitivePointSet::GetPoints, "Initializes the given array theHArrayOfPnt by 3d coordinates of vertices of the whole point set", py::arg("theHArrayOfPnt"));
cls_Select3D_InteriorSensitivePointSet.def("Size", (Standard_Integer (Select3D_InteriorSensitivePointSet::*)() const) &Select3D_InteriorSensitivePointSet::Size, "Returns the length of vector of planar convex polygons");
cls_Select3D_InteriorSensitivePointSet.def("Box", (Select3D_BndBox3d (Select3D_InteriorSensitivePointSet::*)(const Standard_Integer) const) &Select3D_InteriorSensitivePointSet::Box, "Returns bounding box of planar convex polygon with index theIdx", py::arg("theIdx"));
cls_Select3D_InteriorSensitivePointSet.def("Center", (Standard_Real (Select3D_InteriorSensitivePointSet::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_InteriorSensitivePointSet::Center, "Returns geometry center of planar convex polygon with index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_InteriorSensitivePointSet.def("Swap", (void (Select3D_InteriorSensitivePointSet::*)(const Standard_Integer, const Standard_Integer)) &Select3D_InteriorSensitivePointSet::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));
cls_Select3D_InteriorSensitivePointSet.def("BoundingBox", (Select3D_BndBox3d (Select3D_InteriorSensitivePointSet::*)()) &Select3D_InteriorSensitivePointSet::BoundingBox, "Returns bounding box of the point set. If location transformation is set, it will be applied");
cls_Select3D_InteriorSensitivePointSet.def("CenterOfGeometry", (gp_Pnt (Select3D_InteriorSensitivePointSet::*)() const) &Select3D_InteriorSensitivePointSet::CenterOfGeometry, "Returns center of the point set. If location transformation is set, it will be applied");
cls_Select3D_InteriorSensitivePointSet.def("NbSubElements", (Standard_Integer (Select3D_InteriorSensitivePointSet::*)()) &Select3D_InteriorSensitivePointSet::NbSubElements, "Returns the amount of points in set");
cls_Select3D_InteriorSensitivePointSet.def_static("get_type_name_", (const char * (*)()) &Select3D_InteriorSensitivePointSet::get_type_name, "None");
cls_Select3D_InteriorSensitivePointSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_InteriorSensitivePointSet::get_type_descriptor, "None");
cls_Select3D_InteriorSensitivePointSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_InteriorSensitivePointSet::*)() const) &Select3D_InteriorSensitivePointSet::DynamicType, "None");

// Enums

}