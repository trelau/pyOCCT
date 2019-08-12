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
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <math_SingularMatrix.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_math_SingularMatrix(py::module &mod){

py::class_<math_SingularMatrix, opencascade::handle<math_SingularMatrix>, Standard_Failure> cls_math_SingularMatrix(mod, "math_SingularMatrix", "None");

// Constructors
cls_math_SingularMatrix.def(py::init<>());
cls_math_SingularMatrix.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_math_SingularMatrix.def_static("Raise_", (void (*)(const Standard_CString)) &math_SingularMatrix::Raise, "None", py::arg("theMessage"));
cls_math_SingularMatrix.def_static("Raise_", (void (*)(Standard_SStream &)) &math_SingularMatrix::Raise, "None", py::arg("theMessage"));
cls_math_SingularMatrix.def_static("NewInstance_", (opencascade::handle<math_SingularMatrix> (*)(const Standard_CString)) &math_SingularMatrix::NewInstance, "None", py::arg("theMessage"));
cls_math_SingularMatrix.def_static("get_type_name_", (const char * (*)()) &math_SingularMatrix::get_type_name, "None");
cls_math_SingularMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &math_SingularMatrix::get_type_descriptor, "None");
cls_math_SingularMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (math_SingularMatrix::*)() const) &math_SingularMatrix::DynamicType, "None");

// Enums

}