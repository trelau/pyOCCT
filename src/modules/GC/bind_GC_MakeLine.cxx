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
#include <GC_Root.hxx>
#include <Standard.hxx>
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Line.hxx>
#include <GC_MakeLine.hxx>

void bind_GC_MakeLine(py::module &mod){

py::class_<GC_MakeLine, GC_Root> cls_GC_MakeLine(mod, "GC_MakeLine", "This class implements the following algorithms used to create a Line from Geom. * Create a Line parallel to another and passing through a point. * Create a Line passing through 2 points. A MakeLine object provides a framework for: - defining the construction of the line, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed line.");

// Constructors
cls_GC_MakeLine.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_GC_MakeLine.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_GC_MakeLine.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_GC_MakeLine.def(py::init<const gp_Lin &, const gp_Pnt &>(), py::arg("Lin"), py::arg("Point"));
cls_GC_MakeLine.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_GC_MakeLine.def_static("operator new_", (void * (*)(size_t)) &GC_MakeLine::operator new, "None", py::arg("theSize"));
// cls_GC_MakeLine.def_static("operator delete_", (void (*)(void *)) &GC_MakeLine::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeLine.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeLine::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeLine.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeLine::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeLine.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeLine.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeLine::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeLine.def("Value", (const opencascade::handle<Geom_Line> & (GC_MakeLine::*)() const) &GC_MakeLine::Value, "Returns the constructed line. Exceptions StdFail_NotDone if no line is constructed.");

// Enums

}