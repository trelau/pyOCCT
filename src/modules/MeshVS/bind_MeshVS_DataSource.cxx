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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <MeshVS_EntityType.hxx>
#include <Standard_Handle.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Bnd_Box.hxx>
#include <MeshVS_Mesh.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Bnd_Box2d.hxx>
#include <MeshVS_DataSource.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_DataSource(py::module &mod){

py::class_<MeshVS_DataSource, opencascade::handle<MeshVS_DataSource>, Standard_Transient> cls_MeshVS_DataSource(mod, "MeshVS_DataSource", "The deferred class using for the following tasks: 1) Receiving geometry data about single element of node by its number; 2) Receiving type of element or node by its number; 3) Receiving topological information about links between element and nodes it consist of; 4) Receiving information about what element cover this node; 5) Receiving information about all nodes and elements the object consist of 6) Activation of advanced mesh selection. In the advanced mesh selection mode there is created: - one owner for the whole mesh and for all selection modes - one sensitive entity for the whole mesh and for each selection mode Receiving of IDs of detected entities (nodes and elements) in a viewer is achieved by implementation of a group of methods GetDetectedEntities.");

// Fields

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

// Enums

}