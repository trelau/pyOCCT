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
#include <TopoDS_Shape.hxx>
#include <Standard.hxx>
#include <TopoDS_Compound.hxx>

void bind_TopoDS_Compound(py::module &mod){

py::class_<TopoDS_Compound, std::unique_ptr<TopoDS_Compound, Deleter<TopoDS_Compound>>, TopoDS_Shape> cls_TopoDS_Compound(mod, "TopoDS_Compound", "Describes a compound which - references an underlying compound with the potential to be given a location and an orientation - has a location for the underlying compound, giving its placement in the local coordinate system - has an orientation for the underlying compound, in terms of its geometry (as opposed to orientation in relation to other shapes). Casts shape S to the more specialized return type, Compound.");

// Constructors
cls_TopoDS_Compound.def(py::init<>());

// Fields

// Methods
// cls_TopoDS_Compound.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Compound::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Compound.def_static("operator delete_", (void (*)(void *)) &TopoDS_Compound::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Compound.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Compound::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Compound.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Compound::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Compound.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Compound::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Compound.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Compound::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}