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
#include <Intf_Interference.hxx>
#include <Standard.hxx>
#include <IntPatch_Polyhedron.hxx>
#include <Standard_TypeDef.hxx>
#include <Intf_TangentZone.hxx>
#include <gp_XYZ.hxx>
#include <IntPatch_InterferencePolyhedron.hxx>

void bind_IntPatch_InterferencePolyhedron(py::module &mod){

py::class_<IntPatch_InterferencePolyhedron, std::unique_ptr<IntPatch_InterferencePolyhedron, Deleter<IntPatch_InterferencePolyhedron>>, Intf_Interference> cls_IntPatch_InterferencePolyhedron(mod, "IntPatch_InterferencePolyhedron", "Computes the interference between two polyhedra or the self interference of a polyhedron. Points of intersection, polylines of intersection and zones of tangence.");

// Constructors
cls_IntPatch_InterferencePolyhedron.def(py::init<>());
cls_IntPatch_InterferencePolyhedron.def(py::init<const IntPatch_Polyhedron &, const IntPatch_Polyhedron &>(), py::arg("Obje1"), py::arg("Obje2"));
cls_IntPatch_InterferencePolyhedron.def(py::init<const IntPatch_Polyhedron &>(), py::arg("Obje"));

// Fields

// Methods
// cls_IntPatch_InterferencePolyhedron.def_static("operator new_", (void * (*)(size_t)) &IntPatch_InterferencePolyhedron::operator new, "None", py::arg("theSize"));
// cls_IntPatch_InterferencePolyhedron.def_static("operator delete_", (void (*)(void *)) &IntPatch_InterferencePolyhedron::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_InterferencePolyhedron.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_InterferencePolyhedron::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_InterferencePolyhedron.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_InterferencePolyhedron::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_InterferencePolyhedron.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_InterferencePolyhedron::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_InterferencePolyhedron.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_InterferencePolyhedron::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_InterferencePolyhedron.def("Perform", (void (IntPatch_InterferencePolyhedron::*)(const IntPatch_Polyhedron &, const IntPatch_Polyhedron &)) &IntPatch_InterferencePolyhedron::Perform, "Computes the interference between the two Polyhedra.", py::arg("Obje1"), py::arg("Obje2"));
cls_IntPatch_InterferencePolyhedron.def("Perform", (void (IntPatch_InterferencePolyhedron::*)(const IntPatch_Polyhedron &)) &IntPatch_InterferencePolyhedron::Perform, "Computes the self interference of a Polyhedron.", py::arg("Obje"));

// Enums

}