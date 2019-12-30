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
#include <MeshVS_MeshSelectionMethod.hxx>
#include <MeshVS_DrawerAttribute.hxx>
#include <Standard_TypeDef.hxx>
#include <MeshVS_TwoNodes.hxx>
#include <NCollection_Array1.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <MeshVS_Array1OfSequenceOfInteger.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <MeshVS_Buffer.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <Quantity_ColorHasher.hxx>
#include <MeshVS_ColorHasher.hxx>
#include <MeshVS_EntityType.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Bnd_Box.hxx>
#include <MeshVS_Mesh.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Bnd_Box2d.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_MeshPtr.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <MeshVS_Drawer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <MeshVS_PrsBuilder.hxx>
#include <NCollection_Sequence.hxx>
#include <MeshVS_SequenceOfPrsBuilder.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <MeshVS_DataMapOfIntegerOwner.hxx>
#include <AIS_InteractiveObject.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Prs3d_Drawer.hxx>
#include <Select3D_SensitiveSet.hxx>
#include <MeshVS_CommonSensitiveEntity.hxx>
#include <Select3D_BndBox3d.hxx>
#include <SelectBasics_PickResult.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <NCollection_Vector.hxx>
#include <Quantity_Color.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <MeshVS_DataMapOfColorMapOfInteger.hxx>
#include <MeshVS_DataMapOfHArray1OfSequenceOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <MeshVS_DataMapOfIntegerAsciiString.hxx>
#include <MeshVS_DataMapOfIntegerBoolean.hxx>
#include <MeshVS_DataMapOfIntegerColor.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <MeshVS_DataMapOfIntegerMaterial.hxx>
#include <SelectMgr_SOPtr.hxx>
#include <MeshVS_MeshEntityOwner.hxx>
#include <MeshVS_DataMapOfIntegerMeshEntityOwner.hxx>
#include <MeshVS_TwoColors.hxx>
#include <MeshVS_DataMapOfIntegerTwoColors.hxx>
#include <gp_Vec.hxx>
#include <MeshVS_DataMapOfIntegerVector.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <MeshVS_TwoColorsHasher.hxx>
#include <MeshVS_DataMapOfTwoColorsMapOfInteger.hxx>
#include <MeshVS_DataSource3D.hxx>
#include <MeshVS_DeformedDataSource.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <gp_GTrsf.hxx>
#include <MeshVS_DummySensitiveEntity.hxx>
#include <MeshVS_ElementalColorPrsBuilder.hxx>
#include <MeshVS_TwoNodesHasher.hxx>
#include <NCollection_Map.hxx>
#include <MeshVS_MapOfTwoNodes.hxx>
#include <MeshVS_MeshOwner.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <MeshVS_MeshPrsBuilder.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <MeshVS_NodalColorPrsBuilder.hxx>
#include <Graphic3d_Texture2D.hxx>
#include <MeshVS_SelectionModeFlags.hxx>
#include <Select3D_SensitiveFace.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <MeshVS_SensitiveFace.hxx>
#include <MeshVS_SensitiveMesh.hxx>
#include <NCollection_List.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <MeshVS_SensitivePolyhedron.hxx>
#include <gp_XYZ.hxx>
#include <MeshVS_SensitiveQuad.hxx>
#include <Select3D_SensitiveSegment.hxx>
#include <MeshVS_SensitiveSegment.hxx>
#include <MeshVS_SymmetricPairHasher.hxx>
#include <MeshVS_TextPrsBuilder.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <MeshVS_Tool.hxx>
#include <gp_Trsf.hxx>
#include <MeshVS_VectorPrsBuilder.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_DefaultHasher.hxx>
#include <bind_NCollection_Map.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(MeshVS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.SelectMgr");
py::module::import("OCCT.AIS");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.SelectBasics");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Aspect");

// ENUM: MESHVS_MESHSELECTIONMETHOD
py::enum_<MeshVS_MeshSelectionMethod>(mod, "MeshVS_MeshSelectionMethod", "this enumeration describe what type of sensitive entity will be built in 0-th selection mode (it means that whole mesh is selected )")
	.value("MeshVS_MSM_PRECISE", MeshVS_MeshSelectionMethod::MeshVS_MSM_PRECISE)
	.value("MeshVS_MSM_NODES", MeshVS_MeshSelectionMethod::MeshVS_MSM_NODES)
	.value("MeshVS_MSM_BOX", MeshVS_MeshSelectionMethod::MeshVS_MSM_BOX)
	.export_values();


// ENUM: MESHVS_DRAWERATTRIBUTE
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


// FUNCTION: HASHCODE
mod.def("HashCode", (Standard_Integer (*) (const MeshVS_TwoNodes &, const Standard_Integer)) &HashCode, "Computes a hash code for two nodes, in the range [1, theUpperBound]", py::arg("theTwoNodes"), py::arg("theUpperBound"));

// TYPEDEF: MESHVS_ARRAY1OFSEQUENCEOFINTEGER
bind_NCollection_Array1<NCollection_Sequence<int> >(mod, "MeshVS_Array1OfSequenceOfInteger", py::module_local(false));

// CLASS: MESHVS_BUFFER
py::class_<MeshVS_Buffer> cls_MeshVS_Buffer(mod, "MeshVS_Buffer", "None");

// Constructors
cls_MeshVS_Buffer.def(py::init<const Standard_Size>(), py::arg("theSize"));

// TYPEDEF: MESHVS_BUILDERPRIORITY

// TYPEDEF: MESHVS_COLORHASHER
py::class_<Quantity_ColorHasher> cls_MeshVS_ColorHasher(mod, "MeshVS_ColorHasher", "Hasher of Quantity_Color.", py::module_local());

// Constructors
cls_MeshVS_ColorHasher.def(py::init<>());

// Methods
cls_MeshVS_ColorHasher.def_static("HashCode_", (Standard_Integer (*)(const Quantity_Color &, const Standard_Integer)) &Quantity_ColorHasher::HashCode, "Returns hash code for the given RGB color, in the range [1, theUpperBound]", py::arg("theColor"), py::arg("theUpperBound"));
cls_MeshVS_ColorHasher.def_static("IsEqual_", (Standard_Boolean (*)(const Quantity_Color &, const Quantity_Color &)) &Quantity_ColorHasher::IsEqual, "Returns true if two colors are equal.", py::arg("theColor1"), py::arg("theColor2"));

// TYPEDEF: MESHVS_ENTITYTYPE

// CLASS: MESHVS_HARRAY1OFSEQUENCEOFINTEGER
bind_Define_HArray1<MeshVS_HArray1OfSequenceOfInteger, MeshVS_Array1OfSequenceOfInteger>(mod, "MeshVS_HArray1OfSequenceOfInteger");

// CLASS: MESHVS_DATASOURCE
py::class_<MeshVS_DataSource, opencascade::handle<MeshVS_DataSource>, Standard_Transient> cls_MeshVS_DataSource(mod, "MeshVS_DataSource", "The deferred class using for the following tasks: 1) Receiving geometry data about single element of node by its number; 2) Receiving type of element or node by its number; 3) Receiving topological information about links between element and nodes it consist of; 4) Receiving information about what element cover this node; 5) Receiving information about all nodes and elements the object consist of 6) Activation of advanced mesh selection. In the advanced mesh selection mode there is created: - one owner for the whole mesh and for all selection modes - one sensitive entity for the whole mesh and for each selection mode Receiving of IDs of detected entities (nodes and elements) in a viewer is achieved by implementation of a group of methods GetDetectedEntities.");

