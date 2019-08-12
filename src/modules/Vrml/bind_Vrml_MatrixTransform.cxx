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
#include <Standard.hxx>
#include <gp_Trsf.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_MatrixTransform.hxx>

void bind_Vrml_MatrixTransform(py::module &mod){

py::class_<Vrml_MatrixTransform, std::unique_ptr<Vrml_MatrixTransform, Deleter<Vrml_MatrixTransform>>> cls_Vrml_MatrixTransform(mod, "Vrml_MatrixTransform", "defines a MatrixTransform node of VRML specifying matrix and transform properties. This node defines 3D transformation with a 4 by 4 matrix. By default : a11=1 a12=0 a13=0 a14=0 a21=0 a22=1 a23=0 a24=0 a31=0 a32=0 a33=1 a34=0 a41=0 a42=0 a43=0 a44=1 It is written to the file in row-major order as 16 Real numbers separated by whitespace. For example , matrix expressing a translation of 7.3 units along the X axis is written as: 1 0 0 0 0 1 0 0 0 0 1 0 7.3 0 0 1");

// Constructors
cls_Vrml_MatrixTransform.def(py::init<>());
cls_Vrml_MatrixTransform.def(py::init<const gp_Trsf &>(), py::arg("aMatrix"));

// Fields

// Methods
// cls_Vrml_MatrixTransform.def_static("operator new_", (void * (*)(size_t)) &Vrml_MatrixTransform::operator new, "None", py::arg("theSize"));
// cls_Vrml_MatrixTransform.def_static("operator delete_", (void (*)(void *)) &Vrml_MatrixTransform::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_MatrixTransform.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_MatrixTransform::operator new[], "None", py::arg("theSize"));
// cls_Vrml_MatrixTransform.def_static("operator delete[]_", (void (*)(void *)) &Vrml_MatrixTransform::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_MatrixTransform.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_MatrixTransform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_MatrixTransform.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_MatrixTransform::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_MatrixTransform.def("SetMatrix", (void (Vrml_MatrixTransform::*)(const gp_Trsf &)) &Vrml_MatrixTransform::SetMatrix, "None", py::arg("aMatrix"));
cls_Vrml_MatrixTransform.def("Matrix", (gp_Trsf (Vrml_MatrixTransform::*)() const) &Vrml_MatrixTransform::Matrix, "None");
cls_Vrml_MatrixTransform.def("Print", (Standard_OStream & (Vrml_MatrixTransform::*)(Standard_OStream &) const) &Vrml_MatrixTransform::Print, "None", py::arg("anOStream"));

// Enums

}