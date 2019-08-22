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
#include <GCE2d_Root.hxx>
#include <Standard.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Ax22d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Parabola.hxx>
#include <GCE2d_MakeParabola.hxx>

void bind_GCE2d_MakeParabola(py::module &mod){

py::class_<GCE2d_MakeParabola, GCE2d_Root> cls_GCE2d_MakeParabola(mod, "GCE2d_MakeParabola", "This class implements the following algorithms used to create Parabola from Geom2d. * Create an Parabola from two apex and the center. Defines the parabola in the parameterization range : ]-infinite,+infinite[ The vertex of the parabola is the 'Location' point of the local coordinate system 'XAxis' of the parabola. The 'XAxis' of the parabola is its axis of symmetry. The 'Xaxis' is oriented from the vertex of the parabola to the Focus of the parabola. The equation of the parabola in the local coordinate system is Y**2 = (2*P) * X P is the distance between the focus and the directrix of the parabola called Parameter). The focal length F = P/2 is the distance between the vertex and the focus of the parabola.");

// Constructors
cls_GCE2d_MakeParabola.def(py::init<const gp_Parab2d &>(), py::arg("Prb"));
cls_GCE2d_MakeParabola.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("Axis"), py::arg("Focal"));
cls_GCE2d_MakeParabola.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("MirrorAxis"), py::arg("Focal"), py::arg("Sense"));
cls_GCE2d_MakeParabola.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("D"), py::arg("F"));
cls_GCE2d_MakeParabola.def(py::init<const gp_Ax2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("D"), py::arg("F"), py::arg("Sense"));
cls_GCE2d_MakeParabola.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("O"));

// Fields

// Methods
// cls_GCE2d_MakeParabola.def_static("operator new_", (void * (*)(size_t)) &GCE2d_MakeParabola::operator new, "None", py::arg("theSize"));
// cls_GCE2d_MakeParabola.def_static("operator delete_", (void (*)(void *)) &GCE2d_MakeParabola::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_MakeParabola.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_MakeParabola::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_MakeParabola.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_MakeParabola::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_MakeParabola.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_MakeParabola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_MakeParabola.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_MakeParabola::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_MakeParabola.def("Value", (const opencascade::handle<Geom2d_Parabola> & (GCE2d_MakeParabola::*)() const) &GCE2d_MakeParabola::Value, "Returns the constructed parabola. Exceptions StdFail_NotDone if no parabola is constructed.");

// Enums

}