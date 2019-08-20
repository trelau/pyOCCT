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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <ChFi2d_ConstructionError.hxx>
#include <TopoDS_Face.hxx>
#include <ChFi2d_Builder.hxx>
#include <ChFi2d.hxx>

void bind_ChFi2d(py::module &mod){

py::class_<ChFi2d, std::unique_ptr<ChFi2d>> cls_ChFi2d(mod, "ChFi2d", "This package contains the algorithms used to build fillets or chamfers on planar wire.");

// Constructors

// Fields

// Methods
// cls_ChFi2d.def_static("operator new_", (void * (*)(size_t)) &ChFi2d::operator new, "None", py::arg("theSize"));
// cls_ChFi2d.def_static("operator delete_", (void (*)(void *)) &ChFi2d::operator delete, "None", py::arg("theAddress"));
// cls_ChFi2d.def_static("operator new[]_", (void * (*)(size_t)) &ChFi2d::operator new[], "None", py::arg("theSize"));
// cls_ChFi2d.def_static("operator delete[]_", (void (*)(void *)) &ChFi2d::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi2d.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi2d.def_static("operator delete_", (void (*)(void *, void *)) &ChFi2d::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}