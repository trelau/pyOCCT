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
#include <MeshVS_DrawerAttribute.hxx>

void bind_MeshVS_DrawerAttribute(py::module &mod){

py::enum_<MeshVS_DrawerAttribute>(mod, "MeshVS_DrawerAttribute", "Is it allowed to draw beam and face's edge overlapping with this beam.//! Is mesh drawn with reflective material//! Is colored mesh data representation drawn with reflective material//! What part of face or link will be shown if shrink mode. It is recommended this coeff to be between 0 and 1.//! How many nodes is possible to be in face//! If this parameter is true, the compute method CPU time will be displayed in console window//! If this parameter is true, the compute selection method CPU time will be displayed in console window//! If this parameter is false, the nodes won't be shown in viewer, otherwise will be.//! If this parameter is true, the selectable nodes map will be updated automatically when hidden elements change//! If this parameter is false, the face's edges are not shown Warning: in wireframe mode this parameter is ignored//! Is mesh drawing in smooth shading mode//! Is back faces of volume elements should be supressed//! The integer keys for most useful constants attuning mesh presentation appearence WARNING: DA_TextExpansionFactor, DA_TextSpace, DA_TextDisplayType have no effect and might be removed in the future.")
	.value("MeshVS_DA_InteriorStyle", MeshVS_DrawerAttribute::MeshVS_DA_InteriorStyle)
	.value("MeshVS_DA_InteriorColor", MeshVS_DrawerAttribute::MeshVS_DA_InteriorColor)
	.value("MeshVS_DA_BackInteriorColor", MeshVS_DrawerAttribute::MeshVS_DA_BackInteriorColor)
	.value("MeshVS_DA_EdgeColor", MeshVS_DrawerAttribute::MeshVS_DA_EdgeColor)
	.value("MeshVS_DA_EdgeType", MeshVS_DrawerAttribute::MeshVS_DA_EdgeType)
	.value("MeshVS_DA_EdgeWidth", MeshVS_DrawerAttribute::MeshVS_DA_EdgeWidth)
	.value("MeshVS_DA_HatchStyle", MeshVS_DrawerAttribute::MeshVS_DA_HatchStyle)
	.value("MeshVS_DA_FrontMaterial", MeshVS_DrawerAttribute::MeshVS_DA_FrontMaterial)
	.value("MeshVS_DA_BackMaterial", MeshVS_DrawerAttribute::MeshVS_DA_BackMaterial)
	.value("MeshVS_DA_BeamType", MeshVS_DrawerAttribute::MeshVS_DA_BeamType)
	.value("MeshVS_DA_BeamWidth", MeshVS_DrawerAttribute::MeshVS_DA_BeamWidth)
	.value("MeshVS_DA_BeamColor", MeshVS_DrawerAttribute::MeshVS_DA_BeamColor)
	.value("MeshVS_DA_MarkerType", MeshVS_DrawerAttribute::MeshVS_DA_MarkerType)
	.value("MeshVS_DA_MarkerColor", MeshVS_DrawerAttribute::MeshVS_DA_MarkerColor)
	.value("MeshVS_DA_MarkerScale", MeshVS_DrawerAttribute::MeshVS_DA_MarkerScale)
	.value("MeshVS_DA_TextColor", MeshVS_DrawerAttribute::MeshVS_DA_TextColor)
	.value("MeshVS_DA_TextHeight", MeshVS_DrawerAttribute::MeshVS_DA_TextHeight)
	.value("MeshVS_DA_TextFont", MeshVS_DrawerAttribute::MeshVS_DA_TextFont)
	.value("MeshVS_DA_TextExpansionFactor", MeshVS_DrawerAttribute::MeshVS_DA_TextExpansionFactor)
	.value("MeshVS_DA_TextSpace", MeshVS_DrawerAttribute::MeshVS_DA_TextSpace)
	.value("MeshVS_DA_TextStyle", MeshVS_DrawerAttribute::MeshVS_DA_TextStyle)
	.value("MeshVS_DA_TextDisplayType", MeshVS_DrawerAttribute::MeshVS_DA_TextDisplayType)
	.value("MeshVS_DA_TextTexFont", MeshVS_DrawerAttribute::MeshVS_DA_TextTexFont)
	.value("MeshVS_DA_TextFontAspect", MeshVS_DrawerAttribute::MeshVS_DA_TextFontAspect)
	.value("MeshVS_DA_VectorColor", MeshVS_DrawerAttribute::MeshVS_DA_VectorColor)
	.value("MeshVS_DA_VectorMaxLength", MeshVS_DrawerAttribute::MeshVS_DA_VectorMaxLength)
	.value("MeshVS_DA_VectorArrowPart", MeshVS_DrawerAttribute::MeshVS_DA_VectorArrowPart)
	.value("MeshVS_DA_IsAllowOverlapped", MeshVS_DrawerAttribute::MeshVS_DA_IsAllowOverlapped)
	.value("MeshVS_DA_Reflection", MeshVS_DrawerAttribute::MeshVS_DA_Reflection)
	.value("MeshVS_DA_ColorReflection", MeshVS_DrawerAttribute::MeshVS_DA_ColorReflection)
	.value("MeshVS_DA_ShrinkCoeff", MeshVS_DrawerAttribute::MeshVS_DA_ShrinkCoeff)
	.value("MeshVS_DA_MaxFaceNodes", MeshVS_DrawerAttribute::MeshVS_DA_MaxFaceNodes)
	.value("MeshVS_DA_ComputeTime", MeshVS_DrawerAttribute::MeshVS_DA_ComputeTime)
	.value("MeshVS_DA_ComputeSelectionTime", MeshVS_DrawerAttribute::MeshVS_DA_ComputeSelectionTime)
	.value("MeshVS_DA_DisplayNodes", MeshVS_DrawerAttribute::MeshVS_DA_DisplayNodes)
	.value("MeshVS_DA_SelectableAuto", MeshVS_DrawerAttribute::MeshVS_DA_SelectableAuto)
	.value("MeshVS_DA_ShowEdges", MeshVS_DrawerAttribute::MeshVS_DA_ShowEdges)
	.value("MeshVS_DA_SmoothShading", MeshVS_DrawerAttribute::MeshVS_DA_SmoothShading)
	.value("MeshVS_DA_SupressBackFaces", MeshVS_DrawerAttribute::MeshVS_DA_SupressBackFaces)
	.value("MeshVS_DA_User", MeshVS_DrawerAttribute::MeshVS_DA_User)
	.export_values();


}