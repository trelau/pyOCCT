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
#include <VrmlData_Faceted.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Normal.hxx>
#include <VrmlData_Color.hxx>
#include <VrmlData_TextureCoordinate.hxx>
#include <VrmlData_Coordinate.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <gp_XYZ.hxx>
#include <Quantity_Color.hxx>
#include <TopoDS_TShape.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_IndexedFaceSet.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_IndexedFaceSet(py::module &mod){

py::class_<VrmlData_IndexedFaceSet, opencascade::handle<VrmlData_IndexedFaceSet>, VrmlData_Faceted> cls_VrmlData_IndexedFaceSet(mod, "VrmlData_IndexedFaceSet", "Implementation of IndexedFaceSet node");

// Constructors
cls_VrmlData_IndexedFaceSet.def(py::init<>());
cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"));
cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"));
cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"), py::arg("isConvex"));
cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"), py::arg("isConvex"), py::arg("theCreaseAngle"));

// Fields

// Methods
cls_VrmlData_IndexedFaceSet.def("Normals", (const opencascade::handle<VrmlData_Normal> & (VrmlData_IndexedFaceSet::*)() const) &VrmlData_IndexedFaceSet::Normals, "Query the Normals.");
cls_VrmlData_IndexedFaceSet.def("Colors", (const opencascade::handle<VrmlData_Color> & (VrmlData_IndexedFaceSet::*)() const) &VrmlData_IndexedFaceSet::Colors, "Query the Colors.");
cls_VrmlData_IndexedFaceSet.def("TextureCoords", (const opencascade::handle<VrmlData_TextureCoordinate> & (VrmlData_IndexedFaceSet::*)() const) &VrmlData_IndexedFaceSet::TextureCoords, "Query the Texture Coordinates.");
cls_VrmlData_IndexedFaceSet.def("Coordinates", (const opencascade::handle<VrmlData_Coordinate> & (VrmlData_IndexedFaceSet::*)() const) &VrmlData_IndexedFaceSet::Coordinates, "Query the Coordinates.");
// cls_VrmlData_IndexedFaceSet.def("Polygons", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const) &VrmlData_IndexedFaceSet::Polygons, "Query the array of polygons", py::arg("arrPolygons"));
// cls_VrmlData_IndexedFaceSet.def("Polygon", (Standard_Integer (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer *&)) &VrmlData_IndexedFaceSet::Polygon, "Query one polygon.", py::arg("iFace"), py::arg("outIndice"));
cls_VrmlData_IndexedFaceSet.def("SetCoordinates", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Coordinate> &)) &VrmlData_IndexedFaceSet::SetCoordinates, "Set the nodes", py::arg("theCoord"));
// cls_VrmlData_IndexedFaceSet.def("SetPolygons", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetPolygons, "Set the polygons", py::arg("nPolygons"), py::arg("thePolygons"));
// cls_VrmlData_IndexedFaceSet.def("ArrayNormalInd", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const) &VrmlData_IndexedFaceSet::ArrayNormalInd, "Query the array of normal indice", py::arg("arrNormalInd"));
// cls_VrmlData_IndexedFaceSet.def("IndiceNormals", (Standard_Integer (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer *&)) &VrmlData_IndexedFaceSet::IndiceNormals, "Query normals indice for one face. This method should be called after checking myArrNormalInd != NULL, otherwise exception will be thrown.", py::arg("iFace"), py::arg("outIndice"));
// cls_VrmlData_IndexedFaceSet.def("GetNormal", (gp_XYZ (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer)) &VrmlData_IndexedFaceSet::GetNormal, "Query a normal for one node in the given element. The normal is interpreted according to fields myNormals, myArrNormalInd, myNormalPerVertex, as defined in VRML 2.0.", py::arg("iFace"), py::arg("iVertex"));
// cls_VrmlData_IndexedFaceSet.def("SetNormalInd", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetNormalInd, "Set the normals array of indice", py::arg("nIndice"), py::arg("theIndice"));
cls_VrmlData_IndexedFaceSet.def("SetNormals", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Normal> &)) &VrmlData_IndexedFaceSet::SetNormals, "Set the normals node", py::arg("theNormals"));
cls_VrmlData_IndexedFaceSet.def("SetNormalPerVertex", (void (VrmlData_IndexedFaceSet::*)(const Standard_Boolean)) &VrmlData_IndexedFaceSet::SetNormalPerVertex, "Set the boolean value 'normalPerVertex'", py::arg("isNormalPerVertex"));
// cls_VrmlData_IndexedFaceSet.def("ArrayColorInd", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const) &VrmlData_IndexedFaceSet::ArrayColorInd, "Query the array of color indice", py::arg("arrColorInd"));
cls_VrmlData_IndexedFaceSet.def("GetColor", (Quantity_Color (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer)) &VrmlData_IndexedFaceSet::GetColor, "Query a color for one node in the given element. The color is interpreted according to fields myColors, myArrColorInd, myColorPerVertex, as defined in VRML 2.0.", py::arg("iFace"), py::arg("iVertex"));
// cls_VrmlData_IndexedFaceSet.def("SetColorInd", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetColorInd, "Set the colors array of indice", py::arg("nIndice"), py::arg("theIndice"));
cls_VrmlData_IndexedFaceSet.def("SetColors", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Color> &)) &VrmlData_IndexedFaceSet::SetColors, "Set the Color node", py::arg("theColors"));
cls_VrmlData_IndexedFaceSet.def("SetColorPerVertex", (void (VrmlData_IndexedFaceSet::*)(const Standard_Boolean)) &VrmlData_IndexedFaceSet::SetColorPerVertex, "Set the boolean value 'colorPerVertex'", py::arg("isColorPerVertex"));
// cls_VrmlData_IndexedFaceSet.def("ArrayTextureCoordInd", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const) &VrmlData_IndexedFaceSet::ArrayTextureCoordInd, "Query the array of texture coordinate indice", py::arg("arrTextureCoordInd"));
// cls_VrmlData_IndexedFaceSet.def("SetTextureCoordInd", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetTextureCoordInd, "Set the TexCoordiante array of indice", py::arg("nIndice"), py::arg("theIndice"));
cls_VrmlData_IndexedFaceSet.def("SetTextureCoords", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_TextureCoordinate> &)) &VrmlData_IndexedFaceSet::SetTextureCoords, "Set the Texture Coordinate node", py::arg("tc"));
cls_VrmlData_IndexedFaceSet.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_IndexedFaceSet::*)()) &VrmlData_IndexedFaceSet::TShape, "Query the shape. This method checks the flag myIsModified; if True it should rebuild the shape presentation.");
cls_VrmlData_IndexedFaceSet.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_IndexedFaceSet::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_IndexedFaceSet.def("Read", (VrmlData_ErrorStatus (VrmlData_IndexedFaceSet::*)(VrmlData_InBuffer &)) &VrmlData_IndexedFaceSet::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_IndexedFaceSet.def("Write", (VrmlData_ErrorStatus (VrmlData_IndexedFaceSet::*)(const char *) const) &VrmlData_IndexedFaceSet::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_IndexedFaceSet.def("IsDefault", (Standard_Boolean (VrmlData_IndexedFaceSet::*)() const) &VrmlData_IndexedFaceSet::IsDefault, "Returns True if the node is default, so that it should not be written.");
cls_VrmlData_IndexedFaceSet.def_static("get_type_name_", (const char * (*)()) &VrmlData_IndexedFaceSet::get_type_name, "None");
cls_VrmlData_IndexedFaceSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_IndexedFaceSet::get_type_descriptor, "None");
cls_VrmlData_IndexedFaceSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_IndexedFaceSet::*)() const) &VrmlData_IndexedFaceSet::DynamicType, "None");

// Enums

}