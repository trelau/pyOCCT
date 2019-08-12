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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Transformation.hxx>
#include <GC_MakeRotation.hxx>

void bind_GC_MakeRotation(py::module &mod){

py::class_<GC_MakeRotation, std::unique_ptr<GC_MakeRotation, Deleter<GC_MakeRotation>>> cls_GC_MakeRotation(mod, "GC_MakeRotation", "This class implements elementary construction algorithms for a rotation in 3D space. The result is a Geom_Transformation transformation. A MakeRotation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeRotation.def(py::init<const gp_Lin &, const Standard_Real>(), py::arg("Line"), py::arg("Angle"));
cls_GC_MakeRotation.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Angle"));
cls_GC_MakeRotation.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Point"), py::arg("Direc"), py::arg("Angle"));

// Fields

// Methods
// cls_GC_MakeRotation.def_static("operator new_", (void * (*)(size_t)) &GC_MakeRotation::operator new, "None", py::arg("theSize"));
// cls_GC_MakeRotation.def_static("operator delete_", (void (*)(void *)) &GC_MakeRotation::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeRotation.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeRotation::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeRotation.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeRotation::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeRotation.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeRotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeRotation.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeRotation::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeRotation.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeRotation::*)() const) &GC_MakeRotation::Value, "Returns the constructed transformation.");

// Enums

}