// Methods
cls_MeshVS_DataSource.def("GetGeom", [](MeshVS_DataSource &self, const Standard_Integer ID, const Standard_Boolean IsElement, TColStd_Array1OfReal & Coords, Standard_Integer & NbNodes, MeshVS_EntityType & Type){ Standard_Boolean rv = self.GetGeom(ID, IsElement, Coords, NbNodes, Type); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "Returns geometry information about node or element ID is the numerical identificator of node or element IsElement indicates this ID describe node ( if Standard_False ) or element ( if Standard_True ) Coords is an array of co-ordinates of node(s). For node it is only 3 numbers: X, Y, Z in the strict order For element it is 3*n numbers, where n is number of this element vertices The order is strict also: X1, Y1, Z1, X2,...., where Xi, Yi, Zi are co-ordinates of vertices NbNodes is number of nodes. It is recommended this parameter to be set to 1 for node. Type is type of node or element (from enumeration). It is recommended this parameter to be set to MeshVS_ET_Node for node.", py::arg("ID"), py::arg("IsElement"), py::arg("Coords"), py::arg("NbNodes"), py::arg("Type"));
cls_MeshVS_DataSource.def("GetGeomType", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean, MeshVS_EntityType &) const) &MeshVS_DataSource::GetGeomType, "This method is similar to GetGeom, but returns only element or node type.", py::arg("ID"), py::arg("IsElement"), py::arg("Type"));
cls_MeshVS_DataSource.def("Get3DGeom", [](MeshVS_DataSource &self, const Standard_Integer ID, Standard_Integer & NbNodes, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & Data){ Standard_Boolean rv = self.Get3DGeom(ID, NbNodes, Data); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "This method returns topology information about 3D-element Returns false if element with ID isn't 3D or because other troubles", py::arg("ID"), py::arg("NbNodes"), py::arg("Data"));
cls_MeshVS_DataSource.def("GetAddr", (Standard_Address (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean) const) &MeshVS_DataSource::GetAddr, "This method returns pointer which represents element or node data structure. This address will be saved in MeshVS_MeshEntityOwner, so that you can access to data structure fast by the method Owner(). In the redefined method you can return NULL. ID is the numerical identificator of node or element IsElement indicates this ID describe node ( if Standard_False ) or element ( if Standard_True )", py::arg("ID"), py::arg("IsElement"));
cls_MeshVS_DataSource.def("GetNodesByElement", [](MeshVS_DataSource &self, const Standard_Integer ID, TColStd_Array1OfInteger & NodeIDs, Standard_Integer & NbNodes){ Standard_Boolean rv = self.GetNodesByElement(ID, NodeIDs, NbNodes); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "This method returns information about nodes this element consist of. ID is the numerical identificator of element. NodeIDs is the output array of nodes IDs in correct order, the same as coordinates returned by GetGeom(). NbNodes is number of nodes (number of items set in NodeIDs). Returns False if element does not exist", py::arg("ID"), py::arg("NodeIDs"), py::arg("NbNodes"));
cls_MeshVS_DataSource.def("GetAllNodes", (const TColStd_PackedMapOfInteger & (MeshVS_DataSource::*)() const) &MeshVS_DataSource::GetAllNodes, "This method returns map of all nodes the object consist of.");
cls_MeshVS_DataSource.def("GetAllElements", (const TColStd_PackedMapOfInteger & (MeshVS_DataSource::*)() const) &MeshVS_DataSource::GetAllElements, "This method returns map of all elements the object consist of.");
cls_MeshVS_DataSource.def("GetNormal", [](MeshVS_DataSource &self, const Standard_Integer Id, const Standard_Integer Max, Standard_Real & nx, Standard_Real & ny, Standard_Real & nz){ Standard_Boolean rv = self.GetNormal(Id, Max, nx, ny, nz); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, nx, ny, nz); }, "This method calculates normal of face, which is using for correct reflection presentation. There is default method, for advance reflection this method can be redefined. Id is the numerical identificator of only element! Max is maximal number of nodes an element can consist of nx, ny, nz are values whose represent co-ordinates of normal (will be returned) In the redefined method you can return normal with length more then 1, but in this case the appearance of element will be more bright than usual. For ordinary brightness you must return normal with length 1", py::arg("Id"), py::arg("Max"), py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_MeshVS_DataSource.def("GetNodeNormal", [](MeshVS_DataSource &self, const Standard_Integer ranknode, const Standard_Integer ElementId, Standard_Real & nx, Standard_Real & ny, Standard_Real & nz){ Standard_Boolean rv = self.GetNodeNormal(ranknode, ElementId, nx, ny, nz); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, nx, ny, nz); }, "This method return normal of node ranknode of face Id, which is using for smooth shading presentation. Returns false if normal isn't defined.", py::arg("ranknode"), py::arg("ElementId"), py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_MeshVS_DataSource.def("GetNormalsByElement", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer, opencascade::handle<TColStd_HArray1OfReal> &) const) &MeshVS_DataSource::GetNormalsByElement, "This method puts components of normal vectors at each node of a mesh face (at each face of a mesh volume) into the output array. Returns false if some problem was detected during calculation of normals. Id is an identifier of the mesh element. IsNodal, when true, means that normals at mesh element nodes are needed. If nodal normals are not available, or IsNodal is false, or the mesh element is a volume, then the output array contents depend on the element type: face: a normal calculated by GetNormal() is duplicated for each node of the face; volume: normals to all faces of the volume are computed (not for each node!). MaxNodes is maximal number of nodes an element can consist of. Normals contains the result.", py::arg("Id"), py::arg("IsNodal"), py::arg("MaxNodes"), py::arg("Normals"));
cls_MeshVS_DataSource.def("GetAllGroups", (void (MeshVS_DataSource::*)(TColStd_PackedMapOfInteger &) const) &MeshVS_DataSource::GetAllGroups, "This method returns map of all groups the object contains.", py::arg("Ids"));
cls_MeshVS_DataSource.def("GetGroup", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, MeshVS_EntityType &, TColStd_PackedMapOfInteger &) const) &MeshVS_DataSource::GetGroup, "This method returns map of all group elements.", py::arg("Id"), py::arg("Type"), py::arg("Ids"));
cls_MeshVS_DataSource.def("GetGroupAddr", (Standard_Address (MeshVS_DataSource::*)(const Standard_Integer) const) &MeshVS_DataSource::GetGroupAddr, "This method returns pointer which represents group data structure. This address will be saved in MeshVS_MeshOwner, so that you can access to data structure fast by the method Owner(). In the redefined method you can return NULL. ID is the numerical identificator of group", py::arg("ID"));
cls_MeshVS_DataSource.def("IsAdvancedSelectionEnabled", (Standard_Boolean (MeshVS_DataSource::*)() const) &MeshVS_DataSource::IsAdvancedSelectionEnabled, "Returns True if advanced mesh selection is enabled. Default implementation returns False. It should be redefined to return True for advanced mesh selection activation.");
cls_MeshVS_DataSource.def("GetBoundingBox", (Bnd_Box (MeshVS_DataSource::*)() const) &MeshVS_DataSource::GetBoundingBox, "Returns the bounding box of the whole mesh. It is used in advanced selection mode to define roughly the sensitive area of the mesh. It can be redefined to get access to a box computed in advance.");
cls_MeshVS_DataSource.def("GetDetectedEntities", [](MeshVS_DataSource &self, const opencascade::handle<MeshVS_Mesh> & Prs, const Standard_Real X, const Standard_Real Y, const Standard_Real aTol, opencascade::handle<TColStd_HPackedMapOfInteger> & Nodes, opencascade::handle<TColStd_HPackedMapOfInteger> & Elements, Standard_Real & DMin){ Standard_Boolean rv = self.GetDetectedEntities(Prs, X, Y, aTol, Nodes, Elements, DMin); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DMin); }, "Returns maps of entities (nodes and elements) detected by mouse click at the point (X,Y) on the current view plane, with the tolerance aTol. DMin - is out argument should return actual detection tolerance. Returns True if something is detected. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("X"), py::arg("Y"), py::arg("aTol"), py::arg("Nodes"), py::arg("Elements"), py::arg("DMin"));
cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_DataSource::GetDetectedEntities, "Returns maps of entities (nodes and elements) detected by mouse selection with rectangular box (XMin, YMin, XMax, YMax) on the current veiw plane, with the tolerance aTol. Returns True if something is detected. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("XMin"), py::arg("YMin"), py::arg("XMax"), py::arg("YMax"), py::arg("aTol"), py::arg("Nodes"), py::arg("Elements"));
cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, const TColgp_Array1OfPnt2d &, const Bnd_Box2d &, const Standard_Real, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_DataSource::GetDetectedEntities, "Returns maps of entities (nodes and elements) detected by mouse selection with the polyline <Polyline> on the current veiw plane, with the tolerance aTol. Returns True if something is detected. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("Polyline"), py::arg("aBox"), py::arg("aTol"), py::arg("Nodes"), py::arg("Elements"));
cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_DataSource::GetDetectedEntities, "Filter out the maps of mesh entities so as to keep only the entities that are allowed to be selected according to the current context. Returns True if any of the maps has been changed. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("Nodes"), py::arg("Elements"));
cls_MeshVS_DataSource.def_static("get_type_name_", (const char * (*)()) &MeshVS_DataSource::get_type_name, "None");
cls_MeshVS_DataSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DataSource::get_type_descriptor, "None");
cls_MeshVS_DataSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DataSource::*)() const) &MeshVS_DataSource::DynamicType, "None");

// TYPEDEF: MESHVS_MESHPTR

// TYPEDEF: MESHVS_DISPLAYMODEFLAGS

// CLASS: MESHVS_PRSBUILDER
py::class_<MeshVS_PrsBuilder, opencascade::handle<MeshVS_PrsBuilder>, Standard_Transient> cls_MeshVS_PrsBuilder(mod, "MeshVS_PrsBuilder", "This class is parent for all builders using in MeshVS_Mesh. It provides base fields and methods all buildes need.");

