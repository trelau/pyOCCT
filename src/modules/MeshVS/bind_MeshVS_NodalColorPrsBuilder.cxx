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
#include <MeshVS_DataMapOfIntegerColor.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <MeshVS_NodalColorPrsBuilder.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_Texture2D.hxx>

void bind_MeshVS_NodalColorPrsBuilder(py::module &mod){

py::class_<MeshVS_NodalColorPrsBuilder, opencascade::handle<MeshVS_NodalColorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_NodalColorPrsBuilder(mod, "MeshVS_NodalColorPrsBuilder", "This class provides methods to create presentation of nodes with assigned color. There are two ways of presentation building 1. Without using texture. In this case colors of nodes are specified with DataMapOfIntegerColor and presentation is built with gradient fill between these nodes (default behaviour) 2. Using texture. In this case presentation is built with spectrum filling between nodes. For example, if one node has blue color and second one has violet color, parameters of this class may be set to fill presentation between nodes with solar spectrum. Methods: UseTexture - activates/deactivates this way SetColorMap - sets colors used for generation of texture SetColorindices - specifies correspondence between node IDs and indices of colors from color map");

// Constructors
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

// Fields

// Methods
cls_MeshVS_NodalColorPrsBuilder.def("Build", (void (MeshVS_NodalColorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_NodalColorPrsBuilder::Build, "Builds presentation of nodes with assigned color.", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
cls_MeshVS_NodalColorPrsBuilder.def("GetColors", (const MeshVS_DataMapOfIntegerColor & (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::GetColors, "Returns map of colors assigned to nodes.");
cls_MeshVS_NodalColorPrsBuilder.def("SetColors", (void (MeshVS_NodalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_NodalColorPrsBuilder::SetColors, "Sets map of colors assigned to nodes.", py::arg("Map"));
cls_MeshVS_NodalColorPrsBuilder.def("HasColors", (Standard_Boolean (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::HasColors, "Returns true, if map isn't empty");
cls_MeshVS_NodalColorPrsBuilder.def("GetColor", (Standard_Boolean (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &) const) &MeshVS_NodalColorPrsBuilder::GetColor, "Returns color assigned to single node", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_NodalColorPrsBuilder.def("SetColor", (void (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_NodalColorPrsBuilder::SetColor, "Sets color assigned to single node", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_NodalColorPrsBuilder.def("UseTexture", (void (MeshVS_NodalColorPrsBuilder::*)(const Standard_Boolean)) &MeshVS_NodalColorPrsBuilder::UseTexture, "Specify whether texture must be used to build presentation", py::arg("theToUse"));
cls_MeshVS_NodalColorPrsBuilder.def("IsUseTexture", (Standard_Boolean (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::IsUseTexture, "Verify whether texture is used to build presentation");
cls_MeshVS_NodalColorPrsBuilder.def("SetColorMap", (void (MeshVS_NodalColorPrsBuilder::*)(const Aspect_SequenceOfColor &)) &MeshVS_NodalColorPrsBuilder::SetColorMap, "Set colors to be used for texrture presentation theColors - colors for valid coordinates (laying in range [0, 1])", py::arg("theColors"));
cls_MeshVS_NodalColorPrsBuilder.def("GetColorMap", (const Aspect_SequenceOfColor & (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::GetColorMap, "Return colors used for texrture presentation");
cls_MeshVS_NodalColorPrsBuilder.def("SetInvalidColor", (void (MeshVS_NodalColorPrsBuilder::*)(const Quantity_Color &)) &MeshVS_NodalColorPrsBuilder::SetInvalidColor, "Set color representing invalid texture coordinate (laying outside range [0, 1])", py::arg("theInvalidColor"));
cls_MeshVS_NodalColorPrsBuilder.def("GetInvalidColor", (Quantity_Color (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::GetInvalidColor, "Return color representing invalid texture coordinate (laying outside range [0, 1])");
cls_MeshVS_NodalColorPrsBuilder.def("SetTextureCoords", (void (MeshVS_NodalColorPrsBuilder::*)(const TColStd_DataMapOfIntegerReal &)) &MeshVS_NodalColorPrsBuilder::SetTextureCoords, "Specify correspondence between node IDs and texture coordinates (range [0, 1])", py::arg("theMap"));
cls_MeshVS_NodalColorPrsBuilder.def("GetTextureCoords", (const TColStd_DataMapOfIntegerReal & (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::GetTextureCoords, "Get correspondence between node IDs and texture coordinates (range [0, 1])");
cls_MeshVS_NodalColorPrsBuilder.def("SetTextureCoord", (void (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer, const Standard_Real)) &MeshVS_NodalColorPrsBuilder::SetTextureCoord, "Specify correspondence between node ID and texture coordinate (range [0, 1])", py::arg("theID"), py::arg("theCoord"));
cls_MeshVS_NodalColorPrsBuilder.def("GetTextureCoord", (Standard_Real (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer)) &MeshVS_NodalColorPrsBuilder::GetTextureCoord, "Return correspondence between node IDs and texture coordinate (range [0, 1])", py::arg("theID"));
cls_MeshVS_NodalColorPrsBuilder.def("AddVolumePrs", (void (MeshVS_NodalColorPrsBuilder::*)(const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &, const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Real) const) &MeshVS_NodalColorPrsBuilder::AddVolumePrs, "Add to array polygons or polylines representing volume", py::arg("theTopo"), py::arg("theNodes"), py::arg("theCoords"), py::arg("theArray"), py::arg("theIsShaded"), py::arg("theNbColors"), py::arg("theNbTexColors"), py::arg("theColorRatio"));
cls_MeshVS_NodalColorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_NodalColorPrsBuilder::get_type_name, "None");
cls_MeshVS_NodalColorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_NodalColorPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_NodalColorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_NodalColorPrsBuilder::*)() const) &MeshVS_NodalColorPrsBuilder::DynamicType, "None");

// Enums

}