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
#include <TopoDS_Face.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepFill_Filling.hxx>
#include <BRepFill_FaceAndOrder.hxx>

void bind_BRepFill_FaceAndOrder(py::module &mod){

py::class_<BRepFill_FaceAndOrder, std::unique_ptr<BRepFill_FaceAndOrder>> cls_BRepFill_FaceAndOrder(mod, "BRepFill_FaceAndOrder", "A structure containing Face and Order of constraint");

// Constructors
cls_BRepFill_FaceAndOrder.def(py::init<>());
cls_BRepFill_FaceAndOrder.def(py::init<const TopoDS_Face &, const GeomAbs_Shape>(), py::arg("aFace"), py::arg("anOrder"));

// Fields

// Methods
// cls_BRepFill_FaceAndOrder.def_static("operator new_", (void * (*)(size_t)) &BRepFill_FaceAndOrder::operator new, "None", py::arg("theSize"));
// cls_BRepFill_FaceAndOrder.def_static("operator delete_", (void (*)(void *)) &BRepFill_FaceAndOrder::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_FaceAndOrder.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_FaceAndOrder::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_FaceAndOrder.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_FaceAndOrder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_FaceAndOrder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_FaceAndOrder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_FaceAndOrder.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_FaceAndOrder::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}