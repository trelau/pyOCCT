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

void init_Graphic3d_1(py::module &mod) {

	py::module other_mod;

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
