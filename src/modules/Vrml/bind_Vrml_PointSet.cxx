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
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_PointSet.hxx>

void bind_Vrml_PointSet(py::module &mod){

py::class_<Vrml_PointSet, std::unique_ptr<Vrml_PointSet, Deleter<Vrml_PointSet>>> cls_Vrml_PointSet(mod, "Vrml_PointSet", "defines a PointSet node of VRML specifying geometry shapes.");

// Constructors
cls_Vrml_PointSet.def(py::init<>());
cls_Vrml_PointSet.def(py::init<const Standard_Integer>(), py::arg("aStartIndex"));
cls_Vrml_PointSet.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aStartIndex"), py::arg("aNumPoints"));

// Fields

// Methods
// cls_Vrml_PointSet.def_static("operator new_", (void * (*)(size_t)) &Vrml_PointSet::operator new, "None", py::arg("theSize"));
// cls_Vrml_PointSet.def_static("operator delete_", (void (*)(void *)) &Vrml_PointSet::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_PointSet.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_PointSet::operator new[], "None", py::arg("theSize"));
// cls_Vrml_PointSet.def_static("operator delete[]_", (void (*)(void *)) &Vrml_PointSet::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_PointSet.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_PointSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_PointSet.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_PointSet::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_PointSet.def("SetStartIndex", (void (Vrml_PointSet::*)(const Standard_Integer)) &Vrml_PointSet::SetStartIndex, "None", py::arg("aStartIndex"));
cls_Vrml_PointSet.def("StartIndex", (Standard_Integer (Vrml_PointSet::*)() const) &Vrml_PointSet::StartIndex, "None");
cls_Vrml_PointSet.def("SetNumPoints", (void (Vrml_PointSet::*)(const Standard_Integer)) &Vrml_PointSet::SetNumPoints, "None", py::arg("aNumPoints"));
cls_Vrml_PointSet.def("NumPoints", (Standard_Integer (Vrml_PointSet::*)() const) &Vrml_PointSet::NumPoints, "None");
cls_Vrml_PointSet.def("Print", (Standard_OStream & (Vrml_PointSet::*)(Standard_OStream &) const) &Vrml_PointSet::Print, "None", py::arg("anOStream"));

// Enums

}