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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Transformation.hxx>
#include <GCE2d_MakeRotation.hxx>

void bind_GCE2d_MakeRotation(py::module &mod){

py::class_<GCE2d_MakeRotation, std::unique_ptr<GCE2d_MakeRotation>> cls_GCE2d_MakeRotation(mod, "GCE2d_MakeRotation", "This class implements an elementary construction algorithm for a rotation in 2D space. The result is a Geom2d_Transformation transformation. A MakeRotation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GCE2d_MakeRotation.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Point"), py::arg("Angle"));

// Fields

// Methods
// cls_GCE2d_MakeRotation.def_static("operator new_", (void * (*)(size_t)) &GCE2d_MakeRotation::operator new, "None", py::arg("theSize"));
// cls_GCE2d_MakeRotation.def_static("operator delete_", (void (*)(void *)) &GCE2d_MakeRotation::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_MakeRotation.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_MakeRotation::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_MakeRotation.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_MakeRotation::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_MakeRotation.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_MakeRotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_MakeRotation.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_MakeRotation::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_MakeRotation.def("Value", (const opencascade::handle<Geom2d_Transformation> & (GCE2d_MakeRotation::*)() const) &GCE2d_MakeRotation::Value, "Returns the constructed transformation.");

// Enums

}