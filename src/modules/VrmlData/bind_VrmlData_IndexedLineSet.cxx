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
#include <VrmlData_Geometry.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Coordinate.hxx>
#include <VrmlData_Color.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Quantity_Color.hxx>
#include <TopoDS_TShape.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_IndexedLineSet.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_IndexedLineSet(py::module &mod){

py::class_<VrmlData_IndexedLineSet, opencascade::handle<VrmlData_IndexedLineSet>, VrmlData_Geometry> cls_VrmlData_IndexedLineSet(mod, "VrmlData_IndexedLineSet", "Data type to store a set of polygons.");

// Constructors
cls_VrmlData_IndexedLineSet.def(py::init<>());
cls_VrmlData_IndexedLineSet.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_IndexedLineSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isColorPerVertex"));

// Fields

// Methods
cls_VrmlData_IndexedLineSet.def("Coordinates", (const opencascade::handle<VrmlData_Coordinate> & (VrmlData_IndexedLineSet::*)() const) &VrmlData_IndexedLineSet::Coordinates, "Query the Coordinates.");
cls_VrmlData_IndexedLineSet.def("SetCoordinates", (void (VrmlData_IndexedLineSet::*)(const opencascade::handle<VrmlData_Coordinate> &)) &VrmlData_IndexedLineSet::SetCoordinates, "Set the nodes", py::arg("theCoord"));
cls_VrmlData_IndexedLineSet.def("Colors", (const opencascade::handle<VrmlData_Color> & (VrmlData_IndexedLineSet::*)() const) &VrmlData_IndexedLineSet::Colors, "Query the Colors.");
cls_VrmlData_IndexedLineSet.def("SetColors", (void (VrmlData_IndexedLineSet::*)(const opencascade::handle<VrmlData_Color> &)) &VrmlData_IndexedLineSet::SetColors, "Set the Color node", py::arg("theColors"));
// cls_VrmlData_IndexedLineSet.def("Polygons", (size_t (VrmlData_IndexedLineSet::*)(const Standard_Integer **&) const) &VrmlData_IndexedLineSet::Polygons, "Query the array of polygons", py::arg("arrPolygons"));
// cls_VrmlData_IndexedLineSet.def("Polygon", (Standard_Integer (VrmlData_IndexedLineSet::*)(const Standard_Integer, const Standard_Integer *&)) &VrmlData_IndexedLineSet::Polygon, "Query one polygon.", py::arg("iPolygon"), py::arg("outIndice"));
// cls_VrmlData_IndexedLineSet.def("SetPolygons", (void (VrmlData_IndexedLineSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedLineSet::SetPolygons, "Set the polygons", py::arg("nPolygons"), py::arg("thePolygons"));
// cls_VrmlData_IndexedLineSet.def("ArrayColorInd", (size_t (VrmlData_IndexedLineSet::*)(const Standard_Integer **&) const) &VrmlData_IndexedLineSet::ArrayColorInd, "Query the array of color indice", py::arg("arrColorInd"));
cls_VrmlData_IndexedLineSet.def("GetColor", (Quantity_Color (VrmlData_IndexedLineSet::*)(const Standard_Integer, const Standard_Integer)) &VrmlData_IndexedLineSet::GetColor, "Query a color for one node in the given element. The color is interpreted according to fields myColors, myArrColorInd, myColorPerVertex, as defined in VRML 2.0.", py::arg("iFace"), py::arg("iVertex"));
// cls_VrmlData_IndexedLineSet.def("SetColorInd", (void (VrmlData_IndexedLineSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedLineSet::SetColorInd, "Set the colors array of indice", py::arg("nIndice"), py::arg("theIndice"));
cls_VrmlData_IndexedLineSet.def("SetColorPerVertex", (void (VrmlData_IndexedLineSet::*)(const Standard_Boolean)) &VrmlData_IndexedLineSet::SetColorPerVertex, "Set the boolean value 'colorPerVertex'", py::arg("isColorPerVertex"));
cls_VrmlData_IndexedLineSet.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_IndexedLineSet::*)()) &VrmlData_IndexedLineSet::TShape, "Query the shape. This method checks the flag myIsModified; if True it should rebuild the shape presentation.");
cls_VrmlData_IndexedLineSet.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_IndexedLineSet::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_IndexedLineSet::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_IndexedLineSet.def("Read", (VrmlData_ErrorStatus (VrmlData_IndexedLineSet::*)(VrmlData_InBuffer &)) &VrmlData_IndexedLineSet::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_IndexedLineSet.def("Write", (VrmlData_ErrorStatus (VrmlData_IndexedLineSet::*)(const char *) const) &VrmlData_IndexedLineSet::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_IndexedLineSet.def("IsDefault", (Standard_Boolean (VrmlData_IndexedLineSet::*)() const) &VrmlData_IndexedLineSet::IsDefault, "Returns True if the node is default, so that it should not be written.");
cls_VrmlData_IndexedLineSet.def_static("get_type_name_", (const char * (*)()) &VrmlData_IndexedLineSet::get_type_name, "None");
cls_VrmlData_IndexedLineSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_IndexedLineSet::get_type_descriptor, "None");
cls_VrmlData_IndexedLineSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_IndexedLineSet::*)() const) &VrmlData_IndexedLineSet::DynamicType, "None");

// Enums

}