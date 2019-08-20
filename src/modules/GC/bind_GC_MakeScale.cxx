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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Transformation.hxx>
#include <GC_MakeScale.hxx>

void bind_GC_MakeScale(py::module &mod){

py::class_<GC_MakeScale, std::unique_ptr<GC_MakeScale>> cls_GC_MakeScale(mod, "GC_MakeScale", "This class implements an elementary construction algorithm for a scaling transformation in 3D space. The result is a Geom_Transformation transformation (a scaling transformation with the center point <Point> and the scaling value <Scale>). A MakeScale object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeScale.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Point"), py::arg("Scale"));

// Fields

// Methods
// cls_GC_MakeScale.def_static("operator new_", (void * (*)(size_t)) &GC_MakeScale::operator new, "None", py::arg("theSize"));
// cls_GC_MakeScale.def_static("operator delete_", (void (*)(void *)) &GC_MakeScale::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeScale.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeScale::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeScale.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeScale::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeScale.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeScale::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeScale.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeScale::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeScale.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeScale::*)() const) &GC_MakeScale::Value, "Returns the constructed transformation.");

// Enums

}