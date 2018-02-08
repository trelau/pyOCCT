/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Graphic3d_GroupAspect.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Image_PixMap.hxx>
#include <Aspect_HatchStyle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <NCollection_Vec2.hxx>
#include <NCollection_Vec3.hxx>
#include <Graphic3d_Vec3.hxx>
#include <NCollection_Vec4.hxx>
#include <Graphic3d_Vec4.hxx>
#include <Graphic3d_BSDF.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Graphic3d_TypeOfMaterial.hxx>
#include <Graphic3d_TypeOfReflection.hxx>
#include <Graphic3d_BufferType.hxx>
#include <TCollection_AsciiString.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Graphic3d_ShaderAttribute.hxx>
#include <Graphic3d_TypeOfShaderObject.hxx>
#include <OSD_Path.hxx>
#include <Graphic3d_ShaderObject.hxx>
#include <Graphic3d_Vec2.hxx>
#include <NCollection_Mat4.hxx>
#include <Graphic3d_Mat4.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_ShaderVariable.hxx>
#include <Graphic3d_LevelOfTextureAnisotropy.hxx>
#include <Graphic3d_TextureUnit.hxx>
#include <Graphic3d_TypeOfTextureFilter.hxx>
#include <Graphic3d_TypeOfTextureMode.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Graphic3d_TypeOfTexture.hxx>
#include <Graphic3d_TextureRoot.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Graphic3d_TextureSet.hxx>
#include <Aspect_InteriorStyle.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Aspect_TypeOfHighlightMethod.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Graphic3d_CameraTile.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <Graphic3d_Camera.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_XYZ.hxx>
#include <Bnd_Box.hxx>
#include <gp_Trsf.hxx>
#include <gp_Pln.hxx>
#include <Graphic3d_TypeOfLightSource.hxx>
#include <Graphic3d_CLight.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <BVH_Box.hxx>
#include <Graphic3d_BndBox3d.hxx>
#include <Graphic3d_BndBox4f.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Standard_OutOfRange.hxx>
#include <Standard_SStream.hxx>
#include <Graphic3d_AspectTextDefinitionError.hxx>
#include <Aspect_TypeOfStyleText.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <Font_FontAspect.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_Vertex.hxx>
#include <Graphic3d_TextPath.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <Graphic3d_Buffer.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Buffer.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_BoundBuffer.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_TypeOfStructure.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_SequenceOfGroup.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_TypeOfConnection.hxx>
#include <Graphic3d_MapOfStructure.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_CStructure.hxx>
#include <gp_Pnt2d.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Ax2.hxx>
#include <Graphic3d_CappingFlags.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_TypeOfComposition.hxx>
#include <Graphic3d_ViewAffinity.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Graphic3d_TypeOfLimit.hxx>
#include <Graphic3d_CView.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_TypeOfVisualization.hxx>
#include <Graphic3d_NMapOfTransient.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Graphic3d_SortType.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <Aspect_Background.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_FillMethod.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Graphic3d_TypeOfBackfacingModel.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_Map.hxx>
#include <Graphic3d_RenderTransparentMethod.hxx>
#include <Graphic3d_RenderingMode.hxx>
#include <Graphic3d_StereoMode.hxx>
#include <Graphic3d_ToneMappingMethod.hxx>
#include <NCollection_IndexedMap.hxx>
#include <Graphic3d_IndexedMapOfAddress.hxx>
#include <Graphic3d_BndBox4d.hxx>
#include <Graphic3d_PriorityDefinitionError.hxx>
#include <Graphic3d_StructureDefinitionError.hxx>
#include <Graphic3d_TransformError.hxx>
#include <Graphic3d_Vector.hxx>
#include <Graphic3d_SequenceOfStructure.hxx>
#include <Graphic3d_NameOfTextureEnv.hxx>
#include <Graphic3d_TypeOfAnswer.hxx>
#include <NCollection_DataMap.hxx>
#include <Graphic3d_MapOfObject.hxx>
#include <Graphic3d_ArrayOfQuadrangles.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_VectorError.hxx>
#include <Graphic3d_ArrayOfPoints.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
#include <Graphic3d_NameOfTexture2D.hxx>
#include <Graphic3d_Texture2D.hxx>
#include <Graphic3d_Texture2Dmanual.hxx>
#include <Graphic3d_ArrayOfPolygons.hxx>
#include <Graphic3d_ArrayOfQuadrangleStrips.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <Graphic3d_ArrayOfTriangleFans.hxx>
#include <Graphic3d_ArrayOfTriangleStrips.hxx>
#include <Graphic3d_CTexture.hxx>
#include <Graphic3d_GroupDefinitionError.hxx>
#include <Graphic3d_MapIteratorOfMapOfStructure.hxx>
#include <Graphic3d_MaterialDefinitionError.hxx>
#include <Graphic3d_NameOfTexture1D.hxx>
#include <Graphic3d_NameOfTexturePlane.hxx>
#include <Graphic3d_Texture1D.hxx>
#include <Graphic3d_Texture1Dmanual.hxx>
#include <Graphic3d_Texture1Dsegment.hxx>
#include <Graphic3d_Texture2Dplane.hxx>
#include <Graphic3d_TypeOfBackground.hxx>
#include <NCollection_Templates.hpp>
#include <Graphic3d_Templates.hpp>
#include <BVH_Templates.hpp>