// Methods
cls_MeshVS_PrsBuilder.def("Build", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_PrsBuilder::Build, "Builds presentation of certain type of data. Prs is presentation object which this method constructs. IDs is set of numeric identificators forming object appearance. IDsToExclude is set of IDs to exclude from processing. If some entity has been excluded, it is not processed by other builders. IsElement indicates, IDs is identificators of nodes or elements. DisplayMode is numeric constant describing display mode (see MeshVS_DisplayModeFlags.hxx)", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
cls_MeshVS_PrsBuilder.def("CustomBuild", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const) &MeshVS_PrsBuilder::CustomBuild, "This method is called to build presentation of custom elements (they have MeshVS_ET_0D type). IDs is set of numeric identificators of elements for custom building. IDsToExclude is set of IDs to exclude from processing. If some entity has been excluded, it is not processed by other builders. DisplayMode is numeric constant describing display mode (see MeshVS_DisplayModeFlags.hxx)", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
cls_MeshVS_PrsBuilder.def("CustomSensitiveEntity", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_PrsBuilder::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Integer) const) &MeshVS_PrsBuilder::CustomSensitiveEntity, "This method is called to build sensitive of custom elements ( they have MeshVS_ET_0D type )", py::arg("Owner"), py::arg("SelectMode"));
cls_MeshVS_PrsBuilder.def("GetFlags", (Standard_Integer (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetFlags, "Returns flags, assigned with builder during creation");
cls_MeshVS_PrsBuilder.def("TestFlags", (Standard_Boolean (MeshVS_PrsBuilder::*)(const Standard_Integer) const) &MeshVS_PrsBuilder::TestFlags, "Test whether display mode has flags assigned with this builder. This method has default implementation and can be redefined for advance behavior Returns Standard_True only if display mode is appropriate for this builder", py::arg("DisplayMode"));
cls_MeshVS_PrsBuilder.def("GetId", (Standard_Integer (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetId, "Returns builder ID");
cls_MeshVS_PrsBuilder.def("GetPriority", (Standard_Integer (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetPriority, "Returns priority; as priority bigger, as soon builder will be called.");
cls_MeshVS_PrsBuilder.def("GetDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetDataSource, "Returns custom data source or default ( from MeshVS_Mesh ) if custom is NULL");
cls_MeshVS_PrsBuilder.def("SetDataSource", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_PrsBuilder::SetDataSource, "Change custom data source", py::arg("newDS"));
cls_MeshVS_PrsBuilder.def("GetDrawer", (opencascade::handle<MeshVS_Drawer> (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetDrawer, "Returns custom drawer or default ( from MeshVS_Mesh ) if custom is NULL");
cls_MeshVS_PrsBuilder.def("SetDrawer", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_PrsBuilder::SetDrawer, "Change custom drawer", py::arg("newDr"));
cls_MeshVS_PrsBuilder.def("SetExcluding", (void (MeshVS_PrsBuilder::*)(const Standard_Boolean)) &MeshVS_PrsBuilder::SetExcluding, "Set excluding state. If it is Standard_True, the nodes or elements, processed by current builder will be noted and next builder won't process its.", py::arg("state"));
cls_MeshVS_PrsBuilder.def("IsExcludingOn", (Standard_Boolean (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::IsExcludingOn, "Read excluding state");
cls_MeshVS_PrsBuilder.def("SetPresentationManager", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &MeshVS_PrsBuilder::SetPresentationManager, "Set presentation manager for builder", py::arg("thePrsMgr"));
cls_MeshVS_PrsBuilder.def("GetPresentationManager", (opencascade::handle<PrsMgr_PresentationManager3d> (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetPresentationManager, "Get presentation manager of builder");
cls_MeshVS_PrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_PrsBuilder::get_type_name, "None");
cls_MeshVS_PrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_PrsBuilder::get_type_descriptor, "None");
cls_MeshVS_PrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::DynamicType, "None");

// TYPEDEF: MESHVS_SEQUENCEOFPRSBUILDER
bind_NCollection_Sequence<opencascade::handle<MeshVS_PrsBuilder> >(mod, "MeshVS_SequenceOfPrsBuilder", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPOFINTEGEROWNER
bind_NCollection_DataMap<int, opencascade::handle<SelectMgr_EntityOwner>, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerOwner", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGEROWNER

// CLASS: MESHVS_MESH
py::class_<MeshVS_Mesh, opencascade::handle<MeshVS_Mesh>, AIS_InteractiveObject> cls_MeshVS_Mesh(mod, "MeshVS_Mesh", "the main class provides interface to create mesh presentation as a whole");

// Constructors
cls_MeshVS_Mesh.def(py::init<>());
cls_MeshVS_Mesh.def(py::init<const Standard_Boolean>(), py::arg("theIsAllowOverlapped"));

// Methods
cls_MeshVS_Mesh.def("AcceptDisplayMode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::AcceptDisplayMode, "Returns true for supported display modes basing on a list of defined builders.", py::arg("theMode"));
cls_MeshVS_Mesh.def("Compute", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &MeshVS_Mesh::Compute, "Computes presentation using builders added to sequence. Each builder computes own part of mesh presentation according to its type.", py::arg("PM"), py::arg("Prs"), py::arg("DisplayMode"));
cls_MeshVS_Mesh.def("ComputeSelection", (void (MeshVS_Mesh::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &MeshVS_Mesh::ComputeSelection, "Computes selection according to SelectMode", py::arg("Sel"), py::arg("SelectMode"));
cls_MeshVS_Mesh.def("HilightSelected", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &MeshVS_Mesh::HilightSelected, "Draw selected owners presentation", py::arg("PM"), py::arg("Owners"));
cls_MeshVS_Mesh.def("HilightOwnerWithColor", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &MeshVS_Mesh::HilightOwnerWithColor, "Draw hilighted owner presentation", py::arg("thePM"), py::arg("theColor"), py::arg("theOwner"));
cls_MeshVS_Mesh.def("ClearSelected", (void (MeshVS_Mesh::*)()) &MeshVS_Mesh::ClearSelected, "Clears internal selection presentation");
cls_MeshVS_Mesh.def("GetBuildersCount", (Standard_Integer (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetBuildersCount, "How many builders there are in sequence");
cls_MeshVS_Mesh.def("GetBuilder", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::GetBuilder, "Returns builder by its index in sequence", py::arg("Index"));
cls_MeshVS_Mesh.def("GetBuilderById", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::GetBuilderById, "Returns builder by its ID", py::arg("Id"));
cls_MeshVS_Mesh.def("GetFreeId", (Standard_Integer (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetFreeId, "Returns the smallest positive ID, not occupied by any builder. This method using when builder is created with ID = -1");
cls_MeshVS_Mesh.def("AddBuilder", [](MeshVS_Mesh &self, const opencascade::handle<MeshVS_PrsBuilder> & a0) -> void { return self.AddBuilder(a0); });
cls_MeshVS_Mesh.def("AddBuilder", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_PrsBuilder> &, const Standard_Boolean)) &MeshVS_Mesh::AddBuilder, "Adds builder to tale of sequence. PrsBuilder is builder to be added If TreatAsHilighter is true, MeshVS_Mesh will use this builder to create presentation of hilighted and selected owners. Only one builder can be hilighter, so that if you call this method with TreatAsHilighter = Standard_True some times, only last builder will be hilighter WARNING: As minimum one builder must be added as hilighter, otherwise selection cannot be computed", py::arg("Builder"), py::arg("TreatAsHilighter"));
cls_MeshVS_Mesh.def("SetHilighter", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_Mesh::SetHilighter, "Changes hilighter ( see above )", py::arg("Builder"));
cls_MeshVS_Mesh.def("SetHilighter", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::SetHilighter, "Sets builder with sequence index 'Index' as hilighter", py::arg("Index"));
cls_MeshVS_Mesh.def("SetHilighterById", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::SetHilighterById, "Sets builder with identificator 'Id' as hilighter", py::arg("Id"));
cls_MeshVS_Mesh.def("GetHilighter", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetHilighter, "Returns hilighter");
cls_MeshVS_Mesh.def("RemoveBuilder", (void (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::RemoveBuilder, "Removes builder from sequence. If it is hilighter, hilighter will be NULL ( Don't remember to set it to other after!!! )", py::arg("Index"));
cls_MeshVS_Mesh.def("RemoveBuilderById", (void (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::RemoveBuilderById, "Removes builder with identificator Id", py::arg("Id"));
cls_MeshVS_Mesh.def("FindBuilder", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_CString) const) &MeshVS_Mesh::FindBuilder, "Finds builder by its type the string represents", py::arg("TypeString"));
cls_MeshVS_Mesh.def("GetOwnerMaps", (const MeshVS_DataMapOfIntegerOwner & (MeshVS_Mesh::*)(const Standard_Boolean)) &MeshVS_Mesh::GetOwnerMaps, "Returns map of owners.", py::arg("IsElement"));
cls_MeshVS_Mesh.def("GetDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetDataSource, "Returns default builders' data source");
cls_MeshVS_Mesh.def("SetDataSource", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_Mesh::SetDataSource, "Sets default builders' data source", py::arg("aDataSource"));
cls_MeshVS_Mesh.def("GetDrawer", (opencascade::handle<MeshVS_Drawer> (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetDrawer, "Returns default builders' drawer");
cls_MeshVS_Mesh.def("SetDrawer", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_Mesh::SetDrawer, "Sets default builders' drawer", py::arg("aDrawer"));
cls_MeshVS_Mesh.def("IsHiddenElem", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsHiddenElem, "Returns True if specified element is hidden By default no elements are hidden", py::arg("ID"));
cls_MeshVS_Mesh.def("IsHiddenNode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsHiddenNode, "Returns True if specified node is hidden. By default all nodes are hidden", py::arg("ID"));
cls_MeshVS_Mesh.def("IsSelectableElem", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsSelectableElem, "Returns True if specified element is not hidden", py::arg("ID"));
cls_MeshVS_Mesh.def("IsSelectableNode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsSelectableNode, "Returns True if specified node is specified as selectable.", py::arg("ID"));
cls_MeshVS_Mesh.def("GetHiddenNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetHiddenNodes, "Returns map of hidden nodes (may be null handle)");
cls_MeshVS_Mesh.def("SetHiddenNodes", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetHiddenNodes, "Sets map of hidden nodes, which shall not be displayed individually. If nodes shared by some elements shall not be drawn, they should be included into that map", py::arg("Ids"));
cls_MeshVS_Mesh.def("GetHiddenElems", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetHiddenElems, "Returns map of hidden elements (may be null handle)");
cls_MeshVS_Mesh.def("SetHiddenElems", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetHiddenElems, "Sets map of hidden elements", py::arg("Ids"));
cls_MeshVS_Mesh.def("GetSelectableNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetSelectableNodes, "Returns map of selectable elements (may be null handle)");
cls_MeshVS_Mesh.def("SetSelectableNodes", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetSelectableNodes, "Sets map of selectable nodes.", py::arg("Ids"));
cls_MeshVS_Mesh.def("UpdateSelectableNodes", (void (MeshVS_Mesh::*)()) &MeshVS_Mesh::UpdateSelectableNodes, "Automatically computes selectable nodes; the node is considered as being selectable if it is either not hidden, or is hidden but referred by at least one non-hidden element. Thus all nodes that are visible (either individually, or as ends or corners of elements) are selectable by default.");
cls_MeshVS_Mesh.def("GetMeshSelMethod", (MeshVS_MeshSelectionMethod (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetMeshSelMethod, "Returns set mesh selection method (see MeshVS.cdl)");
cls_MeshVS_Mesh.def("SetMeshSelMethod", (void (MeshVS_Mesh::*)(const MeshVS_MeshSelectionMethod)) &MeshVS_Mesh::SetMeshSelMethod, "Sets mesh selection method (see MeshVS.cdl)", py::arg("M"));
cls_MeshVS_Mesh.def("IsWholeMeshOwner", (Standard_Boolean (MeshVS_Mesh::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &MeshVS_Mesh::IsWholeMeshOwner, "Returns True if the given owner represents a whole mesh.", py::arg("theOwner"));
cls_MeshVS_Mesh.def_static("get_type_name_", (const char * (*)()) &MeshVS_Mesh::get_type_name, "None");
cls_MeshVS_Mesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_Mesh::get_type_descriptor, "None");
cls_MeshVS_Mesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::DynamicType, "None");

// CLASS: MESHVS_COMMONSENSITIVEENTITY
py::class_<MeshVS_CommonSensitiveEntity, opencascade::handle<MeshVS_CommonSensitiveEntity>, Select3D_SensitiveSet> cls_MeshVS_CommonSensitiveEntity(mod, "MeshVS_CommonSensitiveEntity", "Sensitive entity covering entire mesh for global selection.");

// Constructors
cls_MeshVS_CommonSensitiveEntity.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const opencascade::handle<MeshVS_Mesh> &, const MeshVS_MeshSelectionMethod>(), py::arg("theOwner"), py::arg("theParentMesh"), py::arg("theSelMethod"));

// Methods
cls_MeshVS_CommonSensitiveEntity.def_static("get_type_name_", (const char * (*)()) &MeshVS_CommonSensitiveEntity::get_type_name, "None");
cls_MeshVS_CommonSensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_CommonSensitiveEntity::get_type_descriptor, "None");
cls_MeshVS_CommonSensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_CommonSensitiveEntity::*)() const) &MeshVS_CommonSensitiveEntity::DynamicType, "None");
cls_MeshVS_CommonSensitiveEntity.def("NbSubElements", (Standard_Integer (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::NbSubElements, "Number of elements.");
cls_MeshVS_CommonSensitiveEntity.def("Size", (Standard_Integer (MeshVS_CommonSensitiveEntity::*)() const) &MeshVS_CommonSensitiveEntity::Size, "Returns the amount of sub-entities of the complex entity");
cls_MeshVS_CommonSensitiveEntity.def("Box", (Select3D_BndBox3d (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer) const) &MeshVS_CommonSensitiveEntity::Box, "Returns bounding box of sub-entity with index theIdx in sub-entity list", py::arg("theIdx"));
cls_MeshVS_CommonSensitiveEntity.def("Center", (Standard_Real (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer, const Standard_Integer) const) &MeshVS_CommonSensitiveEntity::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_MeshVS_CommonSensitiveEntity.def("Swap", (void (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_CommonSensitiveEntity::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIdx1"), py::arg("theIdx2"));
cls_MeshVS_CommonSensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
cls_MeshVS_CommonSensitiveEntity.def("CenterOfGeometry", (gp_Pnt (MeshVS_CommonSensitiveEntity::*)() const) &MeshVS_CommonSensitiveEntity::CenterOfGeometry, "Returns center of a mesh");
cls_MeshVS_CommonSensitiveEntity.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::GetConnected, "Create a copy.");

// TYPEDEF: MESHVS_DATAMAPOFCOLORMAPOFINTEGER
bind_NCollection_DataMap<Quantity_Color, NCollection_Map<int, NCollection_DefaultHasher<int> >, Quantity_ColorHasher>(mod, "MeshVS_DataMapOfColorMapOfInteger", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFCOLORMAPOFINTEGER

// TYPEDEF: MESHVS_DATAMAPOFHARRAY1OFSEQUENCEOFINTEGER
bind_NCollection_DataMap<int, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger>, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfHArray1OfSequenceOfInteger", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFHARRAY1OFSEQUENCEOFINTEGER

// TYPEDEF: MESHVS_DATAMAPOFINTEGERASCIISTRING
bind_NCollection_DataMap<int, TCollection_AsciiString, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerAsciiString", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERASCIISTRING

// TYPEDEF: MESHVS_DATAMAPOFINTEGERBOOLEAN
bind_NCollection_DataMap<int, bool, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerBoolean", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERBOOLEAN

// TYPEDEF: MESHVS_DATAMAPOFINTEGERCOLOR
bind_NCollection_DataMap<int, Quantity_Color, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerColor", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERCOLOR

// TYPEDEF: MESHVS_DATAMAPOFINTEGERMATERIAL
bind_NCollection_DataMap<int, Graphic3d_MaterialAspect, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerMaterial", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERMATERIAL

// CLASS: MESHVS_MESHENTITYOWNER
py::class_<MeshVS_MeshEntityOwner, opencascade::handle<MeshVS_MeshEntityOwner>, SelectMgr_EntityOwner> cls_MeshVS_MeshEntityOwner(mod, "MeshVS_MeshEntityOwner", "The custom owner. This class provides methods to store owner information: 1) An address of element or node data structure 2) Type of node or element owner assigned 3) ID of node or element owner assigned");

// Constructors
cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"));
cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &, const Standard_Integer>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"), py::arg("Priority"));
cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &, const Standard_Integer, const Standard_Boolean>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"), py::arg("Priority"), py::arg("IsGroup"));

// Methods
cls_MeshVS_MeshEntityOwner.def("Owner", (Standard_Address (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::Owner, "Returns an address of element or node data structure");
cls_MeshVS_MeshEntityOwner.def("Type", (MeshVS_EntityType (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::Type, "Returns type of element or node data structure");
cls_MeshVS_MeshEntityOwner.def("ID", (Standard_Integer (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::ID, "Returns ID of element or node data structure");
cls_MeshVS_MeshEntityOwner.def("IsGroup", (Standard_Boolean (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::IsGroup, "Returns true if owner represents group of nodes or elements");
cls_MeshVS_MeshEntityOwner.def("IsHilighted", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_MeshVS_MeshEntityOwner.def("IsHilighted", (Standard_Boolean (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &MeshVS_MeshEntityOwner::IsHilighted, "Returns true if owner is hilighted", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshEntityOwner.def("HilightWithColor", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_MeshVS_MeshEntityOwner.def("HilightWithColor", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::HilightWithColor, "Hilights owner with the certain color", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_MeshVS_MeshEntityOwner.def("Unhilight", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_MeshVS_MeshEntityOwner.def("Unhilight", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::Unhilight, "Strip hilight of owner", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshEntityOwner.def("Clear", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); });
cls_MeshVS_MeshEntityOwner.def("Clear", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::Clear, "None", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshEntityOwner.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshEntityOwner::get_type_name, "None");
cls_MeshVS_MeshEntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshEntityOwner::get_type_descriptor, "None");
cls_MeshVS_MeshEntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::DynamicType, "None");

// TYPEDEF: MESHVS_DATAMAPOFINTEGERMESHENTITYOWNER
bind_NCollection_DataMap<int, opencascade::handle<MeshVS_MeshEntityOwner>, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerMeshEntityOwner", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERMESHENTITYOWNER

// TYPEDEF: MESHVS_TWOCOLORS
/*
py::class_<> cls_MeshVS_TwoColors(mod, "MeshVS_TwoColors", "None");

// Constructors
cls_MeshVS_TwoColors.def(py::init<>());

// Fields
cls_MeshVS_TwoColors.def_readwrite("r1", &r1, "None");
cls_MeshVS_TwoColors.def_readwrite("g1", &g1, "None");
cls_MeshVS_TwoColors.def_readwrite("b1", &b1, "None");
cls_MeshVS_TwoColors.def_readwrite("r2", &r2, "None");
cls_MeshVS_TwoColors.def_readwrite("g2", &g2, "None");
cls_MeshVS_TwoColors.def_readwrite("b2", &b2, "None");
*/

// TYPEDEF: MESHVS_DATAMAPOFINTEGERTWOCOLORS
bind_NCollection_DataMap<int, MeshVS_TwoColors, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerTwoColors", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERTWOCOLORS

// TYPEDEF: MESHVS_DATAMAPOFINTEGERVECTOR
bind_NCollection_DataMap<int, gp_Vec, NCollection_DefaultHasher<int> >(mod, "MeshVS_DataMapOfIntegerVector", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFINTEGERVECTOR

// TYPEDEF: MESHVS_TWOCOLORSHASHER
bind_NCollection_DefaultHasher<MeshVS_TwoColors>(mod, "MeshVS_TwoColorsHasher", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPOFTWOCOLORSMAPOFINTEGER
bind_NCollection_DataMap<MeshVS_TwoColors, NCollection_Map<int, NCollection_DefaultHasher<int> >, NCollection_DefaultHasher<MeshVS_TwoColors> >(mod, "MeshVS_DataMapOfTwoColorsMapOfInteger", py::module_local(false));

// TYPEDEF: MESHVS_DATAMAPITERATOROFDATAMAPOFTWOCOLORSMAPOFINTEGER

// CLASS: MESHVS_DATASOURCE3D
py::class_<MeshVS_DataSource3D, opencascade::handle<MeshVS_DataSource3D>, MeshVS_DataSource> cls_MeshVS_DataSource3D(mod, "MeshVS_DataSource3D", "None");

// Methods
cls_MeshVS_DataSource3D.def("GetPrismTopology", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (MeshVS_DataSource3D::*)(const Standard_Integer) const) &MeshVS_DataSource3D::GetPrismTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def("GetPyramidTopology", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (MeshVS_DataSource3D::*)(const Standard_Integer) const) &MeshVS_DataSource3D::GetPyramidTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def_static("CreatePrismTopology_", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (*)(const Standard_Integer)) &MeshVS_DataSource3D::CreatePrismTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def_static("CreatePyramidTopology_", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (*)(const Standard_Integer)) &MeshVS_DataSource3D::CreatePyramidTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def_static("get_type_name_", (const char * (*)()) &MeshVS_DataSource3D::get_type_name, "None");
cls_MeshVS_DataSource3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DataSource3D::get_type_descriptor, "None");
cls_MeshVS_DataSource3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DataSource3D::*)() const) &MeshVS_DataSource3D::DynamicType, "None");

// CLASS: MESHVS_DEFORMEDDATASOURCE
py::class_<MeshVS_DeformedDataSource, opencascade::handle<MeshVS_DeformedDataSource>, MeshVS_DataSource> cls_MeshVS_DeformedDataSource(mod, "MeshVS_DeformedDataSource", "The class provides default class which helps to represent node displacements by deformed mesh This class has an internal handle to canonical non-deformed mesh data source and map of displacement vectors. The displacement can be magnified to useful size. All methods is implemented with calling the corresponding methods of non-deformed data source.");

// Constructors
cls_MeshVS_DeformedDataSource.def(py::init<const opencascade::handle<MeshVS_DataSource> &, const Standard_Real>(), py::arg("theNonDeformDS"), py::arg("theMagnify"));

// Methods
cls_MeshVS_DeformedDataSource.def("GetGeom", [](MeshVS_DeformedDataSource &self, const Standard_Integer ID, const Standard_Boolean IsElement, TColStd_Array1OfReal & Coords, Standard_Integer & NbNodes, MeshVS_EntityType & Type){ Standard_Boolean rv = self.GetGeom(ID, IsElement, Coords, NbNodes, Type); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "None", py::arg("ID"), py::arg("IsElement"), py::arg("Coords"), py::arg("NbNodes"), py::arg("Type"));
cls_MeshVS_DeformedDataSource.def("GetGeomType", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, const Standard_Boolean, MeshVS_EntityType &) const) &MeshVS_DeformedDataSource::GetGeomType, "None", py::arg("ID"), py::arg("IsElement"), py::arg("Type"));
cls_MeshVS_DeformedDataSource.def("Get3DGeom", [](MeshVS_DeformedDataSource &self, const Standard_Integer ID, Standard_Integer & NbNodes, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & Data){ Standard_Boolean rv = self.Get3DGeom(ID, NbNodes, Data); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "None", py::arg("ID"), py::arg("NbNodes"), py::arg("Data"));
cls_MeshVS_DeformedDataSource.def("GetAddr", (Standard_Address (MeshVS_DeformedDataSource::*)(const Standard_Integer, const Standard_Boolean) const) &MeshVS_DeformedDataSource::GetAddr, "None", py::arg("ID"), py::arg("IsElement"));
cls_MeshVS_DeformedDataSource.def("GetNodesByElement", [](MeshVS_DeformedDataSource &self, const Standard_Integer ID, TColStd_Array1OfInteger & NodeIDs, Standard_Integer & NbNodes){ Standard_Boolean rv = self.GetNodesByElement(ID, NodeIDs, NbNodes); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "None", py::arg("ID"), py::arg("NodeIDs"), py::arg("NbNodes"));
cls_MeshVS_DeformedDataSource.def("GetAllNodes", (const TColStd_PackedMapOfInteger & (MeshVS_DeformedDataSource::*)() const) &MeshVS_DeformedDataSource::GetAllNodes, "None");
cls_MeshVS_DeformedDataSource.def("GetAllElements", (const TColStd_PackedMapOfInteger & (MeshVS_DeformedDataSource::*)() const) &MeshVS_DeformedDataSource::GetAllElements, "None");
cls_MeshVS_DeformedDataSource.def("GetVectors", (const MeshVS_DataMapOfIntegerVector & (MeshVS_DeformedDataSource::*)() const) &MeshVS_DeformedDataSource::GetVectors, "This method returns map of nodal displacement vectors");
cls_MeshVS_DeformedDataSource.def("SetVectors", (void (MeshVS_DeformedDataSource::*)(const MeshVS_DataMapOfIntegerVector &)) &MeshVS_DeformedDataSource::SetVectors, "This method sets map of nodal displacement vectors (Map).", py::arg("Map"));
cls_MeshVS_DeformedDataSource.def("GetVector", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, gp_Vec &) const) &MeshVS_DeformedDataSource::GetVector, "This method returns vector ( Vect ) assigned to node number ID.", py::arg("ID"), py::arg("Vect"));
cls_MeshVS_DeformedDataSource.def("SetVector", (void (MeshVS_DeformedDataSource::*)(const Standard_Integer, const gp_Vec &)) &MeshVS_DeformedDataSource::SetVector, "This method sets vector ( Vect ) assigned to node number ID.", py::arg("ID"), py::arg("Vect"));
cls_MeshVS_DeformedDataSource.def("SetNonDeformedDataSource", (void (MeshVS_DeformedDataSource::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_DeformedDataSource::SetNonDeformedDataSource, "None", py::arg("theDS"));
cls_MeshVS_DeformedDataSource.def("GetNonDeformedDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_DeformedDataSource::*)() const) &MeshVS_DeformedDataSource::GetNonDeformedDataSource, "With this methods you can read and change internal canonical data source");
cls_MeshVS_DeformedDataSource.def("SetMagnify", (void (MeshVS_DeformedDataSource::*)(const Standard_Real)) &MeshVS_DeformedDataSource::SetMagnify, "None", py::arg("theMagnify"));
cls_MeshVS_DeformedDataSource.def("GetMagnify", (Standard_Real (MeshVS_DeformedDataSource::*)() const) &MeshVS_DeformedDataSource::GetMagnify, "With this methods you can read and change magnify coefficient of nodal displacements");
cls_MeshVS_DeformedDataSource.def_static("get_type_name_", (const char * (*)()) &MeshVS_DeformedDataSource::get_type_name, "None");
cls_MeshVS_DeformedDataSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DeformedDataSource::get_type_descriptor, "None");
cls_MeshVS_DeformedDataSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DeformedDataSource::*)() const) &MeshVS_DeformedDataSource::DynamicType, "None");

// CLASS: MESHVS_DRAWER
py::class_<MeshVS_Drawer, opencascade::handle<MeshVS_Drawer>, Standard_Transient> cls_MeshVS_Drawer(mod, "MeshVS_Drawer", "This class provided the common interface to share between classes big set of constants affecting to object appearance. By default, this class can store integers, doubles, OCC colors, OCC materials. Each of OCC enum members can be stored as integers.");

// Constructors
cls_MeshVS_Drawer.def(py::init<>());

// Methods
cls_MeshVS_Drawer.def("Assign", (void (MeshVS_Drawer::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_Drawer::Assign, "This method copies other drawer contents to this.", py::arg("aDrawer"));
cls_MeshVS_Drawer.def("SetInteger", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_Drawer::SetInteger, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetDouble", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Real)) &MeshVS_Drawer::SetDouble, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetBoolean", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Boolean)) &MeshVS_Drawer::SetBoolean, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetColor", (void (MeshVS_Drawer::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_Drawer::SetColor, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetMaterial", (void (MeshVS_Drawer::*)(const Standard_Integer, const Graphic3d_MaterialAspect &)) &MeshVS_Drawer::SetMaterial, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetAsciiString", (void (MeshVS_Drawer::*)(const Standard_Integer, const TCollection_AsciiString &)) &MeshVS_Drawer::SetAsciiString, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetInteger", [](MeshVS_Drawer &self, const Standard_Integer Key, Standard_Integer & Value){ Standard_Boolean rv = self.GetInteger(Key, Value); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Value); }, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetDouble", [](MeshVS_Drawer &self, const Standard_Integer Key, Standard_Real & Value){ Standard_Boolean rv = self.GetDouble(Key, Value); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Value); }, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetBoolean", [](MeshVS_Drawer &self, const Standard_Integer Key, Standard_Boolean & Value){ Standard_Boolean rv = self.GetBoolean(Key, Value); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, Value); }, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetColor", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Quantity_Color &) const) &MeshVS_Drawer::GetColor, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetMaterial", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Graphic3d_MaterialAspect &) const) &MeshVS_Drawer::GetMaterial, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetAsciiString", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, TCollection_AsciiString &) const) &MeshVS_Drawer::GetAsciiString, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("RemoveInteger", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveInteger, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveDouble", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveDouble, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveBoolean", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveBoolean, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveColor", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveColor, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveMaterial", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveMaterial, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveAsciiString", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveAsciiString, "None", py::arg("Key"));
cls_MeshVS_Drawer.def_static("get_type_name_", (const char * (*)()) &MeshVS_Drawer::get_type_name, "None");
cls_MeshVS_Drawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_Drawer::get_type_descriptor, "None");
cls_MeshVS_Drawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_Drawer::*)() const) &MeshVS_Drawer::DynamicType, "None");

// CLASS: MESHVS_DUMMYSENSITIVEENTITY
py::class_<MeshVS_DummySensitiveEntity, opencascade::handle<MeshVS_DummySensitiveEntity>, Select3D_SensitiveEntity> cls_MeshVS_DummySensitiveEntity(mod, "MeshVS_DummySensitiveEntity", "This class allows to create owners to all elements or nodes, both hidden and shown, but these owners user cannot select 'by hands' in viewer. They means for internal application tasks, for example, receiving all owners, both for hidden and shown entities.");

// Constructors
cls_MeshVS_DummySensitiveEntity.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &>(), py::arg("theOwnerId"));

// Methods
cls_MeshVS_DummySensitiveEntity.def("Matches", (Standard_Boolean (MeshVS_DummySensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_DummySensitiveEntity::Matches, "None", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_DummySensitiveEntity.def("NbSubElements", (Standard_Integer (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::NbSubElements, "None");
cls_MeshVS_DummySensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::BoundingBox, "None");
cls_MeshVS_DummySensitiveEntity.def("BVH", (void (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::BVH, "None");
cls_MeshVS_DummySensitiveEntity.def("Clear", (void (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::Clear, "None");
cls_MeshVS_DummySensitiveEntity.def("HasInitLocation", (Standard_Boolean (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::HasInitLocation, "None");
cls_MeshVS_DummySensitiveEntity.def("InvInitLocation", (gp_GTrsf (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::InvInitLocation, "None");
cls_MeshVS_DummySensitiveEntity.def("CenterOfGeometry", (gp_Pnt (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::CenterOfGeometry, "None");
cls_MeshVS_DummySensitiveEntity.def_static("get_type_name_", (const char * (*)()) &MeshVS_DummySensitiveEntity::get_type_name, "None");
cls_MeshVS_DummySensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DummySensitiveEntity::get_type_descriptor, "None");
cls_MeshVS_DummySensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::DynamicType, "None");

// CLASS: MESHVS_ELEMENTALCOLORPRSBUILDER
py::class_<MeshVS_ElementalColorPrsBuilder, opencascade::handle<MeshVS_ElementalColorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_ElementalColorPrsBuilder(mod, "MeshVS_ElementalColorPrsBuilder", "This class provides methods to create presentation of elements with assigned colors. The class contains two color maps: map of same colors for front and back side of face and map of different ones,");

// Constructors
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

// Methods
cls_MeshVS_ElementalColorPrsBuilder.def("Build", (void (MeshVS_ElementalColorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_ElementalColorPrsBuilder::Build, "Builds presentation of elements with assigned colors.", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
cls_MeshVS_ElementalColorPrsBuilder.def("GetColors1", (const MeshVS_DataMapOfIntegerColor & (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::GetColors1, "Returns map of colors same for front and back side of face.");
cls_MeshVS_ElementalColorPrsBuilder.def("SetColors1", (void (MeshVS_ElementalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_ElementalColorPrsBuilder::SetColors1, "Sets map of colors same for front and back side of face.", py::arg("Map"));
cls_MeshVS_ElementalColorPrsBuilder.def("HasColors1", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::HasColors1, "Returns true, if map of colors isn't empty");
cls_MeshVS_ElementalColorPrsBuilder.def("GetColor1", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &) const) &MeshVS_ElementalColorPrsBuilder::GetColor1, "Returns color assigned with element number ID", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_ElementalColorPrsBuilder.def("SetColor1", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_ElementalColorPrsBuilder::SetColor1, "Sets color assigned with element number ID", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_ElementalColorPrsBuilder.def("GetColors2", (const MeshVS_DataMapOfIntegerTwoColors & (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::GetColors2, "Returns map of different colors for front and back side of face");
cls_MeshVS_ElementalColorPrsBuilder.def("SetColors2", (void (MeshVS_ElementalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerTwoColors &)) &MeshVS_ElementalColorPrsBuilder::SetColors2, "Sets map of different colors for front and back side of face", py::arg("Map"));
cls_MeshVS_ElementalColorPrsBuilder.def("HasColors2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::HasColors2, "Returns true, if map isn't empty");
cls_MeshVS_ElementalColorPrsBuilder.def("GetColor2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, MeshVS_TwoColors &) const) &MeshVS_ElementalColorPrsBuilder::GetColor2, "Returns colors assigned with element number ID", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_ElementalColorPrsBuilder.def("GetColor2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &, Quantity_Color &) const) &MeshVS_ElementalColorPrsBuilder::GetColor2, "Returns colors assigned with element number ID theColor1 is the front element color theColor2 is the back element color", py::arg("ID"), py::arg("theColor1"), py::arg("theColor2"));
cls_MeshVS_ElementalColorPrsBuilder.def("SetColor2", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const MeshVS_TwoColors &)) &MeshVS_ElementalColorPrsBuilder::SetColor2, "Sets colors assigned with element number ID", py::arg("ID"), py::arg("theTwoColors"));
cls_MeshVS_ElementalColorPrsBuilder.def("SetColor2", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &, const Quantity_Color &)) &MeshVS_ElementalColorPrsBuilder::SetColor2, "Sets color assigned with element number ID theColor1 is the front element color theColor2 is the back element color", py::arg("ID"), py::arg("theColor1"), py::arg("theColor2"));
cls_MeshVS_ElementalColorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_ElementalColorPrsBuilder::get_type_name, "None");
cls_MeshVS_ElementalColorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_ElementalColorPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_ElementalColorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::DynamicType, "None");

// CLASS: MESHVS_TWONODES
py::class_<MeshVS_TwoNodes> cls_MeshVS_TwoNodes(mod, "MeshVS_TwoNodes", "Structure containing two IDs (of nodes) for using as a key in a map (as representation of a mesh link)");

// Constructors
cls_MeshVS_TwoNodes.def(py::init<>());
cls_MeshVS_TwoNodes.def(py::init<Standard_Integer>(), py::arg("aFirst"));
cls_MeshVS_TwoNodes.def(py::init<Standard_Integer, Standard_Integer>(), py::arg("aFirst"), py::arg("aSecond"));

// Fields
cls_MeshVS_TwoNodes.def_readwrite("First", &MeshVS_TwoNodes::First, "None");
cls_MeshVS_TwoNodes.def_readwrite("Second", &MeshVS_TwoNodes::Second, "None");

// TYPEDEF: MESHVS_TWONODESHASHER
bind_NCollection_DefaultHasher<MeshVS_TwoNodes>(mod, "MeshVS_TwoNodesHasher", py::module_local(false));

// TYPEDEF: MESHVS_MAPOFTWONODES
bind_NCollection_Map<MeshVS_TwoNodes, NCollection_DefaultHasher<MeshVS_TwoNodes> >(mod, "MeshVS_MapOfTwoNodes", py::module_local(false));

// TYPEDEF: MESHVS_MAPITERATOROFMAPOFTWONODES

// CLASS: MESHVS_MESHOWNER
py::class_<MeshVS_MeshOwner, opencascade::handle<MeshVS_MeshOwner>, SelectMgr_EntityOwner> cls_MeshVS_MeshOwner(mod, "MeshVS_MeshOwner", "The custom mesh owner used for advanced mesh selection. This class provides methods to store information: 1) IDs of hilighted mesh nodes and elements 2) IDs of mesh nodes and elements selected on the mesh");

// Constructors
cls_MeshVS_MeshOwner.def(py::init<const SelectMgr_SOPtr &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("theSelObj"), py::arg("theDS"));
cls_MeshVS_MeshOwner.def(py::init<const SelectMgr_SOPtr &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("theSelObj"), py::arg("theDS"), py::arg("thePriority"));

// Methods
cls_MeshVS_MeshOwner.def("GetDataSource", (const opencascade::handle<MeshVS_DataSource> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetDataSource, "None");
cls_MeshVS_MeshOwner.def("GetSelectedNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetSelectedNodes, "Returns ids of selected mesh nodes");
cls_MeshVS_MeshOwner.def("GetSelectedElements", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetSelectedElements, "Returns ids of selected mesh elements");
cls_MeshVS_MeshOwner.def("AddSelectedEntities", (void (MeshVS_MeshOwner::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_MeshOwner::AddSelectedEntities, "Saves ids of selected mesh entities", py::arg("Nodes"), py::arg("Elems"));
cls_MeshVS_MeshOwner.def("ClearSelectedEntities", (void (MeshVS_MeshOwner::*)()) &MeshVS_MeshOwner::ClearSelectedEntities, "Clears ids of selected mesh entities");
cls_MeshVS_MeshOwner.def("GetDetectedNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetDetectedNodes, "Returns ids of hilighted mesh nodes");
cls_MeshVS_MeshOwner.def("GetDetectedElements", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetDetectedElements, "Returns ids of hilighted mesh elements");
cls_MeshVS_MeshOwner.def("SetDetectedEntities", (void (MeshVS_MeshOwner::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_MeshOwner::SetDetectedEntities, "Saves ids of hilighted mesh entities", py::arg("Nodes"), py::arg("Elems"));
cls_MeshVS_MeshOwner.def("HilightWithColor", [](MeshVS_MeshOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_MeshVS_MeshOwner.def("HilightWithColor", (void (MeshVS_MeshOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &MeshVS_MeshOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theColor"), py::arg("theMode"));
cls_MeshVS_MeshOwner.def("Unhilight", [](MeshVS_MeshOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_MeshVS_MeshOwner.def("Unhilight", (void (MeshVS_MeshOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshOwner::Unhilight, "None", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshOwner.def("IsForcedHilight", (Standard_Boolean (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::IsForcedHilight, "None");
cls_MeshVS_MeshOwner.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshOwner::get_type_name, "None");
cls_MeshVS_MeshOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshOwner::get_type_descriptor, "None");
cls_MeshVS_MeshOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::DynamicType, "None");

// CLASS: MESHVS_MESHPRSBUILDER
py::class_<MeshVS_MeshPrsBuilder, opencascade::handle<MeshVS_MeshPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_MeshPrsBuilder(mod, "MeshVS_MeshPrsBuilder", "This class provides methods to compute base mesh presentation");

// Constructors
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

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

// CLASS: MESHVS_NODALCOLORPRSBUILDER
py::class_<MeshVS_NodalColorPrsBuilder, opencascade::handle<MeshVS_NodalColorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_NodalColorPrsBuilder(mod, "MeshVS_NodalColorPrsBuilder", "This class provides methods to create presentation of nodes with assigned color. There are two ways of presentation building 1. Without using texture. In this case colors of nodes are specified with DataMapOfIntegerColor and presentation is built with gradient fill between these nodes (default behaviour) 2. Using texture. In this case presentation is built with spectrum filling between nodes. For example, if one node has blue color and second one has violet color, parameters of this class may be set to fill presentation between nodes with solar spectrum. Methods: UseTexture - activates/deactivates this way SetColorMap - sets colors used for generation of texture SetColorindices - specifies correspondence between node IDs and indices of colors from color map");

// Constructors
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

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

// TYPEDEF: MESHVS_SELECTIONMODEFLAGS

// CLASS: MESHVS_SENSITIVEFACE
py::class_<MeshVS_SensitiveFace, opencascade::handle<MeshVS_SensitiveFace>, Select3D_SensitiveFace> cls_MeshVS_SensitiveFace(mod, "MeshVS_SensitiveFace", "This class provides custom sensitive face, which will be selected if it center is in rectangle.");

// Constructors
cls_MeshVS_SensitiveFace.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwner"), py::arg("thePoints"));
cls_MeshVS_SensitiveFace.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const TColgp_Array1OfPnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwner"), py::arg("thePoints"), py::arg("theSensType"));

// Methods
cls_MeshVS_SensitiveFace.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveFace::get_type_name, "None");
cls_MeshVS_SensitiveFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveFace::get_type_descriptor, "None");
cls_MeshVS_SensitiveFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveFace::*)() const) &MeshVS_SensitiveFace::DynamicType, "None");

// CLASS: MESHVS_SENSITIVEMESH
py::class_<MeshVS_SensitiveMesh, opencascade::handle<MeshVS_SensitiveMesh>, Select3D_SensitiveEntity> cls_MeshVS_SensitiveMesh(mod, "MeshVS_SensitiveMesh", "This class provides custom mesh sensitive entity used in advanced mesh selection.");

// Constructors
cls_MeshVS_SensitiveMesh.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &>(), py::arg("theOwner"));
cls_MeshVS_SensitiveMesh.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Integer>(), py::arg("theOwner"), py::arg("theMode"));

// Methods
cls_MeshVS_SensitiveMesh.def("GetMode", (Standard_Integer (MeshVS_SensitiveMesh::*)() const) &MeshVS_SensitiveMesh::GetMode, "None");
cls_MeshVS_SensitiveMesh.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::GetConnected, "None");
cls_MeshVS_SensitiveMesh.def("Matches", (Standard_Boolean (MeshVS_SensitiveMesh::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitiveMesh::Matches, "Checks whether sensitive overlaps current selecting volume.", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_SensitiveMesh.def("NbSubElements", (Standard_Integer (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::NbSubElements, "Returns the amount of mesh nodes");
cls_MeshVS_SensitiveMesh.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::BoundingBox, "Returns bounding box of mesh");
cls_MeshVS_SensitiveMesh.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitiveMesh::*)() const) &MeshVS_SensitiveMesh::CenterOfGeometry, "Returns center of mesh");
cls_MeshVS_SensitiveMesh.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveMesh::get_type_name, "None");
cls_MeshVS_SensitiveMesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveMesh::get_type_descriptor, "None");
cls_MeshVS_SensitiveMesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveMesh::*)() const) &MeshVS_SensitiveMesh::DynamicType, "None");

// TYPEDEF: MESHVS_POLYHEDRONVERTS
bind_NCollection_List<opencascade::handle<TColgp_HArray1OfPnt> >(mod, "MeshVS_PolyhedronVerts", py::module_local(false));

// TYPEDEF: MESHVS_POLYHEDRONVERTSITER
bind_NCollection_TListIterator<opencascade::handle<TColgp_HArray1OfPnt> >(mod, "MeshVS_PolyhedronVertsIter", py::module_local(false));

// CLASS: MESHVS_SENSITIVEPOLYHEDRON
py::class_<MeshVS_SensitivePolyhedron, opencascade::handle<MeshVS_SensitivePolyhedron>, Select3D_SensitiveEntity> cls_MeshVS_SensitivePolyhedron(mod, "MeshVS_SensitivePolyhedron", "This class is used to detect selection of a polyhedron. The main principle of detection algorithm is to search for overlap with each polyhedron's face separately, treating them as planar convex polygons.");

// Constructors
cls_MeshVS_SensitivePolyhedron.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const TColgp_Array1OfPnt &, const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &>(), py::arg("theOwner"), py::arg("theNodes"), py::arg("theTopo"));

// Methods
cls_MeshVS_SensitivePolyhedron.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::GetConnected, "None");
cls_MeshVS_SensitivePolyhedron.def("Matches", (Standard_Boolean (MeshVS_SensitivePolyhedron::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitivePolyhedron::Matches, "None", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_SensitivePolyhedron.def("NbSubElements", (Standard_Integer (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::NbSubElements, "Returns the amount of nodes of polyhedron");
cls_MeshVS_SensitivePolyhedron.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::BoundingBox, "None");
cls_MeshVS_SensitivePolyhedron.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitivePolyhedron::*)() const) &MeshVS_SensitivePolyhedron::CenterOfGeometry, "None");
cls_MeshVS_SensitivePolyhedron.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitivePolyhedron::get_type_name, "None");
cls_MeshVS_SensitivePolyhedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitivePolyhedron::get_type_descriptor, "None");
cls_MeshVS_SensitivePolyhedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitivePolyhedron::*)() const) &MeshVS_SensitivePolyhedron::DynamicType, "None");

// CLASS: MESHVS_SENSITIVEQUAD
py::class_<MeshVS_SensitiveQuad, opencascade::handle<MeshVS_SensitiveQuad>, Select3D_SensitiveEntity> cls_MeshVS_SensitiveQuad(mod, "MeshVS_SensitiveQuad", "This class contains description of planar quadrangle and defines methods for its detection by OCCT BVH selection mechanism");

// Constructors
cls_MeshVS_SensitiveQuad.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwner"), py::arg("theQuadVerts"));
cls_MeshVS_SensitiveQuad.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwner"), py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("thePnt4"));

// Methods
cls_MeshVS_SensitiveQuad.def("NbSubElements", (Standard_Integer (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::NbSubElements, "Returns the amount of sub-entities in sensitive");
cls_MeshVS_SensitiveQuad.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::GetConnected, "Returns a copy of this sensitive quadrangle");
cls_MeshVS_SensitiveQuad.def("Matches", (Standard_Boolean (MeshVS_SensitiveQuad::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitiveQuad::Matches, "Checks whether the box overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_SensitiveQuad.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitiveQuad::*)() const) &MeshVS_SensitiveQuad::CenterOfGeometry, "Returns center of the box");
cls_MeshVS_SensitiveQuad.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::BoundingBox, "Returns coordinates of the box");
cls_MeshVS_SensitiveQuad.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveQuad::get_type_name, "None");
cls_MeshVS_SensitiveQuad.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveQuad::get_type_descriptor, "None");
cls_MeshVS_SensitiveQuad.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveQuad::*)() const) &MeshVS_SensitiveQuad::DynamicType, "None");

// CLASS: MESHVS_SENSITIVESEGMENT
py::class_<MeshVS_SensitiveSegment, opencascade::handle<MeshVS_SensitiveSegment>, Select3D_SensitiveSegment> cls_MeshVS_SensitiveSegment(mod, "MeshVS_SensitiveSegment", "This class provides custom sensitive face, which will be selected if it center is in rectangle.");

// Constructors
cls_MeshVS_SensitiveSegment.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwner"), py::arg("theFirstPnt"), py::arg("theLastPnt"));

// Methods
cls_MeshVS_SensitiveSegment.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveSegment::get_type_name, "None");
cls_MeshVS_SensitiveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveSegment::get_type_descriptor, "None");
cls_MeshVS_SensitiveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveSegment::*)() const) &MeshVS_SensitiveSegment::DynamicType, "None");

// TYPEDEF: MESHVS_NODEPAIR
/*
bind_std::pair<int, int>(mod, "MeshVS_NodePair", py::module_local());
*/

// CLASS: MESHVS_SYMMETRICPAIRHASHER
py::class_<MeshVS_SymmetricPairHasher> cls_MeshVS_SymmetricPairHasher(mod, "MeshVS_SymmetricPairHasher", "Provides symmetric hash methods pair of integers.");

// Constructors
cls_MeshVS_SymmetricPairHasher.def(py::init<>());

// Methods
cls_MeshVS_SymmetricPairHasher.def_static("HashCode_", (Standard_Integer (*)(const MeshVS_NodePair &, const Standard_Integer)) &MeshVS_SymmetricPairHasher::HashCode, "Computes a hash code for the node pair, in the range [1, theUpperBound]", py::arg("theNodePair"), py::arg("theUpperBound"));
cls_MeshVS_SymmetricPairHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MeshVS_NodePair &, const MeshVS_NodePair &)) &MeshVS_SymmetricPairHasher::IsEqual, "None", py::arg("thePair1"), py::arg("thePair2"));

// CLASS: MESHVS_TEXTPRSBUILDER
py::class_<MeshVS_TextPrsBuilder, opencascade::handle<MeshVS_TextPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_TextPrsBuilder(mod, "MeshVS_TextPrsBuilder", "This class provides methods to create text data presentation. It store map of texts assigned with nodes or elements.");

// Constructors
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

// Methods
cls_MeshVS_TextPrsBuilder.def("Build", (void (MeshVS_TextPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_TextPrsBuilder::Build, "Builds presentation of text data", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("theDisplayMode"));
cls_MeshVS_TextPrsBuilder.def("GetTexts", (const MeshVS_DataMapOfIntegerAsciiString & (MeshVS_TextPrsBuilder::*)(const Standard_Boolean) const) &MeshVS_TextPrsBuilder::GetTexts, "Returns map of text assigned with nodes ( IsElement = False ) or elements ( IsElement = True )", py::arg("IsElement"));
cls_MeshVS_TextPrsBuilder.def("SetTexts", (void (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const MeshVS_DataMapOfIntegerAsciiString &)) &MeshVS_TextPrsBuilder::SetTexts, "Sets map of text assigned with nodes or elements", py::arg("IsElement"), py::arg("Map"));
cls_MeshVS_TextPrsBuilder.def("HasTexts", (Standard_Boolean (MeshVS_TextPrsBuilder::*)(const Standard_Boolean) const) &MeshVS_TextPrsBuilder::HasTexts, "Returns True if map isn't empty", py::arg("IsElement"));
cls_MeshVS_TextPrsBuilder.def("GetText", (Standard_Boolean (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, TCollection_AsciiString &) const) &MeshVS_TextPrsBuilder::GetText, "Returns text assigned with single node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Text"));
cls_MeshVS_TextPrsBuilder.def("SetText", (void (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, const TCollection_AsciiString &)) &MeshVS_TextPrsBuilder::SetText, "Sets text assigned with single node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Text"));
cls_MeshVS_TextPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_TextPrsBuilder::get_type_name, "None");
cls_MeshVS_TextPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_TextPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_TextPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_TextPrsBuilder::*)() const) &MeshVS_TextPrsBuilder::DynamicType, "None");

// CLASS: MESHVS_TOOL
py::class_<MeshVS_Tool> cls_MeshVS_Tool(mod, "MeshVS_Tool", "This class provides auxiliary methods to create differents aspects");

// Constructors
cls_MeshVS_Tool.def(py::init<>());

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

// CLASS: MESHVS_VECTORPRSBUILDER
py::class_<MeshVS_VectorPrsBuilder, opencascade::handle<MeshVS_VectorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_VectorPrsBuilder(mod, "MeshVS_VectorPrsBuilder", "This class provides methods to create vector data presentation. It store map of vectors assigned with nodes or elements. In simplified mode vectors draws with thickened ends instead of arrows");

// Constructors
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &, const Standard_Boolean>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"), py::arg("IsSimplePrs"));

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


}
