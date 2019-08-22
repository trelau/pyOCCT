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
#include <gce_Root.hxx>
#include <Standard.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Parab.hxx>
#include <gce_MakeParab.hxx>

void bind_gce_MakeParab(py::module &mod){

py::class_<gce_MakeParab, gce_Root> cls_gce_MakeParab(mod, "gce_MakeParab", "This class implements the following algorithms used to create Parab from gp. Defines the parabola in the parameterization range : ]-infinite, +infinite[ The vertex of the parabola is the 'Location' point of the local coordinate system (axis placement) of the parabola.");

// Constructors
cls_gce_MakeParab.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Focal"));
cls_gce_MakeParab.def(py::init<const gp_Ax1 &, const gp_Pnt &>(), py::arg("D"), py::arg("F"));

// Fields

// Methods
// cls_gce_MakeParab.def_static("operator new_", (void * (*)(size_t)) &gce_MakeParab::operator new, "None", py::arg("theSize"));
// cls_gce_MakeParab.def_static("operator delete_", (void (*)(void *)) &gce_MakeParab::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeParab.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeParab::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeParab.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeParab::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeParab.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeParab::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeParab.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeParab::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeParab.def("Value", (const gp_Parab & (gce_MakeParab::*)() const) &gce_MakeParab::Value, "Returns the constructed parabola. Exceptions StdFail_NotDone if no parabola is constructed.");
cls_gce_MakeParab.def("Operator", (const gp_Parab & (gce_MakeParab::*)() const) &gce_MakeParab::Operator, "None");

// Enums

}