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

// Interfaces for init files
void init_Graphic3d_1(py::module &);

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

	init_Graphic3d_1(mod);

	}
