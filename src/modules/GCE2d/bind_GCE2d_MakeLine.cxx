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
#include <gp_Ax2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Line.hxx>
#include <GCE2d_MakeLine.hxx>

void bind_GCE2d_MakeLine(py::module &mod){

py::class_<GCE2d_MakeLine, std::unique_ptr<GCE2d_MakeLine, Deleter<GCE2d_MakeLine>>, GCE2d_Root> cls_GCE2d_MakeLine(mod, "GCE2d_MakeLine", "This class implements the following algorithms used to create a Line from Geom2d. * Create a Line parallel to another and passing through a point. * Create a Line passing through 2 points.");

// Constructors
cls_GCE2d_MakeLine.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_GCE2d_MakeLine.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_GCE2d_MakeLine.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_GCE2d_MakeLine.def(py::init<const gp_Lin2d &, const gp_Pnt2d &>(), py::arg("Lin"), py::arg("Point"));
cls_GCE2d_MakeLine.def(py::init<const gp_Lin2d &, const Standard_Real>(), py::arg("Lin"), py::arg("Dist"));
cls_GCE2d_MakeLine.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_GCE2d_MakeLine.def_static("operator new_", (void * (*)(size_t)) &GCE2d_MakeLine::operator new, "None", py::arg("theSize"));
// cls_GCE2d_MakeLine.def_static("operator delete_", (void (*)(void *)) &GCE2d_MakeLine::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_MakeLine.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_MakeLine::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_MakeLine.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_MakeLine::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_MakeLine.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_MakeLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_MakeLine.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_MakeLine::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_MakeLine.def("Value", (const opencascade::handle<Geom2d_Line> & (GCE2d_MakeLine::*)() const) &GCE2d_MakeLine::Value, "Returns the constructed line. Exceptions StdFail_NotDone if no line is constructed.");

// Enums

}