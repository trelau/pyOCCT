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
#include <IGESData_TransfEntity.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_GTrsf.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_TransformationMatrix(py::module &mod){

py::class_<IGESGeom_TransformationMatrix, opencascade::handle<IGESGeom_TransformationMatrix>, IGESData_TransfEntity> cls_IGESGeom_TransformationMatrix(mod, "IGESGeom_TransformationMatrix", "defines IGESTransformationMatrix, Type <124> Form <0> in package IGESGeom The transformation matrix entity transforms three-row column vectors by means of matrix multiplication and then a vector addition. This entity can be considered as an 'operator' entity in that it starts with the input vector, operates on it as described above, and produces the output vector.");

// Constructors
cls_IGESGeom_TransformationMatrix.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_TransformationMatrix.def("Init", (void (IGESGeom_TransformationMatrix::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &IGESGeom_TransformationMatrix::Init, "This method is used to set the fields of the class TransformationMatrix - aMatrix : 3 x 4 array containing elements of the transformation matrix raises exception if aMatrix is not 3 x 4 array", py::arg("aMatrix"));
cls_IGESGeom_TransformationMatrix.def("SetFormNumber", (void (IGESGeom_TransformationMatrix::*)(const Standard_Integer)) &IGESGeom_TransformationMatrix::SetFormNumber, "Changes FormNumber (indicates the Type of Transf : Transformation 0-1 or Coordinate System 10-11-12) Error if not in ranges [0-1] or [10-12]", py::arg("form"));
cls_IGESGeom_TransformationMatrix.def("Data", (Standard_Real (IGESGeom_TransformationMatrix::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_TransformationMatrix::Data, "returns individual Data Errro if I not in [1-3] or J not in [1-4]", py::arg("I"), py::arg("J"));
cls_IGESGeom_TransformationMatrix.def("Value", (gp_GTrsf (IGESGeom_TransformationMatrix::*)() const) &IGESGeom_TransformationMatrix::Value, "returns the transformation matrix 4th row elements of GTrsf will always be 0, 0, 0, 1 (not defined)");
cls_IGESGeom_TransformationMatrix.def_static("get_type_name_", (const char * (*)()) &IGESGeom_TransformationMatrix::get_type_name, "None");
cls_IGESGeom_TransformationMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_TransformationMatrix::get_type_descriptor, "None");
cls_IGESGeom_TransformationMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_TransformationMatrix::*)() const) &IGESGeom_TransformationMatrix::DynamicType, "None");

// Enums

}