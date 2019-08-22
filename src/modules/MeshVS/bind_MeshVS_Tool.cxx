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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <MeshVS_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Vec.hxx>
#include <MeshVS_Tool.hxx>

void bind_MeshVS_Tool(py::module &mod){

py::class_<MeshVS_Tool> cls_MeshVS_Tool(mod, "MeshVS_Tool", "This class provides auxiliary methods to create differents aspects");

// Constructors

// Fields

// Methods
// cls_MeshVS_Tool.def_static("operator new_", (void * (*)(size_t)) &MeshVS_Tool::operator new, "None", py::arg("theSize"));
// cls_MeshVS_Tool.def_static("operator delete_", (void (*)(void *)) &MeshVS_Tool::operator delete, "None", py::arg("theAddress"));
// cls_MeshVS_Tool.def_static("operator new[]_", (void * (*)(size_t)) &MeshVS_Tool::operator new[], "None", py::arg("theSize"));
// cls_MeshVS_Tool.def_static("operator delete[]_", (void (*)(void *)) &MeshVS_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_MeshVS_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &MeshVS_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MeshVS_Tool.def_static("operator delete_", (void (*)(void *, void *)) &MeshVS_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectFillArea3d> { return MeshVS_Tool::CreateAspectFillArea3d(a0); });
cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", (opencascade::handle<Graphic3d_AspectFillArea3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectFillArea3d, "Creates fill area aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", [](const opencascade::handle<MeshVS_Drawer> & a0, const Graphic3d_MaterialAspect & a1) -> opencascade::handle<Graphic3d_AspectFillArea3d> { return MeshVS_Tool::CreateAspectFillArea3d(a0, a1); });
cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", (opencascade::handle<Graphic3d_AspectFillArea3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Graphic3d_MaterialAspect &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectFillArea3d, "Creates fill aspect with values from Drawer according to keys from DrawerAttribute and specific material aspect", py::arg("theDr"), py::arg("Mat"), py::arg("UseDefaults"));
cls_MeshVS_Tool.def_static("CreateAspectLine3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectLine3d> { return MeshVS_Tool::CreateAspectLine3d(a0); });
cls_MeshVS_Tool.def_static("CreateAspectLine3d_", (opencascade::handle<Graphic3d_AspectLine3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectLine3d, "Creates line aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
cls_MeshVS_Tool.def_static("CreateAspectMarker3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectMarker3d> { return MeshVS_Tool::CreateAspectMarker3d(a0); });
cls_MeshVS_Tool.def_static("CreateAspectMarker3d_", (opencascade::handle<Graphic3d_AspectMarker3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectMarker3d, "Creates marker aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
cls_MeshVS_Tool.def_static("CreateAspectText3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectText3d> { return MeshVS_Tool::CreateAspectText3d(a0); });
cls_MeshVS_Tool.def_static("CreateAspectText3d_", (opencascade::handle<Graphic3d_AspectText3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectText3d, "Creates text aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
cls_MeshVS_Tool.def_static("GetNormal_", (Standard_Boolean (*)(const TColStd_Array1OfReal &, gp_Vec &)) &MeshVS_Tool::GetNormal, "Get one of normals to polygon described by these points. If the polygon isn't planar, function returns false", py::arg("Nodes"), py::arg("Norm"));
cls_MeshVS_Tool.def_static("GetAverageNormal_", (Standard_Boolean (*)(const TColStd_Array1OfReal &, gp_Vec &)) &MeshVS_Tool::GetAverageNormal, "Get an average of normals to non-planar polygon described by these points or compute normal of planar polygon. If the polygon isn't planar, function returns false", py::arg("Nodes"), py::arg("Norm"));

// Enums

}