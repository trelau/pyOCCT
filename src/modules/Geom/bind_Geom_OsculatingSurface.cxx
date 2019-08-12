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
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_OsculatingSurface.hxx>
#include <Standard_Type.hxx>
#include <GeomAbs_IsoType.hxx>
#include <Geom_SequenceOfBSplineSurface.hxx>
#include <Geom_HSequenceOfBSplineSurface.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TColStd_Array1OfBoolean.hxx>

void bind_Geom_OsculatingSurface(py::module &mod){

py::class_<Geom_OsculatingSurface, opencascade::handle<Geom_OsculatingSurface>, Standard_Transient> cls_Geom_OsculatingSurface(mod, "Geom_OsculatingSurface", "None");

// Constructors
cls_Geom_OsculatingSurface.def(py::init<>());
cls_Geom_OsculatingSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("BS"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom_OsculatingSurface.def_static("operator new_", (void * (*)(size_t)) &Geom_OsculatingSurface::operator new, "None", py::arg("theSize"));
// cls_Geom_OsculatingSurface.def_static("operator delete_", (void (*)(void *)) &Geom_OsculatingSurface::operator delete, "None", py::arg("theAddress"));
// cls_Geom_OsculatingSurface.def_static("operator new[]_", (void * (*)(size_t)) &Geom_OsculatingSurface::operator new[], "None", py::arg("theSize"));
// cls_Geom_OsculatingSurface.def_static("operator delete[]_", (void (*)(void *)) &Geom_OsculatingSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Geom_OsculatingSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Geom_OsculatingSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom_OsculatingSurface.def_static("operator delete_", (void (*)(void *, void *)) &Geom_OsculatingSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom_OsculatingSurface.def("Init", (void (Geom_OsculatingSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &Geom_OsculatingSurface::Init, "None", py::arg("BS"), py::arg("Tol"));
cls_Geom_OsculatingSurface.def("BasisSurface", (opencascade::handle<Geom_Surface> (Geom_OsculatingSurface::*)() const) &Geom_OsculatingSurface::BasisSurface, "None");
cls_Geom_OsculatingSurface.def("Tolerance", (Standard_Real (Geom_OsculatingSurface::*)() const) &Geom_OsculatingSurface::Tolerance, "None");
cls_Geom_OsculatingSurface.def("UOscSurf", [](Geom_OsculatingSurface &self, const Standard_Real U, const Standard_Real V, Standard_Boolean & t, opencascade::handle<Geom_BSplineSurface> & L){ Standard_Boolean rv = self.UOscSurf(U, V, t, L); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, t); }, "if Standard_True, L is the local osculating surface along U at the point U,V.", py::arg("U"), py::arg("V"), py::arg("t"), py::arg("L"));
cls_Geom_OsculatingSurface.def("VOscSurf", [](Geom_OsculatingSurface &self, const Standard_Real U, const Standard_Real V, Standard_Boolean & t, opencascade::handle<Geom_BSplineSurface> & L){ Standard_Boolean rv = self.VOscSurf(U, V, t, L); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, t); }, "if Standard_True, L is the local osculating surface along V at the point U,V.", py::arg("U"), py::arg("V"), py::arg("t"), py::arg("L"));
cls_Geom_OsculatingSurface.def_static("get_type_name_", (const char * (*)()) &Geom_OsculatingSurface::get_type_name, "None");
cls_Geom_OsculatingSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_OsculatingSurface::get_type_descriptor, "None");
cls_Geom_OsculatingSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_OsculatingSurface::*)() const) &Geom_OsculatingSurface::DynamicType, "None");

// Enums

}