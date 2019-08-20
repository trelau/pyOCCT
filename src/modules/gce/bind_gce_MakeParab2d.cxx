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
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Parab2d.hxx>
#include <gce_MakeParab2d.hxx>

void bind_gce_MakeParab2d(py::module &mod){

py::class_<gce_MakeParab2d, std::unique_ptr<gce_MakeParab2d>, gce_Root> cls_gce_MakeParab2d(mod, "gce_MakeParab2d", "This class implements the following algorithms used to create Parab2d from gp. Defines an infinite parabola. An axis placement one axis defines the local cartesian coordinate system ('XAxis') of the parabola. The vertex of the parabola is the 'Location' point of the local coordinate system of the parabola. The 'XAxis' of the parabola is its axis of symmetry. The 'XAxis' is oriented from the vertex of the parabola to the Focus of the parabola. The 'YAxis' is parallel to the directrix of the parabola and its 'Location' point is the vertex of the parabola. The equation of the parabola in the local coordinate system is Y**2 = (2*P) * X P is the distance between the focus and the directrix of the parabola called Parameter). The focal length F = P/2 is the distance between the vertex and the focus of the parabola.");

// Constructors
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("MirrorAxis"), py::arg("Focal"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("MirrorAxis"), py::arg("Focal"), py::arg("Sense"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("A"), py::arg("Focal"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("D"), py::arg("F"));
cls_gce_MakeParab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("D"), py::arg("F"), py::arg("Sense"));
cls_gce_MakeParab2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("Center"));
cls_gce_MakeParab2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("S1"), py::arg("Center"), py::arg("Sense"));

// Fields

// Methods
// cls_gce_MakeParab2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeParab2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeParab2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeParab2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeParab2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeParab2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeParab2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeParab2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeParab2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeParab2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeParab2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeParab2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeParab2d.def("Value", (const gp_Parab2d & (gce_MakeParab2d::*)() const) &gce_MakeParab2d::Value, "Returns the constructed parabola. Exceptions StdFail_NotDone if no parabola is constructed.");
cls_gce_MakeParab2d.def("Operator", (const gp_Parab2d & (gce_MakeParab2d::*)() const) &gce_MakeParab2d::Operator, "None");

// Enums

}