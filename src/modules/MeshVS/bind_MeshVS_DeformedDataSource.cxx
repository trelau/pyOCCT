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
#include <MeshVS_DataSource.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <MeshVS_EntityType.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <MeshVS_DataMapOfIntegerVector.hxx>
#include <gp_Vec.hxx>
#include <MeshVS_DeformedDataSource.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_DeformedDataSource(py::module &mod){

py::class_<MeshVS_DeformedDataSource, opencascade::handle<MeshVS_DeformedDataSource>, MeshVS_DataSource> cls_MeshVS_DeformedDataSource(mod, "MeshVS_DeformedDataSource", "The class provides default class which helps to represent node displacements by deformed mesh This class has an internal handle to canonical non-deformed mesh data source and map of displacement vectors. The displacement can be magnified to useful size. All methods is implemented with calling the corresponding methods of non-deformed data source.");

// Constructors
cls_MeshVS_DeformedDataSource.def(py::init<const opencascade::handle<MeshVS_DataSource> &, const Standard_Real>(), py::arg("theNonDeformDS"), py::arg("theMagnify"));

// Fields

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

// Enums

}