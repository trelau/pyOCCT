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
#include <MeshVS_PrsBuilder.hxx>
#include <Standard_Handle.hxx>
#include <MeshVS_Mesh.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <MeshVS_DataSource.hxx>
#include <Standard_TypeDef.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <Prs3d_Presentation.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <MeshVS_MeshPrsBuilder.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectLine3d.hxx>

void bind_MeshVS_MeshPrsBuilder(py::module &mod){

py::class_<MeshVS_MeshPrsBuilder, opencascade::handle<MeshVS_MeshPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_MeshPrsBuilder(mod, "MeshVS_MeshPrsBuilder", "This class provides methods to compute base mesh presentation");

// Constructors
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

// Fields

// Methods
cls_MeshVS_MeshPrsBuilder.def("Build", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_MeshPrsBuilder::Build, "Builds base mesh presentation by calling the methods below", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
cls_MeshVS_MeshPrsBuilder.def("BuildNodes", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const) &MeshVS_MeshPrsBuilder::BuildNodes, "Builds nodes presentation", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
cls_MeshVS_MeshPrsBuilder.def("BuildElements", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const) &MeshVS_MeshPrsBuilder::BuildElements, "Builds elements presentation", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
cls_MeshVS_MeshPrsBuilder.def("BuildHilightPrs", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, const Standard_Boolean) const) &MeshVS_MeshPrsBuilder::BuildHilightPrs, "Builds presentation of hilighted entity", py::arg("Prs"), py::arg("IDs"), py::arg("IsElement"));
cls_MeshVS_MeshPrsBuilder.def_static("AddVolumePrs_", (void (*)(const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &, const TColStd_Array1OfReal &, const Standard_Integer, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &MeshVS_MeshPrsBuilder::AddVolumePrs, "Add to array polygons or polylines representing volume", py::arg("Topo"), py::arg("Nodes"), py::arg("NbNodes"), py::arg("Array"), py::arg("IsReflected"), py::arg("IsShrinked"), py::arg("IsSelect"), py::arg("ShrinkCoef"));
cls_MeshVS_MeshPrsBuilder.def_static("HowManyPrimitives_", [](const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & Topo, const Standard_Boolean AsPolygons, const Standard_Boolean IsSelect, const Standard_Integer NbNodes, Standard_Integer & Vertices, Standard_Integer & Bounds){ MeshVS_MeshPrsBuilder::HowManyPrimitives(Topo, AsPolygons, IsSelect, NbNodes, Vertices, Bounds); return std::tuple<Standard_Integer &, Standard_Integer &>(Vertices, Bounds); }, "Calculate how many polygons or polylines are necessary to draw passed topology", py::arg("Topo"), py::arg("AsPolygons"), py::arg("IsSelect"), py::arg("NbNodes"), py::arg("Vertices"), py::arg("Bounds"));
cls_MeshVS_MeshPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshPrsBuilder::get_type_name, "None");
cls_MeshVS_MeshPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_MeshPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshPrsBuilder::*)() const) &MeshVS_MeshPrsBuilder::DynamicType, "None");

// Enums

}