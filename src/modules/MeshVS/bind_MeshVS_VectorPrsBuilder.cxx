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
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <Prs3d_Presentation.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <gp_Trsf.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <MeshVS_DataMapOfIntegerVector.hxx>
#include <gp_Vec.hxx>
#include <MeshVS_VectorPrsBuilder.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_VectorPrsBuilder(py::module &mod){

py::class_<MeshVS_VectorPrsBuilder, opencascade::handle<MeshVS_VectorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_VectorPrsBuilder(mod, "MeshVS_VectorPrsBuilder", "This class provides methods to create vector data presentation. It store map of vectors assigned with nodes or elements. In simplified mode vectors draws with thickened ends instead of arrows");

// Constructors
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &, const Standard_Boolean>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"), py::arg("IsSimplePrs"));

// Fields

// Methods
cls_MeshVS_VectorPrsBuilder.def("Build", (void (MeshVS_VectorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_VectorPrsBuilder::Build, "Builds vector data presentation", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("theDisplayMode"));
cls_MeshVS_VectorPrsBuilder.def("DrawVector", (void (MeshVS_VectorPrsBuilder::*)(const gp_Trsf &, const Standard_Real, const Standard_Real, const TColgp_Array1OfPnt &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &) const) &MeshVS_VectorPrsBuilder::DrawVector, "Adds to array of polygons and polylines some primitive representing single vector", py::arg("theTrsf"), py::arg("Length"), py::arg("MaxLength"), py::arg("ArrowPoints"), py::arg("Lines"), py::arg("ArrowLines"), py::arg("Triangles"));
cls_MeshVS_VectorPrsBuilder.def_static("calculateArrow_", (Standard_Real (*)(TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real)) &MeshVS_VectorPrsBuilder::calculateArrow, "Calculates points of arrow presentation", py::arg("Points"), py::arg("Length"), py::arg("ArrowPart"));
cls_MeshVS_VectorPrsBuilder.def("GetVectors", (const MeshVS_DataMapOfIntegerVector & (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean) const) &MeshVS_VectorPrsBuilder::GetVectors, "Returns map of vectors assigned with nodes or elements", py::arg("IsElement"));
cls_MeshVS_VectorPrsBuilder.def("SetVectors", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, const MeshVS_DataMapOfIntegerVector &)) &MeshVS_VectorPrsBuilder::SetVectors, "Sets map of vectors assigned with nodes or elements", py::arg("IsElement"), py::arg("Map"));
cls_MeshVS_VectorPrsBuilder.def("HasVectors", (Standard_Boolean (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean) const) &MeshVS_VectorPrsBuilder::HasVectors, "Returns true, if map isn't empty", py::arg("IsElement"));
cls_MeshVS_VectorPrsBuilder.def("GetVector", (Standard_Boolean (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, gp_Vec &) const) &MeshVS_VectorPrsBuilder::GetVector, "Returns vector assigned with certain node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Vect"));
cls_MeshVS_VectorPrsBuilder.def("SetVector", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, const gp_Vec &)) &MeshVS_VectorPrsBuilder::SetVector, "Sets vector assigned with certain node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Vect"));
cls_MeshVS_VectorPrsBuilder.def("GetMinMaxVectorValue", [](MeshVS_VectorPrsBuilder &self, const Standard_Boolean IsElement, Standard_Real & MinValue, Standard_Real & MaxValue){ self.GetMinMaxVectorValue(IsElement, MinValue, MaxValue); return std::tuple<Standard_Real &, Standard_Real &>(MinValue, MaxValue); }, "Calculates minimal and maximal length of vectors in map ( nodal, if IsElement = False or elemental, if IsElement = True )", py::arg("IsElement"), py::arg("MinValue"), py::arg("MaxValue"));
cls_MeshVS_VectorPrsBuilder.def("SetSimplePrsMode", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean)) &MeshVS_VectorPrsBuilder::SetSimplePrsMode, "Sets flag that indicates is simple vector arrow mode uses or not default value is False", py::arg("IsSimpleArrow"));
cls_MeshVS_VectorPrsBuilder.def("SetSimplePrsParams", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &MeshVS_VectorPrsBuilder::SetSimplePrsParams, "Sets parameters of simple vector arrwo presentation theLineWidthParam - coefficient of vector line width (to draw line instead of arrow) theStartParam and theEndParam parameters of start and end of thickened ends position of thickening calculates according to parameters and maximum vector length default values are: theLineWidthParam = 2.5 theStartParam = 0.85 theEndParam = 0.95", py::arg("theLineWidthParam"), py::arg("theStartParam"), py::arg("theEndParam"));
cls_MeshVS_VectorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_VectorPrsBuilder::get_type_name, "None");
cls_MeshVS_VectorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_VectorPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_VectorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_VectorPrsBuilder::*)() const) &MeshVS_VectorPrsBuilder::DynamicType, "None");

// Enums

}