PYBIND11_MODULE(Graphic3d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Image");
	py::module::import("OCCT.Aspect");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.OSD");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.BVH");
	py::module::import("OCCT.Font");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_GroupAspect.hxx
	py::enum_<Graphic3d_GroupAspect>(mod, "Graphic3d_GroupAspect", "Identifies primitives aspects defined per group. - ASPECT_LINE: aspect for line primitives; - ASPECT_TEXT: aspect for text primitives; - ASPECT_MARKER: aspect for marker primitives; - ASPECT_FILL_AREA: aspect for face primitives.")
		.value("Graphic3d_ASPECT_LINE", Graphic3d_GroupAspect::Graphic3d_ASPECT_LINE)
		.value("Graphic3d_ASPECT_TEXT", Graphic3d_GroupAspect::Graphic3d_ASPECT_TEXT)
		.value("Graphic3d_ASPECT_MARKER", Graphic3d_GroupAspect::Graphic3d_ASPECT_MARKER)
		.value("Graphic3d_ASPECT_FILL_AREA", Graphic3d_GroupAspect::Graphic3d_ASPECT_FILL_AREA)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BSDF.hxx
	py::enum_<Graphic3d_FresnelModel>(mod, "Graphic3d_FresnelModel", "Type of the Fresnel model.")
		.value("Graphic3d_FM_SCHLICK", Graphic3d_FresnelModel::Graphic3d_FM_SCHLICK)
		.value("Graphic3d_FM_CONSTANT", Graphic3d_FresnelModel::Graphic3d_FM_CONSTANT)
		.value("Graphic3d_FM_CONDUCTOR", Graphic3d_FresnelModel::Graphic3d_FM_CONDUCTOR)
		.value("Graphic3d_FM_DIELECTRIC", Graphic3d_FresnelModel::Graphic3d_FM_DIELECTRIC)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_NameOfMaterial.hxx
	py::enum_<Graphic3d_NameOfMaterial>(mod, "Graphic3d_NameOfMaterial", "Types of aspect materials.")
		.value("Graphic3d_NOM_BRASS", Graphic3d_NameOfMaterial::Graphic3d_NOM_BRASS)
		.value("Graphic3d_NOM_BRONZE", Graphic3d_NameOfMaterial::Graphic3d_NOM_BRONZE)
		.value("Graphic3d_NOM_COPPER", Graphic3d_NameOfMaterial::Graphic3d_NOM_COPPER)
		.value("Graphic3d_NOM_GOLD", Graphic3d_NameOfMaterial::Graphic3d_NOM_GOLD)
		.value("Graphic3d_NOM_PEWTER", Graphic3d_NameOfMaterial::Graphic3d_NOM_PEWTER)
		.value("Graphic3d_NOM_PLASTER", Graphic3d_NameOfMaterial::Graphic3d_NOM_PLASTER)
		.value("Graphic3d_NOM_PLASTIC", Graphic3d_NameOfMaterial::Graphic3d_NOM_PLASTIC)
		.value("Graphic3d_NOM_SILVER", Graphic3d_NameOfMaterial::Graphic3d_NOM_SILVER)
		.value("Graphic3d_NOM_STEEL", Graphic3d_NameOfMaterial::Graphic3d_NOM_STEEL)
		.value("Graphic3d_NOM_STONE", Graphic3d_NameOfMaterial::Graphic3d_NOM_STONE)
		.value("Graphic3d_NOM_SHINY_PLASTIC", Graphic3d_NameOfMaterial::Graphic3d_NOM_SHINY_PLASTIC)
		.value("Graphic3d_NOM_SATIN", Graphic3d_NameOfMaterial::Graphic3d_NOM_SATIN)
		.value("Graphic3d_NOM_METALIZED", Graphic3d_NameOfMaterial::Graphic3d_NOM_METALIZED)
		.value("Graphic3d_NOM_NEON_GNC", Graphic3d_NameOfMaterial::Graphic3d_NOM_NEON_GNC)
		.value("Graphic3d_NOM_CHROME", Graphic3d_NameOfMaterial::Graphic3d_NOM_CHROME)
		.value("Graphic3d_NOM_ALUMINIUM", Graphic3d_NameOfMaterial::Graphic3d_NOM_ALUMINIUM)
		.value("Graphic3d_NOM_OBSIDIAN", Graphic3d_NameOfMaterial::Graphic3d_NOM_OBSIDIAN)
		.value("Graphic3d_NOM_NEON_PHC", Graphic3d_NameOfMaterial::Graphic3d_NOM_NEON_PHC)
		.value("Graphic3d_NOM_JADE", Graphic3d_NameOfMaterial::Graphic3d_NOM_JADE)
		.value("Graphic3d_NOM_CHARCOAL", Graphic3d_NameOfMaterial::Graphic3d_NOM_CHARCOAL)
		.value("Graphic3d_NOM_WATER", Graphic3d_NameOfMaterial::Graphic3d_NOM_WATER)
		.value("Graphic3d_NOM_GLASS", Graphic3d_NameOfMaterial::Graphic3d_NOM_GLASS)
		.value("Graphic3d_NOM_DIAMOND", Graphic3d_NameOfMaterial::Graphic3d_NOM_DIAMOND)
		.value("Graphic3d_NOM_TRANSPARENT", Graphic3d_NameOfMaterial::Graphic3d_NOM_TRANSPARENT)
		.value("Graphic3d_NOM_DEFAULT", Graphic3d_NameOfMaterial::Graphic3d_NOM_DEFAULT)
		.value("Graphic3d_NOM_UserDefined", Graphic3d_NameOfMaterial::Graphic3d_NOM_UserDefined)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfMaterial.hxx
	py::enum_<Graphic3d_TypeOfMaterial>(mod, "Graphic3d_TypeOfMaterial", "Types of materials specifies if a material can change color.")
		.value("Graphic3d_MATERIAL_ASPECT", Graphic3d_TypeOfMaterial::Graphic3d_MATERIAL_ASPECT)
		.value("Graphic3d_MATERIAL_PHYSIC", Graphic3d_TypeOfMaterial::Graphic3d_MATERIAL_PHYSIC)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfReflection.hxx
	py::enum_<Graphic3d_TypeOfReflection>(mod, "Graphic3d_TypeOfReflection", "Nature of the reflection of a material.")
		.value("Graphic3d_TOR_AMBIENT", Graphic3d_TypeOfReflection::Graphic3d_TOR_AMBIENT)
		.value("Graphic3d_TOR_DIFFUSE", Graphic3d_TypeOfReflection::Graphic3d_TOR_DIFFUSE)
		.value("Graphic3d_TOR_SPECULAR", Graphic3d_TypeOfReflection::Graphic3d_TOR_SPECULAR)
		.value("Graphic3d_TOR_EMISSION", Graphic3d_TypeOfReflection::Graphic3d_TOR_EMISSION)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BufferType.hxx
	mod.attr("Graphic3d_BT_RGB") = py::cast(int(Graphic3d_BT_RGB));
	mod.attr("Graphic3d_BT_RGBA") = py::cast(int(Graphic3d_BT_RGBA));
	mod.attr("Graphic3d_BT_Depth") = py::cast(int(Graphic3d_BT_Depth));
	mod.attr("Graphic3d_BT_RGB_RayTraceHdrLeft") = py::cast(int(Graphic3d_BT_RGB_RayTraceHdrLeft));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfShaderObject.hxx
	py::enum_<Graphic3d_TypeOfShaderObject>(mod, "Graphic3d_TypeOfShaderObject", "Type of the shader object (may be extended).")
		.value("Graphic3d_TOS_VERTEX", Graphic3d_TypeOfShaderObject::Graphic3d_TOS_VERTEX)
		.value("Graphic3d_TOS_FRAGMENT", Graphic3d_TypeOfShaderObject::Graphic3d_TOS_FRAGMENT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_LevelOfTextureAnisotropy.hxx
	py::enum_<Graphic3d_LevelOfTextureAnisotropy>(mod, "Graphic3d_LevelOfTextureAnisotropy", "Level of anisotropy filter. Notice that actual quality depends on hardware capabilities!")
		.value("Graphic3d_LOTA_OFF", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_OFF)
		.value("Graphic3d_LOTA_FAST", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_FAST)
		.value("Graphic3d_LOTA_MIDDLE", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_MIDDLE)
		.value("Graphic3d_LOTA_QUALITY", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_QUALITY)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextureUnit.hxx
	py::enum_<Graphic3d_TextureUnit>(mod, "Graphic3d_TextureUnit", "Texture unit.")
		.value("Graphic3d_TextureUnit_0", Graphic3d_TextureUnit::Graphic3d_TextureUnit_0)
		.value("Graphic3d_TextureUnit_1", Graphic3d_TextureUnit::Graphic3d_TextureUnit_1)
		.value("Graphic3d_TextureUnit_2", Graphic3d_TextureUnit::Graphic3d_TextureUnit_2)
		.value("Graphic3d_TextureUnit_3", Graphic3d_TextureUnit::Graphic3d_TextureUnit_3)
		.value("Graphic3d_TextureUnit_4", Graphic3d_TextureUnit::Graphic3d_TextureUnit_4)
		.value("Graphic3d_TextureUnit_5", Graphic3d_TextureUnit::Graphic3d_TextureUnit_5)
		.value("Graphic3d_TextureUnit_6", Graphic3d_TextureUnit::Graphic3d_TextureUnit_6)
		.value("Graphic3d_TextureUnit_7", Graphic3d_TextureUnit::Graphic3d_TextureUnit_7)
		.value("Graphic3d_TextureUnit_8", Graphic3d_TextureUnit::Graphic3d_TextureUnit_8)
		.value("Graphic3d_TextureUnit_9", Graphic3d_TextureUnit::Graphic3d_TextureUnit_9)
		.value("Graphic3d_TextureUnit_10", Graphic3d_TextureUnit::Graphic3d_TextureUnit_10)
		.value("Graphic3d_TextureUnit_11", Graphic3d_TextureUnit::Graphic3d_TextureUnit_11)
		.value("Graphic3d_TextureUnit_12", Graphic3d_TextureUnit::Graphic3d_TextureUnit_12)
		.value("Graphic3d_TextureUnit_13", Graphic3d_TextureUnit::Graphic3d_TextureUnit_13)
		.value("Graphic3d_TextureUnit_14", Graphic3d_TextureUnit::Graphic3d_TextureUnit_14)
		.value("Graphic3d_TextureUnit_15", Graphic3d_TextureUnit::Graphic3d_TextureUnit_15)
		.value("Graphic3d_TextureUnit_BaseColor", Graphic3d_TextureUnit::Graphic3d_TextureUnit_BaseColor)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfTextureFilter.hxx
	py::enum_<Graphic3d_TypeOfTextureFilter>(mod, "Graphic3d_TypeOfTextureFilter", "Type of the texture filter. Notice that for textures without mipmaps linear interpolation will be used instead of TOTF_BILINEAR and TOTF_TRILINEAR.")
		.value("Graphic3d_TOTF_NEAREST", Graphic3d_TypeOfTextureFilter::Graphic3d_TOTF_NEAREST)
		.value("Graphic3d_TOTF_BILINEAR", Graphic3d_TypeOfTextureFilter::Graphic3d_TOTF_BILINEAR)
		.value("Graphic3d_TOTF_TRILINEAR", Graphic3d_TypeOfTextureFilter::Graphic3d_TOTF_TRILINEAR)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfTextureMode.hxx
	py::enum_<Graphic3d_TypeOfTextureMode>(mod, "Graphic3d_TypeOfTextureMode", "Type of the texture projection.")
		.value("Graphic3d_TOTM_OBJECT", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_OBJECT)
		.value("Graphic3d_TOTM_SPHERE", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_SPHERE)
		.value("Graphic3d_TOTM_EYE", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_EYE)
		.value("Graphic3d_TOTM_MANUAL", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_MANUAL)
		.value("Graphic3d_TOTM_SPRITE", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_SPRITE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfTexture.hxx
	py::enum_<Graphic3d_TypeOfTexture>(mod, "Graphic3d_TypeOfTexture", "Type of the texture file format.")
		.value("Graphic3d_TOT_1D", Graphic3d_TypeOfTexture::Graphic3d_TOT_1D)
		.value("Graphic3d_TOT_2D", Graphic3d_TypeOfTexture::Graphic3d_TOT_2D)
		.value("Graphic3d_TOT_2D_MIPMAP", Graphic3d_TypeOfTexture::Graphic3d_TOT_2D_MIPMAP)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfLightSource.hxx
	py::enum_<Graphic3d_TypeOfLightSource>(mod, "Graphic3d_TypeOfLightSource", "Definition of all the type of light sources")
		.value("Graphic3d_TOLS_AMBIENT", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_AMBIENT)
		.value("Graphic3d_TOLS_DIRECTIONAL", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_DIRECTIONAL)
		.value("Graphic3d_TOLS_POSITIONAL", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_POSITIONAL)
		.value("Graphic3d_TOLS_SPOT", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_SPOT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextPath.hxx
	py::enum_<Graphic3d_TextPath>(mod, "Graphic3d_TextPath", "Direction in which text is displayed.")
		.value("Graphic3d_TP_UP", Graphic3d_TextPath::Graphic3d_TP_UP)
		.value("Graphic3d_TP_DOWN", Graphic3d_TextPath::Graphic3d_TP_DOWN)
		.value("Graphic3d_TP_LEFT", Graphic3d_TextPath::Graphic3d_TP_LEFT)
		.value("Graphic3d_TP_RIGHT", Graphic3d_TextPath::Graphic3d_TP_RIGHT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_HorizontalTextAlignment.hxx
	py::enum_<Graphic3d_HorizontalTextAlignment>(mod, "Graphic3d_HorizontalTextAlignment", "Defines the horizontal position of the text relative to its anchor.")
		.value("Graphic3d_HTA_LEFT", Graphic3d_HorizontalTextAlignment::Graphic3d_HTA_LEFT)
		.value("Graphic3d_HTA_CENTER", Graphic3d_HorizontalTextAlignment::Graphic3d_HTA_CENTER)
		.value("Graphic3d_HTA_RIGHT", Graphic3d_HorizontalTextAlignment::Graphic3d_HTA_RIGHT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_VerticalTextAlignment.hxx
	py::enum_<Graphic3d_VerticalTextAlignment>(mod, "Graphic3d_VerticalTextAlignment", "Defines the vertical position of the text relative to its anchor.")
		.value("Graphic3d_VTA_BOTTOM", Graphic3d_VerticalTextAlignment::Graphic3d_VTA_BOTTOM)
		.value("Graphic3d_VTA_CENTER", Graphic3d_VerticalTextAlignment::Graphic3d_VTA_CENTER)
		.value("Graphic3d_VTA_TOP", Graphic3d_VerticalTextAlignment::Graphic3d_VTA_TOP)
		.value("Graphic3d_VTA_TOPFIRSTLINE", Graphic3d_VerticalTextAlignment::Graphic3d_VTA_TOPFIRSTLINE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfPrimitiveArray.hxx
	py::enum_<Graphic3d_TypeOfPrimitiveArray>(mod, "Graphic3d_TypeOfPrimitiveArray", "The type of primitive array in a group in a structure.")
		.value("Graphic3d_TOPA_UNDEFINED", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_UNDEFINED)
		.value("Graphic3d_TOPA_POINTS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_POINTS)
		.value("Graphic3d_TOPA_POLYLINES", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_POLYLINES)
		.value("Graphic3d_TOPA_SEGMENTS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_SEGMENTS)
		.value("Graphic3d_TOPA_POLYGONS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_POLYGONS)
		.value("Graphic3d_TOPA_TRIANGLES", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLES)
		.value("Graphic3d_TOPA_QUADRANGLES", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_QUADRANGLES)
		.value("Graphic3d_TOPA_TRIANGLESTRIPS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLESTRIPS)
		.value("Graphic3d_TOPA_QUADRANGLESTRIPS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_QUADRANGLESTRIPS)
		.value("Graphic3d_TOPA_TRIANGLEFANS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLEFANS)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Buffer.hxx
	py::enum_<Graphic3d_TypeOfAttribute>(mod, "Graphic3d_TypeOfAttribute", "Type of attribute in Vertex Buffer")
		.value("Graphic3d_TOA_POS", Graphic3d_TypeOfAttribute::Graphic3d_TOA_POS)
		.value("Graphic3d_TOA_NORM", Graphic3d_TypeOfAttribute::Graphic3d_TOA_NORM)
		.value("Graphic3d_TOA_UV", Graphic3d_TypeOfAttribute::Graphic3d_TOA_UV)
		.value("Graphic3d_TOA_COLOR", Graphic3d_TypeOfAttribute::Graphic3d_TOA_COLOR)
		.value("Graphic3d_TOA_CUSTOM", Graphic3d_TypeOfAttribute::Graphic3d_TOA_CUSTOM)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Buffer.hxx
	py::enum_<Graphic3d_TypeOfData>(mod, "Graphic3d_TypeOfData", "Type of the element in Vertex or Index Buffer")
		.value("Graphic3d_TOD_USHORT", Graphic3d_TypeOfData::Graphic3d_TOD_USHORT)
		.value("Graphic3d_TOD_UINT", Graphic3d_TypeOfData::Graphic3d_TOD_UINT)
		.value("Graphic3d_TOD_VEC2", Graphic3d_TypeOfData::Graphic3d_TOD_VEC2)
		.value("Graphic3d_TOD_VEC3", Graphic3d_TypeOfData::Graphic3d_TOD_VEC3)
		.value("Graphic3d_TOD_VEC4", Graphic3d_TypeOfData::Graphic3d_TOD_VEC4)
		.value("Graphic3d_TOD_VEC4UB", Graphic3d_TypeOfData::Graphic3d_TOD_VEC4UB)
		.value("Graphic3d_TOD_FLOAT", Graphic3d_TypeOfData::Graphic3d_TOD_FLOAT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CappingFlags.hxx
	py::enum_<Graphic3d_CappingFlags>(mod, "Graphic3d_CappingFlags", "Enumeration of capping flags.")
		.value("Graphic3d_CappingFlags_None", Graphic3d_CappingFlags::Graphic3d_CappingFlags_None)
		.value("Graphic3d_CappingFlags_ObjectMaterial", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectMaterial)
		.value("Graphic3d_CappingFlags_ObjectTexture", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectTexture)
		.value("Graphic3d_CappingFlags_ObjectShader", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectShader)
		.value("Graphic3d_CappingFlags_ObjectAspect", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectAspect)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfComposition.hxx
	py::enum_<Graphic3d_TypeOfComposition>(mod, "Graphic3d_TypeOfComposition", "To manage the transformation matrices of structures.")
		.value("Graphic3d_TOC_REPLACE", Graphic3d_TypeOfComposition::Graphic3d_TOC_REPLACE)
		.value("Graphic3d_TOC_POSTCONCATENATE", Graphic3d_TypeOfComposition::Graphic3d_TOC_POSTCONCATENATE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TransModeFlags.hxx
	py::enum_<Graphic3d_TransModeFlags>(mod, "Graphic3d_TransModeFlags", "Transform Persistence Mode defining whether to lock in object position, rotation and / or zooming relative to camera position.")
		.value("Graphic3d_TMF_None", Graphic3d_TransModeFlags::Graphic3d_TMF_None)
		.value("Graphic3d_TMF_ZoomPers", Graphic3d_TransModeFlags::Graphic3d_TMF_ZoomPers)
		.value("Graphic3d_TMF_RotatePers", Graphic3d_TransModeFlags::Graphic3d_TMF_RotatePers)
		.value("Graphic3d_TMF_TriedronPers", Graphic3d_TransModeFlags::Graphic3d_TMF_TriedronPers)
		.value("Graphic3d_TMF_2d", Graphic3d_TransModeFlags::Graphic3d_TMF_2d)
		.value("Graphic3d_TMF_ZoomRotatePers", Graphic3d_TransModeFlags::Graphic3d_TMF_ZoomRotatePers)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_DiagnosticInfo.hxx
	py::enum_<Graphic3d_DiagnosticInfo>(mod, "Graphic3d_DiagnosticInfo", "Diagnostic info categories bit flags.")
		.value("Graphic3d_DiagnosticInfo_Device", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Device)
		.value("Graphic3d_DiagnosticInfo_FrameBuffer", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_FrameBuffer)
		.value("Graphic3d_DiagnosticInfo_Limits", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Limits)
		.value("Graphic3d_DiagnosticInfo_Memory", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Memory)
		.value("Graphic3d_DiagnosticInfo_NativePlatform", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_NativePlatform)
		.value("Graphic3d_DiagnosticInfo_Extensions", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Extensions)
		.value("Graphic3d_DiagnosticInfo_Short", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Short)
		.value("Graphic3d_DiagnosticInfo_Basic", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Basic)
		.value("Graphic3d_DiagnosticInfo_Complete", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Complete)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ExportFormat.hxx
	py::enum_<Graphic3d_ExportFormat>(mod, "Graphic3d_ExportFormat", "None")
		.value("Graphic3d_EF_PostScript", Graphic3d_ExportFormat::Graphic3d_EF_PostScript)
		.value("Graphic3d_EF_EnhPostScript", Graphic3d_ExportFormat::Graphic3d_EF_EnhPostScript)
		.value("Graphic3d_EF_TEX", Graphic3d_ExportFormat::Graphic3d_EF_TEX)
		.value("Graphic3d_EF_PDF", Graphic3d_ExportFormat::Graphic3d_EF_PDF)
		.value("Graphic3d_EF_SVG", Graphic3d_ExportFormat::Graphic3d_EF_SVG)
		.value("Graphic3d_EF_PGF", Graphic3d_ExportFormat::Graphic3d_EF_PGF)
		.value("Graphic3d_EF_EMF", Graphic3d_ExportFormat::Graphic3d_EF_EMF)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_RenderTransparentMethod.hxx
	py::enum_<Graphic3d_RenderTransparentMethod>(mod, "Graphic3d_RenderTransparentMethod", "Enumerates transparency rendering methods supported by rasterization mode.")
		.value("Graphic3d_RTM_BLEND_UNORDERED", Graphic3d_RenderTransparentMethod::Graphic3d_RTM_BLEND_UNORDERED)
		.value("Graphic3d_RTM_BLEND_OIT", Graphic3d_RenderTransparentMethod::Graphic3d_RTM_BLEND_OIT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_RenderingMode.hxx
	py::enum_<Graphic3d_RenderingMode>(mod, "Graphic3d_RenderingMode", "Describes rendering modes. - RM_RASTERIZATION: enables OpenGL rasterization mode; - RM_RAYTRACING: enables GPU ray-tracing mode.")
		.value("Graphic3d_RM_RASTERIZATION", Graphic3d_RenderingMode::Graphic3d_RM_RASTERIZATION)
		.value("Graphic3d_RM_RAYTRACING", Graphic3d_RenderingMode::Graphic3d_RM_RAYTRACING)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_StereoMode.hxx
	py::enum_<Graphic3d_StereoMode>(mod, "Graphic3d_StereoMode", "This enumeration defines the list of stereoscopic output modes.")
		.value("Graphic3d_StereoMode_QuadBuffer", Graphic3d_StereoMode::Graphic3d_StereoMode_QuadBuffer)
		.value("Graphic3d_StereoMode_Anaglyph", Graphic3d_StereoMode::Graphic3d_StereoMode_Anaglyph)
		.value("Graphic3d_StereoMode_RowInterlaced", Graphic3d_StereoMode::Graphic3d_StereoMode_RowInterlaced)
		.value("Graphic3d_StereoMode_ColumnInterlaced", Graphic3d_StereoMode::Graphic3d_StereoMode_ColumnInterlaced)
		.value("Graphic3d_StereoMode_ChessBoard", Graphic3d_StereoMode::Graphic3d_StereoMode_ChessBoard)
		.value("Graphic3d_StereoMode_SideBySide", Graphic3d_StereoMode::Graphic3d_StereoMode_SideBySide)
		.value("Graphic3d_StereoMode_OverUnder", Graphic3d_StereoMode::Graphic3d_StereoMode_OverUnder)
		.value("Graphic3d_StereoMode_SoftPageFlip", Graphic3d_StereoMode::Graphic3d_StereoMode_SoftPageFlip)
		.value("Graphic3d_StereoMode_NB", Graphic3d_StereoMode::Graphic3d_StereoMode_NB)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ToneMappingMethod.hxx
	py::enum_<Graphic3d_ToneMappingMethod>(mod, "Graphic3d_ToneMappingMethod", "Enumerates tone mapping methods.")
		.value("Graphic3d_ToneMappingMethod_Disabled", Graphic3d_ToneMappingMethod::Graphic3d_ToneMappingMethod_Disabled)
		.value("Graphic3d_ToneMappingMethod_Filmic", Graphic3d_ToneMappingMethod::Graphic3d_ToneMappingMethod_Filmic)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfStructure.hxx
	py::enum_<Graphic3d_TypeOfStructure>(mod, "Graphic3d_TypeOfStructure", "Structural attribute indicating if it can be displayed in wireframe, shadow mode, or both.")
		.value("Graphic3d_TOS_WIREFRAME", Graphic3d_TypeOfStructure::Graphic3d_TOS_WIREFRAME)
		.value("Graphic3d_TOS_SHADING", Graphic3d_TypeOfStructure::Graphic3d_TOS_SHADING)
		.value("Graphic3d_TOS_COMPUTED", Graphic3d_TypeOfStructure::Graphic3d_TOS_COMPUTED)
		.value("Graphic3d_TOS_ALL", Graphic3d_TypeOfStructure::Graphic3d_TOS_ALL)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfConnection.hxx
	py::enum_<Graphic3d_TypeOfConnection>(mod, "Graphic3d_TypeOfConnection", "To manage the connections between the structures.")
		.value("Graphic3d_TOC_ANCESTOR", Graphic3d_TypeOfConnection::Graphic3d_TOC_ANCESTOR)
		.value("Graphic3d_TOC_DESCENDANT", Graphic3d_TypeOfConnection::Graphic3d_TOC_DESCENDANT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_SortType.hxx
	py::enum_<Graphic3d_SortType>(mod, "Graphic3d_SortType", "None")
		.value("Graphic3d_ST_Simple", Graphic3d_SortType::Graphic3d_ST_Simple)
		.value("Graphic3d_ST_BSP_Tree", Graphic3d_SortType::Graphic3d_ST_BSP_Tree)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_NameOfTextureEnv.hxx
	py::enum_<Graphic3d_NameOfTextureEnv>(mod, "Graphic3d_NameOfTextureEnv", "Types of standard textures.")
		.value("Graphic3d_NOT_ENV_CLOUDS", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_CLOUDS)
		.value("Graphic3d_NOT_ENV_CV", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_CV)
		.value("Graphic3d_NOT_ENV_MEDIT", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_MEDIT)
		.value("Graphic3d_NOT_ENV_PEARL", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_PEARL)
		.value("Graphic3d_NOT_ENV_SKY1", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_SKY1)
		.value("Graphic3d_NOT_ENV_SKY2", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_SKY2)
		.value("Graphic3d_NOT_ENV_LINES", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_LINES)
		.value("Graphic3d_NOT_ENV_ROAD", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_ROAD)
		.value("Graphic3d_NOT_ENV_UNKNOWN", Graphic3d_NameOfTextureEnv::Graphic3d_NOT_ENV_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfAnswer.hxx
	py::enum_<Graphic3d_TypeOfAnswer>(mod, "Graphic3d_TypeOfAnswer", "The answer of the method AcceptDisplay AcceptDisplay means is it possible to display the specified structure in the specified view ? TOA_YES yes TOA_NO no TOA_COMPUTE yes but we have to compute the representation")
		.value("Graphic3d_TOA_YES", Graphic3d_TypeOfAnswer::Graphic3d_TOA_YES)
		.value("Graphic3d_TOA_NO", Graphic3d_TypeOfAnswer::Graphic3d_TOA_NO)
		.value("Graphic3d_TOA_COMPUTE", Graphic3d_TypeOfAnswer::Graphic3d_TOA_COMPUTE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfBackfacingModel.hxx
	py::enum_<Graphic3d_TypeOfBackfacingModel>(mod, "Graphic3d_TypeOfBackfacingModel", "Modes of display of back faces in the view")
		.value("Graphic3d_TOBM_AUTOMATIC", Graphic3d_TypeOfBackfacingModel::Graphic3d_TOBM_AUTOMATIC)
		.value("Graphic3d_TOBM_FORCE", Graphic3d_TypeOfBackfacingModel::Graphic3d_TOBM_FORCE)
		.value("Graphic3d_TOBM_DISABLE", Graphic3d_TypeOfBackfacingModel::Graphic3d_TOBM_DISABLE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfShadingModel.hxx
	py::enum_<Graphic3d_TypeOfShadingModel>(mod, "Graphic3d_TypeOfShadingModel", "Definition of the rendering (colour shading) model Graphic3d_TOSM_NONE No lighting, only white ambient light Graphic3d_TOSM_FACET No interpolation, constant shading (Flat Shading) Graphic3d_TOSM_VERTEX Interpolation of color based on normals (Gouraud Shading) Graphic3d_TOSM_FRAGMENT Interpolation of color based on normals (Phong Shading)")
		.value("Graphic3d_TOSM_NONE", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_NONE)
		.value("Graphic3d_TOSM_FACET", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_FACET)
		.value("Graphic3d_TOSM_VERTEX", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_VERTEX)
		.value("Graphic3d_TOSM_FRAGMENT", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_FRAGMENT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfVisualization.hxx
	py::enum_<Graphic3d_TypeOfVisualization>(mod, "Graphic3d_TypeOfVisualization", "Modes of visualisation of objects in a view")
		.value("Graphic3d_TOV_WIREFRAME", Graphic3d_TypeOfVisualization::Graphic3d_TOV_WIREFRAME)
		.value("Graphic3d_TOV_SHADING", Graphic3d_TypeOfVisualization::Graphic3d_TOV_SHADING)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ZLayerSettings.hxx
	py::enum_<Graphic3d_ZLayerSetting>(mod, "Graphic3d_ZLayerSetting", "None")
		.value("Graphic3d_ZLayerDepthTest", Graphic3d_ZLayerSetting::Graphic3d_ZLayerDepthTest)
		.value("Graphic3d_ZLayerDepthWrite", Graphic3d_ZLayerSetting::Graphic3d_ZLayerDepthWrite)
		.value("Graphic3d_ZLayerDepthClear", Graphic3d_ZLayerSetting::Graphic3d_ZLayerDepthClear)
		.value("Graphic3d_ZLayerDepthOffset", Graphic3d_ZLayerSetting::Graphic3d_ZLayerDepthOffset)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_NameOfTexture2D.hxx
	py::enum_<Graphic3d_NameOfTexture2D>(mod, "Graphic3d_NameOfTexture2D", "Types of standard textures.")
		.value("Graphic3d_NOT_2D_MATRA", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MATRA)
		.value("Graphic3d_NOT_2D_ALIENSKIN", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_ALIENSKIN)
		.value("Graphic3d_NOT_2D_BLUE_ROCK", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BLUE_ROCK)
		.value("Graphic3d_NOT_2D_BLUEWHITE_PAPER", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BLUEWHITE_PAPER)
		.value("Graphic3d_NOT_2D_BRUSHED", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BRUSHED)
		.value("Graphic3d_NOT_2D_BUBBLES", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BUBBLES)
		.value("Graphic3d_NOT_2D_BUMP", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BUMP)
		.value("Graphic3d_NOT_2D_CAST", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CAST)
		.value("Graphic3d_NOT_2D_CHIPBD", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CHIPBD)
		.value("Graphic3d_NOT_2D_CLOUDS", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CLOUDS)
		.value("Graphic3d_NOT_2D_FLESH", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_FLESH)
		.value("Graphic3d_NOT_2D_FLOOR", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_FLOOR)
		.value("Graphic3d_NOT_2D_GALVNISD", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_GALVNISD)
		.value("Graphic3d_NOT_2D_GRASS", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_GRASS)
		.value("Graphic3d_NOT_2D_ALUMINUM", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_ALUMINUM)
		.value("Graphic3d_NOT_2D_ROCK", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_ROCK)
		.value("Graphic3d_NOT_2D_KNURL", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_KNURL)
		.value("Graphic3d_NOT_2D_MAPLE", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MAPLE)
		.value("Graphic3d_NOT_2D_MARBLE", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MARBLE)
		.value("Graphic3d_NOT_2D_MOTTLED", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MOTTLED)
		.value("Graphic3d_NOT_2D_RAIN", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_RAIN)
		.value("Graphic3d_NOT_2D_CHESS", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CHESS)
		.value("Graphic3d_NOT_2D_UNKNOWN", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfLimit.hxx
	py::enum_<Graphic3d_TypeOfLimit>(mod, "Graphic3d_TypeOfLimit", "Type of graphic resource limit.")
		.value("Graphic3d_TypeOfLimit_MaxNbLights", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxNbLights)
		.value("Graphic3d_TypeOfLimit_MaxNbClipPlanes", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxNbClipPlanes)
		.value("Graphic3d_TypeOfLimit_MaxNbViews", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxNbViews)
		.value("Graphic3d_TypeOfLimit_MaxTextureSize", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxTextureSize)
		.value("Graphic3d_TypeOfLimit_MaxCombinedTextureUnits", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxCombinedTextureUnits)
		.value("Graphic3d_TypeOfLimit_MaxMsaa", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxMsaa)
		.value("Graphic3d_TypeOfLimit_HasRayTracing", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasRayTracing)
		.value("Graphic3d_TypeOfLimit_HasRayTracingTextures", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasRayTracingTextures)
		.value("Graphic3d_TypeOfLimit_HasRayTracingAdaptiveSampling", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasRayTracingAdaptiveSampling)
		.value("Graphic3d_TypeOfLimit_HasBlendedOit", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasBlendedOit)
		.value("Graphic3d_TypeOfLimit_HasBlendedOitMsaa", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasBlendedOitMsaa)
		.value("Graphic3d_TypeOfLimit_NB", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_NB)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_NameOfTexture1D.hxx
	py::enum_<Graphic3d_NameOfTexture1D>(mod, "Graphic3d_NameOfTexture1D", "Types of standard textures.")
		.value("Graphic3d_NOT_1D_ELEVATION", Graphic3d_NameOfTexture1D::Graphic3d_NOT_1D_ELEVATION)
		.value("Graphic3d_NOT_1D_UNKNOWN", Graphic3d_NameOfTexture1D::Graphic3d_NOT_1D_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_NameOfTexturePlane.hxx
	py::enum_<Graphic3d_NameOfTexturePlane>(mod, "Graphic3d_NameOfTexturePlane", "Type of the texture projection plane for both S and T texture coordinate.")
		.value("Graphic3d_NOTP_XY", Graphic3d_NameOfTexturePlane::Graphic3d_NOTP_XY)
		.value("Graphic3d_NOTP_YZ", Graphic3d_NameOfTexturePlane::Graphic3d_NOTP_YZ)
		.value("Graphic3d_NOTP_ZX", Graphic3d_NameOfTexturePlane::Graphic3d_NOTP_ZX)
		.value("Graphic3d_NOTP_UNKNOWN", Graphic3d_NameOfTexturePlane::Graphic3d_NOTP_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TypeOfBackground.hxx
	py::enum_<Graphic3d_TypeOfBackground>(mod, "Graphic3d_TypeOfBackground", "Describes type of view background.")
		.value("Graphic3d_TOB_NONE", Graphic3d_TypeOfBackground::Graphic3d_TOB_NONE)
		.value("Graphic3d_TOB_GRADIENT", Graphic3d_TypeOfBackground::Graphic3d_TOB_GRADIENT)
		.value("Graphic3d_TOB_TEXTURE", Graphic3d_TypeOfBackground::Graphic3d_TOB_TEXTURE)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_HatchStyle.hxx
	py::class_<Graphic3d_HatchStyle, opencascade::handle<Graphic3d_HatchStyle>, Standard_Transient> cls_Graphic3d_HatchStyle(mod, "Graphic3d_HatchStyle", "A class that provides an API to use standard OCCT hatch styles defined in Aspect_HatchStyle enum or to create custom styles from a user-defined bitmap");
	cls_Graphic3d_HatchStyle.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePattern"));
	cls_Graphic3d_HatchStyle.def(py::init<const Aspect_HatchStyle>(), py::arg("theType"));
	cls_Graphic3d_HatchStyle.def_static("get_type_name_", (const char * (*)()) &Graphic3d_HatchStyle::get_type_name, "None");
	cls_Graphic3d_HatchStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_HatchStyle::get_type_descriptor, "None");
	cls_Graphic3d_HatchStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_HatchStyle::*)() const ) &Graphic3d_HatchStyle::DynamicType, "None");
	cls_Graphic3d_HatchStyle.def("Pattern", (const Standard_Byte * (Graphic3d_HatchStyle::*)() const ) &Graphic3d_HatchStyle::Pattern, "Returns the pattern of custom hatch style");
	cls_Graphic3d_HatchStyle.def("HatchType", (Standard_Integer (Graphic3d_HatchStyle::*)() const ) &Graphic3d_HatchStyle::HatchType, "In case if predefined OCCT style is used, returns index in Aspect_HatchStyle enumeration. If the style is custom, returns unique index of the style");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BSDF.hxx
	py::class_<Graphic3d_Fresnel, std::unique_ptr<Graphic3d_Fresnel, Deleter<Graphic3d_Fresnel>>> cls_Graphic3d_Fresnel(mod, "Graphic3d_Fresnel", "Describes Fresnel reflectance parameters.");
	cls_Graphic3d_Fresnel.def(py::init<>());
	cls_Graphic3d_Fresnel.def_static("CreateSchlick_", (Graphic3d_Fresnel (*)(const Graphic3d_Vec3 &)) &Graphic3d_Fresnel::CreateSchlick, "Creates Schlick's approximation of Fresnel factor.", py::arg("theSpecularColor"));
	cls_Graphic3d_Fresnel.def_static("CreateConstant_", (Graphic3d_Fresnel (*)(const Standard_ShortReal)) &Graphic3d_Fresnel::CreateConstant, "Creates Fresnel factor for constant reflection.", py::arg("theReflection"));
	cls_Graphic3d_Fresnel.def_static("CreateDielectric_", (Graphic3d_Fresnel (*)(Standard_ShortReal)) &Graphic3d_Fresnel::CreateDielectric, "Creates Fresnel factor for physical-based dielectric model.", py::arg("theRefractionIndex"));
	cls_Graphic3d_Fresnel.def_static("CreateConductor_", (Graphic3d_Fresnel (*)(Standard_ShortReal, Standard_ShortReal)) &Graphic3d_Fresnel::CreateConductor, "Creates Fresnel factor for physical-based conductor model.", py::arg("theRefractionIndex"), py::arg("theAbsorptionIndex"));
	cls_Graphic3d_Fresnel.def_static("CreateConductor_", (Graphic3d_Fresnel (*)(const Graphic3d_Vec3 &, const Graphic3d_Vec3 &)) &Graphic3d_Fresnel::CreateConductor, "Creates Fresnel factor for physical-based conductor model (spectral version).", py::arg("theRefractionIndex"), py::arg("theAbsorptionIndex"));
	cls_Graphic3d_Fresnel.def("Serialize", (Graphic3d_Vec4 (Graphic3d_Fresnel::*)() const ) &Graphic3d_Fresnel::Serialize, "Returns serialized representation of Fresnel factor.");
	cls_Graphic3d_Fresnel.def("__eq__", (bool (Graphic3d_Fresnel::*)(const Graphic3d_Fresnel &) const ) &Graphic3d_Fresnel::operator==, py::is_operator(), "Performs comparison of two objects describing Fresnel factor.", py::arg("theOther"));
	cls_Graphic3d_Fresnel.def("FresnelType", (Graphic3d_FresnelModel (Graphic3d_Fresnel::*)() const ) &Graphic3d_Fresnel::FresnelType, "Returns type of Fresnel.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BSDF.hxx
	py::class_<Graphic3d_BSDF, std::unique_ptr<Graphic3d_BSDF, Deleter<Graphic3d_BSDF>>> cls_Graphic3d_BSDF(mod, "Graphic3d_BSDF", "Describes material's BSDF (Bidirectional Scattering Distribution Function) used for physically-based rendering (in path tracing engine). BSDF is represented as weighted mixture of basic BRDFs/BTDFs (Bidirectional Reflectance (Transmittance) Distribution Functions).");
	cls_Graphic3d_BSDF.def(py::init<>());
	cls_Graphic3d_BSDF.def_static("CreateDiffuse_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &)) &Graphic3d_BSDF::CreateDiffuse, "Creates BSDF describing diffuse (Lambertian) surface.", py::arg("theWeight"));
	cls_Graphic3d_BSDF.def_static("CreateMetallic_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &, const Graphic3d_Fresnel &, const Standard_ShortReal)) &Graphic3d_BSDF::CreateMetallic, "Creates BSDF describing polished metallic-like surface.", py::arg("theWeight"), py::arg("theFresnel"), py::arg("theRoughness"));
	cls_Graphic3d_BSDF.def_static("CreateTransparent_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &, const Graphic3d_Vec3 &, const Standard_ShortReal)) &Graphic3d_BSDF::CreateTransparent, "Creates BSDF describing transparent object. Transparent BSDF models simple transparency without refraction (the ray passes straight through the surface).", py::arg("theWeight"), py::arg("theAbsorptionColor"), py::arg("theAbsorptionCoeff"));
	cls_Graphic3d_BSDF.def_static("CreateGlass_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &, const Graphic3d_Vec3 &, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_BSDF::CreateGlass, "Creates BSDF describing glass-like object. Glass-like BSDF mixes refraction and reflection effects at grazing angles using physically-based Fresnel dielectric model.", py::arg("theWeight"), py::arg("theAbsorptionColor"), py::arg("theAbsorptionCoeff"), py::arg("theRefractionIndex"));
	cls_Graphic3d_BSDF.def("Normalize", (void (Graphic3d_BSDF::*)()) &Graphic3d_BSDF::Normalize, "Normalizes BSDF components.");
	cls_Graphic3d_BSDF.def("__eq__", (bool (Graphic3d_BSDF::*)(const Graphic3d_BSDF &) const ) &Graphic3d_BSDF::operator==, py::is_operator(), "Performs comparison of two BSDFs.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_MaterialAspect.hxx
	py::class_<Graphic3d_MaterialAspect, std::unique_ptr<Graphic3d_MaterialAspect, Deleter<Graphic3d_MaterialAspect>>> cls_Graphic3d_MaterialAspect(mod, "Graphic3d_MaterialAspect", "This class allows the definition of the type of a surface. Aspect attributes of a 3d face. Keywords: Material, FillArea, Shininess, Ambient, Color, Diffuse, Specular, Transparency, Emissive, ReflectionMode, BackFace, FrontFace, Reflection, Absorbtion");
	cls_Graphic3d_MaterialAspect.def(py::init<>());
	cls_Graphic3d_MaterialAspect.def(py::init<const Graphic3d_NameOfMaterial>(), py::arg("theName"));
	cls_Graphic3d_MaterialAspect.def_static("NumberOfMaterials_", (Standard_Integer (*)()) &Graphic3d_MaterialAspect::NumberOfMaterials, "Returns the number of predefined textures.");
	cls_Graphic3d_MaterialAspect.def_static("MaterialName_", (Standard_CString (*)(const Standard_Integer)) &Graphic3d_MaterialAspect::MaterialName, "Returns the name of the predefined material of specified rank within range [1, NumberOfMaterials()].", py::arg("theRank"));
	cls_Graphic3d_MaterialAspect.def_static("MaterialType_", (Graphic3d_TypeOfMaterial (*)(const Standard_Integer)) &Graphic3d_MaterialAspect::MaterialType, "Returns the type of the predefined material of specified rank within range [1, NumberOfMaterials()].", py::arg("theRank"));
	cls_Graphic3d_MaterialAspect.def_static("MaterialFromName_", (Graphic3d_NameOfMaterial (*)(const Standard_CString)) &Graphic3d_MaterialAspect::MaterialFromName, "Returns the material for specified name or Graphic3d_NOM_DEFAULT if name is unknown.", py::arg("theName"));
	cls_Graphic3d_MaterialAspect.def("Name", (Graphic3d_NameOfMaterial (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Name, "Returns the material name (within predefined enumeration).");
	cls_Graphic3d_MaterialAspect.def("RequestedName", (Graphic3d_NameOfMaterial (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::RequestedName, "Returns the material name within predefined enumeration which has been requested (before modifications).");
	cls_Graphic3d_MaterialAspect.def("StringName", (const TCollection_AsciiString & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::StringName, "Returns the given name of this material. This might be: - given name set by method ::SetMaterialName() - standard name for a material within enumeration - 'UserDefined' for non-standard material without name specified externally.");
	cls_Graphic3d_MaterialAspect.def("MaterialName", (Standard_CString (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::MaterialName, "Returns the given name of this material. This might be:");
	cls_Graphic3d_MaterialAspect.def("SetMaterialName", (void (Graphic3d_MaterialAspect::*)(const TCollection_AsciiString &)) &Graphic3d_MaterialAspect::SetMaterialName, "The current material become a 'UserDefined' material. Set the name of the 'UserDefined' material.", py::arg("theName"));
	cls_Graphic3d_MaterialAspect.def("Reset", (void (Graphic3d_MaterialAspect::*)()) &Graphic3d_MaterialAspect::Reset, "Resets the material with the original values according to the material name but leave the current color values untouched for the material of type ASPECT.");
	cls_Graphic3d_MaterialAspect.def("Color", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Color, "Returns the diffuse color of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetColor, "Modifies the ambient and diffuse color of the surface.", py::arg("theColor"));
	cls_Graphic3d_MaterialAspect.def("Transparency", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Transparency, "Returns the transparency coefficient of the surface (1.0 - Alpha); 0.0 means opaque.");
	cls_Graphic3d_MaterialAspect.def("Alpha", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Alpha, "Returns the alpha coefficient of the surface (1.0 - Transparency); 1.0 means opaque.");
	cls_Graphic3d_MaterialAspect.def("SetTransparency", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetTransparency, "Modifies the transparency coefficient of the surface, where 0 is opaque and 1 is fully transparent. Transparency is applicable to materials that have at least one of reflection modes (ambient, diffuse, specular or emissive) enabled. See also SetReflectionModeOn() and SetReflectionModeOff() methods.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("SetAlpha", (void (Graphic3d_MaterialAspect::*)(Standard_ShortReal)) &Graphic3d_MaterialAspect::SetAlpha, "Modifies the alpha coefficient of the surface, where 1.0 is opaque and 0.0 is fully transparent.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("AmbientColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::AmbientColor, "Returns the ambient color of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetAmbientColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetAmbientColor, "Modifies the ambient color of the surface.", py::arg("theColor"));
	cls_Graphic3d_MaterialAspect.def("DiffuseColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::DiffuseColor, "Returns the diffuse color of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetDiffuseColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetDiffuseColor, "Modifies the diffuse color of the surface.", py::arg("theColor"));
	cls_Graphic3d_MaterialAspect.def("SpecularColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::SpecularColor, "Returns the specular color of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetSpecularColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetSpecularColor, "Modifies the specular color of the surface.", py::arg("theColor"));
	cls_Graphic3d_MaterialAspect.def("EmissiveColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::EmissiveColor, "Returns the emissive color of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetEmissiveColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetEmissiveColor, "Modifies the emissive color of the surface.", py::arg("theColor"));
	cls_Graphic3d_MaterialAspect.def("Ambient", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Ambient, "Returns the reflection properties of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetAmbient", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetAmbient, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("Diffuse", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Diffuse, "Returns the reflection properties of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetDiffuse", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetDiffuse, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("Specular", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Specular, "Returns the reflection properties of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetSpecular", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetSpecular, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("Emissive", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Emissive, "Returns the emissive coefficient of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetEmissive", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetEmissive, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("Shininess", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::Shininess, "Returns the luminosity of the surface.");
	cls_Graphic3d_MaterialAspect.def("SetShininess", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetShininess, "Modifies the luminosity of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("IncreaseShine", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::IncreaseShine, "Increases or decreases the luminosity.", py::arg("theDelta"));
	cls_Graphic3d_MaterialAspect.def("RefractionIndex", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::RefractionIndex, "Returns the refraction index of the material");
	cls_Graphic3d_MaterialAspect.def("SetRefractionIndex", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetRefractionIndex, "Modifies the refraction index of the material. Warning: Raises MaterialDefinitionError if given value is a lesser than 1.0.", py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("BSDF", (const Graphic3d_BSDF & (Graphic3d_MaterialAspect::*)() const ) &Graphic3d_MaterialAspect::BSDF, "Returns BSDF (bidirectional scattering distribution function).");
	cls_Graphic3d_MaterialAspect.def("SetBSDF", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_BSDF &)) &Graphic3d_MaterialAspect::SetBSDF, "Modifies the BSDF (bidirectional scattering distribution function).", py::arg("theBSDF"));
	cls_Graphic3d_MaterialAspect.def("ReflectionMode", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection) const ) &Graphic3d_MaterialAspect::ReflectionMode, "Returns TRUE if the reflection mode is active, FALSE otherwise.", py::arg("theType"));
	cls_Graphic3d_MaterialAspect.def("SetReflectionMode", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection, const Standard_Boolean)) &Graphic3d_MaterialAspect::SetReflectionMode, "Activates or deactivates the reflective properties of the surface with specified reflection type.", py::arg("theType"), py::arg("theValue"));
	cls_Graphic3d_MaterialAspect.def("SetReflectionModeOn", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection)) &Graphic3d_MaterialAspect::SetReflectionModeOn, "Activates the reflective properties of the surface with specified reflection type.", py::arg("theType"));
	cls_Graphic3d_MaterialAspect.def("SetReflectionModeOff", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection)) &Graphic3d_MaterialAspect::SetReflectionModeOff, "Deactivates the reflective properties of the surface with specified reflection type.", py::arg("theType"));
	cls_Graphic3d_MaterialAspect.def("MaterialType", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfMaterial) const ) &Graphic3d_MaterialAspect::MaterialType, "Returns TRUE if type of this material is equal to specified type.", py::arg("theType"));
	cls_Graphic3d_MaterialAspect.def("SetMaterialType", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfMaterial)) &Graphic3d_MaterialAspect::SetMaterialType, "Set material type.", py::arg("theType"));
	cls_Graphic3d_MaterialAspect.def("IsDifferent", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const ) &Graphic3d_MaterialAspect::IsDifferent, "Returns TRUE if this material differs from specified one.", py::arg("theOther"));
	cls_Graphic3d_MaterialAspect.def("__ne__", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const ) &Graphic3d_MaterialAspect::operator!=, py::is_operator(), "Returns TRUE if this material differs from specified one.", py::arg("theOther"));
	cls_Graphic3d_MaterialAspect.def("IsEqual", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const ) &Graphic3d_MaterialAspect::IsEqual, "Returns TRUE if this material is identical to specified one.", py::arg("theOther"));
	cls_Graphic3d_MaterialAspect.def("__eq__", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const ) &Graphic3d_MaterialAspect::operator==, py::is_operator(), "Returns TRUE if this material is identical to specified one.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_PolygonOffset.hxx
	py::class_<Graphic3d_PolygonOffset, std::unique_ptr<Graphic3d_PolygonOffset, Deleter<Graphic3d_PolygonOffset>>> cls_Graphic3d_PolygonOffset(mod, "Graphic3d_PolygonOffset", "Polygon offset parameters.");
	cls_Graphic3d_PolygonOffset.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderAttribute.hxx
	py::class_<Graphic3d_ShaderAttribute, opencascade::handle<Graphic3d_ShaderAttribute>, Standard_Transient> cls_Graphic3d_ShaderAttribute(mod, "Graphic3d_ShaderAttribute", "Describes custom vertex shader attribute.");
	cls_Graphic3d_ShaderAttribute.def(py::init<const TCollection_AsciiString &, const int>(), py::arg("theName"), py::arg("theLocation"));
	cls_Graphic3d_ShaderAttribute.def("Name", (const TCollection_AsciiString & (Graphic3d_ShaderAttribute::*)() const ) &Graphic3d_ShaderAttribute::Name, "Returns name of shader variable.");
	cls_Graphic3d_ShaderAttribute.def("Location", (int (Graphic3d_ShaderAttribute::*)() const ) &Graphic3d_ShaderAttribute::Location, "Returns attribute location to be bound on GLSL program linkage stage.");
	cls_Graphic3d_ShaderAttribute.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderAttribute::get_type_name, "None");
	cls_Graphic3d_ShaderAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderAttribute::get_type_descriptor, "None");
	cls_Graphic3d_ShaderAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderAttribute::*)() const ) &Graphic3d_ShaderAttribute::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderObject.hxx
	py::class_<Graphic3d_ShaderObject, opencascade::handle<Graphic3d_ShaderObject>, Standard_Transient> cls_Graphic3d_ShaderObject(mod, "Graphic3d_ShaderObject", "This class is responsible for managing shader objects.");
	cls_Graphic3d_ShaderObject.def("IsDone", (Standard_Boolean (Graphic3d_ShaderObject::*)() const ) &Graphic3d_ShaderObject::IsDone, "Checks if the shader object is valid or not.");
	cls_Graphic3d_ShaderObject.def("Path", (const OSD_Path & (Graphic3d_ShaderObject::*)() const ) &Graphic3d_ShaderObject::Path, "Returns the full path to the shader source.");
	cls_Graphic3d_ShaderObject.def("Source", (const TCollection_AsciiString & (Graphic3d_ShaderObject::*)() const ) &Graphic3d_ShaderObject::Source, "Returns the source code of the shader object.");
	cls_Graphic3d_ShaderObject.def("Type", (Graphic3d_TypeOfShaderObject (Graphic3d_ShaderObject::*)() const ) &Graphic3d_ShaderObject::Type, "Returns type of the shader object.");
	cls_Graphic3d_ShaderObject.def("GetId", (const TCollection_AsciiString & (Graphic3d_ShaderObject::*)() const ) &Graphic3d_ShaderObject::GetId, "Returns unique ID used to manage resource in graphic driver.");
	cls_Graphic3d_ShaderObject.def_static("CreateFromFile_", (opencascade::handle<Graphic3d_ShaderObject> (*)(const Graphic3d_TypeOfShaderObject, const TCollection_AsciiString &)) &Graphic3d_ShaderObject::CreateFromFile, "Creates new shader object from specified file.", py::arg("theType"), py::arg("thePath"));
	cls_Graphic3d_ShaderObject.def_static("CreateFromSource_", (opencascade::handle<Graphic3d_ShaderObject> (*)(const Graphic3d_TypeOfShaderObject, const TCollection_AsciiString &)) &Graphic3d_ShaderObject::CreateFromSource, "Creates new shader object from specified source.", py::arg("theType"), py::arg("theSource"));
	cls_Graphic3d_ShaderObject.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderObject::get_type_name, "None");
	cls_Graphic3d_ShaderObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderObject::get_type_descriptor, "None");
	cls_Graphic3d_ShaderObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderObject::*)() const ) &Graphic3d_ShaderObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_ValueInterface, std::unique_ptr<Graphic3d_ValueInterface, Deleter<Graphic3d_ValueInterface>>> cls_Graphic3d_ValueInterface(mod, "Graphic3d_ValueInterface", "Interface for generic variable value.");
	cls_Graphic3d_ValueInterface.def("TypeID", (Standard_Size (Graphic3d_ValueInterface::*)() const ) &Graphic3d_ValueInterface::TypeID, "Returns unique identifier of value type.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Standard_Integer>, std::unique_ptr<Graphic3d_UniformValueTypeID<Standard_Integer>, Deleter<Graphic3d_UniformValueTypeID<Standard_Integer>>>> cls_Graphic3d_UniformValueTypeID_Standard_Integer(mod, "Graphic3d_UniformValueTypeID_Standard_Integer", "None");
	cls_Graphic3d_UniformValueTypeID_Standard_Integer.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Standard_ShortReal>, std::unique_ptr<Graphic3d_UniformValueTypeID<Standard_ShortReal>, Deleter<Graphic3d_UniformValueTypeID<Standard_ShortReal>>>> cls_Graphic3d_UniformValueTypeID_Standard_ShortReal(mod, "Graphic3d_UniformValueTypeID_Standard_ShortReal", "None");
	cls_Graphic3d_UniformValueTypeID_Standard_ShortReal.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Graphic3d_Vec2>, std::unique_ptr<Graphic3d_UniformValueTypeID<Graphic3d_Vec2>, Deleter<Graphic3d_UniformValueTypeID<Graphic3d_Vec2>>>> cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec2(mod, "Graphic3d_UniformValueTypeID_Graphic3d_Vec2", "None");
	cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec2.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Graphic3d_Vec3>, std::unique_ptr<Graphic3d_UniformValueTypeID<Graphic3d_Vec3>, Deleter<Graphic3d_UniformValueTypeID<Graphic3d_Vec3>>>> cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec3(mod, "Graphic3d_UniformValueTypeID_Graphic3d_Vec3", "None");
	cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec3.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Graphic3d_Vec4>, std::unique_ptr<Graphic3d_UniformValueTypeID<Graphic3d_Vec4>, Deleter<Graphic3d_UniformValueTypeID<Graphic3d_Vec4>>>> cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec4(mod, "Graphic3d_UniformValueTypeID_Graphic3d_Vec4", "None");
	cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec4.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Graphic3d_Vec2i>, std::unique_ptr<Graphic3d_UniformValueTypeID<Graphic3d_Vec2i>, Deleter<Graphic3d_UniformValueTypeID<Graphic3d_Vec2i>>>> cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec2i(mod, "Graphic3d_UniformValueTypeID_Graphic3d_Vec2i", "None");
	cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec2i.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Graphic3d_Vec3i>, std::unique_ptr<Graphic3d_UniformValueTypeID<Graphic3d_Vec3i>, Deleter<Graphic3d_UniformValueTypeID<Graphic3d_Vec3i>>>> cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec3i(mod, "Graphic3d_UniformValueTypeID_Graphic3d_Vec3i", "None");
	cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec3i.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<Graphic3d_Vec4i>, std::unique_ptr<Graphic3d_UniformValueTypeID<Graphic3d_Vec4i>, Deleter<Graphic3d_UniformValueTypeID<Graphic3d_Vec4i>>>> cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec4i(mod, "Graphic3d_UniformValueTypeID_Graphic3d_Vec4i", "None");
	cls_Graphic3d_UniformValueTypeID_Graphic3d_Vec4i.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_ShaderVariable, opencascade::handle<Graphic3d_ShaderVariable>, Standard_Transient> cls_Graphic3d_ShaderVariable(mod, "Graphic3d_ShaderVariable", "Describes custom uniform shader variable.");
	cls_Graphic3d_ShaderVariable.def("Name", (const TCollection_AsciiString & (Graphic3d_ShaderVariable::*)() const ) &Graphic3d_ShaderVariable::Name, "Returns name of shader variable.");
	cls_Graphic3d_ShaderVariable.def("IsDone", (Standard_Boolean (Graphic3d_ShaderVariable::*)() const ) &Graphic3d_ShaderVariable::IsDone, "Checks if the shader variable is valid or not.");
	cls_Graphic3d_ShaderVariable.def("Value", (Graphic3d_ValueInterface * (Graphic3d_ShaderVariable::*)()) &Graphic3d_ShaderVariable::Value, "Returns interface of shader variable value.");
	cls_Graphic3d_ShaderVariable.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderVariable::get_type_name, "None");
	cls_Graphic3d_ShaderVariable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderVariable::get_type_descriptor, "None");
	cls_Graphic3d_ShaderVariable.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderVariable::*)() const ) &Graphic3d_ShaderVariable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextureParams.hxx
	py::class_<Graphic3d_TextureParams, opencascade::handle<Graphic3d_TextureParams>, Standard_Transient> cls_Graphic3d_TextureParams(mod, "Graphic3d_TextureParams", "This class describes texture parameters.");
	cls_Graphic3d_TextureParams.def(py::init<>());
	cls_Graphic3d_TextureParams.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureParams::get_type_name, "None");
	cls_Graphic3d_TextureParams.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureParams::get_type_descriptor, "None");
	cls_Graphic3d_TextureParams.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::DynamicType, "None");
	cls_Graphic3d_TextureParams.def("TextureUnit", (Graphic3d_TextureUnit (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::TextureUnit, "Default texture unit to be used, default is Graphic3d_TextureUnit_BaseColor.");
	cls_Graphic3d_TextureParams.def("SetTextureUnit", (void (Graphic3d_TextureParams::*)(Graphic3d_TextureUnit)) &Graphic3d_TextureParams::SetTextureUnit, "Setup default texture unit.", py::arg("theUnit"));
	cls_Graphic3d_TextureParams.def("IsModulate", (Standard_Boolean (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::IsModulate, "Returns TRUE if the texture is modulate. Default value is FALSE.");
	cls_Graphic3d_TextureParams.def("SetModulate", (void (Graphic3d_TextureParams::*)(const Standard_Boolean)) &Graphic3d_TextureParams::SetModulate, "", py::arg("theToModulate"));
	cls_Graphic3d_TextureParams.def("IsRepeat", (Standard_Boolean (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::IsRepeat, "Returns TRUE if the texture repeat is enabled. Default value is FALSE.");
	cls_Graphic3d_TextureParams.def("SetRepeat", (void (Graphic3d_TextureParams::*)(const Standard_Boolean)) &Graphic3d_TextureParams::SetRepeat, "", py::arg("theToRepeat"));
	cls_Graphic3d_TextureParams.def("Filter", (Graphic3d_TypeOfTextureFilter (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::Filter, "Returns texture interpolation filter. Default value is Graphic3d_TOTF_NEAREST.");
	cls_Graphic3d_TextureParams.def("SetFilter", (void (Graphic3d_TextureParams::*)(const Graphic3d_TypeOfTextureFilter)) &Graphic3d_TextureParams::SetFilter, "", py::arg("theFilter"));
	cls_Graphic3d_TextureParams.def("AnisoFilter", (Graphic3d_LevelOfTextureAnisotropy (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::AnisoFilter, "Returns level of anisontropy texture filter. Default value is Graphic3d_LOTA_OFF.");
	cls_Graphic3d_TextureParams.def("SetAnisoFilter", (void (Graphic3d_TextureParams::*)(const Graphic3d_LevelOfTextureAnisotropy)) &Graphic3d_TextureParams::SetAnisoFilter, "", py::arg("theLevel"));
	cls_Graphic3d_TextureParams.def("Rotation", (Standard_ShortReal (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::Rotation, "Returns rotation angle in degrees Default value is 0.");
	cls_Graphic3d_TextureParams.def("SetRotation", (void (Graphic3d_TextureParams::*)(const Standard_ShortReal)) &Graphic3d_TextureParams::SetRotation, "", py::arg("theAngleDegrees"));
	cls_Graphic3d_TextureParams.def("Scale", (const Graphic3d_Vec2 & (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::Scale, "Returns scale factor Default value is no scaling (1.0; 1.0).");
	cls_Graphic3d_TextureParams.def("SetScale", (void (Graphic3d_TextureParams::*)(const Graphic3d_Vec2)) &Graphic3d_TextureParams::SetScale, "", py::arg("theScale"));
	cls_Graphic3d_TextureParams.def("Translation", (const Graphic3d_Vec2 & (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::Translation, "Returns translation vector Default value is no translation (0.0; 0.0).");
	cls_Graphic3d_TextureParams.def("SetTranslation", (void (Graphic3d_TextureParams::*)(const Graphic3d_Vec2)) &Graphic3d_TextureParams::SetTranslation, "", py::arg("theVec"));
	cls_Graphic3d_TextureParams.def("GenMode", (Graphic3d_TypeOfTextureMode (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::GenMode, "Returns texture coordinates generation mode. Default value is Graphic3d_TOTM_MANUAL.");
	cls_Graphic3d_TextureParams.def("GenPlaneS", (const Graphic3d_Vec4 & (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::GenPlaneS, "Returns texture coordinates generation plane S.");
	cls_Graphic3d_TextureParams.def("GenPlaneT", (const Graphic3d_Vec4 & (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::GenPlaneT, "Returns texture coordinates generation plane T.");
	cls_Graphic3d_TextureParams.def("SetGenMode", (void (Graphic3d_TextureParams::*)(const Graphic3d_TypeOfTextureMode, const Graphic3d_Vec4, const Graphic3d_Vec4)) &Graphic3d_TextureParams::SetGenMode, "Setup texture coordinates generation mode.", py::arg("theMode"), py::arg("thePlaneS"), py::arg("thePlaneT"));
	cls_Graphic3d_TextureParams.def("SamplerRevision", (unsigned int (Graphic3d_TextureParams::*)() const ) &Graphic3d_TextureParams::SamplerRevision, "Return modification counter of parameters related to sampler state.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderProgram.hxx
	py::class_<Graphic3d_ShaderProgram, opencascade::handle<Graphic3d_ShaderProgram>, Standard_Transient> cls_Graphic3d_ShaderProgram(mod, "Graphic3d_ShaderProgram", "This class is responsible for managing shader programs.");
	cls_Graphic3d_ShaderProgram.def(py::init<>());
	cls_Graphic3d_ShaderProgram.def("IsDone", (Standard_Boolean (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::IsDone, "Checks if the program object is valid or not.");
	cls_Graphic3d_ShaderProgram.def("GetId", (const TCollection_AsciiString & (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::GetId, "Returns unique ID used to manage resource in graphic driver.");
	cls_Graphic3d_ShaderProgram.def("Header", (const TCollection_AsciiString & (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::Header, "Returns GLSL header (version code and extensions).");
	cls_Graphic3d_ShaderProgram.def("SetHeader", (void (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &)) &Graphic3d_ShaderProgram::SetHeader, "Setup GLSL header containing language version code and used extensions. Will be prepended to the very beginning of the source code. Example:", py::arg("theHeader"));
	cls_Graphic3d_ShaderProgram.def("AttachShader", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const opencascade::handle<Graphic3d_ShaderObject> &)) &Graphic3d_ShaderProgram::AttachShader, "Attaches shader object to the program object.", py::arg("theShader"));
	cls_Graphic3d_ShaderProgram.def("DetachShader", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const opencascade::handle<Graphic3d_ShaderObject> &)) &Graphic3d_ShaderProgram::DetachShader, "Detaches shader object from the program object.", py::arg("theShader"));
	cls_Graphic3d_ShaderProgram.def("ShaderObjects", (const Graphic3d_ShaderObjectList & (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::ShaderObjects, "Returns list of attached shader objects.");
	cls_Graphic3d_ShaderProgram.def("Variables", (const Graphic3d_ShaderVariableList & (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::Variables, "The list of currently pushed but not applied custom uniform variables. This list is automatically cleared after applying to GLSL program.");
	cls_Graphic3d_ShaderProgram.def("VertexAttributes", (const Graphic3d_ShaderAttributeList & (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::VertexAttributes, "Return the list of custom vertex attributes.");
	cls_Graphic3d_ShaderProgram.def("SetVertexAttributes", (void (Graphic3d_ShaderProgram::*)(const Graphic3d_ShaderAttributeList &)) &Graphic3d_ShaderProgram::SetVertexAttributes, "Assign the list of custom vertex attributes. Should be done before GLSL program initialization.", py::arg("theAttributes"));
	cls_Graphic3d_ShaderProgram.def("ClearVariables", (void (Graphic3d_ShaderProgram::*)()) &Graphic3d_ShaderProgram::ClearVariables, "Removes all custom uniform variables from the program.");
	cls_Graphic3d_ShaderProgram.def("PushVariableFloat", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const float)) &Graphic3d_ShaderProgram::PushVariableFloat, "Pushes float uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableVec2", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec2 &)) &Graphic3d_ShaderProgram::PushVariableVec2, "Pushes vec2 uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableVec3", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec3 &)) &Graphic3d_ShaderProgram::PushVariableVec3, "Pushes vec3 uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableVec4", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec4 &)) &Graphic3d_ShaderProgram::PushVariableVec4, "Pushes vec4 uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableInt", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const int)) &Graphic3d_ShaderProgram::PushVariableInt, "Pushes int uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableVec2i", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec2i &)) &Graphic3d_ShaderProgram::PushVariableVec2i, "Pushes vec2i uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableVec3i", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec3i &)) &Graphic3d_ShaderProgram::PushVariableVec3i, "Pushes vec3i uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def("PushVariableVec4i", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec4i &)) &Graphic3d_ShaderProgram::PushVariableVec4i, "Pushes vec4i uniform.", py::arg("theName"), py::arg("theValue"));
	cls_Graphic3d_ShaderProgram.def_static("ShadersFolder_", (const TCollection_AsciiString & (*)()) &Graphic3d_ShaderProgram::ShadersFolder, "The path to GLSL programs determined from CSF_ShadersDirectory or CASROOT environment variables.");
	cls_Graphic3d_ShaderProgram.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderProgram::get_type_name, "None");
	cls_Graphic3d_ShaderProgram.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderProgram::get_type_descriptor, "None");
	cls_Graphic3d_ShaderProgram.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderProgram::*)() const ) &Graphic3d_ShaderProgram::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextureRoot.hxx
	py::class_<Graphic3d_TextureRoot, opencascade::handle<Graphic3d_TextureRoot>, Standard_Transient> cls_Graphic3d_TextureRoot(mod, "Graphic3d_TextureRoot", "This is the texture root class enable the dialog with the GraphicDriver allows the loading of texture.");
	cls_Graphic3d_TextureRoot.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureRoot::get_type_name, "None");
	cls_Graphic3d_TextureRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureRoot::get_type_descriptor, "None");
	cls_Graphic3d_TextureRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::DynamicType, "None");
	cls_Graphic3d_TextureRoot.def_static("TexturesFolder_", (TCollection_AsciiString (*)()) &Graphic3d_TextureRoot::TexturesFolder, "The path to textures determined from CSF_MDTVTexturesDirectory or CASROOT environment variables.");
	cls_Graphic3d_TextureRoot.def("IsDone", (Standard_Boolean (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::IsDone, "Checks if a texture class is valid or not.");
	cls_Graphic3d_TextureRoot.def("Path", (const OSD_Path & (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::Path, "Returns the full path of the defined texture. It could be empty path if GetImage() is overridden to load image not from file.");
	cls_Graphic3d_TextureRoot.def("Type", (Graphic3d_TypeOfTexture (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::Type, "Returns the texture type.");
	cls_Graphic3d_TextureRoot.def("GetId", (const TCollection_AsciiString & (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::GetId, "This ID will be used to manage resource in graphic driver.");
	cls_Graphic3d_TextureRoot.def("Revision", (Standard_Size (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::Revision, "Return image revision.");
	cls_Graphic3d_TextureRoot.def("UpdateRevision", (void (Graphic3d_TextureRoot::*)()) &Graphic3d_TextureRoot::UpdateRevision, "Update image revision. Can be used for signaling changes in the texture source (e.g. file update, pixmap update) without re-creating texture source itself (since unique id should be never modified).");
	cls_Graphic3d_TextureRoot.def("GetImage", (opencascade::handle<Image_PixMap> (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::GetImage, "This method will be called by graphic driver each time when texture resource should be created. Default constructors allow defining the texture source as path to texture image or directly as pixmap. If the source is defined as path, then the image will be dynamically loaded when this method is called (and no copy will be preserved in this class instance). Inheritors may dynamically generate the image. Notice, image data should be in Bottom-Up order (see Image_PixMap::IsTopDown())!");
	cls_Graphic3d_TextureRoot.def("GetParams", (const opencascade::handle<Graphic3d_TextureParams> & (Graphic3d_TextureRoot::*)() const ) &Graphic3d_TextureRoot::GetParams, "Returns low-level texture parameters");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextureMap.hxx
	py::class_<Graphic3d_TextureMap, opencascade::handle<Graphic3d_TextureMap>, Graphic3d_TextureRoot> cls_Graphic3d_TextureMap(mod, "Graphic3d_TextureMap", "This is an abstract class for managing texture applyable on polygons.");
	cls_Graphic3d_TextureMap.def("EnableSmooth", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::EnableSmooth, "enable texture smoothing");
	cls_Graphic3d_TextureMap.def("IsSmoothed", (Standard_Boolean (Graphic3d_TextureMap::*)() const ) &Graphic3d_TextureMap::IsSmoothed, "Returns TRUE if the texture is smoothed.");
	cls_Graphic3d_TextureMap.def("DisableSmooth", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::DisableSmooth, "disable texture smoothing");
	cls_Graphic3d_TextureMap.def("EnableModulate", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::EnableModulate, "enable texture modulate mode. the image is modulate with the shading of the surface.");
	cls_Graphic3d_TextureMap.def("DisableModulate", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::DisableModulate, "disable texture modulate mode. the image is directly decal on the surface.");
	cls_Graphic3d_TextureMap.def("IsModulate", (Standard_Boolean (Graphic3d_TextureMap::*)() const ) &Graphic3d_TextureMap::IsModulate, "Returns TRUE if the texture is modulate.");
	cls_Graphic3d_TextureMap.def("EnableRepeat", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::EnableRepeat, "use this methods if you want to enable texture repetition on your objects.");
	cls_Graphic3d_TextureMap.def("DisableRepeat", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::DisableRepeat, "use this methods if you want to disable texture repetition on your objects.");
	cls_Graphic3d_TextureMap.def("IsRepeat", (Standard_Boolean (Graphic3d_TextureMap::*)() const ) &Graphic3d_TextureMap::IsRepeat, "Returns TRUE if the texture repeat is enable.");
	cls_Graphic3d_TextureMap.def("AnisoFilter", (Graphic3d_LevelOfTextureAnisotropy (Graphic3d_TextureMap::*)() const ) &Graphic3d_TextureMap::AnisoFilter, "Returns level of anisontropy texture filter. Default value is Graphic3d_LOTA_OFF.");
	cls_Graphic3d_TextureMap.def("SetAnisoFilter", (void (Graphic3d_TextureMap::*)(const Graphic3d_LevelOfTextureAnisotropy)) &Graphic3d_TextureMap::SetAnisoFilter, "", py::arg("theLevel"));
	cls_Graphic3d_TextureMap.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureMap::get_type_name, "None");
	cls_Graphic3d_TextureMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureMap::get_type_descriptor, "None");
	cls_Graphic3d_TextureMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureMap::*)() const ) &Graphic3d_TextureMap::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextureSet.hxx
	py::class_<Graphic3d_TextureSet, opencascade::handle<Graphic3d_TextureSet>, Standard_Transient> cls_Graphic3d_TextureSet(mod, "Graphic3d_TextureSet", "Class holding array of textures to be mapped as a set.");
	cls_Graphic3d_TextureSet.def(py::init<>());
	cls_Graphic3d_TextureSet.def(py::init<Standard_Integer>(), py::arg("theNbTextures"));
	cls_Graphic3d_TextureSet.def(py::init<const opencascade::handle<Graphic3d_TextureMap> &>(), py::arg("theTexture"));
	cls_Graphic3d_TextureSet.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureSet::get_type_name, "None");
	cls_Graphic3d_TextureSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureSet::get_type_descriptor, "None");
	cls_Graphic3d_TextureSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureSet::*)() const ) &Graphic3d_TextureSet::DynamicType, "None");
	cls_Graphic3d_TextureSet.def("IsEmpty", (Standard_Boolean (Graphic3d_TextureSet::*)() const ) &Graphic3d_TextureSet::IsEmpty, "Return TRUE if texture array is empty.");
	cls_Graphic3d_TextureSet.def("Size", (Standard_Integer (Graphic3d_TextureSet::*)() const ) &Graphic3d_TextureSet::Size, "Return number of textures.");
	cls_Graphic3d_TextureSet.def("Lower", (Standard_Integer (Graphic3d_TextureSet::*)() const ) &Graphic3d_TextureSet::Lower, "Return the lower index in texture set.");
	cls_Graphic3d_TextureSet.def("Upper", (Standard_Integer (Graphic3d_TextureSet::*)() const ) &Graphic3d_TextureSet::Upper, "Return the upper index in texture set.");
	cls_Graphic3d_TextureSet.def("First", (const opencascade::handle<Graphic3d_TextureMap> & (Graphic3d_TextureSet::*)() const ) &Graphic3d_TextureSet::First, "Return the first texture.");
	cls_Graphic3d_TextureSet.def("SetFirst", (void (Graphic3d_TextureSet::*)(const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_TextureSet::SetFirst, "Return the first texture.", py::arg("theTexture"));
	cls_Graphic3d_TextureSet.def("Value", (const opencascade::handle<Graphic3d_TextureMap> & (Graphic3d_TextureSet::*)(Standard_Integer) const ) &Graphic3d_TextureSet::Value, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"));
	cls_Graphic3d_TextureSet.def("SetValue", (void (Graphic3d_TextureSet::*)(Standard_Integer, const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_TextureSet::SetValue, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"), py::arg("theTexture"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_AspectFillArea3d.hxx
	py::class_<Graphic3d_AspectFillArea3d, opencascade::handle<Graphic3d_AspectFillArea3d>, Standard_Transient> cls_Graphic3d_AspectFillArea3d(mod, "Graphic3d_AspectFillArea3d", "This class defines graphic attributes for opaque 3d primitives (polygons, triangles, quadrilaterals).");
	cls_Graphic3d_AspectFillArea3d.def(py::init<>());
	cls_Graphic3d_AspectFillArea3d.def(py::init<const Aspect_InteriorStyle, const Quantity_Color &, const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real, const Graphic3d_MaterialAspect &, const Graphic3d_MaterialAspect &>(), py::arg("theInterior"), py::arg("theInteriorColor"), py::arg("theEdgeColor"), py::arg("theEdgeLineType"), py::arg("theEdgeWidth"), py::arg("theFrontMaterial"), py::arg("theBackMaterial"));
	cls_Graphic3d_AspectFillArea3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectFillArea3d::get_type_name, "None");
	cls_Graphic3d_AspectFillArea3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectFillArea3d::get_type_descriptor, "None");
	cls_Graphic3d_AspectFillArea3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::DynamicType, "None");
	cls_Graphic3d_AspectFillArea3d.def("InteriorStyle", (Aspect_InteriorStyle (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::InteriorStyle, "Return interior rendering style (Aspect_IS_EMPTY by default, which means nothing will be rendered!).");
	cls_Graphic3d_AspectFillArea3d.def("SetInteriorStyle", (void (Graphic3d_AspectFillArea3d::*)(const Aspect_InteriorStyle)) &Graphic3d_AspectFillArea3d::SetInteriorStyle, "Modifies the interior type used for rendering", py::arg("theStyle"));
	cls_Graphic3d_AspectFillArea3d.def("InteriorColor", (const Quantity_Color & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::InteriorColor, "Return interior color.");
	cls_Graphic3d_AspectFillArea3d.def("InteriorColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::InteriorColorRGBA, "Return interior color.");
	cls_Graphic3d_AspectFillArea3d.def("SetInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_Color &)) &Graphic3d_AspectFillArea3d::SetInteriorColor, "Modifies the color of the interior of the face", py::arg("theColor"));
	cls_Graphic3d_AspectFillArea3d.def("SetInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectFillArea3d::SetInteriorColor, "Modifies the color of the interior of the face", py::arg("theColor"));
	cls_Graphic3d_AspectFillArea3d.def("BackInteriorColor", (const Quantity_Color & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::BackInteriorColor, "Return back interior color.");
	cls_Graphic3d_AspectFillArea3d.def("BackInteriorColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::BackInteriorColorRGBA, "Return back interior color.");
	cls_Graphic3d_AspectFillArea3d.def("SetBackInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_Color &)) &Graphic3d_AspectFillArea3d::SetBackInteriorColor, "Modifies the color of the interior of the back face", py::arg("theColor"));
	cls_Graphic3d_AspectFillArea3d.def("SetBackInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectFillArea3d::SetBackInteriorColor, "Modifies the color of the interior of the back face", py::arg("theColor"));
	cls_Graphic3d_AspectFillArea3d.def("FrontMaterial", (const Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::FrontMaterial, "Returns the surface material of external faces");
	cls_Graphic3d_AspectFillArea3d.def("ChangeFrontMaterial", (Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::ChangeFrontMaterial, "Returns the surface material of external faces");
	cls_Graphic3d_AspectFillArea3d.def("SetFrontMaterial", (void (Graphic3d_AspectFillArea3d::*)(const Graphic3d_MaterialAspect &)) &Graphic3d_AspectFillArea3d::SetFrontMaterial, "Modifies the surface material of external faces", py::arg("theMaterial"));
	cls_Graphic3d_AspectFillArea3d.def("BackMaterial", (const Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::BackMaterial, "Returns the surface material of internal faces");
	cls_Graphic3d_AspectFillArea3d.def("ChangeBackMaterial", (Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::ChangeBackMaterial, "Returns the surface material of internal faces");
	cls_Graphic3d_AspectFillArea3d.def("SetBackMaterial", (void (Graphic3d_AspectFillArea3d::*)(const Graphic3d_MaterialAspect &)) &Graphic3d_AspectFillArea3d::SetBackMaterial, "Modifies the surface material of internal faces", py::arg("theMaterial"));
	cls_Graphic3d_AspectFillArea3d.def("ToSuppressBackFaces", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::ToSuppressBackFaces, "Returns true if back faces should be suppressed (true by default).");
	cls_Graphic3d_AspectFillArea3d.def("SetSuppressBackFaces", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetSuppressBackFaces, "Assign back faces culling flag.", py::arg("theToSuppress"));
	cls_Graphic3d_AspectFillArea3d.def("BackFace", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::BackFace, "Returns true if back faces should be suppressed (true by default).");
	cls_Graphic3d_AspectFillArea3d.def("AllowBackFace", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::AllowBackFace, "Allows the display of back-facing filled polygons.");
	cls_Graphic3d_AspectFillArea3d.def("SuppressBackFace", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SuppressBackFace, "Suppress the display of back-facing filled polygons. A back-facing polygon is defined as a polygon whose vertices are in a clockwise order with respect to screen coordinates.");
	cls_Graphic3d_AspectFillArea3d.def("Distinguish", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::Distinguish, "Returns true if material properties should be distinguished for back and front faces (false by default).");
	cls_Graphic3d_AspectFillArea3d.def("SetDistinguish", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetDistinguish, "Set material distinction between front and back faces.", py::arg("toDistinguish"));
	cls_Graphic3d_AspectFillArea3d.def("SetDistinguishOn", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetDistinguishOn, "Allows material distinction between front and back faces.");
	cls_Graphic3d_AspectFillArea3d.def("SetDistinguishOff", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetDistinguishOff, "Forbids material distinction between front and back faces.");
	cls_Graphic3d_AspectFillArea3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::ShaderProgram, "Return shader program.");
	cls_Graphic3d_AspectFillArea3d.def("SetShaderProgram", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectFillArea3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
	cls_Graphic3d_AspectFillArea3d.def("TextureSet", (const opencascade::handle<Graphic3d_TextureSet> & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::TextureSet, "Return texture array to be mapped.");
	cls_Graphic3d_AspectFillArea3d.def("SetTextureSet", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_TextureSet> &)) &Graphic3d_AspectFillArea3d::SetTextureSet, "Setup texture array to be mapped.", py::arg("theTextures"));
	cls_Graphic3d_AspectFillArea3d.def("TextureMap", (opencascade::handle<Graphic3d_TextureMap> (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::TextureMap, "Return texture to be mapped.");
	cls_Graphic3d_AspectFillArea3d.def("SetTextureMap", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_AspectFillArea3d::SetTextureMap, "Assign texture to be mapped. See also SetTextureMapOn() to actually activate texture mapping.", py::arg("theTexture"));
	cls_Graphic3d_AspectFillArea3d.def("ToMapTexture", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::ToMapTexture, "Return true if texture mapping is enabled (false by default).");
	cls_Graphic3d_AspectFillArea3d.def("TextureMapState", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::TextureMapState, "Return true if texture mapping is enabled (false by default).");
	cls_Graphic3d_AspectFillArea3d.def("SetTextureMapOn", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetTextureMapOn, "Enable or disable texture mapping (has no effect if texture is not set).", py::arg("theToMap"));
	cls_Graphic3d_AspectFillArea3d.def("SetTextureMapOn", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetTextureMapOn, "Enable texture mapping (has no effect if texture is not set).");
	cls_Graphic3d_AspectFillArea3d.def("SetTextureMapOff", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetTextureMapOff, "Disable texture mapping.");
	cls_Graphic3d_AspectFillArea3d.def("PolygonOffset", (const Graphic3d_PolygonOffset & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::PolygonOffset, "Returns current polygon offsets settings.");
	cls_Graphic3d_AspectFillArea3d.def("PolygonOffsets", [](Graphic3d_AspectFillArea3d &self, Standard_Integer & theMode, Standard_ShortReal & theFactor, Standard_ShortReal & theUnits){ self.PolygonOffsets(theMode, theFactor, theUnits); return theMode; }, "Returns current polygon offsets settings.", py::arg("theMode"), py::arg("theFactor"), py::arg("theUnits"));
	cls_Graphic3d_AspectFillArea3d.def("SetPolygonOffsets", [](Graphic3d_AspectFillArea3d &self, const Standard_Integer a0) -> void { return self.SetPolygonOffsets(a0); }, py::arg("theMode"));
	cls_Graphic3d_AspectFillArea3d.def("SetPolygonOffsets", [](Graphic3d_AspectFillArea3d &self, const Standard_Integer a0, const Standard_ShortReal a1) -> void { return self.SetPolygonOffsets(a0, a1); }, py::arg("theMode"), py::arg("theFactor"));
	cls_Graphic3d_AspectFillArea3d.def("SetPolygonOffsets", (void (Graphic3d_AspectFillArea3d::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_AspectFillArea3d::SetPolygonOffsets, "Sets up OpenGL polygon offsets mechanism. <aMode> parameter can contain various combinations of Aspect_PolygonOffsetMode enumeration elements (Aspect_POM_None means that polygon offsets are not changed). If <aMode> is different from Aspect_POM_Off and Aspect_POM_None, then <aFactor> and <aUnits> arguments are used by graphic renderer to calculate a depth offset value:", py::arg("theMode"), py::arg("theFactor"), py::arg("theUnits"));
	cls_Graphic3d_AspectFillArea3d.def("ToDrawEdges", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::ToDrawEdges, "Returns true if edges should be drawn (false by default).");
	cls_Graphic3d_AspectFillArea3d.def("SetDrawEdges", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetDrawEdges, "Set if edges should be drawn or not.", py::arg("theToDraw"));
	cls_Graphic3d_AspectFillArea3d.def("Edge", (bool (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::Edge, "Returns true if edges should be drawn.");
	cls_Graphic3d_AspectFillArea3d.def("SetEdgeOn", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetEdgeOn, "The edges of FillAreas are drawn.");
	cls_Graphic3d_AspectFillArea3d.def("SetEdgeOff", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetEdgeOff, "The edges of FillAreas are not drawn.");
	cls_Graphic3d_AspectFillArea3d.def("EdgeColor", (const Quantity_Color & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::EdgeColor, "Return color of edges.");
	cls_Graphic3d_AspectFillArea3d.def("EdgeColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::EdgeColorRGBA, "Return color of edges.");
	cls_Graphic3d_AspectFillArea3d.def("SetEdgeColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_Color &)) &Graphic3d_AspectFillArea3d::SetEdgeColor, "Modifies the color of the edge of the face", py::arg("theColor"));
	cls_Graphic3d_AspectFillArea3d.def("EdgeLineType", (Aspect_TypeOfLine (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::EdgeLineType, "Return edges line type.");
	cls_Graphic3d_AspectFillArea3d.def("SetEdgeLineType", (void (Graphic3d_AspectFillArea3d::*)(const Aspect_TypeOfLine)) &Graphic3d_AspectFillArea3d::SetEdgeLineType, "Modifies the edge line type", py::arg("theType"));
	cls_Graphic3d_AspectFillArea3d.def("EdgeWidth", (Standard_ShortReal (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::EdgeWidth, "Return width for edges in pixels.");
	cls_Graphic3d_AspectFillArea3d.def("SetEdgeWidth", (void (Graphic3d_AspectFillArea3d::*)(const Standard_Real)) &Graphic3d_AspectFillArea3d::SetEdgeWidth, "Modifies the edge thickness Warning: Raises AspectFillAreaDefinitionError if the width is a negative value.", py::arg("theWidth"));
	cls_Graphic3d_AspectFillArea3d.def("HatchStyle", (const opencascade::handle<Graphic3d_HatchStyle> & (Graphic3d_AspectFillArea3d::*)() const ) &Graphic3d_AspectFillArea3d::HatchStyle, "Returns the hatch type used when InteriorStyle is IS_HATCH");
	cls_Graphic3d_AspectFillArea3d.def("SetHatchStyle", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_HatchStyle> &)) &Graphic3d_AspectFillArea3d::SetHatchStyle, "Modifies the hatch type used when InteriorStyle is IS_HATCH", py::arg("theStyle"));
	cls_Graphic3d_AspectFillArea3d.def("SetHatchStyle", (void (Graphic3d_AspectFillArea3d::*)(const Aspect_HatchStyle)) &Graphic3d_AspectFillArea3d::SetHatchStyle, "Modifies the hatch type used when InteriorStyle is IS_HATCH", py::arg("theStyle"));
	cls_Graphic3d_AspectFillArea3d.def("Values", [](Graphic3d_AspectFillArea3d &self, Aspect_InteriorStyle & theStyle, Quantity_Color & theIntColor, Quantity_Color & theEdgeColor, Aspect_TypeOfLine & theType, Standard_Real & theWidth){ self.Values(theStyle, theIntColor, theEdgeColor, theType, theWidth); return theWidth; }, "Returns the current values.", py::arg("theStyle"), py::arg("theIntColor"), py::arg("theEdgeColor"), py::arg("theType"), py::arg("theWidth"));
	cls_Graphic3d_AspectFillArea3d.def("Values", [](Graphic3d_AspectFillArea3d &self, Aspect_InteriorStyle & theStyle, Quantity_Color & theIntColor, Quantity_Color & theBackIntColor, Quantity_Color & theEdgeColor, Aspect_TypeOfLine & theType, Standard_Real & theWidth){ self.Values(theStyle, theIntColor, theBackIntColor, theEdgeColor, theType, theWidth); return theWidth; }, "Returns the current values.", py::arg("theStyle"), py::arg("theIntColor"), py::arg("theBackIntColor"), py::arg("theEdgeColor"), py::arg("theType"), py::arg("theWidth"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_PresentationAttributes.hxx
	py::class_<Graphic3d_PresentationAttributes, opencascade::handle<Graphic3d_PresentationAttributes>, Standard_Transient> cls_Graphic3d_PresentationAttributes(mod, "Graphic3d_PresentationAttributes", "Class defines presentation properties.");
	cls_Graphic3d_PresentationAttributes.def(py::init<>());
	cls_Graphic3d_PresentationAttributes.def_static("get_type_name_", (const char * (*)()) &Graphic3d_PresentationAttributes::get_type_name, "None");
	cls_Graphic3d_PresentationAttributes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_PresentationAttributes::get_type_descriptor, "None");
	cls_Graphic3d_PresentationAttributes.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::DynamicType, "None");
	cls_Graphic3d_PresentationAttributes.def("Method", (Aspect_TypeOfHighlightMethod (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::Method, "Returns highlight method, Aspect_TOHM_COLOR by default.");
	cls_Graphic3d_PresentationAttributes.def("SetMethod", (void (Graphic3d_PresentationAttributes::*)(const Aspect_TypeOfHighlightMethod)) &Graphic3d_PresentationAttributes::SetMethod, "Changes highlight method to the given one.", py::arg("theMethod"));
	cls_Graphic3d_PresentationAttributes.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::ColorRGBA, "Returns basic presentation color (including alpha channel).");
	cls_Graphic3d_PresentationAttributes.def("Color", (const Quantity_Color & (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::Color, "Returns basic presentation color, Quantity_NOC_WHITE by default.");
	cls_Graphic3d_PresentationAttributes.def("SetColor", (void (Graphic3d_PresentationAttributes::*)(const Quantity_Color &)) &Graphic3d_PresentationAttributes::SetColor, "Sets basic presentation color (RGB components, does not modifies transparency).", py::arg("theColor"));
	cls_Graphic3d_PresentationAttributes.def("Transparency", (Standard_ShortReal (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::Transparency, "Returns basic presentation transparency (0 - opaque, 1 - fully transparent), 0 by default (opaque).");
	cls_Graphic3d_PresentationAttributes.def("SetTransparency", (void (Graphic3d_PresentationAttributes::*)(const Standard_ShortReal)) &Graphic3d_PresentationAttributes::SetTransparency, "Sets basic presentation transparency (0 - opaque, 1 - fully transparent).", py::arg("theTranspCoef"));
	cls_Graphic3d_PresentationAttributes.def("ZLayer", (Graphic3d_ZLayerId (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::ZLayer, "Returns presentation Zlayer, Graphic3d_ZLayerId_Default by default. Graphic3d_ZLayerId_UNKNOWN means undefined (a layer of main presentation to be used).");
	cls_Graphic3d_PresentationAttributes.def("SetZLayer", (void (Graphic3d_PresentationAttributes::*)(const Graphic3d_ZLayerId)) &Graphic3d_PresentationAttributes::SetZLayer, "Sets presentation Zlayer.", py::arg("theLayer"));
	cls_Graphic3d_PresentationAttributes.def("DisplayMode", (Standard_Integer (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::DisplayMode, "Returns display mode, 0 by default. -1 means undefined (main display mode of presentation to be used).");
	cls_Graphic3d_PresentationAttributes.def("SetDisplayMode", (void (Graphic3d_PresentationAttributes::*)(const Standard_Integer)) &Graphic3d_PresentationAttributes::SetDisplayMode, "Sets display mode.", py::arg("theMode"));
	cls_Graphic3d_PresentationAttributes.def("BasicFillAreaAspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (Graphic3d_PresentationAttributes::*)() const ) &Graphic3d_PresentationAttributes::BasicFillAreaAspect, "Return basic presentation fill area aspect, NULL by default. When set, might be used instead of Color() property.");
	cls_Graphic3d_PresentationAttributes.def("SetBasicFillAreaAspect", (void (Graphic3d_PresentationAttributes::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_PresentationAttributes::SetBasicFillAreaAspect, "Sets basic presentation fill area aspect.", py::arg("theAspect"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CameraTile.hxx
	py::class_<Graphic3d_CameraTile, std::unique_ptr<Graphic3d_CameraTile, Deleter<Graphic3d_CameraTile>>> cls_Graphic3d_CameraTile(mod, "Graphic3d_CameraTile", "Class defines the area (Tile) inside a view.");
	cls_Graphic3d_CameraTile.def(py::init<>());
	cls_Graphic3d_CameraTile.def("IsValid", (bool (Graphic3d_CameraTile::*)() const ) &Graphic3d_CameraTile::IsValid, "Return true if Tile has been defined.");
	cls_Graphic3d_CameraTile.def("OffsetLowerLeft", (Graphic3d_Vec2i (Graphic3d_CameraTile::*)() const ) &Graphic3d_CameraTile::OffsetLowerLeft, "Return offset position from lower-left corner.");
	cls_Graphic3d_CameraTile.def("Cropped", (Graphic3d_CameraTile (Graphic3d_CameraTile::*)() const ) &Graphic3d_CameraTile::Cropped, "Return the copy cropped by total size");
	cls_Graphic3d_CameraTile.def("__eq__", (bool (Graphic3d_CameraTile::*)(const Graphic3d_CameraTile &) const ) &Graphic3d_CameraTile::operator==, py::is_operator(), "Equality check.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_WorldViewProjState.hxx
	py::class_<Graphic3d_WorldViewProjState, std::unique_ptr<Graphic3d_WorldViewProjState, Deleter<Graphic3d_WorldViewProjState>>> cls_Graphic3d_WorldViewProjState(mod, "Graphic3d_WorldViewProjState", "Helper class for keeping reference on world-view-projection state. Helpful for synchronizing state of WVP dependent data structures.");
	cls_Graphic3d_WorldViewProjState.def(py::init<>());
	cls_Graphic3d_WorldViewProjState.def(py::init<const Standard_Size, const Standard_Size>(), py::arg("theProjectionState"), py::arg("theWorldViewState"));
	cls_Graphic3d_WorldViewProjState.def(py::init<const Standard_Size, const Standard_Size, const Standard_Transient *>(), py::arg("theProjectionState"), py::arg("theWorldViewState"), py::arg("theCamera"));
	cls_Graphic3d_WorldViewProjState.def("IsValid", (Standard_Boolean (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::IsValid, "Check state validity.");
	cls_Graphic3d_WorldViewProjState.def("Reset", (void (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::Reset, "Invalidate world view projection state.");
	cls_Graphic3d_WorldViewProjState.def("Initialize", [](Graphic3d_WorldViewProjState &self, const Standard_Size a0, const Standard_Size a1) -> void { return self.Initialize(a0, a1); }, py::arg("theProjectionState"), py::arg("theWorldViewState"));
	cls_Graphic3d_WorldViewProjState.def("Initialize", (void (Graphic3d_WorldViewProjState::*)(const Standard_Size, const Standard_Size, const Standard_Transient *)) &Graphic3d_WorldViewProjState::Initialize, "Initialize world view projection state.", py::arg("theProjectionState"), py::arg("theWorldViewState"), py::arg("theCamera"));
	cls_Graphic3d_WorldViewProjState.def("Initialize", [](Graphic3d_WorldViewProjState &self) -> void { return self.Initialize(); });
	cls_Graphic3d_WorldViewProjState.def("Initialize", (void (Graphic3d_WorldViewProjState::*)(const Standard_Transient *)) &Graphic3d_WorldViewProjState::Initialize, "Initialize world view projection state.", py::arg("theCamera"));
	cls_Graphic3d_WorldViewProjState.def("ProjectionState", (Standard_Size & (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::ProjectionState, "Returns projection state counter.");
	cls_Graphic3d_WorldViewProjState.def("WorldViewState", (Standard_Size & (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::WorldViewState, "Returns world view state counter.");
	cls_Graphic3d_WorldViewProjState.def("IsProjectionChanged", (Standard_Boolean (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::IsProjectionChanged, "Compare projection with other state.", py::arg("theState"));
	cls_Graphic3d_WorldViewProjState.def("IsWorldViewChanged", (Standard_Boolean (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::IsWorldViewChanged, "Compare world view transformation with other state.", py::arg("theState"));
	cls_Graphic3d_WorldViewProjState.def("IsChanged", (Standard_Boolean (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::IsChanged, "Compare with other world view projection state.", py::arg("theState"));
	cls_Graphic3d_WorldViewProjState.def("__ne__", (bool (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &) const ) &Graphic3d_WorldViewProjState::operator!=, py::is_operator(), "Compare with other world view projection state.", py::arg("theOther"));
	cls_Graphic3d_WorldViewProjState.def("__eq__", (bool (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &) const ) &Graphic3d_WorldViewProjState::operator==, py::is_operator(), "Compare with other world view projection state.", py::arg("theOther"));
	cls_Graphic3d_WorldViewProjState.def("assign", (void (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::operator=, py::is_operator(), "Copy world view projection state.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Camera.hxx
	py::class_<Graphic3d_Camera, opencascade::handle<Graphic3d_Camera>, Standard_Transient> cls_Graphic3d_Camera(mod, "Graphic3d_Camera", "Camera class provides object-oriented approach to setting up projection and orientation properties of 3D view.");
	cls_Graphic3d_Camera.def(py::init<>());
	cls_Graphic3d_Camera.def(py::init<const opencascade::handle<Graphic3d_Camera> &>(), py::arg("theOther"));
	cls_Graphic3d_Camera.def("CopyMappingData", (void (Graphic3d_Camera::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_Camera::CopyMappingData, "Initialize mapping related parameters from other camera handle.", py::arg("theOtherCamera"));
	cls_Graphic3d_Camera.def("CopyOrientationData", (void (Graphic3d_Camera::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_Camera::CopyOrientationData, "Initialize orientation related parameters from other camera handle.", py::arg("theOtherCamera"));
	cls_Graphic3d_Camera.def("Copy", (void (Graphic3d_Camera::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_Camera::Copy, "Copy properties of another camera.", py::arg("theOther"));
	cls_Graphic3d_Camera.def("SetEye", (void (Graphic3d_Camera::*)(const gp_Pnt &)) &Graphic3d_Camera::SetEye, "Sets camera Eye position.", py::arg("theEye"));
	cls_Graphic3d_Camera.def("Eye", (const gp_Pnt & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Eye, "Get camera Eye position.");
	cls_Graphic3d_Camera.def("SetCenter", (void (Graphic3d_Camera::*)(const gp_Pnt &)) &Graphic3d_Camera::SetCenter, "Sets Center of the camera.", py::arg("theCenter"));
	cls_Graphic3d_Camera.def("Center", (const gp_Pnt & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Center, "Get Center of the camera.");
	cls_Graphic3d_Camera.def("SetUp", (void (Graphic3d_Camera::*)(const gp_Dir &)) &Graphic3d_Camera::SetUp, "Sets camera Up direction vector, orthogonal to camera direction.", py::arg("theUp"));
	cls_Graphic3d_Camera.def("OrthogonalizeUp", (void (Graphic3d_Camera::*)()) &Graphic3d_Camera::OrthogonalizeUp, "Orthogonalize up direction vector.");
	cls_Graphic3d_Camera.def("OrthogonalizedUp", (gp_Dir (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::OrthogonalizedUp, "Return a copy of orthogonalized up direction vector.");
	cls_Graphic3d_Camera.def("Up", (const gp_Dir & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Up, "Get camera Up direction vector.");
	cls_Graphic3d_Camera.def("SetAxialScale", (void (Graphic3d_Camera::*)(const gp_XYZ &)) &Graphic3d_Camera::SetAxialScale, "Set camera axial scale.", py::arg("theAxialScale"));
	cls_Graphic3d_Camera.def("AxialScale", (const gp_XYZ & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::AxialScale, "Get camera axial scale.");
	cls_Graphic3d_Camera.def("SetDistance", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetDistance, "Set distance of Eye from camera Center.", py::arg("theDistance"));
	cls_Graphic3d_Camera.def("Distance", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Distance, "Get distance of Eye from camera Center.");
	cls_Graphic3d_Camera.def("SetDirection", (void (Graphic3d_Camera::*)(const gp_Dir &)) &Graphic3d_Camera::SetDirection, "Sets camera look direction.", py::arg("theDir"));
	cls_Graphic3d_Camera.def("Direction", (gp_Dir (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Direction, "Get camera look direction.");
	cls_Graphic3d_Camera.def("SetScale", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetScale, "Sets camera scale. For orthographic projection the scale factor corresponds to parallel scale of view mapping (i.e. size of viewport). For perspective camera scale is converted to distance. The scale specifies equal size of the view projection in both dimensions assuming that the aspect is 1.0. The projection height and width are specified with the scale and correspondingly multiplied by the aspect.", py::arg("theScale"));
	cls_Graphic3d_Camera.def("Scale", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Scale, "Get camera scale.");
	cls_Graphic3d_Camera.def("SetProjectionType", (void (Graphic3d_Camera::*)(const Graphic3d_Camera::Projection)) &Graphic3d_Camera::SetProjectionType, "Change camera projection type. When switching to perspective projection from orthographic one, the ZNear and ZFar are reset to default values (0.001, 3000.0) if less than 0.0.", py::arg("theProjection"));
	cls_Graphic3d_Camera.def("ProjectionType", (Graphic3d_Camera::Projection (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionType, "Returns camera projection type.");
	cls_Graphic3d_Camera.def("IsOrthographic", (Standard_Boolean (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::IsOrthographic, "Check that the camera projection is orthographic.");
	cls_Graphic3d_Camera.def("IsStereo", (Standard_Boolean (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::IsStereo, "Check whether the camera projection is stereo. Please note that stereo rendering is now implemented with support of Quad buffering.");
	cls_Graphic3d_Camera.def("SetFOVy", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetFOVy, "Set Field Of View (FOV) in y axis for perspective projection.", py::arg("theFOVy"));
	cls_Graphic3d_Camera.def("FOVy", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::FOVy, "Get Field Of View (FOV) in y axis.");
	cls_Graphic3d_Camera.def("ZFitAll", [](Graphic3d_Camera &self, const Standard_Real theScaleFactor, const Bnd_Box & theMinMax, const Bnd_Box & theGraphicBB, Standard_Real & theZNear, Standard_Real & theZFar){ bool rv = self.ZFitAll(theScaleFactor, theMinMax, theGraphicBB, theZNear, theZFar); return std::tuple<bool, Standard_Real &, Standard_Real &>(rv, theZNear, theZFar); }, "Estimate Z-min and Z-max planes of projection volume to match the displayed objects. The methods ensures that view volume will be close by depth range to the displayed objects. Fitting assumes that for orthogonal projection the view volume contains the displayed objects completely. For zoomed perspective view, the view volume is adjusted such that it contains the objects or their parts, located in front of the camera.", py::arg("theScaleFactor"), py::arg("theMinMax"), py::arg("theGraphicBB"), py::arg("theZNear"), py::arg("theZFar"));
	cls_Graphic3d_Camera.def("ZFitAll", (void (Graphic3d_Camera::*)(const Standard_Real, const Bnd_Box &, const Bnd_Box &)) &Graphic3d_Camera::ZFitAll, "Change Z-min and Z-max planes of projection volume to match the displayed objects.", py::arg("theScaleFactor"), py::arg("theMinMax"), py::arg("theGraphicBB"));
	cls_Graphic3d_Camera.def("SetZRange", (void (Graphic3d_Camera::*)(const Standard_Real, const Standard_Real)) &Graphic3d_Camera::SetZRange, "Change the Near and Far Z-clipping plane positions. For orthographic projection, theZNear, theZFar can be negative or positive. For perspective projection, only positive values are allowed. Program error exception is raised if non-positive values are specified for perspective projection or theZNear >= theZFar.", py::arg("theZNear"), py::arg("theZFar"));
	cls_Graphic3d_Camera.def("ZNear", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ZNear, "Get the Near Z-clipping plane position.");
	cls_Graphic3d_Camera.def("ZFar", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ZFar, "Get the Far Z-clipping plane position.");
	cls_Graphic3d_Camera.def("SetAspect", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetAspect, "Changes width / height display ratio.", py::arg("theAspect"));
	cls_Graphic3d_Camera.def("Aspect", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Aspect, "Get camera display ratio.");
	cls_Graphic3d_Camera.def("SetZFocus", (void (Graphic3d_Camera::*)(const Graphic3d_Camera::FocusType, const Standard_Real)) &Graphic3d_Camera::SetZFocus, "Sets stereographic focus distance.", py::arg("theType"), py::arg("theZFocus"));
	cls_Graphic3d_Camera.def("ZFocus", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ZFocus, "Get stereographic focus value.");
	cls_Graphic3d_Camera.def("ZFocusType", (Graphic3d_Camera::FocusType (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ZFocusType, "Get stereographic focus definition type.");
	cls_Graphic3d_Camera.def("SetIOD", (void (Graphic3d_Camera::*)(const Graphic3d_Camera::IODType, const Standard_Real)) &Graphic3d_Camera::SetIOD, "Sets Intraocular distance.", py::arg("theType"), py::arg("theIOD"));
	cls_Graphic3d_Camera.def("IOD", (Standard_Real (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::IOD, "Get Intraocular distance value.");
	cls_Graphic3d_Camera.def("GetIODType", (Graphic3d_Camera::IODType (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::GetIODType, "Get Intraocular distance definition type.");
	cls_Graphic3d_Camera.def("Tile", (const Graphic3d_CameraTile & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::Tile, "Get current tile.");
	cls_Graphic3d_Camera.def("SetTile", (void (Graphic3d_Camera::*)(const Graphic3d_CameraTile &)) &Graphic3d_Camera::SetTile, "Sets the Tile defining the drawing sub-area within View. Note that tile defining a region outside the view boundaries is also valid - use method Graphic3d_CameraTile::Cropped() to assign a cropped copy.", py::arg("theTile"));
	cls_Graphic3d_Camera.def("Transform", (void (Graphic3d_Camera::*)(const gp_Trsf &)) &Graphic3d_Camera::Transform, "Transform orientation components of the camera: Eye, Up and Center points.", py::arg("theTrsf"));
	cls_Graphic3d_Camera.def("ViewDimensions", (gp_XYZ (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ViewDimensions, "Calculate view plane size at center (target) point and distance between ZFar and ZNear planes.");
	cls_Graphic3d_Camera.def("ViewDimensions", (gp_XYZ (Graphic3d_Camera::*)(const Standard_Real) const ) &Graphic3d_Camera::ViewDimensions, "Calculate view plane size at center point with specified Z offset and distance between ZFar and ZNear planes.", py::arg("theZValue"));
	cls_Graphic3d_Camera.def("Frustum", (void (Graphic3d_Camera::*)(gp_Pln &, gp_Pln &, gp_Pln &, gp_Pln &, gp_Pln &, gp_Pln &) const ) &Graphic3d_Camera::Frustum, "Calculate WCS frustum planes for the camera projection volume. Frustum is a convex volume determined by six planes directing inwards. The frustum planes are usually used as inputs for camera algorithms. Thus, if any changes to projection matrix calculation are necessary, the frustum planes calculation should be also touched.", py::arg("theLeft"), py::arg("theRight"), py::arg("theBottom"), py::arg("theTop"), py::arg("theNear"), py::arg("theFar"));
	cls_Graphic3d_Camera.def("Project", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const ) &Graphic3d_Camera::Project, "Project point from world coordinate space to normalized device coordinates (mapping).", py::arg("thePnt"));
	cls_Graphic3d_Camera.def("UnProject", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const ) &Graphic3d_Camera::UnProject, "Unproject point from normalized device coordinates to world coordinate space.", py::arg("thePnt"));
	cls_Graphic3d_Camera.def("ConvertView2Proj", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const ) &Graphic3d_Camera::ConvertView2Proj, "Convert point from view coordinate space to projection coordinate space.", py::arg("thePnt"));
	cls_Graphic3d_Camera.def("ConvertProj2View", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const ) &Graphic3d_Camera::ConvertProj2View, "Convert point from projection coordinate space to view coordinate space.", py::arg("thePnt"));
	cls_Graphic3d_Camera.def("ConvertWorld2View", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const ) &Graphic3d_Camera::ConvertWorld2View, "Convert point from world coordinate space to view coordinate space.", py::arg("thePnt"));
	cls_Graphic3d_Camera.def("ConvertView2World", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const ) &Graphic3d_Camera::ConvertView2World, "Convert point from view coordinate space to world coordinates.", py::arg("thePnt"));
	cls_Graphic3d_Camera.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::WorldViewProjState, "Returns projection modification state of the camera.");
	cls_Graphic3d_Camera.def("ProjectionState", (Standard_Size (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionState, "Returns modification state of camera projection matrix");
	cls_Graphic3d_Camera.def("WorldViewState", (Standard_Size (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::WorldViewState, "Returns modification state of camera world view transformation matrix.");
	cls_Graphic3d_Camera.def("OrientationMatrix", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::OrientationMatrix, "Get orientation matrix.");
	cls_Graphic3d_Camera.def("OrientationMatrixF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::OrientationMatrixF, "Get orientation matrix of Standard_ShortReal precision.");
	cls_Graphic3d_Camera.def("ProjectionMatrix", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionMatrix, "Get monographic or middle point projection matrix used for monographic rendering and for point projection / unprojection.");
	cls_Graphic3d_Camera.def("ProjectionMatrixF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionMatrixF, "Get monographic or middle point projection matrix of Standard_ShortReal precision used for monographic rendering and for point projection / unprojection.");
	cls_Graphic3d_Camera.def("ProjectionStereoLeft", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionStereoLeft, "Returns stereographic matrix computed for left eye. Please note that this method is used for rendering for Projection_Stereo.");
	cls_Graphic3d_Camera.def("ProjectionStereoLeftF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionStereoLeftF, "Returns stereographic matrix of Standard_ShortReal precision computed for left eye. Please note that this method is used for rendering for Projection_Stereo.");
	cls_Graphic3d_Camera.def("ProjectionStereoRight", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionStereoRight, "Returns stereographic matrix computed for right eye. Please note that this method is used for rendering for Projection_Stereo.");
	cls_Graphic3d_Camera.def("ProjectionStereoRightF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::ProjectionStereoRightF, "Returns stereographic matrix of Standard_ShortReal precision computed for right eye. Please note that this method is used for rendering for Projection_Stereo.");
	cls_Graphic3d_Camera.def("InvalidateProjection", (void (Graphic3d_Camera::*)()) &Graphic3d_Camera::InvalidateProjection, "Invalidate state of projection matrix. The matrix will be updated on request.");
	cls_Graphic3d_Camera.def("InvalidateOrientation", (void (Graphic3d_Camera::*)()) &Graphic3d_Camera::InvalidateOrientation, "Invalidate orientation matrix. The matrix will be updated on request.");
	cls_Graphic3d_Camera.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Camera::get_type_name, "None");
	cls_Graphic3d_Camera.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Camera::get_type_descriptor, "None");
	cls_Graphic3d_Camera.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Camera::*)() const ) &Graphic3d_Camera::DynamicType, "None");
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Camera.hxx
	py::enum_<Graphic3d_Camera::Projection>(cls_Graphic3d_Camera, "Projection", "Enumerates supported monographic projections. - Projection_Orthographic : orthographic projection. - Projection_Perspective : perspective projection. - Projection_Stereo : stereographic projection. - Projection_MonoLeftEye : mono projection for stereo left eye. - Projection_MonoRightEye : mono projection for stereo right eye.")
		.value("Projection_Orthographic", Graphic3d_Camera::Projection::Projection_Orthographic)
		.value("Projection_Perspective", Graphic3d_Camera::Projection::Projection_Perspective)
		.value("Projection_Stereo", Graphic3d_Camera::Projection::Projection_Stereo)
		.value("Projection_MonoLeftEye", Graphic3d_Camera::Projection::Projection_MonoLeftEye)
		.value("Projection_MonoRightEye", Graphic3d_Camera::Projection::Projection_MonoRightEye)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Camera.hxx
	py::enum_<Graphic3d_Camera::FocusType>(cls_Graphic3d_Camera, "FocusType", "Enumerates approaches to define stereographic focus. - FocusType_Absolute : focus is specified as absolute value. - FocusType_Relative : focus is specified relative to (as coefficient of) camera focal length.")
		.value("FocusType_Absolute", Graphic3d_Camera::FocusType::FocusType_Absolute)
		.value("FocusType_Relative", Graphic3d_Camera::FocusType::FocusType_Relative)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Camera.hxx
	py::enum_<Graphic3d_Camera::IODType>(cls_Graphic3d_Camera, "IODType", "Enumerates approaches to define Intraocular distance. - IODType_Absolute : Intraocular distance is defined as absolute value. - IODType_Relative : Intraocular distance is defined relative to (as coefficient of) camera focal length.")
		.value("IODType_Absolute", Graphic3d_Camera::IODType::IODType_Absolute)
		.value("IODType_Relative", Graphic3d_Camera::IODType::IODType_Relative)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CLight.hxx
	py::class_<Graphic3d_CLight, std::unique_ptr<Graphic3d_CLight, Deleter<Graphic3d_CLight>>> cls_Graphic3d_CLight(mod, "Graphic3d_CLight", "Light definition");
	cls_Graphic3d_CLight.def(py::init<>());
	cls_Graphic3d_CLight.def("ConstAttenuation", (Standard_ShortReal (Graphic3d_CLight::*)() const ) &Graphic3d_CLight::ConstAttenuation, "Const attenuation factor of positional light source");
	cls_Graphic3d_CLight.def("LinearAttenuation", (Standard_ShortReal (Graphic3d_CLight::*)() const ) &Graphic3d_CLight::LinearAttenuation, "Linear attenuation factor of positional light source");
	cls_Graphic3d_CLight.def("Attenuation", (Graphic3d_Vec2 (Graphic3d_CLight::*)() const ) &Graphic3d_CLight::Attenuation, "Const, Linear attenuation factors of positional light source");
	cls_Graphic3d_CLight.def("Angle", (Standard_ShortReal (Graphic3d_CLight::*)() const ) &Graphic3d_CLight::Angle, "Angle in radians of the cone created by the spot");
	cls_Graphic3d_CLight.def("Concentration", (Standard_ShortReal (Graphic3d_CLight::*)() const ) &Graphic3d_CLight::Concentration, "Intensity distribution of the spot light, with 0..1 range.");
	cls_Graphic3d_CLight.def("ChangeConstAttenuation", (Standard_ShortReal & (Graphic3d_CLight::*)()) &Graphic3d_CLight::ChangeConstAttenuation, "None");
	cls_Graphic3d_CLight.def("ChangeLinearAttenuation", (Standard_ShortReal & (Graphic3d_CLight::*)()) &Graphic3d_CLight::ChangeLinearAttenuation, "None");
	cls_Graphic3d_CLight.def("ChangeAttenuation", (Graphic3d_Vec2 & (Graphic3d_CLight::*)()) &Graphic3d_CLight::ChangeAttenuation, "None");
	cls_Graphic3d_CLight.def("ChangeAngle", (Standard_ShortReal & (Graphic3d_CLight::*)()) &Graphic3d_CLight::ChangeAngle, "None");
	cls_Graphic3d_CLight.def("ChangeConcentration", (Standard_ShortReal & (Graphic3d_CLight::*)()) &Graphic3d_CLight::ChangeConcentration, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_AspectLine3d.hxx
	py::class_<Graphic3d_AspectLine3d, opencascade::handle<Graphic3d_AspectLine3d>, Standard_Transient> cls_Graphic3d_AspectLine3d(mod, "Graphic3d_AspectLine3d", "Creates and updates a group of attributes for 3d line primitives. This group contains the color, the type of line, and its thickness.");
	cls_Graphic3d_AspectLine3d.def(py::init<>());
	cls_Graphic3d_AspectLine3d.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real>(), py::arg("theColor"), py::arg("theType"), py::arg("theWidth"));
	cls_Graphic3d_AspectLine3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectLine3d::get_type_name, "None");
	cls_Graphic3d_AspectLine3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectLine3d::get_type_descriptor, "None");
	cls_Graphic3d_AspectLine3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectLine3d::*)() const ) &Graphic3d_AspectLine3d::DynamicType, "None");
	cls_Graphic3d_AspectLine3d.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectLine3d::*)() const ) &Graphic3d_AspectLine3d::ColorRGBA, "Return color.");
	cls_Graphic3d_AspectLine3d.def("Color", (const Quantity_Color & (Graphic3d_AspectLine3d::*)() const ) &Graphic3d_AspectLine3d::Color, "Return color.");
	cls_Graphic3d_AspectLine3d.def("SetColor", (void (Graphic3d_AspectLine3d::*)(const Quantity_Color &)) &Graphic3d_AspectLine3d::SetColor, "Modifies the color.", py::arg("theColor"));
	cls_Graphic3d_AspectLine3d.def("Type", (Aspect_TypeOfLine (Graphic3d_AspectLine3d::*)() const ) &Graphic3d_AspectLine3d::Type, "Return line type.");
	cls_Graphic3d_AspectLine3d.def("SetType", (void (Graphic3d_AspectLine3d::*)(const Aspect_TypeOfLine)) &Graphic3d_AspectLine3d::SetType, "Modifies the type of line.", py::arg("theType"));
	cls_Graphic3d_AspectLine3d.def("Width", (Standard_ShortReal (Graphic3d_AspectLine3d::*)() const ) &Graphic3d_AspectLine3d::Width, "Return line width.");
	cls_Graphic3d_AspectLine3d.def("SetWidth", (void (Graphic3d_AspectLine3d::*)(const Standard_Real)) &Graphic3d_AspectLine3d::SetWidth, "Modifies the line thickness. Warning: Raises AspectLineDefinitionError if the width is a negative value.", py::arg("theWidth"));
	cls_Graphic3d_AspectLine3d.def("SetWidth", (void (Graphic3d_AspectLine3d::*)(const Standard_ShortReal)) &Graphic3d_AspectLine3d::SetWidth, "Modifies the line thickness. Warning: Raises AspectLineDefinitionError if the width is a negative value.", py::arg("theWidth"));
	cls_Graphic3d_AspectLine3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectLine3d::*)() const ) &Graphic3d_AspectLine3d::ShaderProgram, "Return shader program.");
	cls_Graphic3d_AspectLine3d.def("SetShaderProgram", (void (Graphic3d_AspectLine3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectLine3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
	cls_Graphic3d_AspectLine3d.def("IsEqual", (bool (Graphic3d_AspectLine3d::*)(const Graphic3d_AspectLine3d &)) &Graphic3d_AspectLine3d::IsEqual, "Check for equality with another line aspect.", py::arg("theOther"));
	cls_Graphic3d_AspectLine3d.def("Values", [](Graphic3d_AspectLine3d &self, Quantity_Color & theColor, Aspect_TypeOfLine & theType, Standard_Real & theWidth){ self.Values(theColor, theType, theWidth); return theWidth; }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theType"), py::arg("theWidth"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_AspectTextDefinitionError.hxx
	py::class_<Graphic3d_AspectTextDefinitionError, opencascade::handle<Graphic3d_AspectTextDefinitionError>, Standard_OutOfRange> cls_Graphic3d_AspectTextDefinitionError(mod, "Graphic3d_AspectTextDefinitionError", "None");
	cls_Graphic3d_AspectTextDefinitionError.def(py::init<>());
	cls_Graphic3d_AspectTextDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_AspectTextDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_AspectTextDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_AspectTextDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_AspectTextDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_AspectTextDefinitionError.def_static("NewInstance_", (opencascade::handle<Graphic3d_AspectTextDefinitionError> (*)(const Standard_CString)) &Graphic3d_AspectTextDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_AspectTextDefinitionError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectTextDefinitionError::get_type_name, "None");
	cls_Graphic3d_AspectTextDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectTextDefinitionError::get_type_descriptor, "None");
	cls_Graphic3d_AspectTextDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectTextDefinitionError::*)() const ) &Graphic3d_AspectTextDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_AspectText3d.hxx
	py::class_<Graphic3d_AspectText3d, opencascade::handle<Graphic3d_AspectText3d>, Standard_Transient> cls_Graphic3d_AspectText3d(mod, "Graphic3d_AspectText3d", "Creates and updates a group of attributes for text primitives. This group contains the color, font, expansion factor (height/width ratio), and inter-character space.");
	cls_Graphic3d_AspectText3d.def(py::init<>());
	cls_Graphic3d_AspectText3d.def(py::init<const Quantity_Color &, const Standard_CString, const Standard_Real, const Standard_Real>(), py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"));
	cls_Graphic3d_AspectText3d.def(py::init<const Quantity_Color &, const Standard_CString, const Standard_Real, const Standard_Real, const Aspect_TypeOfStyleText>(), py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"));
	cls_Graphic3d_AspectText3d.def(py::init<const Quantity_Color &, const Standard_CString, const Standard_Real, const Standard_Real, const Aspect_TypeOfStyleText, const Aspect_TypeOfDisplayText>(), py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"));
	cls_Graphic3d_AspectText3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectText3d::get_type_name, "None");
	cls_Graphic3d_AspectText3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectText3d::get_type_descriptor, "None");
	cls_Graphic3d_AspectText3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::DynamicType, "None");
	cls_Graphic3d_AspectText3d.def("Color", (const Quantity_Color & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::Color, "Return the text color.");
	cls_Graphic3d_AspectText3d.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::ColorRGBA, "Return the text color.");
	cls_Graphic3d_AspectText3d.def("SetColor", (void (Graphic3d_AspectText3d::*)(const Quantity_Color &)) &Graphic3d_AspectText3d::SetColor, "Modifies the color.", py::arg("theColor"));
	cls_Graphic3d_AspectText3d.def("SetColor", (void (Graphic3d_AspectText3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectText3d::SetColor, "Modifies the color.", py::arg("theColor"));
	cls_Graphic3d_AspectText3d.def("SetExpansionFactor", (void (Graphic3d_AspectText3d::*)(const Standard_Real)) &Graphic3d_AspectText3d::SetExpansionFactor, "Modifies the expansion factor (height/width ratio) If the factor is less than 1, the characters will be higher than they are wide.", py::arg("theFactor"));
	cls_Graphic3d_AspectText3d.def("Font", (const TCollection_AsciiString & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::Font, "Return the font.");
	cls_Graphic3d_AspectText3d.def("SetFont", (void (Graphic3d_AspectText3d::*)(const TCollection_AsciiString &)) &Graphic3d_AspectText3d::SetFont, "Modifies the font.", py::arg("theFont"));
	cls_Graphic3d_AspectText3d.def("SetFont", (void (Graphic3d_AspectText3d::*)(const Standard_CString)) &Graphic3d_AspectText3d::SetFont, "Modifies the font.", py::arg("theFont"));
	cls_Graphic3d_AspectText3d.def("Space", (Standard_Real (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::Space, "Return the space between characters.");
	cls_Graphic3d_AspectText3d.def("SetSpace", (void (Graphic3d_AspectText3d::*)(const Standard_Real)) &Graphic3d_AspectText3d::SetSpace, "Modifies the space between the characters.", py::arg("theSpace"));
	cls_Graphic3d_AspectText3d.def("Style", (Aspect_TypeOfStyleText (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::Style, "Return the text style.");
	cls_Graphic3d_AspectText3d.def("SetStyle", (void (Graphic3d_AspectText3d::*)(const Aspect_TypeOfStyleText)) &Graphic3d_AspectText3d::SetStyle, "Modifies the style of the text. * TOST_NORMAL Default text. The text is displayed like any other graphic object. This text can be hidden by another object that is nearest from the point of view. * TOST_ANNOTATION The text is always visible. The text is displayed over the other object according to the priority.", py::arg("theStyle"));
	cls_Graphic3d_AspectText3d.def("DisplayType", (Aspect_TypeOfDisplayText (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::DisplayType, "Return display type.");
	cls_Graphic3d_AspectText3d.def("SetDisplayType", (void (Graphic3d_AspectText3d::*)(const Aspect_TypeOfDisplayText)) &Graphic3d_AspectText3d::SetDisplayType, "Define the display type of the text.", py::arg("theDisplayType"));
	cls_Graphic3d_AspectText3d.def("ColorSubTitleRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::ColorSubTitleRGBA, "Return subtitle color.");
	cls_Graphic3d_AspectText3d.def("ColorSubTitle", (const Quantity_Color & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::ColorSubTitle, "Return subtitle color.");
	cls_Graphic3d_AspectText3d.def("SetColorSubTitle", (void (Graphic3d_AspectText3d::*)(const Quantity_Color &)) &Graphic3d_AspectText3d::SetColorSubTitle, "Modifies the color of the subtitle for the TODT_SUBTITLE TextDisplayType and the color of background for the TODT_DEKALE TextDisplayType.", py::arg("theColor"));
	cls_Graphic3d_AspectText3d.def("SetColorSubTitle", (void (Graphic3d_AspectText3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectText3d::SetColorSubTitle, "Modifies the color of the subtitle for the TODT_SUBTITLE TextDisplayType and the color of background for the TODT_DEKALE TextDisplayType.", py::arg("theColor"));
	cls_Graphic3d_AspectText3d.def("GetTextZoomable", (bool (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::GetTextZoomable, "Returns TRUE when the Text Zoomable is on.");
	cls_Graphic3d_AspectText3d.def("SetTextZoomable", (void (Graphic3d_AspectText3d::*)(const bool)) &Graphic3d_AspectText3d::SetTextZoomable, "Turns usage of text zoomable on/off", py::arg("theFlag"));
	cls_Graphic3d_AspectText3d.def("GetTextAngle", (Standard_Real (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::GetTextAngle, "Returns Angle of degree");
	cls_Graphic3d_AspectText3d.def("SetTextAngle", (void (Graphic3d_AspectText3d::*)(const Standard_Real)) &Graphic3d_AspectText3d::SetTextAngle, "Turns usage of text rotated", py::arg("theAngle"));
	cls_Graphic3d_AspectText3d.def("GetTextFontAspect", (Font_FontAspect (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::GetTextFontAspect, "Returns text FontAspect");
	cls_Graphic3d_AspectText3d.def("SetTextFontAspect", (void (Graphic3d_AspectText3d::*)(const Font_FontAspect)) &Graphic3d_AspectText3d::SetTextFontAspect, "Turns usage of Aspect text", py::arg("theFontAspect"));
	cls_Graphic3d_AspectText3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectText3d::*)() const ) &Graphic3d_AspectText3d::ShaderProgram, "Return the shader program.");
	cls_Graphic3d_AspectText3d.def("SetShaderProgram", (void (Graphic3d_AspectText3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectText3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
	// FIXME 	cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace){ self.Values(theColor, theFont, theExpansionFactor, theSpace); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &>(theFont, theExpansionFactor, theSpace); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"));
	// FIXME 	cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace, Aspect_TypeOfStyleText & theStyle, Aspect_TypeOfDisplayText & theDisplayType, Quantity_Color & theColorSubTitle){ self.Values(theColor, theFont, theExpansionFactor, theSpace, theStyle, theDisplayType, theColorSubTitle); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &>(theFont, theExpansionFactor, theSpace); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"), py::arg("theColorSubTitle"));
	// FIXME 	cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace, Aspect_TypeOfStyleText & theStyle, Aspect_TypeOfDisplayText & theDisplayType, Quantity_Color & theColorSubTitle, Standard_Boolean & theTextZoomable, Standard_Real & theTextAngle){ self.Values(theColor, theFont, theExpansionFactor, theSpace, theStyle, theDisplayType, theColorSubTitle, theTextZoomable, theTextAngle); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &, Standard_Boolean &, Standard_Real &>(theFont, theExpansionFactor, theSpace, theTextZoomable, theTextAngle); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"), py::arg("theColorSubTitle"), py::arg("theTextZoomable"), py::arg("theTextAngle"));
	// FIXME 	cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace, Aspect_TypeOfStyleText & theStyle, Aspect_TypeOfDisplayText & theDisplayType, Quantity_Color & theColorSubTitle, Standard_Boolean & theTextZoomable, Standard_Real & theTextAngle, Font_FontAspect & theTextFontAspect){ self.Values(theColor, theFont, theExpansionFactor, theSpace, theStyle, theDisplayType, theColorSubTitle, theTextZoomable, theTextAngle, theTextFontAspect); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &, Standard_Boolean &, Standard_Real &>(theFont, theExpansionFactor, theSpace, theTextZoomable, theTextAngle); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"), py::arg("theColorSubTitle"), py::arg("theTextZoomable"), py::arg("theTextAngle"), py::arg("theTextFontAspect"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_MarkerImage.hxx
	py::class_<Graphic3d_MarkerImage, opencascade::handle<Graphic3d_MarkerImage>, Standard_Transient> cls_Graphic3d_MarkerImage(mod, "Graphic3d_MarkerImage", "This class is used to store bitmaps and images for markers rendering. It can convert bitmap texture stored in TColStd_HArray1OfByte to Image_PixMap and vice versa.");
	cls_Graphic3d_MarkerImage.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("theImage"));
	cls_Graphic3d_MarkerImage.def(py::init<const opencascade::handle<TColStd_HArray1OfByte> &, const Standard_Integer &, const Standard_Integer &>(), py::arg("theBitMap"), py::arg("theWidth"), py::arg("theHeight"));
	cls_Graphic3d_MarkerImage.def("GetBitMapArray", [](Graphic3d_MarkerImage &self) -> opencascade::handle<TColStd_HArray1OfByte> { return self.GetBitMapArray(); });
	cls_Graphic3d_MarkerImage.def("GetBitMapArray", (opencascade::handle<TColStd_HArray1OfByte> (Graphic3d_MarkerImage::*)(const Standard_Real &) const ) &Graphic3d_MarkerImage::GetBitMapArray, "Returns marker image as array of bytes. If an instance of the class has been initialized with image, it will be converted to bitmap based on the parameter theAlphaValue.", py::arg("theAlphaValue"));
	cls_Graphic3d_MarkerImage.def("GetImage", (const opencascade::handle<Image_PixMap> & (Graphic3d_MarkerImage::*)()) &Graphic3d_MarkerImage::GetImage, "Returns marker image. If an instance of the class has been initialized with a bitmap, it will be converted to image.");
	cls_Graphic3d_MarkerImage.def("GetImageAlpha", (const opencascade::handle<Image_PixMap> & (Graphic3d_MarkerImage::*)()) &Graphic3d_MarkerImage::GetImageAlpha, "Returns image alpha as grayscale image. Note that if an instance of the class has been initialized with a bitmap or with grayscale image this method will return exactly the same image as GetImage()");
	cls_Graphic3d_MarkerImage.def("GetImageId", (const TCollection_AsciiString & (Graphic3d_MarkerImage::*)() const ) &Graphic3d_MarkerImage::GetImageId, "Returns an unique ID. This ID will be used to manage resource in graphic driver.");
	cls_Graphic3d_MarkerImage.def("GetImageAlphaId", (const TCollection_AsciiString & (Graphic3d_MarkerImage::*)() const ) &Graphic3d_MarkerImage::GetImageAlphaId, "Returns an unique ID. This ID will be used to manage resource in graphic driver.");
	cls_Graphic3d_MarkerImage.def("GetTextureSize", [](Graphic3d_MarkerImage &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.GetTextureSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns texture size", py::arg("theWidth"), py::arg("theHeight"));
	cls_Graphic3d_MarkerImage.def_static("get_type_name_", (const char * (*)()) &Graphic3d_MarkerImage::get_type_name, "None");
	cls_Graphic3d_MarkerImage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_MarkerImage::get_type_descriptor, "None");
	cls_Graphic3d_MarkerImage.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_MarkerImage::*)() const ) &Graphic3d_MarkerImage::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_AspectMarker3d.hxx
	py::class_<Graphic3d_AspectMarker3d, opencascade::handle<Graphic3d_AspectMarker3d>, Standard_Transient> cls_Graphic3d_AspectMarker3d(mod, "Graphic3d_AspectMarker3d", "Creates and updates an attribute group for marker type primitives. This group contains the type of marker, its color, and its scale factor.");
	cls_Graphic3d_AspectMarker3d.def(py::init<>());
	cls_Graphic3d_AspectMarker3d.def(py::init<const Aspect_TypeOfMarker, const Quantity_Color &, const Standard_Real>(), py::arg("theType"), py::arg("theColor"), py::arg("theScale"));
	cls_Graphic3d_AspectMarker3d.def(py::init<const Quantity_Color &, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfByte> &>(), py::arg("theColor"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theTextureBitmap"));
	cls_Graphic3d_AspectMarker3d.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("theTextureImage"));
	cls_Graphic3d_AspectMarker3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectMarker3d::get_type_name, "None");
	cls_Graphic3d_AspectMarker3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectMarker3d::get_type_descriptor, "None");
	cls_Graphic3d_AspectMarker3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::DynamicType, "None");
	cls_Graphic3d_AspectMarker3d.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::ColorRGBA, "Return color.");
	cls_Graphic3d_AspectMarker3d.def("Color", (const Quantity_Color & (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::Color, "Return the color.");
	cls_Graphic3d_AspectMarker3d.def("SetColor", (void (Graphic3d_AspectMarker3d::*)(const Quantity_Color &)) &Graphic3d_AspectMarker3d::SetColor, "Modifies the color.", py::arg("theColor"));
	cls_Graphic3d_AspectMarker3d.def("Scale", (Standard_ShortReal (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::Scale, "Return scale factor.");
	cls_Graphic3d_AspectMarker3d.def("SetScale", (void (Graphic3d_AspectMarker3d::*)(const Standard_ShortReal)) &Graphic3d_AspectMarker3d::SetScale, "Modifies the scale factor. Marker type Aspect_TOM_POINT is not affected by the marker size scale factor. It is always the smallest displayable dot. Warning: Raises AspectMarkerDefinitionError if the scale is a negative value.", py::arg("theScale"));
	cls_Graphic3d_AspectMarker3d.def("SetScale", (void (Graphic3d_AspectMarker3d::*)(const Standard_Real)) &Graphic3d_AspectMarker3d::SetScale, "Assign scale factor.", py::arg("theScale"));
	cls_Graphic3d_AspectMarker3d.def("Type", (Aspect_TypeOfMarker (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::Type, "Return marker type.");
	cls_Graphic3d_AspectMarker3d.def("SetType", (void (Graphic3d_AspectMarker3d::*)(const Aspect_TypeOfMarker)) &Graphic3d_AspectMarker3d::SetType, "Modifies the type of marker.", py::arg("theType"));
	cls_Graphic3d_AspectMarker3d.def("GetTextureSize", [](Graphic3d_AspectMarker3d &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.GetTextureSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns marker's texture size.", py::arg("theWidth"), py::arg("theHeight"));
	cls_Graphic3d_AspectMarker3d.def("GetMarkerImage", (const opencascade::handle<Graphic3d_MarkerImage> & (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::GetMarkerImage, "Returns marker's image texture. Could be null handle if marker aspect has been initialized as default type of marker.");
	cls_Graphic3d_AspectMarker3d.def("SetMarkerImage", (void (Graphic3d_AspectMarker3d::*)(const opencascade::handle<Graphic3d_MarkerImage> &)) &Graphic3d_AspectMarker3d::SetMarkerImage, "Set marker's image texture.", py::arg("theImage"));
	cls_Graphic3d_AspectMarker3d.def("SetBitMap", (void (Graphic3d_AspectMarker3d::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfByte> &)) &Graphic3d_AspectMarker3d::SetBitMap, "None", py::arg("theWidth"), py::arg("theHeight"), py::arg("theTexture"));
	cls_Graphic3d_AspectMarker3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectMarker3d::*)() const ) &Graphic3d_AspectMarker3d::ShaderProgram, "Return the program.");
	cls_Graphic3d_AspectMarker3d.def("SetShaderProgram", (void (Graphic3d_AspectMarker3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectMarker3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
	cls_Graphic3d_AspectMarker3d.def("Values", [](Graphic3d_AspectMarker3d &self, Quantity_Color & theColor, Aspect_TypeOfMarker & theType, Standard_Real & theScale){ self.Values(theColor, theType, theScale); return theScale; }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theType"), py::arg("theScale"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vertex.hxx
	py::class_<Graphic3d_Vertex, std::unique_ptr<Graphic3d_Vertex, Deleter<Graphic3d_Vertex>>> cls_Graphic3d_Vertex(mod, "Graphic3d_Vertex", "This class represents a graphical 3D point.");
	cls_Graphic3d_Vertex.def(py::init<>());
	cls_Graphic3d_Vertex.def(py::init([] (const Graphic3d_Vertex &other) {return new Graphic3d_Vertex(other);}), "Copy constructor", py::arg("other"));
	cls_Graphic3d_Vertex.def(py::init<const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_Vertex.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_Vertex.def("SetCoord", (void (Graphic3d_Vertex::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Vertex::SetCoord, "Modifies the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_Vertex.def("SetCoord", (void (Graphic3d_Vertex::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_Vertex::SetCoord, "Modifies the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_Vertex.def("Coord", (void (Graphic3d_Vertex::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const ) &Graphic3d_Vertex::Coord, "Returns the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_Vertex.def("Coord", [](Graphic3d_Vertex &self, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Coord(theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Returns the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_Vertex.def("X", (Standard_ShortReal (Graphic3d_Vertex::*)() const ) &Graphic3d_Vertex::X, "Returns the X coordinates.");
	cls_Graphic3d_Vertex.def("Y", (Standard_ShortReal (Graphic3d_Vertex::*)() const ) &Graphic3d_Vertex::Y, "Returns the Y coordinate.");
	cls_Graphic3d_Vertex.def("Z", (Standard_ShortReal (Graphic3d_Vertex::*)() const ) &Graphic3d_Vertex::Z, "Returns the Z coordinate.");
	cls_Graphic3d_Vertex.def("Distance", (Standard_ShortReal (Graphic3d_Vertex::*)(const Graphic3d_Vertex &) const ) &Graphic3d_Vertex::Distance, "Returns the distance between two points.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Buffer.hxx
	py::class_<Graphic3d_Attribute, std::unique_ptr<Graphic3d_Attribute, Deleter<Graphic3d_Attribute>>> cls_Graphic3d_Attribute(mod, "Graphic3d_Attribute", "Vertex attribute definition.");
	cls_Graphic3d_Attribute.def(py::init<>());
	cls_Graphic3d_Attribute.def("Stride", (Standard_Integer (Graphic3d_Attribute::*)() const ) &Graphic3d_Attribute::Stride, "None");
	cls_Graphic3d_Attribute.def_static("Stride_", (Standard_Integer (*)(const Graphic3d_TypeOfData)) &Graphic3d_Attribute::Stride, "Returns size of attribute of specified data type", py::arg("theType"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Buffer.hxx
	py::class_<Graphic3d_Buffer, opencascade::handle<Graphic3d_Buffer>, NCollection_Buffer> cls_Graphic3d_Buffer(mod, "Graphic3d_Buffer", "Buffer of vertex attributes.");
	cls_Graphic3d_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_Graphic3d_Buffer.def("AttributesArray", (const Graphic3d_Attribute * (Graphic3d_Buffer::*)() const ) &Graphic3d_Buffer::AttributesArray, "Returns array of attributes definitions");
	cls_Graphic3d_Buffer.def("Attribute", (const Graphic3d_Attribute & (Graphic3d_Buffer::*)(const Standard_Integer) const ) &Graphic3d_Buffer::Attribute, "Returns attribute definition", py::arg("theAttribIndex"));
	cls_Graphic3d_Buffer.def("ChangeAttribute", (Graphic3d_Attribute & (Graphic3d_Buffer::*)(const Standard_Integer)) &Graphic3d_Buffer::ChangeAttribute, "Returns attribute definition", py::arg("theAttribIndex"));
	cls_Graphic3d_Buffer.def("AttributeOffset", (Standard_Integer (Graphic3d_Buffer::*)(const Standard_Integer) const ) &Graphic3d_Buffer::AttributeOffset, "Returns data offset to specified attribute", py::arg("theAttribIndex"));
	cls_Graphic3d_Buffer.def("Data", (const Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer) const ) &Graphic3d_Buffer::Data, "Returns data for specified attribute", py::arg("theAttribIndex"));
	cls_Graphic3d_Buffer.def("ChangeData", (Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer)) &Graphic3d_Buffer::ChangeData, "Returns data for specified attribute", py::arg("theAttribIndex"));
	cls_Graphic3d_Buffer.def("value", (const Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer) const ) &Graphic3d_Buffer::value, "Access specified element.", py::arg("theElem"));
	cls_Graphic3d_Buffer.def("changeValue", (Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer)) &Graphic3d_Buffer::changeValue, "Access specified element.", py::arg("theElem"));
	cls_Graphic3d_Buffer.def("release", (void (Graphic3d_Buffer::*)()) &Graphic3d_Buffer::release, "Release buffer.");
	cls_Graphic3d_Buffer.def("Init", (bool (Graphic3d_Buffer::*)(const Standard_Integer, const Graphic3d_Attribute *, const Standard_Integer)) &Graphic3d_Buffer::Init, "Allocates new empty array", py::arg("theNbElems"), py::arg("theAttribs"), py::arg("theNbAttribs"));
	cls_Graphic3d_Buffer.def("Init", (bool (Graphic3d_Buffer::*)(const Standard_Integer, const Graphic3d_Array1OfAttribute &)) &Graphic3d_Buffer::Init, "Allocates new empty array", py::arg("theNbElems"), py::arg("theAttribs"));
	cls_Graphic3d_Buffer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Buffer::get_type_name, "None");
	cls_Graphic3d_Buffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Buffer::get_type_descriptor, "None");
	cls_Graphic3d_Buffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Buffer::*)() const ) &Graphic3d_Buffer::DynamicType, "None");
	cls_Graphic3d_Buffer.def("Data", (const Standard_Byte * (Graphic3d_Buffer::*)() const ) &Graphic3d_Buffer::Data, "Returns buffer data");
	cls_Graphic3d_Buffer.def("ChangeData", (Standard_Byte * (Graphic3d_Buffer::*)()) &Graphic3d_Buffer::ChangeData, "Returns buffer data");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_IndexBuffer.hxx
	py::class_<Graphic3d_IndexBuffer, opencascade::handle<Graphic3d_IndexBuffer>, Graphic3d_Buffer> cls_Graphic3d_IndexBuffer(mod, "Graphic3d_IndexBuffer", "Index buffer.");
	cls_Graphic3d_IndexBuffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_Graphic3d_IndexBuffer.def("InitInt32", (bool (Graphic3d_IndexBuffer::*)(const Standard_Integer)) &Graphic3d_IndexBuffer::InitInt32, "Allocates new empty index array", py::arg("theNbElems"));
	cls_Graphic3d_IndexBuffer.def("Index", (Standard_Integer (Graphic3d_IndexBuffer::*)(const Standard_Integer) const ) &Graphic3d_IndexBuffer::Index, "Access index at specified position", py::arg("theIndex"));
	cls_Graphic3d_IndexBuffer.def("SetIndex", (void (Graphic3d_IndexBuffer::*)(const Standard_Integer, const Standard_Integer)) &Graphic3d_IndexBuffer::SetIndex, "Change index at specified position", py::arg("theIndex"), py::arg("theValue"));
	cls_Graphic3d_IndexBuffer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_IndexBuffer::get_type_name, "None");
	cls_Graphic3d_IndexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_IndexBuffer::get_type_descriptor, "None");
	cls_Graphic3d_IndexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_IndexBuffer::*)() const ) &Graphic3d_IndexBuffer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BoundBuffer.hxx
	py::class_<Graphic3d_BoundBuffer, opencascade::handle<Graphic3d_BoundBuffer>, NCollection_Buffer> cls_Graphic3d_BoundBuffer(mod, "Graphic3d_BoundBuffer", "Bounds buffer.");
	cls_Graphic3d_BoundBuffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_Graphic3d_BoundBuffer.def("Init", (bool (Graphic3d_BoundBuffer::*)(const Standard_Integer, const Standard_Boolean)) &Graphic3d_BoundBuffer::Init, "Allocates new empty array", py::arg("theNbBounds"), py::arg("theHasColors"));
	cls_Graphic3d_BoundBuffer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_BoundBuffer::get_type_name, "None");
	cls_Graphic3d_BoundBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_BoundBuffer::get_type_descriptor, "None");
	cls_Graphic3d_BoundBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_BoundBuffer::*)() const ) &Graphic3d_BoundBuffer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Structure.hxx
	py::class_<Graphic3d_Structure, opencascade::handle<Graphic3d_Structure>, Standard_Transient> cls_Graphic3d_Structure(mod, "Graphic3d_Structure", "This class allows the definition a graphic object. This graphic structure can be displayed, erased, or highlighted. This graphic structure can be connected with another graphic structure. Keywords: Structure, StructureManager, Display, Erase, Highlight, UnHighlight, Visible, Priority, Selectable, Visible, Visual, Connection, Ancestors, Descendants, Transformation");
	cls_Graphic3d_Structure.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theManager"));
	cls_Graphic3d_Structure.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Graphic3d_Structure> &>(), py::arg("theManager"), py::arg("thePrs"));
	cls_Graphic3d_Structure.def("Clear", [](Graphic3d_Structure &self) -> void { return self.Clear(); });
	cls_Graphic3d_Structure.def("Clear", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::Clear, "if WithDestruction == Standard_True then suppress all the groups of primitives in the structure. and it is mandatory to create a new group in <me>. if WithDestruction == Standard_False then clears all the groups of primitives in the structure. and all the groups are conserved and empty. They will be erased at the next screen update. The structure itself is conserved. The transformation and the attributes of <me> are conserved. The childs of <me> are conserved.", py::arg("WithDestruction"));
	cls_Graphic3d_Structure.def("Display", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Display, "Displays the structure <me> in all the views of the visualiser.");
	cls_Graphic3d_Structure.def("DisplayPriority", (Standard_Integer (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::DisplayPriority, "Returns the current display priority for the structure <me>.");
	cls_Graphic3d_Structure.def("Erase", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Erase, "Erases the structure <me> in all the views of the visualiser.");
	cls_Graphic3d_Structure.def("Highlight", [](Graphic3d_Structure &self, const opencascade::handle<Graphic3d_PresentationAttributes> & a0) -> void { return self.Highlight(a0); }, py::arg("theStyle"));
	cls_Graphic3d_Structure.def("Highlight", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &, const Standard_Boolean)) &Graphic3d_Structure::Highlight, "Highlights the structure in all the views with the given style", py::arg("theStyle"), py::arg("theToUpdateMgr"));
	cls_Graphic3d_Structure.def("Remove", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Remove, "Suppress the structure <me>. It will be erased at the next screen update. Warning: No more graphic operations in <me> after this call. Category: Methods to modify the class definition");
	cls_Graphic3d_Structure.def("CalculateBoundBox", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::CalculateBoundBox, "Computes axis-aligned bounding box of a structure.");
	cls_Graphic3d_Structure.def("SetInfiniteState", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetInfiniteState, "If <theToSet> is Standard_True then <me> is infinite and the MinMaxValues method method return : theXMin = theYMin = theZMin = RealFirst(). theXMax = theYMax = theZMax = RealLast(). By default, <me> is not infinite but empty.", py::arg("theToSet"));
	cls_Graphic3d_Structure.def("SetDisplayPriority", (void (Graphic3d_Structure::*)(const Standard_Integer)) &Graphic3d_Structure::SetDisplayPriority, "Modifies the order of displaying the structure. Values are between 0 and 10. Structures are drawn according to their display priorities in ascending order. A structure of priority 10 is displayed the last and appears over the others. The default value is 5. Category: Methods to modify the class definition Warning: If <me> is displayed then the SetDisplayPriority method erase <me> and display <me> with the new priority. Raises PriorityDefinitionError if <Priority> is greater than 10 or a negative value.", py::arg("Priority"));
	cls_Graphic3d_Structure.def("ResetDisplayPriority", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::ResetDisplayPriority, "Reset the current priority of the structure to the previous priority. Category: Methods to modify the class definition Warning: If <me> is displayed then the SetDisplayPriority method erase <me> and display <me> with the previous priority.");
	cls_Graphic3d_Structure.def("SetZLayer", (void (Graphic3d_Structure::*)(const Graphic3d_ZLayerId)) &Graphic3d_Structure::SetZLayer, "Set Z layer ID for the structure. The Z layer mechanism allows to display structures presented in higher layers in overlay of structures in lower layers by switching off z buffer depth test between layers", py::arg("theLayerId"));
	cls_Graphic3d_Structure.def("GetZLayer", (Graphic3d_ZLayerId (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::GetZLayer, "Get Z layer ID of displayed structure. The method returns -1 if the structure has no ID (deleted from graphic driver).");
	cls_Graphic3d_Structure.def("SetClipPlanes", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_Structure::SetClipPlanes, "Changes a sequence of clip planes slicing the structure on rendering.", py::arg("thePlanes"));
	cls_Graphic3d_Structure.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::ClipPlanes, "Get clip planes slicing the structure on rendering.");
	cls_Graphic3d_Structure.def("SetVisible", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetVisible, "Modifies the visibility indicator to Standard_True or Standard_False for the structure <me>. The default value at the definition of <me> is Standard_True.", py::arg("AValue"));
	cls_Graphic3d_Structure.def("SetVisual", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfStructure)) &Graphic3d_Structure::SetVisual, "Modifies the visualisation mode for the structure <me>.", py::arg("AVisual"));
	cls_Graphic3d_Structure.def("SetZoomLimit", (void (Graphic3d_Structure::*)(const Standard_Real, const Standard_Real)) &Graphic3d_Structure::SetZoomLimit, "Modifies the minimum and maximum zoom coefficients for the structure <me>. The default value at the definition of <me> is unlimited. Category: Methods to modify the class definition Warning: Raises StructureDefinitionError if <LimitInf> is greater than <LimitSup> or if <LimitInf> or <LimitSup> is a negative value.", py::arg("LimitInf"), py::arg("LimitSup"));
	cls_Graphic3d_Structure.def("SetIsForHighlight", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetIsForHighlight, "marks the structure <me> representing wired structure needed for highlight only so it won't be added to BVH tree. Category: Methods to modify the class definition", py::arg("isForHighlight"));
	cls_Graphic3d_Structure.def("UnHighlight", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::UnHighlight, "Suppresses the highlight for the structure <me> in all the views of the visualiser.");
	cls_Graphic3d_Structure.def("Compute", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::Compute, "None");
	cls_Graphic3d_Structure.def("Compute", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("aProjector"));
	cls_Graphic3d_Structure.def("Compute", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"));
	cls_Graphic3d_Structure.def("Compute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("aProjector"), py::arg("aStructure"));
	cls_Graphic3d_Structure.def("Compute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
	cls_Graphic3d_Structure.def("ReCompute", (void (Graphic3d_Structure::*)()) &Graphic3d_Structure::ReCompute, "Forces a new construction of the structure <me> if <me> is displayed and TOS_COMPUTED.");
	cls_Graphic3d_Structure.def("ReCompute", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_Structure::ReCompute, "Forces a new construction of the structure <me> if <me> is displayed in <aProjetor> and TOS_COMPUTED.", py::arg("aProjector"));
	cls_Graphic3d_Structure.def("ContainsFacet", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::ContainsFacet, "Returns Standard_True if the structure <me> contains Polygons, Triangles or Quadrangles.");
	cls_Graphic3d_Structure.def("Groups", (const Graphic3d_SequenceOfGroup & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::Groups, "Returns the groups sequence included in the structure <me> (internal storage).");
	cls_Graphic3d_Structure.def("NumberOfGroups", (Standard_Integer (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::NumberOfGroups, "Returns the current number of groups in the structure <me>.");
	cls_Graphic3d_Structure.def("NewGroup", (opencascade::handle<Graphic3d_Group> (Graphic3d_Structure::*)()) &Graphic3d_Structure::NewGroup, "Append new group to this structure.");
	cls_Graphic3d_Structure.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::HighlightStyle, "Returns the highlight color for the Highlight method with the highlight method TOHM_COLOR or TOHM_BOUNDBOX.");
	cls_Graphic3d_Structure.def("IsDeleted", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsDeleted, "Returns Standard_True if the structure <me> is deleted. <me> is deleted after the call Remove (me).");
	cls_Graphic3d_Structure.def("IsDisplayed", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsDisplayed, "Returns the display indicator for the structure <me>.");
	cls_Graphic3d_Structure.def("IsEmpty", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsEmpty, "Returns Standard_True if the structure <me> is empty. Warning: A structure is empty if : it do not have group or all the groups are empties and it do not have descendant or all the descendants are empties.");
	cls_Graphic3d_Structure.def("IsInfinite", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsInfinite, "Returns Standard_True if the structure <me> is infinite.");
	cls_Graphic3d_Structure.def("IsHighlighted", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsHighlighted, "Returns the highlight indicator for the structure <me>.");
	cls_Graphic3d_Structure.def("IsTransformed", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsTransformed, "Returns Standard_True if the structure <me> is transformed. <=> The transformation != Identity.");
	cls_Graphic3d_Structure.def("IsVisible", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsVisible, "Returns the visibility indicator for the structure <me>.");
	cls_Graphic3d_Structure.def("MinMaxValues", [](Graphic3d_Structure &self) -> Bnd_Box { return self.MinMaxValues(); });
	cls_Graphic3d_Structure.def("MinMaxValues", (Bnd_Box (Graphic3d_Structure::*)(const Standard_Boolean) const ) &Graphic3d_Structure::MinMaxValues, "Returns the coordinates of the boundary box of the structure <me>. If <theToIgnoreInfiniteFlag> is TRUE, the method returns actual graphical boundaries of the Graphic3d_Group components. Otherwise, the method returns boundaries taking into account infinite state of the structure. This approach generally used for application specific fit operation (e.g. fitting the model into screen, not taking into accout infinite helper elements). Warning: If the structure <me> is empty then the empty box is returned, If the structure <me> is infinite then the whole box is returned.", py::arg("theToIgnoreInfiniteFlag"));
	cls_Graphic3d_Structure.def("Visual", (Graphic3d_TypeOfStructure (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::Visual, "Returns the visualisation mode for the structure <me>.");
	cls_Graphic3d_Structure.def_static("AcceptConnection_", (Standard_Boolean (*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::AcceptConnection, "Returns Standard_True if the connection is possible between <AStructure1> and <AStructure2> without a creation of a cycle.", py::arg("AStructure1"), py::arg("AStructure2"), py::arg("AType"));
	cls_Graphic3d_Structure.def("Ancestors", (void (Graphic3d_Structure::*)(Graphic3d_MapOfStructure &) const ) &Graphic3d_Structure::Ancestors, "Returns the group of structures to which <me> is connected.", py::arg("SG"));
	cls_Graphic3d_Structure.def("Connect", [](Graphic3d_Structure &self, const opencascade::handle<Graphic3d_Structure> & a0, const Graphic3d_TypeOfConnection a1) -> void { return self.Connect(a0, a1); }, py::arg("AStructure"), py::arg("AType"));
	cls_Graphic3d_Structure.def("Connect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection, const Standard_Boolean)) &Graphic3d_Structure::Connect, "If Atype is TOC_DESCENDANT then add <AStructure> as a child structure of <me>. If Atype is TOC_ANCESTOR then add <AStructure> as a parent structure of <me>. The connection propagates Display, Highlight, Erase, Remove, and stacks the transformations. No connection if the graph of the structures contains a cycle and <WithCheck> is Standard_True;", py::arg("AStructure"), py::arg("AType"), py::arg("WithCheck"));
	cls_Graphic3d_Structure.def("Descendants", (void (Graphic3d_Structure::*)(Graphic3d_MapOfStructure &) const ) &Graphic3d_Structure::Descendants, "Returns the group of structures connected to <me>.", py::arg("SG"));
	cls_Graphic3d_Structure.def("Disconnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::Disconnect, "Suppress the connection between <AStructure> and <me>.", py::arg("AStructure"));
	cls_Graphic3d_Structure.def("DisconnectAll", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::DisconnectAll, "If Atype is TOC_DESCENDANT then suppress all the connections with the child structures of <me>. If Atype is TOC_ANCESTOR then suppress all the connections with the parent structures of <me>.", py::arg("AType"));
	cls_Graphic3d_Structure.def_static("Network_", (void (*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection, Graphic3d_MapOfStructure &)) &Graphic3d_Structure::Network, "Returns <ASet> the group of structures : - directly or indirectly connected to <AStructure> if the TypeOfConnection == TOC_DESCENDANT - to which <AStructure> is directly or indirectly connected if the TypeOfConnection == TOC_ANCESTOR", py::arg("AStructure"), py::arg("AType"), py::arg("ASet"));
	cls_Graphic3d_Structure.def("SetOwner", (void (Graphic3d_Structure::*)(const Standard_Address)) &Graphic3d_Structure::SetOwner, "None", py::arg("Owner"));
	cls_Graphic3d_Structure.def("Owner", (Standard_Address (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::Owner, "None");
	cls_Graphic3d_Structure.def("SetHLRValidation", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetHLRValidation, "None", py::arg("AFlag"));
	cls_Graphic3d_Structure.def("HLRValidation", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::HLRValidation, "None");
	cls_Graphic3d_Structure.def("Transformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::Transformation, "Return local transformation.");
	cls_Graphic3d_Structure.def("SetTransformation", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::SetTransformation, "Modifies the current local transformation", py::arg("theTrsf"));
	cls_Graphic3d_Structure.def("Transform", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::Transform, "None", py::arg("theTrsf"));
	cls_Graphic3d_Structure.def("SetTransformPersistence", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &Graphic3d_Structure::SetTransformPersistence, "Modifies the current transform persistence (pan, zoom or rotate)", py::arg("theTrsfPers"));
	cls_Graphic3d_Structure.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::TransformPersistence, "Returns transform persistence of the presentable object.");
	cls_Graphic3d_Structure.def("SetMutable", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::SetMutable, "Sets if the structure location has mutable nature (content or location will be changed regularly).", py::arg("theIsMutable"));
	cls_Graphic3d_Structure.def("IsMutable", (Standard_Boolean (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::IsMutable, "Returns true if structure has mutable nature (content or location are be changed regularly). Mutable structure will be managed in different way than static onces.");
	cls_Graphic3d_Structure.def("ComputeVisual", (Graphic3d_TypeOfStructure (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::ComputeVisual, "None");
	cls_Graphic3d_Structure.def("GraphicClear", (void (Graphic3d_Structure::*)(const Standard_Boolean)) &Graphic3d_Structure::GraphicClear, "Clears the structure <me>.", py::arg("WithDestruction"));
	cls_Graphic3d_Structure.def("GraphicConnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::GraphicConnect, "None", py::arg("ADaughter"));
	cls_Graphic3d_Structure.def("GraphicDisconnect", (void (Graphic3d_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_Structure::GraphicDisconnect, "None", py::arg("ADaughter"));
	cls_Graphic3d_Structure.def("GraphicTransform", (void (Graphic3d_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_Structure::GraphicTransform, "Internal method which sets new transformation without calling graphic manager callbacks.", py::arg("theTrsf"));
	cls_Graphic3d_Structure.def("Identification", (Standard_Integer (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::Identification, "Returns the identification number of the structure <me>.");
	cls_Graphic3d_Structure.def_static("PrintNetwork_", (void (*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::PrintNetwork, "Prints informations about the network associated with the structure <AStructure>.", py::arg("AStructure"), py::arg("AType"));
	cls_Graphic3d_Structure.def("Remove", (void (Graphic3d_Structure::*)(const Standard_Address, const Graphic3d_TypeOfConnection)) &Graphic3d_Structure::Remove, "Suppress the adress <APtr> in the list of descendants or in the list of ancestors.", py::arg("APtr"), py::arg("AType"));
	cls_Graphic3d_Structure.def("SetComputeVisual", (void (Graphic3d_Structure::*)(const Graphic3d_TypeOfStructure)) &Graphic3d_Structure::SetComputeVisual, "None", py::arg("AVisual"));
	cls_Graphic3d_Structure.def_static("Transforms_", [](const gp_Trsf & theTrsf, const Standard_Real theX, const Standard_Real theY, const Standard_Real theZ, Standard_Real & theNewX, Standard_Real & theNewY, Standard_Real & theNewZ){ Graphic3d_Structure::Transforms(theTrsf, theX, theY, theZ, theNewX, theNewY, theNewZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theNewX, theNewY, theNewZ); }, "Transforms theX, theY, theZ with the transformation theTrsf.", py::arg("theTrsf"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNewX"), py::arg("theNewY"), py::arg("theNewZ"));
	cls_Graphic3d_Structure.def("CStructure", (const opencascade::handle<Graphic3d_CStructure> & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::CStructure, "Returns the low-level structure");
	cls_Graphic3d_Structure.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Structure::get_type_name, "None");
	cls_Graphic3d_Structure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Structure::get_type_descriptor, "None");
	cls_Graphic3d_Structure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Structure::*)() const ) &Graphic3d_Structure::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfPrimitives.hxx
	py::class_<Graphic3d_ArrayOfPrimitives, opencascade::handle<Graphic3d_ArrayOfPrimitives>, Standard_Transient> cls_Graphic3d_ArrayOfPrimitives(mod, "Graphic3d_ArrayOfPrimitives", "This class furnish services to defined and fill an array of primitives compatible with the use of the OPENGl glDrawArrays() or glDrawElements() functions. NOTE that the main goal of this kind of primitive is to avoid multiple copies of datas between each layer of the software. So the array datas exist only one time and the use of SetXxxxxx() methods enable to change dynamically the aspect of this primitive.");
	cls_Graphic3d_ArrayOfPrimitives.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfPrimitives::get_type_name, "None");
	cls_Graphic3d_ArrayOfPrimitives.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfPrimitives::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfPrimitives.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::DynamicType, "None");
	cls_Graphic3d_ArrayOfPrimitives.def("Attributes", (const opencascade::handle<Graphic3d_Buffer> & (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::Attributes, "Returns vertex attributes buffer (colors, normals, texture coordinates).");
	cls_Graphic3d_ArrayOfPrimitives.def("Type", (Graphic3d_TypeOfPrimitiveArray (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::Type, "Returns the type of this primitive");
	cls_Graphic3d_ArrayOfPrimitives.def("StringType", (Standard_CString (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::StringType, "Returns the string type of this primitive");
	cls_Graphic3d_ArrayOfPrimitives.def("HasVertexNormals", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::HasVertexNormals, "Returns TRUE when vertex normals array is defined.");
	cls_Graphic3d_ArrayOfPrimitives.def("HasVertexColors", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::HasVertexColors, "Returns TRUE when vertex colors array is defined.");
	cls_Graphic3d_ArrayOfPrimitives.def("HasVertexTexels", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::HasVertexTexels, "Returns TRUE when vertex texels array is defined.");
	cls_Graphic3d_ArrayOfPrimitives.def("VertexNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::VertexNumber, "Returns the number of defined vertex");
	cls_Graphic3d_ArrayOfPrimitives.def("ItemNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::ItemNumber, "Returns the number of total items according to the array type.");
	cls_Graphic3d_ArrayOfPrimitives.def("IsValid", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)()) &Graphic3d_ArrayOfPrimitives::IsValid, "Returns TRUE only when the contains of this array is available.");
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theVertex"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Graphic3d_Vec3 &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theVertex"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex color in the vertex array. Warning: theColor is ignored when the hasVColors constructor parameter is FALSE", py::arg("theVertex"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex color in the vertex array. Warning: theColor is ignored when the hasVColors constructor parameter is FALSE", py::arg("theVertex"), py::arg("theColor32"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const Graphic3d_Vec4ub &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex color in the vertex array. Warning: theColor is ignored when the hasVColors constructor parameter is FALSE", py::arg("theVertex"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex normal in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex normal in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex normal in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and color in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE and theColor is ignored when the hasVColors constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &, const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and color in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE and theColor is ignored when the hasVColors constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"), py::arg("theColor32"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Pnt2d &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex texture in the vertex array. theTexel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theTexel"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex texture coordinates in the vertex array. Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theTX"), py::arg("theTY"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex texture coordinates in the vertex array. Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theTX"), py::arg("theTY"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &, const gp_Pnt2d &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and texture in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE and theTexel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"), py::arg("theTexel"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and texture in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE and Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"), py::arg("theTX"), py::arg("theTY"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and texture in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE and Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"), py::arg("theTX"), py::arg("theTY"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertice", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const gp_Pnt &)) &Graphic3d_ArrayOfPrimitives::SetVertice, "Change the vertice of rank theIndex in the array.", py::arg("theIndex"), py::arg("theVertex"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertice", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::SetVertice, "Change the vertice of rank theIndex in the array.", py::arg("theIndex"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Graphic3d_Vec4ub &)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex> in the array.", py::arg("theIndex"), py::arg("theColor32"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexNormal", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const gp_Dir &)) &Graphic3d_ArrayOfPrimitives::SetVertexNormal, "Change the vertex normal of rank theIndex in the array.", py::arg("theIndex"), py::arg("theNormal"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexNormal", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetVertexNormal, "Change the vertex normal of rank theIndex in the array.", py::arg("theIndex"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexTexel", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const gp_Pnt2d &)) &Graphic3d_ArrayOfPrimitives::SetVertexTexel, "Change the vertex texel of rank theIndex in the array.", py::arg("theIndex"), py::arg("theTexel"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetVertexTexel", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetVertexTexel, "Change the vertex texel of rank theIndex in the array.", py::arg("theIndex"), py::arg("theTX"), py::arg("theTY"));
	cls_Graphic3d_ArrayOfPrimitives.def("Vertice", (gp_Pnt (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::Vertice, "Returns the vertice at rank theRank from the vertex table if defined.", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("Vertice", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Vertice(theRank, theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Returns the vertice coordinates at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", (Quantity_Color (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::VertexColor, "Returns the vertex color at rank theRank from the vertex table if defined.", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, Graphic3d_Vec4ub &) const ) &Graphic3d_ArrayOfPrimitives::VertexColor, "Returns the vertex color at rank theIndex from the vertex table if defined.", py::arg("theIndex"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theR, Standard_Real & theG, Standard_Real & theB){ self.VertexColor(theRank, theR, theG, theB); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theR, theG, theB); }, "Returns the vertex color values at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Integer & theColor){ self.VertexColor(theRank, theColor); return theColor; }, "Returns the vertex color values at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexNormal", (gp_Dir (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::VertexNormal, "Returns the vertex normal at rank theRank from the vertex table if defined.", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexNormal", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theNX, Standard_Real & theNY, Standard_Real & theNZ){ self.VertexNormal(theRank, theNX, theNY, theNZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theNX, theNY, theNZ); }, "Returns the vertex normal coordinates at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexTexel", (gp_Pnt2d (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::VertexTexel, "Returns the vertex texture at rank theRank from the vertex table if defined.", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("VertexTexel", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theTX, Standard_Real & theTY){ self.VertexTexel(theRank, theTX, theTY); return std::tuple<Standard_Real &, Standard_Real &>(theTX, theTY); }, "Returns the vertex texture coordinates at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theTX"), py::arg("theTY"));
	cls_Graphic3d_ArrayOfPrimitives.def("Indices", (const opencascade::handle<Graphic3d_IndexBuffer> & (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::Indices, "Returns optional index buffer.");
	cls_Graphic3d_ArrayOfPrimitives.def("EdgeNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::EdgeNumber, "Returns the number of defined edges");
	cls_Graphic3d_ArrayOfPrimitives.def("Edge", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::Edge, "Returns the vertex index at rank theRank in the range [1,EdgeNumber()]", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddEdge", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddEdge, "Adds an edge in the range [1,VertexNumber()] in the array.", py::arg("theVertexIndex"));
	cls_Graphic3d_ArrayOfPrimitives.def("Bounds", (const opencascade::handle<Graphic3d_BoundBuffer> & (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::Bounds, "Returns optional bounds buffer.");
	cls_Graphic3d_ArrayOfPrimitives.def("HasBoundColors", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::HasBoundColors, "Returns TRUE when bound colors array is defined.");
	cls_Graphic3d_ArrayOfPrimitives.def("BoundNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const ) &Graphic3d_ArrayOfPrimitives::BoundNumber, "Returns the number of defined bounds");
	cls_Graphic3d_ArrayOfPrimitives.def("Bound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::Bound, "Returns the edge number at rank theRank.", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("BoundColor", (Quantity_Color (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const ) &Graphic3d_ArrayOfPrimitives::BoundColor, "Returns the bound color at rank theRank from the bound table if defined.", py::arg("theRank"));
	cls_Graphic3d_ArrayOfPrimitives.def("BoundColor", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theR, Standard_Real & theG, Standard_Real & theB){ self.BoundColor(theRank, theR, theG, theB); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theR, theG, theB); }, "Returns the bound color values at rank theRank from the bound table if defined.", py::arg("theRank"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddBound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddBound, "Adds a bound of length theEdgeNumber in the bound array", py::arg("theEdgeNumber"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddBound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::AddBound, "Adds a bound of length theEdgeNumber and bound color theBColor in the bound array. Warning: theBColor is ignored when the hasBColors constructor parameter is FALSE", py::arg("theEdgeNumber"), py::arg("theBColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("AddBound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddBound, "Adds a bound of length theEdgeNumber and bound color coordinates in the bound array. Warning: <theR,theG,theB> are ignored when the hasBColors constructor parameter is FALSE", py::arg("theEdgeNumber"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetBoundColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::SetBoundColor, "Change the bound color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theColor"));
	cls_Graphic3d_ArrayOfPrimitives.def("SetBoundColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetBoundColor, "Change the bound color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theR"), py::arg("theG"), py::arg("theB"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Group.hxx
	py::class_<Graphic3d_Group, opencascade::handle<Graphic3d_Group>, Standard_Transient> cls_Graphic3d_Group(mod, "Graphic3d_Group", "This class allows the definition of groups of primitives inside of graphic objects (presentations). A group contains the primitives and attributes for which the range is limited to this group. The primitives of a group can be globally suppressed.");
	cls_Graphic3d_Group.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Group::get_type_name, "None");
	cls_Graphic3d_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Group::get_type_descriptor, "None");
	cls_Graphic3d_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Group::*)() const ) &Graphic3d_Group::DynamicType, "None");
	cls_Graphic3d_Group.def("Clear", [](Graphic3d_Group &self) -> void { return self.Clear(); });
	cls_Graphic3d_Group.def("Clear", (void (Graphic3d_Group::*)(const Standard_Boolean)) &Graphic3d_Group::Clear, "Supress all primitives and attributes of <me>. To clear group without update in Graphic3d_StructureManager pass Standard_False as <theUpdateStructureMgr>. This used on context and viewer destruction, when the pointer to structure manager in Graphic3d_Structure could be already released (pointers are used here to avoid handle cross-reference);", py::arg("theUpdateStructureMgr"));
	cls_Graphic3d_Group.def("Remove", (void (Graphic3d_Group::*)()) &Graphic3d_Group::Remove, "Supress the group <me> in the structure. Warning: No more graphic operations in <me> after this call. Modifies the current modelling transform persistence (pan, zoom or rotate) Get the current modelling transform persistence (pan, zoom or rotate)");
	cls_Graphic3d_Group.def("LineAspect", (opencascade::handle<Graphic3d_AspectLine3d> (Graphic3d_Group::*)() const ) &Graphic3d_Group::LineAspect, "Return line aspect.");
	cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Assign line aspect to the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("FillAreaAspect", (opencascade::handle<Graphic3d_AspectFillArea3d> (Graphic3d_Group::*)() const ) &Graphic3d_Group::FillAreaAspect, "Return fill area aspect.");
	cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Modifies the context for all the face primitives of the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("TextAspect", (opencascade::handle<Graphic3d_AspectText3d> (Graphic3d_Group::*)() const ) &Graphic3d_Group::TextAspect, "Return text aspect.");
	cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Modifies the context for all the text primitives of the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("MarkerAspect", (opencascade::handle<Graphic3d_AspectMarker3d> (Graphic3d_Group::*)() const ) &Graphic3d_Group::MarkerAspect, "Return marker aspect.");
	cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Modifies the context for all the marker primitives of the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the line primitives created after this call in the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the face primitives created after this call in the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the text primitives created after this call in the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the marker primitives created after this call in the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("IsGroupPrimitivesAspectSet", (Standard_Boolean (Graphic3d_Group::*)(const Graphic3d_GroupAspect) const ) &Graphic3d_Group::IsGroupPrimitivesAspectSet, "Returns TRUE if aspect is set for the group.", py::arg("theAspect"));
	cls_Graphic3d_Group.def("GroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &, const opencascade::handle<Graphic3d_AspectText3d> &, const opencascade::handle<Graphic3d_AspectMarker3d> &, const opencascade::handle<Graphic3d_AspectFillArea3d> &) const ) &Graphic3d_Group::GroupPrimitivesAspect, "Returns the context of all the primitives of the group.", py::arg("theAspLine"), py::arg("theAspText"), py::arg("theAspMarker"), py::arg("theAspFill"));
	cls_Graphic3d_Group.def("PrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &, const opencascade::handle<Graphic3d_AspectText3d> &, const opencascade::handle<Graphic3d_AspectMarker3d> &, const opencascade::handle<Graphic3d_AspectFillArea3d> &) const ) &Graphic3d_Group::PrimitivesAspect, "Returns the last inserted context in the group for each kind of primitives.", py::arg("theAspLine"), py::arg("theAspText"), py::arg("theAspMarker"), py::arg("theAspFill"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const Graphic3d_Vertex & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); }, py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("AAngle"), py::arg("ATp"), py::arg("AHta"), py::arg("AVta"));
	cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const Standard_CString, const Graphic3d_Vertex &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). AAngle : Orientation of the text (with respect to the horizontal).", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("AAngle"), py::arg("ATp"), py::arg("AHta"), py::arg("AVta"), py::arg("EvalMinMax"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const Graphic3d_Vertex & a1, const Standard_Real a2) -> void { return self.Text(a0, a1, a2); }, py::arg("AText"), py::arg("APoint"), py::arg("AHeight"));
	cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const Standard_CString, const Graphic3d_Vertex &, const Standard_Real, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). The other attributes have the following default values: AAngle : PI / 2. ATp : TP_RIGHT AHta : HTA_LEFT AVta : VTA_BOTTOM", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("EvalMinMax"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const Graphic3d_Vertex & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); }, py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("AAngle"), py::arg("ATp"), py::arg("AHta"), py::arg("AVta"));
	cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const TCollection_ExtendedString &, const Graphic3d_Vertex &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). AAngle : Orientation of the text (with respect to the horizontal).", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("AAngle"), py::arg("ATp"), py::arg("AHta"), py::arg("AVta"), py::arg("EvalMinMax"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const Graphic3d_Vertex & a1, const Standard_Real a2) -> void { return self.Text(a0, a1, a2); }, py::arg("AText"), py::arg("APoint"), py::arg("AHeight"));
	cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const TCollection_ExtendedString &, const Graphic3d_Vertex &, const Standard_Real, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). The other attributes have the following default values: AAngle : PI / 2. ATp : TP_RIGHT AHta : HTA_LEFT AVta : VTA_BOTTOM", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("EvalMinMax"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); }, py::arg("theTextUtf"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6, const Standard_Boolean a7) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("theTextUtf"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"));
	cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const Standard_CString, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <theText> at orientation <theOrientation> in 3D space.", py::arg("theTextUtf"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"), py::arg("theHasOwnAnchor"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); }, py::arg("theText"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"));
	cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6, const Standard_Boolean a7) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("theText"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"));
	cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const TCollection_ExtendedString &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <theText> at orientation <theOrientation> in 3D space.", py::arg("theText"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"), py::arg("theHasOwnAnchor"));
	cls_Graphic3d_Group.def("AddPrimitiveArray", [](Graphic3d_Group &self, const Graphic3d_TypeOfPrimitiveArray a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const opencascade::handle<Graphic3d_Buffer> & a2, const opencascade::handle<Graphic3d_BoundBuffer> & a3) -> void { return self.AddPrimitiveArray(a0, a1, a2, a3); }, py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"));
	cls_Graphic3d_Group.def("AddPrimitiveArray", (void (Graphic3d_Group::*)(const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &, const Standard_Boolean)) &Graphic3d_Group::AddPrimitiveArray, "Adds an array of primitives for display", py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"), py::arg("theToEvalMinMax"));
	cls_Graphic3d_Group.def("AddPrimitiveArray", [](Graphic3d_Group &self, const opencascade::handle<Graphic3d_ArrayOfPrimitives> & a0) -> void { return self.AddPrimitiveArray(a0); }, py::arg("thePrim"));
	cls_Graphic3d_Group.def("AddPrimitiveArray", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const Standard_Boolean)) &Graphic3d_Group::AddPrimitiveArray, "Adds an array of primitives for display", py::arg("thePrim"), py::arg("theToEvalMinMax"));
	cls_Graphic3d_Group.def("Marker", [](Graphic3d_Group &self, const Graphic3d_Vertex & a0) -> void { return self.Marker(a0); }, py::arg("thePoint"));
	cls_Graphic3d_Group.def("Marker", (void (Graphic3d_Group::*)(const Graphic3d_Vertex &, const Standard_Boolean)) &Graphic3d_Group::Marker, "Creates a primitive array with single marker using AddPrimitiveArray().", py::arg("thePoint"), py::arg("theToEvalMinMax"));
	cls_Graphic3d_Group.def("SetStencilTestOptions", (void (Graphic3d_Group::*)(const Standard_Boolean)) &Graphic3d_Group::SetStencilTestOptions, "sets the stencil test to theIsEnabled state;", py::arg("theIsEnabled"));
	cls_Graphic3d_Group.def("SetFlippingOptions", (void (Graphic3d_Group::*)(const Standard_Boolean, const gp_Ax2 &)) &Graphic3d_Group::SetFlippingOptions, "sets the flipping to theIsEnabled state.", py::arg("theIsEnabled"), py::arg("theRefPlane"));
	cls_Graphic3d_Group.def("ContainsFacet", (bool (Graphic3d_Group::*)() const ) &Graphic3d_Group::ContainsFacet, "Returns true if the group contains Polygons, Triangles or Quadrangles.");
	cls_Graphic3d_Group.def("IsDeleted", (Standard_Boolean (Graphic3d_Group::*)() const ) &Graphic3d_Group::IsDeleted, "Returns Standard_True if the group <me> is deleted. <me> is deleted after the call Remove (me) or the associated structure is deleted.");
	cls_Graphic3d_Group.def("IsEmpty", (Standard_Boolean (Graphic3d_Group::*)() const ) &Graphic3d_Group::IsEmpty, "Returns Standard_True if the group <me> is empty.");
	cls_Graphic3d_Group.def("MinMaxValues", [](Graphic3d_Group &self, Standard_Real & theXMin, Standard_Real & theYMin, Standard_Real & theZMin, Standard_Real & theXMax, Standard_Real & theYMax, Standard_Real & theZMax){ self.MinMaxValues(theXMin, theYMin, theZMin, theXMax, theYMax, theZMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(theXMin, theYMin, theZMin, theXMax, theYMax, theZMax); }, "Returns the coordinates of the boundary box of the group.", py::arg("theXMin"), py::arg("theYMin"), py::arg("theZMin"), py::arg("theXMax"), py::arg("theYMax"), py::arg("theZMax"));
	cls_Graphic3d_Group.def("SetMinMaxValues", (void (Graphic3d_Group::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_Group::SetMinMaxValues, "Sets the coordinates of the boundary box of the group.", py::arg("theXMin"), py::arg("theYMin"), py::arg("theZMin"), py::arg("theXMax"), py::arg("theYMax"), py::arg("theZMax"));
	cls_Graphic3d_Group.def("BoundingBox", (const Graphic3d_BndBox4f & (Graphic3d_Group::*)() const ) &Graphic3d_Group::BoundingBox, "Returns boundary box of the group <me> without transformation applied,");
	cls_Graphic3d_Group.def("ChangeBoundingBox", (Graphic3d_BndBox4f & (Graphic3d_Group::*)()) &Graphic3d_Group::ChangeBoundingBox, "Returns non-const boundary box of the group <me> without transformation applied,");
	cls_Graphic3d_Group.def("Structure", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Group::*)() const ) &Graphic3d_Group::Structure, "Returns the structure containing the group <me>.");
	cls_Graphic3d_Group.def("SetClosed", (void (Graphic3d_Group::*)(const bool)) &Graphic3d_Group::SetClosed, "Changes property shown that primitive arrays within this group form closed volume (do no contain open shells).", py::arg("theIsClosed"));
	cls_Graphic3d_Group.def("IsClosed", (bool (Graphic3d_Group::*)() const ) &Graphic3d_Group::IsClosed, "Return true if primitive arrays within this graphic group form closed volume (do no contain open shells).");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ClipPlane.hxx
	py::class_<Graphic3d_ClipPlane, opencascade::handle<Graphic3d_ClipPlane>, Standard_Transient> cls_Graphic3d_ClipPlane(mod, "Graphic3d_ClipPlane", "Container for properties describing graphic driver clipping planes. It is up to application to create instances of this class and specify its properties. The instances are passed into graphic driver or other facilities that implement clipping features (e.g. selection). Depending on usage context the class can be used to specify: - Global clipping applied over the whole scene. - Object-level clipping applied for each particular object. The plane equation is specified in 'world' coordinate system. Please note that the set of planes can define convex clipping volume. Be aware that number of clip planes supported by OpenGl is implementation dependent: at least 6 planes are available. Thus, take into account number of clipping planes passed for rendering: the object planes plus the view defined ones.");
	cls_Graphic3d_ClipPlane.def(py::init<>());
	cls_Graphic3d_ClipPlane.def(py::init([] (const Graphic3d_ClipPlane &other) {return new Graphic3d_ClipPlane(other);}), "Copy constructor", py::arg("other"));
	cls_Graphic3d_ClipPlane.def(py::init<const Graphic3d_ClipPlane::Equation &>(), py::arg("theEquation"));
	cls_Graphic3d_ClipPlane.def(py::init<const gp_Pln &>(), py::arg("thePlane"));
	cls_Graphic3d_ClipPlane.def("SetEquation", (void (Graphic3d_ClipPlane::*)(const gp_Pln &)) &Graphic3d_ClipPlane::SetEquation, "Set plane equation by its geometrical definition. The equation is specified in 'world' coordinate system.", py::arg("thePlane"));
	cls_Graphic3d_ClipPlane.def("SetEquation", (void (Graphic3d_ClipPlane::*)(const Graphic3d_ClipPlane::Equation &)) &Graphic3d_ClipPlane::SetEquation, "Set 4-component equation vector for clipping plane. The equation is specified in 'world' coordinate system.", py::arg("theEquation"));
	cls_Graphic3d_ClipPlane.def("GetEquation", (const Graphic3d_ClipPlane::Equation & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::GetEquation, "Get 4-component equation vector for clipping plane.");
	cls_Graphic3d_ClipPlane.def("IsOn", (Standard_Boolean (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::IsOn, "Check that the clipping plane is turned on.");
	cls_Graphic3d_ClipPlane.def("SetOn", (void (Graphic3d_ClipPlane::*)(const Standard_Boolean)) &Graphic3d_ClipPlane::SetOn, "Change state of the clipping plane.", py::arg("theIsOn"));
	cls_Graphic3d_ClipPlane.def("SetCapping", (void (Graphic3d_ClipPlane::*)(const Standard_Boolean)) &Graphic3d_ClipPlane::SetCapping, "Change state of capping surface rendering.", py::arg("theIsOn"));
	cls_Graphic3d_ClipPlane.def("IsCapping", (Standard_Boolean (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::IsCapping, "Check state of capping surface rendering.");
	cls_Graphic3d_ClipPlane.def("ToPlane", (const gp_Pln & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::ToPlane, "Get geometrical definition.");
	cls_Graphic3d_ClipPlane.def("Clone", (opencascade::handle<Graphic3d_ClipPlane> (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::Clone, "Clone plane. Virtual method to simplify copying procedure if plane class is redefined at application level to add specific fields to it e.g. id, name, etc.");
	cls_Graphic3d_ClipPlane.def("SetCappingMaterial", (void (Graphic3d_ClipPlane::*)(const Graphic3d_MaterialAspect &)) &Graphic3d_ClipPlane::SetCappingMaterial, "Set material for rendering capping surface.", py::arg("theMat"));
	cls_Graphic3d_ClipPlane.def("CappingMaterial", (const Graphic3d_MaterialAspect & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::CappingMaterial, "Returns capping material.");
	cls_Graphic3d_ClipPlane.def("SetCappingTexture", (void (Graphic3d_ClipPlane::*)(const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_ClipPlane::SetCappingTexture, "Set texture to be applied on capping surface.", py::arg("theTexture"));
	cls_Graphic3d_ClipPlane.def("CappingTexture", (opencascade::handle<Graphic3d_TextureMap> (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::CappingTexture, "Returns capping texture map.");
	cls_Graphic3d_ClipPlane.def("SetCappingHatch", (void (Graphic3d_ClipPlane::*)(const Aspect_HatchStyle)) &Graphic3d_ClipPlane::SetCappingHatch, "Set hatch style (stipple) and turn hatching on.", py::arg("theStyle"));
	cls_Graphic3d_ClipPlane.def("CappingHatch", (Aspect_HatchStyle (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::CappingHatch, "Returns hatching style.");
	cls_Graphic3d_ClipPlane.def("SetCappingCustomHatch", (void (Graphic3d_ClipPlane::*)(const opencascade::handle<Graphic3d_HatchStyle> &)) &Graphic3d_ClipPlane::SetCappingCustomHatch, "Set custom hatch style (stipple) and turn hatching on.", py::arg("theStyle"));
	cls_Graphic3d_ClipPlane.def("CappingCustomHatch", (const opencascade::handle<Graphic3d_HatchStyle> & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::CappingCustomHatch, "Returns hatching style.");
	cls_Graphic3d_ClipPlane.def("SetCappingHatchOn", (void (Graphic3d_ClipPlane::*)()) &Graphic3d_ClipPlane::SetCappingHatchOn, "Turn on hatching.");
	cls_Graphic3d_ClipPlane.def("SetCappingHatchOff", (void (Graphic3d_ClipPlane::*)()) &Graphic3d_ClipPlane::SetCappingHatchOff, "Turn off hatching.");
	cls_Graphic3d_ClipPlane.def("IsHatchOn", (Standard_Boolean (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::IsHatchOn, "Returns True if hatching mask is turned on.");
	cls_Graphic3d_ClipPlane.def("GetId", (const TCollection_AsciiString & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::GetId, "This ID is used for managing associated resources in graphical driver. The clip plane can be assigned within a range of IO which can be displayed in separate OpenGl contexts. For each of the context an associated OpenGl resource for graphical aspects should be created and kept. The resources are stored in graphical driver for each of individual groups of shared context under the clip plane identifier.");
	cls_Graphic3d_ClipPlane.def("CappingAspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::CappingAspect, "Return capping aspect.");
	cls_Graphic3d_ClipPlane.def("SetCappingAspect", (void (Graphic3d_ClipPlane::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_ClipPlane::SetCappingAspect, "Assign capping aspect.", py::arg("theAspect"));
	cls_Graphic3d_ClipPlane.def("ToUseObjectMaterial", (bool (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::ToUseObjectMaterial, "Flag indicating whether material for capping plane should be taken from object. Default value: FALSE (use dedicated capping plane material).");
	cls_Graphic3d_ClipPlane.def("SetUseObjectMaterial", (void (Graphic3d_ClipPlane::*)(bool)) &Graphic3d_ClipPlane::SetUseObjectMaterial, "Set flag for controlling the source of capping plane material.", py::arg("theToUse"));
	cls_Graphic3d_ClipPlane.def("ToUseObjectTexture", (bool (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::ToUseObjectTexture, "Flag indicating whether texture for capping plane should be taken from object. Default value: FALSE.");
	cls_Graphic3d_ClipPlane.def("SetUseObjectTexture", (void (Graphic3d_ClipPlane::*)(bool)) &Graphic3d_ClipPlane::SetUseObjectTexture, "Set flag for controlling the source of capping plane texture.", py::arg("theToUse"));
	cls_Graphic3d_ClipPlane.def("ToUseObjectShader", (bool (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::ToUseObjectShader, "Flag indicating whether shader program for capping plane should be taken from object. Default value: FALSE.");
	cls_Graphic3d_ClipPlane.def("SetUseObjectShader", (void (Graphic3d_ClipPlane::*)(bool)) &Graphic3d_ClipPlane::SetUseObjectShader, "Set flag for controlling the source of capping plane shader program.", py::arg("theToUse"));
	cls_Graphic3d_ClipPlane.def("ToUseObjectProperties", (bool (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::ToUseObjectProperties, "Return true if some fill area aspect properties should be taken from object.");
	cls_Graphic3d_ClipPlane.def("MCountEquation", (unsigned int (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::MCountEquation, "Returns modification counter for equation.");
	cls_Graphic3d_ClipPlane.def("MCountAspect", (unsigned int (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::MCountAspect, "Returns modification counter for aspect.");
	cls_Graphic3d_ClipPlane.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ClipPlane::get_type_name, "None");
	cls_Graphic3d_ClipPlane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ClipPlane::get_type_descriptor, "None");
	cls_Graphic3d_ClipPlane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ClipPlane::*)() const ) &Graphic3d_ClipPlane::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_SequenceOfHClipPlane.hxx
	py::class_<Graphic3d_SequenceOfHClipPlane, opencascade::handle<Graphic3d_SequenceOfHClipPlane>, Standard_Transient, NCollection_Sequence<opencascade::handle<Graphic3d_ClipPlane> >> cls_Graphic3d_SequenceOfHClipPlane(mod, "Graphic3d_SequenceOfHClipPlane", "Class defining the sequence of clipping planes.");
	cls_Graphic3d_SequenceOfHClipPlane.def(py::init<>());
	cls_Graphic3d_SequenceOfHClipPlane.def_static("get_type_name_", (const char * (*)()) &Graphic3d_SequenceOfHClipPlane::get_type_name, "None");
	cls_Graphic3d_SequenceOfHClipPlane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_SequenceOfHClipPlane::get_type_descriptor, "None");
	cls_Graphic3d_SequenceOfHClipPlane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_SequenceOfHClipPlane::*)() const ) &Graphic3d_SequenceOfHClipPlane::DynamicType, "None");
	cls_Graphic3d_SequenceOfHClipPlane.def("ToOverrideGlobal", (Standard_Boolean (Graphic3d_SequenceOfHClipPlane::*)() const ) &Graphic3d_SequenceOfHClipPlane::ToOverrideGlobal, "Return true if local properties should override global properties.");
	cls_Graphic3d_SequenceOfHClipPlane.def("SetOverrideGlobal", (void (Graphic3d_SequenceOfHClipPlane::*)(const Standard_Boolean)) &Graphic3d_SequenceOfHClipPlane::SetOverrideGlobal, "Setup flag defining if local properties should override global properties.", py::arg("theToOverride"));
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ViewAffinity.hxx
	py::class_<Graphic3d_ViewAffinity, opencascade::handle<Graphic3d_ViewAffinity>, Standard_Transient> cls_Graphic3d_ViewAffinity(mod, "Graphic3d_ViewAffinity", "Structure display state.");
	cls_Graphic3d_ViewAffinity.def(py::init<>());
	cls_Graphic3d_ViewAffinity.def("IsVisible", (bool (Graphic3d_ViewAffinity::*)(const Standard_Integer) const ) &Graphic3d_ViewAffinity::IsVisible, "Return visibility flag.", py::arg("theViewId"));
	cls_Graphic3d_ViewAffinity.def("SetVisible", (void (Graphic3d_ViewAffinity::*)(const Standard_Boolean)) &Graphic3d_ViewAffinity::SetVisible, "Setup visibility flag for all views.", py::arg("theIsVisible"));
	cls_Graphic3d_ViewAffinity.def("SetVisible", (void (Graphic3d_ViewAffinity::*)(const Standard_Integer, const bool)) &Graphic3d_ViewAffinity::SetVisible, "Setup visibility flag.", py::arg("theViewId"), py::arg("theIsVisible"));
	cls_Graphic3d_ViewAffinity.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ViewAffinity::get_type_name, "None");
	cls_Graphic3d_ViewAffinity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ViewAffinity::get_type_descriptor, "None");
	cls_Graphic3d_ViewAffinity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ViewAffinity::*)() const ) &Graphic3d_ViewAffinity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TransformPers.hxx
	py::class_<Graphic3d_TransformPers, opencascade::handle<Graphic3d_TransformPers>, Standard_Transient> cls_Graphic3d_TransformPers(mod, "Graphic3d_TransformPers", "Class for keeping and computing transformation persistence. Note that instance of this class can not define no transformation persistence Graphic3d_TMF_None - NULL handle should be used for this purpose.");
	cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags>(), py::arg("theMode"));
	cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags, const gp_Pnt &>(), py::arg("theMode"), py::arg("thePnt"));
	cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags, const Aspect_TypeOfTriedronPosition>(), py::arg("theMode"), py::arg("theCorner"));
	cls_Graphic3d_TransformPers.def(py::init<const Graphic3d_TransModeFlags, const Aspect_TypeOfTriedronPosition, const Graphic3d_Vec2i &>(), py::arg("theMode"), py::arg("theCorner"), py::arg("theOffset"));
	cls_Graphic3d_TransformPers.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TransformPers::get_type_name, "None");
	cls_Graphic3d_TransformPers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TransformPers::get_type_descriptor, "None");
	cls_Graphic3d_TransformPers.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::DynamicType, "None");
	cls_Graphic3d_TransformPers.def_static("IsZoomOrRotate_", (Standard_Boolean (*)(Graphic3d_TransModeFlags)) &Graphic3d_TransformPers::IsZoomOrRotate, "Return true if specified mode is zoom/rotate transformation persistence.", py::arg("theMode"));
	cls_Graphic3d_TransformPers.def_static("IsTrihedronOr2d_", (Standard_Boolean (*)(Graphic3d_TransModeFlags)) &Graphic3d_TransformPers::IsTrihedronOr2d, "Return true if specified mode is 2d/trihedron transformation persistence.", py::arg("theMode"));
	cls_Graphic3d_TransformPers.def_static("FromDeprecatedParams_", (opencascade::handle<Graphic3d_TransformPers> (*)(Graphic3d_TransModeFlags, const gp_Pnt &)) &Graphic3d_TransformPers::FromDeprecatedParams, "Create Graphic3d_TransformPers instance from deprecated parameters set decoding 2D corner + offset parameters from 3D point.", py::arg("theFlag"), py::arg("thePoint"));
	cls_Graphic3d_TransformPers.def("IsZoomOrRotate", (Standard_Boolean (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::IsZoomOrRotate, "Return true for Graphic3d_TMF_ZoomPers, Graphic3d_TMF_ZoomRotatePers or Graphic3d_TMF_RotatePers modes.");
	cls_Graphic3d_TransformPers.def("IsTrihedronOr2d", (Standard_Boolean (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::IsTrihedronOr2d, "Return true for Graphic3d_TMF_TriedronPers and Graphic3d_TMF_2d modes.");
	cls_Graphic3d_TransformPers.def("Mode", (Graphic3d_TransModeFlags (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::Mode, "Transformation persistence mode flags.");
	cls_Graphic3d_TransformPers.def("Flags", (Graphic3d_TransModeFlags (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::Flags, "Transformation persistence mode flags.");
	cls_Graphic3d_TransformPers.def("SetPersistence", (void (Graphic3d_TransformPers::*)(const Graphic3d_TransModeFlags, const gp_Pnt &)) &Graphic3d_TransformPers::SetPersistence, "Set Zoom/Rotate transformation persistence with an anchor 3D point. Throws an exception if persistence mode is not Graphic3d_TMF_ZoomPers, Graphic3d_TMF_ZoomRotatePers or Graphic3d_TMF_RotatePers.", py::arg("theMode"), py::arg("thePnt"));
	cls_Graphic3d_TransformPers.def("SetPersistence", (void (Graphic3d_TransformPers::*)(const Graphic3d_TransModeFlags, const Aspect_TypeOfTriedronPosition, const Graphic3d_Vec2i &)) &Graphic3d_TransformPers::SetPersistence, "Set 2d/trihedron transformation persistence with a corner and 2D offset. Throws an exception if persistence mode is not Graphic3d_TMF_TriedronPers or Graphic3d_TMF_2d.", py::arg("theMode"), py::arg("theCorner"), py::arg("theOffset"));
	cls_Graphic3d_TransformPers.def("AnchorPoint", (gp_Pnt (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::AnchorPoint, "Return the anchor point for zoom/rotate transformation persistence.");
	cls_Graphic3d_TransformPers.def("SetAnchorPoint", (void (Graphic3d_TransformPers::*)(const gp_Pnt &)) &Graphic3d_TransformPers::SetAnchorPoint, "Set the anchor point for zoom/rotate transformation persistence.", py::arg("thePnt"));
	cls_Graphic3d_TransformPers.def("Corner2d", (Aspect_TypeOfTriedronPosition (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::Corner2d, "Return the corner for 2d/trihedron transformation persistence.");
	cls_Graphic3d_TransformPers.def("SetCorner2d", (void (Graphic3d_TransformPers::*)(const Aspect_TypeOfTriedronPosition)) &Graphic3d_TransformPers::SetCorner2d, "Set the corner for 2d/trihedron transformation persistence.", py::arg("thePos"));
	cls_Graphic3d_TransformPers.def("Offset2d", (Graphic3d_Vec2i (Graphic3d_TransformPers::*)() const ) &Graphic3d_TransformPers::Offset2d, "Return the offset from the corner for 2d/trihedron transformation persistence.");
	cls_Graphic3d_TransformPers.def("SetOffset2d", (void (Graphic3d_TransformPers::*)(const Graphic3d_Vec2i &)) &Graphic3d_TransformPers::SetOffset2d, "Set the offset from the corner for 2d/trihedron transformation persistence.", py::arg("theOffset"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_GraphicDriver.hxx
	py::class_<Graphic3d_GraphicDriver, opencascade::handle<Graphic3d_GraphicDriver>, Standard_Transient> cls_Graphic3d_GraphicDriver(mod, "Graphic3d_GraphicDriver", "This class allows the definition of a graphic driver for 3d interface (currently only OpenGl driver is used).");
	cls_Graphic3d_GraphicDriver.def("InquireLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)(const Graphic3d_TypeOfLimit) const ) &Graphic3d_GraphicDriver::InquireLimit, "Request limit of graphic resource of specific type.", py::arg("theType"));
	cls_Graphic3d_GraphicDriver.def("InquireLightLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)() const ) &Graphic3d_GraphicDriver::InquireLightLimit, "Request maximum number of active light sources supported by driver and hardware.");
	cls_Graphic3d_GraphicDriver.def("InquirePlaneLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)() const ) &Graphic3d_GraphicDriver::InquirePlaneLimit, "Request maximum number of active clipping planes supported by driver and hardware.");
	cls_Graphic3d_GraphicDriver.def("InquireViewLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)() const ) &Graphic3d_GraphicDriver::InquireViewLimit, "Request maximum number of views supported by driver.");
	cls_Graphic3d_GraphicDriver.def("CreateStructure", (opencascade::handle<Graphic3d_CStructure> (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &Graphic3d_GraphicDriver::CreateStructure, "Creates new empty graphic structure", py::arg("theManager"));
	cls_Graphic3d_GraphicDriver.def("RemoveStructure", (void (Graphic3d_GraphicDriver::*)(opencascade::handle<Graphic3d_CStructure> &)) &Graphic3d_GraphicDriver::RemoveStructure, "Removes structure from graphic driver and releases its resources.", py::arg("theCStructure"));
	cls_Graphic3d_GraphicDriver.def("CreateView", (opencascade::handle<Graphic3d_CView> (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &Graphic3d_GraphicDriver::CreateView, "Creates new view for this graphic driver.", py::arg("theMgr"));
	cls_Graphic3d_GraphicDriver.def("RemoveView", (void (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &)) &Graphic3d_GraphicDriver::RemoveView, "Removes view from graphic driver and releases its resources.", py::arg("theView"));
	cls_Graphic3d_GraphicDriver.def("EnableVBO", (void (Graphic3d_GraphicDriver::*)(const Standard_Boolean)) &Graphic3d_GraphicDriver::EnableVBO, "enables/disables usage of OpenGL vertex buffer arrays while drawing primitiev arrays", py::arg("status"));
	cls_Graphic3d_GraphicDriver.def("MemoryInfo", (Standard_Boolean (Graphic3d_GraphicDriver::*)(Standard_Size &, TCollection_AsciiString &) const ) &Graphic3d_GraphicDriver::MemoryInfo, "Returns information about GPU memory usage.", py::arg("theFreeBytes"), py::arg("theInfo"));
	cls_Graphic3d_GraphicDriver.def("DefaultTextHeight", (Standard_ShortReal (Graphic3d_GraphicDriver::*)() const ) &Graphic3d_GraphicDriver::DefaultTextHeight, "None");
	cls_Graphic3d_GraphicDriver.def("TextSize", (void (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &, const Standard_CString, const Standard_ShortReal, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const ) &Graphic3d_GraphicDriver::TextSize, "Computes text width.", py::arg("theView"), py::arg("theText"), py::arg("theHeight"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
	cls_Graphic3d_GraphicDriver.def("AddZLayer", (void (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId)) &Graphic3d_GraphicDriver::AddZLayer, "Add a new top-level z layer with ID <theLayerId> for the view. Z layers allow drawing structures in higher layers in foreground of structures in lower layers. To add a structure to desired layer on display it is necessary to set the layer ID for the structure.", py::arg("theLayerId"));
	cls_Graphic3d_GraphicDriver.def("RemoveZLayer", (void (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId)) &Graphic3d_GraphicDriver::RemoveZLayer, "Removes Z layer. All structures displayed at the moment in layer will be displayed in default layer (the bottom-level z layer). By default, there are always default bottom-level layer that can't be removed. The passed theLayerId should be not less than 0 (reserved for default layers that can not be removed).", py::arg("theLayerId"));
	cls_Graphic3d_GraphicDriver.def("ZLayers", (void (Graphic3d_GraphicDriver::*)(TColStd_SequenceOfInteger &) const ) &Graphic3d_GraphicDriver::ZLayers, "Returns list of Z layers defined for the graphical driver.", py::arg("theLayerSeq"));
	cls_Graphic3d_GraphicDriver.def("SetZLayerSettings", (void (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &Graphic3d_GraphicDriver::SetZLayerSettings, "Sets the settings for a single Z layer.", py::arg("theLayerId"), py::arg("theSettings"));
	cls_Graphic3d_GraphicDriver.def("ZLayerSettings", (const Graphic3d_ZLayerSettings & (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId) const ) &Graphic3d_GraphicDriver::ZLayerSettings, "Returns the settings of a single Z layer.", py::arg("theLayerId"));
	cls_Graphic3d_GraphicDriver.def("ViewExists", (Standard_Boolean (Graphic3d_GraphicDriver::*)(const opencascade::handle<Aspect_Window> &, opencascade::handle<Graphic3d_CView> &)) &Graphic3d_GraphicDriver::ViewExists, "Returns view associated with the window if it is exists and is activated. Returns Standard_True if the view associated to the window exists.", py::arg("theWindow"), py::arg("theView"));
	cls_Graphic3d_GraphicDriver.def("GetDisplayConnection", (const opencascade::handle<Aspect_DisplayConnection> & (Graphic3d_GraphicDriver::*)() const ) &Graphic3d_GraphicDriver::GetDisplayConnection, "returns Handle to display connection");
	cls_Graphic3d_GraphicDriver.def("NewIdentification", (Standard_Integer (Graphic3d_GraphicDriver::*)()) &Graphic3d_GraphicDriver::NewIdentification, "Returns a new identification number for a new structure.");
	cls_Graphic3d_GraphicDriver.def("RemoveIdentification", (void (Graphic3d_GraphicDriver::*)(const Standard_Integer)) &Graphic3d_GraphicDriver::RemoveIdentification, "Frees the identifier of a structure.", py::arg("theId"));
	cls_Graphic3d_GraphicDriver.def_static("get_type_name_", (const char * (*)()) &Graphic3d_GraphicDriver::get_type_name, "None");
	cls_Graphic3d_GraphicDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_GraphicDriver::get_type_descriptor, "None");
	cls_Graphic3d_GraphicDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_GraphicDriver::*)() const ) &Graphic3d_GraphicDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_StructureManager.hxx
	py::class_<Graphic3d_StructureManager, opencascade::handle<Graphic3d_StructureManager>, Standard_Transient> cls_Graphic3d_StructureManager(mod, "Graphic3d_StructureManager", "This class allows the definition of a manager to which the graphic objects are associated. It allows them to be globally manipulated. It defines the global attributes. Keywords: Structure, Structure Manager, Update Mode, Destroy, Highlight, Visible");
	cls_Graphic3d_StructureManager.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &>(), py::arg("theDriver"));
	cls_Graphic3d_StructureManager.def_static("get_type_name_", (const char * (*)()) &Graphic3d_StructureManager::get_type_name, "None");
	cls_Graphic3d_StructureManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_StructureManager::get_type_descriptor, "None");
	cls_Graphic3d_StructureManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_StructureManager::*)() const ) &Graphic3d_StructureManager::DynamicType, "None");
	cls_Graphic3d_StructureManager.def("Update", [](Graphic3d_StructureManager &self) -> void { return self.Update(); });
	cls_Graphic3d_StructureManager.def("Update", (void (Graphic3d_StructureManager::*)(const Graphic3d_ZLayerId) const ) &Graphic3d_StructureManager::Update, "Invalidates bounding box of specified ZLayerId.", py::arg("theLayerId"));
	cls_Graphic3d_StructureManager.def("Remove", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::Remove, "Deletes and erases the 3D structure manager.");
	cls_Graphic3d_StructureManager.def("Erase", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::Erase, "Erases all the structures.");
	cls_Graphic3d_StructureManager.def("DisplayedStructures", (void (Graphic3d_StructureManager::*)(Graphic3d_MapOfStructure &) const ) &Graphic3d_StructureManager::DisplayedStructures, "Returns the set of structures displayed in visualiser <me>.", py::arg("SG"));
	cls_Graphic3d_StructureManager.def("HighlightedStructures", (void (Graphic3d_StructureManager::*)(Graphic3d_MapOfStructure &) const ) &Graphic3d_StructureManager::HighlightedStructures, "Returns the set of highlighted structures in a visualiser <me>.", py::arg("SG"));
	cls_Graphic3d_StructureManager.def("ReCompute", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::ReCompute, "Forces a new construction of the structure. if <theStructure> is displayed and TOS_COMPUTED.", py::arg("theStructure"));
	cls_Graphic3d_StructureManager.def("ReCompute", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_DataStructureManager> &)) &Graphic3d_StructureManager::ReCompute, "Forces a new construction of the structure. if <theStructure> is displayed in <theProjector> and TOS_COMPUTED.", py::arg("theStructure"), py::arg("theProjector"));
	cls_Graphic3d_StructureManager.def("Clear", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const Standard_Boolean)) &Graphic3d_StructureManager::Clear, "Clears the structure.", py::arg("theStructure"), py::arg("theWithDestruction"));
	cls_Graphic3d_StructureManager.def("Connect", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Connect, "Connects the structures.", py::arg("theMother"), py::arg("theDaughter"));
	cls_Graphic3d_StructureManager.def("Disconnect", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Disconnect, "Disconnects the structures.", py::arg("theMother"), py::arg("theDaughter"));
	cls_Graphic3d_StructureManager.def("Display", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Display, "Display the structure.", py::arg("theStructure"));
	cls_Graphic3d_StructureManager.def("Erase", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Erase, "Erases the structure.", py::arg("theStructure"));
	cls_Graphic3d_StructureManager.def("Highlight", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::Highlight, "Highlights the structure.", py::arg("theStructure"));
	cls_Graphic3d_StructureManager.def("SetTransform", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const opencascade::handle<Geom_Transformation> &)) &Graphic3d_StructureManager::SetTransform, "Transforms the structure.", py::arg("theStructure"), py::arg("theTrsf"));
	cls_Graphic3d_StructureManager.def("ChangeDisplayPriority", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const Standard_Integer, const Standard_Integer)) &Graphic3d_StructureManager::ChangeDisplayPriority, "Changes the display priority of the structure <AStructure>.", py::arg("theStructure"), py::arg("theOldPriority"), py::arg("theNewPriority"));
	cls_Graphic3d_StructureManager.def("ChangeZLayer", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &, const Graphic3d_ZLayerId)) &Graphic3d_StructureManager::ChangeZLayer, "Change Z layer for structure. The Z layer mechanism allows to display structures in higher layers in overlay of structures in lower layers.", py::arg("theStructure"), py::arg("theLayerId"));
	cls_Graphic3d_StructureManager.def("GraphicDriver", (const opencascade::handle<Graphic3d_GraphicDriver> & (Graphic3d_StructureManager::*)() const ) &Graphic3d_StructureManager::GraphicDriver, "Returns the graphic driver of <me>.");
	cls_Graphic3d_StructureManager.def("Identification", (Standard_Integer (Graphic3d_StructureManager::*)(Graphic3d_CView *)) &Graphic3d_StructureManager::Identification, "Attaches the view to this structure manager and sets its identification number within the manager.", py::arg("theView"));
	cls_Graphic3d_StructureManager.def("UnIdentification", (void (Graphic3d_StructureManager::*)(Graphic3d_CView *)) &Graphic3d_StructureManager::UnIdentification, "Detach the view from this structure manager and release its identification.", py::arg("theView"));
	cls_Graphic3d_StructureManager.def("DefinedViews", (const Graphic3d_IndexedMapOfView & (Graphic3d_StructureManager::*)() const ) &Graphic3d_StructureManager::DefinedViews, "Returns the group of views defined in the structure manager.");
	cls_Graphic3d_StructureManager.def("MaxNumOfViews", (Standard_Integer (Graphic3d_StructureManager::*)() const ) &Graphic3d_StructureManager::MaxNumOfViews, "Returns the theoretical maximum number of definable views in the manager. Warning: It's not possible to accept an infinite number of definable views because each view must have an identification and we have different managers.");
	cls_Graphic3d_StructureManager.def("Identification", (opencascade::handle<Graphic3d_Structure> (Graphic3d_StructureManager::*)(const Standard_Integer) const ) &Graphic3d_StructureManager::Identification, "Returns the structure with the identification number <AId>.", py::arg("AId"));
	cls_Graphic3d_StructureManager.def("UnHighlight", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_StructureManager::UnHighlight, "Suppress the highlighting on the structure <AStructure>.", py::arg("AStructure"));
	cls_Graphic3d_StructureManager.def("UnHighlight", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::UnHighlight, "Suppresses the highlighting on all the structures in <me>.");
	cls_Graphic3d_StructureManager.def("RecomputeStructures", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::RecomputeStructures, "Recomputes all structures in the manager. Resets Device Lost flag.");
	cls_Graphic3d_StructureManager.def("RecomputeStructures", (void (Graphic3d_StructureManager::*)(const Graphic3d_MapOfStructure &)) &Graphic3d_StructureManager::RecomputeStructures, "Recomputes all structures from theStructures.", py::arg("theStructures"));
	cls_Graphic3d_StructureManager.def("RegisterObject", (opencascade::handle<Graphic3d_ViewAffinity> (Graphic3d_StructureManager::*)(const opencascade::handle<Standard_Transient> &)) &Graphic3d_StructureManager::RegisterObject, "None", py::arg("theObject"));
	cls_Graphic3d_StructureManager.def("UnregisterObject", (void (Graphic3d_StructureManager::*)(const opencascade::handle<Standard_Transient> &)) &Graphic3d_StructureManager::UnregisterObject, "None", py::arg("theObject"));
	cls_Graphic3d_StructureManager.def("ObjectAffinity", (opencascade::handle<Graphic3d_ViewAffinity> (Graphic3d_StructureManager::*)(const opencascade::handle<Standard_Transient> &) const ) &Graphic3d_StructureManager::ObjectAffinity, "None", py::arg("theObject"));
	cls_Graphic3d_StructureManager.def("IsDeviceLost", (Standard_Boolean (Graphic3d_StructureManager::*)() const ) &Graphic3d_StructureManager::IsDeviceLost, "Returns TRUE if Device Lost flag has been set and presentation data should be reuploaded onto graphics driver.");
	cls_Graphic3d_StructureManager.def("SetDeviceLost", (void (Graphic3d_StructureManager::*)()) &Graphic3d_StructureManager::SetDeviceLost, "Sets Device Lost flag.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CStructure.hxx
	py::class_<Graphic3d_CStructure, opencascade::handle<Graphic3d_CStructure>, Standard_Transient> cls_Graphic3d_CStructure(mod, "Graphic3d_CStructure", "Low-level graphic structure interface");
	cls_Graphic3d_CStructure.def("GraphicDriver", (const opencascade::handle<Graphic3d_GraphicDriver> & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::GraphicDriver, "Returns graphic driver created this structure");
	cls_Graphic3d_CStructure.def("Groups", (const Graphic3d_SequenceOfGroup & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::Groups, "Returns graphic groups");
	cls_Graphic3d_CStructure.def("Transformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::Transformation, "Return transformation.");
	cls_Graphic3d_CStructure.def("SetTransformation", (void (Graphic3d_CStructure::*)(const opencascade::handle<Geom_Transformation> &)) &Graphic3d_CStructure::SetTransformation, "Assign transformation.", py::arg("theTrsf"));
	cls_Graphic3d_CStructure.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::TransformPersistence, "Return transformation persistence.");
	cls_Graphic3d_CStructure.def("SetTransformPersistence", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &Graphic3d_CStructure::SetTransformPersistence, "Set transformation persistence.", py::arg("theTrsfPers"));
	cls_Graphic3d_CStructure.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::ClipPlanes, "Returns associated clip planes");
	cls_Graphic3d_CStructure.def("SetClipPlanes", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_CStructure::SetClipPlanes, "Pass clip planes to the associated graphic driver structure", py::arg("thePlanes"));
	cls_Graphic3d_CStructure.def("BoundingBox", (const Graphic3d_BndBox3d & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::BoundingBox, "Returns bounding box of this presentation");
	cls_Graphic3d_CStructure.def("ChangeBoundingBox", (Graphic3d_BndBox3d & (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::ChangeBoundingBox, "Returns bounding box of this presentation without transformation matrix applied");
	cls_Graphic3d_CStructure.def("IsVisible", (bool (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::IsVisible, "Return structure visibility flag");
	cls_Graphic3d_CStructure.def("IsVisible", (bool (Graphic3d_CStructure::*)(const Standard_Integer) const ) &Graphic3d_CStructure::IsVisible, "Return structure visibility considering both View Affinity and global visibility state.", py::arg("theViewId"));
	cls_Graphic3d_CStructure.def("SetZLayer", (void (Graphic3d_CStructure::*)(const Graphic3d_ZLayerId)) &Graphic3d_CStructure::SetZLayer, "Set z layer ID to display the structure in specified layer", py::arg("theLayerIndex"));
	cls_Graphic3d_CStructure.def("ZLayer", (Graphic3d_ZLayerId (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::ZLayer, "Get z layer ID");
	cls_Graphic3d_CStructure.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::HighlightStyle, "Returns valid handle to highlight style of the structure in case if highlight flag is set to true");
	cls_Graphic3d_CStructure.def("OnVisibilityChanged", (void (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::OnVisibilityChanged, "Update structure visibility state");
	cls_Graphic3d_CStructure.def("Clear", (void (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::Clear, "Clear graphic data");
	cls_Graphic3d_CStructure.def("Connect", (void (Graphic3d_CStructure::*)(Graphic3d_CStructure &)) &Graphic3d_CStructure::Connect, "Connect other structure to this one", py::arg("theStructure"));
	cls_Graphic3d_CStructure.def("Disconnect", (void (Graphic3d_CStructure::*)(Graphic3d_CStructure &)) &Graphic3d_CStructure::Disconnect, "Disconnect other structure to this one", py::arg("theStructure"));
	cls_Graphic3d_CStructure.def("GraphicHighlight", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &, const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_CStructure::GraphicHighlight, "Highlights structure with the given style", py::arg("theStyle"), py::arg("theStruct"));
	cls_Graphic3d_CStructure.def("GraphicUnhighlight", (void (Graphic3d_CStructure::*)()) &Graphic3d_CStructure::GraphicUnhighlight, "Unhighlights the structure and invalidates pointer to structure's highlight style");
	cls_Graphic3d_CStructure.def("ShadowLink", (opencascade::handle<Graphic3d_CStructure> (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_StructureManager> &) const ) &Graphic3d_CStructure::ShadowLink, "Create shadow link to this structure", py::arg("theManager"));
	cls_Graphic3d_CStructure.def("NewGroup", (opencascade::handle<Graphic3d_Group> (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_CStructure::NewGroup, "Create new group within this structure", py::arg("theStruct"));
	cls_Graphic3d_CStructure.def("RemoveGroup", (void (Graphic3d_CStructure::*)(const opencascade::handle<Graphic3d_Group> &)) &Graphic3d_CStructure::RemoveGroup, "Remove group from this structure", py::arg("theGroup"));
	cls_Graphic3d_CStructure.def_static("get_type_name_", (const char * (*)()) &Graphic3d_CStructure::get_type_name, "None");
	cls_Graphic3d_CStructure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_CStructure::get_type_descriptor, "None");
	cls_Graphic3d_CStructure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_CStructure::*)() const ) &Graphic3d_CStructure::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_DataStructureManager.hxx
	py::class_<Graphic3d_DataStructureManager, opencascade::handle<Graphic3d_DataStructureManager>, Standard_Transient> cls_Graphic3d_DataStructureManager(mod, "Graphic3d_DataStructureManager", "This class allows the definition of a manager to which the graphic objects are associated. It allows them to be globally manipulated. It defines the global attributes.");
	cls_Graphic3d_DataStructureManager.def_static("get_type_name_", (const char * (*)()) &Graphic3d_DataStructureManager::get_type_name, "None");
	cls_Graphic3d_DataStructureManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_DataStructureManager::get_type_descriptor, "None");
	cls_Graphic3d_DataStructureManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_DataStructureManager::*)() const ) &Graphic3d_DataStructureManager::DynamicType, "None");

	// Callback for Graphic3d_CView.
	class PyCallback_Graphic3d_CView : public Graphic3d_CView {
	public:
		using Graphic3d_CView::Graphic3d_CView;

		void Redraw() override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, Redraw, ); }
		void RedrawImmediate() override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, RedrawImmediate, ); }
		void Invalidate() override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, Invalidate, ); }
		Standard_Boolean IsInvalidated() override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Graphic3d_CView, IsInvalidated, ); }
		void Resized() override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, Resized, ); }
		Standard_Boolean SetImmediateModeDrawToFront(const Standard_Boolean theDrawToFrontBuffer) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Graphic3d_CView, SetImmediateModeDrawToFront, theDrawToFrontBuffer); }
		void SetWindow(const opencascade::handle<Aspect_Window> & theWindow, const Aspect_RenderingContext theContext) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetWindow, theWindow, theContext); }
		opencascade::handle<Aspect_Window> Window() const  override { PYBIND11_OVERLOAD_PURE(opencascade::handle<Aspect_Window>, Graphic3d_CView, Window, ); }
		Standard_Boolean IsDefined() const  override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Graphic3d_CView, IsDefined, ); }
		const Graphic3d_GraduatedTrihedron & GetGraduatedTrihedron() override { PYBIND11_OVERLOAD_PURE(const Graphic3d_GraduatedTrihedron &, Graphic3d_CView, GetGraduatedTrihedron, ); }
		void GraduatedTrihedronDisplay(const Graphic3d_GraduatedTrihedron & theTrihedronData) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, GraduatedTrihedronDisplay, theTrihedronData); }
		void GraduatedTrihedronErase() override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, GraduatedTrihedronErase, ); }
		void GraduatedTrihedronMinMaxValues(const Graphic3d_Vec3 theMin, const Graphic3d_Vec3 theMax) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, GraduatedTrihedronMinMaxValues, theMin, theMax); }
		Standard_Boolean BufferDump(Image_PixMap & theImage, const Graphic3d_BufferType & theBufferType) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Graphic3d_CView, BufferDump, theImage, theBufferType); }
		Standard_Boolean Export(const Standard_CString theFileName, const Graphic3d_ExportFormat theFormat, const Graphic3d_SortType theSortType) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Graphic3d_CView, Export, theFileName, theFormat, theSortType); }
		void InvalidateBVHData(const Standard_Integer theLayerId) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, InvalidateBVHData, theLayerId); }
		void AddZLayer(const Graphic3d_ZLayerId theLayerId) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, AddZLayer, theLayerId); }
		Standard_Integer ZLayerMax() const  override { PYBIND11_OVERLOAD_PURE(Standard_Integer, Graphic3d_CView, ZLayerMax, ); }
		void InvalidateZLayerBoundingBox(const Graphic3d_ZLayerId theLayerId) const  override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, InvalidateZLayerBoundingBox, theLayerId); }
		Bnd_Box ZLayerBoundingBox(const Graphic3d_ZLayerId theLayerId, const opencascade::handle<Graphic3d_Camera> & theCamera, const Standard_Integer theWindowWidth, const Standard_Integer theWindowHeight, const Standard_Boolean theToIncludeAuxiliary) const  override { PYBIND11_OVERLOAD_PURE(Bnd_Box, Graphic3d_CView, ZLayerBoundingBox, theLayerId, theCamera, theWindowWidth, theWindowHeight, theToIncludeAuxiliary); }
		void RemoveZLayer(const Graphic3d_ZLayerId theLayerId) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, RemoveZLayer, theLayerId); }
		void SetZLayerSettings(const Graphic3d_ZLayerId theLayerId, const Graphic3d_ZLayerSettings & theSettings) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetZLayerSettings, theLayerId, theSettings); }
		opencascade::handle<Standard_Transient> FBO() const  override { PYBIND11_OVERLOAD_PURE(opencascade::handle<Standard_Transient>, Graphic3d_CView, FBO, ); }
		void SetFBO(const opencascade::handle<Standard_Transient> & theFbo) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetFBO, theFbo); }
		opencascade::handle<Standard_Transient> FBOCreate(const Standard_Integer theWidth, const Standard_Integer theHeight) override { PYBIND11_OVERLOAD_PURE(opencascade::handle<Standard_Transient>, Graphic3d_CView, FBOCreate, theWidth, theHeight); }
		void FBORelease(opencascade::handle<Standard_Transient> & theFbo) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, FBORelease, theFbo); }
		void FBOGetDimensions(const opencascade::handle<Standard_Transient> & theFbo, Standard_Integer & theWidth, Standard_Integer & theHeight, Standard_Integer & theWidthMax, Standard_Integer & theHeightMax) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, FBOGetDimensions, theFbo, theWidth, theHeight, theWidthMax, theHeightMax); }
		void FBOChangeViewport(const opencascade::handle<Standard_Transient> & theFbo, const Standard_Integer theWidth, const Standard_Integer theHeight) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, FBOChangeViewport, theFbo, theWidth, theHeight); }
		Aspect_Background Background() const  override { PYBIND11_OVERLOAD_PURE(Aspect_Background, Graphic3d_CView, Background, ); }
		void SetBackground(const Aspect_Background & theBackground) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetBackground, theBackground); }
		Aspect_GradientBackground GradientBackground() const  override { PYBIND11_OVERLOAD_PURE(Aspect_GradientBackground, Graphic3d_CView, GradientBackground, ); }
		void SetGradientBackground(const Aspect_GradientBackground & theBackground) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetGradientBackground, theBackground); }
		TCollection_AsciiString BackgroundImage() override { PYBIND11_OVERLOAD_PURE(TCollection_AsciiString, Graphic3d_CView, BackgroundImage, ); }
		void SetBackgroundImage(const TCollection_AsciiString & theFilePath) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetBackgroundImage, theFilePath); }
		Aspect_FillMethod BackgroundImageStyle() const  override { PYBIND11_OVERLOAD_PURE(Aspect_FillMethod, Graphic3d_CView, BackgroundImageStyle, ); }
		void SetBackgroundImageStyle(const Aspect_FillMethod theFillStyle) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetBackgroundImageStyle, theFillStyle); }
		opencascade::handle<Graphic3d_TextureEnv> TextureEnv() const  override { PYBIND11_OVERLOAD_PURE(opencascade::handle<Graphic3d_TextureEnv>, Graphic3d_CView, TextureEnv, ); }
		void SetTextureEnv(const opencascade::handle<Graphic3d_TextureEnv> & theTextureEnv) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetTextureEnv, theTextureEnv); }
		Standard_Boolean IsCullingEnabled() const  override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Graphic3d_CView, IsCullingEnabled, ); }
		void SetCullingEnabled(const Standard_Boolean theIsEnabled) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetCullingEnabled, theIsEnabled); }
		Graphic3d_TypeOfShadingModel ShadingModel() const  override { PYBIND11_OVERLOAD_PURE(Graphic3d_TypeOfShadingModel, Graphic3d_CView, ShadingModel, ); }
		void SetShadingModel(const Graphic3d_TypeOfShadingModel theModel) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetShadingModel, theModel); }
		Graphic3d_TypeOfBackfacingModel BackfacingModel() const  override { PYBIND11_OVERLOAD_PURE(Graphic3d_TypeOfBackfacingModel, Graphic3d_CView, BackfacingModel, ); }
		void SetBackfacingModel(const Graphic3d_TypeOfBackfacingModel theModel) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetBackfacingModel, theModel); }
		const opencascade::handle<Graphic3d_Camera> & Camera() const  override { PYBIND11_OVERLOAD_PURE(const opencascade::handle<Graphic3d_Camera> &, Graphic3d_CView, Camera, ); }
		void SetCamera(const opencascade::handle<Graphic3d_Camera> & theCamera) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetCamera, theCamera); }
		const Graphic3d_ListOfCLight & Lights() const  override { PYBIND11_OVERLOAD_PURE(const Graphic3d_ListOfCLight &, Graphic3d_CView, Lights, ); }
		void SetLights(const Graphic3d_ListOfCLight & theLights) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetLights, theLights); }
		const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & ClipPlanes() const  override { PYBIND11_OVERLOAD_PURE(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &, Graphic3d_CView, ClipPlanes, ); }
		void SetClipPlanes(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & thePlanes) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, SetClipPlanes, thePlanes); }
		void DiagnosticInformation(TColStd_IndexedDataMapOfStringString & theDict, Graphic3d_DiagnosticInfo theFlags) const  override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, DiagnosticInformation, theDict, theFlags); }
		void displayStructure(const opencascade::handle<Graphic3d_CStructure> & theStructure, const Standard_Integer thePriority) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, displayStructure, theStructure, thePriority); }
		void eraseStructure(const opencascade::handle<Graphic3d_CStructure> & theStructure) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, eraseStructure, theStructure); }
		void changeZLayer(const opencascade::handle<Graphic3d_CStructure> & theCStructure, const Graphic3d_ZLayerId theNewLayerId) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, changeZLayer, theCStructure, theNewLayerId); }
		void changePriority(const opencascade::handle<Graphic3d_CStructure> & theCStructure, const Standard_Integer theNewPriority) override { PYBIND11_OVERLOAD_PURE(void, Graphic3d_CView, changePriority, theCStructure, theNewPriority); }
		Standard_Real considerZoomPersistenceObjects(const Graphic3d_ZLayerId theLayerId, const opencascade::handle<Graphic3d_Camera> & theCamera, const Standard_Integer theWindowWidth, const Standard_Integer theWindowHeight) const  override { PYBIND11_OVERLOAD_PURE(Standard_Real, Graphic3d_CView, considerZoomPersistenceObjects, theLayerId, theCamera, theWindowWidth, theWindowHeight); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CView.hxx
	py::class_<Graphic3d_CView, opencascade::handle<Graphic3d_CView>, PyCallback_Graphic3d_CView, Graphic3d_DataStructureManager> cls_Graphic3d_CView(mod, "Graphic3d_CView", "Base class of a graphical view that carries out rendering process for a concrete implementation of graphical driver. Provides virtual interfaces for redrawing its contents, management of displayed structures and render settings. The source code of the class itself implements functionality related to management of computed (HLR or 'view-dependent') structures.");
	cls_Graphic3d_CView.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theMgr"));
	cls_Graphic3d_CView.def("Identification", (Standard_Integer (Graphic3d_CView::*)() const ) &Graphic3d_CView::Identification, "Returns the identification number of the view.");
	cls_Graphic3d_CView.def("Activate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Activate, "Activates the view. Maps presentations defined within structure manager onto this view.");
	cls_Graphic3d_CView.def("Deactivate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Deactivate, "Deactivates the view. Unmaps presentations defined within structure manager. The view in deactivated state will ignore actions on structures such as Display().");
	cls_Graphic3d_CView.def("IsActive", (Standard_Boolean (Graphic3d_CView::*)() const ) &Graphic3d_CView::IsActive, "Returns the activity flag of the view.");
	cls_Graphic3d_CView.def("Remove", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Remove, "Erases the view and removes from graphic driver. No more graphic operations are allowed in this view after the call.");
	cls_Graphic3d_CView.def("IsRemoved", (Standard_Boolean (Graphic3d_CView::*)() const ) &Graphic3d_CView::IsRemoved, "Returns true if the view was removed.");
	cls_Graphic3d_CView.def("VisualizationType", (Graphic3d_TypeOfVisualization (Graphic3d_CView::*)() const ) &Graphic3d_CView::VisualizationType, "Returns visualization type of the view.");
	cls_Graphic3d_CView.def("SetVisualizationType", (void (Graphic3d_CView::*)(const Graphic3d_TypeOfVisualization)) &Graphic3d_CView::SetVisualizationType, "Sets visualization type of the view.", py::arg("theType"));
	cls_Graphic3d_CView.def("SetComputedMode", (void (Graphic3d_CView::*)(const Standard_Boolean)) &Graphic3d_CView::SetComputedMode, "Switches computed HLR mode in the view", py::arg("theMode"));
	cls_Graphic3d_CView.def("ComputedMode", (Standard_Boolean (Graphic3d_CView::*)() const ) &Graphic3d_CView::ComputedMode, "Returns the computed HLR mode state");
	cls_Graphic3d_CView.def("ReCompute", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_CView::ReCompute, "Computes the new presentation of the structure displayed in this view with the type Graphic3d_TOS_COMPUTED.", py::arg("theStructure"));
	cls_Graphic3d_CView.def("Update", [](Graphic3d_CView &self) -> void { return self.Update(); });
	cls_Graphic3d_CView.def("Update", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::Update, "Invalidates bounding box of specified ZLayerId.", py::arg("theLayerId"));
	cls_Graphic3d_CView.def("Compute", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Compute, "Computes the new presentation of the structures displayed in this view with the type Graphic3d_TOS_COMPUTED.");
	cls_Graphic3d_CView.def("ContainsFacet", (Standard_Boolean (Graphic3d_CView::*)() const ) &Graphic3d_CView::ContainsFacet, "Returns Standard_True if one of the structures displayed in the view contains Polygons, Triangles or Quadrangles.");
	cls_Graphic3d_CView.def("ContainsFacet", (Standard_Boolean (Graphic3d_CView::*)(const Graphic3d_MapOfStructure &) const ) &Graphic3d_CView::ContainsFacet, "Returns Standard_True if one of the structures in the set contains Polygons, Triangles or Quadrangles.", py::arg("theSet"));
	cls_Graphic3d_CView.def("DisplayedStructures", (void (Graphic3d_CView::*)(Graphic3d_MapOfStructure &) const ) &Graphic3d_CView::DisplayedStructures, "Returns the set of structures displayed in this view.", py::arg("theStructures"));
	cls_Graphic3d_CView.def("NumberOfDisplayedStructures", (Standard_Integer (Graphic3d_CView::*)() const ) &Graphic3d_CView::NumberOfDisplayedStructures, "Returns number of displayed structures in the view.");
	cls_Graphic3d_CView.def("HiddenObjects", (const opencascade::handle<Graphic3d_NMapOfTransient> & (Graphic3d_CView::*)() const ) &Graphic3d_CView::HiddenObjects, "Returns map of objects hidden within this specific view (not viewer-wise).");
	cls_Graphic3d_CView.def("ChangeHiddenObjects", (opencascade::handle<Graphic3d_NMapOfTransient> & (Graphic3d_CView::*)()) &Graphic3d_CView::ChangeHiddenObjects, "Returns map of objects hidden within this specific view (not viewer-wise).");
	cls_Graphic3d_CView.def("IsComputed", (Standard_Boolean (Graphic3d_CView::*)(const Standard_Integer, opencascade::handle<Graphic3d_Structure> &) const ) &Graphic3d_CView::IsComputed, "Returns Standard_True in case if the structure with the given <theStructId> is in list of structures to be computed and stores computed struct to <theComputedStruct>.", py::arg("theStructId"), py::arg("theComputedStruct"));
	cls_Graphic3d_CView.def("MinMaxValues", [](Graphic3d_CView &self) -> Bnd_Box { return self.MinMaxValues(); });
	cls_Graphic3d_CView.def("MinMaxValues", (Bnd_Box (Graphic3d_CView::*)(const Standard_Boolean) const ) &Graphic3d_CView::MinMaxValues, "Returns the bounding box of all structures displayed in the view. If theToIncludeAuxiliary is TRUE, then the boundary box also includes minimum and maximum limits of graphical elements forming parts of infinite and other auxiliary structures.", py::arg("theToIncludeAuxiliary"));
	cls_Graphic3d_CView.def("MinMaxValues", [](Graphic3d_CView &self, const Graphic3d_MapOfStructure & a0) -> Bnd_Box { return self.MinMaxValues(a0); }, py::arg("theSet"));
	cls_Graphic3d_CView.def("MinMaxValues", (Bnd_Box (Graphic3d_CView::*)(const Graphic3d_MapOfStructure &, const Standard_Boolean) const ) &Graphic3d_CView::MinMaxValues, "Returns the coordinates of the boundary box of all structures in the set <theSet>. If <theToIgnoreInfiniteFlag> is TRUE, then the boundary box also includes minimum and maximum limits of graphical elements forming parts of infinite structures.", py::arg("theSet"), py::arg("theToIncludeAuxiliary"));
	cls_Graphic3d_CView.def("StructureManager", (const opencascade::handle<Graphic3d_StructureManager> & (Graphic3d_CView::*)() const ) &Graphic3d_CView::StructureManager, "Returns the structure manager handle which manage structures associated with this view.");
	cls_Graphic3d_CView.def("Redraw", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Redraw, "Redraw content of the view.");
	cls_Graphic3d_CView.def("RedrawImmediate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::RedrawImmediate, "Redraw immediate content of the view.");
	cls_Graphic3d_CView.def("Invalidate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Invalidate, "Invalidates content of the view but does not redraw it.");
	cls_Graphic3d_CView.def("IsInvalidated", (Standard_Boolean (Graphic3d_CView::*)()) &Graphic3d_CView::IsInvalidated, "Return true if view content cache has been invalidated.");
	cls_Graphic3d_CView.def("Resized", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Resized, "Handle changing size of the rendering window.");
	cls_Graphic3d_CView.def("SetImmediateModeDrawToFront", (Standard_Boolean (Graphic3d_CView::*)(const Standard_Boolean)) &Graphic3d_CView::SetImmediateModeDrawToFront, "Returns previous mode.", py::arg("theDrawToFrontBuffer"));
	cls_Graphic3d_CView.def("SetWindow", [](Graphic3d_CView &self, const opencascade::handle<Aspect_Window> & a0) -> void { return self.SetWindow(a0); }, py::arg("theWindow"));
	cls_Graphic3d_CView.def("SetWindow", (void (Graphic3d_CView::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &Graphic3d_CView::SetWindow, "Creates and maps rendering window to the view.", py::arg("theWindow"), py::arg("theContext"));
	cls_Graphic3d_CView.def("Window", (opencascade::handle<Aspect_Window> (Graphic3d_CView::*)() const ) &Graphic3d_CView::Window, "Returns the window associated to the view.");
	cls_Graphic3d_CView.def("IsDefined", (Standard_Boolean (Graphic3d_CView::*)() const ) &Graphic3d_CView::IsDefined, "Returns True if the window associated to the view is defined.");
	cls_Graphic3d_CView.def("GetGraduatedTrihedron", (const Graphic3d_GraduatedTrihedron & (Graphic3d_CView::*)()) &Graphic3d_CView::GetGraduatedTrihedron, "Returns data of a graduated trihedron");
	cls_Graphic3d_CView.def("GraduatedTrihedronDisplay", (void (Graphic3d_CView::*)(const Graphic3d_GraduatedTrihedron &)) &Graphic3d_CView::GraduatedTrihedronDisplay, "Displays Graduated Trihedron.", py::arg("theTrihedronData"));
	cls_Graphic3d_CView.def("GraduatedTrihedronErase", (void (Graphic3d_CView::*)()) &Graphic3d_CView::GraduatedTrihedronErase, "Erases Graduated Trihedron.");
	cls_Graphic3d_CView.def("GraduatedTrihedronMinMaxValues", (void (Graphic3d_CView::*)(const Graphic3d_Vec3, const Graphic3d_Vec3)) &Graphic3d_CView::GraduatedTrihedronMinMaxValues, "Sets minimum and maximum points of scene bounding box for Graduated Trihedron stored in graphic view object.", py::arg("theMin"), py::arg("theMax"));
	cls_Graphic3d_CView.def("BufferDump", (Standard_Boolean (Graphic3d_CView::*)(Image_PixMap &, const Graphic3d_BufferType &)) &Graphic3d_CView::BufferDump, "Dump active rendering buffer into specified memory buffer.", py::arg("theImage"), py::arg("theBufferType"));
	cls_Graphic3d_CView.def("Export", [](Graphic3d_CView &self, const Standard_CString a0, const Graphic3d_ExportFormat a1) -> Standard_Boolean { return self.Export(a0, a1); }, py::arg("theFileName"), py::arg("theFormat"));
	cls_Graphic3d_CView.def("Export", (Standard_Boolean (Graphic3d_CView::*)(const Standard_CString, const Graphic3d_ExportFormat, const Graphic3d_SortType)) &Graphic3d_CView::Export, "Export scene into the one of the Vector graphics formats (SVG, PS, PDF...). In contrast to Bitmaps, Vector graphics is scalable (so you may got quality benefits on printing to laser printer). Notice however that results may differ a lot and do not contain some elements.", py::arg("theFileName"), py::arg("theFormat"), py::arg("theSortType"));
	cls_Graphic3d_CView.def("InvalidateBVHData", (void (Graphic3d_CView::*)(const Standard_Integer)) &Graphic3d_CView::InvalidateBVHData, "Marks BVH tree and the set of BVH primitives of correspondent priority list with id theLayerId as outdated.", py::arg("theLayerId"));
	cls_Graphic3d_CView.def("AddZLayer", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::AddZLayer, "Add a new top-level z layer with ID <theLayerId> for the view. Z layers allow drawing structures in higher layers in foreground of structures in lower layers. To add a structure to desired layer on display it is necessary to set the layer ID for the structure.", py::arg("theLayerId"));
	cls_Graphic3d_CView.def("ZLayerMax", (Standard_Integer (Graphic3d_CView::*)() const ) &Graphic3d_CView::ZLayerMax, "Returns the maximum Z layer ID. First layer ID is Graphic3d_ZLayerId_Default, last ID is ZLayerMax().");
	cls_Graphic3d_CView.def("InvalidateZLayerBoundingBox", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId) const ) &Graphic3d_CView::InvalidateZLayerBoundingBox, "Returns the bounding box of all structures displayed in the Z layer.", py::arg("theLayerId"));
	cls_Graphic3d_CView.def("ZLayerBoundingBox", (Bnd_Box (Graphic3d_CView::*)(const Graphic3d_ZLayerId, const opencascade::handle<Graphic3d_Camera> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean) const ) &Graphic3d_CView::ZLayerBoundingBox, "Returns the bounding box of all structures displayed in the Z layer.", py::arg("theLayerId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"), py::arg("theToIncludeAuxiliary"));
	cls_Graphic3d_CView.def("RemoveZLayer", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::RemoveZLayer, "Remove Z layer from the specified view. All structures displayed at the moment in layer will be displayed in default layer ( the bottom-level z layer ). To unset layer ID from associated structures use method UnsetZLayer (...).", py::arg("theLayerId"));
	cls_Graphic3d_CView.def("SetZLayerSettings", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &Graphic3d_CView::SetZLayerSettings, "Sets the settings for a single Z layer of specified view.", py::arg("theLayerId"), py::arg("theSettings"));
	cls_Graphic3d_CView.def("ConsiderZoomPersistenceObjects", (Standard_Real (Graphic3d_CView::*)()) &Graphic3d_CView::ConsiderZoomPersistenceObjects, "Returns zoom-scale factor.");
	cls_Graphic3d_CView.def("FBO", (opencascade::handle<Standard_Transient> (Graphic3d_CView::*)() const ) &Graphic3d_CView::FBO, "Returns pointer to an assigned framebuffer object.");
	cls_Graphic3d_CView.def("SetFBO", (void (Graphic3d_CView::*)(const opencascade::handle<Standard_Transient> &)) &Graphic3d_CView::SetFBO, "Sets framebuffer object for offscreen rendering.", py::arg("theFbo"));
	cls_Graphic3d_CView.def("FBOCreate", (opencascade::handle<Standard_Transient> (Graphic3d_CView::*)(const Standard_Integer, const Standard_Integer)) &Graphic3d_CView::FBOCreate, "Generate offscreen FBO in the graphic library. If not supported on hardware returns NULL.", py::arg("theWidth"), py::arg("theHeight"));
	cls_Graphic3d_CView.def("FBORelease", (void (Graphic3d_CView::*)(opencascade::handle<Standard_Transient> &)) &Graphic3d_CView::FBORelease, "Remove offscreen FBO from the graphic library", py::arg("theFbo"));
	cls_Graphic3d_CView.def("FBOGetDimensions", [](Graphic3d_CView &self, const opencascade::handle<Standard_Transient> & theFbo, Standard_Integer & theWidth, Standard_Integer & theHeight, Standard_Integer & theWidthMax, Standard_Integer & theHeightMax){ self.FBOGetDimensions(theFbo, theWidth, theHeight, theWidthMax, theHeightMax); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theWidth, theHeight, theWidthMax, theHeightMax); }, "Read offscreen FBO configuration.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theWidthMax"), py::arg("theHeightMax"));
	cls_Graphic3d_CView.def("FBOChangeViewport", (void (Graphic3d_CView::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer)) &Graphic3d_CView::FBOChangeViewport, "Change offscreen FBO viewport.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"));
	cls_Graphic3d_CView.def("CopySettings", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_CView> &)) &Graphic3d_CView::CopySettings, "Copy visualization settings from another view. Method is used for cloning views in viewer when its required to create view with same view properties.", py::arg("theOther"));
	cls_Graphic3d_CView.def("RenderingParams", (const Graphic3d_RenderingParams & (Graphic3d_CView::*)() const ) &Graphic3d_CView::RenderingParams, "Returns current rendering parameters and effect settings.");
	cls_Graphic3d_CView.def("ChangeRenderingParams", (Graphic3d_RenderingParams & (Graphic3d_CView::*)()) &Graphic3d_CView::ChangeRenderingParams, "Returns reference to current rendering parameters and effect settings.");
	cls_Graphic3d_CView.def("Background", (Aspect_Background (Graphic3d_CView::*)() const ) &Graphic3d_CView::Background, "Returns background fill color.");
	cls_Graphic3d_CView.def("SetBackground", (void (Graphic3d_CView::*)(const Aspect_Background &)) &Graphic3d_CView::SetBackground, "Sets background fill color.", py::arg("theBackground"));
	cls_Graphic3d_CView.def("GradientBackground", (Aspect_GradientBackground (Graphic3d_CView::*)() const ) &Graphic3d_CView::GradientBackground, "Returns gradient background fill colors.");
	cls_Graphic3d_CView.def("SetGradientBackground", (void (Graphic3d_CView::*)(const Aspect_GradientBackground &)) &Graphic3d_CView::SetGradientBackground, "Sets gradient background fill colors.", py::arg("theBackground"));
	cls_Graphic3d_CView.def("BackgroundImage", (TCollection_AsciiString (Graphic3d_CView::*)()) &Graphic3d_CView::BackgroundImage, "Returns background image texture file path.");
	cls_Graphic3d_CView.def("SetBackgroundImage", (void (Graphic3d_CView::*)(const TCollection_AsciiString &)) &Graphic3d_CView::SetBackgroundImage, "Sets background image texture file path.", py::arg("theFilePath"));
	cls_Graphic3d_CView.def("BackgroundImageStyle", (Aspect_FillMethod (Graphic3d_CView::*)() const ) &Graphic3d_CView::BackgroundImageStyle, "Returns background image fill style.");
	cls_Graphic3d_CView.def("SetBackgroundImageStyle", (void (Graphic3d_CView::*)(const Aspect_FillMethod)) &Graphic3d_CView::SetBackgroundImageStyle, "Sets background image fill style.", py::arg("theFillStyle"));
	cls_Graphic3d_CView.def("TextureEnv", (opencascade::handle<Graphic3d_TextureEnv> (Graphic3d_CView::*)() const ) &Graphic3d_CView::TextureEnv, "Returns environment texture set for the view.");
	cls_Graphic3d_CView.def("SetTextureEnv", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_TextureEnv> &)) &Graphic3d_CView::SetTextureEnv, "Sets environment texture for the view.", py::arg("theTextureEnv"));
	cls_Graphic3d_CView.def("IsCullingEnabled", (Standard_Boolean (Graphic3d_CView::*)() const ) &Graphic3d_CView::IsCullingEnabled, "Returns the state of frustum culling optimization.");
	cls_Graphic3d_CView.def("SetCullingEnabled", (void (Graphic3d_CView::*)(const Standard_Boolean)) &Graphic3d_CView::SetCullingEnabled, "Enables or disables frustum culling optimization.", py::arg("theIsEnabled"));
	cls_Graphic3d_CView.def("ShadingModel", (Graphic3d_TypeOfShadingModel (Graphic3d_CView::*)() const ) &Graphic3d_CView::ShadingModel, "Returns shading model of the view.");
	cls_Graphic3d_CView.def("SetShadingModel", (void (Graphic3d_CView::*)(const Graphic3d_TypeOfShadingModel)) &Graphic3d_CView::SetShadingModel, "Sets shading model of the view.", py::arg("theModel"));
	cls_Graphic3d_CView.def("BackfacingModel", (Graphic3d_TypeOfBackfacingModel (Graphic3d_CView::*)() const ) &Graphic3d_CView::BackfacingModel, "Return backfacing model used for the view.");
	cls_Graphic3d_CView.def("SetBackfacingModel", (void (Graphic3d_CView::*)(const Graphic3d_TypeOfBackfacingModel)) &Graphic3d_CView::SetBackfacingModel, "Sets backfacing model for the view.", py::arg("theModel"));
	cls_Graphic3d_CView.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (Graphic3d_CView::*)() const ) &Graphic3d_CView::Camera, "Returns camera object of the view.");
	cls_Graphic3d_CView.def("SetCamera", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_CView::SetCamera, "Sets camera used by the view.", py::arg("theCamera"));
	cls_Graphic3d_CView.def("Lights", (const Graphic3d_ListOfCLight & (Graphic3d_CView::*)() const ) &Graphic3d_CView::Lights, "Returns list of lights of the view.");
	cls_Graphic3d_CView.def("SetLights", (void (Graphic3d_CView::*)(const Graphic3d_ListOfCLight &)) &Graphic3d_CView::SetLights, "Sets list of lights for the view.", py::arg("theLights"));
	cls_Graphic3d_CView.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_CView::*)() const ) &Graphic3d_CView::ClipPlanes, "Returns list of clip planes set for the view.");
	cls_Graphic3d_CView.def("SetClipPlanes", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_CView::SetClipPlanes, "Sets list of clip planes for the view.", py::arg("thePlanes"));
	cls_Graphic3d_CView.def("DiagnosticInformation", (void (Graphic3d_CView::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const ) &Graphic3d_CView::DiagnosticInformation, "Fill in the dictionary with diagnostic info. Should be called within rendering thread.", py::arg("theDict"), py::arg("theFlags"));
	cls_Graphic3d_CView.def_static("get_type_name_", (const char * (*)()) &Graphic3d_CView::get_type_name, "None");
	cls_Graphic3d_CView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_CView::get_type_descriptor, "None");
	cls_Graphic3d_CView.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_CView::*)() const ) &Graphic3d_CView::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_GraduatedTrihedron.hxx
	py::class_<Graphic3d_AxisAspect, std::unique_ptr<Graphic3d_AxisAspect, Deleter<Graphic3d_AxisAspect>>> cls_Graphic3d_AxisAspect(mod, "Graphic3d_AxisAspect", "Class that stores style for one graduated trihedron axis such as colors, lengths and customization flags. It is used in Graphic3d_GraduatedTrihedron.");
	cls_Graphic3d_AxisAspect.def(py::init<>());
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString>(), py::arg("theName"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color>(), py::arg("theName"), py::arg("theNameColor"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"), py::arg("theToDrawName"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"), py::arg("theToDrawName"), py::arg("theToDrawValues"));
	cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"), py::arg("theToDrawName"), py::arg("theToDrawValues"), py::arg("theToDrawTickmarks"));
	cls_Graphic3d_AxisAspect.def("SetName", (void (Graphic3d_AxisAspect::*)(const TCollection_ExtendedString &)) &Graphic3d_AxisAspect::SetName, "None", py::arg("theName"));
	cls_Graphic3d_AxisAspect.def("Name", (const TCollection_ExtendedString & (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::Name, "None");
	cls_Graphic3d_AxisAspect.def("ToDrawName", (Standard_Boolean (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::ToDrawName, "None");
	cls_Graphic3d_AxisAspect.def("SetDrawName", (void (Graphic3d_AxisAspect::*)(const Standard_Boolean)) &Graphic3d_AxisAspect::SetDrawName, "None", py::arg("theToDraw"));
	cls_Graphic3d_AxisAspect.def("ToDrawTickmarks", (Standard_Boolean (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::ToDrawTickmarks, "None");
	cls_Graphic3d_AxisAspect.def("SetDrawTickmarks", (void (Graphic3d_AxisAspect::*)(const Standard_Boolean)) &Graphic3d_AxisAspect::SetDrawTickmarks, "None", py::arg("theToDraw"));
	cls_Graphic3d_AxisAspect.def("ToDrawValues", (Standard_Boolean (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::ToDrawValues, "None");
	cls_Graphic3d_AxisAspect.def("SetDrawValues", (void (Graphic3d_AxisAspect::*)(const Standard_Boolean)) &Graphic3d_AxisAspect::SetDrawValues, "None", py::arg("theToDraw"));
	cls_Graphic3d_AxisAspect.def("NameColor", (const Quantity_Color & (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::NameColor, "None");
	cls_Graphic3d_AxisAspect.def("SetNameColor", (void (Graphic3d_AxisAspect::*)(const Quantity_Color &)) &Graphic3d_AxisAspect::SetNameColor, "None", py::arg("theColor"));
	cls_Graphic3d_AxisAspect.def("Color", (const Quantity_Color & (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::Color, "Color of axis and values");
	cls_Graphic3d_AxisAspect.def("SetColor", (void (Graphic3d_AxisAspect::*)(const Quantity_Color &)) &Graphic3d_AxisAspect::SetColor, "Sets color of axis and values", py::arg("theColor"));
	cls_Graphic3d_AxisAspect.def("TickmarksNumber", (Standard_Integer (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::TickmarksNumber, "None");
	cls_Graphic3d_AxisAspect.def("SetTickmarksNumber", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetTickmarksNumber, "None", py::arg("theValue"));
	cls_Graphic3d_AxisAspect.def("TickmarksLength", (Standard_Integer (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::TickmarksLength, "None");
	cls_Graphic3d_AxisAspect.def("SetTickmarksLength", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetTickmarksLength, "None", py::arg("theValue"));
	cls_Graphic3d_AxisAspect.def("ValuesOffset", (Standard_Integer (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::ValuesOffset, "None");
	cls_Graphic3d_AxisAspect.def("SetValuesOffset", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetValuesOffset, "None", py::arg("theValue"));
	cls_Graphic3d_AxisAspect.def("NameOffset", (Standard_Integer (Graphic3d_AxisAspect::*)() const ) &Graphic3d_AxisAspect::NameOffset, "None");
	cls_Graphic3d_AxisAspect.def("SetNameOffset", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetNameOffset, "None", py::arg("theValue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_GraduatedTrihedron.hxx
	py::class_<Graphic3d_GraduatedTrihedron, std::unique_ptr<Graphic3d_GraduatedTrihedron, Deleter<Graphic3d_GraduatedTrihedron>>> cls_Graphic3d_GraduatedTrihedron(mod, "Graphic3d_GraduatedTrihedron", "Defines the class of a graduated trihedron. It contains main style parameters for implementation of graduated trihedron");
	cls_Graphic3d_GraduatedTrihedron.def(py::init<>());
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &>(), py::arg("theNamesFont"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &>(), py::arg("theNamesFont"), py::arg("theNamesStyle"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal, const Quantity_Color>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"), py::arg("theGridColor"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal, const Quantity_Color, const Standard_Boolean>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"), py::arg("theGridColor"), py::arg("theToDrawGrid"));
	cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal, const Quantity_Color, const Standard_Boolean, const Standard_Boolean>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"), py::arg("theGridColor"), py::arg("theToDrawGrid"), py::arg("theToDrawAxes"));
	cls_Graphic3d_GraduatedTrihedron.def("ChangeXAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)()) &Graphic3d_GraduatedTrihedron::ChangeXAxisAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("ChangeYAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)()) &Graphic3d_GraduatedTrihedron::ChangeYAxisAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("ChangeZAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)()) &Graphic3d_GraduatedTrihedron::ChangeZAxisAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("ChangeAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer)) &Graphic3d_GraduatedTrihedron::ChangeAxisAspect, "None", py::arg("theIndex"));
	cls_Graphic3d_GraduatedTrihedron.def("XAxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::XAxisAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("YAxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::YAxisAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("ZAxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ZAxisAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("AxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer) const ) &Graphic3d_GraduatedTrihedron::AxisAspect, "None", py::arg("theIndex"));
	cls_Graphic3d_GraduatedTrihedron.def("ArrowsLength", (Standard_ShortReal (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ArrowsLength, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetArrowsLength", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_ShortReal)) &Graphic3d_GraduatedTrihedron::SetArrowsLength, "None", py::arg("theValue"));
	cls_Graphic3d_GraduatedTrihedron.def("GridColor", (const Quantity_Color & (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::GridColor, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetGridColor", (void (Graphic3d_GraduatedTrihedron::*)(const Quantity_Color &)) &Graphic3d_GraduatedTrihedron::SetGridColor, "None", py::arg("theColor"));
	cls_Graphic3d_GraduatedTrihedron.def("ToDrawGrid", (Standard_Boolean (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ToDrawGrid, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetDrawGrid", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Boolean)) &Graphic3d_GraduatedTrihedron::SetDrawGrid, "None", py::arg("theToDraw"));
	cls_Graphic3d_GraduatedTrihedron.def("ToDrawAxes", (Standard_Boolean (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ToDrawAxes, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetDrawAxes", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Boolean)) &Graphic3d_GraduatedTrihedron::SetDrawAxes, "None", py::arg("theToDraw"));
	cls_Graphic3d_GraduatedTrihedron.def("NamesFont", (const TCollection_AsciiString & (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::NamesFont, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetNamesFont", (void (Graphic3d_GraduatedTrihedron::*)(const TCollection_AsciiString &)) &Graphic3d_GraduatedTrihedron::SetNamesFont, "None", py::arg("theFont"));
	cls_Graphic3d_GraduatedTrihedron.def("NamesFontAspect", (Font_FontAspect (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::NamesFontAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetNamesFontAspect", (void (Graphic3d_GraduatedTrihedron::*)(Font_FontAspect)) &Graphic3d_GraduatedTrihedron::SetNamesFontAspect, "None", py::arg("theAspect"));
	cls_Graphic3d_GraduatedTrihedron.def("NamesSize", (Standard_Integer (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::NamesSize, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetNamesSize", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer)) &Graphic3d_GraduatedTrihedron::SetNamesSize, "None", py::arg("theValue"));
	cls_Graphic3d_GraduatedTrihedron.def("ValuesFont", (const TCollection_AsciiString & (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ValuesFont, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetValuesFont", (void (Graphic3d_GraduatedTrihedron::*)(const TCollection_AsciiString &)) &Graphic3d_GraduatedTrihedron::SetValuesFont, "None", py::arg("theFont"));
	cls_Graphic3d_GraduatedTrihedron.def("ValuesFontAspect", (Font_FontAspect (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ValuesFontAspect, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetValuesFontAspect", (void (Graphic3d_GraduatedTrihedron::*)(Font_FontAspect)) &Graphic3d_GraduatedTrihedron::SetValuesFontAspect, "None", py::arg("theAspect"));
	cls_Graphic3d_GraduatedTrihedron.def("ValuesSize", (Standard_Integer (Graphic3d_GraduatedTrihedron::*)() const ) &Graphic3d_GraduatedTrihedron::ValuesSize, "None");
	cls_Graphic3d_GraduatedTrihedron.def("SetValuesSize", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer)) &Graphic3d_GraduatedTrihedron::SetValuesSize, "None", py::arg("theValue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_RenderingParams.hxx
	py::class_<Graphic3d_RenderingParams, std::unique_ptr<Graphic3d_RenderingParams, Deleter<Graphic3d_RenderingParams>>> cls_Graphic3d_RenderingParams(mod, "Graphic3d_RenderingParams", "Helper class to store rendering parameters.");
	cls_Graphic3d_RenderingParams.def(py::init<>());
	cls_Graphic3d_RenderingParams.def("ResolutionRatio", (Standard_ShortReal (Graphic3d_RenderingParams::*)() const ) &Graphic3d_RenderingParams::ResolutionRatio, "Returns resolution ratio.");
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_RenderingParams.hxx
	py::enum_<Graphic3d_RenderingParams::Anaglyph>(cls_Graphic3d_RenderingParams, "Anaglyph", "Anaglyph filter presets.")
		.value("Anaglyph_RedCyan_Simple", Graphic3d_RenderingParams::Anaglyph::Anaglyph_RedCyan_Simple)
		.value("Anaglyph_RedCyan_Optimized", Graphic3d_RenderingParams::Anaglyph::Anaglyph_RedCyan_Optimized)
		.value("Anaglyph_YellowBlue_Simple", Graphic3d_RenderingParams::Anaglyph::Anaglyph_YellowBlue_Simple)
		.value("Anaglyph_YellowBlue_Optimized", Graphic3d_RenderingParams::Anaglyph::Anaglyph_YellowBlue_Optimized)
		.value("Anaglyph_GreenMagenta_Simple", Graphic3d_RenderingParams::Anaglyph::Anaglyph_GreenMagenta_Simple)
		.value("Anaglyph_UserDefined", Graphic3d_RenderingParams::Anaglyph::Anaglyph_UserDefined)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_PriorityDefinitionError.hxx
	py::class_<Graphic3d_PriorityDefinitionError, opencascade::handle<Graphic3d_PriorityDefinitionError>, Standard_OutOfRange> cls_Graphic3d_PriorityDefinitionError(mod, "Graphic3d_PriorityDefinitionError", "None");
	cls_Graphic3d_PriorityDefinitionError.def(py::init<>());
	cls_Graphic3d_PriorityDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_PriorityDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_PriorityDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_PriorityDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_PriorityDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_PriorityDefinitionError.def_static("NewInstance_", (opencascade::handle<Graphic3d_PriorityDefinitionError> (*)(const Standard_CString)) &Graphic3d_PriorityDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_PriorityDefinitionError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_PriorityDefinitionError::get_type_name, "None");
	cls_Graphic3d_PriorityDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_PriorityDefinitionError::get_type_descriptor, "None");
	cls_Graphic3d_PriorityDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_PriorityDefinitionError::*)() const ) &Graphic3d_PriorityDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_StructureDefinitionError.hxx
	py::class_<Graphic3d_StructureDefinitionError, opencascade::handle<Graphic3d_StructureDefinitionError>, Standard_OutOfRange> cls_Graphic3d_StructureDefinitionError(mod, "Graphic3d_StructureDefinitionError", "None");
	cls_Graphic3d_StructureDefinitionError.def(py::init<>());
	cls_Graphic3d_StructureDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_StructureDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_StructureDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_StructureDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_StructureDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_StructureDefinitionError.def_static("NewInstance_", (opencascade::handle<Graphic3d_StructureDefinitionError> (*)(const Standard_CString)) &Graphic3d_StructureDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_StructureDefinitionError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_StructureDefinitionError::get_type_name, "None");
	cls_Graphic3d_StructureDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_StructureDefinitionError::get_type_descriptor, "None");
	cls_Graphic3d_StructureDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_StructureDefinitionError::*)() const ) &Graphic3d_StructureDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TransformError.hxx
	py::class_<Graphic3d_TransformError, opencascade::handle<Graphic3d_TransformError>, Standard_OutOfRange> cls_Graphic3d_TransformError(mod, "Graphic3d_TransformError", "None");
	cls_Graphic3d_TransformError.def(py::init<>());
	cls_Graphic3d_TransformError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_TransformError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_TransformError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_TransformError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_TransformError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_TransformError.def_static("NewInstance_", (opencascade::handle<Graphic3d_TransformError> (*)(const Standard_CString)) &Graphic3d_TransformError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_TransformError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TransformError::get_type_name, "None");
	cls_Graphic3d_TransformError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TransformError::get_type_descriptor, "None");
	cls_Graphic3d_TransformError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TransformError::*)() const ) &Graphic3d_TransformError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vector.hxx
	py::class_<Graphic3d_Vector, std::unique_ptr<Graphic3d_Vector, Deleter<Graphic3d_Vector>>> cls_Graphic3d_Vector(mod, "Graphic3d_Vector", "This class allows the creation and update of a 3D vector.");
	cls_Graphic3d_Vector.def(py::init<>());
	cls_Graphic3d_Vector.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("AX"), py::arg("AY"), py::arg("AZ"));
	cls_Graphic3d_Vector.def(py::init<const Graphic3d_Vertex &, const Graphic3d_Vertex &>(), py::arg("APoint1"), py::arg("APoint2"));
	cls_Graphic3d_Vector.def("Normalize", (void (Graphic3d_Vector::*)()) &Graphic3d_Vector::Normalize, "Normalises <me>. Category: Methods to modify the class definition Warning: Raises VectorError if <me> is null.");
	cls_Graphic3d_Vector.def("SetCoord", (void (Graphic3d_Vector::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_Vector::SetCoord, "Modifies the coordinates of the vector <me>.", py::arg("Xnew"), py::arg("Ynew"), py::arg("Znew"));
	cls_Graphic3d_Vector.def("SetXCoord", (void (Graphic3d_Vector::*)(const Standard_Real)) &Graphic3d_Vector::SetXCoord, "Modifies the X coordinate of the vector <me>.", py::arg("Xnew"));
	cls_Graphic3d_Vector.def("SetYCoord", (void (Graphic3d_Vector::*)(const Standard_Real)) &Graphic3d_Vector::SetYCoord, "Modifies the Y coordinate of the vector <me>.", py::arg("Ynew"));
	cls_Graphic3d_Vector.def("SetZCoord", (void (Graphic3d_Vector::*)(const Standard_Real)) &Graphic3d_Vector::SetZCoord, "Modifies the Z coordinate of the vector <me>.", py::arg("Znew"));
	cls_Graphic3d_Vector.def("Coord", [](Graphic3d_Vector &self, Standard_Real & AX, Standard_Real & AY, Standard_Real & AZ){ self.Coord(AX, AY, AZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(AX, AY, AZ); }, "Returns the coordinates of the vector <me>.", py::arg("AX"), py::arg("AY"), py::arg("AZ"));
	cls_Graphic3d_Vector.def("IsNormalized", (Standard_Boolean (Graphic3d_Vector::*)() const ) &Graphic3d_Vector::IsNormalized, "Returns Standard_True if <me> has length 1.");
	cls_Graphic3d_Vector.def("LengthZero", (Standard_Boolean (Graphic3d_Vector::*)() const ) &Graphic3d_Vector::LengthZero, "Returns Standard_True if <me> has length zero.");
	cls_Graphic3d_Vector.def("X", (Standard_Real (Graphic3d_Vector::*)() const ) &Graphic3d_Vector::X, "Returns the X coordinates of the vector <me>.");
	cls_Graphic3d_Vector.def("Y", (Standard_Real (Graphic3d_Vector::*)() const ) &Graphic3d_Vector::Y, "Returns the Y coordinate of the vector <me>.");
	cls_Graphic3d_Vector.def("Z", (Standard_Real (Graphic3d_Vector::*)() const ) &Graphic3d_Vector::Z, "Returns the Z coordinate of the vector <me>.");
	cls_Graphic3d_Vector.def_static("IsParallel_", (Standard_Boolean (*)(const Graphic3d_Vector &, const Graphic3d_Vector &)) &Graphic3d_Vector::IsParallel, "Returns Standard_True if the vector <AV1> and <AV2> are parallel.", py::arg("AV1"), py::arg("AV2"));
	cls_Graphic3d_Vector.def_static("NormeOf_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_Vector::NormeOf, "Returns the norm of the vector <AX>, <AY>, <AZ>.", py::arg("AX"), py::arg("AY"), py::arg("AZ"));
	cls_Graphic3d_Vector.def_static("NormeOf_", (Standard_Real (*)(const Graphic3d_Vector &)) &Graphic3d_Vector::NormeOf, "Returns the norm of the vector <AVector>.", py::arg("AVector"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_TextureEnv.hxx
	py::class_<Graphic3d_TextureEnv, opencascade::handle<Graphic3d_TextureEnv>, Graphic3d_TextureRoot> cls_Graphic3d_TextureEnv(mod, "Graphic3d_TextureEnv", "This class provides environment texture.");
	cls_Graphic3d_TextureEnv.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
	cls_Graphic3d_TextureEnv.def(py::init<const Graphic3d_NameOfTextureEnv>(), py::arg("theName"));
	cls_Graphic3d_TextureEnv.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));
	cls_Graphic3d_TextureEnv.def("Name", (Graphic3d_NameOfTextureEnv (Graphic3d_TextureEnv::*)() const ) &Graphic3d_TextureEnv::Name, "Returns the name of the predefined textures or NOT_ENV_UNKNOWN when the name is given as a filename.");
	cls_Graphic3d_TextureEnv.def_static("NumberOfTextures_", (Standard_Integer (*)()) &Graphic3d_TextureEnv::NumberOfTextures, "Returns the number of predefined textures.");
	cls_Graphic3d_TextureEnv.def_static("TextureName_", (TCollection_AsciiString (*)(const Standard_Integer)) &Graphic3d_TextureEnv::TextureName, "Returns the name of the predefined texture of rank <aRank>", py::arg("theRank"));
	cls_Graphic3d_TextureEnv.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureEnv::get_type_name, "None");
	cls_Graphic3d_TextureEnv.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureEnv::get_type_descriptor, "None");
	cls_Graphic3d_TextureEnv.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureEnv::*)() const ) &Graphic3d_TextureEnv::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ZLayerSettings.hxx
	py::class_<Graphic3d_ZLayerSettings, std::unique_ptr<Graphic3d_ZLayerSettings, Deleter<Graphic3d_ZLayerSettings>>> cls_Graphic3d_ZLayerSettings(mod, "Graphic3d_ZLayerSettings", "Structure defines list of ZLayer properties.");
	cls_Graphic3d_ZLayerSettings.def(py::init<>());
	cls_Graphic3d_ZLayerSettings.def("Name", (const TCollection_AsciiString & (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::Name, "Return user-provided name.");
	cls_Graphic3d_ZLayerSettings.def("SetName", (void (Graphic3d_ZLayerSettings::*)(const TCollection_AsciiString &)) &Graphic3d_ZLayerSettings::SetName, "Set custom name.", py::arg("theName"));
	cls_Graphic3d_ZLayerSettings.def("Origin", (const gp_XYZ & (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::Origin, "Return the origin of all objects within the layer.");
	cls_Graphic3d_ZLayerSettings.def("OriginTransformation", (const opencascade::handle<Geom_Transformation> & (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::OriginTransformation, "Return the transformation to the origin.");
	cls_Graphic3d_ZLayerSettings.def("SetOrigin", (void (Graphic3d_ZLayerSettings::*)(const gp_XYZ &)) &Graphic3d_ZLayerSettings::SetOrigin, "Set the origin of all objects within the layer.", py::arg("theOrigin"));
	cls_Graphic3d_ZLayerSettings.def("IsImmediate", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::IsImmediate, "Return true if this layer should be drawn after all normal (non-immediate) layers.");
	cls_Graphic3d_ZLayerSettings.def("SetImmediate", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetImmediate, "Set the flag indicating the immediate layer, which should be drawn after all normal (non-immediate) layers.", py::arg("theValue"));
	cls_Graphic3d_ZLayerSettings.def("UseEnvironmentTexture", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::UseEnvironmentTexture, "Return flag to allow/prevent environment texture mapping usage for specific layer.");
	cls_Graphic3d_ZLayerSettings.def("SetEnvironmentTexture", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetEnvironmentTexture, "Set the flag to allow/prevent environment texture mapping usage for specific layer.", py::arg("theValue"));
	cls_Graphic3d_ZLayerSettings.def("ToEnableDepthTest", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::ToEnableDepthTest, "Return true if depth test should be enabled.");
	cls_Graphic3d_ZLayerSettings.def("SetEnableDepthTest", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetEnableDepthTest, "Set if depth test should be enabled.", py::arg("theValue"));
	cls_Graphic3d_ZLayerSettings.def("ToEnableDepthWrite", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::ToEnableDepthWrite, "Return true depth values should be written during rendering.");
	cls_Graphic3d_ZLayerSettings.def("SetEnableDepthWrite", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetEnableDepthWrite, "Set if depth values should be written during rendering.", py::arg("theValue"));
	cls_Graphic3d_ZLayerSettings.def("ToClearDepth", (Standard_Boolean (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::ToClearDepth, "Return true if depth values should be cleared before drawing the layer.");
	cls_Graphic3d_ZLayerSettings.def("SetClearDepth", (void (Graphic3d_ZLayerSettings::*)(const Standard_Boolean)) &Graphic3d_ZLayerSettings::SetClearDepth, "Set if depth values should be cleared before drawing the layer.", py::arg("theValue"));
	cls_Graphic3d_ZLayerSettings.def("PolygonOffset", (const Graphic3d_PolygonOffset & (Graphic3d_ZLayerSettings::*)() const ) &Graphic3d_ZLayerSettings::PolygonOffset, "Return glPolygonOffset() arguments.");
	cls_Graphic3d_ZLayerSettings.def("SetPolygonOffset", (void (Graphic3d_ZLayerSettings::*)(const Graphic3d_PolygonOffset &)) &Graphic3d_ZLayerSettings::SetPolygonOffset, "Setup glPolygonOffset() arguments.", py::arg("theParams"));
	cls_Graphic3d_ZLayerSettings.def("ChangePolygonOffset", (Graphic3d_PolygonOffset & (Graphic3d_ZLayerSettings::*)()) &Graphic3d_ZLayerSettings::ChangePolygonOffset, "Modify glPolygonOffset() arguments.");
	cls_Graphic3d_ZLayerSettings.def("IsSettingEnabled", (Standard_Boolean (Graphic3d_ZLayerSettings::*)(const Graphic3d_ZLayerSetting) const ) &Graphic3d_ZLayerSettings::IsSettingEnabled, "Returns true if theSetting is enabled.", py::arg("theSetting"));
	cls_Graphic3d_ZLayerSettings.def("EnableSetting", (void (Graphic3d_ZLayerSettings::*)(const Graphic3d_ZLayerSetting)) &Graphic3d_ZLayerSettings::EnableSetting, "Enables theSetting", py::arg("theSetting"));
	cls_Graphic3d_ZLayerSettings.def("DisableSetting", (void (Graphic3d_ZLayerSettings::*)(const Graphic3d_ZLayerSetting)) &Graphic3d_ZLayerSettings::DisableSetting, "Disables theSetting", py::arg("theSetting"));
	cls_Graphic3d_ZLayerSettings.def("SetDepthOffsetPositive", (void (Graphic3d_ZLayerSettings::*)()) &Graphic3d_ZLayerSettings::SetDepthOffsetPositive, "Sets minimal possible positive depth offset.");
	cls_Graphic3d_ZLayerSettings.def("SetDepthOffsetNegative", (void (Graphic3d_ZLayerSettings::*)()) &Graphic3d_ZLayerSettings::SetDepthOffsetNegative, "Sets minimal possible negative depth offset.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfQuadrangles.hxx
	py::class_<Graphic3d_ArrayOfQuadrangles, opencascade::handle<Graphic3d_ArrayOfQuadrangles>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfQuadrangles(mod, "Graphic3d_ArrayOfQuadrangles", "Contains quatrangles array definition");
	cls_Graphic3d_ArrayOfQuadrangles.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfQuadrangles.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxEdges"));
	cls_Graphic3d_ArrayOfQuadrangles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfQuadrangles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfQuadrangles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasTexels"));
	cls_Graphic3d_ArrayOfQuadrangles.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfQuadrangles::get_type_name, "None");
	cls_Graphic3d_ArrayOfQuadrangles.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfQuadrangles::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfQuadrangles.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfQuadrangles::*)() const ) &Graphic3d_ArrayOfQuadrangles::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfTriangles.hxx
	py::class_<Graphic3d_ArrayOfTriangles, opencascade::handle<Graphic3d_ArrayOfTriangles>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfTriangles(mod, "Graphic3d_ArrayOfTriangles", "Contains triangles array definition");
	cls_Graphic3d_ArrayOfTriangles.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfTriangles.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxEdges"));
	cls_Graphic3d_ArrayOfTriangles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfTriangles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfTriangles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasTexels"));
	cls_Graphic3d_ArrayOfTriangles.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfTriangles::get_type_name, "None");
	cls_Graphic3d_ArrayOfTriangles.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfTriangles::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfTriangles.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfTriangles::*)() const ) &Graphic3d_ArrayOfTriangles::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_VectorError.hxx
	py::class_<Graphic3d_VectorError, opencascade::handle<Graphic3d_VectorError>, Standard_OutOfRange> cls_Graphic3d_VectorError(mod, "Graphic3d_VectorError", "None");
	cls_Graphic3d_VectorError.def(py::init<>());
	cls_Graphic3d_VectorError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_VectorError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_VectorError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_VectorError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_VectorError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_VectorError.def_static("NewInstance_", (opencascade::handle<Graphic3d_VectorError> (*)(const Standard_CString)) &Graphic3d_VectorError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_VectorError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_VectorError::get_type_name, "None");
	cls_Graphic3d_VectorError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_VectorError::get_type_descriptor, "None");
	cls_Graphic3d_VectorError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_VectorError::*)() const ) &Graphic3d_VectorError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfPoints.hxx
	py::class_<Graphic3d_ArrayOfPoints, opencascade::handle<Graphic3d_ArrayOfPoints>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfPoints(mod, "Graphic3d_ArrayOfPoints", "Contains points array definition");
	cls_Graphic3d_ArrayOfPoints.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfPoints.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfPoints.def(py::init<const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("hasVColors"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfPoints.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfPoints::get_type_name, "None");
	cls_Graphic3d_ArrayOfPoints.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfPoints::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfPoints.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfPoints::*)() const ) &Graphic3d_ArrayOfPoints::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfPolylines.hxx
	py::class_<Graphic3d_ArrayOfPolylines, opencascade::handle<Graphic3d_ArrayOfPolylines>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfPolylines(mod, "Graphic3d_ArrayOfPolylines", "Contains polylines array definition");
	cls_Graphic3d_ArrayOfPolylines.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfPolylines.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxBounds"));
	cls_Graphic3d_ArrayOfPolylines.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"));
	cls_Graphic3d_ArrayOfPolylines.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfPolylines.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"), py::arg("hasVColors"), py::arg("hasBColors"));
	cls_Graphic3d_ArrayOfPolylines.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfPolylines::get_type_name, "None");
	cls_Graphic3d_ArrayOfPolylines.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfPolylines::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfPolylines.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfPolylines::*)() const ) &Graphic3d_ArrayOfPolylines::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Texture2D.hxx
	py::class_<Graphic3d_Texture2D, opencascade::handle<Graphic3d_Texture2D>, Graphic3d_TextureMap> cls_Graphic3d_Texture2D(mod, "Graphic3d_Texture2D", "This abstract class for managing 2D textures");
	cls_Graphic3d_Texture2D.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture2D::get_type_name, "None");
	cls_Graphic3d_Texture2D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture2D::get_type_descriptor, "None");
	cls_Graphic3d_Texture2D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture2D::*)() const ) &Graphic3d_Texture2D::DynamicType, "None");
	cls_Graphic3d_Texture2D.def_static("NumberOfTextures_", (Standard_Integer (*)()) &Graphic3d_Texture2D::NumberOfTextures, "Returns the number of predefined textures.");
	cls_Graphic3d_Texture2D.def_static("TextureName_", (TCollection_AsciiString (*)(const Standard_Integer)) &Graphic3d_Texture2D::TextureName, "Returns the name of the predefined texture of rank <aRank>", py::arg("theRank"));
	cls_Graphic3d_Texture2D.def("Name", (Graphic3d_NameOfTexture2D (Graphic3d_Texture2D::*)() const ) &Graphic3d_Texture2D::Name, "Returns the name of the predefined textures or NOT_2D_UNKNOWN when the name is given as a filename.");
	cls_Graphic3d_Texture2D.def("SetImage", (void (Graphic3d_Texture2D::*)(const opencascade::handle<Image_PixMap> &)) &Graphic3d_Texture2D::SetImage, "Assign new image to the texture. Note that this method does not invalidate already uploaded resources - consider calling ::UpdateRevision() if needed.", py::arg("thePixMap"));
	cls_Graphic3d_Texture2D.def("HasMipMaps", (Standard_Boolean (Graphic3d_Texture2D::*)() const ) &Graphic3d_Texture2D::HasMipMaps, "Return true if mip-maps should be used.");
	cls_Graphic3d_Texture2D.def("SetMipMaps", (void (Graphic3d_Texture2D::*)(const Standard_Boolean)) &Graphic3d_Texture2D::SetMipMaps, "Set if mip-maps should be used (generated if needed). Note that this method should be called before loading / using the texture.", py::arg("theToUse"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Texture2Dmanual.hxx
	py::class_<Graphic3d_Texture2Dmanual, opencascade::handle<Graphic3d_Texture2Dmanual>, Graphic3d_Texture2D> cls_Graphic3d_Texture2Dmanual(mod, "Graphic3d_Texture2Dmanual", "This class defined a manual texture 2D facets MUST define texture coordinate if you want to see somethings on.");
	cls_Graphic3d_Texture2Dmanual.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
	cls_Graphic3d_Texture2Dmanual.def(py::init<const Graphic3d_NameOfTexture2D>(), py::arg("theNOT"));
	cls_Graphic3d_Texture2Dmanual.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));
	cls_Graphic3d_Texture2Dmanual.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture2Dmanual::get_type_name, "None");
	cls_Graphic3d_Texture2Dmanual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture2Dmanual::get_type_descriptor, "None");
	cls_Graphic3d_Texture2Dmanual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture2Dmanual::*)() const ) &Graphic3d_Texture2Dmanual::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfPolygons.hxx
	py::class_<Graphic3d_ArrayOfPolygons, opencascade::handle<Graphic3d_ArrayOfPolygons>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfPolygons(mod, "Graphic3d_ArrayOfPolygons", "Contains polygons array definition");
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxBounds"));
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"));
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasBColors"));
	cls_Graphic3d_ArrayOfPolygons.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxBounds"), py::arg("maxEdges"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasBColors"), py::arg("hasTexels"));
	cls_Graphic3d_ArrayOfPolygons.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfPolygons::get_type_name, "None");
	cls_Graphic3d_ArrayOfPolygons.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfPolygons::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfPolygons.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfPolygons::*)() const ) &Graphic3d_ArrayOfPolygons::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfQuadrangleStrips.hxx
	py::class_<Graphic3d_ArrayOfQuadrangleStrips, opencascade::handle<Graphic3d_ArrayOfQuadrangleStrips>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfQuadrangleStrips(mod, "Graphic3d_ArrayOfQuadrangleStrips", "Contains quadrangles strip array definition");
	cls_Graphic3d_ArrayOfQuadrangleStrips.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfQuadrangleStrips.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxStrips"));
	cls_Graphic3d_ArrayOfQuadrangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfQuadrangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfQuadrangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasSColors"));
	cls_Graphic3d_ArrayOfQuadrangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasSColors"), py::arg("hasTexels"));
	cls_Graphic3d_ArrayOfQuadrangleStrips.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfQuadrangleStrips::get_type_name, "None");
	cls_Graphic3d_ArrayOfQuadrangleStrips.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfQuadrangleStrips::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfQuadrangleStrips.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfQuadrangleStrips::*)() const ) &Graphic3d_ArrayOfQuadrangleStrips::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfSegments.hxx
	py::class_<Graphic3d_ArrayOfSegments, opencascade::handle<Graphic3d_ArrayOfSegments>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfSegments(mod, "Graphic3d_ArrayOfSegments", "Contains segments array definition");
	cls_Graphic3d_ArrayOfSegments.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfSegments.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxEdges"));
	cls_Graphic3d_ArrayOfSegments.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxEdges"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfSegments.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfSegments::get_type_name, "None");
	cls_Graphic3d_ArrayOfSegments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfSegments::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfSegments.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfSegments::*)() const ) &Graphic3d_ArrayOfSegments::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfTriangleFans.hxx
	py::class_<Graphic3d_ArrayOfTriangleFans, opencascade::handle<Graphic3d_ArrayOfTriangleFans>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfTriangleFans(mod, "Graphic3d_ArrayOfTriangleFans", "Contains triangles fan array definition");
	cls_Graphic3d_ArrayOfTriangleFans.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfTriangleFans.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxFans"));
	cls_Graphic3d_ArrayOfTriangleFans.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxFans"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfTriangleFans.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxFans"), py::arg("hasVNormals"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfTriangleFans.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxFans"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasFColors"));
	cls_Graphic3d_ArrayOfTriangleFans.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxFans"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasFColors"), py::arg("hasTexels"));
	cls_Graphic3d_ArrayOfTriangleFans.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfTriangleFans::get_type_name, "None");
	cls_Graphic3d_ArrayOfTriangleFans.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfTriangleFans::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfTriangleFans.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfTriangleFans::*)() const ) &Graphic3d_ArrayOfTriangleFans::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ArrayOfTriangleStrips.hxx
	py::class_<Graphic3d_ArrayOfTriangleStrips, opencascade::handle<Graphic3d_ArrayOfTriangleStrips>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfTriangleStrips(mod, "Graphic3d_ArrayOfTriangleStrips", "Contains triangles strip array definition");
	cls_Graphic3d_ArrayOfTriangleStrips.def(py::init<const Standard_Integer>(), py::arg("maxVertexs"));
	cls_Graphic3d_ArrayOfTriangleStrips.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("maxVertexs"), py::arg("maxStrips"));
	cls_Graphic3d_ArrayOfTriangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"));
	cls_Graphic3d_ArrayOfTriangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"), py::arg("hasVColors"));
	cls_Graphic3d_ArrayOfTriangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasSColors"));
	cls_Graphic3d_ArrayOfTriangleStrips.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("maxVertexs"), py::arg("maxStrips"), py::arg("hasVNormals"), py::arg("hasVColors"), py::arg("hasSColors"), py::arg("hasTexels"));
	cls_Graphic3d_ArrayOfTriangleStrips.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfTriangleStrips::get_type_name, "None");
	cls_Graphic3d_ArrayOfTriangleStrips.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfTriangleStrips::get_type_descriptor, "None");
	cls_Graphic3d_ArrayOfTriangleStrips.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfTriangleStrips::*)() const ) &Graphic3d_ArrayOfTriangleStrips::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CTexture.hxx
	py::class_<Graphic3d_CTexture, std::unique_ptr<Graphic3d_CTexture, Deleter<Graphic3d_CTexture>>> cls_Graphic3d_CTexture(mod, "Graphic3d_CTexture", "None");
	cls_Graphic3d_CTexture.def(py::init<>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_GraphicDriver.hxx
	py::class_<Graphic3d_ViewManager, std::unique_ptr<Graphic3d_ViewManager, Deleter<Graphic3d_ViewManager>>> cls_Graphic3d_ViewManager(mod, "Graphic3d_ViewManager", "None");
	cls_Graphic3d_ViewManager.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_GroupDefinitionError.hxx
	py::class_<Graphic3d_GroupDefinitionError, opencascade::handle<Graphic3d_GroupDefinitionError>, Standard_OutOfRange> cls_Graphic3d_GroupDefinitionError(mod, "Graphic3d_GroupDefinitionError", "None");
	cls_Graphic3d_GroupDefinitionError.def(py::init<>());
	cls_Graphic3d_GroupDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_GroupDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_GroupDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_GroupDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_GroupDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_GroupDefinitionError.def_static("NewInstance_", (opencascade::handle<Graphic3d_GroupDefinitionError> (*)(const Standard_CString)) &Graphic3d_GroupDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_GroupDefinitionError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_GroupDefinitionError::get_type_name, "None");
	cls_Graphic3d_GroupDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_GroupDefinitionError::get_type_descriptor, "None");
	cls_Graphic3d_GroupDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_GroupDefinitionError::*)() const ) &Graphic3d_GroupDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_MaterialDefinitionError.hxx
	py::class_<Graphic3d_MaterialDefinitionError, opencascade::handle<Graphic3d_MaterialDefinitionError>, Standard_OutOfRange> cls_Graphic3d_MaterialDefinitionError(mod, "Graphic3d_MaterialDefinitionError", "None");
	cls_Graphic3d_MaterialDefinitionError.def(py::init<>());
	cls_Graphic3d_MaterialDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Graphic3d_MaterialDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_MaterialDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_MaterialDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_MaterialDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Graphic3d_MaterialDefinitionError.def_static("NewInstance_", (opencascade::handle<Graphic3d_MaterialDefinitionError> (*)(const Standard_CString)) &Graphic3d_MaterialDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Graphic3d_MaterialDefinitionError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_MaterialDefinitionError::get_type_name, "None");
	cls_Graphic3d_MaterialDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_MaterialDefinitionError::get_type_descriptor, "None");
	cls_Graphic3d_MaterialDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_MaterialDefinitionError::*)() const ) &Graphic3d_MaterialDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Texture1D.hxx
	py::class_<Graphic3d_Texture1D, opencascade::handle<Graphic3d_Texture1D>, Graphic3d_TextureMap> cls_Graphic3d_Texture1D(mod, "Graphic3d_Texture1D", "This is an abstract class for managing 1D textures.");
	cls_Graphic3d_Texture1D.def("Name", (Graphic3d_NameOfTexture1D (Graphic3d_Texture1D::*)() const ) &Graphic3d_Texture1D::Name, "Returns the name of the predefined textures or NOT_1D_UNKNOWN when the name is given as a filename.");
	cls_Graphic3d_Texture1D.def_static("NumberOfTextures_", (Standard_Integer (*)()) &Graphic3d_Texture1D::NumberOfTextures, "Returns the number of predefined textures.");
	cls_Graphic3d_Texture1D.def_static("TextureName_", (TCollection_AsciiString (*)(const Standard_Integer)) &Graphic3d_Texture1D::TextureName, "Returns the name of the predefined texture of rank <aRank>", py::arg("aRank"));
	cls_Graphic3d_Texture1D.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture1D::get_type_name, "None");
	cls_Graphic3d_Texture1D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture1D::get_type_descriptor, "None");
	cls_Graphic3d_Texture1D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture1D::*)() const ) &Graphic3d_Texture1D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Texture1Dmanual.hxx
	py::class_<Graphic3d_Texture1Dmanual, opencascade::handle<Graphic3d_Texture1Dmanual>, Graphic3d_Texture1D> cls_Graphic3d_Texture1Dmanual(mod, "Graphic3d_Texture1Dmanual", "This class provides the implementation of a manual 1D texture. you MUST provides texture coordinates on your facets if you want to see your texture.");
	cls_Graphic3d_Texture1Dmanual.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
	cls_Graphic3d_Texture1Dmanual.def(py::init<const Graphic3d_NameOfTexture1D>(), py::arg("theNOT"));
	cls_Graphic3d_Texture1Dmanual.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));
	cls_Graphic3d_Texture1Dmanual.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture1Dmanual::get_type_name, "None");
	cls_Graphic3d_Texture1Dmanual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture1Dmanual::get_type_descriptor, "None");
	cls_Graphic3d_Texture1Dmanual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture1Dmanual::*)() const ) &Graphic3d_Texture1Dmanual::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Texture1Dsegment.hxx
	py::class_<Graphic3d_Texture1Dsegment, opencascade::handle<Graphic3d_Texture1Dsegment>, Graphic3d_Texture1D> cls_Graphic3d_Texture1Dsegment(mod, "Graphic3d_Texture1Dsegment", "This class provides the implementation of a 1D texture applyable along a segment. You might use the SetSegment() method to set the way the texture is 'streched' on facets.");
	cls_Graphic3d_Texture1Dsegment.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
	cls_Graphic3d_Texture1Dsegment.def(py::init<const Graphic3d_NameOfTexture1D>(), py::arg("theNOT"));
	cls_Graphic3d_Texture1Dsegment.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));
	cls_Graphic3d_Texture1Dsegment.def("SetSegment", (void (Graphic3d_Texture1Dsegment::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Texture1Dsegment::SetSegment, "Sets the texture application bounds. Defines the way the texture is stretched across facets. Default values are <0.0, 0.0, 0.0> , <0.0, 0.0, 1.0>", py::arg("theX1"), py::arg("theY1"), py::arg("theZ1"), py::arg("theX2"), py::arg("theY2"), py::arg("theZ2"));
	cls_Graphic3d_Texture1Dsegment.def("Segment", (void (Graphic3d_Texture1Dsegment::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const ) &Graphic3d_Texture1Dsegment::Segment, "Returns the values of the current segment X1, Y1, Z1 , X2, Y2, Z2.", py::arg("theX1"), py::arg("theY1"), py::arg("theZ1"), py::arg("theX2"), py::arg("theY2"), py::arg("theZ2"));
	cls_Graphic3d_Texture1Dsegment.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture1Dsegment::get_type_name, "None");
	cls_Graphic3d_Texture1Dsegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture1Dsegment::get_type_descriptor, "None");
	cls_Graphic3d_Texture1Dsegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture1Dsegment::*)() const ) &Graphic3d_Texture1Dsegment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Texture2Dplane.hxx
	py::class_<Graphic3d_Texture2Dplane, opencascade::handle<Graphic3d_Texture2Dplane>, Graphic3d_Texture2D> cls_Graphic3d_Texture2Dplane(mod, "Graphic3d_Texture2Dplane", "This class allows the management of a 2D texture defined from a plane equation Use the SetXXX() methods for positioning the texture as you want.");
	cls_Graphic3d_Texture2Dplane.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
	cls_Graphic3d_Texture2Dplane.def(py::init<const Graphic3d_NameOfTexture2D>(), py::arg("theNOT"));
	cls_Graphic3d_Texture2Dplane.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));
	cls_Graphic3d_Texture2Dplane.def("SetPlaneS", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetPlaneS, "Defines the texture projection plane for texture coordinate S default is <1.0, 0.0, 0.0, 0.0>", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
	cls_Graphic3d_Texture2Dplane.def("SetPlaneT", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetPlaneT, "Defines the texture projection plane for texture coordinate T default is <0.0, 1.0, 0.0, 0.0>", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
	cls_Graphic3d_Texture2Dplane.def("SetPlane", (void (Graphic3d_Texture2Dplane::*)(const Graphic3d_NameOfTexturePlane)) &Graphic3d_Texture2Dplane::SetPlane, "Defines the texture projection plane for both S and T texture coordinate default is NOTP_XY meaning: <1.0, 0.0, 0.0, 0.0> for S and <0.0, 1.0, 0.0, 0.0> for T", py::arg("thePlane"));
	cls_Graphic3d_Texture2Dplane.def("SetScaleS", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetScaleS, "Defines the texture scale for the S texture coordinate much easier than recomputing the S plane equation but the result is the same default to 1.0", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("SetScaleT", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetScaleT, "Defines the texture scale for the T texture coordinate much easier than recompution the T plane equation but the result is the same default to 1.0", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("SetTranslateS", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetTranslateS, "Defines the texture translation for the S texture coordinate you can obtain the same effect by modifying the S plane equation but its not easier. default to 0.0", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("SetTranslateT", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetTranslateT, "Defines the texture translation for the T texture coordinate you can obtain the same effect by modifying the T plane equation but its not easier. default to 0.0", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("SetRotation", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetRotation, "Sets the rotation angle of the whole texture. the same result might be achieved by recomputing the S and T plane equation but it's not the easiest way... the angle is expressed in degrees default is 0.0", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("Plane", (Graphic3d_NameOfTexturePlane (Graphic3d_Texture2Dplane::*)() const ) &Graphic3d_Texture2Dplane::Plane, "Returns the current texture plane name or NOTP_UNKNOWN when the plane is user defined.");
	cls_Graphic3d_Texture2Dplane.def("PlaneS", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::PlaneS, "Returns the current texture plane S equation", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
	cls_Graphic3d_Texture2Dplane.def("PlaneT", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::PlaneT, "Returns the current texture plane T equation", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
	cls_Graphic3d_Texture2Dplane.def("TranslateS", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::TranslateS, "Returns the current texture S translation value", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("TranslateT", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::TranslateT, "Returns the current texture T translation value", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("ScaleS", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::ScaleS, "Returns the current texture S scale value", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("ScaleT", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::ScaleT, "Returns the current texture T scale value", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def("Rotation", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const ) &Graphic3d_Texture2Dplane::Rotation, "Returns the current texture rotation angle", py::arg("theVal"));
	cls_Graphic3d_Texture2Dplane.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture2Dplane::get_type_name, "None");
	cls_Graphic3d_Texture2Dplane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture2Dplane::get_type_descriptor, "None");
	cls_Graphic3d_Texture2Dplane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture2Dplane::*)() const ) &Graphic3d_Texture2Dplane::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec3.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec3f")) {
		mod.attr("Graphic3d_Vec3") = other_mod.attr("BVH_Vec3f");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec3.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec3d")) {
		mod.attr("Graphic3d_Vec3d") = other_mod.attr("BVH_Vec3d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec3.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec3i")) {
		mod.attr("Graphic3d_Vec3i") = other_mod.attr("BVH_Vec3i");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec3.hxx
	bind_NCollection_Vec3<unsigned int>(mod, "Graphic3d_Vec3u");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec3.hxx
	bind_NCollection_Vec3<unsigned char>(mod, "Graphic3d_Vec3ub");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec3.hxx
	bind_NCollection_Vec3<char>(mod, "Graphic3d_Vec3b");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec4.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec4f")) {
		mod.attr("Graphic3d_Vec4") = other_mod.attr("BVH_Vec4f");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec4.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec4d")) {
		mod.attr("Graphic3d_Vec4d") = other_mod.attr("BVH_Vec4d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec4.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec4i")) {
		mod.attr("Graphic3d_Vec4i") = other_mod.attr("BVH_Vec4i");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec4.hxx
	bind_NCollection_Vec4<unsigned int>(mod, "Graphic3d_Vec4u");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec4.hxx
	bind_NCollection_Vec4<unsigned char>(mod, "Graphic3d_Vec4ub");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec4.hxx
	bind_NCollection_Vec4<char>(mod, "Graphic3d_Vec4b");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec2.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec2f")) {
		mod.attr("Graphic3d_Vec2") = other_mod.attr("BVH_Vec2f");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec2.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec2d")) {
		mod.attr("Graphic3d_Vec2d") = other_mod.attr("BVH_Vec2d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec2.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec2i")) {
		mod.attr("Graphic3d_Vec2i") = other_mod.attr("BVH_Vec2i");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec2.hxx
	bind_NCollection_Vec2<unsigned int>(mod, "Graphic3d_Vec2u");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec2.hxx
	bind_NCollection_Vec2<unsigned char>(mod, "Graphic3d_Vec2ub");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Vec2.hxx
	bind_NCollection_Vec2<char>(mod, "Graphic3d_Vec2b");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Mat4.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Mat4f")) {
		mod.attr("Graphic3d_Mat4") = other_mod.attr("BVH_Mat4f");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Mat4d.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Mat4d")) {
		mod.attr("Graphic3d_Mat4d") = other_mod.attr("BVH_Mat4d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<int>(mod, "Graphic3d_UniformInt");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<NCollection_Vec2<int> >(mod, "Graphic3d_UniformVec2i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<NCollection_Vec3<int> >(mod, "Graphic3d_UniformVec3i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<NCollection_Vec4<int> >(mod, "Graphic3d_UniformVec4i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<float>(mod, "Graphic3d_UniformFloat");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<NCollection_Vec2<float> >(mod, "Graphic3d_UniformVec2");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<NCollection_Vec3<float> >(mod, "Graphic3d_UniformVec3");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	bind_Graphic3d_UniformValue<NCollection_Vec4<float> >(mod, "Graphic3d_UniformVec4");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderProgram.hxx
	bind_NCollection_Sequence<opencascade::handle<Graphic3d_ShaderObject> >(mod, "Graphic3d_ShaderObjectList");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderProgram.hxx
	bind_NCollection_Sequence<opencascade::handle<Graphic3d_ShaderVariable> >(mod, "Graphic3d_ShaderVariableList");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderProgram.hxx
	bind_NCollection_Sequence<opencascade::handle<Graphic3d_ShaderAttribute> >(mod, "Graphic3d_ShaderAttributeList");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ZLayerId.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "integer")) {
		mod.attr("Graphic3d_ZLayerId") = other_mod.attr("integer");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BufferType.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Camera.hxx
	bind_NCollection_Lerp<opencascade::handle<Graphic3d_Camera> >(mod, "Graphic3d_CameraLerp");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_CLight.hxx
	bind_NCollection_List<Graphic3d_CLight>(mod, "Graphic3d_ListOfCLight");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BndBox3d.hxx
	bind_BVH_Box<double, 3>(mod, "Graphic3d_BndBox3d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BndBox4f.hxx
	bind_BVH_Box<float, 4>(mod, "Graphic3d_BndBox4f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_Buffer.hxx
	bind_NCollection_Array1<Graphic3d_Attribute>(mod, "Graphic3d_Array1OfAttribute");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_SequenceOfGroup.hxx
	bind_NCollection_Sequence<opencascade::handle<Graphic3d_Group> >(mod, "Graphic3d_SequenceOfGroup");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_MapOfStructure.hxx
	bind_NCollection_Map<opencascade::handle<Graphic3d_Structure>, NCollection_DefaultHasher<opencascade::handle<Graphic3d_Structure> > >(mod, "Graphic3d_MapOfStructure");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_NMapOfTransient.hxx
	bind_NCollection_Shared<NCollection_Map<const Standard_Transient *, NCollection_DefaultHasher<const Standard_Transient *> >, void>(mod, "Graphic3d_NMapOfTransient");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_IndexedMapOfAddress.hxx
	bind_NCollection_IndexedMap<void *const, NCollection_DefaultHasher<void *const> >(mod, "Graphic3d_IndexedMapOfAddress");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_BndBox4d.hxx
	bind_BVH_Box<double, 4>(mod, "Graphic3d_BndBox4d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_SequenceOfStructure.hxx
	bind_NCollection_Sequence<opencascade::handle<Graphic3d_Structure> >(mod, "Graphic3d_SequenceOfStructure");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_MapOfObject.hxx
	bind_NCollection_DataMap<const Standard_Transient *, opencascade::handle<Graphic3d_ViewAffinity>, NCollection_DefaultHasher<const Standard_Transient *> >(mod, "Graphic3d_MapOfObject");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_StructureManager.hxx
	bind_NCollection_IndexedMap<Graphic3d_CView *, NCollection_DefaultHasher<Graphic3d_CView *> >(mod, "Graphic3d_IndexedMapOfView");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_MapIteratorOfMapOfStructure.hxx

}
