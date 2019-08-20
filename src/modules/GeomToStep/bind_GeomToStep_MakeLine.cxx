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
#include <GeomToStep_Root.hxx>
#include <Standard.hxx>
#include <gp_Lin.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Line.hxx>
#include <Geom2d_Line.hxx>
#include <StepGeom_Line.hxx>
#include <GeomToStep_MakeLine.hxx>

void bind_GeomToStep_MakeLine(py::module &mod){

py::class_<GeomToStep_MakeLine, std::unique_ptr<GeomToStep_MakeLine>, GeomToStep_Root> cls_GeomToStep_MakeLine(mod, "GeomToStep_MakeLine", "This class implements the mapping between classes Line from Geom and Lin from gp, and the class Line from StepGeom which describes a line from Prostep.");

// Constructors
cls_GeomToStep_MakeLine.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_GeomToStep_MakeLine.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_GeomToStep_MakeLine.def(py::init<const opencascade::handle<Geom_Line> &>(), py::arg("C"));
cls_GeomToStep_MakeLine.def(py::init<const opencascade::handle<Geom2d_Line> &>(), py::arg("C"));

// Fields

// Methods
// cls_GeomToStep_MakeLine.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeLine::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeLine.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeLine::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeLine.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeLine::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeLine.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeLine::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeLine.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeLine.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeLine::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeLine.def("Value", (const opencascade::handle<StepGeom_Line> & (GeomToStep_MakeLine::*)() const) &GeomToStep_MakeLine::Value, "None");

// Enums

}