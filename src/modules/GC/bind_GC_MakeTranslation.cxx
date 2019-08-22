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
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Transformation.hxx>
#include <GC_MakeTranslation.hxx>

void bind_GC_MakeTranslation(py::module &mod){

py::class_<GC_MakeTranslation> cls_GC_MakeTranslation(mod, "GC_MakeTranslation", "This class implements elementary construction algorithms for a translation in 3D space. The result is a Geom_Transformation transformation. A MakeTranslation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeTranslation.def(py::init<const gp_Vec &>(), py::arg("Vect"));
cls_GC_MakeTranslation.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("Point1"), py::arg("Point2"));

// Fields

// Methods
// cls_GC_MakeTranslation.def_static("operator new_", (void * (*)(size_t)) &GC_MakeTranslation::operator new, "None", py::arg("theSize"));
// cls_GC_MakeTranslation.def_static("operator delete_", (void (*)(void *)) &GC_MakeTranslation::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeTranslation.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeTranslation::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeTranslation.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeTranslation::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeTranslation.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeTranslation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeTranslation.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeTranslation::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeTranslation.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeTranslation::*)() const) &GC_MakeTranslation::Value, "Returns the constructed transformation.");

// Enums

}