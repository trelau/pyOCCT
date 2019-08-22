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
#include <gp_Lin2d.hxx>
#include <Hatch_LineForm.hxx>
#include <Standard_TypeDef.hxx>
#include <Hatch_Hatcher.hxx>
#include <Hatch_SequenceOfParameter.hxx>
#include <Hatch_Line.hxx>

void bind_Hatch_Line(py::module &mod){

py::class_<Hatch_Line> cls_Hatch_Line(mod, "Hatch_Line", "Stores a Line in the Hatcher. Represented by :");

// Constructors
cls_Hatch_Line.def(py::init<>());
cls_Hatch_Line.def(py::init<const gp_Lin2d &, const Hatch_LineForm>(), py::arg("L"), py::arg("T"));

// Fields

// Methods
// cls_Hatch_Line.def_static("operator new_", (void * (*)(size_t)) &Hatch_Line::operator new, "None", py::arg("theSize"));
// cls_Hatch_Line.def_static("operator delete_", (void (*)(void *)) &Hatch_Line::operator delete, "None", py::arg("theAddress"));
// cls_Hatch_Line.def_static("operator new[]_", (void * (*)(size_t)) &Hatch_Line::operator new[], "None", py::arg("theSize"));
// cls_Hatch_Line.def_static("operator delete[]_", (void (*)(void *)) &Hatch_Line::operator delete[], "None", py::arg("theAddress"));
// cls_Hatch_Line.def_static("operator new_", (void * (*)(size_t, void *)) &Hatch_Line::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Hatch_Line.def_static("operator delete_", (void (*)(void *, void *)) &Hatch_Line::operator delete, "None", py::arg(""), py::arg(""));
cls_Hatch_Line.def("AddIntersection", (void (Hatch_Line::*)(const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Real, const Standard_Real)) &Hatch_Line::AddIntersection, "Insert a new intersection in the sorted list.", py::arg("Par1"), py::arg("Start"), py::arg("Index"), py::arg("Par2"), py::arg("theToler"));

// Enums

}