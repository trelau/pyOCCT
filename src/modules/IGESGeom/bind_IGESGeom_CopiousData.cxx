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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <IGESGeom_CopiousData.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_CopiousData(py::module &mod){

py::class_<IGESGeom_CopiousData, opencascade::handle<IGESGeom_CopiousData>, IGESData_IGESEntity> cls_IGESGeom_CopiousData(mod, "IGESGeom_CopiousData", "defines IGESCopiousData, Type <106> Form <1-3,11-13,63> in package IGESGeom This entity stores data points in the form of pairs, triples, or sextuples. An interpretation flag value signifies which of these forms is being used.");

// Constructors
cls_IGESGeom_CopiousData.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_CopiousData.def("Init", (void (IGESGeom_CopiousData::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColStd_HArray1OfReal> &)) &IGESGeom_CopiousData::Init, "This method is used to set the fields of the class CopiousData - aDataType : Specifies whether data is a pair or a triple or a sextuple. - aZPlane : Common Z value for all points if datatype = 1 - allData : Data to be read in groups of 2, 3 or 6", py::arg("aDataType"), py::arg("aZPlane"), py::arg("allData"));
cls_IGESGeom_CopiousData.def("SetPolyline", (void (IGESGeom_CopiousData::*)(const Standard_Boolean)) &IGESGeom_CopiousData::SetPolyline, "Sets Copious Data to be a Polyline if <mode> is True (Form = 11-12-13) or a Set of Points else (Form 1-2-3)", py::arg("mode"));
cls_IGESGeom_CopiousData.def("SetClosedPath2D", (void (IGESGeom_CopiousData::*)()) &IGESGeom_CopiousData::SetClosedPath2D, "Sets Copious Data to be a Closed Path 2D (Form 63) Warning : DataType is not checked and must be set to ONE by Init");
cls_IGESGeom_CopiousData.def("IsPointSet", (Standard_Boolean (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::IsPointSet, "Returns True if <me> is a Set of Points (Form 1-2-3)");
cls_IGESGeom_CopiousData.def("IsPolyline", (Standard_Boolean (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::IsPolyline, "Returns True if <me> is a Polyline (Form 11-12-13)");
cls_IGESGeom_CopiousData.def("IsClosedPath2D", (Standard_Boolean (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::IsClosedPath2D, "Returns True if <me> is a Closed Path 2D (Form 63)");
cls_IGESGeom_CopiousData.def("DataType", (Standard_Integer (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::DataType, "returns data type 1 = XY ( with common Z given by plane) 2 = XYZ ( point) 3 = XYZ + Vec(XYZ) (point + normal vector)");
cls_IGESGeom_CopiousData.def("NbPoints", (Standard_Integer (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::NbPoints, "returns the number of tuples");
cls_IGESGeom_CopiousData.def("Data", (Standard_Real (IGESGeom_CopiousData::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_CopiousData::Data, "Returns an individual Data, given the N0 of the Point and the B0 of the Coordinate (according DataType)", py::arg("NumPoint"), py::arg("NumData"));
cls_IGESGeom_CopiousData.def("ZPlane", (Standard_Real (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::ZPlane, "If datatype = 1, then returns common z value for all data else returns 0");
cls_IGESGeom_CopiousData.def("Point", (gp_Pnt (IGESGeom_CopiousData::*)(const Standard_Integer) const) &IGESGeom_CopiousData::Point, "returns the coordinates of the point specified by the anIndex raises exception if anIndex <= 0 or anIndex > NbPoints()", py::arg("anIndex"));
cls_IGESGeom_CopiousData.def("TransformedPoint", (gp_Pnt (IGESGeom_CopiousData::*)(const Standard_Integer) const) &IGESGeom_CopiousData::TransformedPoint, "returns the coordinates of the point specified by the anIndex after applying Transf. Matrix raises exception if anIndex <= 0 or anIndex > NbPoints()", py::arg("anIndex"));
cls_IGESGeom_CopiousData.def("Vector", (gp_Vec (IGESGeom_CopiousData::*)(const Standard_Integer) const) &IGESGeom_CopiousData::Vector, "returns i, j, k values if 3-tuple else returns (0, 0, 0) raises exception if anIndex <= 0 or anIndex > NbPoints()", py::arg("anIndex"));
cls_IGESGeom_CopiousData.def("TransformedVector", (gp_Vec (IGESGeom_CopiousData::*)(const Standard_Integer) const) &IGESGeom_CopiousData::TransformedVector, "returns transformed vector if 3-tuple else returns (0, 0, 0) raises exception if anIndex <= 0 or anIndex > NbPoints()", py::arg("anIndex"));
cls_IGESGeom_CopiousData.def_static("get_type_name_", (const char * (*)()) &IGESGeom_CopiousData::get_type_name, "None");
cls_IGESGeom_CopiousData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_CopiousData::get_type_descriptor, "None");
cls_IGESGeom_CopiousData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_CopiousData::*)() const) &IGESGeom_CopiousData::DynamicType, "None");

// Enums

}