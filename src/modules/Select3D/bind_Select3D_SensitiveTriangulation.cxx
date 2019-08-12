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
#include <Select3D_SensitiveTriangulation.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_GTrsf.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>

void bind_Select3D_SensitiveTriangulation(py::module &mod){

py::class_<Select3D_SensitiveTriangulation, opencascade::handle<Select3D_SensitiveTriangulation>, Select3D_SensitiveSet> cls_Select3D_SensitiveTriangulation(mod, "Select3D_SensitiveTriangulation", "A framework to define selection of a sensitive entity made of a set of triangles.");

// Constructors
cls_Select3D_SensitiveTriangulation.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &>(), py::arg("theOwnerId"), py::arg("theTrg"), py::arg("theInitLoc"));
cls_Select3D_SensitiveTriangulation.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theTrg"), py::arg("theInitLoc"), py::arg("theIsInterior"));
cls_Select3D_SensitiveTriangulation.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, const opencascade::handle<TColStd_HArray1OfInteger> &, const gp_Pnt &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theTrg"), py::arg("theInitLoc"), py::arg("theFreeEdges"), py::arg("theCOG"), py::arg("theIsInterior"));

// Fields

// Methods
cls_Select3D_SensitiveTriangulation.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveTriangulation::get_type_name, "None");
cls_Select3D_SensitiveTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveTriangulation::get_type_descriptor, "None");
cls_Select3D_SensitiveTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::DynamicType, "None");
cls_Select3D_SensitiveTriangulation.def("NbSubElements", (Standard_Integer (Select3D_SensitiveTriangulation::*)()) &Select3D_SensitiveTriangulation::NbSubElements, "Returns the amount of nodes in triangulation");
cls_Select3D_SensitiveTriangulation.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveTriangulation::*)()) &Select3D_SensitiveTriangulation::GetConnected, "None");
cls_Select3D_SensitiveTriangulation.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::Triangulation, "None");
cls_Select3D_SensitiveTriangulation.def("Size", (Standard_Integer (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::Size, "Returns the length of array of triangles or edges");
cls_Select3D_SensitiveTriangulation.def("Box", (Select3D_BndBox3d (Select3D_SensitiveTriangulation::*)(const Standard_Integer) const) &Select3D_SensitiveTriangulation::Box, "Returns bounding box of triangle/edge with index theIdx", py::arg("theIdx"));
cls_Select3D_SensitiveTriangulation.def("Center", (Standard_Real (Select3D_SensitiveTriangulation::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_SensitiveTriangulation::Center, "Returns geometry center of triangle/edge with index theIdx in array along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_SensitiveTriangulation.def("Swap", (void (Select3D_SensitiveTriangulation::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveTriangulation::Swap, "Swaps items with indexes theIdx1 and theIdx2 in array", py::arg("theIdx1"), py::arg("theIdx2"));
cls_Select3D_SensitiveTriangulation.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveTriangulation::*)()) &Select3D_SensitiveTriangulation::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
cls_Select3D_SensitiveTriangulation.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::CenterOfGeometry, "Returns center of triangulation. If location transformation is set, it will be applied");
cls_Select3D_SensitiveTriangulation.def("HasInitLocation", (Standard_Boolean (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
cls_Select3D_SensitiveTriangulation.def("InvInitLocation", (gp_GTrsf (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");
cls_Select3D_SensitiveTriangulation.def("GetInitLocation", (const TopLoc_Location & (Select3D_SensitiveTriangulation::*)() const) &Select3D_SensitiveTriangulation::GetInitLocation, "None");

// Enums

}