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
#include <Standard_TypeDef.hxx>
#include <Standard_ConstructionError.hxx>
#include <Select3D_Pnt.hxx>
#include <Standard_OutOfRange.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_PointData.hxx>

void bind_Select3D_PointData(py::module &mod){

py::class_<Select3D_PointData, std::unique_ptr<Select3D_PointData, Deleter<Select3D_PointData>>> cls_Select3D_PointData(mod, "Select3D_PointData", "None");

// Constructors
cls_Select3D_PointData.def(py::init<const Standard_Integer>(), py::arg("theNbPoints"));

// Fields

// Methods
cls_Select3D_PointData.def("SetPnt", (void (Select3D_PointData::*)(const Standard_Integer, const Select3D_Pnt &)) &Select3D_PointData::SetPnt, "None", py::arg("theIndex"), py::arg("theValue"));
cls_Select3D_PointData.def("SetPnt", (void (Select3D_PointData::*)(const Standard_Integer, const gp_Pnt &)) &Select3D_PointData::SetPnt, "None", py::arg("theIndex"), py::arg("theValue"));
cls_Select3D_PointData.def("Pnt", (const Select3D_Pnt & (Select3D_PointData::*)(const Standard_Integer) const) &Select3D_PointData::Pnt, "None", py::arg("theIndex"));
cls_Select3D_PointData.def("Pnt3d", (gp_Pnt (Select3D_PointData::*)(const Standard_Integer) const) &Select3D_PointData::Pnt3d, "None", py::arg("theIndex"));
cls_Select3D_PointData.def("Size", (Standard_Integer (Select3D_PointData::*)() const) &Select3D_PointData::Size, "None");

// Enums

}